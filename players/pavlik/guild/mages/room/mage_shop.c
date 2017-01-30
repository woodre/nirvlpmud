#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "/players/pavlik/guild/mages/inherit/room";
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="The Zinctal Shop";
  long_desc=
	"You are in the Zinctal Shop, a tiny store owned and operated by the\n"+
	"Mage's Tower.  The Zinctal Shop sells the components Wizards require\n"+
	"when casting thier spells.  A strong herbal aroma overpowers your\n"+
	"senses as soon as you enter the room.  There is a small sign on the\n"+
	"counter, other than that the store appears empty.\n";

  items=({
    "sign",
	"=-=-=-=--  Zinctal Shop  --=-=-=-=\n"+
	" Honored Magi,\n"+
	"Our goods are yours for the buying.\n"+
	"May these items serve you well.\n"+
	"  'list' -- list inventory\n"+
	"  'buy <#>' -- make a purchase\n"+
	"              the Mages Guild",
  });

  dest_dir=({
	ROOM_DIR+"guild_room4", "north",
  });

}

query_mguild(){ return "Zinctal Shop"; }

init(){
  ::init();
  if(!mage_check()) return;
  add_action("guild_move","gm");
  add_action("buy_something","buy");
  add_action("list_items","list");
}

list_items(){
  write(
  "A list of inventory reads: \n"+
  "    1. Leather Cord   ............................. 200 gold\n"+
  "    2. Gemstone .................................. 1000 gold\n"+
  "    3. Sulfur Powder............................... "+ACID_COMPONENT_COST+" gold\n"+
  "    4. Heartstone ................................ "+SUMMON_COMPONENT_COST+" gold\n"+
  "    5. Silver Needle .............................. "+SDAGGER_COMPONENT_COST+" gold\n"+
  "    6. Onyx Powder (2 teaspoons) .................. "+ESHIELD_COMPONENT_COST+" gold\n"+
  "    7. Bag of Holding ............................. 500 gold\n"+
  "    8. Platinum Mirror ........................... "+MIMAGE_COMPONENT_COST+" gold\n"+
  "    9. Tespian Orb ................................ 300 gold\n"+
  "   10. Amber Rod ................................. 1500 gold\n"+
  "   11. Granite Powder ............................. "+STONESKIN_COMPONENT_COST+" gold\n"+
  "   12. Spider ..................................... 500 gold\n"+
  "   13. Orb of Souls ............................... 300 gold\n"+
  "   14. Light Feather .............................. 1000 gold\n"+
  "   15. Mage Component Pouch ....................... 1500 gold\n"+
  "\n"+
  "use 'buy <#>'.\n");
  return 1;
}

