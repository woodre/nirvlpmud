#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Winespring Inn";
long_desc =
   "An empty table sits waiting to accomodate the next hungry traveller.\n"+
   "An oil lamp casts flickering shadows on the table top which dart and\n"+
   "weave between the cracks of the wood.  A massive bar runs the length\n"+
   "of the wall to the north and a grey slate fireplace covers the entire\n"+
   "far, south wall.  A gleeman sometimes does magic tricks for drinks and\n"+
   "tips to the southwest.\n";

items = ({
   "fireplace", "Grey slate embedded in red mortar covers the entire wall\n"+
                "from floor to ceiling.  The slate is irregular and has fossil\n"+
                "leaves and insects etched in its rough surface from place to\n"+
                "place.  The slate has been set with great care by a master\n"+
                "craftsman, perhaps even an ogier",
   "lamp",      "A small oil lamp made from blown glass with an open wick",
   "top",       "The top of a well built wooden table",
   "bar",       "Solid and well built, it spans the entire north wall of the inn",
   "wood",      "It is so deeply stained you cannot tell what type of wood it is",
   "gleeman",   "With wispy white hair and bushy eyebrows and mustache to match\n"+
                "the gleeman gestures imperiously at those in the room while\n"+
                "pulling multicolored flowers from thin air.  Sparkling blue eyes\n"+
                "peer out of a wrinkled face that seems to belong more to a gnarled\n"+
                "tree that had seen hard times.  The eyes are piercing, and look\n"+
                "deep into your soul.  The multicolored cloak he wears has odd baggy\n"+
                "sleeves and big pockets inside and out",  
   "table",     "Several spans long and a third as wide, it stands on four legs\n"+
                "of sturdy hewn timber six snitches square.  Its top is thick\n"+
                "as well, and is stained a rich dark brown from the grease and\n"+
                "spilled drinks",
   "wall",      "Covered entirely by a grey slate fireplace to the south and a bar north",
   "cracks",    "Running the length of the table they get larger with the passing of time", 
   
});

dest_dir = ({
   "/players/fakir/inn/room16.c", "north",
   "/players/fakir/inn/room14.c", "south",
   "/players/fakir/inn/room8.c",  "west",
   "/players/fakir/inn/room7.c",  "northwest",
   "/players/fakir/inn/room9.c",  "southwest",
});

}
