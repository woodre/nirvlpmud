#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("myra")) {
  move_object(clone_object("/players/francesco/univ/mob/myra.c"),
	this_object());  }

set_light(1);

short_desc = "Dept. Mech. Engr." ;
long_desc =
     "   The entrance to the Department of Mechanical Engineering is\n"+
     "filled with old items.  These objects are here to let you remember\n"+
     "the works carried out in the past by many researchers which have\n"+
     "contributed to the development of this Institution.  Some of them\n"+
     "are really out of date. The item which looks like the most interesting\n"+
     "one is an internal combustion engine.\n",

items = ({
   "engine","A sectioned engine to show the students how it works.  The carburetor,\n"+
            "the valves, the cylinder, the piston and the crankshaft are well visible\n"+
           "and can be examined in detail",
   "piston", "                     _____\n"+
             "                    /     \\ \n"+
             "                    \\_____/\n"+
             "                      | |\n"+
             "                      | |\n"+
             "                      |_|\n"+
             "Of circular shape, with a cave inside to make it lighter",
   "crankshaft","\n                           __    __\n"+
                "Its shape is the following   |__|   and is made by forged steel",
   "valves","They alternatively open and close to let fuel mixture enter the cylinder",
   "carburetor","Permits to mix the fuel with the air before entering the cylinder",
   "cylinder","Inside the cylinder the fuel mixture explodes and gives mechanical\n"+
              "action to the piston",
   "items","Prototypes, Mechanical parts, Small testing machines, Tools", 
});

dest_dir = ({
  "/players/francesco/univ/rooms/dimec2.c","north",
  "/players/francesco/univ/rooms/corridor3.c","south",
});

}
