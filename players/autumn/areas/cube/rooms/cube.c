/* Author: Autumn
* "The Cube"
*/

/* TODO: 
*move corpse***
*move player to party***
need 'traps'
need mobs - w/ "ask" action
add ansi
test
duplicate
(& go crazy)
*/

inherit "/room/room";
#include "/players/autumn/defs.h" //needs defs 


/*declare var's*/

int trap, base, power;
string *monsters;
string *rooms;



reset(arg) 
{

  if(arg) return;
  
set_light(1);
}

/* ********************************************************************************* */

int checkForPlayers()
{
	int p;
	object *inv;
	
	inv = all_inventory(this_object());
	
	for (p=0; p< sizeof(inv); p++)
	{
		if(inv[p]->is_player() && inv[p] != this_player())
		{
			return 1;
		}
		
		else 
		{
			return 0;
		}
	}
}

/* ********************************************************************************* */

int get_mobs()
{
	int m;
	object temp;
return 1; /* remove this line once the monsters are coded */
	for(m = 0; m < sizeof(monsters);m++)
	{
    temp = present(monsters[m],this_object());
		if(temp)
		{
			destruct(temp);
			temp = clone_object("/players/autumn/cube/mobs/" + monsters[m] + ".c");
		}
			
			switch(random(3)) 
			{
				case 0:
				{	/* set this guy to aggro */
					temp->set_aggro();
					break;
				}
					
				case 1:
				{
					/* set this guy to not kill */
					temp->set_cant_kill();
					break;
				}
				
				case 2:
				{
					/* set this guy to normal */
					temp->set_normal();
					break;
				}
			}
				
		move_object(temp,this_object());
	}

	return 1;
}

/* ********************************************************************************* */

	set_trap()
	{
	int roomNum, *prime;
	base = random(12) + 2; /* to set base*/
	power = random(5) + 2; /* to set power*/
	roomNum = base ^ power;
	prime = ({3, 5, 7, 11, 13}); /* to set bases of prime #'s to identify trapped rooms*/
	
	this_object()->remove_item("number");
	this_object()->add_item("number","A number: " + roomNum);

  trap = 0;
 
		if(member(prime,base) != -1)
		{
			trap=1;
		}
		
		return 1;
	}

/* ********************************************************************************* */	
  
  int get_newRoom()
  {
  
    monsters = ({"quentin","worth","halloway","rennes","leaven","kazan"});
    rooms = ({ "blueCube","whiteCube","yellowCube","greenCube","redCube","grayCube"});

  	if(!checkForPlayers())
  	{
  		get_mobs();
  		set_trap();
  	}

  	add_action("search","search");
  	add_action("smell","smell");
  	add_action("listen","listen");
  	add_action("nDirection","climb");
  	add_action("nDirection","jump");
  	add_action("nDirection","right");
  	add_action("nDirection","left");
  	add_action("nDirection","u");
  	add_action("nDirection","d");
  	add_action("nDirection","n");
  	add_action("nDirection","s");
  	add_action("nDirection","e");
  	add_action("nDirection","w");
  	add_action("nDirection","back");
  	add_action("nDirection","forward");
  	add_action("nDirection","up");
  	add_action("nDirection","down");
  	add_action("nDirection","north");
  	add_action("nDirection","south");
  	add_action("nDirection","east");
  	add_action("nDirection","west");
  	add_action("ask","ask");
  	add_action("checkTrap","throw");
  	add_action("checkTrap","throw boot");
  	add_action("checkTrap","check");
  	add_action("disarmTrap","disarm");
  	add_action("disarmTrap","disarm trap");
	add_action("disarmTrap","avoid");
	add_action("disarmTrap","around");
	
  	return 1;
	
  }
  

