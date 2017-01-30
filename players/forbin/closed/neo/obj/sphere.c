inherit "obj/treasure";

#include "../defs.h"

string Creator, SphereType, Color;
object web, wound;

id(str) 
{ 
 	if(SphereType)
	  return str == "sphere" || str == "dark matter sphere" || str == SphereType ||
	         str == SphereType+" sphere" || str == "dark matter "+SphereType+" sphere";
  else
    return str == "sphere" || str == "dark matter sphere";
}

short() { return HIW+"Dark Matter Sphere "+Color+"["+NORM+
	               SphereType+Color+"]"+NORM; }

long()
{
	write(
		"This is a smooth sphere that is as hard as stone yet lightweight. It is\n"+
		"warm to the touch and you almost feel as though it is living.  You can\n"+
		"'grasp sphere' or 'grasp <type'> at any time to inact its power. \n"+
	  "This "+HIW+"Dark Matter Sphere"+NORM+" was created by "+Creator+"\n");
}

reset(int arg)
{
  if(arg) return;
  SphereType = "none";
  Creator = "unknown";
  Color = HIW;
	call_out("destruct_sphere", 108000);
}

destruct_sphere()
{
  if(root() || !environment()) 
    return;
	if(living(environment()))
	{
		tell_object(environment(),
		  "The sphere disintegrates as it dies...\n");
    destruct(this_object());
		return 1;
	}
	else
	{
		destruct(this_object());
		return 1;
	}
	return 1;
}

int query_value() { return 100; }
int query_save_flag() { return 1; }

void set_type(string x) { SphereType = x; }
string query_type() { return SphereType; }

void set_creator(string x) { Creator = x; }
string query_creator() { return Creator; }

void set_color(string x) { Color = x; }
string query_color() { return Color; }

init()
{
	add_action("cmd_main", "grasp");
}

status cmd_main(string str)
{
	object target, web;
	string msg,msg2,msg3;
	int damage, spcost;
	
	if((int)this_player()->query_ghost()) 
	  return 0;
	  
	if(environment(this_object()) != this_player()) 
	  return 0;
	 
	if(!str)
	{
		tell_object(this_player(),
		  "Grasp what?\n");
		return 1;
	}
	  
  if(str == SphereType || str == "sphere")
  {
	
  	if(SphereType == "heal")
	  {
  		tell_object(this_player(),
	  	  "You grasp the Healing Sphere of "+HIW+"Dark Matter..."+NORM+"\n"+
		    "It softens and enters your body.  There it winds through your bloodstream\n"+
		    "and repairs your wounds.\n");
  		this_player()->heal_self(35);
      command("mon", this_player());
		  destruct(this_object());
  		this_player()->recalc_carry();
	   	return 1;
  	}
	
	  else if(SphereType == "attack")
  	{
	  	if(!this_player()->query_attack())
		  {
			  write("You are not fighting!\n");
  			return 1;
	  	}
		  damage = 12 + random(25);
  		target = (object)this_player()->query_attack();
	  	tell_room(environment(this_player()),
		  	(string)this_player()->query_name()+" grasps a "+HIW+"Dark Matter Sphere..."+NORM+"\n"+
		    "The Sphere erupts into motion as it launches into "+
  		  (string)target->QN+" and "+HIR+
	  	  "Impales"+NORM+" them!\n", ({ this_player() }) );
		  tell_object(this_player(),
  			"You grasp the "+HIW+"Dark Matter Sphere..."+NORM+"\n"+
	  		"The Sphere vibrates as it suddenly launches into the air and forms into a spear!\n"+
		  	Color+"---------- -- ----- "+HIR+"T H U N K"+Color+" ---- ---- -------"+NORM+"\n"+
			  (string)target->QN+" is impaled by the "+HIW+"Dark Matter Spear"+NORM+".\n");
  		target->hit_player(damage);
	  	if(random(100) < 33)
		  {
        if(wound = present("neo_wound_object", target))
  	    {
	      	wound->add_ticks(2+random(5));
	      	wound->add_num(1);
	      }
  	    else
	      {
	        wound = clone_object(OBJECTS+"wound.c");
	        wound->set_ticks(2+random(5));
	        wound->set_num(1);
  	      move_object(wound, target);
	      }
		  }
		  destruct(this_object());
  		this_player()->recalc_carry();
	  	return 1;
  	}
	
  	else if(SphereType == "bind")
	  {
		  if(!this_player()->query_attack())
  		{
	  		tell_object(this_player(),
		  	  "You must be in combat!\n");
			  return 1;
  		}
	  	target = (object)this_player()->query_attack();
		  if(target->is_living() && !target->query_npc())
		  {
  			tell_object(this_player(),
	  		  "You cannot use this on players!\n");
		  	return 1;
  		}
	  	if(target->webbed())
		  {
			  tell_object(this_player(), 
			    "You cannot web "+(string)target->query_name()+" again!\n");
  			return 1;
	  	}
		  if(random(100) > 85)
  		{
	  		tell_object(this_player(),
		  		"You hold the "+HIW+"Dark Matter Sphere"+NORM+" before you...\n"+
			    "Flying from your hand, it attempts to bind "+(string)target->query_name()+", but misses!\n");
  			tell_room(environment(this_player()),
	     	  (string)this_player()->QN+" holds up a "+HIW+"Dark Matter Sphere..."+NORM+"\n"+
			    "It flies from "+(string)this_player()->POS+" hand, but misses "+
  			  (string)target->QN+".\n", ({ this_player() }) );
	  		destruct(this_object());
		  	this_player()->recalc_carry();
			  return 1;
  		}
	  	tell_object(this_player(),
		  	"You hold the "+HIW+"Dark Matter Sphere"+NORM+" before you...\n"+
  			  "It flies from your hand and hits its target.  Thousands of\n"+
	  		HIW+"webs"+NORM+" shoot from the sphere and entangle "+(string)target->QN+".\n");
  		tell_room(environment(this_player()),
	  		(string)this_player()->query_name()+" holds up a "+HIW+"Dark Sphere..."+NORM+"\n"+
		  	"It flies from "+(string)this_player()->POS+" hand and hits its target.  Thousands of\n"+
			  HIW+"webs"+NORM+" shoot from the sphere and entangle "+(string)target->QN+".\n", ({ this_player() }) );
		  web = clone_object(OBJECTS+"webbing.c");
  		web->set_time(40 + random(40));
	  	web->web_person(target);
		  destruct(this_object());
  		this_player()->recalc_carry();
	  	return 1;
  	}
	
	  else if(SphereType == "transfer")
  	{
	  	if(!present("venom_object", this_player()))
		  {
			  tell_object(this_player(),
			    "You cannot figure out what to do with it.\n");
  			return 1;
	  	}
		  tell_object(this_player(),
			  "You grasp the "+HIW+"Dark Matter Sphere..."+NORM+"\n"+
  		  "It dissolves in your hand and you feel a flow of power enter your body.\n");
	  	present("venom_object", this_player())->add_mp(35);
		  command("mp", this_player());
  		destruct(this_object());
	  	this_player()->recalc_carry();
		  return 1;
	  }
  	else
	  {   
		  tell_object(this_player(),
		    "Error: Report this.\n"); 
  		destruct(this_object());  
	  	this_player()->recalc_carry(); 
		  return 1; 
    }
  return 0;
  }
  return 0;
}

int query_weight() { return 1; }