/* Spine Armor 12/2001_Forbin  */
/* Modified from:              */
/* /open/snow/darkarmor.c      */

inherit "/obj/armor.c";
#include "/players/forbin/ansi.h"
string arm;
reset(arg) {
  int i;
int t;
  ::reset(arg);
  if(arg) return;
  i = random(6);
  switch(i) {
  case 1: arm = "cloak"; set_type("misc"); break;
  case 2: arm = "gauntlets"; set_type("ring"); break;
  case 3: arm = "talisman"; set_type("amulet"); break;
  case 4: arm = "warboots"; set_type("boots"); break;
  case 5: arm = "shield"; set_type("shield"); break;
  case 6: arm = "hood"; set_type("helmet"); break;
  default: arm = "armor"; set_type("armor"); break;
  }
  set_name(arm);
   set_short(HIK + "Spine " + capitalize(arm) + NORM);
  if(i == 1 )
  {
	  t = random(14);
      if (t < 11)
      {
      	set_ac(1);
      	set_value(random(500)+150);
      	set_long(
        "Crudely-woven, this cloak seems to make been made of rough, scratchy\n"+
        "wool.  It seems much too thin to offer much protection from the\n"+
        "elements or in battle.\n");
      	set_weight(1);
   	  }
   	  else if (t > 10 && t < 13)
   	  {
      	set_ac(1);
      	set_value(random(400)+250);
      	set_long(
        "This cloak is made from finely-woven material, though you cannot judge\n"+
        "quite what it is made from.  It is of very fine quality, yet feels\n"+
        "strong enough to offer some defense.\n");
      	set_weight(1);
   	  }
   	  else
      {
      	set_ac(2);
      	set_value(random(400)+1000);
      	set_long(
        "This cloak is made from finely-woven material, though you cannot judge\n"+
        "quite what it is made from.  It is of very fine quality, yet feels\n"+
        "strong enough to offer some defense.  An "+HIK+"aura of wickedness"+NORM+" "+
        "surrounds it.\n");
      	set_weight(2);
   	  }
  }
  if(i == 2 ) {
  t = random(14);
    if (t < 11) {
      set_ac(1);
      set_value(random(500)+150);
      set_long(
        "A dirty pair of gauntlets that seem to need a little cleaning.  Rough\n"+
        "and rusty, they appear to have seen much use throughout the years.\n");
      set_weight(1);
    }
    else if (t > 10 && t < 13) {
      set_ac(1);
      set_value(random(400)+250);
      set_long(
        "Strong and menacing to behold, this pair of gauntlets are forged from\n"+
        "a dark unknown metal.  Covered in spikes, they would make both a\n"+
        "formidable defense or weapon in battle.\n");
      set_weight(1);
    }
    else {
      set_ac(2);
      set_value(random(400)+1000);
      set_long(
        "Strong and menacing to behold, this pair of gauntlets are forged from\n"+
        "a dark unknown metal.  Covered in spikes, they would make a formidable\n"+
        "defense or weapon in battle.  An "+HIK+"aura of wickedness"+NORM+" surrounds them\n");
      set_weight(2);
    }
  }
  if(i == 3 ) {
  t = random(14);
    if (t < 11) {
      set_ac(1);
      set_value(random(500)+150);
      set_long(
        "A black talisman hangs from a tattered woven cord.  An emblem of a\n"+
        "star and a moon the front.\n");
      set_weight(1);
    }
    else if (t > 10 && t < 13) {
      set_ac(1);
      set_value(random(400)+250);
      set_long(
        "A beautiful star shaped talisman, hung from a strong, leather\n"+
        "choker.  Strange emblems and sigils adorn its surface and give\n"+
        "off an muted glow.\n");
      set_weight(1);
    }
    else {
      set_ac(2);
      set_value(random(400)+1000);
      set_long(
        "A beautiful star shaped talisman, hung from a strong, leather\n"+
        "choker.  Strange emblems and sigils adorn its surface and give\n"+
        "off an muted glow.  An "+HIK+"aura of wickedness"+NORM+" "+
        "surrounds it.\n");
      set_weight(2);
    }
  }
  if(i == 4 ) {
  t = random(14);
    if (t < 11) {
      set_ac(1);
      set_value(random(500)+150);
      set_long(
        "A tattered set of Warboots.  Made from leather, its metal buckles and\n"+
        "clasps are barely visible beneath the caked on mud.\n");
      set_weight(1);
    }
    else if (t > 10 && t < 13) {
      set_ac(1);
      set_value(random(400)+250);
      set_long(
        "A gleaming pair of Warboots.  Made from fine leather, they are polished\n"+
        "to a high sheen, and have several metal buckles and clasps about them.\n"+
        "A thick, metal place encases the toe of the boots giving added them \n"+
        "protection.\n");
      set_weight(1);
    }
    else {
      set_ac(2);
      set_value(random(400)+1000);
      set_long(
        "A gleaming pair of Warboots.  Made from fine leather, they are polished\n"+
        "to a high sheen, and have several metal buckles and clasps about them.\n"+
        "A thick, metal place encases the toe of the boots giving added them \n"+
        "protection.  An "+HIK+"aura of wickedness"+NORM+" surrounds them.\n");
      set_weight(2);
    }
  }
  if(i == 5 ) {
  t = random(14);
    if (t < 11) {
      set_ac(1);
      set_value(random(500)+150);
      set_long(
        "A simple looking shield made from stretching some poor animal's hide\n"+
        "over a wooden frame.  Worn by both use and age, it looks as if it\n"+
        "might shatter should it take a solid hit.\n");
      set_weight(1);
    }
    else if (t > 10 && t < 13) {
      set_ac(1);
      set_value(random(400)+250);
      set_long(
        "A large, oval shield made from a very heavy metal.  It is dark black\n"+
        "in color, and many spikes radiate from its center.  A very nasty\n"+
        "looking shield indeed.\n");
      set_weight(1);
    }
    else {
      set_ac(2);
      set_value(random(400)+1000);
      set_long(
        "A large, oval shield made from a very heavy metal.  It is dark black\n"+
        "in color, and many spikes radiate from its center.  A very nasty\n"+
        "looking shield indeed.  An "+HIK+"aura of wickedness"+NORM+" "+
	  "surrounds them.\n");
      set_weight(2);
    }
  }
  if(i == 6 ) {
  t = random(14);
    if (t < 11) {
      set_ac(0);
      set_value(random(500)+150);
      set_long(
        "Basically just a round, iron circlet, it seems more apt as decoration\n"+
        "than to protect the wearer.\n");
      set_weight(1);
    }
    else if (t > 10 && t < 13) {
      set_ac(0);
      set_value(random(400)+250);
      set_long(
        "A monstrosity of a helmet.  Large and heavy, horns and spines jut out\n"+
        "from around this helm.\n");
      set_weight(2);
    }
    else {
      set_ac(1);
      set_value(random(400)+1000);
      set_long(
        "A monstrosity of a helmet.  Large and heavy, horns and spines jut out\n"+
        "from around this helm.  An "+HIK+"aura of wickedness"+NORM+" " +
	  "surrounds them.\n");
      set_weight(2);
    }
  }
  if(i == 0 ) {
  t = random(14);
    if (t < 11) {
      set_ac(random(2)+1);
      set_value(ac*300);
      set_long(
        "A unique piece of armor this is - bonemail.  The black bones of some\n"+
        "unfortunate creature have been woven into armor somewhat resembling\n"+
        "chainmail.  It makes an awful racket when moved, but seems like it\n"+
        "could take a great deal of punishment before it becomes damaged.\n");
      set_weight(ac);
    }
    else if (t > 10 && t < 13) {
      set_ac(random(2)+3);
      set_value(ac*300);
      set_long(
        "A great chestpiece made of bone and metal.  Though made from very\n"+
        "crude raw materials, it looks finely-crafted and durable.  Spikes\n"+
        "and spines protrude from it and looks difficult to put on without\n"+
        "hurting oneself.\n");
      set_weight(ac);
    }
    else {
      set_ac(random(2)+4);
      set_value(ac*300);
      set_long(
        "A great chestpiece made of bone and metal.  Though made from very\n"+
        "crude raw materials, it looks finely-crafted and durable.  Spikes\n"+
        "and spines protrude from it and looks difficult to put on without\n"+
        "hurting oneself.  An "+HIK+"aura of wickedness"+NORM+" "+
	  "surrounds them.\n");
      set_weight(ac);
    }
  }
}