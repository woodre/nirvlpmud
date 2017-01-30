inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Village Road";
long_desc =
"     The village road enters the small town of Two Rivers and\n"+
"continues north up the east bank of the river Taren.  The red\n"+
"roof of the Winespring Inn is visble to the northeast.  A small\n"+
"but tidy home is directly east behind a picket fence.  The road\n"+
"follows the flow of the river southwest toward Taren Ferry.\n";

items = ({
"road",  "A dry and dusty road with deep wheel ruts running down the middle",
"bank",  "The river bank is steep and deep here.  Small trees line the\n"+
         "the edge where it drops off to the rushing waters below",
"river", "The river begins to narrow here somewhat",
"roof",  "The red tile roof of the Winespring Inn",
"home",  "The home of the village wisdom. There is a small sign over the door",
"sign",  "HEALS, REMEDIES AND POTIONS AVAILABLE HERE",
"fence", "A three foot tall picket fence. It is painted white. A wide\n"+
         "gate is proped open with a forked stick so any may enter",
});

dest_dir = ({
"/players/fakir/blands/rm7","north",
"/players/fakir/blands/rm5","south",
"/players/fakir/blands/rm36","east",

});

}
