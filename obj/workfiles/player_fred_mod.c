#include <security.h>
#include <ansi.h>
#include "play/paths.h"

inherit "obj/user/channel";
inherit "obj/user/cmd_hook";

#include "living.h"
#include "/obj/follow.c"
#include "/obj/user/one_chan.c"
#include "/closed/handshake.h"
#include "/obj/quest_pt.c"
#include "/obj/player/prego.c"
#include "/obj/monitor.c"

#include "/closed/verte/qt/play_inc.h"
#include "/closed/verte/qt/do/play_inc.h"


#define SAVE_INTERVAL 400
#define INFUSE_LIMIT (((9*level) + (9*ex_lv/4))/2)
#define esc ""
#define IDLELIMIT 1800
#define NUMOBS_STOR 20

/* Earwax's projects */
inherit "/obj/player/stats.c";
inherit "/obj/player/beta.c";
#define PRIVSD "/obj/daemons/closed/readwrite.c"

int nirvana_points;
static int autosave_counter;
static int autoheal_counter;
static int pk_title_time;
static int whimpy_delay,noidlequit,is_interactive;
static int oldtreasure,oldexp;
static int inact,inacttwo,channelcount;
string clan;
string sig;
static string afk_message;
static object myself, soul;
string wkrm,hostname;
static string tellblock;
static string tellhistory,replyto;
static int tellhidx,privblk;
string ok_edit;
string mailaddr;
string saved_where;
string title;
string pretitle;
string password;
static string password2;
string spouse;
string race;
string al_title;
int PKGhostCounter;
int intoxicated;
string fight_area;
int mon,phys_at,headache, max_headache;
int no_spell;
static int idlewarn,idletime;
string called_from_ip;
string msghome;
static int power;
string description;
string guild_name;
string lastime;  /*last login time */
int player_killing;
int invs_count;
int infuse;
int invs_flag;  /* are we invisible??? (players only) */
int new_pl_rest;
int muffled;
int treasure;	
string treasure_str;
string pwd;
int dead;
int guild_rank, guild_exp;
string guild_file;
string home;
int ex_lv;
int qc; /* counter on quit attempts stop reboot jams -Bp */
static int save_level;
static string it;

int stuffed;
int soaked;	
int no_give;
string aprv;
string hint; /* password hint */
static int pc; /*password attempt count */
string *AnsiPref;
string old_last;
static string *player_ids;
static object *my_discon_box;
static string *blocking_pagers;
static status pageblock;
static status testchar_var;
static object gob;
static int attack_count;



#include "/closed/verte/super_secret_pass.h"
#include "/closed/verte/ansi_prefs.h"
#include "play/bank.h"
#include "/room/tune.h"  /* for determining QPs */

#define MAX_SOAK  (level * 8 + ex_lv * 2)
#define MAX_STUFF (level * 8 + ex_lv * 2)
#define MAX_INTOX ((level + 3) + (ex_lv / 5 + 1)) 

/* ======================================================================
 * Tox funs
 * ======================================================================
 */
query_stuffed() { return stuffed; }
add_stuffed(i) {
  if(i < 0 && (-i > stuffed / 10)) 
    i = -stuffed /10;
  stuffed += i;
  if (stuffed < 0) stuffed = 0;
}

query_soaked() { return soaked; }
void add_soaked(int i) {
  if(i < 0 && (-i > soaked /10)) 
    i = -soaked / 10;
  soaked += i;
  if (soaked < 0) soaked = 0;
}

drink_soft(strength) {
  if(strength > 0)
  if (soaked + strength > MAX_SOAK) {
    write("You can't possibly drink that much right now!\n" + 
      "You feel crosslegged enough as it is.\n");
    return 0;
  }
  soaked += strength * 2;
  if (soaked < 0)
    soaked = 0;
  if (soaked == 0)
    write("You feel a bit dry in the mouth.\n");
  return 1;
}

eat_food(strength) {
int jun;
  if(strength > 0)
  if (stuffed + strength > MAX_STUFF) {
    write("This is much too rich for you right now! Perhaps something"+
      " lighter?\n");
    return 0;
  }
  stuffed += strength * 2;
  if(stuffed > MAX_STUFF && random(100) < 15) {
    write("You really shouldn't eat so much.\n");
    this_object()->add_phys_ate(3, random(2));
    return 1;
  }
  if (stuffed < 0)
    stuffed = 0;
  if (stuffed == 0)
    write("Your stomach makes a rumbling sound.\n");
  return 1;
}

/* ======================================================================
 * Logon functions
 * ======================================================================
 */

query_msgin()   { return msgin;   }
query_msgout()  { return msgout;  }
query_mmsgin()  { return mmsgin;  }
query_mmsgout() { return mmsgout; }

clear_password() {
  if(query_ip_name(this_player()) && (int)this_player()->query_level() >= GOD)
    password = 0;
}

static logon() {
    int i, s;
    int j;
    object *us;
    string blockmsg;
  enable_commands();

  write("\n");
    blockmsg = call_other("obj/locklist","check_locklist", query_ip_number());
    if(blockmsg) {
    write(blockmsg +"\n");
    destruct(this_object());
    return;
    }
  cat ("/WELCOME");
  write("\n");
  s = sizeof(us=users());
  while(s--) {
    if(us[s]->query_invis()) continue;
    if(us[s]->query_level() <= 0) continue;
    if(us[s]->is_testchar()) continue;
    if(us[s]->query_level() <= 20) i ++;
    else j ++;
  }
  write("There are currently "+i+" players and "+j+" developers logged in.\n");
  write("Please use the guest name if you just want a look.\n\n");
  phys_at=allocate(6);
  tellblock=allocate(6);
  tellhistory=allocate(7);
  treasure_str=allocate(25);
  write("What is your name: ");
  sethost();
  input_to("logon2");
  call_out("timeout", 60);
  return 1;
}

shoutin () {
  int cexp,lvl,invs;
  string nom,wi;
  if(level > 0 && level < EXPLORE) {
    cexp=call_other("room/adv_guild", "check_level", level);
    add_alignment(0);
    if(experience < cexp) {
      call_other("room/adv_guild", "correct_level", this_object());
    }
    if (ex_lv) {
      cexp=call_other("room/exlv_guild", "check_level", ex_lv);
      if(experience < cexp) {
        call_other("room/exlv_guild", "correct_extra_level", this_object());
      }
    }
  }
  if(player_killing > 1) player_killing = player_killing - 2;
  add_ansi_pref("page", 0);
  add_ansi_pref("pk", 0);
  add_ansi_pref("title",0);
  add_ansi_pref("pretitle",0);
  lvl = this_player()->query_level();
  nom = capitalize(this_player()->query_name());
  invs = this_player()->query_invis();
  if(this_object()->is_testchar()) return 1;
  if(level > 19 || invs > 18) return 1;
  if(lvl > 9999) {wi = "God";lvl = 0;}
  if(lvl > 19 && lvl < 9999) { wi = "Wizard"; lvl = 0; }
  if(lvl > 0) {
    chan_msg(nom + " ( player " + lvl + (ex_lv ? 
             ("+" + ex_lv) : "") + " ) has entered the game.\n", "msg");
    return 1;
  }
  else chan_msg(nom + " ( " + wi + " ) has entered the game.\n","msg");
  return 1;
}

shoutout() {
  int lvl,invs;
  string nom,wi;
  lvl = this_object()->query_level();
  nom = capitalize(this_object()->query_name());
  invs = this_object()->query_invis();
  if(this_object()->is_testchar()) return 1;
  if(level > 19 || invs > 18) return 1;
  if(lvl > 9999) {wi = "God";level = 0;}
  if(lvl > 19 && lvl < 9999) {wi = "Wizard";level = 0;}
  if(lvl > 0) {
    chan_msg(nom + " ( player " + lvl + (ex_lv ? 
             ("+" + ex_lv) : "") + " ) has left the game.\n", "msg");
    return 1; 
  }
  else if(wi)
    chan_msg(nom + " ( "+wi+" ) has left the game.\n", "msg");
  return 1;
}

static timeout() {
  write("\nTimeout\n");
  destruct(this_object());
}

object other_copy;
static try_throw_out(str) {
  object check_copy,ob;
  string blah1,blah,tmp_name;
  remove_call_out("timeout");
  if (str == "" || (str[0] != 'y' && str[0] != 'Y')) {
    write("Come back another time then!\n");
    see_if_other(1);
    destruct(this_object());
    return;
  }
  tmp_name = name;
  name = 0;
  check_copy = find_player(tmp_name);
  if (!check_copy)
    check_copy = find_player("ghost of " + tmp_name);
  name = tmp_name;
  if (!check_copy) {
    write("Something has gone wrong, please try again...\n");
    log_file("BAD_PLAYER", ctime(time()) + " " + name + 
      " money cloning method #2\n");
    see_if_other(1);
    destruct(this_object());
    return;
  }

  ob = environment(other_copy);
  remove_interactive(other_copy);
  log_file("ENTER", cap_name +" (throw)\n");
  if(!interactive(other_copy))
    move_player_to_start(ob);
  else {
    write("Other copy is still interactive, forcing disconnection.\n");
    write("Continue? (y/n) ");
    input_to("try_throw_out");
  }
}

static logon2(str) {
  string ajunk,bjunk;
  remove_call_out("timeout");
  call_out("timeout", 120);
  if (!str || str == "") {
    destruct(this_object());
    return;
  }
  if (name != "logon") {
    illegal_patch("logon2");
    destruct(this_object());
    return;
  }
  str = lower_case(str);
  if (!valid_name(str)) {
    input_to("logon2");
    write("Give name again: ");
    return;
  }
  if (restore_object("banish/" + str)) {
    write("That name is reserved.\n");
    write("Please use another if you wish to create a new character.\n");
    write("Please try again soon.\n");
    destruct(this_object());
    return;
  }
  if (restore_object("pfiles/dumbasses/" + str)) {
    write("Go away.\n");
        destruct(this_object());
    return;
  }
  if (restore_object("players/inactive_saved/"+str)) {
    log_file("INACTIVE",name+" Attempt "+query_ip_name(this_object())+" ("+query_ip_number(this_object())+") "+ctime(time())+"\n");


    if(!password && !experience) {
      write("Your player file is no longer active.\n"+
        "write nirvana_lpmud@yahoo.com to be returned to active status.\n");
      destruct(this_object());
      return;
    }
    if(no_give > 1000 && time() - no_give < 1296000) {
      write("Inactivity must last MORE than 15 days.\n");
      write("Inactivity began at "+ctime(no_give)+"\n");
      write("Reactivation may occur after "+ctime(no_give+1296000)+"\n");
      write("Please try again later. write nirvana@nirvana.mudservices.com\n"+
            "if you have any questions.\n");
      destruct(this_object());
      return;
    }
    no_give = 0;
    write("Restoring from the inactive directory, Welcome Back!\n");
    inact = random(500);
    SET_HANDSHAKE(inact);
  }
  if(!inact)
    if (!restore_object("pfiles/" + extract(str,0,0) + "/" + str)) {
      write("New character.\n");
      mon = 1;
      new_pl_rest = 1;
      if (new_pl_rest) ResetStats();
  }
/* uncomment to lock game to wizards.
if(level < 21) {
      write("wizards only.\n");
     destruct(this_object());
    }
*/
  /* 05/15/06 Earwax: daemonized this: /obj/daemons/closed/ipcheck */
  if(level > 999) {
    string myip;
    myip = query_ip_number();
    if(!"/obj/daemons/closed/ipcheck"->check(myip, str)) {
      write("God and level 1000 access not allowed from your address.\n");
      destruct(this_object());
    }
  }

  name = str;
  see_if_other(2);
  dead = ghost;
  myself = this_player();
  soul = 0;
  /* Trying something. Fred 
  if(soul)
  destruct(soul);
  */
  if (query_invis(0) >= SOMEONE)
    cap_name = "Someone";
  else
    cap_name = capitalize(name);
  /* 03/20/06 Earwax: moved from call_out() to heart_beat() 
  if (level < EXPLORE)
    call_out("autosave", SAVE_INTERVAL);
  call_out("autoheal", INTERVAL_BETWEEN_HEALING);
  */
  sethost();
  local_weight = 0;
  armor_class = 0;
  name_of_weapon = 0;
  weapon_class = WEAPON_CLASS_OF_HANDS;

  if (level == -1)
    cat("/obj/msgs/new_player_passwd");
  
  write("Password: ");
  if (name == "guest") {
    write("(just CR) ");
  }
  if (level != -1)
    input_to("check_password", 1);
  else 
    input_to("new_password", 1);
  attacker_ob = 0;
  alt_attacker_ob = 0;
  save_level = level;
  level = 0;
  fight_area = 0;
  this_object()->testchar_check();
  return;
}

/* ======================================================================
 * 
 * ======================================================================
 */

save_character(arg) {
int diffexp, difftreasure;
  if(arg != "silent" && oldtreasure && oldexp && level < EXPLORE) {
    diffexp = experience - oldexp;
        compute_treasure();
    difftreasure = treasure - oldtreasure;
    if(difftreasure < 5000) { write("Ok.\n"); return 1;}
    if(diffexp < 1000 && level > 11 ) { write("Ok.\n"); return 1;}
    if(diffexp < 100 && level > 3  ) { write("Ok.\n"); return 1;}
    if(diffexp < 5000 && level > 17) { write("Ok.\n"); return 1;}
  }
  oldtreasure = treasure;
  oldexp = experience;
  save_me();
  if (arg != "silent")
    write("Ok.\n");
  return 1;
}

recalc_carry() {
  object ob, next_ob;
  local_weight = 0;
  if (myself)
  ob = first_inventory(myself);
  while (ob) {
    next_ob = next_inventory(ob);
    local_weight += call_other(ob, "query_weight");
    ob = next_ob;
  }
}

reset(arg) {
  if (!arg)
  {
    if(!channel_names)
    channel_names = ({"gossip","msg","risque","newbie","shout",});
    if(!atrbr)
      atrbr = ({charisma,dexterity,intelligence,luck,magic_aptitude,piety,stamina,stealth,strength,will_power,});
    if(!AnsiPref)
    AnsiPref = ({ "page", 0, "tell", 0, "gossip", 0, "risque", 0, "junk", 0, "babble", 0, "newbie", 0, "msg", 0, "announce", 0 });
     if(!saved_aliases)
    saved_aliases = ({ });
    if(!saved_nicknames)
    saved_nicknames = ({ });
    if(!nicknames)
    nicknames = ([ ]);
     if(!aliases)
    aliases = ([ ]);
    setup_stats();
  }
  set_max_spell();
  fight_area = 0;
  idlewarn = 0;
  noidlequit = 1;
  if(!blocking_pagers)
  blocking_pagers = ({ });
   if(!player_ids)
  player_ids = ({ });
  idletime = IDLELIMIT;

  set_max_hp();
  if (name){
    if (head_armor==capitalize(name)) head_armor =0;
  }
  if (!quest_point) 
    recalc_quest();
  if (arg) {
    if(this_object()->query_mounted()) {
      object mm;
      mm=this_object()->query_mounted();
      if(environment(this_object()) && 
        !present(mm, environment(this_object()))) {
      command("dismount "+mm->query_name());
      this_object()->clear_mounted();
      }
    }
    if (level >= EXPLORE) return;
    if (name == NAME_OF_GHOST) {
      ghost = 1;
      msgin = "drifts around";
      msgout = "blows";
    } else {
      ghost = 0;
      dead = 0;
      msgin = "arrives";
      msgout = "leaves";
    }
    recalc_carry();	
    return;
    }
    if (myself)
      return;
    if (creator(this_object())) {
      illegal_patch("cloned player.c");
      destruct(this_object());
      return;
    }
    set_heart_beat(1);
    level = -1;
    name = "logon";
    cap_name = "Logon";
    msgin = "arrives"; msgout = "leaves";
    mmsgin = "arrives in a puff of smoke";
    mmsgout = "disappears in a puff of smoke";
    msghome = "goes home";
    title = "the title-less";
    al_title = "neutral";
    treasure = 0;
    gender = 0;
    fight_area = 0;
}

query_spell_point() {
  if(this_object()->checkNM()) return -200;
  return spell_points;
}

short() {
  string tmp_pre;
  object ob;
  object pt_ob,mount;
  string st_desc,ab,bc,pt_nom,title_tmp,tlcol;
  int i;

  sscanf(file_name(this_object()), "%s#%s",ab,bc);
  if(ab!="obj/player") {
    illegal_patch("cloned player.c short");
    destruct(this_object());
    return;
  }

  pt_nom = 0;
  pt_ob = present("party object", this_object());
  if (pt_ob)
    pt_nom = call_other(pt_ob, "extra_short", 0);
  i = query_invis();
  mount = this_object()->query_mounted();
  if (this_player()) {
      i = query_invis(this_player()->query_level(),this_player()->query_extra_level());
  }
  if (i >= NO_SHORT)
    return 0;
  title_tmp = this_object()->query_title();
  if(query_frog()) title_tmp = "the Frog";
    
  st_desc = cap_name;
  if(title_tmp != "") st_desc += ((delete_colour(title_tmp)[0] == ',') ? "" : " ");
  st_desc += title_tmp;
  st_desc += NORM; /* no more bleeding titles */
  if(pretitle) {
    st_desc = this_object()->query_pretitle()+" "+st_desc;
  }
  if(pt_ob=present("player_short_object",this_object()))
    st_desc=(string)pt_ob->query_player_short();
  if((this_player() && this_player()==this_object()) || level > 21 || guild_name=="mage" || guild_name=="bloodfist") st_desc += " ("+query_al_title()+")";
  st_desc += 
    (is_interactive?"":" (disconnected)");
  if (i < 0) 
    st_desc=(st_desc+" ("+query_invis()+")"+
      (is_interactive ? "": " (disconnected)"));
  if (mount)
    st_desc = st_desc +  " mounted on " + mount->on_what();
  if (pt_ob && pt_nom != 0)
    st_desc = st_desc + " " + pt_nom;
  if(tmp_pre = (string)this_object()->query_testchar_owner())
    st_desc = "["+HIR+capitalize(tmp_pre)+" Test Character"+NORM+"] "+st_desc;
  if (ghost) 
    st_desc = "ghost of " + cap_name + 
      (is_interactive ? "" : " (disconnected)");
  if(afk_message)
    st_desc+=" (afk)";
  if("/pa/admin/pa-daemon"->query_name(name))
  {
    st_desc+= " ["+BOLD+"PLAYER AFFAIRS"+NORM+"]";
  }
  if(present("newbie_helper",this_object()))
    st_desc += " ("+HIB+"Newbie Helper"+NORM+")"
  ;
  if(player_killing && level < 21) st_desc = HIR+"[PK]"+NORM+" "+st_desc;
  if(this_player() && (this_player() != this_object()) && (ob = present("sight_short_modifier", this_player())))
  {
    return (string)ob->modify_short(st_desc);
  }
  if(present("essence of nirvana", this_object())) {
    st_desc = GRN+"<)"+NORM+st_desc+GRN+"(>"+NORM;
  }
  return st_desc;
}  

/* ======================================================================
 * 
 * ======================================================================
 */

