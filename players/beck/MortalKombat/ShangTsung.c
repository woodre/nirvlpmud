/*
Changelog:
Bal 1996-03-15:
- fixed typo in shout() (defeaded->defeated)
* fixed assumptions in heart beat (now no run-time errors)
*/
#define LOGFILE "/players/dragnar/logs/champs.log"
inherit "obj/monster";
inherit "/obj/user/one_chan.c";
#include "/players/beck/MortalKombat/MKWarrior.h"

reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("Shang Tsung");
   set_race("warrior");
   set_alias("shang");
   set_short("Shang Tsung, champion of Mortal Kombat");
   set_long(
      "He seems to be an old man, about 700 years old.  He has not been\n"+
      "defeated in his 500 years as champion of Mortal Kombat.  Even Goro\n"+
      "bows to the master.  If you defeat him you will be crowned the victor.\n");
   set_level(20);
   set_hp(2000);
   set_al(-1000);
   set_wc(45);
   set_ac(20+random(20));
   InFight = 0;
   Fatality = "Shang Tsung smashes you and makes you bleed.\n"+
   "He lets you suffer as you bleed to death.\n";
   
   set_dead_ob(this_object());
}

