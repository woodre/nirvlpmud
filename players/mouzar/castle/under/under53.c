inherit"/room/room";
reset(arg) {
if(!arg) {
  set_light(0);
  short_desc = "Tunnel";
  long_desc = "Well now the only way back is the way in which you entered.  Solid wall\n"+
	      "blocks every direction execpt for north.  If you had reason other than\n"+
	      "just curious now you must go back and face whatever made you come this\n"+
	      "way.  There are two skeletons lying against the west wall.  There is a\n"+
	      "chilly breeze coming from the ceiling.  You can make out a beam of light\n"+
	      "coming from it?\n" ;
  dest_dir = ({"/players/mouzar/castle/under/under52","north",
               });
  items=({"skeletons","Looks as tho these two guys were not brave enough to go back."});
           }
 
} 
