#include <ansi.h>

inherit "/obj/treasure";

int open;

void reset(int x){
  if(x) return;
  
  set_id("blacksmith's toolbox");
  set_alias("box");
  SetMultipleIds(({"toolbox","blacksmith toolbox"}));
  set_short("A "+HIK+"blacksmith"+NORM+"'s toolbox");
  set_long("\
  A small 9\" toolbox containing several implements handy\n\
  for repairing and caring for armors and weapons. One must\n\
  have knowledge of blacksmithing in order to use this,\n\
  however.\n");
  
  set_weight(2);
}

string short(){
  return (string)::short() + " ("+(open?"open":"closed")+")";
}

void long(){
  write("It is "+(open?"open":"closed")+".\n");
  if(open && (environment()==this_player())){
    write("\
You may \"polish\" your armor to remove any impurities,\n\
\"sharpen\" your weapons, or \"repair\" your equipment.\n");
  }
}  

void init(){
  if(environment() == this_player())
  {
    add_action("cmd_open", "open");
    add_action("cmd_close", "close");
    /*
     add_action("cmd_polish", "polish");
     add_action("cmd_sharpen", "sharpen");
     add_action("cmd_repair", "repair");
     */
  }
}

int cmd_open(string str){
  if(!str){
    notify_fail("Open what?\n");
    return 0;
  }
  if(!id(str)){
    notify_fail("You may only \"open\" the "+name+".\n");
    return 0;
  }
  if(open){
    write("The toolbox is already open.\n");
    return 1;
  }
  write("\n\tYou open the "+HIK+"blacksmith"+NORM+
        "'s toolbox.\n");
  say((string)this_player()->query_name()+" opens the latch on "+
    short_desc+".\n");
  open = 1;
  return 1;
}

int cmd_close(string str){
  if(!str){
    notify_fail("Close what?\n");
    return 0;
  }
  if(!id(str)){
    notify_fail("You may only \"close\" the "+name+".\n");
    return 0;
  }
  if(!open){
    write("The toolbox is already closed.\n");
    return 1;
  }
  write("\n\tYou close the "+HIK+"blacksmith"+NORM+
        "'s toolbox.\n");
  say((string)this_player()->query_name()+" closes the latch on "+
    short_desc+".\n");
  open = 0;
  return 1;
}
  