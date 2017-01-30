/* inherit "players/nightshade/new_room"; */
inherit "/room/room";
#include <ansi.h>

/******************************************************************************
 * Program: guild_row4.c
 * Path: /players/nightshade/room
 * Type: room
 * Updated: October 2014 by Karash
 *
 * Purpose: An update to the guildmasters room to add a treasure chest.
 * 
 * History:
 *          
 ******************************************************************************/
 

int thf, ftr, clc, mage;
int x;
object ob;
string chest;

reset(arg){

x = 0;
thf = 0;
clc = 0;
ftr = 0;
mage = 0;
chest = "full";


/** This code will clone the four guildmasters in random order when the room resets in case  **/
/** players have a tendency to attack the first NPC.  This will allow different combinations **/
/** since different masters will join the fight depending which master is attacked first.    **/

/* PATHS UPDATED */
while(x < 4)
{
  switch( random(4) ) 
  {
    case 3:
      if(!present("master thief"))
      {
        ob=clone_object("players/nightshade/mons/master_thief");
        move_object(ob, this_object());
        x++;
		thf = 1;
	  }
	  if(present("master thief") && !thf)
	  {
        x++;
        thf = 1;
	  }
	  break;
    case 2:
      if(!present("master cleric"))
      {
        ob=clone_object("players/nightshade/mons/master_cleric");
        move_object(ob, this_object());
        x++;
		clc = 1;
	  }
	  if(present("master cleric") && !clc)
	  {
        x++;
        clc = 1;
	  }
	  break;
    case 1:
      if(!present("master fighter"))
      {
        ob=clone_object("players/nightshade/mons/master_fighter");
        move_object(ob, this_object());
        x++;
		ftr = 1;
	  }
	  if(present("master fighter") && !ftr)
	  {
        x++;
        ftr = 1;
	  }
	  break;
    default:
      if(!present("master mage"))
      {
        ob=clone_object("players/nightshade/mons/master_mage");
        move_object(ob, this_object());
        x++;
		mage = 1;
	  }
	  if(present("master mage") && !mage)
	  {
        x++;
        mage = 1;
	  }
	  break;
  }

}


if(arg) return;
set_light(1);
short_desc = " Guild_row";
long_desc =
"This is the end of Guild Row. Here the masters of each guild reside. They\n\
don't take too kindly to anyone not of a guild bothering them. They are\n\
very experienced, and if challenged, they will gladly destroy whomever is\n\
foolish enough to do so. Beware, they have a tendency to help each other.\n\
Currently, you stand in the great room which looks pretty plain in the dim\n\
lights, but the "+MAG+"chest"+NORM+" in the back of the room catches your attention.\n";

dest_dir = 
({ "players/nightshade/room/guild_row3", "south", });

items=({
    "chest",
"A small trunk made of solid, heavy, stained wood which looks to be\n\
expertly crafted with intricate designs carved into the wood.\n\
Perhaps you could open it",
	"trunk","&chest&",
	"designs",
"Various decorative patterns are carved into the wood",
    "patterns","&designs&",
	"wood","&designs&",
  });



}


void init()
{
  ::init();
  	add_action("open_chest", "open");
	
}

/** The loot in this chest represents all the loot value available from the four guildmasters and the **/
/** elemental needed to be killed to open the chest, less the item values dropped from each NPC.      **/
open_chest(str)
{
  object THF, CLC, FTR, MAGE, ELE;
  object gold, wand, shld;
  
  THF = present("master thief");
  CLC = present("master cleric");
  FTR = present("master fighter");
  MAGE = present("master mage");
  ELE = present("lightning elemental");
    
  if(!str) { write("What are you trying to open?\n"); return 1; }

  if(str == "chest")
  {
    if(THF || CLC || FTR || MAGE || ELE)
	{
      tell_object(this_player(),"A master of the house prevents you from doing that.\n");
      return 1;
    }
	if(chest == "empty")
	{
      tell_object(this_player(),"The chest is empty.\n");
      return 1;
    }
	if(chest == "full")
	{
	chest = "empty";
    tell_room(this_object(),this_player()->query_name()+" opens the chest to reveal what's inside.\n");
	
	/* PATHS UPDATED */
    gold=clone_object("obj/money");
    gold->set_money(30000+random(15000));
    move_object(gold, this_object());

    wand=clone_object("players/nightshade/misc/courage_wand_new");
    move_object(wand, this_object());

    shld=clone_object("players/nightshade/armor/shield_magresist_new");
    move_object(shld, this_object());		
	
	return 1;
	}
  }
}

