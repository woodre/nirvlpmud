inherit"/room/room";
reset(arg) {
if(!arg) {
  set_light(1);
  short_desc = "Tunnel";
  long_desc = "This part of the little community seems untouched by the fight.  The Drow\n"+
              "must have been pushed back or finished having fun.  You can hear some crying\n"+
              "coming from the north.  You can still hear the singing to the gods going on.\n"+
              "Even tho you don't understand the song it still touches you some.\n" ;
  dest_dir = ({"/players/mouzar/castle/under/under123","north",
               "/players/mouzar/castle/under/under133","south",
               });
           }
 
} 
