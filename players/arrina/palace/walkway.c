inherit "room/room";
reset(arg) {
   if(!arg) {
   set_light(1);
      short_desc = "Courtyard Walkway";

      long_desc =
     "You are on a marble walkway that gently slopes upward to a\n"+ 
     "balcony and archway to the north. You overlook a grand\n"+ 
     "outdoor ballroom. As you look down you see the faint image\n"+ 
     "of sprites and faeries dancing beneath a willow tree on a small\n"+
     "island in a pond.  A stone path winds through the courtyard\n";

   items = ({
     "garden","The garden is filled with rare flowers of many vibrant colors",
     "pond","The pond reflects the dancing light of the fireflies",
     "island","From a small island in the center of the pond grows a\n"+
     "weeping willow tree",
     "tree","The tall willow's branches droop over the pond surrounding it",
     "path","The winding stone path leads from one end of the courtyard\n"+
     "to the other",
     "gate","A giant gateway lies at the northern end of the courtyard",
     "walkway","You are on a marble walkway above the outdoor ballroom",
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
     "sky","The moon is full and glows brightly above you",
     "moon","The moon is full and glows brightly above you",
     "sprites","From this vantage point you see small ethereal figures\n"+ 
     "dancing to unheard music",
     "faeries","From this vantage point you see small ethereal figures\n"+ 
     "dancing to unheard music",
  });

  dest_dir = ({
      "/players/arrina/palace/balcony.c","north",
      "/players/arrina/palace/entry.c","south",
  });
} }

