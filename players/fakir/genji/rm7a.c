inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Tower of Genji";
long_desc =
"     Level one. Southwest room.\n";

items = ({
"room",  "A dry light room",

});

dest_dir = ({
"/players/fakir/genji/rm5b","northeast",
"/players/fakir/genji/rm4b","north",
"/players/fakir/genji/rm8b","east",

});

}
