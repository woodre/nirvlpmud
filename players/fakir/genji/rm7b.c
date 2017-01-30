inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Tower of Genji";
long_desc =
"     Level two. Southwest room.\n";

items = ({
"room",  "A dry light room",

});

dest_dir = ({
"/players/fakir/genji/rm5c","northeast",
"/players/fakir/genji/rm4c","north",
"/players/fakir/genji/rm8c","east",
"/players/fakir/genji/rm7a","west",


});

}
