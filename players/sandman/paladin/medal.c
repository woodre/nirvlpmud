
/*
 * PALADIN GUILD MEDAL 
 * Stores all player info in /members dir
 * This is the object carried by all guild members
 */

#define VERSION "3.0.0"      /* Colorized! */
query_version() { return VERSION; }

#define UPDATE "05/02/94"
query_update() { return UPDATE; }

#include "defs.h"

#define BANISH_MASTER "/players/sandman/paladin/banish_master"
#define MEMBERDIR "players/sandman/paladin/members/"
#define LOGINMSG "enters the game."
#define LOGOUTMSG "has left the game."

/*
 * If you wish to favor or punish the Paladins change this value.
 */
#define FAVOR 0
query_favor() { return FAVOR; }

static int battle, lit, blessed;
static string me; 
int muffled, guild_login, wimpy_at, call_time, bard_cant;
string loginmsg, logoutmsg;
string last_time, wimpydir;

/* Weapon proficiency variables */
int sword_pro, axe_pro, mace_pro, lance_pro, flail_pro;

/* Combat method variables */
static int combat_method; 
int mounted_mod, dual_mod, shield_mod;

reset(arg) {
   if(arg)
      return;
   if(this_player() && !this_player()->query_guild_exp()) 
      this_player()->add_guild_exp(1);
   battle = 0;
   lit = 0;
   combat_method = 0;
   if(!loginmsg) loginmsg = LOGINMSG;
   if(!logoutmsg) logoutmsg = LOGOUTMSG;
}

extra_look(){
   return "A glowing aura of goodness surrounds "+
          capitalize(environment(this_object())->query_name());
}

set_muffled(mf) { muffled = mf; }
query_muffled() { return muffled; }

set_wimpy_at(wa) { wimpy_at = wa; }
query_wimpy_at() { return wimpy_at; }

set_wimpydir(wp) { wimpydir = wp; }
query_wimpydir() { return wimpydir; }
                                                 
set_battle(bt) { battle = bt; }
query_battle() { return battle; }

set_call_time(t) { call_time = t; }
query_call_time() { return call_time; }

set_guild_login(l) { guild_login = l; }
query_guild_login() { return guild_login; }

set_cant() { bard_cant = 1; }
query_cant() { return bard_cant; }

set_blessed(b) {
   blessed = b;
   call_out("end_bless", BLESS_DUR);
}
query_blessed() { return blessed+FAVOR; }
query_spell_blessed() { return blessed; }

id(str) { return str == "medal" || str == "medallion" ||
                 str == "guild_medal" || str == "pro_object" ||
                 str == "guild_death_object"; }

query_auto_load() { return "/players/sandman/paladin/medal:"; }

init_arg() {
   if(restore_object(MEMBERDIR+this_player()->query_real_name()))
     write(filter_color("Restoring guild info..........\n",HIG));
   else {
     write(filter_color("Creating savefile for guild info.......\n",HIG));
     save_medal();
   }
   last_time = ctime(time()); 
   if(guild_login) 
     move_object(this_player(), PALGUILD);
   if(!this_player()->query_invis() && !muffled) 
     guild_emote(loginmsg);
   news();
   return;
}

banish_me() {   
   string *banished_tmp;
   
   banished_tmp = BANISH_MASTER->query_banished();
   if(member_array(this_player()->query_real_name(),banished_tmp) != -1) {
     write(filter_color("You have been banished from the Paladins!\n",HIR));
     destruct(this_object());
     return 1;
   }
}

get() { return 1; }
drop() { return 1; }

short() { 
   string tmp_short;

   tmp_short = "A bronze medallion (worn)";
   if(blessed)
     tmp_short += " [blessed]";
   if(lit)
     tmp_short += " [glowing softly]";
   return tmp_short;
}

