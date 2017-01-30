 
 
inherit"/room/room";
reset(arg) {
if(!arg) {
 
           set_light(1);
short_desc = "A small cobble stone trail";
long_desc = "Here you catch the smell of ale.  As you look to the east you can\n"+
            "a sign hanging over the door reading 'Amster's Brewery'.  To the\n"+
            "north you can see a stream with a bridge going over it.\n";
            
dest_dir = ({
           "/players/mouzar/castle/newbie/trail29","north",
           "/players/mouzar/castle/newbie/brewery","east",
           "/players/mouzar/castle/newbie/trail25","south",
           });
           }
       }
 
 
