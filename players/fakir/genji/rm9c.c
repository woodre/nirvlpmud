inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = "Tower of Genji";
long_desc =
"     Level three. Southeast room.\n";

items = ({
"room",  "A dry light room",

});

dest_dir = ({
"/players/fakir/genji/rm5d","northwest",
"/players/fakir/genji/rm8d","west",
"/players/fakir/genji/rm6d","north",
"/players/fakir/genji/rm9d","east",



});

}
