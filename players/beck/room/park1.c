inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc=
   "Angel Grove Park.\n"+
   "There are trees, flowers, and sunshine filling your visual senses.\n"+
   "There are playing fields to the southeast.\n"+
   "",
   items=
   ({
         "trees","A few small hardwood trees",
         "flowers","Small patches of flowers planted by volunteers",
    });
   dest_dir=
   ({
         "players/beck/room/park6","east",
         "players/beck/room/park7","southeast",
         "players/beck/room/park2","south",
    });
}

short(){
   return "Angel Grove Park";
}

init(){
   ::init();
   if(this_player()){
      if(present("ranger_object",this_player())){
         call_out("ranger_monsters",6);
      }
   }
}

ranger_monsters(){
   if(random(100) < 10){
   }
   if(random(100) < 5){
      if(!present("putty 2",this_object())){
         tell_room(this_object(),"Putties Attack!\n");
         move_object(clone_object("/players/beck/monster/putty.c"),this_object());
         move_object(clone_object("/players/beck/monster/putty.c"),this_object()); 
         move_object(clone_object("/players/beck/monster/putty.c"),this_object()); 
         move_object(clone_object("/players/beck/monster/putty.c"),this_object()); 
      }
   }
}
