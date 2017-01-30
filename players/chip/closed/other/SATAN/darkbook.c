/*
 *    File: /players/chip/closed/other/SATAN/darkbook.c
 *    Function: TP item
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
    
    write(""+RED+"The depths of "+HIR+"Hell"+NORM+""+RED+" are an extremely deadly place of"+NORM+"\n"+
          ""+RED+"eternal pain and suffering. Only those who are alr-"+NORM+"\n"+
          ""+RED+"eady dead should chance going to Hell, as those who"+NORM+"\n"+
          ""+RED+"are still amongst the living "+BOLD+"will surely die"+NORM+""+RED+" anyway."+NORM+"\n"+
          ""+RED+"There is an old chant that the Dark Masters used to"+NORM+"\n"+
          ""+RED+"use that would instantly send them to this most"+NORM+"\n"+
          ""+RED+"dangerous of places. This ancient "+HIK+"'chant'"+NORM+""+RED+" goes:    "+NORM+"\n"+
          "\n"+
          ""+HIK+"'drag me to hell my dark lord'"+NORM+"\n");
        return 1;
}

chant_it(str) {
	
	if (!str)
	{
		write("You must chant the dark words!\n");
		return 1;
	}
	
	if (str != "drag me to hell my dark lord")
	{
		write("You must chant the correct dark words!\n");
		return 1;
	}

	if (str == "drag me to hell my dark lord")
	{
		write("You have made a grave mistake. Feel the suffering that is the Depths of HELL!\n");
		call_other(this_player(), "move_player","through a pillar of fire#players/chip/closed/other/SATAN/room2.c");
		say(this_player()->query_name()+ " disappears in a pillar of fire.\n");
    	return 1;
	}
}
