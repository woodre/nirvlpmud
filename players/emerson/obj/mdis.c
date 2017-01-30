#define MOV_RATE 15
inherit "/obj/monster.c";
reset(arg) {
    ::reset(arg);
    if (!arg){
set_short("A vending machine");
set_long("A Pizza Hut vending machine. You can 'buy' pizza, pepsi, and breadsticks.\n");
set_name("machine");
  set_alias("vending machine");
set_ac(15);
 set_wc(10);
  set_hp(1000);
  set_level(15);
    set_a_chat_chance(15);
    load_a_chat("Machine screams: Are you Stupid?!?!\n");
load_a_chat("Machine yells: Why you do this to me????\n");
    load_a_chat("Machine begs for mercy!!\n");
   }
}
status random_move(){
int n;
n=random(5);
switch(n) {
case 0 : command("east"); break;
case 1 : command("west"); break;
case 2 : command("north"); break;
case 3 : command("south"); break;
case 4 : command("exit"); break;
}
call_out("random_move",MOV_RATE);
  return 1;
}
init() {
	add_action("buy","buy");
}
buy(str) {
    object breadstick,pizza,pepsi;
	if(str=="pizza") {
	if(this_player()->query_money() < 6000) {
	write("You don't have enough gold coins!\n");
	return 1;
	}
	if(!call_other(this_player(), "add_weight", 1)) {
	write("You can't carry that much.\n");
	return 1;
	}
	this_player()->add_money(-6000);
	pizza=clone_object("/players/emerson/heal/lpizza.c");
	move_object(pizza, this_player());
	write("You put your coins in the machine and get a pizza.\n");
	say(capitalize(this_player()->query_real_name())+" buys a pizza from the machine.\n");
	return 1;
	}
     if(str=="pepsi") {
     if(this_player()->query_money() < 5000) {
     write("You need more cash!\n");
     return 1;
     }
     if(!call_other(this_player(), "add_weight", 1)) {
     write("You can't carry that much!\n");
     return 1;
     }
     this_player()->add_money(-5000);
     pepsi=clone_object("/players/emerson/heal/drpepper.c");
     move_object(pepsi, this_player());
     write("You put your coins in the machine and get a bottle of pepsi.\n");
     say(capitalize(this_player()->query_real_name())+" buys some pepsi from the machine.\n");
     return 1;
     }
     if(str="breadstick") {
     if(this_player()->query_money() < 5000) {
      write("You need more cash!\n");
     return 1;
      }
     if(!call_other(this_player(), "add_weight", 1)) {
     write("You can't carry that much!\n");
      return 1;
     }
      this_player()->add_money(-5000);
     breadstick=clone_object("/players/emerson/heal/bsticks.c");
     move_object(breadstick, this_player());
     write("You put your coins in the machine and get a bag of breadsticks.\n");
      say(capitalize(this_player()->query_real_name())+" buys some breadsticks from the machine.\n");
     return 1;
     }
}
get() { return 0; }
