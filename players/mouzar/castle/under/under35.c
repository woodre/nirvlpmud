inherit"/room/room";
reset(arg) {
if(!arg) {
  set_light(0);
  short_desc = "Tunnel";
  long_desc = "You have entered a very large cave.  Looks like something lives here.\n"+
              "Might be wise to leave if it's not.  What you think?  You see a spot\n"+
              "well used in laying down or something like that.  It is the size of a\n"+
              "dragon.\n" ;
  dest_dir = ({"/players/mouzar/castle/under/under34","north",
               });
           }
if(!present("dragon")) { 
  move_object(clone_object("/players/mouzar/castle/under/mon/gdragon"),this_object());
}
} 
init() {
::init();
add_action("blast","blast");
}
 
blast(str) {
    if(present("dragon")) {
      write("You have problems blasting this monster!\n");
      say(capitalize(this_player()->query_name())+" tries to blast the dragon.\n");
      write("Dragon points at you.\n");
      say("The dragon points at "+capitalize(this_player()->query_name())+".\n");
      write("Dragon falls down laughing.\n");
      say("The Dragon falls down laughing.\n");
      return 1;
    }
    return;
}
