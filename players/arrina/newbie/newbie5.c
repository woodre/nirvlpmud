  inherit "room/room";
  reset(arg){
   if(!present("sickman")) {
 move_object(clone_object("/players/arrina/monsters/sickman.c"),this_object());
 }
    if(!arg){
    set_light(0);
    short_desc="Sickroom";
   long_desc=
  "This room smells of medicine and sickness.  You have entered the\n" +
  "bedroom of the man who used to be the head guard of the castle,\n" +
  "who loves the castle as if it were his own.  There is a bed in the\n" +
  "room, and a chair.  The feeling of weakness surrounds you, but it\n"+
  "may be slightly misleading.\n";
    items=({
   "bed", "The bed is dilapidated, but you see that the bedclothes\n"+
           "are of good quality linen",
   "chair","The chair appears to have not been used in a long time",
  });
    dest_dir=({
  "/players/arrina/newbie/newbie4.c","south",
  "/players/arrina/newbie/newbie7.c","north",
  "/players/arrina/newbie/newbie9.c","west",
   });
 }
 }
