inherit "obj/treasure";

#include "../defs.h"

string Creator, Color;
mapping arms, weps;

id(str) 
{ 
  return (str == "sphere" || str == "dark matter sphere" || "creation sphere");
}

short() { return HIW+"Dark Matter Sphere "+Color+"["+NORM+
	               "Creation"+Color+"]"+NORM; }

long()
{
	write(
		"This is a smooth sphere that is as hard as stone yet lightweight. It is\n"+
		"warm to the touch and you almost feel as though it is living.  You can\n"+
		"'form <item>' to create almost any type of armor or weapon.  Type 'form'\n"+
		"by itself for a listing of valid creations.\n"+
	  "This "+HIW+"Dark Matter Sphere"+NORM+" was created by "+capitalize(Creator)+"\n");
}

reset(int arg)
{
  if(arg) return;
  Creator = "unknown";
  Color = HIW;
  
  arms = ([ "main", ({ HIW+"Dark Matter "+Color+"Breastplate"+NORM, 0, 8, 
                      ({ "dark matter breastplate", "breastplate", "neo_formed_armor", }), }),
            "helmet", ({ HIW+"Dark Matter "+Color+"Helm"+NORM, 0, 8, 
                      ({ "dark matter helm", "helm", "neo_formed_armor", }), }),                      
         ]);

  weps = ([ "sword", ({ HIW+"Dark Matter "+NORM+"Broadsword"+NORM, 16,
                       ({ "dark matter broadsword", "broadsword", "neo_formed_weapon", }), }), 
            "dagger", ({ HIW+"Dark Matter "+NORM+"Wardagger"+NORM, 16,
                       ({ "dark matter wardagger", "dark matter dagger", "wardagger", "neo_formed_weapon", }), }), 
         ]);         
           
}

int query_value() { return 100; }
int query_save_flag() { return 1; }

void set_creator(string x) { Creator = x; }
string query_creator() { return Creator; }

void set_color(string x) { Color = x; }
string query_color() { return Color; }

init()
{
	add_action("cmd_main", "form");
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
		  "You may form the following items:\n"+
		  "Armors:   Main, Helm, Boots, Amulet, Misc, \n"+
		  "Weapons:  Sword\n"+
		  "Usage: 'form' <item>'\n");
		return 1;
	}

	if(!(member(str, arms)) || !(member(str, weps)))
	{
		tell_object(this_player(),
		  "You may form the following items:\n"+
		  "Armors:   Main, Helmet, Boots, Amulet, Misc, \n"+
		  "Weapons:  Sword\n"+
		  "Usage: 'form' <item>'\n");
		return 1;
	}	
		  
  if(member(str, arms))
  {
    
  }
  else if(member(str, weps))
  {
    
  }
	
  return 0;
}

int query_weight() { return 1; }
