  inherit "room/room";
  reset(arg){
   if(!present("scribe")) {
 move_object(clone_object("/players/arrina/monsters/scribe.c"),this_object());
 }
    if(!arg){
    set_light(0);
    short_desc="Office";
   long_desc=
  "You have entered the office of the guards.  The records and payroll\n" +
  "of the troops were kept here, and there is a safe on the west wall,\n" +
  "and a desk in the middle of the room.  This is a well-fortified room,\n" +
  "and to the north lies the main portion of the castle, although you can\n"+
  "find no way to get to it yet.\n";
    items=({
   "desk", "The desk is heavy and fine, and it has several ledgers and\n"+
           "journals laying on it, yellowed with age",
   "safe","The safe is open and empty, and covered with dust",
  });
    dest_dir=({
  "/players/arrina/newbie/newbie8.c","east",
   });
 }
 }
