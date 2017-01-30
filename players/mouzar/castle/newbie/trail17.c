 
 
inherit"/room/room";
reset(arg) {
if(!arg) {
 
           set_light(1);
short_desc = "A small cobble stone trail";
long_desc = "You can see a little building with a star on it with the writing\n"+
            "'Sheriff' written under it to the east. To the northwest\n"+
            "you can see a little mansion.  You see a bridge coming up to the\n"+
            "south.\n";
            
dest_dir = ({
           "/players/mouzar/castle/newbie/home","east",
           "/players/mouzar/castle/newbie/trail18","south",
           "/players/mouzar/castle/newbie/trail16","northwest",
           });
           }
       }
 
 
