#define TPN this_player()->query_name()
#define TP this_player()
inherit "/obj/treasure";
int coins, open;
reset(arg) {
  if(arg) return;
  set_id("purse");
  set_short("A Leather Coinpurse");
  set_long(
  "A soft leather coinpurse with a drawstring top.  It is tied shut.\n");

  set_value(25);
  set_weight(1);
  
  }

init() {
  ::init();
  add_action("cmd_open","open");
  add_action("cmd_take","take");
  add_action("cmd_take","get");
  
  add_action("cmd_close","close");
    }
cmd_take(arg) {
  int x;
  
  if(arg == "coins" || arg=="coins from purse") {
    if(environment(this_object()) != TP) {
      write("You must grab the purse first!\n");
      return 1; 
    }
    if(!open) {
      write("You must open the purse first!\n");
      return 1; 
    }
    if(coins) {
       write("There are no more coins in the purse!\n");
       return 1; 
    }
    x = 1800+random(600);
    write("You take "+x+" coins from the purse!\n");
    say(TPN+" takes some coins from a purse!\n");
    coins = 1;
    TP->add_money(x);
    return 1; 
  }
}



cmd_open(arg) {
  if(!arg) {
    write("Open what now?\n");
    return 1; 
  }
  if(arg == "purse") {
    if(environment(this_object()) != this_player()) {
      write("You must grab the purse first!\n");
      return 1; 
    }
    if(open) {
      write("The purse is already open!\n");
      return 1; 
    }
    write("You open up the purse.\n");
    say(TPN+" opens up the purse.\n");
    open = 1; return 1;
  }
  return 1; 
}

cmd_close(arg) {
  if(!arg) {
    write("Close what?\n");
    return 1; 
  }
  if(arg == "purse") {
    if(environment(this_object()) != TP) {
      write("You must grab the purse first!\n");
      return 1; 
    }
    if(!open) {
      write("The purse is already closed!\n");
      return 1;
    }
    write("You close the purse.\n");
    say(TPN+" closes the purse.\n");
    open = 0; return 1; 
  }
  return 1; 
}
 
query_save_flag() { if(coins) return 1; else return 0; }




