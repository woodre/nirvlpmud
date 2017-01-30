/*  Dew Machine
 *  /Nintendo/dewmachine.c
 *  Cloud 2013
 */
 
#include "/obj/ansi.h"
#define CO clone_object

object Dew;
int Cost;
string What;

short()
{ 
	return ""+HIG+"A Mountain Dew Machine"+NORM+""; 
}

status id(string arg) 
{ 
	return (arg == "machine"); 
}


long()  
{
	write("\nThis is where the Dew lives. Get you some.\n");
	write(""+HIW+"ID----------Type-------------------Cost----------------"+NORM+"\n");      
	write(""+HIW+"_______________________________________________________"+NORM+"\n");    
  	write(""+HIG+"dew"+NORM+"   -  "+HIG+"Mountain Dew"+NORM+"             1600 Coins\n");
  	write(""+HIR+"red"+NORM+"   -  "+HIG+"Mountain Dew "+HIR+"Code Red"+NORM+"    1450 Coins  (sp-only)\n");
  	write(""+HIK+"diet"+NORM+"  -  "+HIK+"Diet "+HIG+"Mountain Dew"+NORM+"        3300 Coins  (low-tox)\n");
  	write(""+HIW+"white"+NORM+" -  "+HIG+"Mountain Dew "+HIW+"White Out"+NORM+"   1800 Coins  (hp-only)\n\n");
  	write("'buy   <id>' to purchase.\n");
  	write("'drink <id>' to use.\n");
  	
  	
}

get()   
{ 
	write("Its chained the the floor.\n"); 
	return 0; 
}

init()  
{
	add_action("buy","buy");
}

buy(string str)
{
  

	if(!str)
	{ 
		write("Please select from the choices available.\n"); 
		return 1; 
	}
	
  	if(str == "dew")
  	{
    	Cost = 1600;
    	Dew = CO("/players/cloud/Nintendo/obj/dew.c");
    	What = ""+HIG+"Mountain Dew"+NORM+"";
  	}
  	
  	else if(str == "red")
  	{
    	Cost = 1450;
    	Dew = CO("/players/cloud/Nintendo/obj/reddew.c");
    	What = ""+HIG+"Mountain Dew "+HIR+"Code Red"+NORM+"";
  	}
  	
    else if(str == "diet")
  	{
    	Cost = 3300;
    	Dew = CO("/players/cloud/Nintendo/obj/dietdew.c");
    	What = ""+HIW+"Diet "+HIG+"Mountain Dew"+NORM+"";
  	}
  	
  	else if(str == "white")
  	{
    	Cost = 1800;
    	Dew = CO("/players/cloud/Nintendo/obj/whitedew.c");
    	What = ""+HIW+"Mountain Dew "+HIW+"White Out"+NORM+"";
  	}

  	else
  	{
    	write("Please select from the choices available.\n");
      	return 1;
  	}     

  	if (call_other(this_player(), "query_money", 0) < Cost) 
  	{
    	write("You dont have enough money.\n");
      	return 1;
  	}             

  	if(!this_player()->add_weight(Dew->query_weight())) 
  	{
    	write("You cannot carry that much weight.\n");
    	destruct(Dew);
      	return 1; 
  	}
  	                     
  	write("You buy a "+What+".\n");
  	say(this_player()->query_name() + " buys a "+What+".\n");
  	move_object(Dew,this_player());
  	this_player()->add_money(-Cost);
  	return 1;
}

