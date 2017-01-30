#include "/players/feldegast/defines.h"

inherit ROOM;
int is_here;
reset(arg) {
  object villager;
  int x;
  string adj;
  is_here=1;
  if (arg) return;
  set_light(1);
  short_desc="A jungle village";
  long_desc=
"     This is a village on the outskirts of the jungle.  A dirt\n"+
"path runs east and west through its center.  To the north and\n"+
"south are huts.  A beautiful marble fountain is here.\n";
  items=({
    "huts","The huts in this village are made of strong yet\n"+
           "flexible bamboo",
    "fountain","A marble lion spits water into the fountain's basin",
    "lion","It appears to be crying a crystal tear.  You think you\n"+
           "could pry it loose if you wanted to",
    "jungle","The jungle doesn't look very dense here, but you\n"+
             "imagine it gets much more difficult beyond the\n"+
             "village"
  });
  dest_dir=({
    "/players/feldegast/island/hut3","north",
    "/players/feldegast/island/village1","west",
    "/players/feldegast/island/village3","east",
    "/players/feldegast/island/hut4","south"
  });
  if(!present("villager")) {
    while(x<3) {
      x++;
      switch(random(12)) {
        case 0: adj=" wary";break;
        case 1: adj=" happy";break;
        case 2: adj=" rugged";break;
        case 3: adj=" big";break;
        case 4: adj=" grimy";break;
        case 5: adj=" happy";break;
        case 6: adj=" bearded";break;
        case 7: adj=" bemused";break;
        case 8: adj=" relaxed";break;
        case 9: adj=" tense";break;
        case 10: adj=" handsome";break;
        case 11: adj=" strong";break;
        case 12: adj=" vain";break;
        default: adj=" stupid";break;
      }
      villager=clone_object("/obj/monster");
      villager->set_name("villager");
      villager->set_alias("native");
      villager->set_short("A"+adj+" villager");
      villager->set_long(
"This is a"+adj+" villager.  He wears a loincloth and his\n"+
"skin is decorated with an elaborate paint scheme.\n"
      );
      villager->set_race("human");
      villager->set_level(3);
      villager->set_wc(7);
      villager->set_ac(4);
      villager->set_hp(45);
      villager->set_al(50);
      villager->set_a_chat_chance(5);
      villager->load_a_chat("Villager asks: Why?\n");
      villager->load_a_chat("Villager yells for help.\n");
      villager->load_a_chat("Villager yells: Pirate!\n");
      villager->add_money(90+random(10));
      move_object(villager,this_object());
    }
  }
}
init() {
  ::init();
  add_action("pry","pry");
}
pry(str) {
  object tear;
  if(!str) {
    write("Pry what?\n");
    return 1;
  }
  if(str=="tear" || str=="crystal") {
    if(!is_here) {
      write("The crystal tear is gone!\n");
      return 1;
    }
    write("You pry the crystal tear from the lion statue.\n");
    is_here=0;   
    tear=clone_object("/obj/treasure");
    tear->set_short(HIW+"A lion's tear"+NORM);
    tear->set_long("This is a glittering crystal tear that you got\n"+
                   "from the marble lion.\n");
    tear->set_id("marble_lion_tear");
    tear->set_alias("tear");
    tear->set_value(10);
    tear->set_weight(0);
    tear->set_dest_flag(1);
    move_object(tear,this_player());
    return 1;
  }
  write("Pry what?\n");
  return 1;
}

