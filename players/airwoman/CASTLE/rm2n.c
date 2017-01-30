inherit "room/room";

object sign;
reset(arg){
   if(!arg){
        set_light(1);
        short_desc="if...then...else";
        long_desc=
        "The streets are clean.  The weather is beautiful.\n"+
        "Can u ask for anything more?  How about a Bud Light?\n";
        dest_dir=({"players/airwoman/CASTLE/rm1n", "south",
		   "players/airwoman/forest/room1", "north",
        "players/airwoman/CASTLE/sexroom", "east"});       
             
	sign = clone_object("players/airwoman/sign");
	move_object(sign, this_object());
}
}
init() {
#ifndef __LDMUD__
  add_action("bud");  add_xverb("");
  ::init();
#else
::init();
  add_action("bud", "", 3);
#endif
}

bud(str) {
  string a, b;
  object bud1;

  if (sscanf(str, "%sbud%s", a, b)==2 ||
      sscanf(str, "%sBud%s", a, b)==2 ||
      sscanf(str, "%sBUD%s", a, b)==2) {
    if (!present("bud", this_object())) {
      move_object(clone_object("/players/airwoman/bud"), this_object());
      tell_room(this_object(), "Bud appears in a flash!\n");
      return 1; /* Rumplemintz */
    }
  }
  return 0; /* Rumplemintz */
}
