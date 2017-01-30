inherit "/players/vertebraker/closed/std/monster.c";
#include "/players/tristian/lib/ClubFeddefine.h"
id(str) { return (::id(str) || str == "con" || str == "convict" || str == "showering con"); }

reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("a showering convict");
  set_alt_name("convict");
  set_race("human");
  set_alias("guard");
  set_gender("male");
  set_short("A Showering Convict");
  set_long(
    "This is your average convict who is taking a shower. He is nervous\n"+
    "about having company in the shower with him.\n");
  set_level(20);
  set_ac(45+random(10));
  set_wc(25+random(10));
  set_hp((750)+random(100));
  set_al(-1);
  set_aggressive(1);
  set_chat_chance(20);
  load_chat(
    "The con cries, 'Quit looking at my ass!!! I don't go that way!!!'\n");
  load_chat(
    "The con drops the soap.\n");
  set_death_emote(
    "\n\nAfter #MN# dies, you search #MP# clothes.\n");

  set_dead_ob(this_object());
  set_chance(40);
  set_spell_dam(40+random(20));

  set_spell_mess1(
    "\nThe con throws the soap at you.\n");
  set_spell_mess2(
    "\nThe con throws the soap at you.\n");
}

monster_died()
{
 int s;
   s=5;
   while(s--)
   move_object(clone_object(OBJ+"cig.c"));

  tell_room(environment(),
    "As the convict dies he drops the soap.\n"+NORM);
  move_object(
    clone_object(OBJ+"soap.c"),
    this_object());
}