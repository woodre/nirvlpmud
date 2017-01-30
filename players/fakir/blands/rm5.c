inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Village Road";
long_desc =
"     The village road continues toward the town of Two Rivers\n"+
"as it follows the twisting east bank of the river Taren and forks\n"+
"to the north.  Southwest as the river flows leads to Taren Ferry.\n"+
"The fork east is for the most part unused and overgrown with grass\n"+
"and tall weeds.\n";

items = ({
"road",  "A dry and dusty road with deep wheel ruts running down the middle",
"bank",  "The river bank is steep and deep here.  Small trees line the\n"+
         "the edge where it drops off to the rushing waters below",
"river", "The river narrows here and rapids flow over large boulders",
"fork",  "A fork in the road to the north and east",
"grass", "Tall broadleaf grass with a heavy stalk",
"weeds", "Milkweed and cowtail for the most part",

});

dest_dir = ({
"/players/fakir/blands/rm6","north",
"/players/fakir/blands/rm4","southwest",
"/players/fakir/blands/rm36","east",

});

}
