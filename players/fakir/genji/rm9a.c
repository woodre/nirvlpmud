inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Tower of Genji";
long_desc =
"     Level one. Southeast room.\n";

items = ({
"room",  "A dry light room",

});

dest_dir = ({
"/players/fakir/genji/rm5b","northwest",
"/players/fakir/genji/rm8b","west",
"/players/fakir/genji/rm6b","north",

});

}
