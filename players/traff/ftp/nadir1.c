/*  NADIR1.C - Loads into WALL6.C part of Delnoch Town.
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
    set_name("nadir");
    set_race("human");
    set_alias("tribesman");
    set_short(HIR"Wolfshead tribesman"+NORM);
    set_long(HIY+
"A member of Ulrich's own tribe, this seasoned fighter bears the\n"+
"scars of many battles.  He is fearless and tough.  Like so\n"+
"many of the tribesmen, he is tall and lean with skin tanned dark\n"+
"by the sun.  He has gained much experience in his years of fighting,\n"+
"and is a tough and fearsome fighter.\n"+NORM);
    set_level(16+random(3));
    set_hp(350+random(100));
    set_al(-1000);
    set_wc(22+random(5));
    set_ac(13+random(3));
    set_chat_chance(20);
    set_a_chat_chance(20);
    load_chat("Warrior hits Nadir with a bone crushing sound.\n");
    load_chat("Warrior hit Nadir very hard.\n");
    load_chat("Warrior hits Nadir hard.\n");
    load_chat("Warrior tickles Nadir in the stomach.\n");
    load_chat("Warrior swings wildly at Nadir and misses.\n");
    load_chat("Nadir hits Warrior with a bone crushing sound.\n");
    load_chat("Nadir hit Warrior very hard.\n");
    load_chat("Nadir hits Warrior hard.\n");
    load_chat("Nadir tickles Warrior in the stomach.\n");
    load_chat("Nadir swings wildly at Warrior and misses.\n");
    load_chat("*CLANG*\nA mace bounces off a shield nearby.\n");
    load_chat("A young boy screams as his arm is severed by an axe.\n"+
       "He clutches the bloody stump and staggers to the back of the wall.\n");
    load_chat("A Nadir tribesman climbs over the wall and stands.  He\n"+
       "starts swinging his blade wildly to make room for his comrades.\n");
    load_chat("A Delnoch warrior uses a forked pole to push a ladder\n"+
       "away from the wall.  A dozen men scream as they fall.\n");
    load_chat("*THUNK*\nAn arrow lodges in the neck of a man next to you.\n");
    load_chat("A soldier who has been run through, grabs his attacker\n"+
       "in a bear hug, and they both topple from the wall.\n");
    load_chat("YIIIIIIIIEEEEEEEE!!\nAnother man plummets from the wall.\n");
    load_chat("-PLOP-  A head falls at your feet and rolls away.  You\n"+
       "look up and catch a glimpse of Druss, blood dripping from his axe.\n");
    load_a_chat("Warrior screams as he charges you.\n");
    load_a_chat("Warrior hits Nadir with a bone crushing sound.\n");
    load_a_chat("Warrior hit Nadir very hard.\n");
    load_a_chat("Warrior hits Nadir hard.\n");
    load_a_chat("Warrior tickles Nadir in the stomach.\n");
    load_a_chat("Warrior swings wildly at Nadir and misses.\n");
    load_a_chat("Nadir hits Warrior with a bone crushing sound.\n");
    load_a_chat("Nadir hit Warrior very hard.\n");
    load_a_chat("Nadir hits Warrior hard.\n");
    load_a_chat("Nadir tickles Warrior in the stomach.\n");
    load_a_chat("Nadir swings wildly at Warrior and misses.\n");
    load_a_chat("*CLANG*\nA mace bounces off a shield nearby.\n");
    load_a_chat("A young boy screams as his arm is severed by an axe.\n"+
       "He clutches the bloody stump and staggers to the back of the wall.\n");
    load_a_chat("A Nadir tribesman climbs over the wall and stands.  He\n"+
       "starts swinging his blade wildly to make room for his comrads.\n");
    load_a_chat("A Delnoch warrior uses a forked pole to push a ladder\n"+
       "away from the wall.  A dozen men scream as they fall.\n");
    load_a_chat("*THUNK*\nAn arrow lodges in the neck of a man next to you.\n");
    load_a_chat("A soldier who has been run through, grabs his attacker\n"+
       "in a bear hug, and they both topple from the wall.\n");
    load_a_chat("YIIIIIIIIEEEEEEEE!!\nAnother man plummets from the wall.\n");
    load_a_chat("-PLOP-  A head falls at your feet and rolls away.  You\n"+
       "look up and catch a glimpse of Druss, blood dripping from his axe.\n");
    coins=clone_object("obj/money");
    coins->set_money(random(101)+900);
    move_object(coins,this_object());
}
