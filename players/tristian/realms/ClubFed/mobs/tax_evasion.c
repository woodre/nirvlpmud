#include "/players/tristian/lib/ClubFeddefine.h"
inherit "/players/vertebraker/closed/std/monster.c";

id(str) { return (::id(str) || str == "con" || str == "convict" || str == "jimmy"); }

reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("Jimmy");
  set_alt_name("jim");
  set_race("human");
  set_alias("criminal");
  set_gender("male");
  set_short("Jimmy Tedeschi");
  set_long(
    "Jimmy is in his mid 50's, with bright smart eyes and a balding head.\n"+
    "He is in for tax evasion. He took it to the next level, however,\n"+
    "not by not filing, but by filing bogus returns in his name and others\n"+
    "to collect all the refunds.\n\n"+
    HIR+"Tax Evasion"+NORM+": When a person commits fraud in filing or paying taxes.\n");
  set_level(20);
  set_ac(47+random(10));
  set_wc(27+random(10));
  set_hp((800)+random(100));
  set_al(-250);
  set_aggressive(0);
  set_chat_chance(5);
  load_chat(
    "Jimmy states: 'Like the government needs the money like I do.'\n");
  load_chat(
    "Jimmy cries: 'Why me God? Why me?'\n");
  set_death_emote(
    "\n\nAs #MN# dies, cigarettes fall out of #MP# pockets.\n");

  set_dead_ob(this_object());
  set_chance(40);
  set_spell_dam(40+random(20));

  set_spell_mess1(
    "\nThe convict pulls out a shank and " +HIG+"plunges"+NORM+" it into your "+HIR+"heart"+NORM+".\n");
  set_spell_mess2(
    "\nThe convict pulls out a shank and " +HIG+"plunges"+NORM+" it into your "+HIR+"heart"+NORM+".\n");
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
