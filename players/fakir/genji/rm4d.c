inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Tower of Genji";
long_desc =
"     Level four. West room.\n";

items = ({
"room",  "A dry light room",

});

dest_dir = ({
"/players/fakir/genji/rm5e","east",
"/players/fakir/genji/rm1e","north",
"/players/fakir/genji/rm4c","west",
"/players/fakir/genji/rm7e","south",
"/players/fakir/genji/rm5a","down",


});

}
