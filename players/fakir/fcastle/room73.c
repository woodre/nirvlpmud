inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Outer Ward";
long_desc =
"   The ancient wall of the castle rises high above your left\n"+
"shoulder. Waist high ramparts form a short defensive wall to\n"+
"the right, and give a good view of the western approach to the\n"+
"castle wall.  Just ahead, a two-story guard tower overlooks\n"+
"this area of the castle's outer ward, as well as the entire\n"+
"southern ward.  You are standing on the western ward, facing\n"+
"south.\n";

items = ({
"shoulder",   "Its YOUR shoulder....don't you know what it looks like?",
"wall",       "Thick grey stone with very fine joints. Not even a knife\n"+
              "blade could slide between the individual stones",
"castle",     "Built in some former age of magic, its stone walls shine\n"+
              "with a dim glimmer of residual magic",
"ramparts",   "Raised portions of the southern defensive wall which makes\n"+
              "up the southern ward of the castle.  Archers and pikemen\n"+
              "use the ramparts for cover in case of an attack",
"drawbridge", "You cannot see it from here unless you peek over the ramparts",
"tower",      "A two story tower with small slit type windows, built as a\n"+
              "defensive haven for the guards in case the outer ward becomes\n"+
              "overrun by attackers",
"ward",       "The defensive walkway and battlement that surrounds the entire\n"+
              "castle.  Built twenty feet from ground level, it affords a good\n"+
              "view of the surrounding countryside, and a very effective means of\n"+
              "defending the castle. You are standing on the western ward, facing"+
              "south",
});
if(!present("trolloc",this_object()))
 move_object(clone_object("/players/fakir/woods/TEMP/trolloc4.c"),this_object());

dest_dir = ({
   "/players/fakir/fcastle/room20.c", "south",
   "/players/fakir/fcastle/room5.c",  "north",
});
}