long() {
    string a_or_an;
    status me_me;
    int ptime;
    string racetmp, tmptmp;
    if(this_object() == this_player()) me_me = 1;
    write(short() + " (" + gender + ")" + ".\n");
    if (call_other(this_player(),"query_level") >= EXPLORE) {
        if (level >= GOD) {
	    write("==> god\n");
        } else if (level >= ELDER) {
	    write("==> elder wizard\n");
        } else if (level >= SENIOR) {
	    write ("==> senior wizard\n");
        } else if (level > EXPLORE) {
	    write("==> wizard\n");
        } else if (level == EXPLORE) {
	    write("==> apprentice wizard\n");
	}
    }
     if(description) write(cap_name + " "+description+"\n");
     racetmp = race;
     if(frog) racetmp = "Frog";
    tmptmp = racetmp;
    racetmp = lower_case(delete_colour(racetmp));
    if(racetmp[0] == 'a' || racetmp[0] == 'e' || racetmp[0] == 'i' ||
      racetmp[0] == 'o' || racetmp[0] == 'u')
      a_or_an = 1;
    racetmp = tmptmp;
    write((this_player()==this_object()?"You are":cap_name+" is") + (a_or_an ? " an":" a")+" "+racetmp+", "+phys_at[1]+" feet "+phys_at[2]+" inches tall, "+phys_at[3]+" lbs.\n");
    if(pregnancy) {
         ptime=age-pregnancy;
         if(phys_at[3] > 250) ptime -= 600;
         if(phys_at[3] > 300) ptime -= 200;
         if(phys_at[3] > 350) ptime -= 400;
         if(phys_at[3] > 400) ptime -= 400;
       if(ptime > 4000) write(me_me?"You look":(cap_name+" looks"));
       if(ptime > 4000 && ptime < 5001) write(" about 3 months pregnant.\n");
       if(ptime > 5000 && ptime < 7200) write(" about 4 months pregnant.\n");
        if(ptime > 7199 && ptime < 9000) write(" about 5 months pregnant.\n");
        if(ptime > 8999 && ptime < 10800) write(" about 6 months pregnant.\n");
        if(ptime > 10799 && ptime < 12700) write(" about 7 months pregnant.\n");
        if(ptime > 12699 && ptime < 14400) write(" about 8 months pregnant.\n");
         if(ptime > 14399 && ptime < 163000) write(" about 9 months pregnant.\n");
          }
   if (player_killing) write((me_me?"You":cap_name)+" can fight other players.\n");
    if (ghost || frog)
	return;
    if (hit_point < max_hp/10) {
        write((me_me?"You are":cap_name+" is")+" in very bad shape.\n");
	return;
    }
    if (hit_point < max_hp/5) {
        write((me_me?"You are":cap_name+" is")+" in bad shape.\n");
	return;
    }
    if (hit_point < max_hp/2) {
        write((me_me?"You are":cap_name+" is")+" somewhat hurt.\n");
	return;
    }
    if (hit_point < max_hp * 9 / 10) { 
        write((me_me?"You are":cap_name+" is")+" slightly hurt.\n");
	return;
    }
    write((me_me?"You are":cap_name+" is")+" in good shape.\n");
}

/* ======================================================================
 * 
 * ======================================================================
 */

go_north() { command("north"); invs_counter(); return 1; }
go_south() { command("south"); invs_counter(); return 1; }
go_east()  { command("east");  invs_counter(); return 1; }
go_west()  { command("west");  invs_counter(); return 1; }
go_up()    { command("up");    invs_counter(); return 1; }
go_down()  { command("down");  invs_counter(); return 1; }
go_northwest() { invs_counter(); command("northwest"); return 1; }
go_northeast() { invs_counter(); command("northeast"); return 1; }
go_southwest() { invs_counter(); command("southwest"); return 1; }
go_southeast() { invs_counter(); command("southeast"); return 1; }

old_score() {
  log_file("earwax.player", ctime()+" old_score used: "+name+query_verb()+"\n");
  write("This has been deactivated.\n");
  write("Notify Earwax via mudmail or email immediately if you are reading this.\n");
  /* I placed this code in /obj/player/oldscore.c verbatim - Earwax */
  return 1;
}

player_id_check(arg) { return (member_array(arg, player_ids) > -1); }

id(str) {
    int i;

    i = query_invis();
    if (this_player())
        i = query_invis(call_other(this_player(),"query_level"));
    if (i < 0 && (str == name) || (player_id_check(str)))
        return 1;
    if (i >= NO_ID)
        return 0;
     if (ghost && str == "ghost of " + name)
          return 1;
    if (str == name || player_id_check(str))
	return 1;
   if(str == PLAYER_ID)
     return 1;
    return 0;
}


query_title() {
  string tlcol;
  return ((tlcol=get_ansi_pref("title")) ? tlcol+title+NORM : title);
}
query_pretitle() {
  string tlcol;
  
  if(!pretitle || pretitle == "") return 0;
  return ((tlcol=get_ansi_pref("pretitle")) != 0 ? tlcol+pretitle+NORM : pretitle);
}

set_pretitle(str) {
  if (!str) return 0;
  if (name == "guest") {
    write("guest cannot have a pretitle.\n");
  }
  else if (str == "|") {
    pretitle = 0;
  }
  else pretitle = extract(str, 0, 60);
  return 1;
}

set_level(lev) {
    if (lev > CREATE || lev < level && level >= EXPLORE)
        return illegal_patch("set_level");
    level = lev;
    set_max_hp();
    set_max_spell();
    if (level >= EXPLORE) {
        tell_object(myself, "Adding wizard commands...\n");
	soul("on");
    }
    if (level >= EXPLORE && soul)
        call_other(soul,"update",1);
    log_file("ADVANCE",ctime(time()) + " " +cap_name+" advanced to level "+level+"\n");
    save_me();
}

destruct_inventory() {
  object next_ob,ob;

  ob = first_inventory(this_object());
  while(ob) {
  	next_ob = next_inventory(ob);
    if (!call_other(ob, "id", "soul") && !call_other(ob,"id","wiz_soul"))
	    destruct(ob);
	  ob = next_ob;
  }
}

set_pk_title_time(t) { pk_title_time = t; }

set_title(t) {
  if(pk_title_time > time()) {
    write("You cannot set your title at this time.\n");
    write("You must wait "+(pk_title_time - time())+" seconds.\n");
    return 1;
  }
  if (t == "|") {
    write("Clearing your title.\n");
    title = "";
    return 1;
  }
  if (!t) {
	  write("Your title is " + title + ".\n");
	  return 1;
  }
  title = t;
  return 1;
}

set_wiz_level(key){
    string lev;
    int new_level;
    string verb;

    if (!interactive(this_player())) {
        write("Sorry, but you are not a player.\n");
        return 0;
    }
    lev = call_other(call_other(this_player(), "query_soul"),
	"get_handshake",key);
    if (lev) sscanf(lev,"%d",new_level);
    if(level > new_level) verb = "demoted";
    else verb = "promoted";
    level = new_level;
    tell_object(myself,"You were "+verb+" to level " + lev + " by " +

        capitalize(call_other(this_player(),"query_real_name")) + ".\n");
    tell_object(myself,"Remember to read the help files to determine your new abilities.\n");
    log_file("PROMOTIONS", "["+ctime()[4..15]+"] "+capitalize(name)+" was "+verb+" to Level " + lev +
        " by " + capitalize(this_player()->query_real_name()) +
	".\n");
    soul("off");
    save_me();
  if(soul)
    destruct(soul);
    soul("on");
    return 1;
}

do_quit(str) {
  if(str) return 0;
  if (file_size("/players/" + this_player()->query_real_name() +
    "/logout") < 1) 
    return quit();
  write("Do you wish to execute your logout file(y/N)? ");
  input_to("do_quit2");
  return 1;
}

do_quit2(str) {
  if (lower_case(str) == "y")
    soul->run_command_file("/players/" + this_object()->query_real_name() +
      "/logout", "quit");
  return quit();
}

quit() {
    object army;
    if(inact) inacttwo = inact;
    qc += 1;
    if(!this_object()) return;
    command("unkeep all", this_object());
    if(this_object()->query_mounted()) {
      object mm;
      mm=this_object()->query_mounted();
      if(environment())
      move_object(mm,environment(this_object()));
	      command("dismount "+mm->query_name());
    }
    power = 0;
    if(qc < 5) {
    if (level < EXPLORE)
    {
     army = present("armageddon",find_object("room/church"));
     if(army) 
       if(army->query_goingdown()) 
         cross_reboot_save();
	drop_all(1);
    }
    if(!stringp(lastime)) lastime = "UNKNOWN";
    if(strlen(lastime) > 70) lastime ="UNKNOWN";
    if(query_invis() < 19)
    {
    lastime=lastime+" to "+ctime()[4..15]+ctime()[19..24];
   }
    clear_followers();
    save_me();
    shoutout();
    }
    if(qc > 4) save_me();
    destruct_inventory();
    if (level >= EXPLORE) { write("Inventory destructed.\n");
       rm("/log/"+this_object()->query_real_name()); }
    write("Saving "); write(capitalize(name)); write(".\n");
    checked_say(cap_name + " left the game.\n");
    log_file("ENTER", extract(ctime(time()),4,15) + " " + name + " exit " + experience +
             " ep, " + money + " g. "+called_from_ip+"\n");
    if(inact) {
      no_give = time();
      save_object("players/inactive_saved/"+name);
      inacttwo = 0;
      rm("/pfiles/"+extract(name,0,0)+"/"+name+".o");
    }
    destruct(this_object());
    return 1;
}

valid_attack(ob) {
  int their_level, can_attack;
  object here,here2;
  
  if(name=="guest" && !ob->query_npc()) return 0;    
  if(this_player() && (ob == this_player())) return 0;
  if(environment(this_object())->query_no_fight()) {
    write("Fighting is NOT allowed to begin here.\n");
    return 0;
  }
  if(call_other(ob, "is_player") && !call_other(ob, "query_interactive")) {
    write("You cannot attack disconnected players.\n");
    return 0;
  }

  /* Put these as close to the top as possible, reduce lag -Bp */
  /* If we're already fighting them, then it must be OK. */
  if (ob == attacker_ob || ob == alt_attacker_ob) return 1;
  /* They can always attack NPCs */
  if (call_other(ob, "query_npc")) return 1;

  if (ob->is_player() &&
      environment()->query_no_pk()) {
    write("PK is NOT allowed to begin here.\n");
    return 0;
   }
  if((int)ob->query_guild_name()=="Nosferatu" && guild_name=="Nosferatu") {
    return 1;
  }
  if (call_other(ob, "is_player")) {
    if (call_other(ob, "query_level", 0) > 19) {
      write("You can't attack a wizard!\n");
      tell_object(ob, name+" tried to attack you.\n");
      return 0;
    }
    if (call_other(this_object(), "query_level", 0) > 19) {
      write("Wizards cannot attack players!\n");
      return 0;
    }
    their_level = ob->query_level();
    if(their_level < 8 && level - their_level > 3) {
      write("Pick on someone your own size.\n");
      return 0;
   }
   if(level < 8 && their_level - level > 3) {
     write("You shouldn't be picking fights like that.\n");
     return 0;
   }
  }
  here=environment(this_object());
  here2=environment(ob);
  if(fight_area && ob->query_fight_area() && fight_area == file_name(here)) {
    if(this_object()->query_level() > 2 && ob->query_level() > 2) 
    return 1;
  }
  if(ob->query_pl_k() > 1 || this_object()->query_pl_k() > 1) {
    if(here2->query_spar_area() && here->query_spar_area()) return 1;
    write("One or both pk flags are set to spar.This is not a sparing area.\n");
    return 0;
    } 
  if(ob->query_pl_k() && this_object()->query_pl_k() && 
    this_object()->query_level() > 2 && ob->query_level() > 2)
    return 1;
  
  return 0;
}

communicate(str) {
    if (!str) {
	write("Say what?\n");
	return 1;
    }
str = format(str,60);
    if (ghost) {
	say(short() + " says: " + str + ".\n");
        if (brief == 1)
	    write("Ok.\n");
	else
	    write("You say: " + str + "\n");
	return 1;
    }
    say(cap_name + " says: " + str + "\n");
    if (brief == 1)
	write("Ok.\n");
    else
	write("You say: " + str + "\n");
    return 1;
}

static autosave() {
    if (brief != 1)
	write("\nAutosaving character...\n");
    if (idlewarn && is_interactive && query_idle(this_object()) < IDLELIMIT) 
       idlewarn = 0;
    if(call_other("room/prison", "query_locked", name)) { 
    write("You should be in prison, back you go.\n");
    say(cap_name+" is sucked into a blue light beam back to the prison.\n");
    move_object(this_object(), "room/prison");
    }
    /* 03/29/06 Earwax: using a command() instead to force save
    save_me();
    */
    command("save silent", this_object());
    /* 03/20/06 Earwax: moved to heart_beat()
    call_out("autosave", SAVE_INTERVAL);
    */
}

/* hp_regen_object & sp_regen_object code by verte, recoded by earwax */

static autoheal() {
  int x, ack;
  object regen_ob,ob;
    
  if (headache && !(--headache)) /* Earwax */
    tell_object(myself, "You no longer have a head ache.\n");
      
  x=2; ack = 0;
  if( regen_ob = present("hp_regen_object", this_object()) ) {
    while(regen_ob) {
      x += (int)regen_ob->query_hp_regen();      
      ack++;
      regen_ob = present("hp_regen_object "+ack, this_object());
    }
    ack = 0;
  }
  if(!query_attack()) {
    hit_point += intoxicated ? (3*x) : x; 
    if (hit_point > max_hp)
      hit_point = max_hp;
  }
  x=2; ack = 0;
  if( regen_ob = present("sp_regen_object", this_object()) ) {
    while(regen_ob) {
      x += (int)regen_ob->query_sp_regen();      
      ack++;
      regen_ob = present("sp_regen_object "+ack, this_object());
    }
    ack = 0;
  }    
    
  if(!query_attack()) {
    spell_points += intoxicated ? (3*x) : x;
    if(spell_points > max_spell)
      spell_points=max_spell;
  }
        
  if (intoxicated && !(--intoxicated)) { /* 05/15/06 Earwax */
    headache = max_headache; max_headache = 0;
    tell_object(myself, "You suddenly without reason get a bad head ache.\n");
    if ((hit_point -= 3) < 0) hit_point = 0;
  }
   /* 03/20/06 Earwax: moved callout to heart_beat() */
}

static intoxicate() {
  string cs, w;

  if (!intoxicated) return;
  call_out("intoxicate", 5 + random(56));
  
  switch(random(7)) {
    case 0 .. 2: return;
    case 3: cs = " hiccups.\n"; w = "You hiccup.\n"; break;
    case 4: cs = " seems to fall, but takes a step and recovers.\n"; w  = "You stumble.\n"; break;
    case 5: cs = " looks drunk.\n"; w = "You feel drunk.\n"; break;
    case 6: cs = " burps.\n"; w = "You burp.\n";
  }
  checked_say(cap_name + cs);
  write(w);
}

heart_beat() {
  int att_mhp,timetoboot,myidletime;
  if(!this_object()) return;
  if (!afk_message && interactive(this_object())) {
    myidletime = query_idle(this_object());
    if(myidletime > 600 && (!this_object()->query_afk_message()))
      command("afk idle", this_object());
  }
  if (!interactive(this_object()) && is_interactive) {
    say(capitalize(name)+" just disconnected.\n");
    /* Stop cheaters with treasure -Bp */
    timetoboot=call_other("obj/time_check","discon_check",0);
    if(timetoboot > 900)
      call_out("discon_quit", 900);
    else if(timetoboot > 200 && timetoboot < 901)
      call_out("discon_quit",timetoboot-100);
    else if(timetoboot > 15 && timetoboot < 201)
      call_out("discon_quit",timetoboot-8);
    else
      discon_quit();
  }
  if(!this_object()) return;
  is_interactive = interactive(this_object());
  channelcount = 0;
  set_max_spell();
  set_max_hp();
  attack_count = 0;
  if(PKGhostCounter && !(PKGhostCounter -=2))
    tell_object(this_object(), "\nYou may now revive from your incorporeal form.\n\n");
  if(ghost) return;
  if (is_interactive) 
  {
    if(myidletime < idletime+300) 
    {
      if(name != "vertebraker")
        age += 1;
      if(alignment < 0 && random(10) < 1) alignment += 1;
      if(alignment > 0 && random(10) < 1) alignment -= 1;
    }

    if(infuse > 0)
      infuse -= 1+random(3);
     else infuse = 0;

    /* infuse = (infuse ? infuse-- : 0); Fred [5.23.06] */
  }
  /* 
   * ========================================================
   * Pregnancy stuffs - move this to /obj/player/pregger.c 
   */
  if (pregnancy && myidletime < idletime+300) {
    int pregtmp;
    pregtmp = age - pregnancy;
    if(pregtmp == 2000) add_phys_at(3,5+random(kc()));
    if(pregtmp == 3000) add_phys_at(3,random(5)+random(kc()));
    if(pregtmp == 4000) add_phys_at(3,2+random(4)+random(kc()));
    if(pregtmp == 6000) add_phys_at(3,2 + random(4)+random(kc()));
    if(pregtmp == 8000) add_phys_at(3,2+random(4)+random(kc()));
    if(pregtmp == 10000) add_phys_at(3,1+random(10)+random(kc()));
    if(pregtmp == 12000) add_phys_at(3,3 +random(8)+random(kc()));
    if(pregtmp == 14000) add_phys_at(3,2+random(8)+random(kc()));
    if(pregtmp == 15500) add_phys_at(3,1+random(8)+random(kc()));
    if(pregtmp == 16500) add_phys_at(3,1+random(8)+random(kc()));
    if(pregtmp == 17500) add_phys_at(3,1+random(8)+random(kc()));
    if(pregtmp == 18500) add_phys_at(3,1+random(8)+random(kc()));
    if(pregtmp < 3000 && pregtmp > 500) {
      if(random(4000) < 3 || phys_at[4]==4001) { 
        write("You feel sick, like you are going to puke.\n");
        if(phys_at[4] > 4000) phys_at[4]=0;
        add_phys_at(3,-random(3));
        if(random(100) < 10) {
          write("You bend over and puke.\n");
          say(cap_name+" doubles over and pukes.\n");
        }
      }
      if(random(5000) < 3) {
        write("You feel a strange hunger for food.\n");
      }
    }
    if(pregtmp > 1000 && pregtmp < 18000) {
      object bbb;
       if(random(9000) < 3 || phys_at[4]==4004) {
       int rrx;
       rrx = random(3);
       if(phys_at[4] > 4000) phys_at[4]=0;
       if(rrx == 0)
         tell_object(this_object(),"You have a strange craving for peanut butter and hotdog sandwiches.\n");
       if(rrx == 1)
         tell_object(this_object(),"You have a strange craving for pickles and ice cream.\n");
       if(rrx == 2)
        tell_object(this_object(),"Your feet feel swollen.\n");
     }
      if(random(8200) < 2 || phys_at[4]==4002) {
        tell_object(this_object(),"Your breasts feel heavier and"+
          " larger.\n");
        if(phys_at[4] > 4000) phys_at[4]=0;
        say(cap_name+" wiggles uncomfortably as though her top is"+
          " too tight.\n");
        bbb=present("boobs",this_object()); 
        if(bbb) {
          bbb->add_cup(1);
          bbb->add_bust(1);
        }
      }
    }
    if(pregtmp > 12000) {
      if(random(25000) < 40 || phys_at[4]==4003) {
        if(phys_at[4] > 4000) phys_at[4]=0;
         tell_object(this_object(),"You feel the baby kick inside you.\n");
         say(cap_name+" jumps up as though something startled her.\n");
      }
    }
    if(pregtmp > 11000) {
      if(random(29000) < 40 || phys_at[4]==4004) {
        if(phys_at[4] > 4000) phys_at[4]=0;
        tell_object(this_object(),"You suddenly need to pee...really, really bad.\n");
      }
    }
    if(pregtmp > 15840) {
      if(random(1000) < 20)
        tell_object(this_object(),"You feel labor pains.\n");
    }
    if(pregtmp > 16200+random(500)) 
      if(random(900000) < pregtmp && phys_at[4]!=5001) 
      child_birth();
  }
  /* 
   * End of preggers stuff that should be daemonized
   * ========================================================
   */
   
  already_fight = 0;
  if(is_interactive) {
    if (stuffed) {
      if(attacker_ob) { if(!random(3)) stuffed --; }
      else stuffed -= (1+random(3));
    }
    if (soaked) {
      if(attacker_ob) { if(!random(3)) soaked --; }
      else soaked -= (1+random(3));
    }
  }
  

  if(soaked < 0) soaked = 0;
  if(stuffed < 0) stuffed = 0;
  
  /* 
   * Exactly what is this for???
   * No function attack_check() defined anywheres
   * Commenting this out for now 
   * 05/15/06 Earwax
   */
  /*
  if (attacker_ob)
  {
    if(present("player_attack_object", this_object()) 
    && this_object()->attack_check()) {
      int no_hits;
      object aob, bob;
      aob = first_inventory(this_object());
      while(aob){
        bob = next_inventory(aob);
        if(aob->id("player_attack_object")) {
          if(!no_hits && aob->player_attack_no_hit()) {
            no_hits = 1;
          }
          aob->player_attack();
         }
         aob = bob;
      }
      if(!no_hits){
        this_object()->toggle_already_fight(1);
        attack();
      }
    }
    else
    {
      attack();
    }
  }
  */
  if (attacker_ob)
    attack();
  /*
   * End of bogglement (laf, not really)
   */
   
  dam_taken_this_round=0;
   
  if(attacker_ob) {
    if (whimpy && hit_point < max_hp*whimpy/100) {
      if(whimpy_delay) { whimpy_delay = 0; run_away(); }
      else whimpy_delay = 1;
    }
    if (mon) print_monitor();
  }
  process_do_cmd();
  if(!noidlequit) {
    if (!idlewarn && is_interactive && myidletime > idletime) {
      write("You have been idle for "+idletime/60+" minutes. You will be logged off in "+ 
        "5 minutes.\n");
      idlewarn = 1;
    }
    if(idlewarn && is_interactive && myidletime < idletime) 
      idlewarn = 0;
    if(is_interactive && myidletime > idletime+300) {
      tell_object(this_object(), "Idle too long.....\n");
      if(level > EXPLORE) write(ctime(time())+"\n");
      log_file("ENTER", name + " idle quit ");
      call_other(this_object(), "discon_quit", 0);
    }
  }
  /* 03/20/06 Earwax: moved these to heart_beat() rather than call_out() */
  if (level < EXPLORE) {
    if ((autosave_counter += 2) >= SAVE_INTERVAL) {
      autosave_counter = 0;
      autosave();
    }
    if ((autoheal_counter += 2) >= INTERVAL_BETWEEN_HEALING) {
      autoheal_counter = 0;
      autoheal();
    }
  }
}

