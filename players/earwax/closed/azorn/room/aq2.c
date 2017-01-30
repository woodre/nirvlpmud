/*
 *      File:                   /players/earwax/closed/azorn/room/aq2
 *      Function:               
 *      Author(s):              Earwax@Nirvana
 *      Copyright:              Copyright (c) 2005 Earwax/David Halek
 *                                      All Rights Reserved.
 *      Source:                 10/21/2005
 *      Notes:                  
 *      Change History:
 */

#include "../defs.h" 
#define SEARCHCAP 3

inherit ROOM; /* ~closed/azorn/room/room.c */

int FSearches, CSearches;

void 
reset(status arg)
{
	::reset(arg);
	FSearches = CSearches = 0;
	
	if (arg)
	  return;
	
	short_desc = HIK+"Acolyte Quarters"+NORM;
	long_desc = HIK
    + "This would appear to be a berthing area for the acolytes of the Cult\n"
    + "of Azorn.  There are dozens of cots in here, each with a footlocker\n"
    + "at the end closest to the center of the room.  The quarters continue\n"
    + "to the north and south.  The exit from the quarters is to the east.\n"
    + NORM;
  dest_dir = ({ 
	  RPATH+"aq3.c", "north",
	  RPATH+"aq1.c", "south",
	  RPATH+"h1.c", "east",
    });
  items = ({
	  "acolytes", "The acolytes sleep here",
	  "area", "It's a berthing area",
	  "cots", "There are dozens of them all identical",
	  "door", "It simply looks heavy-duty",
	  "quarters", "These quarters extend to the north from here",
	  "footlockers", "There are many of them, perhaps there is something in one",
	  "footlocker", "There are many footlockers, perhaps there is something in one",
	  "exit", "It's to the east."
  });
}


/* 
 * Function name:  on_search
 * Description:    Search footlockers and cots, randomly generate loot
 *                 search_results() is in the room inherit.
 * Arguments:      arg - given by player as what to search
 * Returns:        0 for failure, 1 for success
 */

status on_search(string arg)
{
	if ((object)this_player()->query_attack())
	{
		write("Searching while under attack would be rather unwise.\n");
		return 1;
	}
	if (arg == "footlocker" || arg == "footlockers")
  {
	  if (FSearches >= SEARCHCAP)
	  {
	    write("You've already searched all the footlockers.\n");
	    return 1;
    }
	    
	  write("You search through some footlockers...\n");
	  say((string)this_player()->query_name()+" searches through some footlockers.\n");
	  search_results("footlocker");
	  FSearches++;
	  return 1;
  }
	if (arg == "cot" || arg == "cots")
  {
	  if (CSearches >= SEARCHCAP)
	  {
	    write("You've already searched all the cots.\n");
	    return 1;
    }
	    
	  write("You search through some cots...\n");
	  say((string)this_player()->query_name()+" searches through some cots.\n");
	  search_results("cot");
	  CSearches++;
	  return 1;
  }
  return 0; /* Use regular search results now. */
}