/* ********************************************************************************* */


	search(str)
	{
		if(!str) 
		{	
		write("What are you trying to search?\n"); 
		say(TPN+" is investigating the room.\n");
		return 1; 
		}
		
  		if(str)
  		{
  			write("There is nothing to find.\n");
			say(TPN+" is investigating the room.\n");
  			return 1;
  		}
	}

	smell(str)
	{
	
		if(!str) 
		{	
		write("You smell a foul stench of sweat.\n"); 
		return 1; 
		}
		
  		if(str)
  		{
  			switch(str) 
  			{
  				case "boot": 
  					write("A seriously stinky boot. Why the hell would you smell that?\n");
					say(TPN+" is really gross. They smelled a really stinky boot.\n");
  				break;
  				
  				case "boots":
  					write("Seriously stinky boots. Why the hell would you smell them?\n");
					say(TPN+" is really gross. They like to smell stinky boots.\n");
          break;
          
  				default:
  					write("You smell a foul stench of sweat.\n");
  					break;
  				}
  			}
  			
  			return 1;
  		}	

	listen(str)
	{
		write("You hear noises of metal scraping metal and loud bangs, as if \n"+
				"something big is being dropped from high above the ground.\n");	
	}
	
/* ********************************************************************************* */

	int nDirection()
	{
		int r;
		r=random(sizeof(rooms));
		
		if(trap==0)
		{
			move_object(this_player(), "/players/autumn/cube/rooms/"+rooms[r]+".c");
			write("You leave "+query_verb()+".\n");
			say(TPN+" takes a chance and leaves "+query_verb()+".\n");
			command("look",TP);
			say(TPN+" appears out of nowhere.\n");
		}
		
		else
		{
			write("You can't leave yet.\n");   /*remove l8r*/
		}
		
		return 1;
	}

/* ********************************************************************************* */



	checkTrap(str) 
	{
		write("You take a chance and throw the boot through the hatch!\n");
		say(TPN+"throws the shoe through the hatch, attempting to uncover a trap.\n");
		tell_room(this_object(), "O o ... o O Man... that looks DANGEROUS! O o ... o O\n");

		if(trap==1)

			{
			write("You found a trap. It might be deadly... \n");
			say(TPN+" found a trap.\n");
			tell_room(this_object(),"WATCH OUT!!! You may want to try to 'disarm' or 'avoid' the trap.\n");
			return 1;
			}
			
		if(trap!=1)
			{
			write("It appears to be safe.\n");
			say(TPN+" checked for traps. The room appears to be safe\n.");
			}
	}

	disarmTrap(str)
	{
		int disarm;
		disarm=random(100);

		switch (disarm)
		{
			case 0..24:
			{
				write("You attempt to disarm a trap.\n");
				write("YOU SET OFF A TRAP! DUCK!\n");
				say(TPN+" SET OFF A TRAP! DUCK!\n");
				tell_room(this_object(),"...\n...\n...");
				tell_room(this_object(),"You're in luck, you avoided the threat.\n");
				trap=0;
			}
	
			case 25..49:
			{
				write("You attempt to disarm a trap.\n");
				write("YOU SET OFF A TRAP! THERE'S NO DODGING THIS ONE!!!\n");
				say(TPN+" SET OFF A TRAP! THERE'S NO DODGING THIS ONE!!!\n");
			
				/* HIT PLAYER */
				trapDamage();
			}
	
			case 50..74:
			{
				write("You disarm a trap.\n");
				say(TPN+" successfully disarmed a trap!\n");
				trap=0;
			}
		
			case 75..100:
			{
				write("You attempt to disarm a trap.\n");
				write("You set off the trap!!\n");
				say(TPN+" SET OFF A TRAP!\n");
				
				trapDamage();
			}
		}
	
	}

             
/* ********************************************************************************* */

	int trapDamage()
	{
		int t;
		object temp;
return 1; /* remove this line once the monsters are coded */
		for(t = 0; t < sizeof(traps);t++)
		{
    		temp = present(traps[t],this_object());
			if(temp)
			{
				destruct(temp);
				temp = clone_object("/players/autumn/cube/traps/" + traps[t] + ".c");
			}
			
			switch(random(2)) 
			{
				case 0:
				{	/* set this guy to aggro */
					temp->set_aggro();
					break;
				}
				
				case 1:
				{
					/* set this guy to normal */
					temp->set_normal();
					break;

			}

	}

	return 1;
}