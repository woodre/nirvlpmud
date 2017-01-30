#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
 

set_light(1);

short_desc = "Dept. Mech. Engr." ;
long_desc =
     "   At the end of the corridor there is a bronze statue representing\n"+
     "a man.  It looks like he is solemnly watching at you and somewhow\n"+
     "warning you.  He must have been teaching to several students during\n"+
     "his long academic career.  The present professors wanted to acknowledge\n"+
     "his devotion to this Department by establishing The Annual Best Paper \n"+
     "Award presented to the PhD student which prepared the best Thesis \n"+
     "within the Department.  A plaque in the bottom part of the statue \n"+
     "reads something.  On a corner of the room a winding staircase leads\n"+ 
     "down.\n",
items = ({
   "statue","It is the bust of a man, brown color,  shining bright",
   "plaque","                  Dr. Mario Rossi  \n"+
            "      Born in Roma, 1910,  Deceased in Roma, 1988\n"+
            "       Pionier in Mechanical Engineering Studies\n"+
            "In his great Wisdom our Department has flourished through\n"+
            "the past decades and will survive into the next millenium",
   "staircase","A large winding staircase leading down",
});
;

dest_dir = ({
   "/players/francesco/univ/rooms/dimec15.c","south",
   "/players/francesco/univ/rooms/dimec19.c","east",
   "/players/francesco/univ/rooms/dimec20.c","west",
   "/players/francesco/univ/rooms/dimec21.c","northeast",
   "/players/francesco/univ/rooms/dimec22.c","northwest",
   "/players/francesco/masterquest/lab.c","down",
});

}
