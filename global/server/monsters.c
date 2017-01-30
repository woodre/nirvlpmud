/*************************************************************************
 global/server/monsters.c, Copyright by Carador, Sep-Nov-97, Tubmud

 This file contains a database of all killed monsters. Currently
 (Nov-97) it contains about 1200 monsters.

 Everything will (hopefully) work fine up to 6000 monsters. If the
 database will exceed 6000 entries it needs finetuning for evalcost-
 saving (or just increase the MAX_EVAL_COST).
 The database will not accept more than 7000 monsters to avoid too
 long evaluations
*************************************************************************/

#pragma strong_types

/*
 * if our host is not the one it should be, we think that this is most
 * likely a testmud which has not been declared as one. it is vital to
 * this object that no testmud overwrites the real data, so I think
 * it is necessary to do this check, even if it means that this will
 * not work at once in home-muds.
 * if you want to run a real mud (no testmud) on another host you have
 * to change the value of HOME_HOST in /sys/names.h.
 */

#include <names.h>

#define MAINTAIN_DB

#if __HOST_NAME__ != HOME_HOST
#  ifndef TESTMUD
#    define TESTMUD
#  endif
#endif

#include <server.h>
#include <time_units.h>
#include <prop/npc.h>
#include <kernel.h>
#include <event.h>
#include <describe.h>
#include <is_wizard.h>
#include <message.h>

// for mapping monsters
#define MO_LASTKILL     0
#define MO_NUMBER       1
#define MO_WEIGHT       2
#define MO_LEVEL        3
#define MO_CREATOR      4
#define MO_AREA         5       // Coogan, 17-Jul-2004
#define MO_WIDTH        6       // Coogan, 17-Jul-2004

// for static mapping intmonsters
#define INMO_LEVEL      0
#define INMO_ID         1


#define MIN_LEVEL_WEIGHT 5
#define MAX_LEVEL_WEIGHT 50  // 40 -> 50, Coogan, 30-Jun-98

static variables inherit "basic/create";
static variables inherit ACCESS;

int     count;
string *similar_approved_monsters;
mapping monsters;

nosave mapping intmonsters;
nosave int     weight_sum;
nosave int     level_weight_sum;
nosave int     active_count;
nosave string *castles;
nosave string *areas;

int adjust_level(int l) {
  if (l <= 0)
    return 0;
  if (l > MAX_LEVEL_WEIGHT) return MAX_LEVEL_WEIGHT;
  if (l < MIN_LEVEL_WEIGHT) return MIN_LEVEL_WEIGHT;
  return l;
}


// Return the current identifying count. Will be increased for every
// new monster.

int query_count() {
  return count;
}

// Return the number of known monsters. Is usually smaller than
// query_count

int query_active_count() {
  return active_count;
}


// Return the sum of the levels of all known monsters. This value
// together with player->query_kill_points() gives us the
// promille value in combat

int query_level_weight_sum() {
  // the database shall setup itself anew, we know that there will
  // be more than 10000, so let this be the lower bound
  if (level_weight_sum < 10000)
    return 10000;
  return level_weight_sum;
}


// Return the sum of the experience that is given for slaying all
// monsters. This is the traditional kill experience.
// It is used as upper limit to calculate the experience for
// solving quests, scenarios, exploring and for the additional
// experience for first-time-slaying of a monster.

int query_weight_sum() {
  // same as above
  if (weight_sum < 5000000)
    return 5000000;
#if 0  // Coogan, 28-Feb-02
  if (weight_sum > 7500000)  // Coogan, 26-Feb-02
    return 7500000;
#endif
  return weight_sum;
}


// Returns the level of monster mon. This is used by the player to
// calculate his kill-points.

int query_level_weight(int mon) {
  if (!member(intmonsters, mon))
    return 0;
#if 0  // Coogan, 30-Jun-98, 0 again, 14-Nov-00
  return intmonsters[mon, INMO_LEVEL];
#else
  return adjust_level(intmonsters[mon, INMO_LEVEL]);
#endif
}


// Returns the identifying string to a monster with number mon

