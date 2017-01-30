#include "/players/mythos/closed/guild/def.h"

inherit "players/mythos/amon/forest/monster1";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("aizen");
  set_race("avatar");
  set_short("Aizen-Myoo");
  set_long("Here sits one of the buddist deities or avatars- Aizen-Myoo.\n"+
           "Great protector and suppressor of carnal lusts, he guards this \n"+
           "room.  The Hunter placed him here to protect ths tower.\n"+
           "The six arms of this avatar each holds a gem and the three\n"+
           "eyes see EVERYTHING.\n");
  set_hp(600);
  set_level(21);
  set_al(500);
  set_wc(30);
  set_ac(25);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_chat_chance(1);
  set_a_chat_chance(25);
  load_chat("Aizen watches you carefully.\n");
  load_chat("One of the avatar's arms twitches in anticipation.\n");
  load_a_chat("An arm flashes out and hits you!\n");
  load_a_chat("Aizen-Myoo glares at you.\n");
  set_mult(6);
  set_mult_chance(60);
  set_mult_dam1(20);
  set_mult_dam2(40);
  move_object(clone_object("/players/mythos/amisc/gem.c"),this_object());
  move_object(clone_object("/players/mythos/amisc/gem2.c"),this_object());
  move_object(clone_object("/players/mythos/amisc/gem3.c"),this_object());
  move_object(clone_object("/players/mythos/amisc/gem6.c"),this_object());
  move_object(clone_object("/players/mythos/amisc/gem5.c"),this_object());
  move_object(clone_object("/players/mythos/amisc/gem4.c"),this_object());
}

monster_died() {
  if(present(fear,this_object()->query_attack())) {
    present(fear,this_object()->query_attack())->set_bow(1);
    present(fear,this_object()->query_attack())->save_dark();
    command("uu",this_object()->query_attack());
    tell_object(this_object()->query_attack(),
      "You feel power flood you!\n"+
      "Sympathetic magic enters your blood!\n"+
      "To cast type <wound>\n");
  
/*
  write_file("/players/mythos/closed/guild/task_spell",
    ctime(time())+" "+(this_object()->query_attack())->query_real_name()+
    "  wound\n");}
*/
}
}
