inherit "room/room";
int i;
reset(arg) {
  monster();
  if(arg) return;
  short_desc="Stereo Room";
long_desc="This room is covered wall to wall with stereo speakers and graphitti."+
"\nIn the center of the room you see the local gang leader Tyrone.\n";
  dest_dir=({"players/grimm/rooms/haphaz_g3","north"});
set_light(1);

}
monster() {
int count;
   object tyrone;

   if(!present("tyrone")) {
      tyrone = clone_object("players/grimm/monster/tyrone");
      move_object(tyrone, this_object());
   }
}
