#include "/players/tristian/lib/ClubFeddefine.h"
inherit "/players/vertebraker/closed/std/monster.c";

id(str) { return (::id(str) || str == "con" || str == "convict" || str == "johnny"); }

reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("Johnny");
  set_alt_name("john");
  set_race("human");
  set_alias("criminal");
  set_gender("male");
  set_short("Johnny Santilli");
  set_long(
    " Johnny is an older man who worked for the city for almost 20 years\n"+
    "until he got busted for getting kickbacks from the mob. He was\n"+
    "the local building official and for greasing the skids on mob run\n"+
    "projects, he was making a six figure income.\n\n"+
    HIR+"Kickbacks"+NORM+": Occurs when a person who sells an item pays\n"+
    "back a portion of the purchase price to the buyer.\n\n");
  set_level(20);
  set_ac(47+random(10));
  set_wc(27+random(10));
  set_hp((800)+random(100));
  set_al(-250);
  set_aggressive(0);
  set_chat_chance(5);
  load_chat(
    "Johnny states: 'It wasn't illegal. They would have gotten them passed anyways.'\n");
  load_chat(
    "Johnny cries: 'Why me God? Why me?'\n");
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