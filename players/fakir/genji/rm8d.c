inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Tower of Genji";
long_desc =
"     Level four. South room.\n";

items = ({
"room",  "A dry light room",

});

dest_dir = ({
"/players/fakir/genji/rm5e","north",
"/players/fakir/genji/rm7e","west",
"/players/fakir/genji/rm9e","east",
"/players/fakir/genji/rm5a","down",



});

}