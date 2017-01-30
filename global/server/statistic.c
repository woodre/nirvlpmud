/*
 * /global/server/statistic.c
 * Made by Alfe for Tubmud May 1995
 */

#include <wizlevels.h>
#include <prop/player.h>
#include <kernel.h>
#include <server.h>
#include <limits.h>
#include <closures.h>
#include <time_units.h>
#include <names.h>
#include <fingerd.h>
#if TUBMUD  // Coogan, 26-Oct-00
#include <published/peerage.h>  // added published, Coogan, 10-Nov-1998
#else
#define PEERAGE_IS_PEER(x) 0
#endif
#include <libs.h>
#include <is_wizard.h>


/*
 * if our host is not the one it should be, we think that this is most
 * likely a testmud which has not been declared as one. it is vital to
 * this object that no testmud overwrites the real data, so I think
 * it is necessary to do this check, even if it means that this will
 * not work at once in home-muds.
 * if you want to run a real mud (no testmud) on another host you have
 * to change the value of HOME_HOST in /sys/names.h.
 */

#if __HOST_NAME__ != HOME_HOST
#  ifndef TESTMUD
#    define TESTMUD
#  endif
#endif

inherit ACCESS;
inherit "basic/create";
#if 0  // Coogan, 18-Dec-1998
inherit "basic/mapping";
#endif
inherit "basic/name";

#define SAVE_FILE "/save/statistic"
#define POPULATION_FILE "/save/population"
#define ENTER_FILE "/save/enter"
#define DECAY ({ 99,70,0 })

#define TIME 0
#define EXPERIENCE 1
#define COMBAT 2
#define QUEST 3
#define EXPLORE 4
#define AGE 5
#define ALIGN 6
#define STATE 7
#define WIDTH 8  // this must be the value of the last of the above defined
                 // macros + 1

mapping used_rooms, active_players, online_players;
int next_date_for_online_players;
mixed *users_at_hour;

private status is_normal_player(object player) {
  return (player->query_level() <= PL_MAX_PLAYER_LEVEL &&
          !is_wizard(player,IW_TOOLUSER));
}

void add_online_player(object pl) {
  int level;
  string name;
  level = pl->query_level();
  name = pl->query_real_name();
  online_players[name] = (level >= WL_ARCH? PL_MIN_HLP_LEVEL+4 :
                          level >= WL_ELDER? PL_MIN_HLP_LEVEL+3 :
                          level >= WL_APPRENTICE? PL_MIN_HLP_LEVEL+2 :
                          PEERAGE_IS_PEER(pl)? PL_MIN_HLP_LEVEL+1 :
                          level > PL_MIN_HLP_LEVEL? PL_MIN_HLP_LEVEL :
                          level);
}

/*
 * This is called once per day, around 00:30 in the night.
 */
