inherit "room/room";
id(str) { return str == "castle"; }
init() {
   ::init();
        add_action("enter"); add_verb("enter");
}
enter(str) {
  if(str=="castle"){
    write("You enter the dwarven castle.\n");
    this_player()->move_player("enter#players/rumplemintz/room/dlords/castle/ent");
    return(1);
    }
  write("Enter what?\n");
  return 1;
}
reset(arg) {
        if(!arg) {
                set_light(1);
        short_desc = "Facade to Dwarf Lord castle";
        long_desc = "You stand at the facade to a small, battle beaten castle, with\n"+
                "vines and blood strewn about.  The Dwarves made no attempt to keep this\n"+
                "castle clean.  The whole structure is sickening to look at.\n";

        dest_dir = ({
                "players/rumplemintz/room/dlords/room8", "south",
                "players/rumplemintz/room/dlords/room18", "north",
                });
        items = ({
                "castle", "It is the most horrifying thing you've ever seen."
                });
        }
}