string number2id(int mon) {
  if (!member(intmonsters, mon))
    return 0;
  return intmonsters[mon,INMO_ID];
}

int id2number(string id) {
  if (!member(monsters, id))
    return 0;
  return monsters[id, MO_NUMBER];
}


// this returns the components of which the automatically generated
// monster-id consists
// this is new, 26-Jan-98

string *get_monster_id_components(object m) {
  string tmp;
  
  tmp = m->query_creator_object();    // for basic/livings
  if (tmp) {
    tmp = explode(tmp, "#")[0];       // only the program-name counts
                                      // that's for vrooms with monsters
  }
  else {
    tmp = m->query_create_room() &&   // obj/monster
          load_name(m->query_create_room());
    if (tmp == "bin/shell" ||         // Coogan, 06-Nov-98, 21-Jan-99; there
        tmp == "obj/tools/newrobe" || // are always some wizards around,
        tmp == "obj/tools/robe"    || // cloning monsters in public areas
        tmp == "tools/stack/update")
      tmp = 0;
  }

  if (!tmp)
    return 0;                         // no creating object known, do not add

  return ({ "" + creator(m),          // to ensure that it's a string
            explode(tmp, "/")[<1],
            explode(load_name(m), "/")[<1],
            lower_case(describe(m, ARTICLE_NONE) || ""),
            "" + m->query_level() }); // make it a string
}


// this returns the identifier of monster m
// this has been changed, 26-Jan-98

string get_monster_id(object m) {
  string tmp;
  string *components;

  if (tmp = m->query_property(P_MONSTER_DATABASE_ID))
    return tmp;

  if (!(components = get_monster_id_components(m)))
    return 0;
  return implode(components, "#");
}


// called via call_out by reset from obj/living
// it sets a monster-database-id when there are more than one of
// the same monster in the same room
// this is new, 26-Jan-98

void set_monster_database_id(object m) {
  string cmp, *cmp_comp, room;
  object ob;
  int num;
  string *numbers;
  string *components;
  string race;

  if (!m ||
      !environment(m) ||
      !living(m) ||
      query_once_interactive(m))
    return;

  // it's a real monster. So first we handle, if there's a race set.
  // Coogan, 08-Dec-00, 18-Dec-00
  room = m->query_create_room() &&
         load_name(m->query_create_room());
  cmp = load_name(m);

  if (!(race = m->query_race()))
    log_file("RACE", "Race not set: " + cmp + " (" + room + ")\n");
#if 0  // Coogan, 11-Sep-2002
  else if (!sizeof(LIB_RACE->query_race_tree(race)))
#else
  else if (!LIB_RACE->query_is_known_race(race))
#endif
    log_file("RACE", "Unknown race: " + race + "\n"
                     "          in: " + cmp + " (" + room + ")\n");

  if (m->query_property(P_MONSTER_DATABASE_ID))
    return;

  // following check ensures an array with exactly five elements,
  // Coogan & Chameloid, 16-Feb-98
  if (!pointerp(components = get_monster_id_components(m)) ||
      sizeof(components) != 5)
    return;
    
  numbers = ({ });

  // now scan environment for monsters which are the same
  for (ob = first_inventory(environment(m)); ob; ob = next_inventory(ob)) {
    if (!living(ob) ||
        query_once_interactive(ob) ||
        ob == m ||
        !(cmp = get_monster_id(ob)) ||
        sizeof(cmp_comp = explode(cmp, "#")) != 5 ||
        components[0] != cmp_comp[0] ||  // wrong creator
        components[1] != cmp_comp[1] ||  // wrong room
        components[2] != cmp_comp[2] ||  // wrong filename
        components[4] != cmp_comp[4]     // wrong level
       ) continue;
    cmp_comp = explode(cmp_comp[3], "_");
    if (cmp_comp[0] != components[3])
      continue;                          // wrong name

    // a ha. ob is a monster of same kind as m, so we need his number
    // behind the _

    if (sizeof(cmp_comp) != 2)
      num = 1;                           // has no number, so it's number 1
    else
      num = ((int)cmp_comp[1]) || 1;
    if (member(numbers, num) < 0)
      numbers += ({ num });
  }

  if (!sizeof(numbers))
    return;                              // m is the only one of its kind
                                         // in the room, nothing to do

  // find the first unused number
  for (num=1; num<=sizeof(numbers); num++)
    if (member(numbers, num) < 0)
      break;


  if (num > 1) {
    components[3] += "_" + num;
    m->set_property(P_MONSTER_DATABASE_ID, implode(components, "#"));
  }
}


