/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2004 Forbin
//                  All Rights Reserved.
//  Realm:        The Ruins (/players/forbin/realms/ruins/)
//  Function:     NPC Daemon
//  Create Date:  2004.07.29
//  Last Edit:    2004.07.29 -Forbin
//  Notable Changes: 
//    2005.01.24 -added dtype protections/weakness to both ice and fire types 
*/ 

#include "/players/forbin/realms/ruins/ruinsdefine.h"
#include "/players/forbin/logging.h"
#pragma combine_strings
inherit "/players/vertebraker/closed/std/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("daemon");
  set_alt_name("archangel");
  set_short("Archangel DAEMON");
}

initialize(mixed arg) {
  object mob;
  string type;
  int wc, ac;  
  if(!arg) {
    switch(random(2)) {
      case 0: wc = 26; ac = 15; type = "ice"; break;
      case 1: wc = 29; ac = 13; type = "fire"; break;
      default: wc = 26; ac = 15; type = "ice"; break;
    }
  }
  else 
    wc = arg[0]; ac = arg[1]; type = arg[2]; 
  mob = previous_object();
  mob->set_name("figure");
  mob->set_short("A dark figure");
  if(type == "ice") {
    mob->set_long(
      "  Before you is a figure dressed in blue tinted robes. Its hands,\n"+
      "feet, and face are completely covered by the drooping robe, allowing\n"+
      "no hints too what might lay beneath.  You feel a cold rush of air and\n"+
      "a chill that permeates the air.\n");
    mob->set_hp(40);
    mob->load_chat("You feel a cold draft rush at you from somewhere in the room.\n");
    mob->load_chat("The figure stands looking at you, its unseen eyes studying you.\n");
  }
  if(type == "fire") {
    mob->set_long(
      "  Standing before you is a tall figure.  Its dark frame is shrouded\n"+
      "in a long coat which covers it from the shoulders down to its booted\n"+
      "feet.  Its head is covered with some sort of black cloth, with no\n"+
      "visible eyeholes.  It stands perfectly still, carefully watching you.\n");
    mob->set_hp(40);
    mob->load_chat("You feel heat eminating from somewhere in the room.\n");
    mob->load_chat("The figure stands looking at you, its unseen eyes studying you.\n");    
  }  
  mob->set_al(-random(1000));
  mob->set_level(18);  
  mob->set_wc(wc);
  mob->set_ac(ac);
  mob->set_chat_chance(5);    
  mob->set_heart_beat(2);
  mob->set_dead_ob(previous_object());
  mob->set_changed(0);
}