long() {
   write("A beautifully crafted medallion made of bronze.\n");
   write("In the center of the medallion is a pyramid comprised of\n");
   write("three levels.  Each level is divided into a corresponding\n");  
   write("number of parts.  Each part contains an image.\n");   
   write("The third level, the base of the pyramid, is divided into\n"); 
   write("three parts. The first part has a picture of a sword, the next\n");  
   write("a depiction of a human body, and the last part, a shield.\n");
   write("The second level, the middle of the pyramid, consists of\n");
   write("two parts.  The left part has an image of a book, while the\n");
   write("right part shows a sceptre.  The first level, the top of\n");
   write("pyramid has the lone picture of a balance, with both sides\n");
   write("being even with each other.\n"); 
   write("Type 'medal' for help\n");
}

init() {
   me = this_player()->query_real_name();
   this_player()->set_guild_name("paladin");
   add_action("battlescore","battlescore");
   add_action("battlescore","bsc");
   add_action("news","news");
   add_action("set_combat_method","combat");
   add_action("guild_login","login");
   add_action("manual","manual");
   add_action("continual_light","continual");
   add_action("dispell","dispell");
   add_action("no_spell","missile",2);
   add_action("no_spell","shock",2);
   add_action("no_spell","fireball",2);
   add_action("no_spell","sonic",2);
   add_action("save_medal","savemedal"); 
   add_action("restore_medal","restoremedal");
   add_action("loginmsg","loginmsg");
   add_action("logoutmsg","logoutmsg");
   add_action("quit","quit");
   add_action("msgs","msgs");
   add_action("toggle_color","toggle_color");
/***************************/
/*   Commands in power.c   */
/***************************/
   add_action("members","members");
   add_action("clw","clw");
   add_action("csw","csw");
   add_action("ccw","ccw");
   add_action("set_guild_title","gtitle"); 
   add_action("rank","rank");
   add_action("muffles","muffles"); 
   add_action("register","newmedal");  
   add_action("wimpydir","wimpydir");
   add_action("wimpyhp","wimpyhp");
   add_action("guild_tell","gtell",2);
   add_action("guild_tell"); add_xverb("-");
   add_action("guild_who","gwho");
   add_action("guild_emote","gemote",2);
   add_action("who2","wh");
   add_action("finger","finger");  
   add_action("help_medal","medal"); 
   add_action("judge","judge");
   add_action("salute","salute");
   add_action("identify_object","identify",2);
   add_action("call","call");
   add_action("protection","protection");
   add_action("bless","bless");
   add_action("assess","assess");
   add_action("mark","mark");
   add_action("invite","invite");
   add_action("killing_blow","kb");
   add_action("change","change");
   add_action("repair","repair");
   add_action("cant","cant");
   add_action("guild_echo","emit");
   add_action("compare","compare");
/***************************/ 
/* Guild Commander Powers  */
/***************************/ 
   add_action("banish","banish");
   add_action("banish_list","banishlist");
   add_action("restore","restore");
   add_action("cmdr_tell","ctell",2);
   add_action("summon","summon");
   add_action("palstat","palstat");
   add_action("cmdtitle","cmdtitle");
   add_action("castle","castle");
   add_action("cmdr_help","cmdr_help");
   banish_me();
}

/* Enable/Disable Color */
int color_ok;

toggle_color() {
   color_ok = !color_ok;
   if(color_ok)
     write("Ansi color is ON!\n");
   else
     write("Ansi color is OFF!\n");
   return 1;
}
query_color() { return color_ok; }


save_medal() {
   save_object(MEMBERDIR+this_player()->query_real_name());
   write(filter_color("Guild info saved.....\n",HIG));
   return 1;
}

restore_medal() {
   restore_object(MEMBERDIR+this_player()->query_real_name());
   write(filter_color("Guild info restored.....\n",HIG));
   return 1;
}

end_bless() {
   if(!blessed)
     return 1;
   blessed = 0;
   tell_object(environment(this_object()), 
       filter_color("Your blessing has worn off.\n",HIG));
   return 1;
}

/* Don't allow use of spells */
no_spell() { 
  notify_fail("It is not the way of the Paladin to use spells."); 
}

/*
 * Heartbeat will only be on when the battlescore command
 * is being used.
 */

