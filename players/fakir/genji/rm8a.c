inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Tower of Genji";
long_desc =
"     Level one. South room.\n";

items = ({
"room",  "A dry light room",

});

dest_dir = ({
"/players/fakir/genji/rm5b","north",
"/players/fakir/genji/rm7b","west",
"/players/fakir/genji/rm9b","east",

});

}
