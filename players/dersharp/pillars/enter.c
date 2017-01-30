inherit "room/room";
reset(arg) {
   if(arg) return;
   short_desc="The Pillars of Peril";
   long_desc ="As you enter this newbie area you feel that there is more\n"+
              "here than meets the eye.  The trail continues south to where\n"+
              "you can just make out a large tree and beyond that a jumbled\n"+
              "group of pillars.\n";
   set_light(1);
   dest_dir = ({
                "/players/dersharp/pillars/room3.c", "south",
                "/players/dersharp/rooms/enter.c", "out",
});
}
init(){
   ::init();
  if (this_player()->query_level() < 21) {
   if(this_player()->query_level()>8){
      move_object(this_player(), "/room/church");
      return 1;
   }
  }
}
