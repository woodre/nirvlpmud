#include "/players/forbin/realms/keats/keatsdefine.h"
inherit "/players/forbin/realms/keats/room.c";

string Location;
int Open, Lock;
int Called;

reset(arg) 
{
  if(arg) return;
  Open = 0; Lock = 1; /* Vigeous Road gate closed, lock broken but in place */
  Called = 0;         /* has a guard been called to stop opening of gate? */
  short_desc = KEATS;
  Location = "Square of Sad King Billy";
  long_desc = 
    "\n                "+HIW+"The Vigeous Road"+C+"        (["+NORM+"northeast"+C+"])"+NORM+"\n"+
    "                "+HIW+"Saint Antonnius Way"+C+"     (["+NORM+"southeast"+C+"])"+NORM+"\n"+
    "                "+HIW+"The Avenue of the Word"+C+"  (["+NORM+"south"+C+"])"+NORM+"\n"+
    "                "+HIW+"The Path of the Dead"+C+"    (["+NORM+"southwest"+C+"])"+NORM+"\n"+
    "                "+HIW+"Grand Market Street"+C+"     (["+NORM+"northwest"+C+"])"+NORM+"\n"+
    "  The Great Square of Sad King Billy stretches hundreds of men across,\n"+
    "the pentagonal square marking the civic center of the City of Keats.\n"+
    "Wide, towering gates stand at each apex of the square, marking the\n"+
    "commencement of each of the five major thoroughfares inside the city.\n"+
    "A broad cobbled pathway circles the expanse of grass that makes up the\n"+
    "bulk of the plaza.  On the western edge of the square lies "+HIW+"The Holy\n"+
    "Church of the Spoken Sacrament"+NORM+", while directly across from it stands\n"+ 
    "the "+HIM+"T"+NORM+MAG+"ower of the "+HIM+"M"+NORM+MAG+"agi"+NORM+".\n";
  add_item(({"city","keats","city of keats"}),
    "The perimeter of the plaza is thickly surrounded mostly by marketplaces\n"+
    "and resturants.  The multi-storied buildings stretch skyward, blocking\n"+
    "any view of the horizon.  It's easy to imagine Keats continuing on in\n"+
    "this fashion, blossoming outward like a vibrant spring flower");
  add_item(({"gate","gates","towering gate","towering gates"}),
    "Each of the major thoroughfares pass through a massive gate on their\n"+
    "way from the square.  The surface of each gate wall is so smooth, that\n"+
    "they appear to have been carved from a single piece of marble.  Heavy\n"+
    "looking iron gates are hinged between each pillar of the gateway");
  add_item(({"thoroughfare","thoroughfares"}),
    "The five main streets in Keats all terminate or begin from the sqaure,\n"+
    "depending moslty on your point of view");  
  add_item(({"path","pathway","cobbled path","cobbled pathway"}),
    "A wide circular road has been laid in a perfect circle surcumscribed\n"+
    "within the pentagonal square.  On either side, lush grass grows,\n"+
    "delineating the boundry of buildings and plaza");
  add_item(({"grass","plaza"}),
    "The plaza is a grand pentagonal space bounded by buildings and filled\n"+
    "with a large expanse of grass.  Directly in the center is a sprawling\n"+
    "fountain which splashes and gurgles with soothing life");
  add_item("fountain",
    "Erected in the center of the grassy plaza is a large fountain.  It\n"+
    "dominates the square even as its ellipical dimensions of fifty feet\n"+
    "by twenty-three feet are dwarfed by its surroundings.  Water bubbles\n"+
    "loudly from the many spouts and fissures of the fountain while "+HIW+"The\n"+
    "Lamentation of Saint Marie of Oswego"+NORM+", sculpted in the round by the\n"+
    "master Miguel Alessandro Diaz, makes an imposing centerpiece, flanked\n"+
    "on both the east and west by towering sixty foot obelisks.");
  add_item(({"obelisk","obelisks"}),
    "Twin obelisks shoot toward the sky, their smooth stone sides carefully\n"+
    "crafted, the white marble carved square and true.  The pyramidal tops\n"+
    "shimmer and dance, reflecting light off their bronzed faces.");
  add_item(({"sculpture","lamentation","saint","marie","saint marie",
            "saint marie of oswego","lametation","lametation of marie",
            "lametation of saint marie","lamentation of saint",
            "lamentation of saint marie of oswego"}),
    "This wonderful sculpture shows Marie of Oswego, then a nun, later a saint, in\n"+
    "tremendous sorrow.  Kneeling before a great demonic creature, tears streak\n"+
    "her cheeks even as her face is uplifted heavenward.  Her hands are upturned\n"+
    "towards the sky, palms near her mouth in an obvious sign of horror.  The vile\n"+
    "creature towers over her, its body aflame.  In one hand it holds a sphere,\n"+
    "while in the other, a burning spear that points westward");
  add_item(({"the vigeous road","vigeous road","road"}),
    "The Vigeous road begins in the northeast part of the square and heads off\n"+
    "toward what used to be the home of the city's monarch.  Since the death of\n"+
    "Sad King Billy, there has been no king nor queen; instead the City of Keats\n"+
    "is controlled by the Church.  A wrought iron door is closed at its gate\n");    
  add_item(({"saint antonnius way","antonnius way","way"}),
    "Saint Antonnius II was the second Pope Fleet Admiral of the Church after the\n"+
    "Fall of Earth.  A great thinker, he laid much of the groundwork for the Church's\n"+
    "eventually domination of universal politics.  His namesake road traces a rather\n"+
    "circuitious route through the city's southern riones, visiting many holy sites");
  add_item(({"the avenue of the word","avenue","avenue of the word","avenue of word"}),
    "The Avenue of the Word runs south from the square, taking travellers to and\n"+
    "from this great city");
  add_item(({"the path of the dead","path","path of the dead","path of dead"}),
    "The Path of the Dead once held a much more tranquil name, but since the Great\n"+
    "Conflagration swept through Keats several decades ago, it has become a haven\n"+
    "for the undead.  It was soon both renamed and avoided by the locals");
  add_item(({"grand market street","market street","street"}),
    "In the northeast, a wide street begins, leading into the City's main market\n"+
    "area.  Just beyond its gate stands shops and vendors of all sorts");
  add_exit(RMS+"1vigeous01.c", "northeast");
  add_exit(RMS+"1antonius01.c", "southeast");
  add_exit(RMS+"1word01.c", "south");
  add_exit(RMS+"1morti01.c", "southwest");
  add_exit(RMS+"1market01.c", "northwest");
  add_object("/players/forbin/mages/obj/tower.c");
  add_object("/players/forbin/realms/keats/OBJ/church.c");
  set_light(1);
}

init() 
{
  ::init();
  add_action("cmd_ne", "northeast");
  add_action("cmd_ne", "ne");
  add_action("cmd_block", "southeast");
  add_action("cmd_block", "se");
  add_action("cmd_block", "southwest");
  add_action("cmd_block", "sw");
  add_action("cmd_block", "northwest");
  add_action("cmd_block", "nw");  
  add_action("cmd_open_and_close", "open");
  add_action("cmd_open_and_close", "close");
  add_action("cmd_remove", "remove");  
}

status cmd_block() 
{
    tell_object(this_player(),
      "A guard informs you: \"Sorry.  Closed for construction.\"\n");
    return 1; 
}

status cmd_ne() 
{
  if(!Open)
  {
    tell_object(this_player(),
      "The gateway leading to "+HIW+"The Vigeous Road"+NORM+" is closed.\n");
    return 1; 
  }
}

status cmd_open_and_close(string arg)
{
  
}

status cmd_remove(string arg)
{
  
}