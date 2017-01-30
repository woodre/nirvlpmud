inherit"/room/room";
reset(arg) {
if(!arg) {
  set_light(1);
  short_desc = "Duergar Community";
  long_desc = "This part of the little community seems untouched by the fight.  The Drow\n"+
              "must have been pushed back or finished having fun.  There is cheering coming\n"+
              "coming from the east.  Sounds as tho there is a party going on.  To the west\n"+
              "there isn't even a sound.  Just the echos coming off the walls from the\n" +
              "cheering and stuff coming from the east.\n";
  dest_dir = ({"/players/mouzar/castle/under/under131","west",
               "/players/mouzar/castle/under/under129","east",
               });
           }
 
  if(!present("drunk")) {
    move_object(clone_object("/players/mouzar/castle/under/mon/dudrunk"),this_object());
    move_object(clone_object("/players/mouzar/castle/under/mon/dudrunk"),this_object());
  }
} 
