#include "/players/pestilence/ansi.h"
inherit "/players/vertebraker/closed/std/monster";
#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
#define attacker attacker_ob
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Austin");
  set_alt_name("austin");
  set_alias("austin dailey");
  set_short("Austin Dailey");
  set_long("Austin is a small child around two years old.  He has light brown\n"+
           "hair.  He doesn't look scared but he's still hiding.  Austin is\n"+
           "holding a small teddy bear tightly to his body.\n");
  set_race("human");
  set_gender("male");
  set_level(11);
  set_wc(15);
  set_ac(8+random(3));
  set_hp(165);
  set_heal(2,12);
  add_money(0);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_al(0);
  load_chat("Austin says: i went poopie daddy.\n");
  load_chat("Austin says: can i play with the ants?\n");
  set_chat_chance(15);
  load_a_chat("Austin starts to cry.\n");
  load_a_chat("Austin kicks you in the shin.\n");
  set_a_chat_chance(25);
  set_spell_mess2("Austin throws a shoe at you, striking you in the arm.\n");
  set_spell_mess1("Austin throws a shoe at his attacker.\n");
  set_chance(30);
  set_spell_dam(5+random(5));
}

monster_died() {
  move_object(clone_object("/players/pestilence/amity/obj/bear.c"),
      environment(this_object()));
  tell_room(environment(this_object()),
        "As Austin hits the floor, his teddy bear falls from his grasp.\n");
return 0; }
