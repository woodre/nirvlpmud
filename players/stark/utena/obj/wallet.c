inherit "obj/treasure";
int cashout;
int money;
reset(arg) {
  if(arg) return;
  set_id("Wallet");
  set_alias("wallet");
  set_short("Leather wallet");
  set_long(
"A slender black leather wallet.  It is soft and yet still rugged.  \n"+
"There is a small metal rose on the side.  Perhaps you could open \n"+
"the wallet and see what's inside.\n");
  set_weight(1);
  set_value(200);
}

init() {
::init();
add_action("open","open");
}

query_save_flag() { return 1; }
set_coins(int i){ money = i; }

open(arg){
	if(arg=="wallet"){
			if(cashout==0){
				write("You open the wallet and look through it.  You find "+money+" in coins!\n");
				this_player()->add_money(money);
				cashout=1;
				money=0;
				return 1;
			}
			write("You look through the wallet but find nothing of interest.\n");
			return 1;
	}
	return;
}

