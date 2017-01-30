inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Tower of Genji";
long_desc =
"     Level four. Southwest room.\n";

items = ({
"room",  "A dry light room",

});

dest_dir = ({
"/players/fakir/genji/rm5e","northeast",
"/players/fakir/genji/rm4e","north",
"/players/fakir/genji/rm8e","east",
"/players/fakir/genji/rm7e","west",
"/players/fakir/genji/rm5a","down",


});

}