heart_beat() {
   if(!me) 
     return;
   if(!battle)
     set_heart_beat(0);
   if(battle && wimpy_at && find_player(me)->query_hp() < wimpy_at) {
      if(find_player(me)->query_attack()) {
         if(wimpydir) {
            command(wimpydir, find_player(me));
            tell_object(find_player(me),
                filter_color("You retreat to the "+wimpydir+"!\n",HIG,
                find_player(me)));
         } else
            find_player(me)->run_away();
         }
   }
   if(battle) {
      int hp, sp, mhp, msp;
      hp = find_player(me)->query_hp();
      sp = find_player(me)->query_sp();
      mhp = find_player(me)->query_mhp();
      msp = find_player(me)->query_msp();
      tell_object(find_player(me),
         filter_color("Hit points: ["+hp+"/"+mhp+"]    Spell points: ["
         +sp+"/"+msp+"]\n",HIR, find_player(me)));
   }
}

/********************************/
/*      WEAPON PROFICIENCY      */
/********************************/

set_weapon_pro(str, arg) {
   if(str == "sword") sword_pro = arg;
   if(str == "axe") axe_pro = arg;
   if(str == "mace") mace_pro = arg;
   if(str == "lance") lance_pro = arg;
   if(str == "flail") flail_pro = arg;
}

query_weapon_pro(str) {
   if(str == "sword") return sword_pro;
   if(str == "axe") return axe_pro;
   if(str == "mace") return mace_pro;
   if(str == "lance") return lance_pro;
   if(str == "flail") return flail_pro;
}

/****************************/
/*      COMBAT METHODS      */
/****************************/

/*
 * Which combat method are we using?
 * 0 = standard
 * 1 = mounted
 * 2 = shield & sword
 * 3 = dual weapons
 */

query_combat_method() { return combat_method; }

query_combat_mod(str) {
   if(str == "mounted") return mounted_mod;
   if(str == "shield") return shield_mod;
   if(str == "dual") return dual_mod;
}

set_combat_mod(str, arg) {
   if(str == "mounted") mounted_mod = arg;
   if(str == "shield") shield_mod = arg;
   if(str == "dual") dual_mod = arg;
}

set_combat_method(str) {
   if(str == "standard") {
     if(mounted_attack())
       return 1;
     write(filter_color("Combat method set to Standard.\n",HIG));
     combat_method = 0;
     return 1;
   }
   if(str == "mounted") {
     write(filter_color("Combat method set to Mounted.\n",HIG));
     combat_method = 1;
     return 1;
   }
   if(str == "shield") {
     if(mounted_attack())
       return 1;
     write(filter_color("Combat method set to Shield & Sword.\n",HIG));
     combat_method = 2;
     return 1;
   }
   if(str == "dual") {
     if(mounted_attack())
       return 1;
     write(filter_color("Combat method set to Dual Weapons.\n",HIG));
     combat_method = 3;
     return 1;
   }
   write("Available combat methods:\n");
   write("------------------------------------------------------------\n");
   write("Standard   Mounted   Shield & Sword   Dual Weapons\n");
   return 1;
}

/*
 * Do not allow players to change combat methods
 * during mounted attack.
 */

mounted_attack() {
   object warhorse;
   warhorse = present("paladin_horse", environment(this_player()));
   if(warhorse && warhorse->query_attack()) 
     notify_fail("You cannot change combat methods during mounted attack.\n");
   return 0;
}

/****************************/
/* SOME INFO USED BY RANK() */
/****************************/

abilities() {
   write("Weapon Proficiencies:                  Combat Methods:\n");
   write("[===========================]          [======================]\n");
   write(justify(" Sword:",10)+justify(sword_pro,5)+justify("Axe:",10)+
         justify(axe_pro,4)+justify("",10)+justify(" Mounted:",20)+
         justify(mounted_mod,4)+"\n");
   write(justify(" Lance:",10)+justify(lance_pro,5)+justify("Flail:",10)+
         justify(flail_pro,4)+justify("",10)+justify(" Shield & Sword:",20)+
         justify(shield_mod,4)+"\n");
   write(justify(" Mace:",10)+justify(mace_pro,5)+justify("",24)+
         justify(" Dual Weapons:",20)+justify(dual_mod,4)+"\n");
   write("[===========================]          [======================]\n");
   write("\n");
   write("Current Combat Method: ");
   if(combat_method == 0)
     write("Standard\n");
   if(combat_method == 1)
     write("Mounted\n");
   if(combat_method == 2)
     write("Shield & Sword\n");
   if(combat_method == 3) 
     write("Dual Weapons\n");
   write("\n");
   return 1;
}

