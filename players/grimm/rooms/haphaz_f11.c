inherit "room/room";
reset(arg) {
  monster();
  if(arg) return;
  short_desc="Black Room";
long_desc=
"You have entered a very dark room.  There is an air of mystery here that\n"
+"gives you a headache.  You feel as though your mind is being probed by\n"
+"some unknown force.\n";
  dest_dir=({"players/grimm/rooms/haphaz_e11","west"});
set_light(1);

}
monster() {
int count;
   object flayer;

   if(!present("flayer")) {
      flayer = clone_object("players/grimm/monster/flayer");
      move_object(flayer, this_object());
   }
}
