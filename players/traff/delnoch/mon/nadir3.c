/*  NADIR3.C - Loads into WALL6.C part of Delnoch Town.
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
    set_short(HIR+"Monkey Tribesman"+NORM);
    set_long(YEL+
"A fierce looking member of the Monkey tribe.  He is not too\n"+
"tall and has coal black hair.  It looks as if this might\n"+
"be his first real battle.  Be careful though, the nadir\n"+
"are raised as trained fighters.\n"+NORM);
    set_level(14+random(3));
    set_hp(200+random(200));
    set_al(-1000);
    set_wc(18+random(5));
    set_ac(11+random(3));
    set_chat_chance(5);
    set_a_chat_chance(10);
    load_chat("A Nadir looks at you, unsure if you are friend or foe.\n");
    load_a_chat("A Nadir screeches like a monkey as he charges you.\n");
    coins=clone_object("obj/money");
    coins->set_money(random(101)+750);
    move_object(coins,this_object());
}
