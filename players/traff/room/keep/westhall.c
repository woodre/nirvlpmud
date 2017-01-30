 inherit "room/room";
 reset(arg){
/*
   if(!present("templar"))  {
    move_object(clone_object("/players/traff/mon/templar.c"),this_object());  }
  if(!present("general"))  {
    move_object(clone_object("/players/traff/mon/general.c"),this_object());  }
  if(!present("captain"))  {
    move_object(clone_object("/players/traff/mon/captain.c"),this_object());  }
  if(!present("aide"))  {
    move_object(clone_object("/players/traff/mon/aide.c"),this_object());  }
*/
   if(!arg){
     set_light(1);
    short_desc="West Hall";
    long_desc=
("This is the west hall.  It is smaller than the east hall, and used\n"+
"for smaller gatherings.  There are a number of tables and chairs\n"+
"scattered around the room.  There is the usual fireplace here and\n"+
"of course another painting on the wall.  To the north it looks like\n"+
"there are private rooms, and to the west is the Chapel.\n");
 items=({
"floor","Polished marble from the mountains",
"walls","The walls are made from stone also",
"fire","The fire blazes warmly",
"fireplace","A smaller fireplace, it heats the room nicely",
"tables","Suitable for 4 to 6 people the tables have inlaid wood tops",
"chairs","Sturdy but comfortable looking",
 });
   dest_dir=({
/*
"/players/traff/room/keep/library.c","north",
*/
"/players/traff/room/kentry.c","east",
/*
"/players/traff/room/keep/chapel.c","west",
*/
      });
    }
  }
 init()  {
 ::init();
  add_action("search","search");
}
 search(str)  {
   if(!str)  {
    write("Search what?\n");
    return 1;  }
   write("You search the "+str+" but find nothing of interest.\n");
  return 1;  }
 
