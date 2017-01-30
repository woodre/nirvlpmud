#include <ansi.h>

inherit "/obj/treasure";

void reset(int x){
  if(x) return;
  
  set_id("strangler fig");
  set_alias("fig");
  
  set_short("a "+GRN+"strangler"+NORM+" "+MAG+"fig"+NORM);
  set_long("\
The "+GRN+"strangler"+NORM+" "+MAG+"fig"+NORM+" is a banyan fig,\n\
usually native to southern Florida, the Caribbeans,\n\
Central America and South America. It is a favorite\n\
treat of the wild bili ape. These figs in particular\n\
seem particularly tasty.\n");

  set_weight(1);
  set_value(666+random(333));
}

void init(){
  ::init();
  if(environment()==this_player())
    add_action("cmd_eat","eat");
}

int cmd_eat(string str){
  if(!str)
    return(notify_fail("Eat what?\n"), 0);
  if(!id(str))
    return(notify_fail("You may only eat "+short()+"\n"),0);
  write("\n\t...You take a bite from "+short()+"...\n\n");
  say((string)this_player()->query_name()+" takes a bite from "+short()+".\n");
  this_player()->heal_self(250);
  this_player()->eat_food(-20);
  this_player()->drink_soft(-20);
  command("mon", this_player());
  write("The rest of the fig looks useless, so you throw it away.\n");
  destruct(this_object());
  return 1;
}
