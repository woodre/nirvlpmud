/*
 kitchen.c
*/
 
inherit "room/room";

int pump_count;
string str, str2;
 
object glass_obj;
 
init() {
  ::init();

  add_action("pump", "pump");
  add_action("sniff", "sniff");
}
 
pump(str) {
  if (str != "handle" && str != "water") return;
  if (pump_count >= 2) {
    say(call_other(this_player(), "query_name") + " pumps the handle.\n");
    write("You pump the handle up, then down.\n");
    write("Klick! You hear a soft click from the room to the east.\n");
    call_other("players/nooneelse/red/pantry", "open_the_door", 0);
    glass_obj=0;
    glass_obj=present("glass");
    if (glass_obj) {
      glass_obj->set_glass_full(1);
      write("The glass is full of water.\n");
    }
    else {
      write("Water splashes all over the counter.\n");
    }
    return 1;
  }
  pump_count = pump_count + 1;
  say(call_other(this_player(), "query_name") + " pumps the handle.\n");
  write("Ok.\n");
  write("You pump the handle up, then down.\n");
  if (pump_count == 2) {
    glass_obj=0;
    glass_obj=present("glass");
    if (glass_obj) {
      glass_obj->set_glass_full(1);
      write("Water pours into the glass.\n");
      return 1;
    }
    else {
      write("Water splashes all over the counter.\n");
      return 1;
    }
  }
  return 1;
}
 
sniff() {
  write("Yech!  That's a disgusting smell!\n");
  command("puke", this_player());
  return 1;
}

reset(arg) {
  if (arg) return;

  pump_count=0;
  set_light(1);
  no_castle_flag=1;
  short_desc = "kitchen";
  long_desc =
    "This is the kitchen of this fine manor.  It is equipped with\n"+
    "the finest in stoves, kettles, fireplaces and even an iceroom.\n"+
    "A faint smell of garbage permeates the air however, and the\n"+
    "copper kettles on the counter seem to be somewhat tarnished.\n"+
    "Under the window, fixed to the counter, is a water pump.\n";
  items =
    ({
      "stoves", "Old, dirty stoves for cooking large meals.",
      "stove", "An old, dirty stove for cooking large meals.",
      "kettles", "Crusty, dirty kettles of various sizes.",
      "kettle", "A crusty, dirty kettle.",
      "fireplaces", "Two large fireplaces with spits in them.",
      "fireplace", "A large fireplace with a spit in it.",
      "spits", "Large, dirty racks for turning meat while cooking.",
      "spit", "A large, dirty rack for turning meat while cooking.",
      "iceroom", "A small room with bits of dried food stuck to the floor.\n"+
                 "The entrance is choked with debris.  You cannot enter.",
      "food", "Dry, useless lumps of once frozen food.",
      "pump", "A hand operated water pump, that looks operable.",
      "counter", "A scarred, dirty counter used in the preparation of food.",
      "window", "This is a dirty window that has been nailed shut.",
  });
  dest_dir =
    ({
      "players/nooneelse/red/ballroom", "south",
      "players/nooneelse/red/pantry", "east",
      "players/nooneelse/red/dining", "southeast",
    });
  if (!present("glass")) {
    glass_obj=clone_object("players/nooneelse/obj/glass");
    glass_obj->set_glass_full(0);
    move_object(glass_obj, this_object());
  }
  return;
}

set_pump_count(arg) {pump_count=arg;}

query_pump() {return pump_count;}

look_out_window() {
  write("You can't see through the window, but you can tell: ");
  command("look at sky", this_player());
  return 1;
}

id(str) {
  str2=0;
  if (str) sscanf(str,"at %s", str2);
  if (str=="window" || str2=="window") {
    look_out_window();
    return 1;
  }
  return (str=="stoves" || str=="stove" ||
          str=="kettles" || str=="kettle" ||
          str=="fireplaces" || str=="fireplace" ||
          str=="spits" || str=="spit" ||
          str=="iceroom" ||
          str=="food" ||
          str=="pump" ||
          str=="counter");
}
