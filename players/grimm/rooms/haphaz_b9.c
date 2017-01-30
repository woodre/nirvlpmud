inherit "room/room";
reset(arg) {
  monster();
  if(arg) return;
  short_desc="Silvery Room";
long_desc="This is the home of a Gleamer.  The walls are very slick and\n"+
"shiney.  The floor and ceiling look as though they were made of glass.\n";
  dest_dir=({"players/grimm/rooms/haphaz_b8","north"});
set_light(1);

}
monster() {
int count;
   object gleamer;

   if(!present("gleamer")) {
      gleamer = clone_object("players/grimm/monster/gleamer");
      move_object(gleamer, this_object());
   }
}
