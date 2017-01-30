#include "/players/tristian/lib/ClubFeddefine.h"
inherit "/players/vertebraker/closed/std/monster.c";

id(str) { return (::id(str) || str == "con" || str == "convict" || str == "dante"); }

reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("Dante");
  set_race("human");
  set_alias("criminal");
  set_gender("male");
  set_short("Dante Simmons");
  set_long(
    "Dante is in his early 30's, with shifty eyes and close cropped blond hair.\n"+
    "He is in for cell phone fraud. He was selling usage of cell phones for\n"+
    "overseas calls and then pocketing the money charged for the usage.\n\n"+

    HIR+"Cellular Phone Fraud"+NORM+": The unauthorized use, tampering, or manipulation of a cellular\n"+
    "phone or service.  This can be accomplished by either use of a stolen phone or where an actor signs\n"+
    "up for service under false identification or where the actor clones a valid electronic serial number\n"+
    "(ESN) by using an ESN reader and reprograms another cellular phone with a valid ESN number.\n");
  set_level(20);
  set_ac(45+random(10));
  set_wc(30+random(10));
  set_hp((800)+random(200));
  set_al(-250);
  set_aggressive(0);
  set_chat_chance(5);
  load_chat(
    "Dante states: 'I was only trying to make a living.'\n");
  load_chat(
    "Dante cries: 'Why me God? Why me?'\n");
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