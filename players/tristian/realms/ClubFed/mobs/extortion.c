#include "/players/tristian/lib/ClubFeddefine.h"
inherit "/players/vertebraker/closed/std/monster.c";

id(str) { return (::id(str) || str == "con" || str == "convict" || str == "jack"); }

reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("Jack");
  set_alt_name("Jack");
  set_race("human");
  set_alias("criminal");
  set_gender("male");
  set_short("Jack Spillane");
  set_long(
    "Jack was a contractor with big arms, a tan and plenty of tattoos.\n"+
    "He is in for extortion because he wanted to build a track\n"+
    "housing development and tried to scare off the current residents\n"+
    "of the properties by threatening to burn them out.\n\n"+
    HIR+"Extortion"+NORM+": Occurs when one person illegally obtains property\n"+
    "from another by actual or threatened force, fear, or violence,\n"+
    "or under cover of official right.\n\n");
  set_level(20);
  set_ac(47+random(10));
  set_wc(27+random(10));
  set_hp((800)+random(100));
  set_al(-250);
  set_aggressive(0);
  set_chat_chance(5);
  load_chat(
    "Jack moans: 'Damn Pigs!!'\n");
  load_chat(
    "Jack says: 'Stupid homeowners!! All they had to do was leave.'\n");
  set_death_emote(
    "\n\nAs #MN# dies, cigarettes fall out of #MP# pockets.\n");

  set_dead_ob(this_object());
  set_chance(40);
  set_spell_dam(40+random(20));

  set_spell_mess1(
    "\nThe convict pulls out a shiv and " +HIY+"plunges"+NORM+" it into your "+BLINK+BRED+"chest"+NORM+".\n");
  set_spell_mess2(
    "\nThe convict pulls out a shiv and " +HIY+"plunges"+NORM+" it into your "+BLINK+BRED+"chest"+NORM+".\n");
}

monster_died()
{
 int s;
   s=5;
   while(s--)
   move_object(clone_object(OBJ+"cig.c"));

  tell_room(environment(),
    "As the convict dies he drops his shiv.\n"+NORM);
  move_object(
    clone_object(OBJ+"shiv.c"),
    this_object());
}