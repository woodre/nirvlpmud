#include "../def.h"

inherit "/players/forbin/mages/npc/master.c";

string m_name()          { return "Jurgen"; }
string m_school()        { return "necr"; }
string m_school_proper() { return "Necromancy"; }
string m_attribute()     { return ""; }
string m_attribute_proper() { return ""; }
string m_list_heading()  
{ 
  return "                     "+TGC+"Necromancy"+NORM+"                       "; 
}


id(str) 
{ 
  return (::id(str) || str == "jurgen" || str == "mortus"  
                    || str == "jurgen mortus" || str == "necromancer"); 
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
  item->set_short(HIK+"Mage's robes"+NORM);
  item->set_long(
    "This is a long description that no one should ever see.\n");
  item->set_ac(0);
  move_object(item, this_object());
  init_command("wear robe");
  
  item = clone_object("/obj/armor.c");
  item->set_weight(1);
  item->set_value(500);
  item->set_type("misc");
  item->set_name("cloak");
  item->set_short(HIK+"A hooded cloak"+NORM);
  item->set_long(
    "This is a long description that no one should ever see.\n");
  item->set_ac(0);
  move_object(item, this_object());
  init_command("wear cloak");
  
  item = clone_object("/obj/treasure.c");
  item->set_weight(1);
  item->set_value(500);
  item->set_name("spellbook");
  item->set_short(HIK+"Jurgen Mortus' Magic Spellbook "+HIR+"["+NORM+RED+"*"+HIR+"]"+NORM);
  item->set_long(
    "This is a long description that no one should ever see.\n");
  move_object(item, this_object());  
  
  item = clone_object("/obj/armor.c");
  item->set_weight(1);
  item->set_value(500);
  item->set_type("amulet");
  item->set_name("soulcatcher");
  item->set_short(HIK+"A soul"+HIR+"(x)"+HIK+"catcher"+NORM);
  item->set_long(
    "This is a long description that no one should ever see.\n");
  item->set_ac(0);
  move_object(item, this_object());
  init_command("wear amulet");
  
  set_name("Jurgen Mortus");
  set_race("human");
  set_gender("male");
  set_short("Jurgen Mortus, "+HIK+"the Necromancer"+NORM);
  set_level(100);
  set_hp(100000);
  set_al(-666);
  set_wc(80);
  set_ac(80);
  Busy = 0;
}

long(string str)
{
	object gob;
  long_desc =
    "A sizable man of many years, Jurgen studied the necromantic arts\n"+
    "for man years before abandoning the Realm of Death in order to teach\n"+
    "others the skills of manipulating such dark powers.  His ebony robes\n"+
    "appear to draw in the surrounding light, and a large cloak is tied\n"+
    "around his thick neck, its hood draped carefully across his back.\n";  
  if((gob = present("forbin_mage_object", this_player())))
    long_desc += 
      "  Jurgen may "+SGC+"["+PGC+"teach"+SGC+"]"+NORM+
      " you necromantic spells and can "+SGC+"["+PGC+"raise"+SGC+"]"+NORM+" your\n"+
      "ability in the school of necromancy.  Just speak what you wish to do.\n"+
      "You may type "+SGC+"["+PGC+"master help"+SGC+"]"+NORM+" for more information.\n";   
  ::long();
}