add_alignment(a) { /* 05/11/06 Earwax: recoded some of this */
  if (a == 0) return;
  
  if(this_player() && this_player()->is_player() 
  && this_player()->query_level() > EXPLORE 
  && this_player()->query_level() < GOD 
  && this_object()->is_testchar() > 0)
    return 0;

  if(level != 30)    
    alignment -= (alignment*2/(30-level));
  if(level == 30)
    alignment -= (alignment*2/(31-level)); 

  alignment += a;
  if(alignment > CAP_GOOD_ALIGN) alignment = CAP_GOOD_ALIGN;
  if(alignment < CAP_EVIL_ALIGN) alignment = CAP_EVIL_ALIGN;
  if (alignment > KILL_NEUTRAL_ALIGNMENT * 64) {
	  al_title = "white lord";
	  return;
  }
  if (alignment > KILL_NEUTRAL_ALIGNMENT * 32) {
	  al_title = "paladin";
	  return;
  }
  if (alignment > KILL_NEUTRAL_ALIGNMENT * 16)
	  al_title = "crusader";
  else if (alignment > KILL_NEUTRAL_ALIGNMENT * 8) 
  	al_title = "good";
	else if (alignment > KILL_NEUTRAL_ALIGNMENT * 4) 
  	al_title = "honorable";
	else if (alignment > - KILL_NEUTRAL_ALIGNMENT * 4) 
  	al_title = "neutral";
	else if (alignment > - KILL_NEUTRAL_ALIGNMENT * 8)
  	al_title = "malicious";
	else if (alignment > - KILL_NEUTRAL_ALIGNMENT * 16) 
  	al_title = "evil";
	else if (alignment > - KILL_NEUTRAL_ALIGNMENT * 32)
  	al_title = "infamous";
	else if (alignment > - KILL_NEUTRAL_ALIGNMENT * 64) 
		al_title = "black knight";
  else
    al_title = "lord of evil";
}

test_dark() { /* 05/11/06 Earwax: recoded this */
  if (set_light(0) > 0 || present("dark_sight_object", this_object()))
    return 0;
  if (level > SENIOR) {
    write("But you may still see...\n");
    return 0;
  }
  return 1;
}

put(str) {
    int i;
    string item;
    string container;
    object item_o;
    object container_o;

    private;
    if (!str)
	return 0;
    power = 0;
    if (level >= ITEM_OVER)
        if (sscanf(str,"! %s",power) == 1) {
            str = power;
	    power = "!";
        }
    if (this_object()->test_dark())
	return 1;
    if (sscanf(str, "%s in %s", item, container) != 2) {
	write("put what?\n");
	return 1;
    }
    container = lower_case(container);
    container_o = present(container, this_player());
    if (!container_o)
	container_o = present(container, environment(this_player()));
    if (!container_o) {
	write("There are no " + container + "s here!\n");
	return 1;
    }
    if (!call_other(container_o, "can_put_and_get", 0) && !power) {
	write("You can't do that.\n");
	return 1;
    }
    if(item == "all") {
      object a, b;
      a = first_inventory(this_player());
      while(a) {
        b = next_inventory(a);
        if(a->query_name() && !a->drop()) {
          write((string)a->short()+" ... ");
          put((string)a->query_name()+" in "+container);
        }
        a = b;
      }
      return 1;
    }
    item = lower_case(item);
    item_o = present(item, this_player());
    if (!item_o) {
	write("You have no " + item + "!\n");
	return 1;
    }
    if (item_o == container_o)
	return 0;
    if (call_other(item_o, "prevent_insert") && !power)
	return 1;
    if (call_other(item_o, "drop", 0) && !power)
	return 1;
    if (!item_o)
        return 1;
    i = call_other(item_o, "query_weight");

    if((item_o->can_put_and_get()) && !item_o->is_armor() && !item_o->is_weapon())

    {
      write("You can't put a container inside another container.\n");
      return 1;
    }
    if (call_other(container_o, "add_weight", i) || power) {
	call_other(environment(item_o), "add_weight", -i);
	move_object(item_o, container_o);
	checked_say(cap_name + " puts the " + item + " in the " + container + ".\n");
	write("Ok.\n");
	it = item;
	return 1;
    }
    write("There is not room for more.\n");
    return 1;
}

pick_up(str) {
    string item;
    string container;
    object item_o;
    object container_o;


    private;
    if (!str) {
	write("Get what?\n");
	return 1;
    }
    power = 0;
    if (level >= ITEM_OVER)
    if (sscanf(str,"! %s",power) == 1) {
            str = power;
	    power = "!";
        }
    if (ghost && !power) {
	write("Your incorporeal hand passes right through it.\n");
	return 1;
    }
    if (this_object()->test_dark() && !power)
	return 1;
    if (str == "all") {
	get_all(environment());
	return 1;
    }
    if (sscanf(str, "%s from %s", item, container) != 2) {
	pick_item(str);
	return 1;
    }
    container_o = present(lower_case(container), environment(this_player()));
    if(!container_o) container_o = present(lower_case(container), this_player());
    if(container == "bag")
      container_o = present(lower_case(container), this_player());
    if (!container_o) {
	write("There is no " + container + " here.\n");
	return 1;
    }
    if (!call_other(container_o, "can_put_and_get", 0) && !power) {
	write("You can't do that!\n");
	return 1;
    }
    if (item == "all") {
        get_all(container_o);
	return 1;
    }
    item_o = present(item, container_o);
    if (item_o) {
	if (call_other(item_o, "id", item)) {
	    int weight;
	    if (living(container_o) &&
	        call_other(item_o, "drop", 1) && !power) {
		write("You can not take " + item + " from " +
		      container + ".\n");
		return 1;
	    }
	    if (!call_other(item_o, "get", item) && !power) {
		write("You can not take " + item + " from " +
		      container + ".\n");
		return 1;
	    }
	    weight = call_other(item_o, "query_weight");
	    if (!add_weight(weight) && !power) {
		write("You can not carry more.\n");
		return 1;
	    }
	    call_other(container_o, "add_weight", -weight);
	    move_object(item_o, myself);
	    it = item;
	    write("Ok.\n");
	    checked_say(cap_name + " takes " + item + " from " + container + ".\n");
	    return 1;
	}
    }
    write("There is no " + item + " in the " + container + ".\n");
    return 1;
}

 pick_item(obj) {
    object ob;
    int i;

    obj = lower_case(obj);
    ob = present(obj, environment(this_player()));
    if (!ob) {
	write("That is not here.\n");
	return 1;
    }
    if (ghost && !power) {
	write("You fail.\n");
	return 1;
    }
    if (environment(ob) == myself) {
	write("You already have it!\n");
	return 1;
    }
    if (!call_other(ob, "get") && !power) {
	write("You can not take that!\n");
	return 1;
    }
    i = call_other(ob, "query_weight");
    if (add_weight(i) || power) {
	move_object(ob, myself);
	checked_say(cap_name + " takes " + obj + ".\n");
	it = obj;
	write("Ok.\n");
	return 1;
    }
    write("You can't carry that much.\n");
    return 1;
}

drop_thing(obj) {
    string tmp;
    string tmp2;
    int x;
    int i;

    private;
    power = 0;
    if (level >= ITEM_OVER)
        if (sscanf(obj,"! %s",power) == 1) {
            obj = power;
	    power = "!";
        }
    if (!obj) {
	write("What?\n");
	return 1;
    }
    if (obj == "all") {
	drop_all(1);
	return 1;
    }
    if(sscanf(obj, "%d coins", x) || sscanf(obj, "%d money", x) ||
       sscanf(obj, "%d gold coins", x) || sscanf(obj, "%d coin", x))
    {
      object gold;
      if(x <= 0 || (int)this_player()->query_money() < x)
        return (write("You only have " + money + " coins.\n"), 1);

      gold = clone_object("/obj/money");
      gold->set_money(x);
      move_object(gold, environment(this_player()));
      this_player()->add_money(-x);
      write("You drop " + x + " " + (x == 1 ? "coin" : "coins") + ".\n");
      say(this_player()->query_name() + " drops some coins.\n");
      return 1;
    }
    if (sscanf(obj, "%s in %s", tmp, tmp2) == 2) {
        put(obj);
	return 1;
    }
    if (obj == "money" || obj == "coins") 
     if(!present("money",this_object())) {
       write("You may drop a certain amount of money, or 'all money'\n");
       return 1;
     }
     if(obj == "all coins" || obj == "all money") {
     if (no_give){
     write("You cannot drop money while another copy is logging in.\n");
     return 1;
     }
	drop_all_money(1);
	return 1;
    }
    tmp = obj;
    obj = present(lower_case(obj), this_player());
    if (!obj) {
	write("That is not here.\n");
	return 1;
    }
    if (drop_one_item(obj)) {
	it = tmp;
	write("Ok.\n");
	checked_say(cap_name + " drops the " + tmp + ".\n");
    }
    return 1;
}

query_weight() { return 80; }

add_weight(w) {
    int max;


  if(strength < 21)
    max = level + 6 + strength/5;
  if(strength > 20)
    max = level + 10 + (strength-20)/5;
    if (level == 1)
    max = level + 6 + strength/2;
    if(ex_lv) max += (ex_lv / 4);
    if (frog)
	max = max / 2;
    if (w + local_weight > max || w + local_weight < 0)
	return 0;
    local_weight += w;
    return 1;
}

static shout_to_all(str) { /* 05/11/06 Earwax: yanked the rest of this */
  write(format("Use the channels to shout as explained on the command " +
               "help channels.\n"));
  return 1;
}

inv() { /* 05/11/06 Earwax: reformatted the code */
  object ob;
  
  if (test_dark()) return 1;
  ob = first_inventory(myself);
  while (ob) {
  	string str;
  	str = call_other(ob, "short");
	  if (str) {
	    write(str + ".\n");
	    it = str;
	  }
	  ob = next_inventory(ob);
  }
  write("Carrying "+this_object()->query_pct_weight()+"% of maximum capacity.\n");
    return 1;
}

examine(str) { return (command("look " + str, this_player())); }
glance() {  return look(0,1); }

look(str, remote) {
    object ob, ob_tmp;
    string item;
    int max;
    if (this_object()->test_dark())
	return 1;
    if(present("blindness_object", this_object()))
    {
      write("You can't see!\n");
      return 1;
    }
    if (!str) {
        if (remote) {
	    write(call_other(environment(), "short")); write("\n");
	} else {
         if(brief == 2) {
           string sdec;
           string vsdec;
           int sdecl,lkcol;
            sdec=call_other(environment(), "short");
            sdecl = strlen(sdec);
            sdecl=40-(sdecl/2);
            if(lkcol=get_ansi_pref("roomtitle"))
              write(pad(" ",sdecl-1)+lkcol+sdec+NORM+"\n");
            else
            write(pad(" ",sdecl-1)+sdec+"\n");
          }
	    call_other(environment(), "long");
	}
	ob = first_inventory(environment());
	max = MAX_LIST;
	while(ob && max > 0) {
	    if (ob != myself) {
		string short_str;
		short_str = call_other(ob, "short");
		if (short_str) {
		    max -= 1;
		    write(short_str + ".\n");
		    it = short_str;
		}
	    }
	    ob = next_inventory(ob);
	}
  if(player_killing && environment()
  && call_other("/obj/play/move_tracker","check_blood",file_name(environment())))
    write("You detect the blood of a player killer.\n");
	return 1;
    }
    if (sscanf(str, "at %s", item) || sscanf(str, "in %s", item) || (item = str))
    {
	item = lower_case(item);
	ob = present(item, this_player());
        if(!ob) ob = present("_"+item+"_", this_player());
         /* security for player-made-to-order objects -Bp */
	if (!ob && call_other(environment(this_player()), "id", item))
	    ob = environment(this_player());
	if (!ob)
	    ob = present(item, environment(this_player()));
	if (!ob) {
	    write("There is no " + item + " here.\n");
	    return 1;
	}
	it = item;
	call_other(ob, "long", item);
        if(!ob->is_player() && living(ob)) say(cap_name+" looks at "+ob->query_name()+"\n");
        if(ob->is_player()) {
          if(environment(this_object())==environment(ob)){
            if(ob != this_object()) {
              tell_object(ob,cap_name+" looks at you.\n");
              say(cap_name + " looks at " + ob->query_name() + "\n", ob);
            } else
              say(cap_name+" looks at "+query_objective()+"self in a reflection.\n");
          }
          if(level < EXPLORE && environment(this_object())!=environment(ob))
            tell_object(ob,cap_name+" looks at you from afar.\n");
       }
        if(present("look_block", ob)) {
           return 1;
         }
	if (!call_other(ob, "can_put_and_get", item))
	    return 1;
        if (living(ob)) {
	    object special;
	    special = first_inventory(ob);
	    while (special) {
                object special2;
	        string extra_str;
                special2 = next_inventory(special);
		extra_str = call_other(special, "extra_look");
		if (extra_str)
		    write(extra_str + ".\n");
                special = special2;
	    }
	}
	ob_tmp = first_inventory(ob);
	while (ob_tmp && call_other(ob_tmp, "short") == 0)
	    ob_tmp = next_inventory(ob_tmp);
	if (ob_tmp) {
	    if (living(ob))
            {
                if(ob == this_player()) write("\tYou are carrying:\n");
                else
		write("\t" + capitalize(item) + " is carrying:\n");
            }
	    else
		write("\t" + capitalize(item) + " contains:\n");
	}
	max = MAX_LIST;
	ob = first_inventory(ob);
	while (ob && max > 0) {
	    string sh;
	    sh = call_other(ob, "short");
	    if (sh)
		write(sh + ".\n");
	    ob = next_inventory(ob);
	    max -= 1;
	}
	return 1;
    }
    write("Look AT something, or what?\n");
    return 1;
}

static check_password(p) {
    if (password == 0 && name != "guest")
        write("You have no password! Set it with the 'password' cmd.\n");
    else if (name != "guest" && (crypt(p,extract(password,0,1)) != password)) {
        if (p != "hint") write("Wrong password!\n");
        if (p != "hint" && hint && pc < 2) write("Try 'hint' if you forgot.\n");
    if(p == "hint") {
      if (save_level < EXPLORE && hint) write("Password hint: "+hint+"\n");
      if (save_level < EXPLORE && !hint) write("No hint set.\n");
      if (save_level >= EXPLORE) write("No hints for wizards, sorry.\n");
    }
         see_if_other(1);
        pc += 1;
        if(pc > 2)
	destruct(myself);
        write("Password: ");
        input_to("check_password", 1);
	return;
    }
    if(inact) {
      save_me(3);
      rm("/players/inactive_saved/"+name+".o");
      log_file("INACTIVE",name+" returned from inactive. \n");
      inact = 0;
    }   

    write("\n");
    level = save_level;
    add_commands();
  if(soul)
    destruct(soul);
    soul("on");
  init_channels();
  if (!mailaddr || mailaddr == "")
  {
    write("Please enter your email or web page address (or 'none'): ");
      new_pl_rest = 1;
    input_to("getmailaddr");
    return;
  }
    if (!hint || hint == "") {
    if (level < EXPLORE ) {
    write("Please enter a password reminder hint.\n");
    write("Please note anyone may view it.\nHint: ");
    new_pl_rest = 1;
    pc = 987;
    input_to("gethint");
    return;
    }}
  

  if(saved_where) {
   write("Return to previous location? ");
   call_out("timeout",60);
   input_to("prevloc");
   return;
  }
    if(!gender || !phys_at[1] || !phys_at[3]) {
        write("Please select a gender, either male or female: ");
        new_pl_rest=1;
        input_to("new_gender");
    } else {
        move_player_to_start(0);
    }
}

/*
 * Give a new password to a player.
 */
static new_password(p) {
    private;
    if (!p || p == "") {
        write("You have aborted the character creation process.\n");
	write("Try again another time then.\n");
	destruct(myself);
	return;
    }
    if (strlen(p) < 6) {
        write("The password must be at least 6 characters long.\n");
	write("Password: ");
	input_to("new_password", 1);
	return;
    }
    if (password == 0) {
	password = p;
	write("Password: (again) ");
	input_to("new_password", 1);
	return;
    }
    if (password != p) {
	write("You changed !\n");
        cat("/obj/msgs/passwd_not_match");
	destruct(myself);
	return;
    }
    password = crypt(password,0);
    call_other("room/adv_guild", "advance", 0);
    hit_point = max_hp;
    add_commands();
  init_channels();
    write("\n");
    cat("/obj/msgs/hint");
    write("Hint: ");
    input_to("getnewhint");
}
getnewhint(phint) {
    hint = phint;
    cat("/obj/msgs/gender");
    write("Please select a gender, either male or female: ");
    input_to("new_gender");
}

