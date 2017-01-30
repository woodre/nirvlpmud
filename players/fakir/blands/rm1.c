inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Village Road";
long_desc =
"     The village road to the town of Two Rivers winds along\n"+
"the twisting east bank of the river Taren and leads off to\n"+
"the north and south.\n";

items = ({
"road",  "A dry and dusty road with wheel ruts running down the middle",
"bank",  "A two foot bank of moist mud and round stones drops to the\n"+
         "level of the rivers gentle flow.  Signs of errosion are evident",
"river", "The river Taren.  Its waters are clear and cold",

});

dest_dir = ({
"/players/fakir/blands/rm2","north",
"/players/fakir/blands/rm0","south",

});

}
