inherit "room/room";

void
reset(status arg) {
  object whip;

  if (!present("whip", this_object())) {
    whip = clone_object("obj/weapon");
    whip->set_name("whip");
    whip->set_short("A whip");
    whip->set_long("A leather whip.  It has been stained black from dried "+
                   "blood.\n");
    whip->set_class(6);
    whip->set_weight(1);
    whip->set_value(15);
    move_object(whip, this_object());
  }
  if (arg)
    return;
  set_light(1);
  short_desc = "Torture chamber";
  long_desc = 
"This is the torture chamber of the castle.  Around the walls\n" +
"hang various tools for inflicting as much pain as possible to\n" +
"the victims.  Their screams still seem to linger in the air.\n";
  dest_dir = ({
    "players/angmar/castle/downstairs", "north",
  });
  items = ({
    "chamber", "The chamber has a thin coating of blood on the floor",
    "tools", "Standard torture tools.  You shudder as you move near them",
    "screams", "They echo in your ear, though you know them to be false",
  });
}

void
init() {
  room::init();
  add_action("listen", "listen");
}

status
listen() {
  write("You perk up your ears.  You can almost hear someone screaming in "+
        "pain.\n");
  return 1;
}
