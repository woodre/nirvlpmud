inherit "room/room";
int i;

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = "A blood vessel";
long_desc =
  "  Swirling red liquid, rich with oxygen swished by back and forth carrying\n"+
  "vital nutrients to the rest of the body.\n";

items = ({
  "liquid","Oxygen rich blood flowing by",
  "nutrients","Oxygen and minerals needed elsewhere in the body",
});

dest_dir = ({
  "players/eurale/Hippo/liver","liver",
  "players/eurale/Hippo/thin_colon3","colon",
  "players/eurale/Hippo/blood3","up",
  "players/eurale/Hippo/blood5","down",
});

}
