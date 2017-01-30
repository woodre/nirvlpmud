#include "/players/tristian/lib/ClubFeddefine.h"
inherit "/players/vertebraker/closed/std/monster.c";

id(str) { return (::id(str) || str == "con" || str == "convict" || str == "billy"); }

reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("Billy");
  set_alt_name("bill");
  set_race("human");
  set_alias("criminal");
  set_gender("male");
  set_short("Billy Jones");
  set_long(
    "Billy was a young stockbroker in his 20's with a promising career\n"+
    "ahead of him.  He was making millions from inside knowledge on a hot\n"+
    "internet stock, until the Federal Trade Commission got wind of it and\n"+
    "crawled inside every one of his business dealings.\n\n"+
    HIR+"Insider Trading"+NORM+": When a person uses inside, confidential,\n"+
    "or advance information to trade in shares of publicly held corporations.\n\n");
  set_level(20);
  set_ac(47+random(10));
  set_wc(27+random(10));
  set_hp((800)+random(100));
  set_al(-250);
  set_aggressive(0);
  set_chat_chance(5);
  load_chat(
    "Billy moans: 'The Deal, its all about THE DEAL!!'\n");
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