inherit "room/room";
object luigi;
reset(arg) {
  monster();
  if(arg) return;
  short_desc="Arcade Room";
long_desc=
"This is the hideout of a rather well known (but antiquated) arcade hero.\n"
+"He lives in this meager domicile to avoid the terrors that the Nintendo\n"
+"company has decided would be in his next adventure.\n";
  dest_dir=({"players/grimm/rooms/haphaz_h7","northeast"});
set_light(1);

}
init() {
   add_action("northeast","northeast");
   }
northeast() {
   this_player()->move_player("northeast#players/grimm/rooms/haphaz_h7");
   return 1;
   }
monster() {
int count;

   if(!present("luigi")) {
      luigi = clone_object("players/grimm/monster/luigi");
      move_object(luigi, this_object());
   }
}
