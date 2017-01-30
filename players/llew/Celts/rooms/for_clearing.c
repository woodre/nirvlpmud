inherit "room/room";

int not_exitable;

reset(arg) {
if(!arg) {
   set_light(1);
   short_desc="Cairne";
   long_desc="\tPassing through the forest you enter a clearing.\n"+
      "Standing in the middle of this clearing is a mound of large\n"+
      "stones about seven feet high and ten feet in diameter.  The mound\n"+
      "is old.  Vegatation grows in the earth filled spaces between the\n"+
      "many rocks.  Around on all sides are the tall trees of the forest\n"+
      "although to the east you see a road in the distance.\n";
   dest_dir=({
      "/players/llew/Celts/rooms/for_road1.c","east",
   });
   items=({"forest","The thick forest blocks passage in most directions",
      "trees","The trees rise far above, blocking out some of the light",
      "stones","The stones are most definately not native to this region.\nIt must have taken great ordeal to make this mound",
      "mound","The cairne must be used as a marker of some sort.",
      "road","Through the trees you see the road from which you came here on",
      });
   if(!present("druid")) transfer(clone_object("/players/llew/Celts/monsters/druid.c"),this_object());
   }
}

init() {
   ::init();
   add_action("search","search");
   add_action("go_east","east");
   add_action("cairne","enter");
   this_player()->set_fight_area();
}

search() {
   write("Your search proves futile.\n");
   return 1;
}

cairne(str) {
   if(!str) {write("Enter what?"); return 1;}
   if(str == "cairne") {
      write("This area is currently under construction.\n"); 
      return 1;
   }
}

realm() {
   if(not_exitable) return "NT";
   return 0;
}

go_east() {
   if(not_exitable) {
      write("What?\n");
      return 1;
   }
   this_player()->move_player("east#/players/llew/rooms/for_road1.c");
   return 1;
}

no_exit(n) {
   not_exitable=n;
}
