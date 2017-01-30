/*
 *    File: /players/chip/items/apartment/cheeseburger.c
 *    Function: Sellable Item
 *    Author(s): Chip@Nirvana
 *    Copyright: Copyright (c) 2008 Chip
 *               All Rights Reserved
 *    Source: 5/31/08
 *    Notes: 
 *
 *
 *    Change History:
 */
 
inherit "obj/treasure";
#include <ansi.h>

id(str) {
   return str == "dark_book" || str == "book";
           }
reset(arg) {
   if(arg) return;
   
   set_alias("book");
   set_short("A "+HIR+"Satanic"+NORM+" Looking Book");
   set_long("This book is extremely old and evil looking.\n"+
            "It is still in surprisingly excellent condition\n"+
            "most likely from being stowed inside the ammo box.\n"+
            "\n");
   set_value(0);
   set_weight(1);
   set_dest_flag(1);
}
   
   init() {
        ::init();
        
        add_action("read_it", "read");
        add_action("chant_it", "chant");
        }

read_it(str) {
    
    write("The depths of Hell are an extremely deadly place of\n"+
          "eternal pain and suffering. Only those who are alr-\n"+
          "eady dead should chance going to Hell, as those who\n"+
          "are still amongst the living will surely die anyway.\n"+
          "There is an old chant that the Dark Masters used to\n"+
          "use that would instantly send them to this most\n"+
          "dangerous of places. This ancient 'chant' goes:    \n"+
          "\n"+
          "'drag me to hell my dark lord'\n");
        return 1;
}

chant_it(str) {
	
	if (!str)
	{
		write("You must chant the magic words!\n");
		return 1;
	}
	
	if (str != "drag me to hell my dark lord")
	{
		write("You must chant the correct magic words!\n");
		return 1;
	}

	if (str == "drag me to hell my dark lord")
	{
		write("You have made a grave mistake. Feel the suffering that is the Depths of HELL!\n");
		call_other(this_player(), "move_player","in a pillar of fire##players/chip/closed/other/SATAN/room2.c");
		say(this_player()->query_name()+ " disappears in a pillar of fire.\n");
    	return 1;
	}
}