private void log_online_players() {
  mixed h;
  string entry;
  next_date_for_online_players += ONE_DAY;
  entry = (ctime(time()-ONE_DAY)[0..3] +  // the weekday
           (time() / ONE_DAY - 1) + " ");  // the date in days since 1970
  h = allocate(PL_MIN_HLP_LEVEL + 5);
  h[0] = sizeof(online_players);  // the sum of all
  map(m_values(online_players),lambda(({ 'state }),
                                            ({ (#'+=),
                                               ({ CL_INDEX,quote(h),'state }),
                                               1 })));
  entry += implode(map(h,#'to_string)," ") + "\n";
  online_players = ([]);  // clear it for the next day.
  map(users(),#'add_online_player);  // add the current players.
  unguarded(1,#'write_file,({ ENTER_FILE,entry }));
  unguarded(1,#'save_object,SAVE_FILE);
}

mapping query_online_players() { return copy(online_players); }

#define HOUR to_int(ctime()[11..12])

/*
 * This is called once per hour, around 30 minutes past the full hour.
 */
static void enhance_statistics() {
#ifndef TESTMUD
  mixed h;
  string entry;
  int i;
  /*
   * bureaucracy ...
   */
  while (remove_call_out("enhance_statistics") >= 0)
    ;
  call_out("enhance_statistics",ONE_HOUR);
  /*
   * rooms ...
   */
  h = filter(users(),#'is_normal_player);  // all players' rooms
  h = map(h,#'environment)-({ 0 });  // just in case ...
  h -= filter(h,#'clonep);  // only use rooms which are blueprints
  h = map(h,#'load_name);
  used_rooms += mkmapping(h,map(allocate(sizeof(h)),#'|,time()));
  /*
   * users ...
   */
  h = HOUR;
  entry = "";
  if (!h || time()-SE_TIME->query_boot_time() < ONE_HOUR)
    entry += "\n" + ctime() + ":";
 entry += "\t" + sizeof(users());
  unguarded(1,#'write_file,({ POPULATION_FILE,entry }));
  if (next_date_for_online_players < time())
    log_online_players();
  if (!users_at_hour[h])
    users_at_hour[h] = map(DECAY,
                                 lambda(({ 'x }),
                                        ({ #'=,'x,sizeof(users())*100 })));
  else
    for (i=sizeof(DECAY); i--; )
      users_at_hour[h][i] = (users_at_hour[h][i]*DECAY[i]/100+
                             sizeof(users())*(100-DECAY[i]));
  unguarded(1,#'save_object,SAVE_FILE);
#endif
}

private void init_statistics() {
  if (file_size(SAVE_FILE + ".o") > 0)
    unguarded(1,#'restore_object,SAVE_FILE);
  used_rooms = used_rooms || ([]);
  active_players = active_players || m_allocate(0,WIDTH);
  if (widthof(active_players) != WIDTH)   // Alfe 1997-Nov-28
  // Coogan, 24-Aug-99, changed to m_reallocate()
  active_players = m_reallocate(active_players, WIDTH);
  users_at_hour = users_at_hour || allocate(ONE_DAY / ONE_HOUR);
  online_players = online_players || ([]);
  next_date_for_online_players = (next_date_for_online_players ||
                                  (time()/ONE_DAY + 1) * ONE_DAY);
  if (next_date_for_online_players < time())
    log_online_players();
  else
    map(users(),#'add_online_player);
  SE_USERS->add_notify();  // to find out who is an 'active' player for tablets
}

varargs void update_player(string name,object pl) {
  if (extern_call() && !check_previous_privilege(1))
    raise_error("Illegal call of update_player()\n");
  name = to_real_name(name);
  pl = pl || find_player(name) || FINGERD->load_player(name);
  if (!pl || pl->query_guest())
    return;  // do nothing with guests.
  if (pl->query_level() >= WL_APPRENTICE ||
      pl->query_property(P_TESTPLAYER) ||
      pl->test_flag(96))
    m_delete(active_players,name);
  else {
    active_players[name,TIME] = time();
#ifdef NEW_LEVELS
// Carador, 02-Dec-1997
       // This no longer contains the experience, it contains a value
       // which enables us to calculate the experienced player easily,
       // The most experienced player is the one with the highest level,
       // if the levels are equal use the level points to determine the
       // position. As the levelpoints cannot go beyond 3000 we
       // use 4000 * level + levelpoints. The higher this value, the 
       // more experienced is the player. The tablets just may use
       // value / 4000 to get the level and value % 4000 to get the
       // levelpoints.
    active_players[name,EXPERIENCE] = 
       4000 * pl->query_level() + LIB_ADVANCE->query_promille_sum(pl);
       // The following contain the promille-values in combat, quest
       // and exploring. 
    active_players[name,COMBAT] = LIB_ADVANCE->query_combat_promille(pl);
    active_players[name,QUEST] = LIB_ADVANCE->query_quest_promille(pl);
    active_players[name,EXPLORE] = LIB_ADVANCE->query_explore_promille(pl);
#else
    active_players[name,EXPERIENCE] = pl->query_exp();
    active_players[name,COMBAT] = pl->query_combat_exp();
    active_players[name,QUEST] = pl->query_quest_points();
    active_players[name,EXPLORE] = LIB_EXPLORE->explored(pl);
#endif
    active_players[name,AGE] = pl->query_age();
    active_players[name,ALIGN] = pl->query_alignment();
    // 0: normal player
    // 1: hlp
    // 2: peer
    if (PEERAGE_IS_PEER(pl))  // peer?
      active_players[name,STATE] = 2;
    else
      if (pl->query_level() >= PL_MIN_HLP_LEVEL)  // hlp?
        active_players[name,STATE] = 1;
      else
        active_players[name,STATE] = 0;
  }
}

void notify_login(string name) {
  update_player(name);
  add_online_player(find_player(name));
}

void notify_depetrify(string name) {
  update_player(name);
}

#if 0  // too costly (would use FINGERD) and not necessary.
       // let the player object do this call ;-)
void notify_logout(string name) { update_player(name); }
#endif

void notify_petrify(string name) { update_player(name); }

/*
 * This function returns a mapping of the last 400 to 500 active players.
 * The mapping will contain the names of the players pointing to the time they
 * logged in last.
 */
varargs mapping query_active_players(status trusted) {
  mixed h;
  if (sizeof(active_players) > 500) {  // please adjust this value if necessary
    h = order_alist(m_values(active_players),m_indices(active_players));
    h = h[1][0..<399];  // the longest-not-present players
    active_players -= mkmapping(h);  // subtract them
  }
  if (trusted)
    if (extern_call() && !check_previous_privilege(1))
      raise_error("Illegal call of query_active_players(1)\n");
    else
      return active_players;
  else
    return copy(active_players);
}

mapping query_active_group(int group) {
  mixed h;
  h = query_active_players(1);
  return filter_indices(h,lambda(({ 'name }),
                                 ({ (#'==),
                                    ({ CL_INDEX,h,'name,STATE }),
                                    group })));
}



// following two functions added by Carador, 15-Dec-1997 

mapping query_active_lowlevel_players() 
{
  return query_active_group(0);
}

mapping query_active_highlevel_players()
{
  mixed h;
  h = query_active_players(1);
  return filter_indices(h,lambda(({ 'name }),
                                 ({ (#'!=),
                                    ({ CL_INDEX,h,'name,STATE }),
                                    0 })));
}

#define ROOM_DELETE_DELAY 3000000

void create() {
  init_statistics();
#ifndef TESTMUD
  // all half-past-the-hour
  call_out("enhance_statistics",
           (ONE_HOUR+HALF_HOUR-(time() % ONE_HOUR)) % ONE_HOUR);
  // do not delete that often. not necessary and costy. that's why this
  // is here in create() and not in refresh() or anything.
  used_rooms = filter_indices(used_rooms,
                              lambda(({ 'x }),
                                     ({ (#'>),
                                        ({ CL_INDEX,used_rooms,'x }),
                                        time()-ROOM_DELETE_DELAY })));
#endif
}

mapping query_registered_rooms() { return copy(used_rooms); }

/*
 * string *query_used_rooms(int age) returns the rooms which's last
 * registration was at last <age> seconds ago.
 *
 * values for <age> above ROOM_DELETE_DELAY (which is 3000000 at the moment)
 * do not make sense because older rooms are not kept in the database.
 */
string *query_used_rooms(int age) {
  return m_indices(filter_indices(used_rooms,
                                  lambda(({ 'x }),
                                         ({ (#'>),
                                            ({ CL_INDEX,used_rooms,'x }),
                                            time()-age }))));
}

/*
 * mixed *query_users_at_hour(int hour) returns
 * (if hour is negative or greater than 23)
 *    an array of entries as described below
 * (else)
 *    0  if no data is available for this day-hour yet
 *      or
 *    an array of numbers where each element is a floating mean of the
 *    number of users logged in at this hour of the day; the first entry
 *    is the most slowly adapting value, the last is the fastest adapting
 *    value.
 */
mixed *query_users_at_hour(int hour) {
  if (hour<0 || hour>23)
    return users_at_hour[0..];
  return users_at_hour[hour];
}

#ifndef TESTMUD

void notify_destruct() {
  unguarded(1,#'save_object,SAVE_FILE);
}

#endif
