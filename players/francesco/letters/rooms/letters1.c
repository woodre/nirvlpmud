#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

if (!present("dispenser")) {
  move_object(clone_object("/players/francesco/letters/items/dispenser.c"),
	this_object());  }
set_light(1);

short_desc = "Landing along the stairs" ;
long_desc =
     "   The second floor landing is an ample room, with a high ceiling.\n"+
     "There is an open door to the north and two flights.  Next to the\n"+
     "ascending one there is a sign.  On the walls are hanging some \n"+
     "posters and announcements.  \n",

items = ({
   "landing","It is the connection between two flights of stairs",
   "ceiling","Of a semi-circular shape, like the old roman arches",
   "door","The door is high and wide.  There are some nouns written on it",
   "flights","The two flights are wide and with short steps",
   "sign","There are some lettering written on it to read",
   "walls","White painted, perfectly maintained",   
   "posters","They show in short some research themes performed \n"+
             "in the Letters Department", 
   "announcements","They announce some openings for tenure positions",
   "nouns","LETTERS DEPARTMENT",
});

dest_dir = ({
  "/players/francesco/univ/rooms/corridor3.c","down",
  "/players/francesco/letters/rooms/letters2.c","north"
});

}

init() {
    ::init();
    add_action("read"); add_verb("read");
}

read(str) {
    if(!str) {notify_fail("Read what?\n"); return 0;}
    if (str=="lettering")
       {write("Staff only.\n"); return 1;}
    notify_fail("Read what?\n"); return 0;}
