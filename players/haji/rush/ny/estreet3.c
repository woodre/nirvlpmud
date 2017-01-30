inherit "room/room";
int i;
reset(arg) {
  monster();
  if(arg) return;
  short_desc="A street in New York";
  long_desc="This is a street in New York.  To the east you can\n" +
            "see the welfare office where you can cash your coins\n" +
            "for welfare checks and vice versa.  To the north you see\n" +
            "an old worn out building with a sign that says: 'City Hall' \n" +
            "on it.\n";

  dest_dir=({
          "players/haji/rush/ny/estreet2", "south",
          "players/haji/rush/ny/welfoff", "east",
            });
set_light(1);

}


monster() {
int count;
   object hippie;

   if(!present("liberal")) {
    while (i<3) {
      hippie = clone_object("players/haji/rush/char/libpr");
      move_object(hippie, this_object());
     i++;
       }
    i = 0;
   }
}
