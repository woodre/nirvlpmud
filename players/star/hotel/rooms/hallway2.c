/*
*      File:                 /players/star/rooms/hallway2.c
*      Function:
*      Author(s):            Star@Nirvana
*      Copyright:            Copyright (c) 2005 Star/Charity Goddard
*                                    All Rights Reserved
*      Source:               11/06/2005
*      Notes:
*      Change History:
*/

#include <ansi.h>
#include </players/star/defs.h>

inherit "/room/room";

/* Change this to whatever your key will ID to later, qtip for testing. */
#define KEYID "ol_apt_key"

/* Global Variables */
status Locked;

reset(arg)
{
   ::reset(arg);
   
   /* On reset, see if there are any players in room.  If none, relock. */
      if (arg)
      {
      object ob;
      
      if (Locked)
         return; /* No need to bother if it's already locked. */
         
      /* This loops through the objects in the room, one by one.  It
      * first sets ob to the first object in the room, checks if it's
         * a player, if so, kick out.  If no objects it never loops, just
         * kicks out of the loop and continues the code.  If the first
      * object isn't a player, then set ob to be the next object in the
      * same inventory as current ob, and do the checks again.  Do 
      * this until either a player is come across, or it runs out of
      * objects to check.
      */
      ob = first_inventory(this_object());
      while(ob)
      {
         if (ob->is_player())
            return;
         ob = next_inventory(ob);
}
      Locked = 1;
      return;
   }
   
   set_light(1);
   short_desc = "A Hallway";
   long_desc =
   "   This hallway is very plain, with white walls and a blue carpet that\n"+
   "has some kind of squiggly black pattern.  It is a narrow hallway, and\n"+
   "so drab that it almost does not seem to be part of the rest of the\n"+
   "hotel.  There is a door to the east, and the hallway extends west back\n"+
   "toward the lobby.\n";
   
   items =
   ({
         "walls",
         "The walls are white and boring",
         "carpet",
         "The carpet is thick, and by far the nicest thing in the hall",
         "pattern",
         "The pattern isn't anything special, just squiggly black lines",
         "door",
         "The door is as white and boring as the walls",
    });
   dest_dir =
   ({
    HOTEL+"rooms/hallway.c",     "west",
    HOTEL+"rooms/live_room.c",   "east",
    });
   Locked = 1;
}

status do_lock(string arg)
{
   object ob;
   if (arg != "door" && arg != "east door")
      {
      write("Lock what?\n");
      return 1;
   }
   if (Locked == 1)
      {
      write("The door is already locked.\n");
      return 1;
   }
   ob = present(KEYID,this_player());
   if(!ob)
      {
      write("You don't have the correct key to lock this door.\n");
      return 1;
   }
   
    write("You close the door and lock it with the key.\n");
    say(this_player()->query_name()+" closes and locks the door.\n", this_player());
   Locked = 1;
   return 1;
}

status do_unlock(string arg)
{
   object ob; /* Used for the key object */
   
   /* Check argument, make sure it's the door they are trying to
   * unlock.  If it's not 'door' or 'east door' then use notify_fail()
      * and return 0, so that the game will go through any other unlock
   * actions the player may have, before giving that as a failure msg
   * rather than 'What?'
   *
   * After that, make sure that the door isn't already unlocked.
   */
   if (arg != "door" && arg != "east door")
      {
      notify_fail("Unlock what?\n");
      return 0;
   }
   if (!Locked)
      {
      notify_fail("The door is already unlocked.\n");
      return 0;
   }
   
   /* Check if they have the right key on them. */
      if (!(ob = present(KEYID, this_player())))
      {
      notify_fail("You don't have the correct key to unlock this door.\n");
      return 0;
   }
   
   /* They have the right key, used the right syntax.  Now let's unlock
   * the door and add the exit to short description/allow them to use
   * the exit.
   */
   
    write("You unlock and open the door.\n");
    say(this_player()->query_name()+" unlocks and opens the door.\n", this_player());
   Locked = 0;
   /* This lets it show up in room short. */
   return 1;
}

status do_east(string arg)
{
   if (Locked)
      {
      write("You can't go through a locked door.\n");
      return 1;
   }
   
   this_player()->move_player("east through the door#/players/star/hotel/rooms/live_room");
   return 1;
}

init()
{
   ::init();
   add_action("do_lock", "lock");
   add_action("do_unlock", "unlock");
   add_action("do_east", "east");
   add_action("do_east", "e");
}
