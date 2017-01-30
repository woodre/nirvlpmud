inherit"/room/room";
object found;
reset(arg) {
if(!arg) {
  found = 0;
  set_light(1);
  short_desc = "Tunnel";
  long_desc = "You hear a roar from the east of this part of the tunnel.  It is warmer\n"+
              "in this area.  There is a pile of bones that lie at the mouth of the\n"+
              "eastward tunnel.  There is no flesh left on the body.  From the looks of\n"+
              "the fragile bones this person must have been elven.\n" ;
  dest_dir = ({
		"/players/mouzar/castle/under/under48","north",
               "/players/mouzar/castle/under/under45","south",
               "/players/mouzar/castle/under/under47","east",
               });
           }
 
} 
init() {
::init();
  add_action("search","search");
}

search(str) {
  if(str == "bones" && found == 1) {
    write("You find nothing in the pile of bones\n");
    say(this_player()->query_name()+" searches some bones.\n");
    return 1;
  }
  if(str == "bones") {
    write("You find a ring that is probally more useful to you than the pile of bones.\n");
    say(this_player()->query_name()+" searchs a pile of bones.\n");
    move_object(clone_object("/players/mouzar/castle/under/obj/bring"),this_player());
    found = 1;
    return 1;
  return;
}
  }
