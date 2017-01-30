inherit "room/room";
reset(arg) {
  monster();
  if(arg) return;
  short_desc="Black Room";
long_desc=
"You have entered a very dark room.  There is an air of mystery here that\n"
+"gives you a headache.  You feel as though your mind is being probed by\n"
+"some unknown force.  You can also feel a presence of extreme evil here.\n";
  dest_dir=({"players/grimm/rooms/haphaz_j8","south"});

  call_out("keep",600);
}
monster() {
int count;
   object lich;

   if(!present("lich")) {
      lich = clone_object("players/grimm/monster/lich");
      move_object(lich, this_object());
   }
}

keep() {
  monster();
  call_out("keep",600);
  return 1;
}