buy_something(str){
  object obj;
  int value;

  if(str == "1")
  {
	obj = clone_object("obj/treasure");
	obj->set_id("leather cord");
	obj->set_alias("cord");
	obj->set_short("A leather cord");
	obj->set_long("A leather cord.\n");
	obj->set_weight(1);
	obj->set_value(50);
	value = 200;
  }
  else if(str == "2")
  {
	obj = clone_object("obj/treasure");
	obj->set_id("gem_stone");
	obj->set_alias("gemstone");
	obj->set_short("A Gemstone");
	obj->set_long("A small semi-precious gemstone.\n");
	obj->weight(1);
	obj->set_value(600);
	value = 1000;
  }
  else if(str == "3")
  {
	obj = clone_object("obj/treasure");
	obj->SetMultipleIds(({"sulfur", "powder", "sulfur powder", ACID_COMPONENT_ID}));
	obj->set_short("Sulfur Powder (1 pinch)");
	obj->set_long("A pinch of sulfur powder.\n");
	obj->set_weight(1);
	obj->set_value(500);
	value = ACID_COMPONENT_COST;
  }
  else if(str == "4")
  {
	obj = clone_object(OBJ_DIR + "heartstone");
	value = SUMMON_COMPONENT_COST;
  }
  else if(str == "5")
  {
	obj = clone_object("obj/treasure");
	obj->SetMultipleIds(({"needle", "silver needle", SDAGGER_COMPONENT_ID}));
	obj->set_short("A Silver Needle");
	obj->set_long("A Silver Needle.\n");
	obj->set_weight(0);
	obj->set_value(50);
	value = SDAGGER_COMPONENT_COST;
  }
  else if(str == "6")
  {
	obj = clone_object("obj/treasure");
	obj->SetMultipleIds(({"powder", "onyx powder", "onyx powder", ESHIELD_COMPONENT_ID}));
	obj->set_short("A bit of Onyx Powder");
	obj->set_long("Two teaspoons of Onyx Powder.\n");
	obj->set_weight(0);
	obj->set_value(500);
	value = ESHIELD_COMPONENT_COST;
  }
  else if(str == "7")
  {
        obj = clone_object("/players/saber/stuff/mbag");
	value = 500;
  }
  else if(str == "8")
  {
	obj = clone_object("obj/treasure");
	obj->SetMultipleIds(({"mirror", "platinum mirror", MIMAGE_COMPONENT_ID}));
	obj->set_short("A Platinum Mirror");
	obj->set_long("A tiny sheet of platinum.\nIt is shiny enough to be a mirror.\n");
	obj->set_weight(1);
	obj->set_value(5000);
	obj->set_save_flag(0);
	value = MIMAGE_COMPONENT_COST;
  }
  else if(str == "9")
  {
	obj = clone_object("obj/treasure");
	obj->set_id("tespian orb");
	obj->set_alias("orb");
	obj->set_short("A Tespian Orb");
	obj->set_long("A sphere of fagile tespian glass.\n");
	obj->set_weight(0);
	obj->set_value(150);
	obj->set_save_flag(0);
	value = 300;
  }
  else if(str == "10")
  {
	obj = clone_object("obj/treasure");
	obj->set_id("amber rod");
	obj->set_alias("rod");
	obj->set_short("An Amber Rod");
	obj->set_long("A rod of golden amber.\n");
	obj->set_weight(0);
	obj->set_value(500);
	obj->set_save_flag(0);
	value = 1500;
  }
  else if(str == "11")
  {
	obj = clone_object("obj/treasure");
	obj->SetMultipleIds(({"powder", "granite powder", STONESKIN_COMPONENT_ID}));
	obj->set_short("Granite Powder");
	obj->set_long("A pile of granite powder.\n");
	obj->set_weight(0);
	obj->set_value(650);
	obj->set_save_flag(0);
	value = STONESKIN_COMPONENT_COST;
  }
  else if(str == "12")
  {
    obj = clone_object("/obj/treasure");
    obj->SetMultipleIds(({"spider"}));
    obj->set_short("Spider");
    obj->set_long("A tiny black spider.\n");
    obj->set_value(500);
    obj->set_save_flag(0);
    value = 500;
  }
  else if(str == "13")
  {
    obj = clone_object("/obj/treasure");
    obj->SetMultipleIds(({"orb of souls","orb"}));
    obj->set_short("Orb of Souls");
    obj->set_long("A chromatic, clear orb.\n");
    obj->set_value(300);
    obj->set_save_flag(0);
    value = 300;
    
  }
  else if(str == "14")
  {
    obj = clone_object("/obj/treasure");
    obj->SetMultipleIds(({"feather","light feather"}));
    obj->set_short("Light feather");
    obj->set_long("A light feather.\n");
    obj->set_value(500);
    obj->set_save_flag(0);
    value = 1000;
  }
 else if(str == "15")
  {
    obj = clone_object("/players/pavlik/guild/mages/objects/pouch");
     value = 1500;
  }
  else
  {
	value = -1;
  }

  if(value == -1){
	write("No such item.\n");
	return 1;
  }
  if(this_player()->query_money() < value){
	write("You do not have enough money.\n");
	return 1;
  }

  write("You purchase "+obj->short()+" for "+value+" coins.\n");
  move_object(obj, this_player());
  this_player()->add_money(-value);
  if(!obj->id("bag") && !obj->id("pouch"))
  {
    object pouch;
    if(!(pouch = present("mage's component pouch", this_player())))
    {
      return 1;
    }
    else
    {
      move_object(obj, pouch);
    }
  }
  return 1;

}
