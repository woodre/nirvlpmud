#include "../def.h"

inherit "/players/forbin/mages/npc/master.c";

string m_name()          { return "Lucius"; }
string m_school()        { return "abju"; }
string m_school_proper() { return "Abjuration"; }
string m_attribute()     { return "power"; }
string m_attribute_proper() { return "Power"; }
string m_list_heading()  
{ 
  return "                             "+TGC+"Abjuration"+NORM+"                              ";
}

id(str) 
{ 
  return (::id(str) || str == "lucius" || str == "bane"  
                    || str == "lucius bane"); 
}

reset(arg)  
{
  object item;
  if(arg) return;  
  ::reset(arg);
  
  item = clone_object("/obj/armor.c");
  item->set_weight(1);
  item->set_value(500);
  item->set_type("armor");
  item->set_name("robe");
  item->set_short(HIB+"Mage's robes"+NORM);
  item->set_long(
    "This is a long description that no one should ever see.\n");
  item->set_ac(0);
  move_object(item, this_object());
  init_command("wear robe");

  item = clone_object("/obj/treasure.c");
  item->set_weight(1);
  item->set_value(500);
  item->set_name("spellbook");
  item->set_short(BLU+"Lucius Bane's Magic Spellbook "+BLU+"["+HIB+"*"+NORM+BLU+"]"+NORM);
  item->set_long(
    "This is a long description that no one should ever see.\n");
  move_object(item, this_object());    
  
  item = clone_object("/obj/weapon.c");
  item->set_weight(2);
  item->set_class(10);
  item->set_type("club");
  item->set_alias("staff");
  item->set_name("ironwood");
  item->set_short("A Staff of Ironwood "+BLU+"["+HIB+"*"+NORM+BLU+"]"+NORM);
  item->set_long(
    "This is a long description that no one should ever see.\n");
  item->set_value(1400);
  move_object(item, this_object());  
  
  set_name("Lucius Bane");
  set_race("human");
  set_gender("male");
  set_short("Lucius Bane");
  set_level(100);
  set_hp(100000);
  set_al(500);
  set_wc(80);
  set_ac(80);
  Busy = 0;
}

long(string str)
{
	object gob;
  long_desc =
    "Lucius stands, arms akimbo, in a clearly contemplative process of\n"+ 
    "thought.  He is a short, slender man of obvious means, indicated by\n"+
    "his wonderfully tailored blue silk robe.  An authority on the magic\n"+
    "of abjuration, he is skilled at spells of protection.\n";  
  if((gob = present("forbin_mage_object", this_player())))
    long_desc += 
      "  Lucius may "+SGC+"["+PGC+"teach"+SGC+"]"+NORM+
      " you spells of abjuring and can "+SGC+"["+PGC+"raise"+SGC+"]"+NORM+" your\n"+
      "ability in the school of abjuration.  Just speak what you wish to do.\n"+
      "You may type "+SGC+"["+PGC+"master help"+SGC+"]"+NORM+" for more information.\n";   
  ::long();
}

