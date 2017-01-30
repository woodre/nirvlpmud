int clonato;
inherit "room/room";
 
reset(arg) {
        object rat;
    if(arg) return;
    set_light(1);
    long_desc = "You are in a maze of tunnels.  Off to the east you can feel\n"+
		"dry heat drifting in.  You can hear cheery voices coming from\n"+
		"west.  To the north you can see a network of tunnels.  There is\n"+
		"fresh air coming from the south.  You hear something to the southwest!\n";
   short_desc = "An intersection";
    dest_dir = ({ "/room/sunalley1.c", "south",
		  "/players/mouzar/castle/mid/cave3", "north",
		  "/players/mouzar/castle/path9","east",
	   	  "/players/mouzar/castle/path1","west",
		  "/players/mouzar/castle/mid/cave1", "southwest"
		});
          rat=clone_object("/players/mouzar/castle/monsters/rat1");
      move_object(rat,this_object());
 
call_out("clone_shit", 1);
}
clone_shit()
{ if(!clonato&&!present("rat"))
    { object man;
      say("A man comes in crying cause you just killed his rat.\n");
      man=clone_object("/players/mouzar/castle/monsters/man1");
      move_object(man,this_object());
      clonato=1; 
    }
call_out("clone_shit", 3);
}
 
 
