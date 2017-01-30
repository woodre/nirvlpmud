#include "/players/tristian/lib/ClubFeddefine.h"
inherit "/players/vertebraker/closed/std/monster.c";

id(str) { return (::id(str) || str == "con" || str == "convict" || str == "calvin"); }

reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("Calvin");
  set_alt_name("calvin");
  set_race("human");
  set_alias("criminal");
  set_gender("male");
  set_short("Calvin Jackson");
  set_long(
    "Calvin is a black man, with round glasses and perfect white teeth.\n"+
    "He is in for forging documents in a real estate scam.  He got\n"+
    "picked off because he tried to pass false deeds to an undercover FBI agent.\n\n"+
    HIY+"Forgery"+NORM+": When a person passes a false or\n"+
    "worthless instrument such as a check or counterfeit\n"+
    "security with the intent to defraud or injure the recipient.\n\n");
  set_level(20);
  set_ac(45+random(10));
  set_wc(25+random(10));
  set_hp((800)+random(100));
  set_al(-250);
  set_aggressive(0);
  set_chat_chance(5);
  load_chat(
    "Calvin whines: 'I am innocent!! Ask anyone in here.'\n");
  load_chat(
    "Calvin says: 'I can do this time standing on my head.'\n");
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