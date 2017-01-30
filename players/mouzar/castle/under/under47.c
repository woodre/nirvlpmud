inherit"/room/room";
reset(arg) {
if(!arg) {
  set_light(0);
  short_desc = "Tunnel";
  long_desc = "You have entered a very large chamber.  Looks like something lives here.\n"+
              "might be wise to leave if it's not.  What you think?  The only stuff you\n"+
              "see here is a nest of some kind.  There is no light source here.  So unless\n"+
              "you brought your own.  It is kinda warm here.  Just right if you would to\n"+
              "some eggs.\n" ;
  dest_dir = ({"/players/mouzar/castle/under/under46","west",
               });
           }
if(!present("wyvern")) { 
  move_object(clone_object("/players/mouzar/castle/under/mon/wyvern"),this_object());
}
} 
