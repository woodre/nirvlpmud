inherit "room/room";
reset(arg) {
  monster();
  if(arg) return;
  short_desc="Foggy Room";
long_desc="This room is rather foggy.  The air is slightly thinner in here\n"+
"though.\n";
  dest_dir=({"players/grimm/rooms/haphaz_f2","southeast"});
set_light(1);

}
monster() {
int count;
   object vampire;

   if(!present("vampire")) {
      vampire = clone_object("players/grimm/monster/vampire");
      move_object(vampire, this_object());
   }
}
