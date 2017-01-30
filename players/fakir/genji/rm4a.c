inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Tower of Genji";
long_desc =
"     Level one. West room.\n";

items = ({
"room",  "A dry light room",

});

dest_dir = ({
"/players/fakir/genji/rm5b","east",
"/players/fakir/genji/rm1b","north",
"/players/fakir/genji/rm7b","south",

});

}
