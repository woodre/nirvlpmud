inherit "room/room";
object terminator;
reset(arg) {
  monster();
  if(arg) return;
  short_desc="High-Tech Room";
long_desc=
"This is the home of the legendary Terminator.\n";
  dest_dir=({"players/grimm/rooms/haphaz_j3","northeast"});
set_light(1);

}
monster() {
int count;

   if(!present("terminator")) {
      terminator = clone_object("players/grimm/monster/terminator");
      move_object(terminator, this_object());
   }
}
