inherit "room/room";
realm(){ return "NT";}
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc=("???");
   long_desc=
   "The water here is much deeper than it appears.  You find yourself \n"+
   "swimming in the cool water immediatly.  You notice that the stream\n"+
   "goes directly into the rocks in one direction, and seems to flow through\n"+
   "a small opening to the ocean in the other.  From here you can climb out to\n"+
   "the grassy area, or swim upstream or downstream.\n"+
   "It is not wise to hang around as some of the fish do not appear to be friendly.\n"+
   "",
   items=
   ({
    });
   dest_dir=
   ({
    });
   if(!present("pirhana", this_object())){
      move_object(clone_object("/players/beck/monster/pirhana.c"), this_object());
   }
   if(!present("pirhana 2", this_object())){
      move_object(clone_object("/players/beck/monster/pirhana.c"), this_object());
   }
}
init() {
   ::init() ;
   add_action("climb","climb");
   add_action("swim","swim");
}
climb(arg){
   if(!arg) {write("What do you want to climb?\n"); return 1;}
   if(arg !="bank") {write("You can only climb the bank.\n"); return 1;}
   call_other(this_player(),"move_player","climb#/players/beck/room/venus5.c");
   return 1;
}
swim(arg) {
   if(!arg){write("Where do you want to swim to?\n"); return 1;}
   if(arg=="downstream"){
      write("You swim downstream...right into the ocean.\n");
      call_other(this_player(),"move_player","swim#/players/beck/room/sea4.c");
      return 1;}
}
