inherit "/players/sado/rooms/mansion.c";

reset(arg)
{
  if (!arg) {
    set_short("Eso's Secret Garden");
    set_long("The ground slopes gently away from you toward a broad pool at the center\n"+
"of the garden.  The water is dark and rippled by the spray from a tiered\n"+
"stone fountain.  At either end of the pool a willow tree dips its fronds\n"+
"into the water.  There are rosebushes everywhere, surrounded by rich green\n"+
"lawn.  A stone walk winds its way among dark, well-kept hedges, and under\n"+
"trellises draped with flowering vines.  Stone statues lurk in shaded\n"+
"corners.  A high brick wall surrounds the garden, keeping out unwanted\n"+
"visitors.\n");
    set_dest_dir(
		 ({
	"/players/sado/rooms/workroom.c","work",
	"/players/sado/shop/shop.c","shop",
	}));
    set_items(
	      ({
      "pool","The fountain is carved from granite, cherubs clamber on Venus, the centerpiece, streams\n" +
             "of water flowing from their mouths, spraying into the dark pool at the fountain's base.\n" +
             "From the upper pool, the water flows out into lower pools, trickling slowly, but providing\n" +
             "enough oxygenation to support the carp which swim in the murky waters, eating all the mosquitos",
      "fountain","The fountain is carved from granite, cherubs clamber on Venus, the centerpiece, streams\n" +
             "of water flowing from their mouths, spraying into the dark pool at the fountain's base.\n" +
             "From the upper pool, the water flows out into lower pools, trickling slowly, but providing\n" +
             "enough oxygenation to support the carp which swim in the murky waters, eating all the mosquitos",
      "rosebushes","Blood red roses are just beginning to bud on the sprawling bushes.  The bushes run\n" +
                   "everywhere, wrapping their spiny sinews around all kinds of statues and other garden furniture",
      "roses","Blood red roses are just beginning to bud on the sprawling bushes.  The bushes run\n" +
                   "everywhere, wrapping their spiny sinews around all kinds of statues and other garden furniture",
      "hedges","The hedges for a low maze.  The path winds its way among them, meandering through the trellises and\n" +
               "open spaces, past flower beds, into little alcoves recessed into the hedges where they grow taller",
      "path","The hedges for a low maze.  The path winds its way among them, meandering through the trellises and\n" +
               "open spaces, past flower beds, into little alcoves recessed into the hedges where they grow taller",
      "statues","Most of the statuery looks like copies of ancient greek heros and gods.  Though the subjects are\n" + 
                "taken from Greek myth, the style is decidedly roman, though some of the women's clothes look more\n" +
                "modern than that era.  It's all very victorian in fact.  Neo-romanesque and romantic, combined",
      "wall","A tall brick wall surrounds the three non-mansion sides of the garden, preventing anyone from entering\n" +
             "uninvited.  A small gate in the corner of one wall, partially covered by trailing ivy, is the only exit\n" +
             "apart from heading on up into the mansion",
	}));
    set_light(1);
  }
}
