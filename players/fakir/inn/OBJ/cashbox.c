#define TPN this_player()->query_name()
#define TP this_player()
inherit "/obj/treasure";
int coins, open;
reset(arg) {
  if(arg) return;
  set_id("cashbox");
  set_short("A Cashbox");
  set_long(
  "A solid brass cashbox with a strong looking clasp and lock.  It\n"+
  "is not locked.  The lid has the small emblem of a dragon etched\n"+
  "on it.  It must have some coins inside you could take.\n");

  set_value(50);
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
  
  if(arg == "coins" || arg=="coins from cashbox") {
    if(environment(this_object()) != TP) {
      write("You must grab the cashbox first!\n");
      return 1; 
    }
    if(!open) {
      write("You must open the cashbox first!\n");
      return 1; 
    }
    if(coins) {
       write("There are no more coins in the cashbox!\n");
       return 1; 
    }
    x = 3000+random(2000);
    write("You take "+x+" coins from the cashbox!\n");
    say(TPN+" takes some coins from a cashbox!\n");
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
  if(arg == "cashbox") {
    if(environment(this_object()) != this_player()) {
      write("You must grab the cashbox first!\n");
      return 1; 
    }
    if(open) {
      write("The cashbox is already open!\n");
      return 1; 
    }
    write("You open up the cashbox.\n");
    say(TPN+" opens up the cashbox.\n");
    open = 1; return 1;
  }
  return 1; 
}

cmd_close(arg) {
  if(!arg) {
    write("Close what?\n");
    return 1; 
  }
  if(arg == "cashbox") {
    if(environment(this_object()) != TP) {
      write("You must grab the cashbox first!\n");
      return 1; 
    }
    if(!open) {
      write("The cashbox is already closed!\n");
      return 1;
    }
    write("You close the cashbox.\n");
    say(TPN+" closes the cashbox.\n");
    open = 0; return 1; 
  }
  return 1; 
}
get() { if(present("bran",
environment())) return 0; else return 1; }

 
query_save_flag() { if(coins) return 1; else return 0; }




