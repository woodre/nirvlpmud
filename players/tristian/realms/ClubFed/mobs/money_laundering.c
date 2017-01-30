#include "/players/tristian/lib/ClubFeddefine.h"
inherit "/players/vertebraker/closed/std/monster.c";

id(str) { return (::id(str) || str == "con" || str == "convict" || str == "vito"); }

reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("Vito");
  set_alt_name("vito");
  set_race("human");
  set_alias("criminal");
  set_gender("male");
  set_short("Vito Scagnelli");
  set_long(
    " Vito is a black haired man in his mid 40's.  He is in for\n"+
    "laundering mob money.  He wanted to become a made man but\n"+
    "got arrested before he could. He is now a very angry man\n"+
    "because of this.\n\n"+
    HIR+"Money Laundering"+NORM+": The investment or transfer of money from\n"+
    "racketeering, drug transactions, or other embezzlement schemes so\n"+
    "that it appears that its original source either cannot be traced\n"+
    "or is legitimate.\n\n");
  set_level(20);
  set_ac(47+random(10));
  set_wc(27+random(10));
  set_hp((800)+random(100));
  set_al(-250);
  set_aggressive(0);
  set_chat_chance(5);
  load_chat(
    "Vito whines: 'I wanna be a made man.'\n");
  load_chat(
    "Vito says: 'I was so close, fugedabuitit'\n");
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