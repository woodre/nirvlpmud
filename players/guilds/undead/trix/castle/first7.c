inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
"As you enter the room you feel the age of the walls come down on you.\n"+
"Scattered on the ground are various old rusty weapons. A circular\n"+
"staircase goes up to the darkness of the battlement above you.\n"+
"A doorway to the east leads to the castle's courtyard.\n";
    short_desc ="A simple room";
    dest_dir = ({
             /*     "/players/trix/closed/guild/castle/first","up", */
                  "/players/trix/closed/guild/castle/first2.c","east"
                                                        });
}
realm(){return "NT";}
