#pragma strong_types

inherit "room/room";

void
reset(status arg) {

  if(!present("eagle", this_object())){
    object ruby,eagle;
    eagle = clone_object("obj/monster");
    eagle->set_name("eagle");
    eagle->set_level(9);
    eagle->set_hp(100);
    eagle->set_wc(10);
    eagle->set_short("An eagle");
    eagle->set_long(
      "The eagle glares at you. He doesn't want to be disturbed.\n");
    eagle->set_al(50);
    ruby = clone_object("obj/treasure");
    ruby->set_id("ruby");
    ruby->set_short("A small ruby");
    ruby->set_value(100);
    move_object(ruby, eagle);
    move_object(eagle, this_object());
  }
  if (arg)
    return;
  set_light(1);
  short_desc = "Eagle's nest";
  long_desc = 
"You are on the top of Misty Mountain.  It's very cold up here, although\n" +
"the view of the fairyland below is terrific.  There is a nest here.\n";
  dest_dir = ({
    "players/angmar/fairyland/mountain", "down",
  });
  items = ({
    "nest", "The home of a few eaglets, which are mysteriously missing",
    "fairyland", "The expanse of land beneath you stretches out to the horizon",
    "mountain", "The mountain stretches below you.  You can see a ledge and a door",
    "door", "You cannot tell if the door is open or closed",
    "ledge", "There is an indistinguishable figure on the ledge",
    "figure", "You can't make out the details.  The figure is too far away",
  });
}

string realm() { return ("fairyland"); }
