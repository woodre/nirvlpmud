inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Armory";
long_desc =
"   The armory of the castle.\n";

items = ({
"armory",   "The armory of the castle",

});
if(!present("trolloc",this_object()))
 move_object(clone_object("/players/fakir/woods/TEMP/trolloc4.c"),this_object());

dest_dir = ({
   "/players/fakir/fcastle/room31.c", "out",
});
}


