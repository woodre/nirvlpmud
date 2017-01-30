#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("narrator")) {
  move_object(clone_object("/players/francesco/2001/mobs/narrator3.c"),
	this_object());  }
set_light(1);

short_desc = "The Moon" ;
long_desc =
     "   MOON,  YEAR 2001\n"+
     "The Clavius Base on the Moon is made by 5 wide transparent cupoles,\n"+
     "the bigger being about 300 feet high, the others about 200.  Some\n"+
     "buildings are inside,  they look like either laboratories and \n"+
     "dormitorys.  Several antennas are on the top of the cupoles, in\n"+
     "their outer part, protruding towards the deep space.\n",

items = ({
   "buildings","They are quite similar to those seen on the Earth",
   "laboratories", "The labs are made by one floor only, with high ceilings",
   "dormitorys","They have a regular shape, with small windows, very much space-saving",
   "antennas","They are made by ample metallic paraboles with a pole in their center",
   "space","Since there is no atmosphere on the Moon, it appears dark",
});

dest_dir = ({
  "/players/francesco/2001/rooms/moon4.c","northwest",
  "/players/francesco/2001/rooms/moon2.c","west",
});

}

query_no_fight() { return 1;}