static new_gender(str) {
    str = lower_case(str);
    if (str == "creature" || str == "male" || str == "female") {
      gender = str;
      cat("/obj/msgs/race");
      write("Race:");  
      input_to("new_race");
    } else {
	write("You must select either male or female: ");
	input_to("new_gender");
    }
}

/* 05/11/06 Earwax: Did some formatting on this */
static move_player_to_start(where) { 
  object ob;
  int treas_c;
  string junk,junkb,tmp_name;
  
  tmp_name = name;
  name = 0;
  other_copy = find_player(tmp_name);
  if (!other_copy)
  	other_copy = find_player("ghost of " + tmp_name);
  name = tmp_name;
  if (other_copy && other_copy != this_object()) {
    if (interactive(other_copy)) {
      write("You are already playing!\nReconnect? ");
      call_out("timeout",60);
      input_to("try_throw_out");
    }
    else {
      write("Reconnecting to linkdead character.\n");
      log_file("ENTER", name+" (reconnect)\n");
      other_copy->rem_discon();
      if(!exec(other_copy, this_object())) {
        write("Something has gone wrong....\n");
        write("Transfering items to storage box, removing other copy.\n");
        other_copy->set_saved_where(file_name(environment(other_copy)));
        other_copy->discon_quit();
        /* Crude patch to fix exec failures  -Bp */
        destruct("obj/player");
         /* Log it */
         log_file("EXEC",name+" had exec fail.\n");
         write("Disconnecting, please try again...\n");
      }
      destruct(this_object());
 
      if (other_copy)
      if (environment(other_copy))
        tell_room(environment(other_copy),
          capitalize(name) + " reenters the game.\n");
    }
    return;
  }
  set_living_name(name);
  if(soul)
    destruct(soul);
  soul("on");
   
  if(level >= CREATE)
    write(read_bytes("/WIZNEWS", 0, file_size("/WIZNEWS")));
  else {
    if(where == "room/adv_guild") cat("/doc/short_news");
    if(where != "room/adv_guild")
      write(read_bytes("/NEWS", 0, file_size("/NEWS")));
  }
  if(name=="guest") {
    write("\nNote: guest will automatically quit after 200 seconds\n");
    log_file("GUEST",extract(ctime(time()),4,15)+"  "+
     query_ip_number(this_object())+"  "+
     query_ip_name(this_object())+"\n");
  }
  if (new_pl_rest != 1) 
    restore_object("pfiles/" + extract(name,0,0) + "/" + name);
  else save_me();
    no_give = 0;
  if (weapon_class > WEAPON_CLASS_OF_HANDS)
    weapon_class = WEAPON_CLASS_OF_HANDS;

  EnableWizAnsiPrefs();
  EnableSeniorAnsiPrefs();
  this_object()->add_ansi_pref("equip", 0);
  this_object()->restore_aliaii();
  this_object()->restore_nicknames();
  if (crime)
    call_out("clear_crime", 1500);
  if (armor_class > 0)
    armor_class = 0;
  if (query_invis() < 10000)
    log_file("ENTER", extract(ctime(time()),4,15)+ " (" + name + ") enter " + experience +
	    " ep, " + money + " g.\n");
  new_pl_rest = 0;
  set_max_spell();
  if (!dexterity) dexterity = 8;
  if (!charisma) charisma = 8;
  if (auto_load == "")
  auto_load = 0;
  if(saved_where) 
  {
    /* Added by Fred [06.13.06] */
    if(saved_where == "/obj/discon.c")
     saved_where = this_object()->query_home();
    /* End additions */
    move_object(myself,saved_where);
    load_auto_obj(auto_load);
    saved_where = 0;
  } else {
    if (where) {
	    move_object(myself, where);
      load_auto_obj(auto_load);
    } else {
      if (home) {
        load_auto_obj(auto_load);
        if(!catch(home->blahhh(0))) {
	        move_object(myself, home);
        }
        else move_object(myself, "/room/vill_green");
      } 
      else {
	      move_object(myself, "room/vill_green");
	      load_auto_obj(auto_load);
      }
    }
  }
  checked_say(cap_name + " enters the game.\n");
  if(where=="room/adv_guild") {
    cat("/doc/helpdir/newbie_attribs");
    write(HIY+"\n\nNew players: If you are lost, type 'recall'.\n\n"+NORM);
  }
  if(gob) gob->guild_login();
    call_out("shoutin",0);
  if (query_invis())
    write("YOU ARE INVISIBLE = " + query_invis() + "!\n\n");
  if (muffled)
    write("YOU HAVE ON EAR MUFFS.\n");
  if (ghost)
    write("YOU ARE A GHOST!\n\n");
  call_other("room/post", "query_mail");
  if (called_from_ip && query_ip_number() != called_from_ip)
    if(name != "guest")
      write("Your last login was from " + called_from_ip + "\n");
  called_from_ip = query_ip_number();
  sethost();
  if (lastime) {
    write("Your last login was on " + lastime + "\n");
  }
  old_last=lastime;
  lastime = extract(ctime(time()),4,15)+extract(ctime(time()),19,24);
  if(!race && gender !="creature") race = "human";
  if(!race && gender =="creature") race = "creature";
  if(race !="creature" && gender =="creature") {
    race = "creature"; gender=="male"; }
  if(gender =="creature") gender="male";
  if(this_object()->query_guild_name()) {
    if(sscanf(this_object()->query_guild_name(),"warrio%s",junk) 
    || sscanf(this_object()->query_guild_name(),"symbiot%s",junk) 
    || sscanf(this_object()->query_guild_name(),"Knights Temp%s",junk) 
    || sscanf(this_object()->query_guild_name(),"neo symbi%s",junk)) {
      if(auto_load && sscanf(auto_load, "%smaledicta/closed/w/gob%s",junk,junkb) == 2) {
        write("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        write("****************************************************************************\n");
        write("maledicta's warriors are now closed.\n");
        write("clearing guild status and swapped exp.....\n");
        log_file("MAL_GUILD",cap_name+" "+guild_name+" "+guild_exp+" "+this_object()->query_guild_exp()*2/3+"\n");
        player_killing = 0;
        this_object()->set_guild_name(0);
        write(guild_name);
        experience += guild_exp*2/3;
        write(experience+" "+guild_exp);
        this_object()->add_guild_exp(-this_object()->query_guild_exp());
        this_object()->add_guild_rank(-this_object()->query_guild_rank());
        destruct(present("warrior_gob"),this_object());
        write("All set.\n");
        write("***************************************************************************\n");
        write("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
      }
      if(auto_load && sscanf(auto_load, "%smaledicta/venom%s",junk,junkb) == 2) {
        write("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        write("****************************************************************************\n");
        write("maledicta's symbiotes are now closed.\n");
        write("clearing guild status and swapped exp.....\n");
        log_file("MAL_GUILD",cap_name+" "+guild_name+" "+guild_exp+" "+this_object()->query_exp()/3+"\n");
        player_killing = 0;
        this_object()->set_guild_name(0);
        this_object()->add_exp(this_object()->query_exp()/3);
        this_object()->add_guild_exp(-this_object()->query_guild_exp());
        this_object()->add_guild_rank(-this_object()->query_guild_rank());
        destruct(present("venom_object"),this_object());
        write("All set.\n");
        write("***************************************************************************\n");
        write("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
      }
    }
  }
  
  setup_atrbr();
  if (treasure > 0) {
    if(treasure_str[1]) {
      write("Restoring lost inventory items...\n");
      treas_c=0;
      while(treas_c<NUMOBS_STOR) {
        if(treasure_str[treas_c]) {
          object t_ob;
          string err,arg;
          int hit,miss;
          sscanf(treasure_str[treas_c],"%s#%s$%d@%d",treasure_str[treas_c], arg,hit,miss);
          if ( err = catch(t_ob = clone_object(treasure_str[treas_c])) )
            t_ob=clone_object("/players/boltar/things/hcookie");
          if (arg) t_ob->locker_init(arg);
          if (hit) t_ob->set_hits(hit);
          if (miss) t_ob->set_misses(miss);
          move_object(t_ob,this_object());
        } 
        treasure_str[treas_c]=0;
        hit = 0; miss = 0; arg = 0;
        treas_c+=1;
      }
      recalc_carry();
    }
    write("Restoring value from lost inventory items...\n");
    if(treasure == 314159265) treasure = 1; /*safety*/
	  money += treasure;
	  treasure = 0;
  }
  qc = 0;
  /* set quit counter to zero */
  ob = first_inventory(environment());
  while (ob) {
    if (ob != this_object()) {
	    string sh;
	    sh = call_other(ob, "short");
	    if (sh)
	      write(sh + ".\n");
    }
    ob = next_inventory(ob);
  }
  if ((int)this_object()->query_level() >= WIZARD)
  if (file_size("/players/" + this_object()->query_real_name() 
  + "/login") > 0)
    soul->wiz_auto_exec();
  if(this_object()->query_level() <= APPRENTICE) save_me();
}

help(what) {
  call_other("/closed/wiz_soul", "more", "/doc/"+(what?"helpdir/"+what:"help"));
  return 1;
}

tell(str) {
    object ob;
    string TellColor;
    string who;
    string msg;
    string afk_str;
    if (ghost) {
  	  write("Because you are a ghost, you fail.\n");
	    return 1;
    }
    if (spell_points < 0) {
    	write("You are low on power.\n");
	    return 1;
    }
    if(query_verb()=="reply") str = replyto + " " + str;
    if (!str || sscanf(str, "%s %s", who, msg) != 2) {
	write("Tell what?\n");
	return 1;
    }
    it = lower_case(who);
    ob = find_player(it, 1);
    who = capitalize(it);
    if (!ob) ob = find_living(it);
    if (!ob) {
	write("No player with that name.\n");
	return 1;
    }
    if (interactive(ob)) {
	if (level < ob->query_level() && ob->query_invis() >= 39) {
	    write("No player with that name.\n");
	    return 1;
	}
        if (level < GOD && in_editor(ob)) {
	    write("That person is editing. Please try again later.\n");
	    return 1;
	}
        if (level < 21 && ob->query_tellblock()) {
          write("That person is blocking tells. Please try again later.\n");
           return 1;
        }
        if(tellblock[0] == "on" && ob->query_level() < 21 && level < 21) {
           write("You cannot use tell when tellblock is on.\n");
           return 1;
        }
      if(query_idle(ob) > 120) tell_object(myself, who+" is idle at the moment. You may not get a response right away.\n");
      if((afk_str=ob->query_afk_message()))
        tell_object(myself, who+" is afk: "+afk_str+"\n");
    }
    if(!ob->query_npc() && !interactive(ob)) tell_object(myself, who+" is disconnected.\n");
if(call_other(this_object(),"query_invis",0) > 20 && level < 199)
  {
  write( "Don't be annoying.  Become visible before you talk to someone!\n" );
  return 1;
  }
    ob->Replyer(name);
    ob->add_tellhistory(cap_name + " tells you: " + msg);
msg = format(msg, 60);
    if(ob->query_level() > level && cap_name=="Someone") tell_object(ob,"< "+name+" > ");
    TellColor=ob->get_ansi_pref("tell");
    if(TellColor) tell_object(ob, TellColor + cap_name + " tells you: " + msg + "\n" + NORM);
    else tell_object(ob, cap_name + " tells you: " + msg + "\n");
    write("Ok.\n");
    write("You tell "+ob->query_name()+" "+msg);
    if (level < EXPLORE)
	spell_points -= 1;
    return 1;
}

whisper(str) {
    object ob;
    string who;
    string msg;
    if (ghost) {
	write("You fail.\n");
	return 1;
    }
    if (!str || sscanf(str, "%s %s", who, msg) != 2) {
	write("Whisper what?\n");
	return 1;
    }
    it = lower_case(who);
    ob = find_player(it, 1);
    if (!ob || !present(it, environment(this_player()))) {
	write("No player with that name in this room.\n");
	return 1;
    }
    who = (string)ob->query_name();
    tell_object(ob, cap_name + " whispers to you: " + msg + "\n");
    write("Ok.\n");
    checked_say(cap_name + " whispers something to " + who + ".\n");
    return 1;
}

add_hit_point(arg) {
  object thypl;
  int TGR; 
  int INF_MIN, INF_MAX, INF_ADD;
  int liv_infuse,LIV_INFUSE_LIMIT;
  thypl = this_player();
  if(thypl)
    if (level < EXPLORE && thypl->query_interactive() && thypl != this_object()){
      if(thypl->query_level() > EXPLORE)
        log_file("POINTS", name + " hp-add "+ arg + call_other(thypl, "query_real_name", 0) + " " + ctime(time()) + "\n");
      else 
        if(environment(thypl) != environment(this_object())) {
          arg = 0;
          /* tell_object(thypl,"Player to Player Hit Point transfers are not allowed.\n"); */
          tell_object(thypl,cap_name+" is not here.\n");
          tell_object(this_object(),"Attempted Hit Point transfer Aborted.\n");
        return 1; }
        if(thypl->query_guild_name() == "healer") { 
           TGR = thypl->query_guild_rank();   /* between 5 and 40 */ 
           INF_MIN = liv_infuse + (3 - TGR/10)*arg/2; 
           INF_MAX = LIV_INFUSE_LIMIT/2 + TGR; 
           INF_ADD = ((6 - (TGR / 7)) * arg / 2);
           if(INF_MIN < 0) INF_MIN = 0; 
           if(INF_MAX < 0) INF_MAX = 0;
           if(INF_ADD < 0) INF_ADD = 0; 
        } else { INF_MIN = infuse+3*arg/2; INF_MAX = (INFUSE_LIMIT)/2; INF_ADD = 3*arg/2; }
        if(((INFUSE_LIMIT) < INF_MIN ||infuse >INF_MAX) && arg > 0) {
          int blah;
          blah = 2*((INFUSE_LIMIT) - infuse)/3;
          tell_object(thypl,cap_name+" must wait before absorbing "+arg+" hit points.\n");
          if(infuse < INF_MAX && blah > 0 && arg > 0)
            tell_object(thypl,cap_name+" may absorb up to "+blah+" hit points.\n");
          tell_object(this_object(),"You must wait before absorbing more hit points.\n");
          arg = 0;
        return 1; }
        if(arg > 0) infuse += INF_ADD;
    }
    if(!this_object()->query_interactive()) {
       say(cap_name+" is disconnected.\n");
       stop_fight(); if (this_player()) this_player()->stop_fight();
    return 0; }
    if(arg < 0)
    {
      object x;
      dam_taken_this_round += (-arg);
      if(x=present("damage_report_object", this_object()))
        x->report_damage(-arg, previous_object());
    }
    hit_point += arg;
    if (hit_point > max_hp) hit_point = max_hp;
    if (hit_point < 0) hit_point = 0;
}



add_spell_point(arg) {
  object thypl;
  int TGR;
  int INF_MIN, INF_MAX, INF_ADD;
  int liv_infuse,LIV_INFUSE_LIMIT;
  thypl = this_player();
  if(thypl) 
    if (level < EXPLORE && thypl->query_interactive() && thypl != this_object()) {
      if(thypl->query_level() > EXPLORE) 
        log_file("POINTS", name + " sp-add "+ arg + call_other(thypl, "query_real_name", 0) + " " + ctime(time()) + "\n");
      else {
        if(environment(thypl) != environment(this_object())) {
          arg = 0;
          tell_object(thypl,cap_name+" is not here.\n");
          tell_object(this_object(),"Attempted Spell Point transfer Aborted.\n");
        return 1; }
        if(thypl->query_guild_name() == "healer") { 
           TGR = thypl->query_guild_rank();
           INF_ADD = ((6 - (TGR / 7)) * arg / 2);
           if(INF_MIN < 0) INF_MIN = 0; 
           if(INF_MAX < 0) INF_MAX = 0;
           if(INF_ADD < 0) INF_ADD = 0;
        } else { INF_MIN = infuse+3*arg/2; INF_MAX = (INFUSE_LIMIT)/2; INF_ADD = 3*arg/2; }
        if(((INFUSE_LIMIT) < INF_MIN ||infuse >INF_MAX) && arg > 0) {
          int blah;
          blah = 2*((INFUSE_LIMIT) - infuse)/3;
          tell_object(thypl,cap_name+" must wait before absorbing "+arg+" spell points.\n");
          if(infuse < INF_MAX && blah > 0 && arg > 0)
             tell_object(thypl,cap_name+" may absorb up to "+blah+" spell points.\n");
          tell_object(this_object(),"You must wait before absorbing more spell points.\n");
          arg = 0;
        return 1; }
        if(arg > 0) infuse += INF_ADD;
      }
    }
    spell_points += arg;
    if(arg < 0 && guild_name=="Knights Templar" && this_object()->query_mounted()) spell_points += 2*arg/3;
    if (spell_points > max_spell) spell_points = max_spell;
}

drop_one_item(ob) {
    int weight;

    if (call_other(ob, "id", "soul") || (call_other(ob, "drop", 0) && !power))
        return 0;
    if (!ob)
        return 0;
    weight = call_other(ob, "query_weight");
    if (!weight)
	weight = 0;
    add_weight(-weight);
    move_object(ob, environment(myself));
    return 1;
}

drop_all(verbose) {
    object ob;
    object next_ob;
    if (!myself || !living(myself))
        return;
    ob = first_inventory(myself);
    while(ob) {

	string out;
	next_ob = next_inventory(ob);
	it = call_other(ob, "short");
	if (drop_one_item(ob) && verbose) {
	    out = it + ".\n";
	    checked_say(cap_name + " drops " + out);
	    tell_object(myself, "drop: " + out);
	}
	ob = next_ob;
    }
}

valid_name(str) {
  int i, length;
  if (str == "logon") {
    write("Invalid name.\n");
	  return 0;
  }
  length = strlen(str);
  if (length > 11) {
	  write("Too long name.\n");
	  return 0;
  }
  i=0;
  while(i<length) {
	  if (str[i] < 'a' || str[i] > 'z') {
	    write("Invalid characters in name:" + str + "\n");
	    write("Character number was " + i + ".\n");
      /* log_file("BAD_NAME", str + "\n"); */
	    return 0;
    }
	  i ++;
  }
  return 1;
}

static change_password(str) {
    if (password && password !="" && !str) {
	write("Give old password as an argument.\n");
	return 1;
    }
    if(password)
    if (crypt(str, extract(password,0,1)) != password) {
	write("Wrong old password.\n");
	return 1;
    }
    write("New password: ");
    password2 = 0;
    input_to("change_password2", 1);
    return 1;
}

static change_password2(str) {
    if (!str) {
	write("Password not changed.\n");
	return;
    }
   if(strlen(str) < 6) {
     write("Password must be at least 6 characters long.\n");
     return;
   }
    if (password2 == 0) {
	password2 = str;
	write("Again: ");
	input_to("change_password2", 1);
	return;
    }
    if (password2 != str) {
	write("Wrong! Password not changed.\n");
	return;
    }
    password = crypt(password2,0);
    password2 = 0;
    write("Password changed.\n");
    if (level < EXPLORE ) {
    write("Please enter a password reminder hint.\n");
    write("Please note anyone may view it.\nHint: ");
    input_to("gethint");
    }
}

/* 
 * 05/16/06 Earwax:  removed bug/idea/typo from here.  they
 * are in /obj/player/bugtypoidea.c verbatim, but no longer 
 * need to be here as it's wasted memory.
 */

static converse() {
  write("Give '**' to stop.\n");
  write("]");
  input_to("converse_more");
  return 1;
}

static converse_more(str) {
  if (!str) {
	  input_to("converse_more");
	  return;
  }
  if (str == "**") {
	  write("Ok.\n");
	  return;
  }
  if(str)
	  say(cap_name + " says: " + str + "\n");
  write("]");
  input_to("converse_more");
}

static toggle_whimpy(arg) {
    int per;
    string ttt,dir;
    if(!arg) {
    write("Wimpy set at "+whimpy+"% in "+whimpy_dir+" direction.\n");
    write("To turn wimpy off use 'wimpy off'\n");
       return 1;
    }
    if(arg=="off") {
      whimpy = 0;
      whimpy_dir = "random";
      write("Brave mode.\n");
      return 1;
    }
    if(sscanf(arg, "%d %s",per,dir) !=2) {
       write("Usage wimpy hp% direction\n");
       write("direction can be random or any valid exit command.\n\n");
       return 1;
    }
    if(sscanf(dir,"do%s",ttt) && ttt != "wn") {
      write("No you don't.\n");
      return 1;
    }
    if(per > 99) {
      write("Now that is a rather silly value to set wimpy to.\n");
      write("Try a lower number.\n");
      return 1;
    }
    whimpy = per;
    whimpy_dir = dir;
    write("Wimpy set at "+per+"% in "+dir+" direction.\n");
    return 1;
}

query_brief() { return brief; }

static toggle_brief() {
    brief += 1;
    if(brief == 3) brief = 0;
    if (brief==1)
        write("Brief mode.\n");
    else if (brief==0)
        write("Verbose mode.\n");
    else {
         add_ansi_pref("roomtitle", 0);
        write("Detail mode.\n");
        }
    return 1;
}


add_exp(e) {
string tmpo,tmpi;
    if (this_player() && this_player() != this_object() &&
     call_other(this_player(), "query_level", 0) > 1 &&
      query_ip_number(this_player()) && level < 20)
     {
  if(previous_object())
{
  sscanf(file_name(previous_object()),"%s#%s",tmpo,tmpi);
  if(tmpo !="obj/party")
  if(file_name(previous_object()) != "obj/partymaster")
        {
	log_file("EXPERIENCE", ctime(time()) + " " + name + "(" + level + 
		") " + e + " exp by " + this_player()->query_real_name() + 
		"(" + this_player()->query_level() + ")" +"\n");
  log_file("EXPERIENCE",file_name(previous_object())+"-^\n");
 }
   }
    }
  if (is_interactive) {
    experience += e;
     call_other("obj/exp_store.c","collector",cap_name,e);
  }
    if (level <= 19)
	add_worth(e);
}

query_intoxination() { return intoxicated; }
add_intoxination(i) {
  intoxicated += i;
  if (intoxicated < 0) {
	  intoxicated = 0;
	  remove_call_out("intoxicate");
	  return;
  }
  if (intoxicated && find_call_out("intoxicate") == -1)
    call_out("intoxicate", 5 + random(56));
}

second_life() {
  int lt;
  string st;
  object here;
  if (level >= EXPLORE)
	  return illegal_patch("second_life set_level");
  ghost = 1;
  msgin = "drifts around";
  msgout = "blows";
  headache = 0;
  intoxicated = 0;
  hunter = 0;
  hunted = 0;
  attacker_ob = 0;
  alt_attacker_ob = 0;
  save_me();
  tell_object(myself,"\n\n");
  st="You die.";
  lt=strlen(st); lt=40-(lt/2);
  tell_object(myself, pad(" ",lt-1)+st+"\n");
  st="You have a strange feeling.";
  lt=strlen(st); lt=40-(lt/2);
  tell_object(myself, pad(" ",lt-1)+st+"\n");
  st="You can see your own dead body from above.";
  lt=strlen(st); lt=40-(lt/2);
  tell_object(myself, pad(" ",lt-1)+st+"\n");
  st="setting hit points to 1/3 max....";
  lt=strlen(st); lt=40-(lt/2);
  tell_object(myself, pad(" ",lt-1)+st+"\n");
  tell_object(myself, "\n\n");
  here=environment(this_object());
  move_object(clone_object("/obj/tunnel"),here);
  clear_followers();
  clear_follow();
  tell_room(here,"A white dot appears and expands into a bright white "+
    "tunnel.\n");
  tell_room(here,"The tunnel shimmers slightly as it grows in strength.\n");
  tell_object(myself, "You feel a desire to enter the tunnel.\n");
  return 1;
}

remove_ghost() {
   object thing;
   int cexp;
    if (!ghost)

	return 0;
    if(PKGhostCounter) return (tell_object(this_object(), "\nYou may not be revived from death for another " + PKGhostCounter + " seconds.\n\n"), 1);
    tell_object(this_object(), "You feel a very strong force.\n");
    tell_object(this_object(), "You are sucked away...\n");
    tell_object(this_object(), "You reappear in a more solid form.\n");
    if(environment()) {
    tell_room(environment(), "Some mist disappears.\n", ({ this_object() }));
    tell_room(environment(), cap_name + " appears in a solid form.\n", ({ this_object() }));
    }
    ghost = 0;
    dead = 0;
    msgin = "arrives";
    msgout = "leaves";
   if(present("guild_death_object", this_object())){
   thing = present("guild_death_object",this_object());
  call_other(thing, "guild_death",0);
   }
   else {
     cexp=call_other("room/adv_guild", "check_level", level);
     if(experience < cexp)
       call_other("room/adv_guild", "correct_level", this_player());
     if (ex_lv) {
      cexp=call_other("room/exlv_guild", "check_level", ex_lv);
      if(experience < cexp)
        call_other("room/exlv_guild", "correct_extra_level", this_object());
     }
   }
    save_me();
    return 1;
}

stop_hunting_mode() {
  if (!hunted) {
    write("You are not hunting anyone.\n");
  	return 1;
  }
  call_other(hunted, "stop_hunter");
  hunted = 0;
  write("Ok.\n");
  return 1;
}

drink_alcohol(strength) {
  if(strength > 0)
    if (intoxicated > MAX_INTOX && strength > 0) {
        write("You fail to reach the drink with your mouth.\n");
	return 0;
    }
    add_intoxination(strength);
    if (intoxicated < 0) intoxicated = 0;
    if (intoxicated == 0)
	write("You are completely sober.\n");
    if (intoxicated > 0 && headache) {
	headache = 0;
	tell_object(myself, "Your head ache disappears.\n");
    }
    if (intoxicated > max_headache)
	max_headache = intoxicated;
    if (max_headache > 8)
	max_headache = 8;
    return 1;
}

static spell_invis(str) {
    object ob;
    if (this_object()->test_dark())
	return 1;
    spell_block();
    if(no_spell) { write("You are unable to do that.\n"); return 1;}
    if (level < 15)
	return 0;
    if (spell_points < 40 || this_object()->checkNM())
    {
      write("You do not have enough spell points.\n"); 
      return 1;}
    if (!str)
	ob = myself;
    else
	ob = present(lower_case(str), environment(this_player()));
    if (!ob || !living(ob)) {
	write("At whom?\n");
	return 1;
    }
    if (ob == myself) {
write("You see your hands disappear!\n");
say(cap_name + " fades into nothing.\n");
  is_invis = 18;
  if(level > 20) is_invis = 19;
   invs_flag = 1;
   invs_count = 0;
  call_other(myself, "add_spell_point", -40);
   if (is_invis >= SOMEONE) cap_name = "Someone";

	return 1;
    }
   say(cap_name + " waves his hands and casts a spell.\n");
    say("You see " + call_other(ob, "query_name") + " disappear!!!!\n");
    write("You make " + call_other(ob, "query_name") + " disappear.\n");
   call_other(ob, "set_invs_sp", 0);
   call_other(myself, "add_spell_point", -40);
   if (is_invis >= SOMEONE) cap_name = "Someone";

    return 1;
}

set_invs_sp() {
   is_invis=18;
   invs_flag=1;
   invs_count=0;
   return 1;
}
unset_invs_sp() {
   is_invis=0;
   invs_flag=0;
   invs_count=0;
   return 1;
}

visible () {
   invs_flag = 0;
   invs_count=0;
 if(this_player() && (this_player()->query_invis() > 20))
   command("vis", this_player());
 else
   write("You are now visible.\n");
 is_invis=0;
   say(cap_name + " appears in a puff of smoke.\n");
   return 1;
}

invs_counter () {
  if (invs_flag != 0) {
    invs_count ++;
    if (invs_count > 14+random(8)) {
      write ("You are visible again.\n");
      is_invis=0;
      invs_count=0;
      invs_flag = 0;
    }
  }
  return 1;
}
give_object(str) {
    string item, dest;
    object item_ob, dest_ob;
    int weight;
    int maxflag,coins,dest_coin;

    private;
    power = 0;
    if (level >= ITEM_OVER)
        if (sscanf(str,"! %s",power) == 1) {
            str = power;
	    power = "!";
        }
    if (!str)
	return 0;
    if (this_object()->test_dark())
	return 1;
    if (sscanf(str, "%d coins to %s", coins, dest) == 2)
	item = 0;
    else if ( sscanf(str, "1 coin to %s", dest) == 1)
	coins = 1;
    else if ( sscanf(str, "coin to %s", dest) == 1)
	coins = 1;
    else if (sscanf(str, "one coin to %s", dest) == 1)
	coins = 1;
    else if (sscanf(str, "%s to %s", item, dest) != 2) {
	write("Give what to whom?\n");
	return 1;
    }
    dest = lower_case(dest);
    if (item) {
	item = lower_case(item);
	item_ob = present(item, this_player());
	if (!item_ob) {
	    write("There is no " + item + " here.\n");
	    return 1;
	}
	it = item;
	if (environment(item_ob) == this_object() &&
	    call_other(item_ob, "drop", 1) && !power) {
	    return 1;
	} else if (!item_ob || (!call_other(item_ob, "get") && !power)) {
	    write("You can't get that !\n");
	    return 1;
	}
    }
    dest_ob = present(dest, environment(this_player()));
    if (!dest_ob) {
	write("There is no " + capitalize(dest) + " here.\n");
	return 1;
    }
    if (!living(dest_ob) && !power) {
	write("You can't do that.\n");
	return 1;
    }
    if (!item) {
   if (no_give) {
    write("You cannot give money while another copy is logging in.\n");
    return 1;
    }
	if (coins <= 0 && !power)
	    return 0;
	if (money < coins && !power) {
	    write("You don't have that much money.\n");
	    return 1;
	}
	if (!power) money -= coins;
	/* Checkpoint the character, to prevent cheating */
	if (coins > 1 && !power)
	    save_me();
        dest_coin = dest_ob->query_money();
        if(dest_coin  > MAXCOINS) maxflag = 1;
	call_other(dest_ob, "add_money", coins);
        if(!maxflag && dest_ob->query_money() == MAXCOINS) maxflag = 2; 
        if(!maxflag)
        if (coins != 1)
	    checked_say(cap_name + " gives " + coins + " coins to " + capitalize(dest) +
	    ".\n");
	else
	    checked_say(cap_name + " gives 1 coin to " + capitalize(dest) + ".\n");
        if(maxflag == 2)
           checked_say(cap_name + " gives " + (MAXCOINS - dest_coin) +
           " coins to " + capitalize(dest) + ".\n");
	write("Ok.\n");
	return 1;
    }
   if(!item_ob) return 1;
    weight = call_other(item_ob, "query_weight");
    if (!call_other(dest_ob, "add_weight", weight) && !power) {
	write(capitalize(dest) + " can't carry any more.\n");
	return 1;
    }
    add_weight(-weight);
    if(dest_ob == this_object()) {
      if(item_ob->id("moneyXX")) {
        if(!weight) { 
           add_weight(-item_ob->query_oldwt());
       }
        if(weight < item_ob->query_olderwt()) {
          add_weight(-item_ob->query_olderwt());
          item_ob->clear_olderwt();
          add_weight(weight);
        }
      }
    }
    move_object(item_ob, dest_ob);
    checked_say(cap_name + " gives " + item + " to " + capitalize(dest) + ".\n");
    write("Ok.\n");
    return 1;
}

static get_all(from) {
    object ob, next_ob;

    ob = first_inventory(from);
    while(ob) {
	string item;
	next_ob = next_inventory(ob);
	item = call_other(ob, "short");
	if ((item && call_other(ob, "get")) || (power && ob != myself)) {
	    int weight;
	    if (!living(from) || !call_other(ob, "drop", 1) || power) {
	        if (!call_other(ob, "id", "soul")) {
		    weight = call_other(ob, "query_weight");
		    if (add_weight(weight) || power) {
		        write(item + ": Ok.\n");
			call_other(from,"add_weight",-weight);
			move_object(ob, this_object());
			checked_say(cap_name + " takes: " + item + ".\n");
		    } else {
		        write(item + ": Too heavy.\n");
		    }
		}
	    }
	    it = item;
	}
	ob = next_ob;
    }
}

/* 05/16/06 Earwax:  daemonized pose */

save_me(arg) {
    string ab,bc;
    sscanf(file_name(this_object()), "%s#%s",ab,bc);
    if(ab!="obj/player")
     {
        illegal_patch("cloned player.c add_commands block");
	destruct(this_object());
	return;
    }
    if(!inact && arg !=3)
    if(!environment(this_object())) return 0;
    if(!inact && arg !=3)
    compute_auto_str();
    if (level < EXPLORE)
	compute_treasure();
     if(level < 2) ok_edit="new_bie567";
     if(level > 2 && ok_edit=="new_bie567") ok_edit = 0;
    if (level)
	save_object("pfiles/" + extract(name,0,0) + "/" + name);
    if(this_player() == this_object() && !inact && arg !=3)
    if (level > EXPLORE || file_size("/players/"+name+".o") > 0)
        save_object("players/"+name);
}

illegal_patch(what) {
    write("You are struck by a mental bolt from the interior of the game.\n");
    log_file("ILLEGAL",
	     capitalize(call_other(this_player(), "query_real_name")) + " " +
	     ctime(time()) + " " + what + "\n");
    return 0;
}

load_auto_obj(str) {
  string file, argument, rest;
  object ob;

  while (str && str != "") {
  	if (sscanf(str, "%s:%s^!%s", file, argument, rest) != 3) {
	    write("Auto load string corrupt.\n");
	    return;
	  }
	  str = rest;
	  ob = find_object(file);
	  if (!ob)
      continue;
	  ob = clone_object(file);
	  if (argument)
	    call_other(ob, "init_arg", argument);
    if(ob)
	    move_object(ob, this_object());
  }
}

compute_auto_str() {
  object next_ob,ob;
  string str;

  auto_load = "";
  ob = first_inventory(this_object());
  while (ob) {
	  str = call_other(ob, "query_auto_load");
	  next_ob = next_inventory(ob);
	  ob = next_ob;
	  if (!str)
	    continue;
	  auto_load = auto_load + str + "^!";
  }
}

compute_treasure() {
    object ob;
    int x, s;
    object *obs;
    int v,b,c;
    string str,a;

    if(treasure == 314159265){ 
      treasure = 1; 
      return;
    } /* flagging above prevents clearing reboot cross save */
    treasure = 0;
    while(c<NUMOBS_STOR) {
      treasure_str[c]=0;
      c+=1;
    }
    c=0;
    obs = deep_inventory(this_object());
    s=sizeof(obs);
    b=0;    
    for(x=0;x<s;x++) {
       ob = obs[x];
       if(!ob) continue;
       if(ob->short())
         if(!ob->query_save_flag() && !ob->query_auto_load() &&
            !ob->id("GI") && ((ob->generic_object() && 
            ob->locker_arg()) || !ob->generic_object()) ){
           str = file_name(ob);
           if(sscanf(str, "players/%s#%d",a,c)==2) {
             sscanf(str,"%s#%d",a,c);
             str = a;
             str = str + "#" + ob->locker_arg();
             str = str + "$" + ob->query_hits();          
             str = str + "@" + ob->query_misses();
             if(b<NUMOBS_STOR)
               treasure_str[b] = str;
             b += 1;
           }
         } 
      if(!c || b > NUMOBS_STOR-1) {
        v += call_other(ob, "query_value");
	if (v <= 100000) treasure += v;
	else treasure += 1000;
      } else treasure += 1;
        c = 0;
    }
}

smart_report(str) {
  string who;

  current_room=file_name(environment(this_object()));
  if (!str || !current_room || sscanf(current_room, "players/%s/", who) != 1)
	  return;
  log_file(who + ".rep", ctime()[4..15] + " " + current_room + " " + str + "\n");
    return 1;
}

/*
 * Daemonize this
 */
nomask string valid_write(string arg,object c) {
  string str, who,tmpa,tmpb,tmpc, file, temp;
  string tpa,tpb;
  int tempb;
  object prev_caller;
				     
  if (name == "ew") {
    tell_object(this_player(), "arg: "+arg+"\nc:"+creator(c)+"\nthis_ob: "+(string)this_object()->query_real_name()+"\n");
    tell_object(this_player(), "inact: "+inact+"\nghs: "+get_handshake(handshake)+"\ncaller: "+(string)caller()->query_real_name()+"/"+creator(caller())+"\n");
    return (string)PRIVSD->check_write(arg, c, this_object(), inact, get_handshake(handshake), caller());
  }
  if (!arg) return 0;
  prev_caller = caller();
  if (caller()!=myself || !c) c=caller();
  if (c!=this_object() && !in_editor(this_object()))

  if (extract(file_name(c),0,3)=="room" ||
      extract(file_name(c),0,2)=="obj" ||
      extract(file_name(c),0,2)=="bin" ||
      extract(file_name(c),0,5)=="closed")
    c=this_object();

  if (in_editor(this_object())) c=this_object();
  if(inact && !inacttwo) {
    if((int)get_handshake(handshake) != inact) {
      return 0;
    }
    if (sscanf(arg, "/pfiles/%s.o", who) == 1) {
      if(who == extract(name,0,0)+"/"+name) 
        return "pfiles/"+extract(name,0,0)+"/"+name+".o";
      return 0;
    }
  write("past-pfile-name-check");
    if (sscanf(arg, "/players/%s.o", who) == 1) {
      if(who == name) return "players/"+name+".o";
      if (sscanf(arg, "/players/inactive_saved/%s.o", who) == 1) {
        if(who == name) return "players/inactive_saved/"+name+".o";
        return 0;
      }
      return 0;
    }
    if (sscanf(arg, "/players/inactive_saved/%s.o", who) == 1) {
      if(who == name) return "players/inactive_saved/"+name+".o";
      return 0;
    }
    return 0;
  }
 if(sscanf(arg,"/bin/soul/%s",who) && prev_caller && basename(prev_caller) == "/bin/soul/editor") return "bin/soul/"+who;
  if(sscanf(arg, "/doc/helpdir/%s",who)) return "doc/helpdir/"+who;
  if(sscanf(arg, "/pfiles/notes/%s",who)) return "pfiles/notes/"+who;
  if (extract(arg,0,8)=="/Driver32") {
    if(sscanf(arg, "%splayers%s", tmpa, tmpb) !=2 ) {
      return 0; } else {
      tmpa = 0;
      sscanf(tmpb, "/%s/", tmpa);
      if(!tmpa) sscanf(tmpb, "/%s", tmpa);
      if(tmpa == name) return extract(arg,1,strlen(arg));
      return 0; 
    }
  }
  str = arg;
  if (str == "~" || str == "~/") 
    str = "/players/" + name;
  else if (sscanf(str,"~/%s",temp) == 1)
    str = "/players/" + name + "/" + temp;
  else if (sscanf(str,"~%s",temp) == 1)
    str = "/players/" + temp;
  else if (str[0] != '/')
    str = pwd + str;
  if (sscanf(str, "%s//%s", temp)) return 0;
  if (sscanf(str, "//%s", temp)) return 0;
  if (sscanf(str, "/.%s", temp)) return 0;
  if (sscanf(str, "%s/.%s", temp, temp)) return 0;
  if (sscanf(str, "/players/%s/%s", who, file) == 2) {
    if(level < ELDER && level > 20)
      if(sscanf(str,"%s"+name+"%s",tpa,tpb) != 2)
        if(sscanf(file_name(c),"players/"+who+"/%s",temp)!=1) {
          string a, b;
          string vvverb;
          vvverb = query_verb();
          if(vvverb == "mv" || vvverb == "cp" || vvverb == "ed" ||vvverb=="rm")
       if(level < 1000)
       log_file("ED_OTHER",name+" ["+vvverb+"] "+str+" "+ctime(time())+"\n");
     }
    if(!ok_edit) ok_edit="none#";
    if ((who == ok_edit || sscanf(ok_edit, "%s"+who+"%s", tmpa,tmpb)==2 || 
        who == name || level >= ED_OTHERS) && c==this_object()) {
      if(sscanf(ok_edit,"%s"+who+"/%s#%s",tmpa,tmpb,tmpc)==3){ 
        if(sscanf(str,"%s"+tmpb+"%s",tmpa,tmpc)==2)
          return "players/" + who + "/" + file;
        else 
          return 0;
        }
        if(who!="tar_castles" || who!="inactive_saved" || who!="pre_reno" || 
           level >= ELDER)
	  return "players/" + who + "/" + file;
    }
    if (sscanf(file_name(c),"players/"+who+"/%s",temp)==1)
      return "players/" + who + "/" + file;
    return 0;
  }
  if(sscanf(str,"/players/%s.o",file) == 1)
    if(level >= ELDER || (prev_caller && file_name(prev_caller)=="obj/simul_efun"))
      return "players/"+file+".o";
  if (sscanf(str,"/open/%s", file) == 1) {
    string vverb;
    vverb = query_verb();
    if(vverb == "mv" || vverb == "cp" || vverb == "ed" || vverb == "rm")
      log_file("ED_OTHER",name+" ["+vverb+"] "+str+" "+ctime(time())+"\n");
    return "open/" + file;
  }
  if (sscanf(str, "/log/WR/%s_%s", who,file) == 2)
    if (who == name || level >= ED_LOG)
      return "log/WR/" + who + "_" + file;
  if(sscanf(str, "/log/user/%s", who) &&
      ((prev_caller && basename(prev_caller)[0..8] == "/obj/user") ||
      (level >= ED_LOG)))
    return "log/user/"+who;
  if(sscanf(str, "/doc/%s",file) && level >= ELDER) return "doc/"+file;
  if(sscanf(str, "/pa/log/%s", who) == 1) {
        if((prev_caller && (basename(prev_caller)=="/obj/soul" || basename(prev_caller)=="/closed/wiz_soul")) || level >= SENIOR)
    {
    return "pa/log/"+who;
    }
  }
  if(sscanf(str, "/pa/admin/%s", who) == 1) {
    if(level < SENIOR) return 0;
  }
  if(sscanf(str, "/pa/%s", who) == 1) {
    if(who=="log/Snoop.txt")
      if(query_verb()=="snoop") return "pa/"+who;
    else if(level >= SENIOR || "/pa/admin/pa-daemon"->query_name(name))
   {
      return "pa/"+who;
  }
  }
  if (sscanf(str, "/log/SQLDATA/%s.%s", who,file) == 2)
    if (who == name || level >= ED_LOG)
      return "log/SQLDATA/" + who + "." + file;
  if(sscanf(str, "/ideas/sugg_old/%s", file) == 1)
    return "ideas/sugg_old/" + file;
  if(sscanf(str, "/ideas/%s", file) == 1)
    return "ideas/" + file;
  if (c!=this_object())
    return 0;
  if (sscanf(str, "/log/%s.%s", who,file) == 2)
    if (who == name || (capitalize(who) != who &&
	level >= ED_OTHERS) || level >= ED_LOG)
      return "log/" + who + "." + file;

  if (sscanf(str, "/log/%s", who) == 1) {
    if (who == name ||  (capitalize(who) != who &&
        level >= ED_OTHERS) || level >= ED_LOG)
      return "log/" + who;
    if(who == ok_edit || sscanf(ok_edit, "%s"+who+"#%s", tmpa,tmpb)==2 ||
       sscanf(ok_edit, who+"%s", tmpa)) 
     return "log/" + who;
  }

  if ((sscanf(str, "/obj/%s", file) == 1) && level >= EDIT_STANDARD)
    return "obj/" + file;
  if((sscanf(str, "/room/housing/%s",file) == 1) && prev_caller && (file_name(prev_caller)[0..11]=="room/housing"))
    return "room/housing/"+file;
  if ((sscanf(str, "/room/%s", file) == 1) && level >= EDIT_STANDARD)
    return "room/" + file;
    if ((sscanf(str, "/post_dir/%s", file) == 1) && level >= ELDER)
        return "post_dir/" + file;
    if ((sscanf(str, "/closed/%s", file) == 1) && level >= ELDER)
	return "closed/" + file;    
    if ((sscanf(str, "/banish/%s", file) == 1) && level >= ELDER)
       return "banish/" + file;
    if ((sscanf(str, "/bin/%s", file) == 1) && level >= ELDER)
        return "bin/" + file;
    if(sscanf(str,"/pfiles/%s",file))
      if(level >= ELDER || (prev_caller && file_name(prev_caller) == "obj/simul_efun"))
         return "pfiles/" + file;
    if ((sscanf(str, "/%s", file) == 1) && level >= ELDER)
      if (file && (sscanf(file, "%s/%s", str, str)!=2) && level >= ELDER)
	return file;
    if (level >= ALL_POWER) {
	sscanf(str,"/%s",file);
	return file;
    }
    return 0;
}

nomask string valid_read(string arg) {
    string str, who,tmpa,tmpb, file, temp,tmp;
    object c, prev_caller;
    int tempb;

    /*
     * Because argument lists are passed unevaluated, by the time caller()
     * gets executed, the real caller() will be valid_read, not whoever

     * actually called us.  Thus, we get caller() before calling valid_write.
     */
    c = caller();
    if (c!=this_object() && !in_editor(this_object()))
    if (extract(file_name(c),0,3)=="room" ||
		extract(file_name(c),0,2)=="obj" ||
                extract(file_name(c),0,2)=="bin" ||
                extract(file_name(c),0,7)=="post_dir" ||
		extract(file_name(c),0,5)=="closed")
	c=this_object();


    if(sscanf(arg, "%sacces%s", temp,tmp) == 2) return arg;
    file = valid_write(arg,c);
    if (file)
	return file;

    str = arg;
    if (str == "~" || str == "~/") 
	str = "/players/" + name;
    else if (sscanf(str,"~/%s",temp) == 1)
	str = "/players/" + name + "/" + temp;
    else if (sscanf(str,"~%s",temp) == 1)
	str = "/players/" + temp;
    else if (str[0] != '/')
	str = pwd + str;
    if (sscanf(str, "//%s", temp)) return 0;
    if (sscanf(str, "%s//%s", temp, temp)) return 0;
    if (sscanf(str, "/.%s",  temp)) return 0;
    if (sscanf(str, "%s/.%s", temp) > 1) return 0;
    if (sscanf(str, "%star_castles%s", temp) > 1) return 0;
    if(sscanf(str, "/players/%s/PLAN", who) == 1) return "players/" + who + "/PLAN";
    if (sscanf(str, "/players/%s/closed/%s", who, file) == 2) {
  if (who == name || level >= 100)
    {
       return "players/"+who+"/closed/"+file;
          }
  return 0;
  }
    if (sscanf(str, "/players/inactive_saved/%s.o", who) == 1) {
  if (((who == name || level >= SENIOR) && c==this_object()) || (prev_caller && (prev_caller == find_object("/obj/simul_efun"))))
	    return "players/inactive_saved/" + who + ".o";
	return 0;
    }
   if (sscanf(str, "/players/guilds/%s",who) == 1) {
      if(level >= ITEM_OVER && c==this_object())
         return "players/guilds/" + who;
      return 0;
   }
    if (sscanf(str, "/players/%s/%s", who, file) == 2) {
    if(!ok_edit) ok_edit="none#";
	if ((who == ok_edit || sscanf(ok_edit, "%s"+who+"%s", tmpa,tmpb)==2 || who == name || level >= READ_OTHERS) && c==this_object())
    {
	    return "players/" + who + "/" + file;
    }
	return 0;
    }
    if (sscanf(str, "/players/%s.o", who) == 1) {
  if (((who == name || level >= SENIOR) && c==this_object()) || (prev_caller && (prev_caller == find_object("/obj/simul_efun"))))
	    return "players/" + who + ".o";
	return 0;
    }
    if (sscanf(str, "/pfiles/%s.o", who) == 1) {
  if (((who == name[0..0]+"/"+name || level >= SENIOR) && c==this_object()) || (prev_caller && (prev_caller == find_object("/obj/simul_efun"))))
	    return "pfiles/" + who + ".o";
	return 0;
    }
    if (sscanf(str, "/post_dir/%s"+".o", who) == 1 || sscanf(str, "post_dir/%s"+".o", who) == 1) {
	if ((who == name || level >= ELDER) && c==this_object())
	    return "/post_dir"+"/" + who + ".o";
	return 0;
    }
    if (sscanf(str, "/pa/%s", file) == 1) {
        if(str=="/pa/admin/pa-list.txt") return "pa/admin/pa-list.txt";
        if (level >= SENIOR || "/pa/admin/pa-daemon"->query_name(name)) return "pa/"+file;
        return 0;
      }
    if (sscanf(str, "/closed/%s", file) == 1) {
	if (level >= ELDER && c==this_object())
	    return "/closed/"+file;
	return 0;
    }
    if (sscanf(str, "/%s", file) == 1)
	return file;

    write("Bad file name.\n");
    return 0;		/* Should not happen */
}

soul(str) {
  string junk,junk2;
    object here,guild_object,temp;
    remove_call_out("timeout");
    remove_call_out("timeout");
    if (!str) return 0;
    if (str != "on" && str != "off") return 0;
    here = environment(this_object());
    if (str == "off" && !soul) {
        tell_object(myself, "You don't have one.\n");
	return 1;
    }
    if (here)
        save_me();

temp = first_inventory(this_object());
while(temp) {

 if (temp->id("GI")) guild_object = temp;
temp = next_inventory(temp);
}
if(!present("GI")){
if (!guild_object && guild_file && guild_file !="" && guild_file != 0) {
  if(!catch(call_other(guild_file, "id", "GI")))
  {
    gob=clone_object(guild_file);
    move_object(gob, this_object());
   }
  }
 }

    if (soul) {
        if (here) {
	    tell_object(myself, "You lose your soul!\n");
	    if (str == "on")
	        tell_object(myself, "Something's odd though...\n");
	}
      if(soul)
	destruct(soul);
    }
    if (str == "off") {
        return 1;
    }
    if (soul) {
        if (here)
	    tell_object(myself, "You cannot bring yourself to do this.\n");
	return 1;
    }
    if (level < EXPLORE) {
        soul = clone_object("obj/soul");
    } else if (level < GOD) {
	soul = clone_object("closed/wiz_soul");
    } else {
	soul = clone_object("closed/wiz_soul");
    }
    move_object(soul, myself);
    if (here)
        tell_object(myself, "You have been ensouled.\n");
    return 1;
}

remote_ed(key) {
  string tpa,tpb,file;
  private;
  file = call_other(soul,"get_handshake",key);
  file = valid_write(file);
  if (!file) {
	  write("You cannot edit that file.\n");
	  return 1;
  }
  tell_object(myself,"editing: "+file +"\n");
  ed(file);
}

remote_cmd(key) {
  string str;
    
  str = call_other(soul,"get_handshake",key);
  if (str)
    command(str);
}

inherit "/obj/wiz/snoop/play_lib";

query_soul() { return soul; }

remote_say(str, ignore) {
    if (ignore)
        say(str, ignore);
    else
        say(str);
}

set_wc(num) { weapon_class = num; }
set_ac(num) { armor_class = num;  }

query_muffled() { return (level < 0? 1 : muffled); }

emergency(str) {
    if (!str) {
	write("Shout what?\n");
	return 1;
    }
   if(channelcount > 3) {
     write("Spaming level reached. Message not sent.\n");
     return 1;
   }
   channelcount += 1;
    if(name=="guest" || age < 1800) {
        write("You cannot do that yet.\n");
        return 1;
    }
   if (age < 1800) {
     write("Players less than one half hour old cannot use emergency.\n"+
           "If you have a REAL problem please tell any wizard or higher level player\n"+
           "to relay your message.\n"+
           "This was done to stop abuse by those who wished to disturb others on the mud.\n");
   return 1;
 }
    shout("!" + cap_name + " screams: " + str + "\n");
    log_file("EMERGENCY",cap_name + ": " + str + "\n");
    write("Ok. But it better be an emergency!\n");
    return 1;
}


set_pwd(str) {
  private;
  if (!str) {
    write("Null path!\n");
    return;
  }
  if (str[0] == '/')
    pwd = str;
  else
    pwd = "/" + str;
}

get_path() { return query_pwd(); }

update (num) {
    if(!(soul = present("player_soul", this_object())) &&
       !(soul = present("wiz_soul", this_object())))
     return;
    if (num == 1) msgin = call_other(soul,"query_msgin");
    if (num == 2) mmsgin = call_other(soul,"query_mmsgin");
    if (num == 3) msgout = call_other(soul,"query_msgout");
    if (num == 4) mmsgout = call_other(soul,"query_mmsgout");
    if (num == 5) {
        is_invis = call_other(soul,"query_invis");
	if (query_invis() > SOMEONE) {
	    cap_name = "Someone";
	} else {
	    cap_name = capitalize(name);
	}
    }
    if (num == 6) {muffled = call_other(soul,"query_muffled");
   }
    if (num == 7) alignment = call_other(soul,"query_alignment");
    if (num == 8) al_title = call_other(soul,"query_al_title");
    if (num == 9) msghome = call_other(soul,"query_msghome");
    if (num== 10) wkrm = call_other(soul, "query_alt_wkrm");
}

is_player() { return 1; }

query_quests(str) {
    string tmp, rest, rest_tmp;
    int i;

    if (str == -1) {
	write("quests: "+quests+"\n");
	return;
    }
    if (str == 0) {
	return quests;
    }
    rest = quests;
    while (rest) {
	if (str == rest)
	    return 1;
	i = sscanf(rest, "%s#%s", tmp, rest_tmp);
	if (i == 0)
	    return 0;
	if (tmp == str)
	    return 1;
	if (i == 1)
	    return 0;
	rest = rest_tmp;
    }
    return 0;
}

query_gender() { return gender; }
set_gender(g) {
  if (g == "creature" || g == "male" || g == "female")
    gender = g;
}

query_call_outs() {
  write("active call_outs\n");
  dump_call_out("timeout");
  dump_call_out("intoxicate");
  /* 03/20/06 Earwax: these no longer call_out()
  dump_call_out("autosave");
  dump_call_out("autoheal");
  */
}

dump_call_out(str) {
  int i;
  if ((i = find_call_out(str)) >= 0)
    write(str + ":\t" + i + "\n");
}

query_guild_rank() { return guild_rank; }
query_guild_exp() { return guild_exp; }
query_guild_file() { return guild_file; }
add_guild_rank(x) { guild_rank += x; }
add_guild_exp(x) { guild_exp += x; }
set_guild_file(str) { guild_file = str; }

void load_cmd_hook() { add_action("cmd_hook"); add_xverb(""); }

/* 05/11/06 Earwax: Yet more reformatting, yanked some old stuff */
add_commands() {
  string ab,bc;
  sscanf(file_name(this_object()), "%s#%s",ab,bc);
  if(ab!="obj/player") {
    illegal_patch("cloned player.c add_commands block");
	  destruct(this_object());
	  return;
  }
  add_action("cmd_suicide", "suicide");
  load_cmd_hook();
  add_action("cmd_do_talk"); add_xverb(">");
  add_action("go_inactive","inactive");
  add_action("tellblock","tellblock");
  add_action("cmd_assist", "assist");
  add_action("write_tellhistory","tellhistory");
  add_action("follow","follow");
  add_action("cmd_lead", "lead");
  add_action("follow_status", "fstatus");
  add_action("check_reboot","reboot");
  add_action("location_unk", "church");
  add_action("cmd_monitor", "mon");
  add_action("cmd_setmon","setmon");
  add_action("logme","logme");
  add_action("give_object"); add_verb("give");
  add_action("mud_list"); add_verb("mudlist");
  add_action("set_pretitle"); add_verb("pretitle");
  add_action("wield_and_wear"); add_verb("ready");
  add_action("wield_and_wear"); add_xverb("#");
  add_action("set_mailaddr"); add_verb("setmail");
  add_action("score"); add_verb("score");
  add_action("score"); add_verb("sc");
/*
  add_action("set_pl_k"); add_verb("kill_players");
*/
  add_action("score2"); add_verb("score2");
  add_action("score2"); add_verb("sc2");
  add_action("save_character"); add_verb("save");
  if (this_object()->query_level() < CREATE)
    add_action("quit", "quit");
  else
    add_action("do_quit", "quit");
   
  add_action("new_communicate", "say");
  add_action("new_communicate"); add_xverb("\"");
  add_action("new_communicate"); add_xverb("'");
  add_action("shout_to_all"); add_verb("shout");
  add_action("put"); add_verb("put");
  add_action("pick_up"); add_verb("get");
  add_action("pick_up"); add_verb("take");
  add_action("drop_thing"); add_verb("drop");
  add_action("look"); add_verb("look");
  add_action("look"); add_verb("l");
  add_action("examine"); add_verb("examine");
  add_action("examine"); add_verb("exa");
  add_action("tell"); add_verb("tell");
/*
  add_action("tell","reply");
*/
  add_action("whisper"); add_verb("whisper");
  add_action("change_password"); add_verb("password");
  if(level > EXPLORE) add_action("smart_report","rep");
  add_action("converse"); add_verb("converse");
  add_action("toggle_brief"); add_verb("brief");
  add_action("toggle_whimpy"); add_verb("wimpy");
  add_action("stop_hunting_mode"); add_verb("stop");
  add_action("spell_invis"); add_verb("invisible");
  add_action("visible"); add_verb("visible");
/*
  add_action("pose"); add_verb("pose");
*/
  add_action("soul"); add_verb("soul");
  add_action("emergency"); add_verb("emergency");
  add_action("glance"); add_verb("glance");
  add_action("go_north"); add_verb("n");
  add_action("go_south"); add_verb("s");
  add_action("go_west"); add_verb("w");
  add_action("go_east"); add_verb("e");
  add_action("go_northwest"); add_verb("nw");
  add_action("go_northeast"); add_verb("ne");
  add_action("go_southwest"); add_verb("sw");
  add_action("go_southeast"); add_verb("se");
  add_action("go_up"); add_verb("u");
  add_action("go_down"); add_verb("d");
  add_action("add_channel", "channel");
  add_action("remove_channel", "muffle");
  add_action("list_channels", "channels");
  add_action("have_sex","sex");
  add_action("money_item", "cashmoney");
  add_action("test_items", "itemtest");
  add_action("cmd_sell", "sell");
}
 
patch_ok_edit(str)
{
  if(query_ip_number(this_player()) && (int)this_player()->query_level() >= ELDER)
    ok_edit = str;
}

query_hostname()
{
	return (hostname ? hostname : query_ip_name ( this_object() ) );
}
static sethost() 
{
  if(this_object())
	  hostname = query_ip_name(this_object());
}

set_home(str) { home = str; }
query_home() { return home; }

set_fight_area() {
      fight_area=file_name(environment(this_object()));
       return 1;
   }
clear_fight_area() {
      fight_area=0;
      return 1;
  }
check_fight_area() {
  if(fight_area && fight_area == file_name(environment(this_object())))
    return 1;
  else {
    fight_area = 0;
    return 0;
  }
}
query_fight_area() {
   return fight_area;
  }
query_pl_k() {
    return player_killing;
  }
set_pl_k(x) {
   player_killing = x;
/*
      if (call_other(this_object(), "query_real_name",0)=="guest")
      {
         write("Guest cannot be a player killer.\n");
         return 1;
       }
      if (level < 3){
     write("Your level is not high enough.\n");
       return 1;
}
   if(str == "spar" && !environment(this_object())->query_spar_area()) {
     write("You are not in a sparing area.\n");
     return 1;
   }
   if(player_killing == 1 && str == "spar") player_killing = 3;
   if(!player_killing && str == "spar") player_killing = 2;
   if(!str)
   player_killing = 1;
   if(!str) {
    write("player killing has been set.\n");
    write("you may now attack or be attacked by other players who also have their's set.\n");
   }
   if(str == "spar") {
    write("sparing pk flag set.\n");
   }
   if(str && str != "spar") {
    write("Usage: kill_players, kill_players spar\n");
   }
   return 1;
*/
  }
query_interactive(){
     return interactive(this_object());
    }
set_mailaddr(addr) {
   if(!addr)
  {
    write("Your current mail address is "+mailaddr+"\n");
    write("Type setmail <arg> to list a new one.\n");
    return 1;
  }
  mailaddr = addr;
  write("Your mail address is " + mailaddr + "\n");
 return 1;
}

query_mailaddr() {
  return mailaddr;
}

static getmailaddr(maddr) {
  mailaddr = maddr;
  if(mailaddr == "") mailaddr = "none";
  move_player_to_start(0);
}

static gethint(phint) {
  hint = phint;
  if(pc == 987 && !environment(this_object())) move_player_to_start(0);
  return;
}

wield_and_wear() {
string name_of_item;
name_of_item = first_inventory(this_player());
while (name_of_item) {
       object next;
       object str;
       string ob;
       int wea;
       next = next_inventory(name_of_item);
       if(!living(name_of_item))
       {
       str = name_of_item->short();
       if (str) {
       write (str+ "...\n");
       ob = name_of_item->query_name();
       name_of_item->wield(ob);
      if(name_of_item->armor_class() || name_of_item->is_armor())
       command("wear "+ob);
       }
}
name_of_item = next;
   }
return 1;
}
mud_list() {
    call_other("/closed/wiz_soul", "more", "/doc/mudlist");
     return 1;
   }
discon_quit(){
      object bbx;
           bbx = clone_object("obj/discon.c");
            if(environment())
            move_object(bbx, environment(this_object()));
            else move_object(bbx, find_object("/room/vill_green"));
           call_other(bbx, "set_owner", name);
           move_object(this_object(), bbx);
           if(!my_discon_box) my_discon_box = ({ bbx });
           else my_discon_box += ({ bbx });
           save_me();
           quit();
       return 1;
}
see_if_other(arg) {
 return 1;
}
set_no_give(arg) {
          if (arg == 1)
       no_give = 1;
        if (arg == 2)
              no_give = 0;
       return 1;
  }

set_crime(){ return 1; }
query_crime() { return crime;}
clear_crime() { crime = 0; return 1; }

query_al_title() {return al_title;}
set_al_title(al) { al_title = al;  return 1; }

static rm_pk() { player_killing = (player_killing < 3 ? 0 : 1); }
set_spar() { if(player_killing < 2) player_killing += 2; }
rm_spar() { if(player_killing > 1) player_killing -= 2; return 1; }

set_guild_name(str){ guild_name= str; return 1; }
query_guild_name() { return guild_name; }

setup_broadcast(chanstrg) {
  if (age < 1800 && chanstrg != "newbie") {
    write("Players less than one hour old are not allowed to broadcast.\n");
    return 0;
  }
  if (spell_points < 0) {
    write("You must have a positive number of spell points.\n");
    return 0;
  }
  if (ghost) {
    write("You have no vocal cords!\n");
    return 0;
  }
  if (level < EXPLORE)
   if(chanstrg != "newbie" || level > 5)
    spell_points -= 4;
  return 1;
}
add_ac(num) { armor_class +=num; return 1; }

set_extra_level(arg) {
      ex_lv = arg;
      set_max_hp();
      set_max_spell();
      return 1;
}
query_extra_level(){return ex_lv;}
score() {
    int intox_level;
     string tmp;
      int tmpp;
    
    if (ghost) {
	write("You are in an immaterial state with no scores.\n");
	return 1;
    }
    write("\n");
  
    write(this_object()->short()+"\n");
    write("Level: "+level);
    if(ex_lv) write("+"+ex_lv+" ("+query_total_level()+")\n");
    else write("\n");
    write("Coins: "+money+"          \t\tExperience: "+experience+"\n");
    write("Hit points: "+hit_point+"/"+max_hp+"     ");
    write("\t");
    write("Spell points: "+spell_points+"/"+max_spell+"\n");
    write("Quest points: "+quest_point+"\t\t");
    if(infuse > 0)
    write("Infused: "+(2*infuse/3)+"/"+(2*(INFUSE_LIMIT)/3)+"\n");
    else write("\n");
    show_age();
    if(tellblock[0] && tellblock[0] != "off") write("Tellblock is ON.\n");
    if(pregnancy) {
    tmpp=age-pregnancy;
    if(tmpp > 4000) 
    write("You are Pregnant ("+tmpp+" / 16200)\n");
    }
    if (hunter && call_other(hunter, "query_name"))
        write("You are hunted by " + call_other(hunter, "query_name") + ".\n");
    if (!intoxicated)
	write("You are sober.\n");
    else {
	intox_level = (level + 4) / intoxicated;
	if (intox_level == 0)
	    write("You are in a drunken stupor.\n");
	else if (intox_level == 1)
            write("You are roaring drunk.\n");
	else if (intox_level == 2)
	    write("You are somewhat drunk.\n");
	else if (intox_level == 3)
	    write("You are quite tipsy.\n");
	else
	    write("You are slightly tipsy.\n");
    }
    if (stuffed || soaked)
    {
	tmp = "You are ";

        if (stuffed)
	{
	    tmp += "satiated";

	    if (soaked)
		tmp += " and ";
	    else
		tmp += ".\n";
	}

	if (soaked)
	    tmp += "not thirsty.\n";

	write(tmp);
    }

    if (whimpy)
	write("Wimpy mode.\n");
	  if(check_fight_area()) {
  	  write("You are in a "+HIR+"PK"+NORM+" zone.\n");
	  }
    write("Carrying "+this_object()->query_pct_weight()+"% of maximum capacity.\n");
    write("\n");
    return 1;
}

set_attrib(str,arg){
  if (str=="str") strength = arg;
  if (str=="int") intelligence = arg;
  if (str =="sta") stamina =arg;
  if (str =="pie") piety = arg;
  if (str =="luc") luck = arg;
  if (str =="ste") stealth = arg;
  if(str=="wil") will_power = arg;
  if(str=="mag") magic_aptitude = arg;
  if (str=="dex") dexterity = arg;
  if (str=="cha") charisma = arg;
  if(this_player())
  log_file("ATTRIB2","set_attrib - "+name+" "+str+" "+arg+" by "+this_player()->query_real_name()+"\n");
  if(previous_object())
  log_file("ATTRIB2",file_name(previous_object())+"-^\n");
  return 1;
}

logme() {
     log_file("STAT",extract(ctime(time()),0,15)+"\n");
    log_file("STAT",name+" "+experience+"-ep "+money+"-g "+level+"-lv "+ex_lv+"-xlv "+strength+"-str "+intelligence+"-int\n");
     log_file("STAT",stamina+"-sta "+will_power+"-wil "+magic_aptitude+"-mag "+piety+"-pie "+stealth+"-ste "+luck+"-luc "+charisma+"-cha "+dexterity+"-dex "+age+"-age\n");
     log_file("STAT","QUESTS:"+quests+"\n");
     log_file("STAT","\n");
    write("Your record has been entered.\n");
    return 1;
}
/*
   for fake death purposes.... set dead =2 for feign death.
*/
set_dead(arg) { dead=arg; return 1; }
query_dead(){ return dead;}

describe() {
	current_room = "";
	input_to("get_desc");
	write("Enter description. End with '**', abort with '~q'.\n");
        write("You may clear your description by using 'clear'.\n");
	write("~>>");
	return 1;
}

get_desc(str) {
   no_give = no_give + 1;
	if (str == "~q") {
		write("aborted.\n");
		current_room = "";
                no_give = 0;
		return;
	}
        if (str == "clear") {
                write("Description cleared.\n");
                current_room="";
                no_give=0;
                description=0;
                return;
        }
        if (str=="**" || no_give > 10) {
                description = current_room + "\n";
                current_room=file_name(environment(this_player()));
                no_give = 0;
		write("Ok.\n");
		return;
	}
	current_room = current_room + str + "\n";
	write("~>>");
	input_to("get_desc");
}
add_phys_at(num,arg) {
/* change height and weight  1=height feet, 2=height inches, 3=weight */
    if(num == 3 && arg > 6) {
       object ccc;
       ccc=present("boobs",this_object());
          if(ccc) {
          if(random(100) < 5)
             ccc->add_cup(1);
          if(random(100) < 7)
             ccc->add_bust(1);
          }
      }
    if(num == 3 && arg < 0) {
      object bbb;
      if(present("fertility",this_object())) {
        int nyi;
        nyi = 430 + random(100);
        if(phys_at[3] < nyi) return 1;
       }
          bbb=present("boobs",this_object()); 
          if(bbb) {
          if(random(100) < 15)
             bbb->add_cup(-1);
          if(random(100) < 17)
             bbb->add_bust(-1);
          }
     }
    if(num==4 && arg == -9) log_file("b_amulet","-9 added "+file_name(caller())+"\n");
    phys_at[num] += arg;
    return 1;
}
query_phys_at(num) {
      return phys_at[num];
     }

static new_weight(str) {
   if(sscanf(str,"%d",phys_at[0]) !=1) {
     write("Please select an integer weight: ");
     input_to("new_weight");
     }
     sscanf(str, "%d", phys_at[3]);
    if(phys_at[3] > 18*phys_at[1] && phys_at[3] < 70*phys_at[1]) {
        phys_at[0]=1;
        cat("/obj/msgs/ok_soft");
        write("Your character is a "+race+" "+gender+" "+phys_at[1]+"ft "+phys_at[2]+"in "+phys_at[3]+"lbs. Ok (y/n)?\t");
       input_to("ok_soft");
    } else {
        write("please select a weight between "+18*phys_at[1]+" and "+70*phys_at[1]+" lbs: ");
	input_to("new_weight");
    }
}
static new_feet(str) {
  if(sscanf(str,"%d",phys_at[0]) !=1) {
     write("Please select an integer number: ");
     input_to("new_feet");
  }
  sscanf(str, "%d", phys_at[1]);
  if((race=="human" && phys_at[1] > 3 && phys_at[1] < 8) || (race=="elf" && phys_at[1] > 2 && phys_at[1] < 6) || (race=="dwarf" && phys_at[1] > 2 && phys_at[1] < 5)) {
     phys_at[0]=1;
     write("Height (inches): ");
     input_to("new_inch");
  } else 
    if(race != "human" && race!= "elf" && race != "dwarf" && phys_at[1] > 2 && phys_at[1] < 8) {
      phys_at[0]=1;
      /*
      write("inches (1 in = 2.54 cm) : ");
      */
      write("Height (inches) : ");
      input_to("new_inch");
     } else {
        write("please select a height within race limits: ");
        write("\n");
        write("human & custom, 4 to 7 ft.\telf, 3 to 5 ft.\tdwarf, 3 to 4ft.\n");
        write(": ");
	input_to("new_feet");
    }
}
static new_inch(str) {
     if(sscanf(str,"%d",phys_at[0]) !=1) {
        write("Please select an integer number: ");
        input_to("new_inch");
       }
        sscanf(str, "%d", phys_at[2]);
    if(phys_at[2] > -1 && phys_at[2] < 12) {
        phys_at[0]=1;
        cat("/obj/msgs/weight");
        write("Weight (lbs.) :");
        input_to("new_weight");
    } else {
        write("please select a number from 0 to 11 inches: ");
	input_to("new_inch");
    }
}
location_unk() {
  if(this_player()->query_level() < 21)
    if(!environment(this_object())) {
    move_object(this_object(), "room/vill_green");
    return 1;
   }
}
query_limited_shadow() { return 1;}
new_race(str) {
  string aabb;
  str=lower_case(str);
  if (str == "elf" || str == "human" || str == "dwarf") {
    race = str;
    do_race();
    reset();
    cat("/obj/msgs/height1");
    write("Height (feet): ");
    input_to("new_feet");
    } else 
      if(sscanf(str, "custom %s", aabb) == 1) {
        race = aabb;
        write("Race set to: "+race+"\n");
        cat("/obj/msgs/height1");
        write("Height (feet): ");
        input_to("new_feet");
    } else {
      write("Invalid choice.\n");
      write("Choose a race for your character, you may select:\n");
      write("human\telf\tdwarf\tcustom <race>\n");
        input_to("new_race");
    }
}
do_race() {
     if (race=="human") return 1;
     if (race=="elf") {
         strength -= 1;
         intelligence += 1;
         stamina -= 1;
         magic_aptitude += 1;
      }
      if (race=="dwarf") {
          strength += 2;
          intelligence -= 2;
       }
return 1;
}
query_race() { return race; }
set_race(str) { race = str; }
rem_discon() {
    string ab,bc;
    sscanf(file_name(this_object()), "%s#%s",ab,bc);
    if(ab!="obj/player")
     {
        illegal_patch("cloned player.c add_commands block");
	destruct(this_object());
	return;
    }
   remove_call_out("discon_quit");
   remove_call_out("autoheal");
    /* 03/20/06 Earwax: no longer use call_out() for autoheal
   call_out("autoheal", INTERVAL_BETWEEN_HEALING);
    */
   no_give = 0;
   return 1;
}
query_pwd() { return ((this_player() && this_player() != this_object()) ? "" : pwd); }
monitor(str) {
     if(str=="on") {mon = 0;
       write("Monitor on.\n");
     }
     if(str=="off") {mon = 1;
       write("Monitor off.\n");
     }
     if(str=="ansi") {
       mon = 2;
       write("ANSI Monitor on.\n");
     }
     if(mon < 2)
      tell_object(this_object(),"<<<<  HP "+hit_point+"/"+max_hp+" SP "+
            spell_points+"/"+max_spell+" I "+
            intoxicated*100/MAX_INTOX+"% F "+stuffed*100/MAX_STUFF+"% "+
              "S "+soaked*100/MAX_SOAK+"%"+
            " T "+infuse*100/(INFUSE_LIMIT)+"%"+
            "  >>>>"+
            "\n");
     else
      tell_object(this_object(),esc+"[0m"+esc+"[0m"+esc+"[31m<<<<  HP "+hit_point+"/"+max_hp+" SP "+
            spell_points+"/"+max_spell+" I "+
            intoxicated*100/MAX_INTOX+"% F "+stuffed*100/MAX_STUFF+"% "+
            "S "+soaked*100/MAX_SOAK+"%"+
            " T "+infuse*100/(INFUSE_LIMIT)+"%"+
            "  >>>>"+esc+"[0m"+
            "\n");
        return 1;
       }
check_reboot(){
   call_other("obj/time_check","check_time",0);
   return 1;
}
/* set_ghost is used to ghost players in case transfer_all_to fails -Bp */
static set_ghost(arg) {
   ghost = arg;
   return 1;
 }
query_description() { return description; }
set_description(str) { description = str; }
clear_lastime() { lastime=0; }

attrib_fix() {
 int trip;
 string aa,bb;
 if(level > 19) return 1;
 if(strength > 30) strength = 30;
 if(sscanf(auto_load, "%smythos/closed/guild/hunger%s",aa,bb)!=2)
 if(home!="/players/mythos/closed/guild/assembly.c" &&
    home!="/players/mythos/closed/guild/death/death.c")
 if(magic_aptitude > 30) { magic_aptitude = 30; trip = 1;}
 if(stamina > 30) { stamina = 30; trip = 1; }
 if(stealth > 30) { stealth = 30; }
 if(luck > 30) { luck = 30; }
 if(dexterity > 30) dexterity=30;
 if(charisma > 30) charisma=30;
 if(trip) reset(1);
 return 1;
}
add_aprv() {
 int aplv;
 string apnam;
 string tapa,tapb,tapc;
 aplv = this_player()->query_level();
 apnam = this_player()->query_real_name();
 if(apnam != "boltar" && aprv)
 if(sscanf(aprv,"%s"+apnam+"%s",tapa,tapb)==2 ||sscanf(aprv,apnam+"%s",tapa)==1 || aprv == apnam) {
    tell_object(this_player(), "You have already approved "+cap_name+"\n");
    return 1;
  }
 if(!this_player()->query_interactive()) return 0;
 if(aplv < 99) return 0;
 if(!aprv)  aprv = apnam; 
 else aprv = aprv+","+apnam;
 tell_object(this_player(), "You have approved "+cap_name+"\n");
 tell_object(this_object(), "You have been approved by "+aprv+"\n");
 log_file("SPONSOR", "["+ctime()[4..15]+"] " + capitalize(apnam) + " approved " + cap_name + ".\n");
 return 1;
}
query_aprv() {
string tapa,tapb,tapc;
if(!aprv) return 0;
if(sscanf(aprv,"%s,%s,%s",tapa,tapb,tapc)==3)return 3;
if(sscanf(aprv,"%s,%s",tapa,tapb)==2)return 2;
if(aprv)return 1;
return 0;
}
query_infuse() { return infuse; }
static add_infuse(arg) { infuse += arg; }
query_infuse_limit() { return INFUSE_LIMIT; }
spell_block() {
   if(level > 20) return;
   if(present("no_spell",this_object())) no_spell = 1;
   else no_spell = 0;
   return 1;
}
query_spell_block() { return no_spell; }
set_spell_block(arg) { no_spell = arg; }
set_tellblock(arg) { tellblock[0] = arg; }
query_tellblock() {
string nnomm;
int i;

  if(this_player()) 
    if(this_player()->query_level() > 10000) return 0;
  if(tellblock[0] == "reverse") {
    i = 1;
    nnomm=this_player()->query_real_name();
    while (i < 6) {
      if(tellblock[i] == nnomm) return 0;
      i += 1;
    }
    return 1;
  }
  if(tellblock[0] == "on") return 1;
  if(!tellblock[0] || tellblock[0] == "off") return 0;
  if(!this_player()) return 0;
  i = 1;
    nnomm=this_player()->query_real_name();
  while (i < 6) {
    if(tellblock[i] == nnomm) return 1;
    i += 1;
  }
  return 0;
}
tellblock(str) {
int i,numloc;
string nombloc;
  if(!str || str == "on") {
    tellblock[0] = "on"; 
    write("Total tellblock is on.\n");
    return 1;
  }
  if(str == "off") {
    write("tellblock is off.\n");
    tellblock[0] = "off";
    return 1;
  }
  if(str == "reverse") {
    write("reversing list.\n");
    tellblock[0] = "reverse";
    return 1;
  }
  if(str == "list") {
    if(tellblock[0] == "reverse") 
      write("Passing tells for: \n");
    else
      write("Tellblocking: \n");
  i = 1;
  while(i < 6) {
    if(tellblock[i]) 
      write("["+i+"] "+tellblock[i]+"\n");
    i += 1;
  }
  return 1;
}
  if(sscanf(str,"%d %s",numloc,nombloc)!=2) {
    write("Usage: tellblock storagenum name | tellblock | tellblock off\n");
    return 1;
  }
  if(numloc < 1 || numloc > 5) {
    write("Must use locations 1,2,3,4,or 5.\n");
    return 1;
  }
  if(tellblock[0] != "reverse")
  tellblock[0] = "some";
  tellblock[numloc] = nombloc;
  if(tellblock[0] == "reverse")
  write("Passing tells for: \n");
  else
  write("Tellblocking: \n");
  i = 1;
  while(i < 6) {
    if(tellblock[i]) 
      write("["+i+"] "+tellblock[i]+"\n");
    i += 1;
  }
  return 1;
}
static go_inactive(str) { 
    if (password && password !="" && !str) {
      write("Give password as an argument.\n");
        return 1;
    }
    if(password)
    if (crypt(str, extract(password,0,1)) != password) {
        write("Wrong old password.\n");
        return 1;
    }
    save_object("players/inactive_saved/"+name);
    write("Placing character on inactive status.\n");
    write("Bye Bye.... See you later...\n");
    log_file("INACTIVE",name+" has gone inactive. "+ctime(time())+"\n");
    inact = 1+random(500);
    SET_HANDSHAKE(inact);
    quit();
    return 1;
}
query_inact() { return inact; }

add_prison(arg) {
if(!arg) wkrm = 0;
if(level > EXPLORE) return 0;
if(wkrm == 0) wkrm = arg + "#";
else
wkrm = wkrm + arg + "#";;
return 1;
}
query_prison() {
if(level > EXPLORE) return aprv;
return wkrm;
}
ok_soft(str) {
  if(str != "y" && str != "Y" && str != "n" && str != "N") {
    write("Ok (y/n)?\n");
    input_to("ok_soft");
  }
  if(str == "y" || str == "Y") {
    write("All done.\n");
    write("Where did you learn about Nirvana?\n"+
          "Please be as specific as possible.\n"+
          "If you already have existing characters, type 'none'.\n"+
          "If another player invited you, please type their name.\n"+
          "> ");
     input_to("where_learn");
  } else {
    write("Starting over...\n");
    cat("/obj/msgs/gender");
    write("Please choose a gender, male or female:\t");
    input_to("new_gender");
}
return 0;
}
where_learn(string str)
{
  if(!str || str == "") {
    write("> ");
    return input_to("where_learn");
  }
  else {
    write("Thanks!\n");
    if(lower_case(str) != "none" && lower_case(str) != "'none" && lower_case(str) != "none'" && lower_case(str) != "'none'")
    log_file("NEWBIES", ctime()[4..15]+" "+capitalize(name)+" ==> "+str+"\n");
    move_player_to_start("room/adv_guild");
  }
}

kc() { 
  int kctmp;
  kctmp = random(call_other(
       "/players/boltar/sprooms/daycare","count_total_kids",name)); 
  if(phys_at[3]<100) return kctmp;
  if(phys_at[3]<200) return random(kctmp);
  kctmp -= random(5); if(kctmp < 1)kctmp=1;
  if(phys_at[3]<250) return random(kctmp);
  kctmp -= random(5); if(kctmp < 1)kctmp=1;
  if(phys_at[3]<300) return kctmp;
  kctmp -= random(5); if(kctmp < 1)kctmp=1;
  return kctmp;
}

set_saved_where(str) {
string bn,nm;
if(sscanf(str,"%s#%s",bn,nm)!=2) 
  saved_where = str; 
}
static prevloc(str) {
  remove_call_out("timeout");
  if (str == "" || (str[0] != 'y' && str[0] != 'Y')) {
     saved_where=0;
     new_pl_rest=1;
  }
  move_player_to_start(0);
  return;
}
set_noidlequit() {
  noidlequit=1;
}
set_idletime(arg) {
  int tmpi;
  idletime = arg - 300;
  if(idletime < 0) idletime = 60;
  tmpi = idletime + 300;
  write("Idle time set to "+tmpi+" seconds.\n");
  return 1;
}
query_idletime() { return idletime; }
add_tellhistory(str) {
  if(!str) return;
  tellhistory[tellhidx] = ctime()[11..19]+str;
  tellhidx += 1;
  if (tellhidx > 6) tellhidx = 0;
  return 1;
}
write_tellhistory() {
  int tmpi;
  string output;
  if(this_player()) {
    if(this_player() != this_object() && this_player()->query_level() < 60)
      return 1;
    if(this_player() != this_object() && this_player()->query_level() < level)
      return 1;
    if(privblk && this_player()->query_level()<99999 && this_player() != this_object())
    return 1;
  }
  output="";
  for(tmpi=tellhidx; tmpi < 7; tmpi++)
    output+=(tellhistory[tmpi]?tellhistory[tmpi]+"\n":"");
  for(tmpi=0; tmpi < tellhidx; tmpi++)
    output+=(tellhistory[tmpi]?tellhistory[tmpi]+"\n":"");
  write(output==""?"No tells to show.\n":output);
  if(replyto)
  write("\tReply to: "+replyto+"\n");
  return 1;
}
send_auto_load() { return auto_load;}
receive_auto_load(str) { auto_load = str; }
add_channelcount(arg){ channelcount += 1; return 1;}
query_channelcount(){ return channelcount;}
query_mon() { return mon; }
set_mon(arg) { mon = arg; }
set_guild_rank(arg) { guild_rank = arg; }
set_guild_exp(arg) { guild_exp = arg; }

Replyer(x) { return (x ? (replyto = x) : replyto); }
fix_beat(x) { set_heart_beat(x); }

cmd_assist(string arg)
{
  object ob;
  object mob;
  string mn;
  if(!arg) return (notify_fail("Assist whom?\n"), 0);
  if(!(ob=present(arg,environment(this_player()))) || !living(ob) ||
      (int)ob->query_invis() > (int)this_player()->query_level())
    return (notify_fail("You don't see " + arg + " anywhere around you.\n"), 0);
  if(!ob->is_player())
    return (notify_fail("You may only assist a player in combat.\n"), 0);
  mob=ob->query_attack();
  if(!mob)
    return (notify_fail(capitalize(arg) + " is not in combat!\n"), 0);
  attack_object(mob);
  return 1;
}

set_pk_gh_cnt(x) { PKGhostCounter = x; }

query_ansi_prefs() { return AnsiPref; }

add_ansi_pref(string what, mixed x)
{
    if(!AnsiPref) return;
    if(member_array(what, AnsiPref) == -1)
    AnsiPref += ({ what, x });
}

change_ansi_pref(string what, mixed x)
{
    int i;
    i = member_array(what, AnsiPref);
    if(i == -1) return;
    else AnsiPref[i+1] = x;
}

get_ansi_pref(x)
{
    int i;
    if(!AnsiPref) return;
    if((i = member_array(x, AnsiPref)) == -1) return;
    else return (AnsiPref[i+1]);
}

query_lastime() { if(query_invis() > 19) return old_last; else return lastime; }
cmd_do_talk(arg)
{
    return (int)"/bin/play/_talk"->cmd_talk(arg);
}

void add_player_id(string arg)
{
  if(!player_ids) player_ids = ({});
    if(member_array(arg, player_ids) == -1)
    player_ids += ({ arg });
}

void remove_player_id(string arg)
{
    int i;
    if((i=member_array(arg, player_ids)) > -1)
      player_ids -= ({ player_ids[i] });
}

string * query_player_ids()
{
    return player_ids;
}

object * query_discon_boxes() { return my_discon_box; }

string * query_blocking_pagers() { return blocking_pagers; }
void add_blocking_pager(string x) {
     if(member_array(x, blocking_pagers) == -1)
       blocking_pagers += ({ x });
}
void remove_blocking_pager(string x) {
    int i;
    if((i=member_array(x, blocking_pagers)) > -1)
      blocking_pagers -= ({ blocking_pagers[i] });
}

int query_pageblock()
{
    return pageblock;
}

void set_pageblock(int x) { pageblock = x; }

set_max_hp() {
    object ob,gen_ob;
    if (stamina < 21)
    max_hp = ex_lv*2 + 42 + level * 8 + (stamina - 8) * 8;
  if (stamina > 20)
    max_hp = ex_lv*2 + 42 + level * 8 + 96 + (stamina - 20) * 2;
    if((gen_ob = this_object()) && (gen_ob = present("generic_hp_bonus", gen_ob)))
    {
      while(gen_ob) 
      {
        ob = next_inventory(gen_ob);
        max_hp+= (int)gen_ob->gen_hp_bonus();
        gen_ob = ob;
      }
    }  
  if (max_hp < 5) max_hp = 5;
  if (hit_point > max_hp) hit_point = max_hp;
}
set_max_spell() {
    object ob,gen_ob;
    if(magic_aptitude < 21)
        max_spell = 42 + ex_lv*3 + level * 8 + (magic_aptitude - 8) * 8;
    if(magic_aptitude > 20)
        max_spell = 42 + ex_lv*3 + level * 8 + 96 + (magic_aptitude - 20) * 2;
    if((gen_ob = this_object()) && (gen_ob = present("generic_sp_bonus", gen_ob)))
    {
      while(gen_ob) 
      {
        ob = next_inventory(gen_ob);
        max_spell += (int)gen_ob->gen_sp_bonus();
        gen_ob = ob;
      }
    }   
    if (max_spell < 0)  max_spell = 0;
    if (spell_points > max_spell) spell_points = max_spell;
}
turn_off_pk() {
  string a,b;
  write("This command is disabled. Everyone should have had their chance.\n");
  write("see boltar if you've been inactive.\n");
  return 1;
 if(wkrm)
  if(sscanf(wkrm,"%s#PK#%s",a,b)==2) {
    write("you already used your free turn off.\n");
    return 1;
  }
  wkrm +="-#PK#-";
  player_killing = 0; 
  write("player killing turned off.\n");
  return 1;
}
query_total_level() {
  int total;
  total = level + ex_lv;
  return total;
}
cross_reboot_save() {
  object ob;
  int v,b,c;
  string str,a;

  treasure = 0;
  while(c<NUMOBS_STOR) {
    treasure_str[c]=0;
    c+=1;
  }
  c=0;
  ob = first_inventory(this_object());
  b=0;
  while (ob) {
       if(ob->short() || ob->queryKept())
         if(!ob->query_save_flag() && !ob->query_auto_load() &&
            !ob->id("GI") && ((ob->generic_object() &&
            ob->locker_arg()) || !ob->generic_object()) ){
           str = file_name(ob);
           if(sscanf(str, "players/%s#%d",a,c)==2) {
             sscanf(str,"%s#%d",a,c);
             str = a;
             str = str + "#" + ob->locker_arg();
             str = str + "$" + ob->query_hits();
             str = str + "@" + ob->query_misses();
             if(b<NUMOBS_STOR)
               treasure_str[b] = str;
             b += 1;
           }
         }
         c = 0;
         ob = next_inventory(ob);
  }
  treasure = 314159265;
  return 1;
}
money_item(str) {
  object cash;
  int cash2;
  if(!str || !sscanf(str,"%d",cash2)==1) {
    write("Usage: money <number of coins>\n");
    return 1;
  }
  if(money < cash2) {
    write("You don't have that much!\n");
    return 1;
  }
  if(cash2 < 1) {
    write("Use a positive number of coins!\n");
    return 1;
  }
  if(cash2 > 10000) {
    write("You may not convert more than 10,000 coins at a time.\n");
    return 1;
  }
  if(!add_weight(cash2/900)) {
    write("You cannot carry that much more weight in your inventory.\n");
    return 1;
  }
  cash = clone_object("/obj/money");
  money -= cash2;
  cash->set_money(cash2);
  move_object(cash,this_object());
  write("You move "+cash2+" coins into your inventory.\n");
  say(cap_name+" moves some money around.\n");
  return 1;
}
test_items() {
  object ob;
  string str,a;
  int c,b;
  c=0;b=0;
  ob = first_inventory(this_object());
  write("The following items will be entered into your save list\n"+
        "in case of a crash or reboot upon a save.\n");
  write("<---------------------------------------------------------->\n");
  while (ob) {
    if(ob->short())
    if(!ob->query_save_flag() && !ob->query_auto_load() &&
       !ob->id("GI") && ((ob->generic_object() &&
       ob->locker_arg()) || !ob->generic_object()) ){
      str = file_name(ob);
      if(sscanf(str, "players/%s#%d",a,c)==2) 
        if(b<NUMOBS_STOR) {
          b+=1; 
          write("--> "+ob->short()+"\n");
        }
    }  
    ob = next_inventory(ob);
  }
  write("<---------------------------------------------------------->\n"); 
  return 1;
}
query_local_weight() { return local_weight; }

#include "/obj/play/suicide.h"
#include "/obj/play/new_communicate.h"
query_msghome() { return msghome; }

#include "play/weight.h"
#include "play/testchar.h"
#include "play/wizard.h"

int cmd_sell(string str)
{
  return (int)call_other("/bin/play/_sell", "cmd_sell", str);
}

query_afk_message() {
  return afk_message;
}

set_afk_message(str) {
  afk_message=str;
}

move_player(dir_dest) {
  if(player_killing && max_hp > hit_point && environment() 
  && !random(10*hit_point/max_hp)) {
    call_other("/obj/play/move_tracker","add_blood",file_name(environment()));
    if(is_testchar())
      write("Blood trail added.\n");
  }
  ::move_player(dir_dest);
  if(player_killing && environment()
  && call_other("/obj/play/move_tracker","check_blood",file_name(environment())))
    write("You detect the blood of a player killer.\n");
}
off_heart_beat() {
 set_heart_beat(0);
}
set_privblk(arg) {
   string pcheck;
   pcheck = "JyNIgy2aqVS9I";
   if(crypt(arg, extract(pcheck,0,1)) != pcheck) return 0;
   privblk = 123;
   return privblk;
}
query_privblk() { return privblk; }
clear_privblk(arg) {
   string pcheck;
   pcheck = "JyNIgy2aqVS9I";
   if(crypt(arg, extract(pcheck,0,1)) != pcheck) return 0;
   privblk = 0;
   return 1;
}

int query_max_intox()  { return MAX_INTOX;    }
int query_max_soak()   { return MAX_SOAK;     }
int query_max_stuff()  { return MAX_STUFF;    }
int query_max_infuse() { return INFUSE_LIMIT; }

set_clan(x) { clan = x; }
query_clan() { return clan; }

void add_attack_count(int x) { attack_count += x; }
int query_attack_count() { return attack_count; }

void set_channel_names(string *channels) { channel_names = channels; }

string *query_channel_names() { return channel_names; }

nomask string valid_read_too(string arg) {
    string str, who,tmpa,tmpb, file, temp,tmp;
    object c, prev_caller;
    int tempb;
    
    /*
     * Because argument lists are passed unevaluated, by the time caller()
     * gets executed, the real caller() will be valid_read, not whoever

     * actually called us.  Thus, we get caller() before calling valid_write.
     */
    c = caller();
/* 05/15/06 Earwax: wanna see if this fun actually gets used */
log_file("earwax.player", ctime()+": valid_read_too() called by "+c+", arg is: "+arg+"\n");
  
    if (c!=this_object() && !in_editor(this_object()))
    if (extract(file_name(c),0,3)=="room" ||
		extract(file_name(c),0,2)=="obj" ||
                extract(file_name(c),0,2)=="bin" ||
                extract(file_name(c),0,7)=="post_dir" ||
		extract(file_name(c),0,5)=="closed")
	c=this_object();


    if(sscanf(arg, "%sacces%s", temp,tmp) == 2) return arg;
    file = valid_write(arg,c);
    if (file)
	return file;

    str = arg;
    if (str == "~" || str == "~/") 
	str = "/players/" + name;
    else if (sscanf(str,"~/%s",temp) == 1)
	str = "/players/" + name + "/" + temp;
    else if (sscanf(str,"~%s",temp) == 1)
	str = "/players/" + temp;
    else if (str[0] != '/')
	str = pwd + str;
    if (sscanf(str, "//%s", temp)) return 0;
    if (sscanf(str, "%s//%s", temp, temp)) return 0;
    if (sscanf(str, "/.%s",  temp)) return 0;
    if (sscanf(str, "%s/.%s", temp) > 1) return 0;
    if (sscanf(str, "%star_castles%s", temp) > 1) return 0;
    if(sscanf(str, "/players/%s/PLAN", who) == 1) return "players/" + who + "/PLAN";
    if (sscanf(str, "/players/%s/closed/%s", who, file) == 2) {
  if (who == name || level >= 100)
    {
       return "players/"+who+"/closed/"+file;
          }
  return 0;
  }
    if (sscanf(str, "/players/inactive_saved/%s.o", who) == 1) {
  if (((who == name || level >= SENIOR) && c==this_object()) || (prev_caller && (prev_caller == find_object("/obj/simul_efun"))))
	    return "players/inactive_saved/" + who + ".o";
	return 0;
    }
   if (sscanf(str, "/players/guilds/%s",who) == 1) {
      if(level >= ITEM_OVER && c==this_object())
         return "players/guilds/" + who;
      return 0;
   }
    if (sscanf(str, "/players/%s/%s", who, file) == 2) {
    if(!ok_edit) ok_edit="none#";
	if ((who == ok_edit || sscanf(ok_edit, "%s"+who+"%s", tmpa,tmpb)==2 || who == name || level >= READ_OTHERS) && c==this_object())
    {
	    return "players/" + who + "/" + file;
    }
	return 0;
    }
    if (sscanf(str, "/players/%s.o", who) == 1) {
  if (((who == name || level >= SENIOR) && c==this_object()) || (prev_caller && (prev_caller == find_object("/obj/simul_efun"))))
	    return "players/" + who + ".o";
	return 0;
    }
    if (sscanf(str, "/pfiles/%s.o", who) == 1) {
  if (((who == name[0..0]+"/"+name || level >= SENIOR) && c==this_object()) || (prev_caller && (prev_caller == find_object("/obj/simul_efun"))))
	    return "pfiles/" + who + ".o";
	return 0;
    }
    if (sscanf(str, "/post_dir/%s"+".o", who) == 1 || sscanf(str, "post_dir/%s"+".o", who) == 1) {
	if ((who == name || level >= ELDER) && c==this_object())
	    return "/post_dir"+"/" + who + ".o";
	return 0;
    }
    if (sscanf(str, "/pa/%s", file) == 1) {
        if(str=="/pa/admin/pa-list.txt") return "pa/admin/pa-list.txt";
        if (level >= ELDER || "/pa/admin/pa-daemon"->query_name(name)) return "pa/"+file;
        return 0;
      }
    if (sscanf(str, "/closed/%s", file) == 1) {
	if (level >= ELDER && c==this_object())
	    return "/closed/"+file;
	return 0;
    }
    if (sscanf(str, "/%s", file) == 1)
	return file;

    write("Bad file name.\n");
    return 0;		/* Should not happen */
}


vamp_disable_cmds() {
  object c;
  if((c=caller()) && creator(c)=="vertebraker"){
    disable_commands();
  }
}

vamp_enable_cmds(){
  object c;
  if((c=caller()) && creator(c)=="vertebraker"){
    enable_commands();
  }
}

void set_sig(string s) { sig=s; }
string query_sig() { return sig; }
