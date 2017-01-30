inherit "room/room";
int i;
reset(arg) {
  monster();
  if(arg) return;
  short_desc="A street in New York";
long_desc="You are feeling much better as you head farther south.\n" +
          "However, on the ground you see some insects that were left by\n" +
          "some sixties reject.  Also, to your relief to the south you see\n" +
          "the EIB building home to the Great Rush! To the east is an alley.\n";

  dest_dir=({
          "players/haji/rush/ny/wstreet2", "north",
          "players/haji/rush/ny/eib/ent", "south",
          "players/haji/rush/ny/walley", "east",
            });
set_light(1);

}


monster() {
int count;
   object hippie;

   if(!present("hippie")) {
    while (i<1) {
      hippie = clone_object("players/haji/rush/char/potsm");
      move_object(hippie, this_object());
     i++;
       }
    i = 0;
   }
}
