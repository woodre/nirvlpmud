inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = "Tower of Genji";
long_desc =
"     Level three. West room.\n";

items = ({
"room",  "A dry light room",

});

dest_dir = ({
"/players/fakir/genji/rm5d","east",
"/players/fakir/genji/rm1d","north",
"/players/fakir/genji/rm4b","west",
"/players/fakir/genji/rm7d","south",


});

}
