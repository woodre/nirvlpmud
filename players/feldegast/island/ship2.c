#include "/players/feldegast/defines.h"
inherit ROOM;
reset(arg) {
  object pirate, weapon, armor;
  string adj, name, l, alt_name;
  int x, weight, value, class;
  if (arg) return;
  set_light(1);
  short_desc="A pirate ship";
  long_desc=
"You are aboard a pirate ship just off the shore of a small island.\n"+
"You are near the bow of the ship.  A gentle breeze cools you.  Below\n"+
"you is the entrance to the hold.\n";
  items=({
     "hold","You can't quite make out what's in the hold.  It's too dark.\n"
  });
  dest_dir=({
    "/players/feldegast/island/ship1","north",
    "/players/feldegast/island/ship3","south",
    "/players/feldegast/island/hold","down"
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
      pirate->set_gender("male");
      pirate->set_level(3);
      pirate->set_wc(7);
      pirate->set_ac(4);
      pirate->set_hp(50);
      pirate->set_al(-50);
      pirate->set_a_chat_chance(5);
      pirate->load_a_chat("Pirate says: Arrrhh!\n");
      pirate->load_a_chat("Pirate growls savagely.\n");
      pirate->add_money(10+random(30));
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
        case 2: name="a hook";
                l="A curved piece of metal with a sharp point.\n";
                class=6;
                value=30;
                weight=2;
                alt_name="hook";
                break;
      }
      weapon=clone_object("obj/weapon");
      weapon->set_name(name);
      weapon->set_class(class);
      weapon->set_value(value);
      weapon->set_weight(weight);
      weapon->set_alt_name(alt_name);
      transfer(weapon,pirate);
      transfer(weapon,pirate);
      move_object(pirate,this_object());
    }
    pirate=clone_object("obj/monster");
    pirate->set_name("pirate");
    pirate->set_alt_name("king");
    pirate->set_short("The Pirate King");
    pirate->set_long(
"This is the pirate king.  He's a middle-aged, slightly balding man\n"+
"who plundered his way up to this position in his youth.\n"
    );
    pirate->set_race("human");
    pirate->set_gender("male");
    pirate->set_level(7);
    pirate->set_wc(11);
    pirate->set_ac(6);
    pirate->set_hp(105);
    pirate->set_al(-50);
    pirate->set_chat_chance(5);
    pirate->load_chat(
"\nThe Pirate King sings: For I am the pirate king,\n"+
"                       and it 'tis, it 'tis a glorious thing,\n"+
"                       to be the pirate king!\n"
    );
    pirate->load_chat(
"\nThe Pirate King sings: Oh, better far to live and die\n"+
"                       Under the brave black flag I fly,\n"+
"                       Than play a hypocritical part,\n"+
"                       With a pirate head and a pirate heart!\n"
    );
    pirate->load_chat(
"\nThe Pirate King sings: Away to the world across the seas...\n"+
"                       Where pirates all have law degrees!\n"+
"                       But I'll be true to the sun I sing,\n"+
"                       And live and die a Pirate King!\n"
    );
    pirate->load_chat(
"\nThe Pirate King sings: When I venture forth to seek my prey,\n"+
"                       I crush my foes in a royal way.\n"+
"                       The ladies yield, and the ships go down.\n"+
"                       Or is it the other way around?\n"
    );
    pirate->load_chat(
"\nThe Pirate King sings: Many a king in a gilded tower,\n"+
"                       If he wants to climg to pomp and power,\n"+
"                       Must somehow manage, to get through,\n"+
"                       More dirty work than ever I do!\n"
    );
    pirate->add_money(50+random(50));
    weapon=clone_object("obj/weapon");
    weapon->set_name("A steel cutlass");
    weapon->set_long("A sharp, slightly curving sword with one edge.\n");
    weapon->set_class(14);
    weapon->set_value(200);
    weapon->set_weight(2);
    weapon->set_alt_name("cutlass");
    transfer(weapon,pirate);
    move_object(pirate,this_object());    
  }
}
init() {
  ::init();
  add_action("block","down");
}
block() {
  if(present("pirate")||present("king")) {
    write("A pirate prevents you from entering the hold.\n");
    return 1;
  }
}    
