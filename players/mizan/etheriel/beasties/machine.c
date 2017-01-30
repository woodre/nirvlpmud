#define HEALS "players/mizan/etheriel/heals/"
#define ITEMS "players/mizan/etheriel/items/"
inherit "/players/mizan/core/monster.c";

string item;
int cost;

reset(arg){
  object gold, stick;
/*
  if(find_living("009040662")) {
    move_object(this_object(), "players/mizan/castle");
    destruct(this_object());
    return 1;
  }
*/
  if(!item) {
    item=allocate(22);
    item[0]=HEALS+"orange.c";
    item[1]=HEALS+"sandwich.c";
    item[2]=HEALS+"pkcandy.c";
    item[3]=HEALS+"spam.c";
    item[4]=HEALS+"twinkie.c";
    item[5]=HEALS+"jug.c";
    item[6]=ITEMS+"rose.c";
    item[7]=HEALS+"thermos.c";
    item[8]=HEALS+"crate.c";
    item[9]=HEALS+"benzine.c";
    item[10]=HEALS+"poptarts.c";
    item[11]=HEALS+"neutromuck.c";
    item[12]=ITEMS+"blockbuster.c";
    item[13]=ITEMS+"spuckballs.c";
    item[14]=HEALS+"portable_cow.c";
    item[15]=HEALS+"scooby.c";
    item[16]=HEALS+"bunupill.c";
    item[17]=ITEMS+"kickme.c";
    item[18]=ITEMS+"guidexl.c";
    item[19]=ITEMS+"notepad_exe.c";
    item[20]=ITEMS+"rawtoast.c";
    item[21]=HEALS+"berynol-tank.c";
  }
  if(!cost) {
    cost=allocate(22);
    cost[0]=100;
    cost[1]=200;
    cost[2]=5;
    cost[3]=700;
    cost[4]=10000;
    cost[5]=500;
    cost[6]=50;
    cost[7]=300;
    cost[8]=10000;
    cost[9]=10000;
    cost[10]=10000;
    cost[11]=10000;
    cost[12]=150;
    cost[13]=1000;
    cost[14]=10000;
    cost[15]=10000;
    cost[16]=10000;
    cost[17]=50;
    cost[18]=2700;
    cost[19]=100;
    cost[20]=10000;
    cost[21]=350;
  }
   ::reset(arg);
   if(arg) return;
   set_name("machine");
   set_race("machine");
   set_alias("009040662");
   set_short("A magical vending machine");
  set_long("This is a magical vending machine. Sure, you've seen lots of these..\n"+
"It's alive, and when it notices you looking at it it, it says:\n"+
"  'Type list for a list of items!'\n");
   set_level(13);
   set_hp(1200);
   set_al(1000);
   set_wc(2);
   set_ac(12);
   set_chance(100);
   set_spell_dam(30);
   set_spell_mess1("The machine launches a coin at you and hits you squarely in the head!");
  set_spell_mess2("The machine cries: What did I ever do to you??");
   set_chat_chance(10);
load_chat("The machine makes a nasty noise.\n");
load_chat("The machine says: Howdy!\n");
   gold=clone_object("obj/money");
   gold->set_money(random(200)+800);
   move_object(gold,this_object());
   stick=clone_object("players/mizan/etheriel/items/purple-stick.c");
   move_object(stick, this_object());
}

init() {
  add_action("list_items","list");
  add_action("buy_item","push");
  add_action("buy_item","buy");
  ::init();
}

list_items() {
  cat("/players/mizan/etheriel/environs/text/MACHINE_LIST");
  return 1;
}

buy_item(arg) {
  object thingo;
  int item_no;
  if(!arg) return 0;
  if(sscanf(arg, "%d", item_no) != 1) {
    write("The machine boggles at you.\n");
    return 1;
  }
  sscanf(arg, "%d", item_no);
  if(item_no == 9) { write("That item is temporarily (maybe) sold out.\nWe'd apologize for the incovenience, but that would be disingenuous.\n"); return 1; }
  if(item_no > 0 && item_no < 23) {
    int price;
    price=cost[item_no-1];
  if((this_player()->query_money()) < cost[item_no-1]) {
      write("The machine beeps: You don't have enough gold!\n");
      return 1;
    }
    this_player()->add_money(-cost[item_no-1]);
    thingo = clone_object(item[item_no-1]);
    if(!this_player()->add_weight(thingo->query_weight())) {
      write("The machine says: Doh! You are carrying too much already.\n");
      move_object(thingo, environment(this_object()));
    return 1;
  }
  else move_object(thingo, this_player());
    write("You dump your coins into the machine and the item pops into your hands.\n"+
    "The machine says: Thanks!\n");
    say((this_player()->query_name())+" buys something from the machine.\n");
    return 1;
  }
  write("The machine peers quizzically at you.\n");
  return 1;
}     

query_permanency() { return 1; }
