#include "/players/tristian/lib/ClubFeddefine.h"
inherit "/players/vertebraker/closed/std/monster.c";

id(str) { return (::id(str) || str == "con" || str == "convict" || str == "sal"); }

reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("Sal");
  set_alt_name("sal");
  set_race("human");
  set_alias("criminal");
  set_gender("male");
  set_short("Sal Goldstein");
  set_long(
    "Sal is an older gentleman, slightly overweight, with jowels that\n"+
    "make him look like a bulldog.  He is in for healthcare fraud.\n"+
    "He wanted the easy life of a doctor, but not the hassle of the\n"+
    "schooling that went along with it.  He got busted when he botched\n"+
    "a face lift.\n\n"+
    HIR+"Healthcare Fraud"+NORM+": Where an unlicensed health care provider provides services\n"+
    "under the guise of being licensed and obtains monetary benefit for the service.\n\n");
  set_level(20);
  set_ac(45+random(10));
  set_wc(25+random(10));
  set_hp((750)+random(100));
  set_al(-250);
  set_aggressive(1);
  set_chat_chance(10);
  load_chat(
    "Sal moans: 'I was a good doctor!! I coulda fixed it!'\n");
  load_chat(
    "Sal says: 'Damn my stupdity to hell!!'\n");
  set_death_emote(
    "\n\nAs #MN# dies, cigarettes fall out of #MP# pockets.\n");

  set_dead_ob(this_object());
  set_chance(40);
  set_spell_dam(40+random(20));

  set_spell_mess1(
    "\nThe convict pulls out a shank and " +HIY+"sticks"+NORM+" it into your "+BLINK+BRED+"side"+NORM+".\n");
  set_spell_mess2(
    "\nThe convict pulls out a shank and " +HIY+"sticks"+NORM+" it into your "+BLINK+BRED+"side"+NORM+".\n");
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