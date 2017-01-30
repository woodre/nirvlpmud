inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Courtyard Shop";
long_desc =
"   The shop of the castle courtyard.\n";

items = ({
"shop",   "The shop of the castle courtyard was open at one time, but\n"+
"is closed due to a rampant disease which killed the shopkeeper.  In\n"+
"due time, someone may purchase the shop and return it to business.",

});
if(!present("trolloc",this_object()))
 move_object(clone_object("/players/fakir/woods/TEMP/trolloc4.c"),this_object());

dest_dir = ({
   "/players/fakir/fcastle/room31.c", "out",
});
}


