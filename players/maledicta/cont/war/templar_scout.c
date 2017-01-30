#include "/players/maledicta/ansi.h"
#define WAR "/players/maledicta/cont/war/war"
inherit "obj/monster.c";

object gold,helmet,armor,weapon;


reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("scout");
set_alt_name("templar_scout");
set_alias("templar");
set_race("human");
set_short(BOLD+"Templar "+NORM+YEL+"Scout"+NORM);
set_long(
"  Before you is a thin human dressed in light brown\n"+
"leather armor with camouflage decorating his cloak,\n"+
"helm and gloves. A short sword is strapped to his \n"+
"side with several daggers located in strategic places\n"+
"on his body.  You can get a 'report' from him on the\n"+
"wars current situation.\n"); 
set_level(10);
set_hp(150);
set_al(1000);
set_wc(14);
set_ac(8);
set_aggressive(0);
set_heart_beat(1);
gold = clone_object("obj/money");
gold->set_money(450);
move_object(gold,this_object());
}

init(){
	::init();
if(present("KnightInvite", this_player())){
  add_action("report","report");
  }
}

query_templar_guard(){ return 1; }
report(){
string wootoo;
switch(WAR->query_total_goblins()){
 case 9000..100000:
 wootoo = "around ten-thousand, far more than we first thought";
 break;
 case 7000..8999:
 wootoo = "about 7500 troops";
 break;
 case 5000..6999: 
 wootoo = "about 5500 or so, its hard to say exactly";
 break;
 case 3000..4999:
 wootoo = "under 5000 troops, we are getting closer";
 break;
 case 1000..2999:
 wootoo = "under 3000 troops, it won't be long now";
 break;
 case 1..999:
 wootoo = "under a thousand troops. They are on the ropes";
 break;
 }
   
write(
"The Templar Scout nods and reports,\n"+
"\"The goblins are currently based to the west through the mountain's\n"+
" pass. There are several means to reach their base camp, but I am\n"+
" unsure of which is the least dangerous so far. There scouts and\n"+
" patrols are just too thick at the moment.  Right now they number\n"+
" at "+wootoo+".\"\n"+
"He continues,\n"+
"\"Now, this total number isn't all in one place, so you should be\n"+
" able to avoid a majority of them, if you plan it right. Good luck,\n"+
" and god speed.\"\n");
return 1;
}  