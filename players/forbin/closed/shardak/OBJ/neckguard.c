/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2005 Forbin
//                  All Rights Reserved.
//  Realm:        Shardak Guild
//  Function:     Guild Armor
//  Create Date:  2005.08.01
//  Last Edit:    2005.08.01 -Forbin
//  Notes:        Special AC 1, weight 1 misc
//                Fairly constant return 2
//                Requires:
//                  3 dragonscales
//                  4 bone shards
//                  1500 coins
//  Notable Changes:            
*/

#include "/players/forbin/ansi.h"
inherit "obj/armor";

#define SHORTD RED+"Horned "+HIR+"Dragon"+NORM+RED+"plate "+HIR+"Neckguard"+NORM

void reset(int arg)
{
 if(arg) return;
 ::reset(arg);

  set_name("Horned Dragonplate Neckguard");
  SetMultipleIds(({"neckguard","guard","dragonplate neckguard","horned neckguard",
  	               "horned dragonplate neckguard","shardak neckguard"}));
  set_short(SHORTD);
  set_ac(2);
  set_params("other|fire", 0, 5, "fire_special");
  set_type("misc");
  set_weight(1);
  set_value(20000);
}

void long()
{
	if(present("shardak_mark", this_player()))
	  long_desc =
	    "A finely crafted pice of armor with sweeping curves and tight\n"+
	    "interlocking joints, this neckguard is designed to protect the\n"+
	    "wearer from the dangerouly beheading strikes of bladed weapons.\n"+
	    "Two curved sections bow over the shoulders, while a third joins\n"+
	    "the pieces together to form a 'V' in the center of one's chest.\n"+
	    "The wide lip of the guard sticks up high enough to obscure the\n"+
	    "wearer's chin and is adorned with faintly glowing symbols.  As\n"+
	    "the guard sweeps around to the back of the user's head, two\n"+
	    "large horns are formed from poured dragonsteel, giving the\n"+
	    "wearer a fearsome demonic look.\n"+
      "  These boots offer protection from ["+HIR+"fire"+NORM+"].\n";
  else
    long_desc =
	    "A finely crafted pice of armor with sweeping curves and tight\n"+
	    "interlocking joints, this neckguard is designed to protect the\n"+
	    "wearer from the dangerouly beheading strikes of bladed weapons.\n"+
	    "Two curved sections bow over the shoulders, while a third joins\n"+
	    "the pieces together to form a 'V' in the center of one's chest.\n"+
	    "The wide lip of the guard sticks up high enough to obscure the\n"+
	    "wearer's chin and is adorned with faintly glowing symbols.  As\n"+
	    "the guard sweeps around to the back of the user's head, two\n"+
	    "large horns are formed from poured dragonsteel, giving the\n"+
	    "wearer a fearsome demonic look.\n";    
  ::long();
}

int do_special(object user)
{
	object nmy;
	if(!present("shardak_mark", user)) 
    return 0;
	if(!(nmy = (object)user->query_attack()))
	  return 0;
  if(!random(8))
    return 1;
  return 2;
}

int fire_special(object user)
{
  if(!present("shardak_mark", user)) 
    return 0;
  if(!random(10))
  {
    tell_object(user,
      "Your "+SHORTD+" protects you from the fire.\n"+NORM);
    tell_room(environment(user),
      (string)user->query_name()+"'s neckguard protects "+
      (string)user->query_objective()+" from the fire.\n", ({ user }) );
    return 0501;
  }
  return 0;
}		