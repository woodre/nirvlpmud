inherit "room/room";
reset(arg){
 if(!arg){
  set_light(1);
  short_desc="Living Chamber";
  long_desc="This is a general resting and eating room where the guards and clerics\n"+
            "meet and relax while off-duty.  It has the basic stuff.  Better hope\n"+
            "that the guards are all on duty, cause they wouldn't be happy to see\n"+
            "here.  They wouldn't like to take their work to their resting area.\n";
  dest_dir=({"players/mouzar/quest/lroom6","south",
             "players/mouzar/quest/lroom1","west",
             "players/mouzar/quest/lroom2","east",});
 }
 if(!present("guard",this_object())){
   move_object(clone_object("/players/mouzar/quest/mon/mbguard"),this_object());
 }
}
