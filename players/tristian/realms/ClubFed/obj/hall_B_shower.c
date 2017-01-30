/*
//  Created:      Tristian@Nirvana
//  Copyright:    Copyright (c) 2005 Tristian
//                  All Rights Reserved.
//  Function:     Prison Mid-Level Area
//  Create Date:  2005.06.03
//	Thanks to everyone who helped me...
//  especially Illarion & Vertebraker
*/

#include "/players/tristian/lib/ClubFeddefine.h"
inherit "players/vertebraker/closed/std/room.c";
int lock;
int door;


reset(arg) {
	if(arg) return;
if (!present("con")) {
  move_object(clone_object("/players/tristian/realms/ClubFed/mobs2/shower_con.c"),
        this_object()); }
        
lock = 0;
door = 1;
set_light(1);

short_desc = HIR+"Club Fed"+NORM+" cellblock "+HIG+"'B'"+NORM+" Showers"; 

long_desc =
	" These are the showers at the end of the cellblock 'B' hallway.\n"+
	"The stories that are told about what happens to a convict in the\n"+
	"showers are truly frightening.  The showers line one wall, and\n"+
	"the floors and walls are tiled from top to bottom.  The windows\n"+
	"are all frosted, but still covered with bars. The door creaks\n"+
	"shut behind.\n\n"+
	HIR+"'Did that sound like the lock being turned??'\n"+NORM;
add_property("NT");
add_property("PK");

items = ({
"walls", 
	"The walls, they are covered in a lime green tile\n",
"window",
  "Fixed panes of glass that are frosted to provide some privacy",
"glass",
  "Frosted windows that provide some privacy",
"showers",
  "A row of about 10 showers for prisoners to clean themselves",
"wall", 
	"The walls, they are covered in a lime green tile",
"tile",
  "Lime green ceramic tile with bad grout\n",
"grout",
  "This grout was once white, but years of use have left it a dingy grey\n",
"floor",
  "Lime green tile on the floor that matches the walls\n",
"door",
	"The door that leads into the shower, it is covered with bars and has a lock",
"bars",
	HIK+"---------------------------------------------------\n"+
	"|      ||     ||     ||     ||     ||     ||      |\n"+
	"|      ||     ||     ||     ||     ||     ||      |\n"+
	"|      ||     ||     ||     ||     ||     ||      |\n"+
	"|      ||     ||     ||     ||     ||     ||      |\n"+
	"|      ||     ||     ||     ||     ||     ||      |\n"+
	"|      ||     ||     ||     ||     ||     ||      |\n"+
	"|      ||     ||     ||     ||     ||     ||      |\n"+
	"|      ||     ||     ||     ||     ||     ||      |\n"+
	"|      ||     ||     ||     ||     ||     ||      |\n"+
	"---------------------------------------------------\n"+NORM,
});

dest_dir = ({
  RMS+"hall_B_10",		"west",
});
}

init() {
::init();
  AA("Smell","smell");
  AA("Search","search");
  AA("Listen","listen");
  AA("Unlock","unlock");
  AA("West","west");
  AA("Open","open");
  AA("Close","close");
  AA("Lock","lock");
  AA("Quit","quit");
  AA("cmd_call","call");  
}

Quit()
{
  write(HIR+"This is prison, it's kill or be killed in here, quitting is not allowed.\n\n"+NORM);
  return 1;
}

Lock(str)
{
	if(str!="door")
	{ 
  write("Lock what?\n");
	return 1;
	}
	if(str == "door")
	 {
		if(!present("jail key",this_player()))
		{
	  write("You need the key to lock this door.\n");
    return 1;
    } else {
    if(door == 1) {
    write("You need to close the door before you can lock it.\n");
    return 1;
    
    } else {
    
    if(lock == 1 && door == 0 && present("jail key",this_player())) 
    {
    write("You lock the door behind you.\n");
    lock = 0;
    return 1;
    }}}}}

Unlock(str)
{
	if(str!="door")
	{ 
  write("Unlock what?\n");
	return 1;
	}
	if(str == "door")
	 {
		if(lock == 0 && present("jail key",this_player()))
		{
	  write("You unlock the door.\n");
    lock = 1;
    return 1;
    } 
 		else
 		{
    write("The door is locked, you need the key from the guard.\n");
    return 1;
    }
   }
}
		
West()
{
	if(lock == 1 && door == 0)
	{
	return 0;
	}
	if(lock == 0)
	{
	write("The door is locked.\n");
	return 1;
	}
	if(lock == 1 && door == 1)
	{
	write("The door is closed.\n");
	return 1;
	}
}
Open(str)
{
	if(str!="door")
	{ 
	write("Open what?\n");
	return 1;
	}
	if(str == "door" && door == 1 && lock == 1)
	{
	write("You open the door.\n");
	say(TPN + " opens the door.\n");
  door = 0;
	return 1;
	}
	if(str == "door" && lock == 0)
	{
	write("The door is locked.\n");
	return 1;
	}
}

Close(str)
{
	if(str!="door")
	{ 
	write("Close what?\n");
	return 1;
	}
	if(str == "door" && door == 0 && lock == 1)
	{
	write("You open the door.\n");
	say(TPN + " opens the door.\n");
  door = 0;
	return 1;
	}
	if(str == "door" && lock == 0)
	{
	write("The door is locked.\n");
	return 1;
	}
}

Smell(str) {
  if(!str || str == "air") {
    write("The smells in the prison are fairly antiseptic.\n");
    return 1;
}
    return 1;
}

Search() {
    write("You find nothing special.\n");
	 return 1;
}

Listen() {
    write("The sounds of a somewhat atypical prison, The guard walking up\n"+
    "and down the hall, and a slightly mechanical buzz are in the air.\n");
    return 1;
}

string *callers;

cmd_call(string str)
{
  if(!str)
  {
    notify_fail("Call who?\n");
    return 0;
  }
  if(str != "guard" && str != "the guard")
  {
    notify_fail("You can only call the guard.\n");
    return 0;
  }
  
  if(!callers) callers = ({ });
  
  if(member_array(this_player()->query_real_name(),callers) > -1)
  {
    notify_fail("You've already called the guard.\n");
    return 0;
  }
  
  write(
    "You call the guard. He comes down the hall, enters the showers and locks\n"+
    "the door behind him.\n");
  say((string)this_player()->query_name()+" bangs on the bars and the guard comes in!\n");
  
  move_object(clone_object("/players/tristian/realms/ClubFed/mobs2/guard.c"),
    this_object());
 
  callers += ({ this_player()->query_real_name() });
  return 1;
}


