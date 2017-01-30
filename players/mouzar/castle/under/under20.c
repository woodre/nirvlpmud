inherit"/room/room";
int i;
reset(arg) {
if(!arg) {
  set_light(1);
  short_desc = "Drow House";
  long_desc = "This seem to be a guest house of some kind.  It is well lit unlike\n"+
              "the rest of the place here in Undermouz.  There is the smell of roses\n"+
              "in the air.  The room seems to have been destroyed by a fireball or\n"+
	      "or something of that effect.\n";
  dest_dir = ({"/players/mouzar/castle/under/under19","north",
               });
           }
} 
