#include "../def.h"
inherit "/players/forbin/closed/std/room.c";

string Location;

reset(arg) 
{
  if(arg) return;
  short_desc = TOWER;
  Location = "Grand Foyer";
  long_desc = 
    "  The pitch darkness seems to close in.  Barely able to see more than\n"+
    "a few inches, the features of the dark room are impossible to make out\n"+
    "in such utter gloom.  Swirling darker and darker, the sinister\n"+
    "murkiness appears to moves with a life of its own.\n";
  set_light(1);
  add_item(({"dark","darkness","feature","features","room","gloom",
             "murkiness","area","place","here","around","cave","caves",
             "pitch","path","pitch darkness"}),
    "You can't see anything in this darkness...");  
  set_chance(random(5));
    add_msg("Did something just brush past you?");
    add_msg("The darkness seems to close in on you...");
    add_msg("You tremble with fear...");
    add_msg("You hear a shrill scratching further into the blackness...");
    add_msg("You spin around, swearing that something just breathed on your neck...");
    add_msg("An mournful wail fills your head...");
    add_msg("You hear something move just ahead in the darkness...");
    add_msg("Shadows swirl about the room...");
    add_msg("A dark wind whistles through the area...\n");
  add_listen("main", 
    "You listen closely and hear a slight scream.\n");
  add_listen("scream",
    "From deeper within the caves you hear a bloodcurddling scream.\n");
  add_smell("main", "You smell the acrid stench of sulfar.\n"); 
}

query_magetower() { return 1; }

short() 
{ 
  int i;
  string sh;
  if(set_light(0) > 0) 
  { 
    if(this_player()) 
    {
      if(!environment(this_player())->query_magetower() &&
        this_player()->query_level() < 40) 
        return TOWER; 
      else 
        return short_desc+SGC+" ["+TGC+Location+SGC+"]"+NORM; 
    }
    else
      return short_desc;   
  }
  else 
    return "Dark room";     
}
