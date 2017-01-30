inherit "/players/vertebraker/closed/std/monster.c";
#include "/players/tristian/lib/ClubFeddefine.h"
id(str) { return (::id(str) || str == "guard" ); }

reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("Prison Guard");
  set_alt_name("guard");
  set_race("human");
  set_alias("guard");
  set_gender("male");
  set_short("Prison Guard");
  set_long(
    "This is a run of the mill prison guard. He is wearing a uniform, and a\n"+
    "belt filled with the normal prison guard items, including a billy club,\n"+
    "mace, and handcuffs.\n\n");
  set_level(20);
  set_ac(50+random(10));
  set_wc(35+random(10));
  set_hp((1000)+random(100));
  set_al(-1);
  set_aggressive(0);
  set_chat_chance(20);
  load_chat(
    "The guard states:  'You're not getting out that easy.'\n");
  set_a_chat_chance(20);
  load_a_chat(
    "The guard cries for help and sprays you with pepper spray.\n");
  set_death_emote(
    "\n\nAs #MN# dies, the prison key falls out of #MP# pocket.\n");

  set_dead_ob(this_object());
  set_chance(40);
  set_spell_dam(40+random(20));

  set_spell_mess1(
    "\nThe guard pounds on you with his billy club.\n");
  set_spell_mess2(
    "\nThe guard pounds on you with his billy club.\n");
}

monster_died()
{
  move_object(clone_object(OBJ+"jailkey.c"));

  tell_room(environment(),
    "As the guard dies he drops his billy club.\n"+NORM);
  move_object(
    clone_object(OBJ+"billyclub.c"),
    this_object());
}
