#include "/players/forbin/realms/keats/keatsdefine.h"
inherit "obj/treasure";

reset(arg) 
{
  if(arg) return;
  set_short(0);
  SetMultipleIds(({"church","holy church","church of the spoken sacrament",
                   "church of the spoken sacrament",
                   "holy church of the spoken sacrament",            
                   "the holy church of the spoken sacrament",
                   "window","windows","stained glass","stained glass window",
                   "stained glass windows","arch","arches","column","columns",
                   "entry","entryway","steps","roofline","gargoyle","gargoyles"}));
}

void long(string str) {
  if(str == "window" || str == "windows" || str == "stained glass" ||
     str == "stained glass window" || str == "stained glass windows")
  {
  	tell_object(this_player(),
  	  "The windows of the cathedral are a myriad of colors.  They shimmer\n"+
  	  "from light within the chuch.\n");
  }
  else if(str == "entry" || str == "entryway")
  {
  	tell_object(this_player(),
  	  "The entryway is framed by several columns and beautified by the\n"+
  	  "many arches that decorate the exterior of the church.\n");
  }  
  else if(str == "column" || str == "columns")
  {
  	tell_object(this_player(),
  	  "Seven columns stand supporting at the entryway before giving way\n"+
  	  "to sweeping arches above.\n");
  }
  else if(str == "arch" || str == "arches" || str == "archway" ||
          str == "archways")
  {
  	tell_object(this_player(),
  	  "There are scores of arches that criss-cross higher and higher as\n"+
  	  "climb the walls of the cathedral.  Near the top, they help to\n"+
  	  "support the roofline.\n");
  }
  else if(str == "roofline")
  {
  	tell_object(this_player(),
  	  "The roofline of the cathedral is gently curved and supported by\n"+
  	  "scores of arches and buttresses.  It's silver roof glistens\n"+
  	  "brightly, giving it a slick, wet look.\n");
  }    
  else if(str == "gargoyle" || str == "gargoyles")
  {
  	tell_object(this_player(),
  	  "High above the square, four stone gargoyles keep watch over the\n"+
  	  "city.  Even from this distance, they seem oddly lifelike.\n");
  }  
  else 
    tell_object(this_player(),
      "Dominating the western space of the square, "+HIW+"The Holy Church of the\n"+ 
      "Spoken Sacrament"+NORM+" is a beautiful cathedral that leads to the massive\n"+
      "enclave of the New Vatican City.  Large steps fan out from the base\n"+
      "of its entryway, while wide columns stretch thirty feet high before\n"+
      "gently curving and melding into graceful archways.  Sharp, angular\n"+
      "gargoyles perch upon the roofline hundreds of feet in the air, gazing\n"+
      "out across the square.  Scores of stained glass windows glisten and\n"+
      "sparkle in the light, giving the church a soulful, living quality.\n");
}

get() { return 0; }

init() 
{
  ::init();
  add_action("cmd_enter", "enter");
}

status cmd_enter(string str) 
{
  if(!str || (str != "church" && str != "cathedral" && 
              str != "entryway" && str != "entry")) return 0; 
  tell_object(this_player(),
    "You start up the steps toward the "+str+".\n");
  tell_room(this_object(),
    (string)this_player()->query_name()+
    " starts up the steps toward the "+str+".\n", ({ this_player() })); 
  this_player()->move_player("into the church#"+RMS+"1church01.c");     
  return 1; 
}
