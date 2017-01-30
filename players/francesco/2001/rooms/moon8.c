#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("monolith")) {
  move_object(clone_object("/players/francesco/2001/items/monolith.c"),
	this_object());  }
if (!present("photo")) {
  move_object(clone_object("/players/francesco/2001/mobs/photo.c"),
	this_object());  }
set_light(1);

short_desc = "The Moon" ;
long_desc =
     "   MOON,  YEAR 2001\n"+
     "In the middle of the desolated landscape of the Moon an area is \n"+
     "escavated and delimited by wires and by metallic shields.  A frantic\n"+
     "activity is carried out by several men bringing tools or driving \n"+
     "strange vehicles,  both around and within the delimited area.  \n"+
     "Several high power xenon lamps almost blind your sight.  A monolith \n"+
     "stands in the center of the delimited area.\n",

items = ({
   "lamps","They are positioned on high poles, their light is bright white",
   "wires", "Some long, red and white wires useful to delimitate selected areas",
   "shields","They are held vertically, and are made by rectangular 6x3 feet panels",
   "vehicles","They have only the frame of a car, without the body, used to be called Lunar Rovers",
   "men","They are all dressed with space suits, helmets and oxygen tanks, they move jump by jump",
   "tools","Some portable drilling machines, hammers, screw drivers, computers, microphones",
   "area","It is an open zone escavated below the Moon surface",
});

dest_dir = ({
  "/players/francesco/2001/rooms/moon7.c","west",
  "/players/francesco/2001/rooms/moon16.c","southwest",
});

}


init(){
      ::init();
      add_action("touch","touch");
      }

touch(str) 
  {
  if(!str) {write("Touch what?\n"); return 1;}
  if(str!="monolith") {write("Touch what?\n"); return 1; }
  write("All of a sudden a brilliant blast of light surrounds the room.\n"+
        "Your mind blows,  your eyes close, your body feels weightless.\n"+
        " ....... ......... ........... ........... ......... .......\n"+
        "   ...     .....     .......     .......     .....     ...\n"+
        "    .        .         ...         ...         .        .\n"+
        "                        .           . \n"+
        "             You are transported elsewhere.\n");
  call_out("wait",5);
  this_player()->move_player("to another age#players/francesco/2001/rooms/discovery1.c");
  return 1;
  }

wait(){return 1;}
