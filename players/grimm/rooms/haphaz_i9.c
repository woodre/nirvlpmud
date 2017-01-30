inherit "room/room";
reset(arg) {
  monster();
  if(arg) return;
  short_desc="Dark Room";
long_desc=
"You have entered a very dark room.  You aren't sure but you feel as though\n"
+"you are being watched.\n";
  dest_dir=({"players/grimm/rooms/haphaz_j9","east"});

}
monster() {
int count;
   object demon;

   if(!present("demon")) {
      demon = clone_object("players/grimm/monster/shad_demon");
      move_object(demon, this_object());
   }
}
