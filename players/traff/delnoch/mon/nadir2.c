/*  NADIR2.C - Loads into WALL6.C part of Delnoch Town.
    One of 6 monsters that load into WALL6.C.  NADIR1.C and WAR1.C
    contain the chat strings that give the appearence of a raging
    battle surrounding the player.
    Changes as of 5-31-96:
    Color added.
*/
#include "/players/traff/closed/ansi.h"
inherit "obj/monster";

reset(arg) {
  object coins;
  ::reset(arg);
  if(arg) return;
    set_name("tribesman");
    set_race("human");
    set_alias("nadir");
    set_short(HIR+"Spear Tribesman"+NORM);
    set_long(YEL+
"From his weathered skin you think this Nadir has been around\n"+
"a while.  Lean and muscular he has no doubt fought many\n"+
"battles during the unification of the tribes.  That he\n"+
"has survived to be here attests to his skills.\n"+NORM);
    set_level(15+random(3));
    set_hp(325+random(100));
    set_al(-1000);
    set_wc(20+random(5));
    set_ac(12+random(3));
    set_chat_chance(5);
    set_a_chat_chance(10);
    load_chat("A Nadir looks at you, unsure if you are friend or foe.\n");
    load_a_chat("A Nadir with a long spear charges you.\n");
    coins=clone_object("obj/money");
    coins->set_money(random(101)+850);
    move_object(coins,this_object());
}
