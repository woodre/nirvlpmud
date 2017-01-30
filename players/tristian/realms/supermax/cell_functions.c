/*
//  Created:      Tristian@Nirvana
//  Copyright:    Copyright (c) 2005 Tristian
//                  All Rights Reserved.
//  Function:     Prison Mid-Level Area Common Room Functions
//  Create Date:  2006.26.04
//	Thanks to everyone who helped me...
//  especially Illarion & Vertebraker
//
//  Change History:
*/

#include "/players/tristian/lib/supermaxdefine.h"


/*GLOBALS*/
int Lock;
int Door;

/*
// Function Name: Unlock
// Description: Unlocks a door to allow access to the adjacent room. 
*/
/*Unlock(str)
{
  if(str!="door")
  {
    notify_fail("Unlock what?\n");
    return 0;
  }
  if(str == "door")
  {
    if(Lock == 0 && present("jail key",this_player()))
    {
      write("You unlock the door.\n");
      say(TPN + " unlocks the door.\n");
      Lock = 1;
      return 1;
    }
    if(Lock == 1)
    {
	  write("The door is already unlocked.\n");
	  return 1;
   }
    else
    {
      write("The door is locked, you need the key from the guard.\n");
      return 1;
    }
  }
}

/*
//  Function Name: North
//  Description: Blocks the exit to the north if the door is closed.
//              Also tells the player if the door is still locked. 
*/
North()
{
  if(Lock == 1 && Door == 0)
  {
    return 0;
  }
  if(Lock == 0)
  {
    write("The door is locked.\n");
    return 1;
  }
  if(Lock == 1 && Door == 1)
  {
    write("The door is closed.\n");
    return 1;
  }
}

/*
//  Function Name: East
//  Description: Blocks the exit to the east if the door is closed.
//              Also tells the player if the door is still locked. 
*/
East()
{
  if(Lock == 1 && Door == 0)
  {
    return 0;
  }
  if(Lock == 0)
  {
    write("The door is locked.\n");
    return 1;
  }
  if(Lock == 1 && Door == 1)
  {
    write("The door is closed.\n");
    return 1;
  }
}
/*
//  Function Name: South
//  Description: Blocks the exit to the south if the door is closed.
//              Also tells the player if the door is still locked. 
*/
South()
{
  if(Lock == 1 && Door == 0)
  {
    return 0;
  }
  if(Lock == 0)
  {
    write("The door is locked.\n");
    return 1;
  }
  if(Lock == 1 && Door == 1)
  {
    write("The door is closed.\n");
    return 1;
  }
}

/*
//  Function Name: West
//  Description: Blocks the exit to the west if the door is closed.
//              Also tells the player if the door is still locked. 
*/
West()
{
  if(Lock == 1 && Door == 0)
  {
    return 0;
  }
  if(Lock == 0)
  {
    write("The door is locked.\n");
    return 1;
  }
  if(Lock == 1 && Door == 1)
  {
    write("The door is closed.\n");
    return 1;
  }
}

/*
// Function Name: Open
// Description: Opens a closed door & unlocked door. 
*/	
Open(str)
{
  if(str!="door")
  {
    notify_fail("Open what?\n");
    return 0;
  }
  if(str == "door" && Door == 1 && Lock == 1)
  {
    write("You open the door.\n");
    say(TPN + " opens the door.\n");
    Door = 0;
    return 1;
  }
  if(str == "door" && Lock == 0)
  {
    write("The door is locked.\n");
    return 1;
  }
  else
  {
	write("The door is already open.\n");
	return 1;
  }
}

/*
// Function Name: Lock
// Description: Locks a door. 
*/
Lock(str)
{
  if(str!="door")
  {
    notify_fail("Lock what?\n");
    return 0;
  }
  if(str == "door" && Door == 0)
  {
    write("The door is open, close it first.\n");
    return 1;
  }
  if(str == "door" && Door == 1)
  {
    if(Lock == 1 && present("jail key",this_player()))
    {
      write("You lock the door.\n");
      say(TPN + " locks the door.\n");
      Lock = 0;
      return 1;
    }
    else
    {
      write("The door is already locked.\n");
      return 1;
    }
  }
}

/*
// Function Name: Close
// Description: Closes a door. 
*/
Close(str)
{
  if(str!="door")
  {
    notify_fail("Close what?\n");
    return 0;
  }
  if (!Door)
  {
    write("You close the door.\n");
    say(TPN + " closes the door.\n");
    Door = 1;
    return 1;
  }
    write("The door is already closed.\n");
    return 1;
}