#include "/players/feldegast/defines.h"
inherit ROOM;
  object pirate,weapon,shovel;
  static opened;
  string adj, name, l, alt_name;
  int x,weight,value,class;
reset(arg) {
  object pirate;
  opened=0;
  if(!present("pirate")) {
    while(x<4) {
      x++;
      switch(random(7)) {
        case 0: adj=" burly";break;
        case 1: adj=" one-eyed";break;
        case 2: adj=" rugged";break;
        case 3: adj=" dirty";break;
        case 4: adj=" grimy";break;
        case 5: adj="n ugly";break;
        case 6: adj=" bearded";break;
        case 7: adj=" peg-legged";break;
        default: adj=" stupid";break;
      }
      pirate=clone_object("/obj/monster");
      pirate->set_name("pirate");
      pirate->set_short("A"+adj+" pirate");
      pirate->set_long(
"This is a"+adj+" pirate.  He doesn't look friendly.\n"
      );
      pirate->set_race("human");
      pirate->set_level(2);
      pirate->set_wc(6+random(1));
      pirate->set_ac(3);
      pirate->set_hp(30);
      pirate->set_al(-50);
      pirate->set_a_chat_chance(5);
      pirate->load_a_chat("Pirate says: Arrrhh!\n");
      pirate->load_a_chat("Pirate growls savagely.\n");
      pirate->add_money(30+random(30));
      switch(random(2)) {
        case 0: name="a belaying pin";
                l="A pin that is used on ships to hold ropes.\n";
                class=5;
                value=15;
                weight=1;
                alt_name="pin";
                break;
        case 1: name="a knife";
                l="A big knife.\n";
                class=6;
                value=25;
                weight=1;
                alt_name="knife";
                break;
        case 2: name="a cutlass";
                l="A sharp, slightly curving sword with one sharp edge.\n";
                class=9;
                value=75;
                weight=2;
                alt_name="cutlass";
                break;
      }
      weapon=clone_object("obj/weapon");
      weapon->set_name(name);
      weapon->set_class(class);
      weapon->set_value(value);
      weapon->set_weight(weight);
      weapon->set_alt_name(alt_name);
      transfer(weapon,pirate);
      move_object(pirate,this_object());
    }
  }

  if (arg) return;
  set_light(0);
  short_desc="The Ship's Hold";
  long_desc=
"     This is the deep, dank hold of a pirate ship.  At the moment,\n"+
"the hold is almost entirely empty except for a single crate in the\n"+
"corner.  A rope ladder leads back up to the deck.\n";
  items=({
    "crate","A wooden box.  You think you could open it"
  });
  dest_dir=({
    "/players/feldegast/island/ship2","up"
  });
}
init() {
  ::init();
  add_action("open","open");
}
open(str) {
  if(!str) {
     write("Open ");
     return 0;
  }
  if(!str=="crate") {
    write("Open ");
    return 0;
  }
  if(opened) {
    write("Somebody already opened it and took all the stuff.\n");
    return 1;
  }
  if(present("pirate")) {
    write("A pirate stops you from opening the crate.\n");
    return 1;
  }
  write("You open the crate and spread its contents on the floor.\n");
  shovel=clone_object("obj/treasure");
  shovel->set_short("A shovel");
  shovel->set_id("feld-shovel");
  shovel->set_alias("shovel");
  shovel->set_value(20);
  shovel->set_long("An old shovel.\n");
  shovel->set_weight(1);
  move_object(shovel,this_object());
  opened=1;
  return 1;
}
