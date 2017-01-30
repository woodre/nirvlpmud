inherit "room/room";
int i;
reset(arg) {
  monster();
  if(arg) return;
  short_desc="A street in New York";
long_desc="You think that camera crews often frequent here.\n" +
          "To the north is the NBC building, which houses NBC news and on\n" +
          "occasion, David Letterman.  To the west you see THE photo store" +
          "\nthat made Letterman's show has made so famous.\n";

  dest_dir=({
          "players/haji/rush/ny/wstreet3", "south",
            });
set_light(1);

items = ({"photo store",
 "This is the photo store that has been famous by Dave's 'May we see your photos please?' \n",
  });
}


monster() {
int count;
   object crewman;

   if(!present("crewman")) {
    while (i<3) {
      crewman = clone_object("players/haji/rush/char/crew");
      move_object(crewman, this_object());
     i++;
       }
    i = 0;
   }
}
