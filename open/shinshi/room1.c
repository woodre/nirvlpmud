/*                                                                    
 *    File: /players/chip/closed/other/SATAN/room1.c                
 *    Function: room
 *    Author(s): Chip@Nirvana       
 *    Copyright: Copyright (c) 2008 Chip      
 *               All Rights Reserved   
 *    Source: 7/30/09           
 *    Notes:                                                          
 *                                                                    
 *                                                                    
 *    Change History:                                                 
 *
 *	  Used the code from /room/bank.c in order to allow the chest in the room to unlock and open so you can retrieve an item from it -Shinshi
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "/room/room";
int chest_is_open, chest_is_locked;
int found;

reset(arg)
{
  ::reset(arg);
  
  chest_is_open = 0; chest_is_locked = 1;
  
  if(arg) return;
  set_light(1);
  short_desc = "A dusty cellar";
  long_desc =
    "This is a dusty old storage cellar. There are only a few empty boxes lying around,\n"+
    "and an old steel ammo box up on a table.\n";

  add_smell("mold", "The scent is strong and makes it difficult to breathe properly");
  add_smell("urine", "The scent is strong and makes it difficult to breathe properly");
  
  items =
  ({
    "cellar",
    "Just an old, dusty storage area",
    "boxes",
    "They are all empty",
    "ammo box",
    "It's steel and green. It is also locked. Judging by the weight, there seems to be something inside",
    "table",
    "It is old and wooden. The only things on it are a steel ammo box and alot of dust",
    "dust",
    "It covers everything",
    "mold",
    "It is growing in many large spots, due to trapped moisture and humidity",
    "mildew",
    "It is growing in many large spots, due to trapped moisture and humidity",
    
    });

  dest_dir =
  ({
    "/room/church.c",     "church",
  });
}

init()
{
	::init();
	
	add_action("unlock", "unlock");
	add_action("open", "open");
	add_action("grab", "grab");
}

open(str) {
    if (str && str != "chest")
        return 0;
    if (chest_is_open){
	    write("The chest is already open!\n");
        return 1;
    }
    if (chest_is_locked) {
        write("The chest is locked.\n");
        return 1;
    }
    chest_is_open = 1;
    write("Ok.\n");
    say(this_player()->query_name()+" opened the chest.\n");
    return 1;
}

unlock(str) {
    if (str && str != "chest")
        return 0;
	if (!chest_is_locked){
		write("The chest is already unlocked!\n");
		return 1;
	}
	if (chest_is_locked && !present("chips_key", this_player())){
		write("You don't have the correct key.\n");
		return 1;
	}
	if (chest_is_locked && present("chips_key", this_player())){
		chest_is_locked = 0;
	    write("Ok.\n");
	
	    write("As the chest unlocks, the key disappears.\n");      /*You can cut this part out if you want. If you don't, the key will disappear*/
	    destruct(present("chips_key",this_player()));
	    say(this_player()->query_name()+" unlocks the chest.\n");
	    return 1;
	}
}

grab(str) {
	if (!str) {
		write("What would you like to do?\n");
		return 1;
	}
	if (str != "book from chest") {
		write("What would you like to grab from the chest?\n");
		return 1;
	}
    if (!chest_is_open) {
        write("The chest is closed.\n");
        return 1;
    }
    if (chest_is_locked) {
	    write("The chest is locked.\n");
	    return 1;
    }
    if (str == "book from chest") {
	    if (found) {
		    write("You search the chest and find that the book has been taken!\n");
		    return 1;
	    }
	    move_object(clone_object("/players/shinshi/sword.c"), this_player());
	    write("You pull a demonic book from the chest.\n");
    	found = 1;
    	return 1;
	}
}