attributes() {
   int str, sta, pie, luc, ste, wil, inte, mag;
   str = this_player()->query_attrib("str");
   sta = this_player()->query_attrib("sta");
   pie = this_player()->query_attrib("pie");
   luc = this_player()->query_attrib("luc");
   ste = this_player()->query_attrib("ste");
   wil = this_player()->query_attrib("wil");
   inte = this_player()->query_attrib("int");
   mag = this_player()->query_attrib("mag");
   write("Attributes:\n");
write("[================================================================]\n");
   write(justify("Strength:",18)+justify(str,5)+justify("Stamina:",18)+
         justify(sta,5)+justify("Piety:",18)+justify(pie,5)+"\n");
   write(justify("Luck:",18)+justify(luc,5)+justify("Stealth:",18)+
         justify(ste,5)+justify("Will power:",18)+justify(wil,5)+"\n");
   write(justify("Intelligence:",18)+justify(inte,5)+
         justify("Magic Aptitude:",18)+justify(mag,5)+"\n");
write("[================================================================]\n");
   return 1;
}

/*
 * When we die, make sure we are set to the correct level.
 * Calls the guilds advancement hall instead of the regular
 * adv_guild.  Used when someone is regenerated, called by
 * the second_life() in player.c
 */

guild_death() {
   tell_object(environment(this_object()), 
       filter_color("Correcting Paladin level....\n",HIG));
   PALGUILD->correct_level(environment(this_object()));
   return 1;
}

/********************************/
/*      VARIOUS COMMANDS        */
/********************************/

/*
 * Set login/logout msgs and destinations
 */

loginmsg(str) {
   if(!str) {
     loginmsg = LOGINMSG;
     write(filter_color("Login message cleared.\n",HIG));
     return 1;
   }
   loginmsg = str;
   write(filter_color("Your login message is now:\n",HIG));
   write(filter_color(this_player()->query_name()+" "+loginmsg+"\n",HIG));
   save_medal();
   return 1;
}

logoutmsg(str) {
   if(!str) {
     logoutmsg = LOGOUTMSG;
     write(filter_color("Logout message cleared.\n",HIG));
     return 1;
   }
   logoutmsg = str;
   write(filter_color("Your logout message is now:\n",HIG));
   write(filter_color(this_player()->query_name()+" "+logoutmsg+"\n",HIG));
   save_medal();
   return 1;
}

msgs() {
   write("Guild Messages:\n");
   write("---------------\n");
   write("Login:\t"+loginmsg+"\n");
   write("Logout:\t"+logoutmsg+"\n");
   return 1;
}

guild_login() {
   guild_login = !guild_login;
   if(guild_login)
     write(filter_color("You are set to logon in the Paladins Guild.\n",HIG));
   if(!guild_login)
     write(filter_color("You are set to logon in the village church.\n",HIG));
   save_medal();
   return 1;
}

/* 
 * Cause player to give logout msg and save_medal when they quit
 */

quit() {
   if(!this_player()->query_invis() && !muffled) 
     guild_emote(logoutmsg);
   save_medal();
   this_player()->quit();
   return 1;
}

/*
 * Create a light source
 */

continual_light(str) {
   if(!str || str != "light")
     return;
   if(!MAIN->verify_use())
     return 1;
   if(lit) 
     notify_fail("Your medallion is already lit.");
   lit = 1;
   if(set_light(1) == 1) {
     write("You can see again.\n");
     say(capitalize(this_player()->query_name())+
                                 "'s medallion begins to glow.\n");
   } else
     write("Ok.\n");
   return 1;
}

/*
 * Dispell light or protection from evil spell
 */