change(mixed arg) {
  object mob;
  object wep;
  int wc, ac;
  string type, weppath, wepname;  
  if(!arg) {
    switch(random(2)) {
      case 0: wc = 26; ac = 15; type = "ice"; weppath = "ice_cleaver.c"; wepname ="cleaver"; break;
      case 1: wc = 29; ac = 13; type = "fire"; weppath = "flaming_sword.c"; wepname ="sword";break;
      default: wc = 26; ac = 15; type = "ice"; weppath = "ice_cleaver.c"; wepname ="cleaver";break;
    }
  } 
  else 
    wc = arg[0]; ac = arg[1]; type = arg[2]; weppath = arg[3]; wepname = arg[4];
  mob = previous_object();
  if(type == "ice") {
    tell_room(environment(mob),
    "\n\n\n\n   The dark figure's clothes shread as "+HIC+"Crystalline Armor"+NORM+""+
      " grows from beneath!\n\n\n\n"+
    "          Now standing before you is an "+HIC+"Archangel of Ice."+NORM+"\n\n\n");
    mob->set_short("An Archangel of "+HIC+"Ice"+NORM+"");
    mob->set_long(
    "  Now standing before you is a being of pure evil, its body protected\n"+
    "by a shell of crystalline ice.  You look into its eyes and see that\n"+
    "they are twin orbs of pure blue, leaving you with a feeling of little\n"+
    "humanity.  Wielded in its hand is a huge "+wepname+", gleaming with\n"+
    "a frosty coating.  This creature seems impenetrable in its armor.\n");
    mob->set_name("Archangel of Ice");
    mob->load_a_chat("The Archangel's eyes "+HIC+"GLOW "+NORM+"with a cold rage.\n");
    mob->load_a_chat("The Archangel snarls with anger as his "+wepname+" strikes at you!\n");
    mob->load_a_chat("The Archangel's crystalline form deflects some of the damage.\n");
    mob->set_armor_params("other|ice",0,100,0);   /* no damage from other|ice */
    mob->set_armor_params("other|water",0,-50,0); /* one and one half damage from other|water */    
    mob->set_armor_params("other|fire",0,-100,0); /* double damage from other|fire */    
    if(!random(2)) 
      mob->add_spell("ice",
      "\tYou scream in pain as twin rays of pure $HC$ICE$N$ slam into you.\n",
      "The Archangel's eyes fire twin rays of pure $HC$ICE$N$ at #CTN#.\n",
      5, "5-15", "other|ice", 0);
    else 
      mob->add_spell("ice",
      "\tYour skin freezes as a cone of $HC$FROST$N$ envelopes you.\n",
      "#CTN# is enveloped in a cone of $HC$FROST$N$.  #CTO# screams in pain.\n",
      10, "5-10", "other|ice", 0);
    mob->set_death_chat(
    "As the Archangel dies you see its armor shatter, its hand crumbling and\n"+
    "allowing its weapon to fall from its grasp.  It clatters to the ground\n"+
    "with a loud clang.\n\n\n"+
    "\n\nThe body immediately melts leaving a blackened puddle of water.\n");       
  }
  if(type == "fire") {
    tell_room(environment(mob),
    "\n\n\n\n   The dark figure's clothes shread in a "+HIR+"FIERY Explosion"+NORM+"!\n\n\n\n"+
    "          Now standing before you is an "+HIR+"Archangel of Fire."+NORM+"\n\n\n");
    mob->set_short("An Archangel of "+HIR+"Fire"+NORM+"");
    mob->set_long(
    "  Quite different that its original form, this creature now burns\n"+
    "bright with a flaming aura.  With the cloth and coat burned away you\n"+
    "now see the true features of it.  Its head is covered with short white\n"+
    "hair, its eyes nearly the same color.  Its skin is charcoal black and\n"+
    "its torso, arms, and legs are covered with redish tinged armor.  A\n"+
    "flaming "+wepname+" is held ready in his grip, burning brightly.  Huge\n"+
    "flaming wings spread out from its back, sending out flaming waves of\n"+ 
    "of heat.  You detect no humanity eminating from this thing of evil.\n");
    mob->set_name("Archangel of Fire");
    mob->load_chat("You feel heat eminating from somewhere in the room.\n");
    mob->load_chat("The figure stands looking at you, its unseen eyes studying you.\n");
    mob->load_a_chat("The Archangel's eyes "+RED+"BLAZE"+NORM+" with rage.\n");
    mob->load_a_chat("The Archangel snarls with anger as his "+wepname+" strikes at you!\n");
    mob->load_a_chat("The Archangel's fiery wings rake the air with searing heat.\n");
    mob->set_armor_params("other|fire",0,100,0);   /* no damage from other|fire */
    mob->set_armor_params("other|ice",0,-50,0);    /* one and one half damage from other|ice */    
    mob->set_armor_params("other|water",0,-100,0); /* double damage from other|water */    
    if(!random(2)) 
      mob->add_spell("fire",
      "\n\tFire steams from the Archangel's outstretched hand towards you...\n"+
      "\t\tYou scream in pain $HR$FIRE$N$ engulfs you.\n",
      "$HR$FIRE$N$ streams from the Archangel's outstretched hand towards #CTN#.\n",
       5, "5-15", "other|fire", 0);
    else
      mob->add_spell("fire",
      "\tThe Archangel $HW$SLICES$N$ you with the tip of its $HR$FIERY$N$ wing.\n",
      "The Archangel $HW$SLICES$N$ #CTN# with the tip of its $HR$FIERY$N$ wing.\n",
      10, "5-10", "other|fire", 0);
    mob->set_death_chat(      
    "As the Archangel dies you see his flaming "+wepname+" fall from his limp hand,\n"+
    "clattering to the ground loudly.\n\n\n"+
    "\n\nA searing heat encompasses the corpse, burning it into ashes.\n");      
  }  
  mob->set_race("archangel"); 
  mob->set_changed(1);
  wep = clone_object(OBJ+weppath);
  move_object(wep, mob);
  command("wield weapon", mob);
  mob->set_wc(wc);
  mob->set_ac(ac);
  mob->set_a_chat_chance(15);  
}


    
