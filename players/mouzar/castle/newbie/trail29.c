 
 
inherit"/room/room";
reset(arg) {
if(!arg) {
 
           set_light(1);
short_desc = "A small bridge";
long_desc = "You can hear yourself walk across this small bridge.  You get the\n"+
            "the feeling that it is going to break under you so you hurry across\n"+
            "it.\n";
            
dest_dir = ({
           "/players/mouzar/castle/newbie/trail30","north",
           "/players/mouzar/castle/newbie/trail28","south",
           });
           }
       }
 
 
