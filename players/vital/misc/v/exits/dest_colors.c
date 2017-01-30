/******************************************************************************
 *
 *  File:         dest_colors.c
 *
 *  Function:     move a player to Francesco's Colors from guild hall
 *
 *  Author(s):    Vital
 *
 *  Copyright:    Copyright (c) 2007 Vital-Dev
 *                All Rights Reserved.
 *
 *  Source:       Started anew.
 *
 *  Change History:
 *      2007-06-15    Added Header
 *  
 *****************************************************************************/

#include "/players/guilds/vampires/headers/player_object.h"
#include "/players/guilds/vampires/headers/guild.h"
#include <ansi.h>

int
main()
{
  if (TP && PFANGS)
  {
    PFANGS->tell_my_room(capitalize((string)TPN) + "extends " + TPPOS +
      "wings and flies off to the " + RED + "C" + YEL + "o" + HIY + "l" + 
      NORM + GRN + "o" + BLU + "r" + MAG + "s.\n");
    write("You extend your wings and fly off to the " + RED + "C" + YEL +
      "o" + HIY + "l" + NORM + GRN + "o" + BLU + "r" + MAG + "s.\n");
    TP->move_player("into the mist#players/francesco/kale/rooms/entrance");
    return 1;
  }
  return 0;
}
