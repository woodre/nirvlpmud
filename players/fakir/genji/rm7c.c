inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = "Tower of Genji";
long_desc =
"     Level three. Southwest room.\n";

items = ({
"room",  "A dry light room",

});

dest_dir = ({
"/players/fakir/genji/rm5d","northeast",
"/players/fakir/genji/rm4d","north",
"/players/fakir/genji/rm8d","east",
"/players/fakir/genji/rm7b","west",


});

}
