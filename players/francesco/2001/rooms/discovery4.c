#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("poole")) {
  move_object(clone_object("/players/francesco/2001/mobs/poole.c"),
	this_object());  }

set_light(1);

short_desc = "Discovery" ;
long_desc =
     "   DISCOVERY SPACECRAFT,  1,000,000 MILES FROM EARTH\n"+
     "The hub link of the Discovery has four doors which lead to the connecting\n"+
     "aisles to the outer rooms.  It can be called the center of gravity of the\n"+
     "spacecraft.  Due to this reason, the bodies have no weight, people can float\n"+
     "like in the deep interplanetary space.  It is a round room about 40 feet in \n"+
     "diameter.  It is really hard to say where is the up and where is the down.  \n"+
     "Some consoles and monitors are positioned along the walls.\n",

items = ({
   "consoles","They hold some keyboards and scanners, likely to give \n"+
              "the opening and closing commands of the doors",
   "monitors","They are flat LCD displays, filled with an endless sequence of numbers",
   "walls","About 13 feet tall, shining a bright silver color",
   "doors","Can be opened by putting your hand on a side scanner",
   "aisles","They are just tubes leading to the hub of the spacecraft",
});

dest_dir = ({
  "/players/francesco/2001/rooms/discovery24.c","east",
  "/players/francesco/2001/rooms/discovery13.c","south",
  "/players/francesco/2001/rooms/discovery23.c","west",  
  "/players/francesco/2001/rooms/discovery16.c","north",

});

}
