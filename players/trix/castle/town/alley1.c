inherit "room/room";
 
reset(arg) {
  if(arg) return;
  set_light(1);
  long_desc =
"  You are walking down a dusty alley.  The landscape is really sad and\n"+
"oppressive.  A strange feeling in your blood and bones tells you this is a\n"+
"bad place.\n";
  short_desc = "A dusty alley";
  dest_dir = ({
    /* "/players/trix/castle/town/alley2.c","north" */
    "/players/trix/castle/town/mainroad5.c","south",
    "/players/trix/castle/town/coven.c","down"
  });
}

/* Nonexistant room -feld
init(){
  ::init();
  add_action("north","north");
}
north(){
  write("No no no, sorry but that zone is too dangerous for you by now.\n");
  return 1;
}
*/

