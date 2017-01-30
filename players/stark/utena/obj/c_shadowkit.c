inherit "obj/treasure";
#include "/players/stark/defs.h"
int cashout;
int money;
reset(arg) {
  if(arg) return;
  set_id("c_small kit");
  set_alias("kit");
  set_short("Small Kit");
  set_long(
"   A small black box with a metal latch.  It has a small black \n"+
"handle made of plastic.  Perhaps you could open it up.\n");
  set_weight(1);
  set_value(200);
}

init() {
::init();
add_action("open","open");
}

set_coins(int i){ money = i; }


open(arg){
	if(arg=="box"|arg=="kit"){
			if(cashout==0){
				write("You open up the box and rifle through it.  Inside you find some props and "+money+" in coins!\n");
				this_player()->add_money(money);
				cashout=1;
				money=0;
				return 1;
			}
			write("You open up the box and rifle through it but find nothing valuable.\n");
			return 1;
	}
	return;
}

