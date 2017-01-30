inherit "room/room";
object corridor;
reset(arg) {
  if(!arg) {
    set_light(1);
    short_desc = "Stairwell in sub-lvl 1";
    long_desc = "Welcome to level II of the underground passages of Dwarves.\n"+
      "You still have some venturing to go, but you can smell it getting closer.\n"+
       "The only obvious exit is up.\n";
    items = ({
      "stairwell", "It looks old and weak, maybe you shouldn't try it."
      });
    }
}
init() {
  add_action("search_room", "search");
  add_action("east", "east");
  add_action("up", "up");
}
search_room() {
  write("You search about frantically, and find an exit east.\n");
  say(capitalize(this_player()->query_name())+" searches the room.\n");
  corridor = this_player();
  return 1;
}
east() {
  if(corridor==this_player()){
    write("You go east through yet another hidden exit.\n");
    this_player()->move_player("east#players/rumplemintz/room/dlords/castle/room21");
    return(1);
  }
  write("What?\n");
  return 1;
}
up() {
  this_player()->move_player("up#players/rumplemintz/room/dlords/castle/room19");
  return 1;
}
