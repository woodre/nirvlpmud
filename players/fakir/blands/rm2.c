inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Beezers Ferry";
long_desc =
"     The village road to the town of Two Rivers winds along\n"+
"the twisting east bank of the river Taren and leads off to\n"+
"the northeast and south.  Eastward lies the road to Taren Ferry.\n"+
"An old but serviceable platform ferry rests against the bank of\n"+
"the river.  A thick hemp rope is tied off to a massive tree\n"+
"stump and runs from the east bank to the western shore of the river.\n";

items = ({
"road",  "A dry and dusty road with wheel ruts running down the middle",
"bank",  "A two foot bank of moist mud and round stones drops to the\n"+
         "level of the rivers gentle flow.  Signs of errosion are evident",
"river", "The river Taren.  Its waters are clear and cold",
"ferry", "Constructed of rough hewn logs of timber with a plank\n"+
         "platform lashed to the top.  A thick hemp rope runs\n"+
         "through huge loops of iron mounted to one side",
"rope",  "Braided from thick strands of hemp, it is heavily waxed",
"stump", "The cut trunk of a once huge oak tree",
"shore", "The opposite bank of the river, a good two stones throw away",

});

dest_dir = ({
"/players/fakir/blands/rm3","northeast",
"/players/fakir/blands/rm1","south",

});

}
