inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Tower of Genji";
long_desc =
"     Level two. West room.\n";

items = ({
"room",  "A dry light room",

});

dest_dir = ({
"/players/fakir/genji/rm5c","east",
"/players/fakir/genji/rm1c","north",
"/players/fakir/genji/rm4a","west",
"/players/fakir/genji/rm7c","south",


});

}
