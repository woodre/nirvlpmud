#include <ansi.h>

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = "Gas City";
  long_desc =
"  Welcome to Gas City. Under the guidance of Mayor Bob Ray this\n\
has become a very prosperous town. It was built along the Scenic\n\
Mississinewa River, which foster growth and security. It is a quaint,\n\
quiet, safe, secure and friendly town to over 8000 people. This town\n\
is strategically located along the I-69 corridor.\n";
 
  items =
  ({
  "Gas City",
"A town that carries many shadows",
  "mayor",
"Bob Ray",
  "bob ray",
"Bob Ray has been the Mayor of Gas City for over 23 years.\n\
He was the main contractor who built a majority of the original\n\
town. He has a three story house on main street.He is also a\n\
member of the Masons, and has had several presidents stay in\n\
his house.",
  "river",
"It is a nice flowing river. Many people like to tube down it\n\
in the summer.",
  "people",
"Towns people",
  "i-69",
"a corridor that the federal government wants to extend from\n\
Indiana to Texas",
  "town",
"A place where people live, it is lively",
  "house",
"An elegant three story home",
  "Masons",
"An organization derived from the ancient knights templar",
  "shadows",
"Dark secrets",
  "corridor",
"A large and long stretch of road",
  "road",
"what you drive on, a paved road",    
});
  dest_dir =
  ({
"/players/angel/area/school/room/town", "heli",	  
"/room/lanceroad3", "exit",	
  });
}
