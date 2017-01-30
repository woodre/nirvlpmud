inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Village Road";
long_desc =
"     The village road to the town of Two Rivers winds along\n"+
"the twisting east bank of the river Taren and leads off to\n"+
"the northeast and southwest.  East is a small trading post.\n";

items = ({
"road",  "A dry and dusty road with wheel ruts running down the middle",
"bank",  "A two foot bank of moist mud and round stones drops to the\n"+
         "level of the rivers gentle flow.  Signs of errosion are evident",
"river", "The river Taren.  Its waters are clear and cold",
"trading post", "A wooden cabin of full cut timbers with most of the\n"+
                "bark removed or rotted away.  Smoke rises from the\n"+
                "top of a poorly built chimney of round river stones",

});

dest_dir = ({
"/players/fakir/blands/rm4","northeast",
"/players/fakir/blands/rm2","southwest",

});

}
