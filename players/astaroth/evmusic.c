inherit        "room/room";
 
object newkd;
 
reset(arg) { 
 if(!present("johnathan")) {
   move_object(clone_object("players/astaroth/nk1.c"), this_object());
 }
 if(!present("jordan")) {
   newkd = clone_object("players/astaroth/nk1.c");
   newkd->set_name("jordan");
   newkd->set_short("Jordan");
   move_object(newkd, this_object());
 }
 if(!present("danny")) {
   newkd = clone_object("players/astaroth/nk1.c");
   newkd->set_name("danny");
   newkd->set_short("Danny");
   move_object(newkd, this_object());
 }
 if(!present("donnie")) {
   newkd = clone_object("players/astaroth/nk1.c");
   newkd->set_name("donnie");
   newkd->set_short("Donnie");
   move_object(newkd, this_object());
 }
 if(!present("joe")) {
   newkd = clone_object("players/astaroth/nk1.c");
   newkd->set_name("joe");
   newkd->set_short("Joe");
   move_object(newkd, this_object());
 }
  if(!arg) {
  set_light(1);
  short_desc = "Let's start out evil here...";
  long_desc = 
   "This section starts in the most evil force known in the current \n"+
   "universe - the New Kids on the Block.  The music doesn't get any\n"+
   "worse than this...  How could it???\n"+
   "Kill them quick, they are real wimps!\n";
  dest_dir = ({"players/astaroth/music1", "south",
               "players/astaroth/music2", "east",
               "players/astaroth/milvil", "west",
               "players/astaroth/ev3", "north"});
  }
}
