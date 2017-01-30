inherit"/room/room";
reset(arg) {
if(!arg) {
  set_light(1);
  short_desc = "Tunnel";
  long_desc = "The mumbling starts to get louder as you near the source.  The smell starts\n"+ 
              "to over take you here.  You are force to take out a rag and cover your nose.\n"+
              "The mumbling seem to be a song of some sort.  Sounds almost like it is spoken\n"+
              "in dwarven.  Could it be a friendly group you have stumbled upon?  There are\n"+ 
              "boot prints littering the floor here.\n" ;
  dest_dir = ({"/players/mouzar/castle/under/under40","south",
               "/players/mouzar/castle/under/under41","west",
               });
           }
 
} 
