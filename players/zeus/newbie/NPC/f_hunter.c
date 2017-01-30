inherit "/obj/monster";
#define F1 1200 /* cost of jerky */
#define F2 1200 /* cost of water */
#define F3 1200 /* cost of cider */
#define F4 2250 /* cost of brandy */
object spear;

reset(arg) {
	::reset(arg);
   if (!arg) {

  if(!present("spear", this_object())){
	spear = clone_object("/obj/weapon.c");
	spear->set_type("spear");
	spear->set_name("spear");
	spear->set_short("A sharp wooden spear");
	spear->set_long(
	  "This is a very sharp and well crafted wooden spear.  The tip is\n"+
	  "made of iron and has been sharpened to a deadly point.  This\n"+
	  "would be a great weapon for hunting animals.\n");
	spear->set_class(15);
	spear->set_weight(2);
	spear->set_value(400);
	move_object(spear, this_object());
	init_command("wield spear");
  }

  set_name("friendly hunter");
  set_alias("hunter");
  set_short("A friendly hunter");
  set_long(
"This is a rather friendly looking hunter.  He is outfitted in green and\n"+
"brown clothing, and looks about ready to go off hunting.  In one hand\n"+
"he is carrying a long wooden spear.  He seems to have some things for\n"+
"sale, perhaps you should 'ask' him about his wares.\n");
  set_gender("male");
  set_race("human");
  set_level(16);
  set_hp(300+random(100));
  set_ac(13);
  set_wc(20);
  set_al(400);
  set_aggressive(0);
  add_money(100);
  set_chat_chance(4);
  set_a_chat_chance(3);
  load_chat("The hunter asks, \"Would you like to buy some food?\"\n");
  load_chat("The hunter smiles happily.\n");
  load_chat("The hunter smiles at you.\n");
  load_chat("The hunter says, \"Sure is a lovely day today.\"\n");
  load_chat("The hunter glances off into the forest.\n");
  load_chat("The hunter looks at his spear and smiles.\n");
  load_a_chat("The hunter asks, \"Why must we fight?\"\n");
  load_a_chat("You hunter says, \"I don't like you anymore.\"\n");
} }

void init(){
	::init();
	add_action("ask_cmd", "ask");
	add_action("buy_cmd", "buy");
	add_action("list_cmd", "list");
}

list_cmd(){	ask_cmd("hunter"); return 1; }

ask_cmd(str){
  if(str != "hunter" && str != "friendly hunter") return 0;
  tell_room(environment(), "The hunter says:  "+
	  "Here is what I have for sale.\n\n"+
	  "\tStrip of chicken jerky\t\t"+F1+" coins\n"+
	  "\tThermos of water\t\t"+F2+" coins\n"+
	  "\tBottle of hard cider\t\t"+F3+" coins\n"+
	  "\tBottle of brandy\t\t"+F4+" coins\n"+
	  "\n"+
	  "You may 'buy' any of these food items.\n\n");
  return 1;
}

purchase(x, str){
  int cost;
  object sale;
  if(1 == x){
	sale = clone_object("/players/zeus/heals/jerky.c");  	
	cost = F1;   
  }
  else if(2 == x){
	sale = clone_object("/players/zeus/heals/water.c");   
	cost = F2;   
  }
  else if(3 == x){
	  sale = clone_object("/players/zeus/heals/cider.c");  
	  cost = F3;  
  }
  else if(4 == x){
	sale = clone_object("/players/zeus/heals/brandy.c");   
	cost = F4;  
  }
  else return 0;
  if(this_player()->query_money() < cost){
	tell_room(environment(), 
		"The hunter says, \"You can't afford that "+
		this_player()->query_name()+".\n");
	return 1;
  }
  if(!this_player()->add_weight(1)){
	tell_room(environment(),
		"The hunter says, \"You can't carry that "+
		this_player()->query_name()+".\n");
	return 1;
  }
  write("You pay the hunter "+cost+" coins for the "+str+".\n");
  tell_room(environment(), this_player()->query_name()+
	  " pays the hunter for the "+str+".\n", ({ this_player() }));
  this_player()->add_money(-cost);
  this_object()->add_money(cost/3);
  move_object(sale, this_player());
  return 1;
}

buy_cmd(str){
  if(str == "chicken" || str == "jerky" || str == "chicken jerky")
	purchase(1, str);
  else if(str == "water" || str == "thermos of water")
	purchase(2, str);
  else if(str == "cider" || str == "bottle of cider" || str == "hard cider")
	purchase(3, str);
  else if(str == "brandy" || str == "thermos of brandy")
	purchase(4, str);
  else return 0;
  return 1;
}

