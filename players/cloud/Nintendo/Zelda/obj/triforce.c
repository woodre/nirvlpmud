/*
 *  Triforce
 *  /Nintendo/Zelda/obj/triforce.c
 *  Cloud 2015
 */
 
#include "/obj/ansi.h";
inherit "obj/treasure";

reset(arg)  
{
	if(arg) return;

   	set_name("Tri_Force");
   	set_alias("triforce");
   	set_short(""+HIY+"Triforce"+NORM+"");
   	set_long("Three triangles connected together leaving an empty triangle in the center.\n"+
   			 "Legend has it: Someone with equal balance of power, wisdom, and courage\n"+
   			 "can make one wish after touching the triforce. An unbalanced individual\n"+
   			 "attempting a wish, would cause it to split into three seperate pieces.\n"+
   			 "Maybe you should try and "+HIY+"make wish"+NORM+".\n");
   	set_weight(1);
   	set_value(1);
}

init()
	{
		::init();
		add_action("makeawish","make");
	}

makeawish(string str)
{
	int I;
	if(str == "wish")
	{				
  		I = (30000 + random(5000));
			tell_object(this_player(),
	  			"\nYou open your eyes just as coins rain down from the sky into your hands.\n\n");
			tell_room(environment(this_player()),
				"\n"+this_player()->query_name()+" opens his eyes just as coins rain down from the sky into their hands.\n", ({ this_player() }));			
    		this_player()->add_money(I);
    		destruct(this_object());
    		return 1;
	}		
	else
	{
		write("What?\n");
		return 1;
	}
}