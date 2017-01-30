#include "/players/tristian/lib/ClubFeddefine.h"
inherit "/players/vertebraker/closed/std/monster.c";

id(str) { return (::id(str) || str == "con" || str == "convict" || str == "marty"); }

reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("Marty");
  set_alt_name("marty");
  set_race("human");
  set_alias("criminal");
  set_gender("male");
  set_short("Marty Roe");
  set_long(
    "Marty is a typical middle aged manager, greying hair, and a belly that\n"+
    "is starting to bulge.  He is in for embezzling money from a former\n"+
    "employer. He made off with more than a half a million dollars but\n"+
    "got greedy and tried for more when he got popped.\n\n"+
    HIG+"Embezzlement"+NORM+": When a person who has been entrusted with money\n"+
    "or property appropriates it for his or her own use and benefit.\n\n");
  set_level(20);
  set_ac(45+random(10));
  set_wc(25+random(10));
  set_hp((800)+random(100));
  set_al(-250);
  set_aggressive(0);
  set_chat_chance(5);
  load_chat(
    "Marty whines: 'I am innocent, just like everyone in here.'\n");
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