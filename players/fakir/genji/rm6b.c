inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Tower of Genji";
long_desc =
"     Level two. East room.\n";

items = ({
"room",  "A dry light room",

});

dest_dir = ({
"/players/fakir/genji/rm5c","west",
"/players/fakir/genji/rm3c","north",
"/players/fakir/genji/rm9c","south",
"/players/fakir/genji/rm6c","east",



});

}
