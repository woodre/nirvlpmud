inherit "/obj/monster.c";
#include "/players/jareel/define.h"

  reset(arg){
    string str;
    object gold;
    ::reset(arg);
  if(arg) return;
 
  set_name(BOLD+"Karn"+NORM+" - "+HIY+"Yelmalian"+NORM+" Blacksmith"+NORM);
  set_alias("karn");
  set_alt_name("blacksmith");
  set_race("human");
  set_short(BOLD+"Karn"+NORM+" - "+HIY+"Yelmalian"+NORM+" Blacksmith"+NORM);
  set_long(
    "Long soot filled blond hair flows from Karns bronze skin.\n"+
    "His muscles bulge as he moves around the small quaint shop.\n"+
    "Years of service have creased his face and furrowed his \n"+
    "brow.  This is an imposing figure that should not be taken\n"+
    "lightly.\n");
  set_level(21);
  set_hp(1000);
  set_al(0);
  MOCO("/players/jareel/weapons/YELMALIAN/blacksmithhammer.c"),this_object());
    init_command("wield hammer");
  set_heal(40,1);
  set_wc(50);
  set_ac(75);
  gold = clone_object("obj/money");
  gold->set_money(random(5000) + 3000);
  move_object(gold,this_object());
  set_chat_chance(10);
    load_chat(
      "Karn says: 'Are you joining the hunting party to go after the Crimson Bat?.'\n");
    load_chat(
      "Karn says: 'Do you want to buy something?'\n");
    load_chat( 
      "Karn says: 'I can make something out of the hides of those damn Dark Demons.'\n");
    load_chat(
      "Karn strikes his hammer.'\n");
    load_chat(
      "The Sun Forge heats the room.\n");
    load_chat(
      "Karn says: 'If you want a 'list' of item just ask for it.'\n");
}

  init(){
    ::init();
    add_action("order","buy");
    add_action("list","list");
}

  list(){
    write("Karn says: here is my list of items:\n");
    write("\n");
    write("  COST   HIDE    ITEM   ||    COST   HIDE    ITEM\n");
    write("  2000    3     Helmet  ||    2000    1     Necklace\n");
    write("  2000    5     Shield  ||    2000    2     Bracelet\n");
    write("  2000    2     Amulet  ||    2000    3     Chest\n");
    write("  2000    3     Boots   ||    2000    4     Cloak\n");
    write("  2000    1     Ring    ||    2000    1     Earring\n");
    write("  2000    2     Belt    ||    2000    2     Gloves\n");
    write("  5000    10    Armor   ||    2000    4     Pants\n");
    write("  2000    3     Misc    ||    2000    2     Underwear\n");
    write("\n");
    write("\n");
  return 1;
}

