/*  WAR2.C - Loads into WALL6.C part of Delnoch Town.
    One of 6 monsters that load into WALL6.C.  NADIR1.C and WAR1.C
    contain the chat strings that give the appearence of a raging
    battle surrounding the player.
    Changes as of 5-31-96:
    Color added.
*/
#include "/players/traff/closed/ansi.h"
inherit "obj/monster";

reset(arg)
{
  object coins;
  ::reset(arg);
  if(arg) return;
    set_name("warrior");
    set_race("human");
    set_alias("soldier");
    set_short(HIB+"Experienced warrior"+NORM);
    set_long(CYN+
"A professional soldier, this middle aged warrior is in good\n"+
"shape.  Medium height with brown hair and a distinctive\n"+
"scar on his cheek, he has helped train most of the men\n"+
"fighting here.  He is tough!  Fair to his troops, but\n"+
"ruthless to his enemies.\n"+NORM);
    set_level(15+random(3));
    set_hp(325+random(100));
    set_al(1000);
    set_wc(20+random(5));
    set_ac(12+random(3));
    set_chat_chance(5);
    set_a_chat_chance(10);
    load_chat("A warrior looks at you, unsure if you are friend or foe.\n");
    load_a_chat("Warrior screams as he charges you.\n");
    coins=clone_object("obj/money");
    coins->set_money(random(101)+850);
    move_object(coins,this_object());
}
