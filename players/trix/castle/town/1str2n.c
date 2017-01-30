inherit "room/room";
 
reset(arg) {
  if(!present("sand"))
    move_object(clone_object("/players/trix/castle/quest/monst/sand"),this_object());

  if(arg) return;
  set_light(1);
  long_desc = 
"  You're on Trixtown 1st street.  You can see shops on either side of this\n"+
"street that runs from south to north.\n";
  short_desc = "Trixtown 1st street";
  dest_dir = ({ "/players/trix/castle/town/1str3n.c","north",
                  "/players/trix/castle/town/1str1n.c","south",
                  "/players/trix/castle/town/jewelry.c","west",
                  "/players/trix/castle/town/hairdressers.c","east"});
}