int get_monster_number(object m) {
  string id;
 
  if (!(id = get_monster_id(m)))
    return -1;
  return id2number(id);
}



// This gets called by obj/living when a player
// killed a monster or made at least 25% damage to a killed monster
// major changes 3-Jan-98

varargs void monster_killed(object monster, object player, int weight,
                            int damage_percent) {
  int level, ad_level;
  string id;
  object *party, pl;

  if (!player || !monster || !living(monster) ||
      interactive(monster) || !interactive(player))
    return;

  level = monster->query_level();
  ad_level = adjust_level(level);  // Coogan, 30-Jun-98

  id = get_monster_id(monster);
  if (!id || !stringp(id))
    return;

  if (monster->query_property(P_NO_MONSTER_DATABASE)) { 
             // this monster shall not be member of our list
    if (member(monsters, id)) {
#ifndef TESTMUD
      log_file("MONSTER_DATABASE",
               "set weights for " + id + " to zero (property)\n");
#endif
      weight_sum -= monsters[id, MO_WEIGHT];
      level_weight_sum -= adjust_level(monsters[id, MO_LEVEL]);
      intmonsters -= ([ monsters[id, MO_NUMBER] ]);
      monsters[id, MO_WEIGHT] = 0;
      monsters[id, MO_LEVEL] = 0;
      call_out("save_me", 0);  // Coogan, 30-Jun-98
    }
    return;
  }

  if (weight == 0) {  // mustn't be, as this means, the living has had 0 exp
    log_file("MONSTER_DATABASE",                // Coogan, 05-Mar-02
             "Warning: " + id + " has a weight of 0!\n");
  }

  if (member(monsters, id)) {
    monsters[id, MO_LASTKILL] = time();
    weight_sum = weight_sum - monsters[id, MO_WEIGHT] + weight;
    monsters[id, MO_WEIGHT] = weight;

    if (level > monsters[id, MO_LEVEL] &&
        !is_wizard(player, IW_APPRENTICE)) {  // Coogan, 20-Sep-01
      level_weight_sum = level_weight_sum -
                           adjust_level(monsters[id, MO_LEVEL]) + ad_level;
      log_file("MONSTER_DATABASE",
               "Level of " + id + " increased from " + monsters[id, MO_LEVEL] +
               " to " + level + "\n");
      monsters[id, MO_LEVEL] = level;
      intmonsters[monsters[id, MO_NUMBER], INMO_LEVEL] = ad_level;
    } else {
      ad_level = adjust_level(monsters[id, MO_LEVEL]);  // !! Coogan
    }
    player->add_killed_monster(monsters[id, MO_NUMBER],
                               ad_level, damage_percent);
#if 1 // Coogan, 19-Apr-99: party handling: a party killing a monster -
      // the monster #count will be set as killed for all present party members
    if (pl = SE_PARTY->query_party_leader(player)) {
      party = SE_PARTY->query_party_members(pl) - ({ player });
      party = filter(party, lambda(({ 'x }),
                                   ({ #'present, 'x,
                                      ({ #'environment, player })})));
      map_objects(party,
                  "add_killed_monster", monsters[id, MO_NUMBER], ad_level);
    }
#endif
    return;
  }

  // Wizards and Testplayers shall not add new monster to the database
  if (is_wizard(player) || is_wizard(player, IW_TESTPLAYER))
    return;

  if (creator(monster) &&
      member(castles, creator(monster)) < 0) {
#ifndef TESTMUD
    log_file("MONSTER_DATABASE", "not added " + id + " (castle not open)\n");
#endif
    return;
  }

  if (active_count >= 6000) {
    send_message(({ M_TARGETS, filter(users(), #'is_wizard),
                    "Critical: Database /global/server/monsters is getting "
                    "too full. Please check this!" }));
  }

  if (active_count >= 7000) {
#ifndef TESTMUD  // fixed next call, Coogan, 24-Oct-00
    log_file("MONSTER_DATABASE", "not added " + id + " (database full)\n");
#endif
    return;
  }

  weight_sum += weight;
  level_weight_sum += adjust_level(level);
  active_count++;
  count++;
  monsters += ([ id : time(); count; weight; level; creator(monster); 0 ]);
  intmonsters += ([ count : ad_level; id ]);
  player->add_killed_monster(count, ad_level, damage_percent);
#ifndef TESTMUD
  unguarded(1, #'write_file, ({ "/save/monsters_list",
      sprintf("%5d %-s\n", count, id) }));
  log_file("MONSTER_DATABASE", "added " + id + " (c: " + count + " w: " +
    weight + " l: " + level + ")\n"
    "   in " + object_name(environment(player)) + "\n");
    // added the 'in' part because of problems with several monsters,
    // for which I don't know, where they have been killed; Coogan, 03-Jun-98
#endif

#if 1 // Coogan, 19-Apr-99: party handling: a party killing a monster -
      // the monster #count will be set as killed for all present party members
  if (pl = SE_PARTY->query_party_leader(player)) {
    party = SE_PARTY->query_party_members(pl) - ({ player });
    party = filter(party, lambda(({ 'x }),
                                 ({ #'present, 'x,
                                    ({ #'environment, player })})));
    map_objects(party, "add_killed_monster", count, ad_level);
  }
#endif
  call_out("refresh", 0);
}



// This is called during creation of the object and sets everything
// up, scans for to be deleted monsters.

private void do_setup_monsters(string key, int lastkill, int number,
                               int weight, int level, mixed cre,
                               string area) {
  status inactive;
  int ad_level;  // Coogan, 30-Jun-98

  if (get_eval_cost() > 200000) {
    if (cre && member(castles, cre) < 0) {
#ifndef TESTMUD
      log_file("MONSTER_DATABASE", "Ignored: " + key +
               " (castle not open)\n");
      // debug("coogan", key + "\" \"" + cre);
      inactive = 1;
#endif
    }

    if (time() - lastkill > HALF_YEAR && !inactive) {
#ifndef TESTMUD
#if 0  // Coogan, 03-Nov-98
      log_file("MONSTER_DATABASE", "ignored " + key + 
        " (not killed long time)\n");
      inactive = 1;
#else
      log_file("MONSTER_DATABASE_WARN", "Warning: " + key +
               " (not killed long time)\n");
#endif
#endif
    }
  }

  if (inactive)  // Coogan, 03-Nov-98
    return;

  ad_level = adjust_level(level);
  if (!weight && !inactive)
    log_file("MONSTER_DATABASE_WARN",
             "Warning: " + key + " has weight 0\n");
  if (weight && !inactive) {
    if (!ad_level)
      log_file("MONSTER_DATABASE_WARN",
               "Warning: " + key + " has a level of 0\n");
    // next logging by Coogan, 22-Jul-2004
    if (!area || member(areas, area) == -1)
      log_file("MONSTER_DATABASE_WARN",
               "Warning: "+ key +" has "+ (area?"an invalid":"no") +" area\n");
    intmonsters += ([ number : ad_level; key ]);
    weight_sum += weight;
    level_weight_sum += ad_level;
    active_count++;
  }
}

void create() {
  if (clonep()) {
    call_out(#'destruct, 0, this_object());
    return;
  }

  restore_object("/save/monsters");
  if (!monsters)
    monsters = ([:MO_WIDTH]);           // added MO_WIDTH, Coogan, 17-Jul-2004
  if (widthof(monsters) != MO_WIDTH)    // Coogan, 17-Jul-2004
    monsters = m_reallocate(monsters, MO_WIDTH);
  if (!similar_approved_monsters)
    similar_approved_monsters = ({ });
  intmonsters = ([:2]);                 // added :2, Coogan, 17-Jul-2004
  weight_sum = 0;
  level_weight_sum = 0;
  castles = SE_CASTLES->query_castles() + ({ "0" });
  areas   = LIB_EXPLORE->query_area_names();  // Coogan, 17-Jul-2004
  walk_mapping(monsters, #'do_setup_monsters);
#ifndef TESTMUD
  log_file("MONSTER_DATABASE", ctime() + ": loaded, c: " + count + ", a: " +
      active_count+ ", w: " + weight_sum + ", l: " + level_weight_sum +
      ", eval_left: " + get_eval_cost() + "\n");
#endif
  call_out("refresh", 2);
  call_out("check_double", 6);
}

void save_me() {  // Coogan, 30-Jun-98
#ifndef TESTMUD
  unguarded(1, #'save_object, "/save/monsters");
#endif
}

void refresh() {
  save_me();
}

void notify_destruct() {  // Coogan, 30-Jun-98
  save_me();
}

// This checks for similar monsters. Similar, in the monster-database
// unwanted monsters are those who have a random (or changing) name
// or random (or changing) level. 

void check_double() {
  string *ind;
  int i, count;
  status flag;
  mixed tmp, tmp2;

#ifndef TESTMUD
  rm("/open/double_monsters");
#endif
  ind = sort_array(m_indices(monsters), #'<);
  if (!sizeof(ind))
    return;
  tmp = explode(ind[<1], "#");
  for (i=sizeof(ind)-1; i--;) {
    if (get_eval_cost() < 100000)
      break;
    if (member(similar_approved_monsters, ind[i])  > -1)
      continue;
    tmp2 = explode(ind[i], "#");
    if (sizeof(tmp) == 5 &&
        sizeof(tmp2) == 5 &&
        strstr(tmp2[3], "_") < 0 &&
        tmp[0] == tmp2[0] &&
        tmp[1] == tmp2[1] ) {
      if (!flag) {
        flag = 1;
        count++;
#ifndef TESTMUD
        write_file("/open/double_monsters", ind[i+1] + "\n");
#endif
      }
      count++;
#ifndef TESTMUD
      write_file("/open/double_monsters", ind[i] + "\n");
#endif
    }
    else
      flag=0;
    tmp = tmp2;
  }
#ifndef TESTMUD
  if (count)
    log_file("MONSTER_DATABASE", "WARNING: detected " + count +
       " similar monsters (check /open/double_monsters)\n");
#endif
}


// Do not delete these functions. They will be activated
// temporarily when the database is maintained manually.

#ifdef MAINTAIN_DB

varargs status add_monster(string id, int number, int level, string creator) {
  mixed h;
  int weight;
  if (!id || !number)
    return 0;
  h = explode(id, "#") - ({ "" });
  if (!level)
    level = adjust_level(h[<1]);
  if (!creator)
    creator = h[0];
  weight = LIB_ADVANCE->query_monster_exp(level) / 60;
  if (member(monsters, id))
    return 0;
  monsters += ([ id : time(); number; weight; level; creator ]);
  log_file("MONSTER_DATABASE",
           "re-added: " + id + " at number " + number + "\n"); 
  return 1;
}

void set_count(int c) {
  count = c;
}

// Coogan, 03-Nov-98: needed that because of moved monsters
status change_monster_creator(string id, string creator) {
  string ocreator;

  if (!member(monsters, id) ||
      member(castles, creator) < 0)
    return 0;

  ocreator = monsters[id, MO_CREATOR];

#ifndef TESTMUD
  log_file("MONSTER_DATABASE",
           "changed creator of " + id + " from " + ocreator + " to " +
           creator + " (manual change by " +
           this_player()->query_real_name() + ")\n");
#endif
  monsters[id, MO_CREATOR] = creator;
  return 1;
}
  
status change_monster_id(string old, string new) {

  if (!member(monsters, old) ||
      member(monsters, new))
    return 0;

  monsters += ([ new : 
                 monsters[old,0];
                 monsters[old,1];
                 monsters[old,2];
                 monsters[old,3];
                 monsters[old,4];
                 monsters[old,5]
              ]);
  m_delete(monsters, old);
  intmonsters[monsters[new, MO_NUMBER], INMO_ID] = new;
#ifndef TESTMUD  // Coogan, 30-Jun-98
  log_file("MONSTER_DATABASE",
           "changed " + old + "\n     to " + new + " (manual change by " +
           this_player()->query_real_name() + ")\n");
#endif
  return 1;
}

status change_monster_number(int old, int new) {  // Coogan, 21-Feb-99
  string mid;
  if (member(intmonsters, new) || !member(intmonsters, old))
    return 0;
  mid = number2id(old);
  intmonsters += ([ new : intmonsters[old, INMO_LEVEL];
                          intmonsters[old, INMO_ID] ]);
  intmonsters -= ([ old ]);
  monsters[mid, MO_NUMBER] = new;
#ifndef TESTMUD
  log_file("MONSTER_DATABASE",
           "changed number of " + mid + " from " + old + " to " + new +
           " (manual change by " + this_player()->query_real_name() + ")\n");
#endif
  return 1;
}

status change_monster_area(string id, string area) {  // Coogan, 17-Jul-2004
  string old_area;
  if (!member(monsters, id))
    return 0;
  if (member(areas, area) == -1) {
    log_file("MONSTER_DATABASE",
             "NOT changed area of " + id + " to " + area + " because " +
             area + " is not a known area!\n");
    return 0;
  }
  old_area = monsters[id, MO_AREA];
#ifndef TESTMUD
  log_file("MONSTER_DATABASE",
           "changed area of " + id + " from " + old_area + " to " + area +
           " (manual change by " + this_player()->query_real_name() + ")\n");
#endif
  monsters[id, MO_AREA] = area;
  return 1;
}

// Coogan, 17-Jul-2004
private void do_change_area_name(string key, int lastkill, int number,
                                 int weight, int level, mixed cre, string area,
                                 string area_old, string area_new) {
  if (area == area_old)
    area = area_new;
}

status change_area_name(string area_old, string area_new) { //Coogan,17-Jul-2004
  int i;
  if ((i = member(areas, area_old)) == -1 ||
      member(areas, area_new) == -1) {
    log_file("MONSTER_DATABASE",
             "NOT changed area name " + area_old + " to " + area_new +
             "because " + (i==-1 ? area_old : area_new) +
             " is not a known area (requested by "+
             this_player()->query_real_name() + ")\n");
    return 0;
  }
#ifndef TESTMUD
  log_file("MONSTER_DATABASE",
           "changed area name " + area_old + " to " + area_new +
           "(manual change by " + this_player()->query_real_name() + ")\n");
#endif
  walk_mapping(monsters, #'do_change_area_name, area_new);
  return 1;
}

status remove_single_monster(string id) {
  if (!member(monsters, id))
    return 0;
#ifndef TESTMUD
  log_file("MONSTER_DATABASE", "removed " + id + " (manual remove by " +
                               this_player()->query_real_name() + ")\n");
#endif
  active_count--;
  weight_sum       -= monsters[id, MO_WEIGHT];
  level_weight_sum -= intmonsters[monsters[id, MO_NUMBER], INMO_LEVEL];
  intmonsters      -= ([ monsters[id, MO_NUMBER] ]);
  monsters -= ([ id ]);
  return 1;
}

void remove_monsters(string file) {
  if (file_size(file) < 0)
    return;
  map(explode(read_file(file), "\n")[0..<2], #'remove_single_monster);
  call_out("refresh", 0);
}

private void my_similar_approve(string id) {
  if (member(similar_approved_monsters, id) < 0) {
#ifndef TESTMUD
    log_file("MONSTER_DATABASE", "approved similar " + id + "\n");
#endif
    similar_approved_monsters += ({ id });
  }
}

void add_similar_approved_monsters(string file) {
  if (file_size(file) < 0)
    return;
  map(explode(read_file(file), "\n")[0..<2], #'my_similar_approve);
  call_out("refresh", 0);
}
#endif


/*

Below are several information functions to see how the
monster-database looks like.

Call /global/server/monsters print_statistic 0  (levels)
Call /global/server/monsters print_statistic 1  (experience)
Call /global/server/monsters print_statistic 2  (creators)
Call /global/server/monsters dump_monsters (dumps all known monsters
                                            alphabetically to /open/monsters)
*/

static int *stat_exp = ({ 20000, 15000, 10000, 5000, 2000, 1000, 500, 200,
                          100, 50, 0 });
static mapping statistic;

private void make_statistic(string key, int lastkill, int number, 
                            int weight, int level, mixed cre, int stat_type) {
  mixed tmp;

  if (!member(intmonsters, number))
    return;   // not active

  switch (stat_type) {
    case 0 : // levelmaessige aufteilung
      if (!member(statistic, level))
        statistic += ([ level : 1;weight]);
      else {
        statistic[level]++;
        statistic[level,1]+= weight;
      }
      break;

    case 1 :   // expmaessige aufteilung
      for (tmp=sizeof(stat_exp); tmp--;) {
        if (weight < stat_exp[tmp])
          break;
      }
      tmp++;
      if (!member(statistic, stat_exp[tmp]))
        statistic += ([ stat_exp[tmp] : 1; weight ]);
      else {
        statistic[stat_exp[tmp],0]++;
        statistic[stat_exp[tmp],1]+=weight;
      }
      break;

    case 2 :   // creatormaessige aufteilung
      cre = cre||"0";
      if (!member(statistic, cre))
        statistic += ([ cre : 1;weight ]);
      else {
        statistic[cre,0]++;
        statistic[cre,1]+=weight;
      }
      break;
  }
}

// string to void, Coogan, 26-Mar-2011
varargs void print_statistic(int stat_type) {
  int i;
  mixed tmp;

  statistic = ([ ]);
  walk_mapping(monsters, #'make_statistic, stat_type);
  switch (stat_type) {
    case 0:
      write("\nLevel |  Amount  |  Total Weight\n");
      write("------+----------+----------------\n");
      for (i=0; i<100; i++) {
        if (!member(statistic,i))
          continue;
        printf("%3d   |   %4d   |   %8d\n",
            i, statistic[i,0],statistic[i,1]);
      }
      break;

    case 1:
      write("\n   Weight  |  Amount  |  Total Weight\n");
      write("-----------+----------+--------------\n");
      for (i=0; i<sizeof(stat_exp); i++) {
        printf(" > %5d   |   %4d   |   %8d\n",
            stat_exp[i], 
            (member(statistic, stat_exp[i]) ?
               statistic[stat_exp[i],0] : 0),
            (member(statistic, stat_exp[i]) ?
               statistic[stat_exp[i],1] : 0)
        );
      }
      break;
    case 2:
      tmp = sort_array(m_indices(statistic), #'<);
      write("\n   Creator   |  Amount  | Total Weight\n");
      write(  "-------------+----------+--------------\n");
      for (i=sizeof(tmp); i--;)
        printf(" %:-10s  |   %4d   |   %8d\n", tmp[i],
            statistic[tmp[i],0], statistic[tmp[i],1]);
    
      break;
  }
  write("\nNumber of monsters: " + sizeof(monsters) + ", active: " +
      active_count + ", weight: " +
      weight_sum + ", levelweight " +  level_weight_sum + "\n");
  statistic = 0;
}

// der code unterhalb hier kackt ab, wenn es mehr als MAX_ARRAY_SIZE
// monster (gegenwaertig 3000) gibt

void dump_monsters(status all) {
#ifndef TESTMUD
  rm("/open/monsters");
  // added filtering of inactive monsters, Coogan, 15-Dec-2003
  if (all)
    write_file("/open/monsters",
               implode(sort_array(m_indices(monsters),
                                  #'>), "\n")+"\n");
  else
    write_file("/open/monsters",
               implode(sort_array(m_indices(filter(monsters,
                                                   (: $2[MO_WEIGHT] != 0 :))),
                                  #'>), "\n")+"\n");
#endif
}

varargs mapping query_monsters(string area) {
  if (area) {
    if (member(areas, area) == -1)
      return 0;
    return filter(monsters, (: $2[MO_AREA] == $3 :), area);
  }
  return copy(monsters);
}

mapping query_intmonsters() {
  return copy(intmonsters);
}

