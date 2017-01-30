inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "";
long_desc =
"   \n";

items = ({
"",   "",

});
if(!present("trolloc",this_object()))
 move_object(clone_object("/players/fakir/woods/TEMP/trolloc4.c"),this_object());

dest_dir = ({
   "/players/fakir/fcastle/room11.c", "east",
   "/players/fakir/fcastle/room78.c", "west",
});
}


