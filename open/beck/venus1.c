#define tp this_player()->query_real_name()
inherit "room/room";
int i, search_count;
init() {
   ::init() ;
   add_action("walk","walk");
   add_action("swim","swim");
   add_action("climb","climb");
   add_action("search","search");
}
reset(int arg) {
   if(arg) return;
   call_out("ocean",40);
   set_light(1);
   short_desc=("???");
   long_desc=
   "Here is a desolate beach.  Fine white sand covers the ground.\n"+
   "The ocean extends to the horizon, as far as the eye can see.\n"+
   "There are large sand dunes.  If you cross over them you can go inland.\n"+
   "Although the scene is familiar, you feel strange inside.  There seems\n"+
   "to be no people anywhere around here.  Glancing around you begin\n"+
   "to notice the strange plant life that thrives here.\n"+
   "Only one thought exists in your mind; 'Where am I?'\n",
   items=
   ({
         "sand","The sand is pure white.  It reflects so much sunlight\n"+
         "you are forced to squint your eyes",
         "dunes","large sand dunes inhibit your view of the inland area.\n"+
         "maybe you should climb the dunes and see whats on the other side",
         "ocean","You are at peace as you stare across the ocean",
         "beach","The beach is covered with a fine white sand.  It seems to\n"+
         "extend for a half-mile from here.  Try to walk the beach from here",
    });
   dest_dir=
   ({
    });
   if(!present("flytrap", this_object())){
move_object(clone_object("/players/beck/monster/flytrap.c"), this_object());
   }
   if(!present("flytrap 2", this_object())){
move_object(clone_object("/players/beck/monster/flytrap.c"), this_object());
   }
}
walk(arg) {
   if(!arg) {write("Where do you want to walk?\n"); return 1; }
   if(arg !="beach") {
      write("Only the beach seems easy enough to walk along.\n");
      return 1;
   }
   write("You stroll down the beach.\n");
   say(capitalize(this_player()->query_real_name()) + " walks along the beach.\n");
call_other(this_player(),"move_player","walking#/players/beck/room/venus2.c");
   return 1;
}
climb(arg) {
   if(!arg) {write("Where are going to climb?"); return 1; }
   if(arg !="dunes") {
      write("The only thing to climb here is the dunes");
      return 1;
   }
   say(capitalize(this_player()->query_real_name()) + "climbs up the dunes.\n");
   write("You climb up the dunes.\n");
call_other(this_player(),"move_player","climb#/players/beck/room/venus3.c");
   return 1;
}
search(arg) {
   if (search_count == 0)  {
      search_count = search_count + 1;
      write("You find a sharks tooth!\n");
move_object(clone_object("/players/beck/object/shark_tooth.c"), this_player());
      say (tp +" searches the area\n");
      return 1;  }
   else
      {
      search_count = search_count +1;
      write("You find nothing.\n");
      say(tp+" searches the area.\n");
      return 1;
   }   }

swim(arg) {
   write("You swim out into the ocean.\n");
   say(capitalize(this_player()->query_real_name()) +"swims out into the ocean.\n");
call_other(this_player(),"move_player","swiming#/players/beck/room/sea1.c");
   return 1;
}
ocean(){
   tell_room(this_object(),"Waves go crashing onto the sand by your feet.\n");
   call_out("ocean",100);
   return 1;
}
