#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("strygalldwir");
set_alias("bird");
set_alt_name("stry");
set_race("creature");
set_short("Strygalldwir");
set_long("A creature well over six feet in height, with great branches\n"+
"of antlers growing out of its forehead.  Nude, its flesh\n"+
"is a uniform ash-gray in color.  It appears to be sexless,\n"+
"and it had gray, leathery wings extending far out behind\n"+
"it and joining with the night.  It held a short, heavy sword.\n");

set_level(10);
   set_hp(150);
   set_wc(14);
   set_ac(8);
   set_al(0);
   set_aggressive(0);
   set_dead_ob(this_object());
   
set_chat_chance(5);
load_chat("Stry says:  I will eat your heart out.\n");
load_chat("Stry asks:  Who are you?\n");
load_chat("Stry says:  Four times must I ask and four times be refused\n"+
"before I kill you.\n");
load_chat("Stry exclaims:  Tonight I will suck the marrow from your bones!\n");
  
   gold = clone_object("obj/money");
gold->set_money(450);
   move_object(gold,this_object());
}

monster_died() {
   tell_room(environment(this_object()),
"Stry collapse hard on the ground, it makes a loud SPAT sound.\n");
}