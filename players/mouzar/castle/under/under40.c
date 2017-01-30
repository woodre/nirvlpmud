inherit"/room/room";
reset(arg) {
if(!arg) {
  set_light(1);
  short_desc = "Tunnel";
  long_desc = "Here you start to hear mumbling.  You catch the smell of wastes and\n"+
              "decomposing bodys.  This tunnel is long and dark.  There is flickering\n"+
              "of torch light to the north.  These caves can be filled with anything.\n"+
              "from smart to dumb or from harmless to dangerous.  There are boot prints\n"+
              "littering the floor here.\n" ;
  dest_dir = ({"/players/mouzar/castle/under/under42","north",
               "/players/mouzar/castle/under/under38","south",
		"/players/mouzar/castle/under/under43","east",
               });
           }
 
} 
