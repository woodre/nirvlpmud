inherit"/room/room";
int i;
reset(arg) {
if(!arg) {
  set_light(1);
  short_desc = "Tunnel";
  long_desc = "Here you can hear chanting that makes the hairs on the back of you neck\n"+
              "stand.  It is one of the most evil chanting you have ever heard.  You\n"+
              "take notice of the number of spiders crawling around has increased. The\n"+
              "tunnel gets wider to the west.\n" ;
  dest_dir = ({"/players/mouzar/castle/under/under30","west",
               "/players/mouzar/castle/under/under32","east",
               });
           }
} 
