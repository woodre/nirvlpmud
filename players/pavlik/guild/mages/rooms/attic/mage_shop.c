#include "/players/pavlik/guild/mages/rooms/ROOMS"
inherit "room/room";
reset(arg) {
  if(!arg) {
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
 "/players/pavlik/guild/mages/rooms/guild_room4", "north",
});

   }
}

query_mguild(){ return "Zinctal Shop"; }

init(){
  ::init();
  add_action("guild_move","gm");
  add_action("buy_something","buy");
  add_action("list_items","list");
  mage_check();
}

list_items(){
  write(
  "A list of inventory reads: \n"+
  "    1. Leather Cord   ............................. 200 gold\n"+
  "    2. Gemstone .................................. 1000 gold\n"+
  "    3. Peacock Feather ............................ 100 gold\n"+
  "    4. Sulfur ..................................... 700 gold\n"+
  "    5. Heartstone ................................ 1500 gold\n"+
  "    6. Silver Needle .............................. 100 gold\n"+
  "    7. Onyx Powder (2 teaspoons) .................. 900 gold\n"+
  "    8. Ivory Tusk ................................ 2000 gold\n"+
  "    9. Bag of Holding ............................. 500 gold\n"+
  "   10. Platinum Mirror .......................... 12000 gold\n"+
  "   11. Bag of Dove Feathers ...................... 1400 gold\n"+
  "   12. Tespian Orb ................................ 300 gold\n"+
  "   13. Amber Rod ................................. 1500 gold\n"+
  "   14. Golden Circlet ............................. 800 gold\n"+
  "   15. <more soon> .......................1,823,111,590 gold\n"+
  "\n"+
  "use 'buy <#>'.\n");
  return 1;
}

buy_something(str){
  object obj;
  int value;

  if(str == "1"){
    obj = clone_object("obj/treasure");
    obj->set_id("leather cord");
    obj->set_alias("cord");
    obj->set_short("A leather cord");
    obj->set_long("A leather cord.\n");
    obj->set_weight(1);
    obj->set_value(50);
    value = 200;
  }
  else if(str == "2"){
    obj = clone_object("obj/treasure");
    obj->set_id("gem_stone");
    obj->set_alias("gemstone");
    obj->set_short("A Gemstone");
    obj->set_long("A small semi-precious gemstone.\n");
    obj->weight(1);
    obj->set_value(600);
    value = 1000;
  }
  else if(str == "3"){
    obj = clone_object("obj/treasure");
    obj->set_id("peacock_feather");
    obj->set_alias("feather");
    obj->set_short("A peacock feather");
    obj->set_long("A colorful peacock feather.\n");
    obj->set_weight(1);
    obj->set_value(75);
    value = 100;
    }
  else if(str == "4"){
    obj = clone_object("obj/treasure");
    obj->set_id("sulfur");
    obj->set_alias("sulfur");
    obj->set_short("A bit of sulfur");
    obj->set_long("A bit of sulfur.\n");
    obj->set_weight(1);
    obj->set_value(500);
    value = 700;
    }
  else if(str == "5"){
    obj = clone_object("players/pavlik/guild/mages/obj/heartstone");
    value = 1500;
    }
  else if(str == "6"){
    obj = clone_object("obj/treasure");
    obj->set_id("silver needle");
    obj->set_alias("needle");
    obj->set_short("A Silver Needle");
    obj->set_long("A Silver Needle.\n");
    obj->set_weight(0);
    obj->set_value(50);
    value = 100;
    }
  else if(str == "7"){
    obj = clone_object("obj/treasure");
    obj->set_id("onyx powder");
    obj->set_alias("powder");
    obj->set_short("A bit of Onyx Powder");
    obj->set_long("Two teaspoons of Onyx Powder.\n");
    obj->set_weight(0);
    obj->set_value(500);
    value = 900;
    }
  else if(str == "8"){
    obj = clone_object("obj/treasure");
    obj->set_id("ivory tusk");
    obj->set_alias("tusk");
    obj->set_short("An Ivory Tusk");
    obj->set_long("A long white ivory tusk.\n");
    obj->set_weight(1);
    obj->set_value(1000);
    value = 2000;
    }
  else if(str == "9"){
    obj = clone_object("players/pavlik/guild/mages/obj/bag_holding");
    value = 500;
    }
  else if(str == "10"){
    obj = clone_object("obj/treasure");
    obj->set_id("platinum mirror");
    obj->set_alias("mirror");
    obj->set_short("A Platinum Mirror");
    obj->set_long("A tiny sheet of platinum.\nIt is shiny enough to be a mirror.\n");
    obj->set_weight(1);
    obj->set_value(5000);
    obj->set_save_flag(0);
    value = 12000;
    }
  else if(str == "11"){
    obj = clone_object("players/pavlik/items/dove_feathers");
    value = 1400;
    }
  else if(str == "12"){
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
  else if(str == "13"){
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
  else if(str == "14"){
    obj = clone_object("players/pavlik/guild/mages/obj/strangle_obj");
    value = 800;
  }
  else {
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
  return 1;
}
