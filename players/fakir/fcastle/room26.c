inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Outer Ward";
long_desc =
"   The northeast corner of the castle rises high above.  A two-\n"+
"story guard tower overlooks the north and east wards.  Chest\n"+
"high ramparts form short defensive walls running west and south,\n"+
"and give good views of the northern and eastern approach to the\n"+
"castle.\n";

items = ({
"corner",     "Where the north and east wards meet, at the northeast corner\n"+
              "of the castle", 
"walls",      "Thick grey stone with very fine joints. Not even a knife\n"+
              "blade could slide between the individual stones",
"castle",     "Built in some former age of magic, its stone walls shine\n"+
              "with a dim glimmer of residual magic",
"ramparts",   "Raised portions of the southern defensive wall which makes\n"+
              "up the southern ward of the castle.  Archers and pikemen\n"+
              "use the ramparts for cover in case of an attack",
"drawbridge", "You cannot see it from here unless you peek over the ramparts",
"tower",      "A two story tower with small slit type windows, built as a\n"+
              "defensive haven for the guards in case the outer ward becomes\n"+
              "overrun by attackers.  The tower door has been left open",
"ward",       "The defensive walkway and battlement that surrounds the entire\n"+
              "castle.  Built twenty feet from ground level, it affords a good\n"+
              "view of the surrounding countryside, and a very effective means of\n"+
              "defending the castle. You are standing at the northeast corner of\n"+
              "the castle ward",
});
if(!present("trolloc",this_object()))
 move_object(clone_object("/players/fakir/woods/TEMP/trolloc4.c"),this_object());

dest_dir = ({
   "/players/fakir/fcastle/room12.c", "south",
   "/players/fakir/fcastle/room79.c", "west",
   "/players/fakir/fcastle/room27.c", "tower",
});
}


