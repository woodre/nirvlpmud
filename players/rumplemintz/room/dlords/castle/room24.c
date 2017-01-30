inherit "room/room";
object corridor;
reset(arg) {
  if(!arg) {
    set_light(1);
    short_desc = "Nowhere in Dwarf land";
    long_desc = "Still on level III of the underground passages of Dwarves.\n"+
      "You still have some venturing to go, but you can smell it getting closer.\n"+
       "The only obvious exit is northwest.\n";
    items = ({
      "stairwell", "It looks old and weak, maybe you shouldn't try it."
      });
    }
}
init() {
  add_action("search_room", "search");
  add_action("northwest", "northwest");
  add_action("north", "north");
}
search_room() {
  write("You search about frantically, and find an exit north.\n");
  say(capitalize(this_player()->query_name())+" searches the room.\n");
  corridor = this_player();
  return 1;
}
north() {
  if(corridor==this_player()){
    write("You go north through yet another hidden exit.\n");
    this_player()->move_player("north#players/rumplemintz/room/dlords/castle/room25");
    return(1);
  }
  write("What?\n");
  return 1;
}
northwest() {
  this_player()->move_player("northwest#players/rumplemintz/room/dlords/castle/room23");
  return 1;
}