order(string str){
    int cost;
    string file;
  switch(str){
  case "amulet":
    cost = 2000;
    file = "/players/jareel/armor/DWARFFORGE/demon/amulet.c";
  break;
  case "armor":
    cost = 5000;
    file = "/players/jareel/armor/DWARFFORGE/demon/armor.c";
  break;
  case "belt":
    cost = 2000;
    file = "/players/jareel/armor/DWARFFORGE/demon/belt.c";
  break;
  case "boots":
    cost = 2000;
    file = "/players/jareel/armor/DWARFFORGE/demon/boots.c";
  break;
  case "bracelet":
    cost = 2000;
    file = "/players/jareel/armor/DWARFFORGE/demon/bracelet.c";
  break;
  case "chest":
    cost = 2000;
    file = "/players/jareel/armor/DWARFFORGE/demon/chest.c";
  break;
  case "earring":
    cost = 2000;
    file = "/players/jareel/armor/DWARFFORGE/demon/earring.c";
  break;
  case "gloves":
    cost = 2000;
    file = "/players/jareel/armor/DWARFFORGE/demon/gloves.c";
  break;
  case "helmet":
    cost = 2000;
    file = "/players/jareel/armor/DWARFFORGE/demon/helmet.c";
  break;
  case "misc":
    cost = 2000;
    file = "/players/jareel/armor/DWARFFORGE/demon/misc.c";
  break;
  case "necklace":
    cost = 2000;
    file = "/players/jareel/armor/DWARFFORGE/demon/necklace.c";
  break;
  case "pants":
    cost = 2000;
    file = "/players/jareel/armor/DWARFFORGE/demon/pants.c";
  break;
  case "ring":
    cost = 2000;
    file = "/players/jareel/armor/DWARFFORGE/demon/ring.c";
  break;
  case "cloak":
    cost = 2000;
    file = "/players/jareel/armor/DWARFFORGE/demon/cloak.c";
  break;
  case "shield":
    cost = 2000;
    file = "/players/jareel/armor/DWARFFORGE/demon/shield.c";
  break;
  case "underwear":
    cost = 2000;
    file = "/players/jareel/armor/DWARFFORGE/demon/underware.c";
  break;
  default:
    notify_fail("Talieos says: What was that you wanted to buy?\n");
    return 0;
  break;
}
  if(!present("ademonhide",this_player())){
    notify_fail("Karn says: You more raw material for that.\n");
    return 0;
  }
  if(str == "helmet" && !present("ademonhide 3",this_player())){
    notify_fail("Karn says: I will need more Demon Hide to complete that project.\n");
    return 0;
  }
  if(str == "shield" && !present("ademonhide 5",this_player())){
    notify_fail("Karn says: I will need more Demon Hide to complete that project.\n");
    return 0;
  }
  if(str == "amulet" && !present("ademonhide 2",this_player())){
    notify_fail("Karn says: I will need more Demon Hide to complete that project.\n");
    return 0;
  }  
  if(str == "boots" && !present("ademonhide 3",this_player())){
    notify_fail("Karn says: I will need more Demon Hide to complete that project.\n");
    return 0;
  }
  if(str == "belt" && !present("ademonhide 2",this_player())){
    notify_fail("Karn says: I will need more Demon Hide to complete that project.\n");
    return 0;
  }
  if(str == "armor" && !present("ademonhide 10",this_player())){
    notify_fail("Karn says: I will need more Demon Hide to complete that project.\n");
    return 0;
  }
  if(str == "misc" && !present("ademonhide 3",this_player())){
    notify_fail("Karn says: I will need more Demon Hide to complete that project.\n");
    return 0;
  }
  if(str == "bracelet" && !present("ademonhide 2",this_player())){
    notify_fail("Karn says: I will need more Demon Hide to complete that project.\n");
    return 0;
  }
  if(str == "chest" && !present("ademonhide 3",this_player())){
    notify_fail("Karn says: I will need more Demon Hide to complete that project.\n");
    return 0;
  }
  if(str == "cloak" && !present("ademonhide 4",this_player())){
    notify_fail("Karn says: I will need more Demon Hide to complete that project.\n");
    return 0;
  }
  if(str == "gloves" && !present("ademonhide 2",this_player())){
    notify_fail("Karn says: I will need more Demon Hide to complete that project.\n");
    return 0;
  }
  if(str == "pants" && !present("ademonhide 4",this_player())){
    notify_fail("Karn says: I will need more Demon Hide to complete that project.\n");
    return 0;
  }
  if(str == "underwear" && !present("ademonhide 2",this_player())){
    notify_fail("Karn says: I will need more Demon Hide to complete that project.\n");
    return 0;
  }
  if(this_player()->query_money() < cost){
    notify_fail("Karn says: You need more money.\n");
    return 0;
  }
  this_player()->add_money(-cost); 
    move_object(clone_object(file),this_player());
    destruct(present("ademonhide",this_player()));
    this_player()->recalc_carry();
    write("Karn takes your hide and forges a "+str+" from it.\n");
    write("Karn hands you a "+str+" and quickly takes your money.\n");
  say("Karn takes "+this_player()->query_name()+"'s shell and forges a "+str+" from it.\n",this_player());
  say("Karn hands "+this_player()->query_name()+" a "+str+" and quickly takes "+this_player()->query_possessive()+"   money.\n",this_player());
  if(str == "helmet"){
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
}
  if(str == "shield"){
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
}
  if(str == "amulet"){
    destruct(present("ademonhide",this_player()));
}
  if(str == "boots"){
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
}
  if(str == "belt"){
    destruct(present("ademonhide",this_player()));
}
  if(str == "armor"){
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
}
  if(str == "misc"){
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
}
  if(str == "bracelet"){
    destruct(present("ademonhide",this_player()));
}
  if(str == "chest"){
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
}
  if(str == "cloak"){
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
}
  if(str == "gloves"){
    destruct(present("ademonhide",this_player()));
}
  if(str == "pants"){
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
}
  if(str == "underwear"){
    destruct(present("ademonhide",this_player()));
}
return 1;
}
