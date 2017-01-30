#include <ansi.h>

inherit "room/room";

int x;

reset(arg)
{
  ::reset(arg);
  if( !present("anakin", this_object()) )
    move_object(clone_object("/players/angel/area/walmart/npc/anakin.c"), this_object());  
  if( !present("yoda", this_object()) )
  {
    for(x=0; x<1; x++)
    {
    move_object(clone_object("/players/angel/area/walmart/npc/yoda.c"), this_object());
    }
}
if(arg) return;
  set_light(1);
  short_desc = HIB+"Toy department"+NORM;
  long_desc =
"   "+HIB+"Toy Department"+NORM+"\n\
  Welcome to the Wal-Mart Toyland! Find the biggest selection of\n\
most-wanted holiday toys for every boy and girl on your list. We\n\
have Eight trucks a-truckin', nine Dora's dancing, ten Tigger's\n\
tumbling! Shop here for the 12 Toys of Christmas toppings on every\n\
kid's wish list. We're the source for the latest in technology,\n\
from digital cameras to televisions to boomboxes. The cutting edge\n\
of cool, the vixens of vogue, unleash their inner diva with fabulous\n\
new BRATZ dolls, toys, and accessories. Have fun shopping!\n";

  items =
  ({
    "walmart",
    "Wal-Mart is a large retailer bent on overtaking the world!",
    "toyland",
    "A section of the store where all toy are sold",
    "holiday",
    "A religious feast day, a holy day",
    "toy",
    "An object for children to play with",
    "toys",
    "An object for children to play with",
    "boy",
    "A human male child",
    "girl",
    "A human female child",
    "list",
    "Compiling of information together",
    "trucks",
    "A vehicle used to haul stuff",
    "dora",
    "A cartoon figure",
    "tigger",
    "A cartoon figure",
    "kid",
    "A adolescent human",
    "kids",
    "Adolescent humans",
    "technology",
    "The application of science to create industrial or commercial objectives",
    "cameras",
    "An apparatus for taking photographs",
    "television",
    "An electronic apparatus that receives electromagnetic\n\
waves and displays the reconverted images on a screen",
    "boombox",
    "A portable stereo",
    "diva",
    "A very successful singer",
    "bratz",
    "A cartoon figure",
    "doll",
    "A child's small toy that has the likeness of a human",
    "accessories",
    "Something nonessential but desirable that contributes to an\n\
effect or result",

  });
  dest_dir =
  ({
   	"/players/angel/area/walmart/room/hardlines", "hardlines",
  });
}

init() {
  ::init();
    add_action("stop","hardlines",1);
    add_action("disallow","quit");
}

  stop() {
    if(present("anakin", environment(this_player())))
{write("Anakin uses the force and you are smashed against the wall as you try to escape.\n");
say(this_player()->query_name()+" is smashed against the wall as they try to escape.\n");
        return 1;
}}

  disallow() {
    if(present("anakin", environment(this_player())))
      if(this_player()->query_ghost() == 1) { return 0; }
      else{
      write("You can't quit from here.\n");
        return 1; }
}

realm(){ return "NT"; }
