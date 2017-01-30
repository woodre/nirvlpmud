/************************************************
| Adam Pierson- actually Methos, the oldest known living immortal
| a bit different from the other mobs in that he will
| escape by jumping out the window.
***********************************/
inherit "players/illarion/high/mon/imm_mon";
#include "/players/illarion/dfns.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("Adam Pierson");
  set_short("A dark-haired man with an amused look");
  set_long(
"Not too tall, not too muscled, not too obvious...  this man is almost\n"+
"perfectly average, although his gaze betrays a large, sly intellect.\n"+
"He wears slacks and a pull-over sweater as if he has worn something\n"+
"similar all his life, and looks quite at home here.\n");
  set_level(18);
  set_race("immortal");
  set_weapon_path(HOBJ+"psword");
  set_gender("male");
  set_hp(2000);
  set_wc(35);
  set_attacks(3);
  set_x_attack_chance(60);
  set_ac(20);
  set_al(-200);
  set_chat_chance(7);
  load_chat("The man's eyes twinkle in some private amusement.\n");
  load_chat("Suddenly, you feel judged and found a bit wanting.\n");
  load_chat("The man gets a beer from the fridge.\n");
  set_a_chat_chance(7);
  load_a_chat("Pierson says, \"I've told you, I want to LIVE!\"\n");
  load_a_chat("The man's eyes guage you and the room carefully.\n");
  load_a_chat("The man eyes the window with a glint in his gaze.\n");
  set_chance(10);
  set_spell_mess1("A frying pan hits you in the face.\n");
  set_spell_mess2("Pierson snatches up a frying pan and swings it.\n");
  set_spell_dam(20);
  set_dead_ob(this_object());
}
id(string str) { return ::id(str) || str == "adam" || str == "man"; }
monster_died() {
  tell_room(environment(this_object()),
    "As you strike the killing blow, Pierson staggers over to the window\n"+
    "and throws himself out, leaving his weapon behind.\n");
  /* changes the description of the window he crashes through */
  environment(this_object())->break_window();
  destruct(present("corpse",environment(this_object())));
  return 1;
}
