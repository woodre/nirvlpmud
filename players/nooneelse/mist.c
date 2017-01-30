/*
 mist.c
*/

inherit "room/room";

string str;

int cross_is_gone;

object cross, drop_item;

init() {
  ::init();

  add_action("search", "search");
  add_action("drop_something", "drop");
}

search(str) {
  if (str && str != "mist") return;
  write("You grope around blindly in the mist.\n");
  say(this_player()->query_name()+" gropes around blindly in the mist.\n");
  if (20 >= random(100) && !present("treasure map", this_player())) {
    write("You find something and pick it up!\n");
    say(this_player()->query_name()+" found a map!\n");
    drop_item=clone_object("/players/nooneelse/obj/treasure_map");
    drop_item->set_short("A map");
    drop_item->set_long("A treasure map!  Most of the drawings on the\n"+
                        "map are faded, but at the bottom, it says:\n\n"+
                        "Find the fork, but remember, when it's gone\n"+
                        "there may still be more to be dug up.\n");
    drop_item->set_destination("/players/nooneelse/greenentry");
    drop_item->set_treasure_name("sapphire");
    drop_item->set_treasure_alias_name("star sapphire");
    drop_item->set_treasure_short("A blue sapphire");
    drop_item->set_treasure_long("A valuable blue star sapphire.\n");
    drop_item->set_treasure_value(500);
    drop_item->set_treasure_weight(2);
    move_object(drop_item, this_player());
    return 1;
  }
  if (cross_is_gone) return 1;
  if (present("cross", this_player())) return 1;
  if (20 >= random(100)) {
    write("You find something and pick it up!\n");
    say(this_player()->query_name()+" found a silver cross!\n");
    cross=clone_object("obj/treasure");
    cross->set_id("cross");
    cross->set_alias("holy item");
    cross->set_short("a little cross");
    cross->set_long("This is a beautiful little silver cross with "+
                    "ancient holy symbols etched in it.\n");
    cross->set_value(50);
    cross->set_weight(1);
    move_object(cross, this_player());
    cross_is_gone=1;
    return 1;
  }
  return 1;
}

drop_something(str) {
  if (!str) return;
  if (str == "all") {
    write("Are you crazy?  You'll lose it all!\n");
    return 1;
  }
  drop_item=present(str,this_player());
  if(!drop_item) {
    write("You don't have one of those.\n");
    return 1;
  }
  if(drop_item->drop() || !drop_item->short()) {
    write("You can't drop that!\n");
    return 1;
  }
  destruct(drop_item);
  write("The "+str+" drops into the mist and disappears.\n");
  say("The "+str+" drops into the mist and disappears.\n");
  if (str == "cross") cross_is_gone=0;
  return 1;
}

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc = "violet mist";
  no_castle_flag=1;
  long_desc = 
    "You are standing in an erie violet mist.  It is impossible to\n"+
    "determine one direction from another.  It's so thick that you can't\n"+
    "even see your feet.  If you dropped anything, you would have to search\n"+
    "a lot and still might not find it.\n"+
    "Will you enter the mist further or run for your life?\n";
  items =
    ({
      "mist", "It is a thick violet mist that very little light penetrates.\n"+
              "You can't even see the ground.",
    });
  dest_dir = 
    ({
      "players/nooneelse/mist", "north",
      "players/nooneelse/mist", "east",
      "players/nooneelse/mist", "south",
      "players/nooneelse/mist", "west",
      "players/nooneelse/entryforest/e_forest11", "run",
      "players/nooneelse/dim", "enter",
    });
  cross_is_gone=0;
}
