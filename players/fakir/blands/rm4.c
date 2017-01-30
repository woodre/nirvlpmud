inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Village Road";
long_desc =
"     The village road to the town of Two Rivers winds along\n"+
"the twisting east bank of the river Taren and leads off to\n"+
"the northeast and southwest.  A merchant from Tar Valon has\n"+
"drawn his wagon off the road to the east and set up shop.\n";

items = ({
"road",  "A dry and dusty road with wheel ruts running down the middle",
"bank",  "A two foot bank of moist mud and round stones drops to the\n"+
         "level of the rivers gentle flow.  Signs of errosion are evident",
"river", "The river Taren.  Its waters are clear and cold",
"merchant", "He is wearing brightly colored clothing and a tall felt hat",
"wagon", "A four wheeled merchant's wagon with cloth sides and a wooden roof",

});

dest_dir = ({
"/players/fakir/blands/rm5","northeast",
"/players/fakir/blands/rm3","southwest",

});

}
