/*
 *      File:                   /players/earwax/closed/azorn/lib/room.c
 *      Function:               Inherit for Azorn quest area rooms
 *      Author(s):              Earwax@Nirvana
 *      Copyright:              Copyright (c) 2005 Earwax/David Halek
 *                                      All Rights Reserved.
 *      Source:                 10/21/2005
 *      Notes:                  
 *      Change History:
 */

#include "../defs.h"
inherit "/room/room.c";

void set_short(string arg) { short_desc = HIK+arg+" "+NORM; }

/* 
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 */

void reset(status arg)
{
	::reset(arg);
	
	if (arg)
	  return;

}
	  

