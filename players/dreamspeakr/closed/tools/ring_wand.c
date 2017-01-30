id(str) { return str == "wand"; }
short() { return "A Ring_wand"; }
long() {
write("A ring fixing device, just ring_fix <player>.\n");
}

init() { add_action("restore_ring","ring_fix"); }

restore_ring(str) {
  object new;

  if( !str ) {
    write("Usage: ring_fix <Target>.\n");
    return 1;
  }
  if( !find_player(str) ){
    write("That player is not online.\n");
    return 1;
  }
  new = clone_object("/players/dreamspeakr/WEDDING/OBJ/wedding_ring.c");
  move_object(new, find_player(str));
  if( (int)new->fix_ring() ) {
      write("Restoring wedding ring info. . . \n");
  }
  else {
      write("Could not restore ring.  No info file. . .\n");
      destruct(new);
  }
  return 1;
}

get() { return 1; }