dispell(str) {
   if(!str)
     return;
   if(str == "light") {
     if(!lit) 
       notify_fail("Your medallion is not lit.");
     lit = 0;
     if(set_light(-1) == 0) {
       write("It turns dark.\n");
       say(capitalize(this_player()->query_name())+"'s medallion darkens.\n");
     } else 
       write("Ok.\n");
     return 1;
   }
   if(str == "protection from evil") {
     if(!this_player()->query_protected_from_evil()) 
       notify_fail("You are not under a protection from evil spell.");
     this_player()->stop_protection_from_evil();
     write("You are no longer protected from evil.\n");
     return 1;
   }
   return;
}

/*
 * View the Paladin's Manual
 */

manual() {
   MOREFILE->more("/players/sandman/paladin/helpdir/manual");
   return 1;
}

/*
 * Read paladin news
 */

news() {
   if(query_color())
     write(HIM);
   cat("/players/sandman/paladin/NEWS");
   if(query_color())
     write(NORM);
   return 1;
}

/*
 * Engage battlescore. Will activivate guild wimpy.
 */

battlescore() {
   battle = !battle;   
   if(battle) {
     write(filter_color("Battlescore has been turned ON.\n",HIG));
     set_heart_beat(1);
   } 
   if(!battle) {   
     write(filter_color("Battlescore has been turned OFF.\n",HIG));
     set_heart_beat(0);
   }
   return 1;
}

/*************************************/
/*   FUNCTIONS THAT CALL POWERS.C    */
/*************************************/

clw(str) {  MAIN->cure_light_wounds(str);  return 1; }
csw(str) {  MAIN->cure_serious_wounds(str);  return 1; }
ccw(str) {  MAIN->cure_critical_wounds(str);  return 1; }

wimpyhp(str) {  MAIN->wimpyhp(str);  return 1; }
wimpydir(str) {  MAIN->wimpydir(str);  return 1; }

muffles() {  MAIN->muffles();  return 1; }  
guild_tell(str) {  MAIN->guild_tell(str);  return 1; } 
guild_emote(str) {  MAIN->guild_emote(str);  return 1; }   
guild_who() {  MAIN->guild_who();  return 1; }
guild_echo(str) {  MAIN->guild_echo(str); return 1; }

rank() {  MAIN->rank();  return 1; }
set_guild_title() {  MAIN->set_guild_title();  return 1; }
register() {  MAIN->register();  return 1; }
help_medal(str) {  MAIN->help_medal(str);  return 1; }

finger(str) {  MAIN->finger(str);  return 1; }
who2() {  MAIN->who2();  return 1; }

call() {  MAIN->call(call_time);  return 1; }
identify_object(str) {  MAIN->identify_object(str);  return 1; }
judge(str) {  MAIN->judge(str);  return 1; }
salute(str) {  MAIN->salute(str);  return 1; }
protection(str) {  MAIN->protection(str);  return 1; }
bless() {  MAIN->bless();  return 1; }
assess(str) {  MAIN->assess(str);  return 1; }
mark(str) {  MAIN->mark(str);  return 1; }
members() {  MAIN->members();  return 1; }
invite(str) {  MAIN->invite(str);  return 1; }
killing_blow(str) {  MAIN->killing_blow(str); return 1; }
change(str) {  MAIN->change(str);  return 1; }
repair(str) {  MAIN->repair(str);  return 1; }
cant(str) {  MAIN->bards_cant(str);  return 1; }
compare(str) {  MAIN->compare(str);  return 1; }

banish(str) {  MAIN->banish(str);  return 1; }
restore(str) {  MAIN->restore(str);  return 1; }
cmdr_tell(str) {  MAIN->cmdr_tell(str);  return 1; }
summon(str) {  MAIN->summon(str);  return 1; }
palstat(str) {  MAIN->palstat(str);  return 1; }
banish_list(str)  {  MAIN->banish_list();  return 1; }
cmdtitle() {  MAIN->cmdtitle();  return 1; }
castle() {  MAIN->castle();  return 1; }
cmdr_help() {  MAIN->cmdr_help();  return 1; }

