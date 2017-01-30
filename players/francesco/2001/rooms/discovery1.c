#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("narrator")) {
  move_object(clone_object("/players/francesco/2001/mobs/narrator4.c"),
	this_object());  }

set_light(1);

short_desc = "Discovery" ;
long_desc =
     "   DISCOVERY SPACECRAFT,  1,000,000 MILES FROM EARTH\n"+
     "The cargo bay of the discovery is a room with a spherical shape and\n"+
     "diameter of about 20 feet.  The doors of this room alternatively \n"+
     "open and close to allow the entrance and the exit off the spacecraft,\n"+
     "without the risk of harmful space debris entering inside.\n",

items = ({
   "doors","They follow the spherical shape of the room, and can be opened with leverages",
   "debris","It is the so-called space trash. There is no debris here,\n"+
            "it is confined outside",
});

dest_dir = ({
  "/players/francesco/2001/rooms/discovery8.c","west",
  "/players/francesco/2001/rooms/discovery11.c","northeast",
});

}
query_no_fight() { return 1;}
