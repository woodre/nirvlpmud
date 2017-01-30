#pragma strong_types

inherit "room/room";

void
reset(string arg) {
  object mushroom, elf, we;

  if (!present("slimy mushroom")) {
    mushroom = clone_object("obj/treasure");
    mushroom->set_name("mushroom");
    mushroom->set_short("A slimy mushroom");
    mushroom->set_long("Yuck! Disgusting!\n");
    mushroom->set_value(5);
    mushroom->set_alias("slimy mushroom");
    move_object(mushroom,this_object());
  }
  if (!present("elf")) {
    elf = clone_object("players/angmar/castle/elf");
    elf->set_gender("male");
    we = clone_object("obj/weapon");
    we->set_name("knife");
    we->set_short("Big knife");
    we->set_class(9);
    we->set_value(25);
    we->set_weight(1);
    move_object(we, elf);
    move_object(elf, this_object());
    elf = clone_object("players/angmar/castle/elf");
    elf->set_gender("male");
    we = clone_object("obj/weapon");
    we->set_name("sword");
    we->set_short("Small sword");
    we->set_class(11);
    we->set_value(40);
    we->set_weight(2);
    move_object(we, elf);
    move_object(elf, this_object());
  }
  if (arg)
    return;
  set_light(1);
  short_desc = "The beech woods";
  long_desc = 
"You are in the beech woods. The air feels warm, and the birds are\n"+
"singing. You feel very happy.\n";
  dest_dir = ({
    "players/angmar/fairyland/beech1","east",
    "players/angmar/fairyland/edge2","north",
  });
  items = ({
    "woods", "The woods consist of a huge number of beech trees",
    "trees", "Beech trees, which have been here for years",
    "beech trees", "Beech trees, which have been here for years",
    "birds", "All types and varieties, singing and flying around",
    "air", "The sun has warmed up the area",
  });
}

string realm() { return ("fairyland"); }

void
init(){
  room::init();
  add_action("climb", "climb");
  add_action("listen", "listen");
}

status
climb(string str) {
  if (!str)
    return 0;
  if (str == "tree" || str == "trees") {
    write("You try, but cannot reach the branches of the beech tree.\n");
    say(this_player()->query_name() + " tries, but cannot reach the branches.\n");
    return 1;
  }
  return 0;
}

status
listen(string str) {
  if (!str)
    return 0;
  if (str == "birds" || str == "to birds" || str == "birdsong") {
    write("The birds sound happy to be here.\n");
    say(this_player()->query_name() + " listens to the birds.\n");
    return 1;
  }
  return 0;
}
