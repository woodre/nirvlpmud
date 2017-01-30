 
 
inherit"/room/room";
reset(arg) {
if(!arg) {
 
           set_light(1);
short_desc = "A small dirt trail";
long_desc = "This trail is bring you to a couple of buildings.  Here you can\n"+
            "see a pond ot the right.  Today it looks like a good day to go\n"+ 
            "fishing.\n";
          
dest_dir = ({
           "/players/mouzar/castle/newbie/trail4","north",
           "/players/mouzar/castle/newbie/trail6","south",
           });
           }
       }
 
 
