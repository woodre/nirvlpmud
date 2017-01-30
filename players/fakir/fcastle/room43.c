inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Storage Room";
long_desc =
"   Boxes, sacks, and all sorts of goods lie strewn about and stacked\n"+
"in piles.  Broken bottles and leather drawstring bags are all mixed\n"+
"in with the debris.\n";

items = ({
"",   "",

});
if(!present("trolloc",this_object()))
 move_object(clone_object("/players/fakir/woods/TEMP/trolloc4.c"),this_object());

dest_dir = ({
   "/players/fakir/fcastle/room36.c", "out",
});
}


