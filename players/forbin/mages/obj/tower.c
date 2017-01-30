#include "/players/forbin/define.h"
inherit "obj/treasure";

int Open, Locked;

id(str) 
{ 
	return (::id(str) || str == "tower" || str == "tower of the magi" 
		                || str == "the tower of the magi"
	                  || str == "door" || str == "doors"
	                  || str == "opening" || str == "openings"
	                  || str == "tower" || str == "towers"
	                  || str == "sign" || str == "paper" || str == "paper sign"); 
}

reset(arg) 
{
  if(arg) return;
  set_short(0);
  Open = 0;
  Locked = 1;
}

void long(string str) {
  if(str == "sign" || str == "paper sign") 
  {
    tell_object(this_player(),
      "A paper sign, carefully lettered by hand.  You could read it.\n");
  }
  else if(str == "opening" || str == "openings")
  {
  	tell_object(this_player(),
  	  "Thin white brickwork surrounds the blackness of every square window.\n");
  }
  else if(str == "door" || str == "doors")
  {
    tell_object(this_player(),
      "A pair of large wooden doors mark the entrance to the tower.  They are\n"+
      "currently "+(Open ? "opened" : "closed")+".  There is a sign posted to the\n");
  }
  else 
    tell_object(this_player(),
      "Looming over the square like a sentinel, a magnificent tower of purple\n"+
      "stone stretches skyward, disappearing into the mist above.  Each of the\n"+
      "individual stones making up this citadel of the mages have been perfectly\n"+
      "laid, their joints barely visible even upon close scrutiny.  Hundreds of\n"+
      "square openings dot the tower as far up as you can see, yet only a single\n"+
      "pair of doors are present at ground level.\n");
}

get() { return 0; }

init() 
{
  ::init();
  add_action("cmd_read", "read");
  add_action("cmd_enter", "enter");
  add_action("cmd_open_and_close", "open");
  add_action("cmd_open_and_close", "close");
  add_action("cmd_lock_and_unlock", "lock"); 
  add_action("cmd_lock_and_unlock", "unlock");  
}

status cmd_read(string str) 
{
  if(!str || str != "sign") 
  { 
    notify_fail("Read what?\n"); 
      return 0; 
  }
  tell_object(this_player(),
    "\nThe hand written sign reads:\n\n"+
    "     The "+HIM+"T"+NORM+MAG+"ower of the "+HIM+
    "M"+NORM+MAG+"agi"+NORM+" will remain locked\n"+
     "     until time for the Mages guild to open.\n\n");
    return 1; 
}

status cmd_open_and_close(string str)
{
}

status cmd_lock_and_unlock(string str)
{
}

status cmd_enter(string str) 
{
  if(!str || (str != "tower" && str != "door")) return 0; 
  tell_object(this_player(),
    "The "+str+" is closed and locked.\n"+
    "There is a sign posted on the door.\n");
  tell_room(this_object(),
    (string)this_player()->query_name()+
    " tries to enter the locked tower.\n", ({ this_player() }));  
  return 1; 
}