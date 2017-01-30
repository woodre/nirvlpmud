#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
 inherit "obj/treasure";

int i ;
 reset(arg)  {
  if(arg) return;
  set_id("stocker");
  set_short("Arrina's stocking tool (stocker)");
  set_long("  This is Arrina's tool for distributing Xmas stockings.\n"+
      "To dispense a stocking: 'stock [player]'\n" +
      "It was built Christmas Eve, 1996.\n " +
      " XOXOXOXO\n");
 set_weight(1);
 set_value(0);
        }
 init()  {
  ::init();
  add_action("stock_punk","stock");
        }

stock_punk(victim)
	{
	int extract;
	string extraction;
	object rottenkid, stocking, lump;
	if (environment() != this_player()) 
		{
		/* write("You must get it first!\n"); */
		return 0;
		}
	
	rottenkid = find_living(victim);
	if(rottenkid && rottenkid->query_invis() > 19)
     		rottenkid = 0;
    	if (!rottenkid)
	  {
	  write ("  You couldn't find " + victim + "\n");
	  return 1;
	  }
	stocking = clone_object("/players/arrina/treas/stocking");
	stocking->set_name("stocking");
	stocking->set_short(rottenkid->query_name()+
		"'s Christmas Stocking");
	lump = clone_object("/players/arrina/treas/lump");
	extract = random (3);
	if (extract < 1) extraction = "lignite";
	if (extract == 2) extraction = "bituminous";
	if (extract == 1) extraction = "anthracite";
	lump->set_name("coal");
	lump->set_short("a lump of " + extraction + " coal");
	transfer(lump,stocking);
	transfer(stocking, rottenkid);
	write("  You give  " + rottenkid->query_name() + 
	      " their just desserts...\n"); 
   tell_object(rottenkid,HIR+"   You just received a Christmas stocking!\n"+NORM+
         HIR+"\n    Could it be from Santa..?\n"+NORM);
	return 1;
	}

