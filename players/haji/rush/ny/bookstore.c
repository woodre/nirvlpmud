inherit "room/room";
int i;
reset(arg) {
  monster();
  if(arg) return;
  short_desc="An nice looking bookstore";
long_desc="This is your typical bookstore.\n";

  dest_dir=({
          "players/haji/rush/ny/wstreet2", "east",
            });
set_light(1);

}


monster() {
int count;
   object hippie;

   if(!present("bookkeeper")) {
    while (i<1) {
      hippie = clone_object("players/haji/rush/char/bookk");
      move_object(hippie, this_object());
     i++;
       }
    i = 0;
   }
}
