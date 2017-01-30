inherit"/room/room";
#include <ansi.h>
 
reset(arg)
{
::reset(arg);
if(arg)return;
if(!present("plucky", this_object()))move_object(clone_object("/players/wicket/tv/looney/mobs/plucky.c"), this_object());  
set_light(1);
  short_desc = GRN+"Plucky"+NORM+" the "+GRN+"Duck"+NORM+"\' "+GRN+"s"+NORM+" House"+NORM;
  long_desc = " A small cute house with the walls a soft blue color and well lit. All\n\
  the trim is a pasty white color around the house. Furniture made of reeds\n\
  and bamboo fills the house. A normal small bed that is also built of bamboo\n\
  by the window. The television softly glows from the corner of the room.\n\
  Pictures of the family are hung all over the wall as well as a picture,\n\
  of Plucky\'s woman Shirley. A small table made of wood sits against one of\n\
  the far walls with four wooden chairs around it. Sounds of nature can be\n\
  heard all though out the house.\n";
  items = 
  ({
    "table",
    "A small simple wooden table with four chairs arranged around it",
    "bed",
    "A small bamboo bed with a blanket neatly place on it",
    "television",
    "A tv with nothing on it but a fuzzy picture",
    "walls",
    "Soft blue colored walls with a pasty white trim",
    "furniture",
    "All kinds of furniture thats made of reeds that have been tied together",
    "bed",
    "A small bed made of bamboo that is tied together with added leaves for padding",
    "picture",
    "A picture of Shirley hangs on the wall next to the family portrait of plucky\'s family",
    "portrait",
    "A family portrait of Plucky\'s Family",
    "chairs",
    "A small cluster of chairs arranged around the wooden table",
     });
       dest_dir=({
  "/players/wicket/tv/looney/rooms/pond.c","south",
  "/players/wicket/tv/looney/rooms/toonroad3.c","west",
  });
  }