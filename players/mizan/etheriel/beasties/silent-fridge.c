#define HEALS "players/mizan/etheriel/heals/"
#define ITEMS "players/mizan/etheriel/items/"

inherit "/players/mizan/core/monster.c";
string item;
int cost;

reset(arg)
{
   object gold, stick;
   if(!item) 
   {
       item=allocate(13);
       item[0] = ITEMS+"armpit-hair.c";
       item[1] = ITEMS+"water-balloon-box.c";
       item[2] = ITEMS+"backpack.c";
       item[3] = ITEMS+"flashlight.c";
       item[4] = ITEMS+"bowling-ball.c";
       item[5] = ITEMS+"rose.c";
       item[6] = ITEMS+"smelly-sock.c";
       item[7] = ITEMS+"shit.c";
       item[8] = ITEMS+"plyrblinker.c";
       item[9] = ITEMS+"doorknob.c";
       item[10] = ITEMS+"random-item.c";
       item[11] = ITEMS+"peeball/peeball.c";
       item[12] = ITEMS+"blockbuster-box.c";
   }
  
   if(!cost) 
   {
       cost=allocate(13);
       cost[0]=1000;
       cost[1]=60;
       cost[2]=300;
       cost[3]=100;
       cost[4]=120;
       cost[5]=50;
       cost[6]=200;
       cost[7]=1000;
       cost[8]=125;
       cost[9]=200;
       cost[10]=200;
       cost[11]=200;
       cost[12]=200;
   }
   
   ::reset(arg);
   if(arg) return;
   
   set_name("A refrigerator");
   set_race("fridge");
   set_short("A silent refrigerator");
   
   set_long("This is a silent refrigerator, much like the kind you commonly\n"+
"see in a college dorm room or apartment. Covered with a variety of\n"+
"stickers, it looks somewhat well-travelled- some of the stickers that\n"+
"catch your eye are 'Icelandair', 'Animas, New Mexico', 'Tahiti', 'Rome',\n"+
"and a big neon one that reads: Type 'list' for a list of stuff!\n");
   
   set_level(7);
   set_hp(88);
   set_al(90);
   set_wc(12);
   set_ac(20);
   

   gold=clone_object("obj/money");
   gold->set_money(random(50)+20);
   move_object(gold,this_object());
}

init() {
  add_action("list_items","list");
  add_action("buy_item","push");
  add_action("buy_item","buy");
  ::init();
}

list_items() {
  cat("/players/mizan/etheriel/environs/text/SILENT_FRIDGE_ITEM_LIST");
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
  if(item_no > 0 && item_no < 14) {
    int price;
    price=cost[item_no-1];
    if((this_player()->query_money()) < cost[item_no-1]) {
      write("The fridge borks: You don't have enough gold!\n");
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
