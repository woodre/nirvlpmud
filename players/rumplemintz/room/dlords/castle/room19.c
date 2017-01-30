inherit "room/room";
reset(arg) {
  if(!arg) {
    set_light(1);
    short_desc = "Stairwell to sub-lvl 1";
    long_desc = "You found the secret stairwell that leads down to lvl 1.\n"+
     "Your quest for Lord Dwarven Lord is almost over, it's a good thing\n"+
     "you didn't stop questing on the last lord...\n";
    dest_dir = ({
      "players/rumplemintz/room/dlords/castle/room20", "down",
      "players/rumplemintz/room/dlords/castle/room18", "west",
      });
    items = ({
      "stairwell", "It looks old and weak, maybe you shouldn't try it."
      });
    }
}
