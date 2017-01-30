inherit "/obj/monster.c";
#include "/players/jareel/define.h"

  reset(arg){
    string str;
    object gold;
    ::reset(arg);
  if(arg) return;
 
  set_name(HIK+"Mikaeus"+NORM+" - the Unhallowed "+HIK+"Malia"+NORM+" Blacksmith"+NORM);
  set_alias("mikaeus");
  set_alt_name("blacksmith");
  set_race("chaos");
  set_short(HIK+"Mikaeus"+NORM+" - the Unhallowed "+HIK+"Malia"+NORM+" Blacksmith"+NORM);
  set_long(
    "Long soot filled blond hair flows from Mikaeuss bronze skin.\n"+
    "His muscles bulge as he moves around the small quaint shop.\n"+
    "Years of service have creased his face and furrowed his \n"+
    "brow.  This is an imposing figure that should not be taken\n"+
    "lightly.\n");
  set_level(26);
  set_hp(1800);
  set_al(-400);
  MOCO("/players/jareel/weapons/YELMALIAN/blacksmithhammer.c"),this_object());
    init_command("wield hammer");
  set_heal(40,1);
  set_res(60); 
  set_ac_bonus(30); /* Res Bonus */
  
  set_armor_params("other|light",0,-100,"prot_from_light"); /* Major Problem */ 
  set_armor_params("other|dark",0,100,"prot_from_dark"); 
  set_armor_params("other|fire",0,90,"prot_from_fire"); 
  set_armor_params("other|ice",0,10,"prot_from_ice"); 
  set_armor_params("other|evil",0,100,"prot_from_evil");  /* No Problem evil is my Friend */
  set_armor_params("other|wind",0,-30,"prot_from_wind"); 
  set_armor_params("other|electric",0,-50,"prot_from_electric"); 
  set_armor_params("other|good",0,-100,"prot_from_good"); /* Creature is super evil */
  set_armor_params("other|water",0,50,"prot_from_water"); 
  set_armor_params("other|earth",0,60,"prot_from_earth"); 
  set_armor_params("other|laser",0,100,"prot_from_laser"); 
  set_armor_params("other|poison",0,100,"prot_from_poisen"); 
  set_armor_params("magical",0,60,"prot_from_magical"); /* Creature is magic */
  set_armor_params("other|sonic",0,40,"prot_from_sonic"); 
  set_armor_params("other|mental",0,60,0); 
  
  set_wc(45);
  set_ac(75);
  gold = clone_object("obj/money");
  gold->set_money(random(25000) + 3000);
  move_object(gold,this_object());
  set_chat_chance(10);
    load_chat(
      "Mikaeus says: 'Are you joining the to greats Crimsons Bats?.'\n");
    load_chat(
      "Mikaeus says: 'Do you wantss to buy somethingss?'\n");
    load_chat( 
      "Mikaeus says: 'Eyesss canss makess somethinsss outss of theesse demonss hides of those wonderfoolss Darks Demons.'\n");
    load_chat(
      "Mikaeus strikes demonic steel with its hammer.'\n");
    load_chat(
      "The Demon Fire burns.\n");
    load_chat(
      "Mikaeus says: 'If you wantss a 'list' of itemss just askes forss itss.'\n");
}

  init(){
    ::init();
    add_action("order","buy");
    add_action("list","list");
}

  list(){
    write("Mikaeus says: heress is my lists of items:\n");
    write("\n");
    write("   COST   HIDE    ITEM    "+HIK+"||"+NORM+"     COST   HIDE    ITEM\n");
    write(HIY+"  20000    "+HIK+"20     Helmet  ||"+HIY+"    20000    "+HIK+"20     Necklace\n");
    write(HIY+"  20000    "+HIK+"20     Shield  ||"+HIY+"    20000    "+HIK+"20     Bracelet\n");
    write(HIY+"  20000    "+HIK+"20     Amulet  ||"+HIY+"    20000    "+HIK+"20     Chest\n");
    write(HIY+"  20000    "+HIK+"20     Boots   ||"+HIY+"    20000    "+HIK+"20     Cloak\n");
    write(HIY+"  20000    "+HIK+"20     Ring    ||"+HIY+"    20000    "+HIK+"20     Earring\n");
    write(HIY+"  20000    "+HIK+"20     Belt    ||"+HIY+"    20000    "+HIK+"20     Gloves\n");
    write(HIY+"  50000    "+HIK+"30     Armor   ||"+HIY+"    20000    "+HIK+"20     Pants\n");
    write(HIY+"  20000    "+HIK+"20     Misc    ||"+HIY+"    20000    "+HIK+"20     Underwear\n");
    write(HIY+"          80000    "+HIK+"40    "+HIG+"Set of the Underworld\n"+HIK);
    write(HIY+"          80000    "+HIK+"40    "+HIG+"Set of the Disease\n"+HIK);
    write(HIY+"          80000    "+HIK+"40    "+HIG+"Set of the Death Walker\n"+NORM);
	    write("\n");
    write("  The sets are Comprised of one last secret piece\n\n");
    write("  The Malia blacksmith is an ass and will not tell\n");
    write("  you what that piece is.\n\n");
    write("  Combine may also combine sets to make '"+HIG+"Full sets"+NORM+"'\n");
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
    notify_fail("Mikaeus says: You more raw material for that.\n");
    return 0;
  }
  if(str == "belt" && !present("cacodemontail",this_player())&& !present("ademonhide 20",this_player())){
    notify_fail("Mikaeus says: I will need more Demon Hide to complete that project.\n");
    return 0;
  }
  if(str == "belt" && !present("cacodemontail",this_player())&& !present("ademonhide 20",this_player())){
    notify_fail("Mikaeus says: I will need more Demon Hide to complete that project.\n");
    return 0;
  }
  if(str == "belt" && !present("cacodemontail",this_player())&& !present("ademonhide 20",this_player())){
    notify_fail("Mikaeus says: I will need more Demon Hide to complete that project.\n");
    return 0;
  }  
  if(str == "belt" && !present("cacodemontail",this_player())&& !present("ademonhide 20",this_player())){
    notify_fail("Mikaeus says: I will need more Demon Hide to complete that project.\n");
    return 0;
  }
  if(str == "belt" && !present("cacodemontail",this_player())&& !present("ademonhide 20",this_player())){
    notify_fail("Mikaeus says: I will need more Demon Hide to complete that project.\n");
    return 0;
  }
  if(str == "belt" && !present("cacodemontail",this_player())&& !present("ademonhide 20",this_player())){
    notify_fail("Mikaeus says: I will need more Demon Hide to complete that project.\n");
    return 0;
  }
  if(str == "belt" && !present("cacodemontail",this_player())&& !present("ademonhide 20",this_player())){
    notify_fail("Mikaeus says: I will need more Demon Hide to complete that project.\n");
    return 0;
  }
  if(str == "belt" && !present("cacodemontail",this_player())&& !present("ademonhide 20",this_player())){
    notify_fail("Mikaeus says: I will need more Demon Hide to complete that project.\n");
    return 0;
  }
  if(str == "belt" && !present("cacodemontail",this_player())&& !present("ademonhide 20",this_player())){
    notify_fail("Mikaeus says: I will need more Demon Hide to complete that project.\n");
    return 0;
  }
  if(str == "belt" && !present("cacodemontail",this_player())&& !present("ademonhide 20",this_player())){
    notify_fail("Mikaeus says: I will need more Demon Hide to complete that project.\n");
    return 0;
  }
  if(str == "belt" && !present("cacodemontail",this_player())&& !present("ademonhide 20",this_player())){
    notify_fail("Mikaeus says: I will need more Demon Hide to complete that project.\n");
    return 0;
  }
  if(str == "belt" && !present("cacodemontail",this_player())&& !present("ademonhide 20",this_player())){
    notify_fail("Mikaeus says: I will need more Demon Hide to complete that project.\n");
    return 0;
  }
  if(str == "belt" && !present("cacodemontail",this_player())&& !present("ademonhide 20",this_player())){
    notify_fail("Mikaeus says: I will need more Demon Hide to complete that project.\n");
    return 0;
  }
  if(this_player()->query_money() < cost){
    notify_fail("Mikaeus says: You need more money.\n");
    return 0;
  }
  this_player()->add_money(-cost); 
    move_object(clone_object(file),this_player());
    destruct(present("ademonhide",this_player()));
    this_player()->recalc_carry();
    write("Mikaeus takes your hide and forges a "+str+" from it.\n");
    write("Mikaeus hands you a "+str+" and quickly takes your money.\n");
  say("Mikaeus takes "+this_player()->query_name()+"'s shell and forges a "+str+" from it.\n",this_player());
  say("Mikaeus hands "+this_player()->query_name()+" a "+str+" and quickly takes "+this_player()->query_possessive()+"   money.\n",this_player());
  if(str == "helmet"){
    destruct(present("ademonhide",this_player()));
	destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
	destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
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
  if(str == "shield"){
    destruct(present("ademonhide",this_player()));
	destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
	destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
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
  if(str == "amulet"){
    destruct(present("ademonhide",this_player()));
	destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
	destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
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
  if(str == "boots"){
    destruct(present("ademonhide",this_player()));
	destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
	destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
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
  if(str == "belt"){
    destruct(present("ademonhide",this_player()));
	destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
	destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
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
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
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
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
	destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
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
  if(str == "bracelet"){
    destruct(present("ademonhide",this_player()));
	destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
	destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
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
  if(str == "chest"){
    destruct(present("ademonhide",this_player()));
	destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
	destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
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
  if(str == "cloak"){
    destruct(present("ademonhide",this_player()));
	destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
	destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
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
  if(str == "gloves"){
    destruct(present("ademonhide",this_player()));
	destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
	destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
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
  if(str == "pants"){
    destruct(present("ademonhide",this_player()));
	destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
	destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
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
  if(str == "underwear"){
    destruct(present("ademonhide",this_player()));
	destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
	destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
    destruct(present("ademonhide",this_player()));
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
return 1;
}
