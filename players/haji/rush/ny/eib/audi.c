inherit "room/room";
int i;
reset(arg) {
  monster();
  if(arg) return;
short_desc="The audience for the Rush Limbaugh show";
long_desc="This is where the audience to that great show the\n" +
          "Rush Limbaugh show.  Being here makes you feel REALLY good.\n" +
          "To the west is the studio entrance and to the east is where Rush\n" +
          "makes his nightly appearance.\n";

  dest_dir=({
          "players/haji/rush/ny/eib/tv1", "west",
          "players/haji/rush/ny/eib/rushr", "east",
            });
set_light(1);

}


monster() {
int count;
   object hippie;

   if(!present("hippie")) {
    while (i<7) {
      hippie = clone_object("players/haji/rush/char/audimem");
      move_object(hippie, this_object());
     i++;
       }
    i = 0;
   }
}
