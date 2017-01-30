inherit "obj/monster.c";
#include "/players/linus/def.h"
  id(str) { return str=="bee" || str=="honey bee"; }
  reset(arg)  {
    ::reset(arg);
    if(arg) return; 
  set_aggressive(0);
  set_level(5);
  set_wc(9);
  set_ac(5);
  set_name("bee");
  switch(random(15)){
    case 0..5: b1(); break;
    case 6..10: b2(); break;
    case 11..15: b3(); break;
    default: b1(); break;
    }
  }
  b1(){
  set_short("A small "+YEL+"honey"+NORM+" bee");
  set_long(
  " The bee flies about in search of honey.  The beating of his wings\n"+
  "make a buzzing sound.  Small sacks of honey hang from his legs.\n");
  set_chat_chance(5);
    load_chat("The bee lands on a small flower.\n");
  set_a_chat_chance(20);
    load_a_chat("The bee stings you! OUCH!\n");
  set_dead_ob(this_object());
  }
  b2(){
  set_short("a large "+YEL+"honey"+NORM+" bee");
  set_long(
  " The bee flies around, hopping from flower to flower.  Its strong\n"+
  "wings make a loud buzzing sound.\n");
  set_chat_chance(5);
    load_chat("The bee flies past your ear.\n");
  set_a_chat_chance(20);
    load_a_chat("The bee stings you, leaving a small "+HIR+"mark"+NORM+".\n");
  set_dead_ob(this_object());
  }
  b3(){
  set_short("A "+YEL+"honey"+NORM+" bee");
  set_long(
  "  The bee flies around, in search of flowers.  Small sacks of honey\n"+
  "hang from his legs, and a small stinger protrudes from his backside.\n");
  set_dead_ob(this_object());
  }
  monster_died() {
   object corpse;
     corpse = present("corpse", environment(this_object()));
   tell_room(environment(TO),"As the bee hits the ground, his stinger is knocked off.\n");
     move_object(clone_object("/players/linus/Newbie/obj/stinger.c"),
  environment(this_object()));
  return 1;
  }
