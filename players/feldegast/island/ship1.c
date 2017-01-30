#include "/players/feldegast/defines.h"
inherit ROOM;
reset(arg) {
  object pirate, weapon;
  string adj, name, l, alt_name;
  int x, weight, value, class;
  if (arg) return;
  set_light(1);
  short_desc="A pirate ship";
  long_desc=
"You are aboard a pirate ship just off the shore of a small island.\n"+
"To the north is the captain's cabin.  To the east is a launch that\n"+
"you can take back to shore.  Above you is the crow's nest.\n";
  items=({
    "launch","A small boat with a pair of oars.  You think you could\n"+
             "sail it yourself.",
    "ship","A sleak, fast vessel bristling with cannons.  Perfect for piracy.\n"
  });
  dest_dir=({
    "/players/feldegast/island/cabin","north",
    "/players/feldegast/island/beach2","shore",
    "/players/feldegast/island/ship2","south",
    "/players/feldegast/island/crow_nest","up"
  });
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
      pirate->set_wc(6);
      pirate->set_ac(4);
      pirate->set_hp(50);
      pirate->set_al(-50);
      pirate->set_a_chat_chance(5);
      pirate->load_a_chat("Pirate says: Arrrhh!\n");
      pirate->load_a_chat("Pirate growls savagely.\n");
      pirate->add_money(30+random(50));
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
}
init() {
  ::init();
  add_action("block","south");
  add_action("block","north");
}
block() {
  if(present("pirate")) {
    write("A pirate blocks your way.\n");
    return 1;
  }
}    
