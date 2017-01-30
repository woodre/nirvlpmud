inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
"As you enter the room you feel the age of the walls come down on you.\n"+
"Scattered on the ground are various old rusty weapons. A circular staircase\n"+
"goes up to the darkness of the battlement above you. A doorway to the west\n"+
"leads to the castle's courtyard.\n";
    short_desc ="A simple room";
    dest_dir = ({
                  /* "/players/trix/closed/guild/castle/second","up",*/
                  "/players/trix/closed/guild/castle/first2.c","west"
                                                        });
}
realm(){return "NT";}
