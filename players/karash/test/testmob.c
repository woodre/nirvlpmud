
inherit "/obj/monster.c";
#include <ansi.h>

reset(arg) {
  ::reset(arg);
  if(arg) return;
   
  set_name("mob");
  set_race("critter");

  set_short("A test mob");
  set_long(
    "  A test mob.\n"+
    "  A test mob.\n");
  set_al(0);

  set_level(27);
  set_hp(1900);
  set_wc(58);
  set_ac(27);
  set_wc_bonus(26);
  set_hp_bonus(600);


  set_gender("male");
  /*set_dead_ob(this_object());*/
  set_aggressive(0);
  set_chat_chance(0);
   load_chat("chat 1.\n");
   load_chat("chat 2.\n");
   load_chat("chat 3.\n");
   
   
  }
  
  
init() {
  ::init();

  tell_room(environment(), "INIT CHECK 1\n");

  write(present("GI", find_player("marsellus"))->query_sand_points()+"\n");
}

/*
heart_beat() {
    ::heart_beat();



}
*/