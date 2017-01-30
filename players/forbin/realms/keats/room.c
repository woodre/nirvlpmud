/*
 *  Created:      Forbin@Nirvana
 *  Copyright:    Copyright (c) 2004 Forbin
 *                  All Rights Reserved.
 *  Function:     Room inherit for City of Keats area
 *  Create Date:  2004.06.12
 *  Last Edit:    2004.06.12 -Forbin
 *  Notes:        Sets the standard Keats short()
 *  Notable Changes:
 */

#include "/players/forbin/realms/keats/keatsdefine.h"
inherit "/players/forbin/closed/std/room.c";

string Location;

short() { 
  return (Location ? KEATS+" "+C+"(["+NORM+Location+C+"])"+NORM : KEATS); 
}
