inherit "room/room";
int i;
reset(arg) {
  monster();
  if(arg) return;
  short_desc="A street in New York";
  long_desc=" This is a street in New York, to the south\n" +
            "You see Central Park. To the west you see a soup\n" +
            "kitchen.\n";

  dest_dir=({
          "players/haji/rush/ny/estreet2", "north",
      "players/haji/rush/ny/soupk", "west",   
            });
set_light(1);

}


monster() {
int count;
   object hippie;

   if(!present("mugger")) {
    while (i<1) {
      hippie = clone_object("players/haji/rush/char/mugger");
      move_object(hippie, this_object());
     i++;
       }
    i = 0;
   }
}
