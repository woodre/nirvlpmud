inherit "room/room";
reset(arg) {
if(!arg) {
  set_light(0);
  short_desc = "Tunnel";
  long_desc = "Past all the spider webs to the East you come to another part of the\n"+
	      "endless caves of the Undermouz.  The cave is lite by some fungus on\n"+
	      "on the walls.  There are what seems to be foot prints on the floor\n"+
	      "but it's features are more skeletal than anything.\n" ;
           }
  dest_dir= ({"/players/mouzar/castle/under/under51","west",
	    });

if(!present("skeleton")) {
  move_object(clone_object("/players/mouzar/castle/under/mon/skeleton"),this_object());
  move_object(clone_object("/players/mouzar/castle/under/mon/skeleton"),this_object());
  move_object(clone_object("/players/mouzar/castle/under/mon/skeleton"),this_object());
} 
}

init() {
  add_action("east","east");
::init();
}

east(str) {
  if(!present("skeleton") && sizeof(dest_dir) == 2) {
    dest_dir+=({ "/players/mouzar/castle/under/under49", "east" });
    write("The wall disappears, revealing a passage to the east!\n");
    say("The wall disappears, revealing a passage to the east!\n");
    return 1;
  }
  if(present("skeleton")) {
    write("A wall blocks you path East.\n");
    return 1;
  }
  return ::move(str);
}
