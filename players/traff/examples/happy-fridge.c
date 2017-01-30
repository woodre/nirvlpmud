
#define HEALS "players/mizan/etheriel/heals/"
#define ITEMS "players/mizan/etheriel/items/"
inherit "obj/monster";
string item;
int cost;

reset(arg){
  object gold, stick;
  if(!item) {
    item=allocate(11);
    item[0]=ITEMS+"portable-panic-btn.c";
    item[1]=ITEMS+"sc.c";
    item[2]=ITEMS+"backpack.c";
    item[3]=ITEMS+"flashlight.c";
    item[4]=HEALS+"zagnuts.c";
    item[5]=ITEMS+"rose.c";
      item[7]=HEALS+"cheesenub.c";
    item[8]=ITEMS+"plyrblinker.c";
         item[6]=HEALS+"gargle-blaster.c";
    item[9]=ITEMS+"doorknob.c";
     item[10]=HEALS+"evil.c";
  }
  if(!cost) {
    cost=allocate(11);
    cost[0]=35;
    cost[1]=50;
    cost[2]=300;
    cost[3]=100;
    cost[4]=1300;
    cost[5]=50;
      cost[6]=10000;
      cost[7]=10000;
    cost[8]=125;
    cost[9]=200;
    cost[10]=1500;
  }
   ::reset(arg);
   if(arg) return;
   set_name("A refrigerator");
   set_race("fridge");
   set_short("A happy refrigerator");
   set_long("This is a happy refrigerator, much like the kind you commonly\n"+
"see in a college dorm room or apartment. Covered with a variety of\n"+
"stickers, it looks somewhat well-travelled- some of the stickers that\n"+
"catch your eye are 'Icelandair', 'Animas, New Mexico', 'Tahiti', 'Rome',\n"+
"and a big neon one that reads: Type 'list' for a list of stuff!\n");
   set_level(7);
   set_hp(105);
   set_al(940);
   set_wc(12);
   set_ac(14);
   set_chance(30);
   set_spell_dam(13);
   set_spell_mess1("The fridge cries: Die! Punk!");
  set_spell_mess2("The fridge slams you with its door!");
   set_chat_chance(5);
load_chat("The fridge says: Type 'help jello' to see the extended commands!\n");
load_chat("The fridge asks: Do you speak Icelandic?\n");
load_chat("The fridge whistles happily.\n");
load_chat("The fridge smiles at you.\n");
load_chat("The fridge says: Type 'list' for a list of stuff!\n");
load_chat("The fridge says: I love Bjork. Do you?\n");
load_chat("The fridge sings: 'Dah dah dah do doh dee!'\n");
load_chat("The fridge sways and grooves to the beat.\n");
load_chat("The fridge wistfully sings: 'Lately, I find myself gazing at stars...\n"+
          "    hearing guitars... like someone in love...'\n");
load_chat("The fridge sings: '...Lately... I seem to walk as though I have wings...\n"+
	  "    ...bump into things... like someone in love...'\n");
load_chat("The fridge says: Hi there!\n");
   gold=clone_object("obj/money");
   gold->set_money(random(50)+260);
   move_object(gold,this_object());
    move_object(clone_object("players/mizan/etheriel/items/dehydrated-h20"), this_object());
}

init() {
  add_action("list_items","list");
  add_action("buy_item","push");
  add_action("buy_item","buy");
  ::init();
}

list_items() {
  cat("/players/mizan/etheriel/environs/SPOOGLE_ITEM_LIST");
  return 1;
}

buy_item(arg) {
  object thingo;
  int item_no;
  if(!arg) return 0;
  if(sscanf(arg, "%d", item_no) != 1) {
    write("The fridge goes: Huh?\n");
    return 1;
  }
  sscanf(arg, "%d", item_no);
  if(item_no > 0 && item_no < 12) {
    int price;
    price=cost[item_no-1];
    if((this_player()->query_money()) < cost[item_no-1]) {
      write("The fridge fungles: You don't have enough gold!\n");
      return 1;
    }
    this_player()->add_money(-cost[item_no-1]);
    thingo = clone_object(item[item_no-1]);
    if(!this_player()->add_weight(thingo->query_weight())) {
      write("The fridge says: You are carrying too much stuff!\n");
      move_object(thingo, environment(this_object()));
    return 1;
    }
    else move_object(thingo, this_player());
    write("You give your coins to the fridge and the item pops out into your hands.\n"+
    "The fridge says: Thanks!\n");
    say((this_player()->query_name())+" buys something from the fridge.\n");
    return 1;
  }
  write("The fridge is left in a steep bogglement.\n");
  return 1;
}     

query_permanency() { return 1; }
