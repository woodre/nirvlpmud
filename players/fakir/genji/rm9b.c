inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Tower of Genji";
long_desc =
"     Level two. Southeast room.\n";

items = ({
"room",  "A dry light room",

});

dest_dir = ({
"/players/fakir/genji/rm5c","northwest",
"/players/fakir/genji/rm8c","west",
"/players/fakir/genji/rm6c","north",
"/players/fakir/genji/rm9c","east",



});

}
