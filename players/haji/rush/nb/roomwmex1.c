inherit "room/room";
int i;
reset(arg) {
  monster();
  if(arg) return;
  short_desc="An alley in New York";
long_desc="This is your typical trash strewn alley.\n";

  dest_dir=({
          "players/haji/rush/ny/wstreet1", "west",
            });
set_light(1);

}


monster() {
int count;
   object hippie;

   if(!present("liberal")) {
    while (i<1) {
      hippie = clone_object("players/haji/rush/char/complib");
      move_object(hippie, this_object());
     i++;
       }
    i = 0;
   }
}
