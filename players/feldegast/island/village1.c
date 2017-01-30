#include "/players/feldegast/defines.h"

inherit ROOM;

reset(arg) {
  object villager, sandals;
  string adj;
  int x;
  if (arg) return;
  set_light(1);
  short_desc="A jungle village";
  long_desc=
"     This is a village on the outskirts of the jungle.  A dirt\n"+
"path runs east and west through its center.  To the north and\n"+
"south are huts.  To the east you see a fountain.\n";
  items=({
    "huts","The huts in this village are made of strong yet\n"+
           "flexible bamboo.",
    "fountain","You can't make it out very well from here.",
    "jungle","The jungle doesn't look very dense here, but you\n"+
             "imagine it gets much more difficult beyond the\n"+
             "village."
  });
  dest_dir=({
    "/players/feldegast/island/hut1","north",
    "/players/feldegast/island/jungle_path","west",
    "/players/feldegast/island/village2","east",
    "/players/feldegast/island/hut2","south"
  });
  if(!present("messenger")) {
    villager=clone_object("/obj/monster");
    villager->set_name("messenger");
    villager->set_short("Messenger");
    villager->set_long(
"This is the village messenger.  It's his job to make sure everyone\n"+
"is informed of what goes on.\n"
    );
    villager->set_race("human");
    villager->set_level(4);
    villager->set_hp(60);
    villager->set_wc(9);
    villager->set_ac(4);
    villager->set_al(50);
    villager->add_money(50);
    sandals=clone_object("/obj/armor");
    sandals->set_short("A pair of sandals");
    sandals->set_name("sandals");
    sandals->set_long("A pair of good sandals made out of leather.\n");
    sandals->set_alias("sandal");
    sandals->set_ac(1);
        sandals->set_weight(1);
    sandals->set_type("boots");
    sandals->set_value(50);
    move_object(sandals,villager);
     move_object(villager,this_object());
  }
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
