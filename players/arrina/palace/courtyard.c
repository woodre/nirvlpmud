inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(1);
    short_desc = "Courtyard Ballroom";

    long_desc =
   "You are in an ethereal courtyard that serves as a ballroom.\n"+  
   "At the northern end of the courtyard is a garden and pond lit\n"+ 
   "in the nighttime air by the dazzling glow of fireflies. The center\n"+  
   "of the pond contains a small island with a weeping willow tree.\n"+ 
   "Running through the courtyard is a winding stone path, leading\n"+ 
   "from the great gateway in the northern wall to the massive double\n"+ 
   "doors to the west and south. Running above the courtyard from\n"+ 
   "the south wall is a marble walkway that leads to a balcony to the\n"+ 
   "north and disappears into a small archway. A gathering area\n"+
   "is set before the eastern wall, which contains tall stained glass\n"+
   "windows lit from behind with an unearthly fire.\n";

  items = ({
   "garden","The garden is filled with rare flowers of many vibrant colors",
   "pond","The pond reflects the dancing light of the fireflies.  Yet other\n"+
   "dim lights are faintly visible deep within the water",
   "island","From a small island in the center of the pond grows a weeping\n"+ 
   "willow tree",
   "tree","As you look at the tree you think you hear the faint notes of a\n"+
   "flute and the distant laughter of mischievous voices",
   "path","The winding stone path leads from the gateway to two sets of\n"+
   "double doors to the west and south",
   "gate","A giant gateway lies at the northern end of the courtyard",
   "walkway","A marble walkway crosses above you, extending from the\n"+
   "south wall to an archway in the opposite wall over the gateway",
   "glass","You look at the chapel's stained glass windows from the outside.\n"+
   "An image spanning all the windows becomes visible that is not\n"+
   "apparent from within the chapel. You see the figure of a kneeling\n"+ 
   "Paladin with his sword raised above him toward the moon.\n"+
   "The figure is outlined by the shimmering glow of fire",
   "windows","You look at the chapel's stained glass windows from the outside.\n"+
   "An image spanning all the windows becomes visible that is not\n"+
   "apparent from within the chapel. You see the figure of a kneeling\n"+ 
   "Paladin with his sword raised above him toward the moon.\n"+
   "The figure is outlined by the shimmering glow of fire",
   "fire","You look at the chapel's stained glass windows from the outside.\n"+
   "An image spanning all the windows becomes visible that is not\n"+
   "apparent from within the chapel. You see the figure of a kneeling\n"+ 
   "Paladin with his sword raised above him toward the moon.\n"+
   "The figure is outlined by the shimmering glow of fire",
   "sprites","From the corner of your eye you faintly perceive small ethereal\n"+
   "figures dancing to the music of a flute",
   "faeries","From the corner of your eye you faintly perceive small ethereal\n"+
   "figures dancing to the music of a flute",
  });

  dest_dir = ({
    "/players/arrina/palace/gateway.c","north",
    "/players/arrina/palace/entry.c","south",
    "/players/arrina/palace/feasthall.c","west",
  });
} }
