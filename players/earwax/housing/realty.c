/* **************************************************************************
 * File:           /players/earwax/housing/realty.c                         *
 * Function:       Give players somewhere to buy land from.                 *
 * Author:         Earwax                                                   *
 * Copyright:      Copyright (c) 2004 Earwax.  All rights reserved.         *
 * Source:         5/28/04                                                  *
 * Notes:                                                                   *
 * Change History: Added hupdate so I could correct mistakes.               *
 * *************************************************************************/

#include "defs.h"

inherit "/room/room.c";

/* **************************************************************************
 * Function:     reset
 * Description:  Called when room is created or reset
 * Arguments:    arg (0 on creation, 1 on reset)
 * Return:       void
 * *************************************************************************/
void
reset(status arg)
{
  ::reset(arg);
  
  if (arg)
    return;
  
  if (!find_object(LANDD))
    LANDD->reset(0);
      
/*
  move_object( clone_object( "/players/dragnar/closed/auction/bidding_machine.c" ), this_object() );
*/
  set_light(1);
  short_desc = HIY+"Nirvana Realty Services"+NORM+NORM;
  long_desc = (string)WAXFUNS->line_wrap("The Nirvana Realty office reeks of \
money.  From the plush carpeting to the elegant lighting it's obvious that the \
office generates a great deal of income.  The walls are decorated in portraits \
of what one might assume to be palaces and land once (or currently) handled by \
this office.  There is a "+HIK+"sign"+NORM+NORM+" here that one can "+HIW+"look \
at"+NORM+NORM+" or "+HIW+"read"+NORM+NORM+".\n");
  dest_dir = ({
    "/room/path1.c", "east"
    });
  items = ({ "office", "It would appear to be a very prosperous realty office"
           , "carpeting", "It's very plush, probably quite expensive"
           , "lighting", "It's quite elegant, probably very expensive"
           , "walls", "They are decorated with portraits"
           , "portraits", "Mostly portraits of land.  One, however, is of Earwax"
           , "earwax", "You really don't want to look closely.  One word: FUGLY"
           , "land", "Beautiful portraits of land adorn the walls"
         });
}

status
do_hinfo(string arg)
{
  write("Attempting to access housing system information...\n");
    return ((status)(BIN+"hinfo.c")->main(arg, this_object(), this_object()));
}

status
do_read(string arg)
{
  if (arg != "sign")
  {
    notify_fail("You may "+HIW+"read"+NORM+NORM+" the "+HIK+"sign"+NORM+NORM+".\n");
    return 0;
  }
  write(HIW+"==============================================================================\n"+NORM+NORM);
  write("The sign says: Welcome to Nirvana Realty Services!\n\
The following are the commands available here:\n");
  write(HIW+"==============================================================================\n"+NORM+NORM);
  write(HIW+"list"+HIK+" <filter and sort arguments>\n"+HIW);
  write("dlist"+HIK+" <(ascending sort) filter and sort arguments>\n"+HIW);
  write("listhelp"+NORM+NORM+" (how to use the filter and sort arguments\n"+HIW);
  write("purchase"+HIK+" <index number>\n"+HIW);
  write("sell"+HIK+" <index number> <asking price> <economy adjustment flag>\n"+NORM+NORM);
  write(HIW+"view"+HIK+" <index number>"+NORM+NORM+" view information about land.\n");
  write(HIW+"hinfo"+NORM+NORM+" (Information about land and what it's good for).\n");
/* This isn't in yet....later though perhaps
  write("(Economy adjustment factors market price into land prices).\n");
*/
  if ((int)this_player()->query_level() > 19)
    write(HIY+"hupdate"+HIK+" <index num>"+NORM+NORM+" reload room information.\n");
  write(HIW+"==============================================================================\n"+NORM+NORM);
    
  return 1;
}

status
listhelp(string arg)
{
  string text;
  
  write(HIW+"==============================================================================\n"+NORM+NORM);
  text = "Nirvana Realty Services have at their disposal (and therefore your disposal), a very \
powerful listings function.  Using this function you can sort the real estate listings in myriad \
ways, as well as filter for certain elements.  Sorting simply requires putting one more more of \
the sort keywords in as your argument.  Using"+HIW+" dlist "+NORM+NORM+"instead of "+HIW+"list"
+NORM+NORM+" will \
cause the resulting output to be sorted in descending order.  Ascending is the default.  For \
filtering for certain types of information, merely input the filter keywords.\n";
  write((string)WAXFUNS->line_wrap(text));
  write(HIK+"\nNote: use 'list all' or 'dlist all' for primary sorts.\n");
  write("Note: for using sort, it's put keywords in order you wish to sort by.\n");
  write(HIW+"==============================================================================\n"+NORM+NORM);
  write(HIK+"\Filters:\n"+NORM+NORM+"\
unavailable: Show land not presently on the market.\n\
available:   Show only land available to buy.\n\
large:       Show large plots. (Palace-size, or unlimited rooms.  Level 19+75).\n\
medium:      Show medium plots. (House-size, or 5-7 rooms maximum. Level 19+30).\n\
small:       Show small plots. (Hut-size, or   1-3 rooms maximum. level 19).\n\
creator:     Show only lands by that creator.  ");
  write(HIW+"list creator earwax"+NORM+NORM+" for example.\n\
developed:   Show only land that has already been built upon.\n\
undeveloped: Show only undeveloped land.\n");
  write(HIW+"==============================================================================\n"+NORM+NORM);
  write(HIK+"Sorts:\n"+NORM+NORM+"\
bycreator:    Sort by creator name.\n\
realm:        Sort by realm name.\n\
lotsize:      Sort by size.\n\
cost:         Sort by cost.\n\
development:  Sort by number of rooms already developed.\n");
  write(HIW+"==============================================================================\n"+NORM+NORM);
  return 1;
}

status
do_view(string arg)
{
  if (intp(arg))
    arg = ""+arg;
    
  return (status)LANDD->view_land(this_player(), arg);
}

status
do_list(string arg)
{
  if (arg == "help")
    return listhelp(arg);
    
  return (status)LANDD->dump_list(this_player(), arg);
}

status
do_sell(string arg)
{
  if (!arg || !strlen(arg))
  {
    notify_fail("What number were you selling?\n");
    return 0;
  }

  return (status)LANDD->sell_land(this_player(), arg);
}

status
do_look(string arg)
{
  if (arg == "sign" || arg == "at sign")
    return do_read("sign");
  
  return 0;
}

status
do_purchase(string arg)
{
  int index;
  
  if (!arg || !strlen(arg))
  {
    notify_fail("What number do you wish to purchase?\n");
    return 0;
  }
  
  return (status)LANDD->purchase_land(this_player(), arg);
}

status
do_hupdate(string arg)
{
	int index;
	
	if (!arg || sscanf(arg+"", "%d"+"", index) != 1)
	{
    notify_fail("You must supply the numeric index of the land to update.\n");
    return 0;
  }
  
  return (status)LANDD->hupdate_land(index);
}

init()
{
  ::init();

  add_action("do_hinfo", "hinfo");
  add_action("do_read", "read");
  add_action("do_look", "look");
  add_action("do_list", "list");
  add_action("do_list", "dlist");
  add_action("do_purchase", "purchase");
  add_action("do_sell", "sell");
  add_action("listhelp", "listhelp");
  add_action("do_look", "l");
  add_action("do_view", "view");
  add_action("do_hupdate", "hupdate");
}


