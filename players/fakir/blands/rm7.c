inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Village Road";
long_desc =
"     The village road continues north up the east bank of the\n"+
"river Taren as well as south toward Taren Ferry.  The village\n"+
"inn is visble to the east.  Small shrubs and bushes grow along\n"+
"the bank of the river hiding it from view.\n";

items = ({
"road",  "A dry and dusty road with deep wheel ruts running down the middle",
"bank",  "The river bank is is hidden here by small shrubs and bushes",
"river", "The river is hidden from view by small shrubs and bushes",
"inn",   "The Winespring Inn, gathering place for the townsfolk",
"shrubs","Green, leafy, low growing shrubs of a wild native variety",
"bushes","Small green leaves cover the branches of each bush...\n"+
         "A small opening is visible and could perhaps be a trail\n"+
         "to the river bank.  You might be able to 'push' through",

});

dest_dir = ({
"/players/fakir/blands/rm8","north",
"/players/fakir/blands/rm6","south",
"/players/fakir/inn/room1","east",

});

}
