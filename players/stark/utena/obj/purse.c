inherit "obj/treasure";
int open;
int cashout;
int money;
reset(arg) {
  if(arg) return;
  set_id("Purse");
  set_alias("purse");
  set_short("Small purse");
  set_long(
"This small black purse is rather plain.  It has a long black strap \n"+
"with no design.  There is a small rose design embroidered into the \n"+
"purse.  There is a zipper across the front, perhaps you could unzip it.\n");
  set_weight(1);
  set_value(200);
}

init() {
::init();
add_action("unzip","unzip");
add_action("zip","zip");
}

query_save_flag() { return 1; }
set_coins(int i){ money = i; }

unzip(arg){
	if(arg=="purse"){
		if(open==0){
			if(cashout==0){
				write("You unzip the purse and look through it.  You find "+money+" in coins!\n");
				this_player()->add_money(money);
				cashout=1;
				money=0;
				open=1;
				return 1;
			}
			write("You unzip the purse and look through it but find nothing of interest.\n");
			open=1;
			return 1;
		}
		write("The purse is already open.\n");
		return 1;
	}
	return;
}

zip(arg){
	if(arg=="purse"){
		if(open){
			write("You zip up the purse.\n");
			open=0;
			return 1;
		}
		write("The purse is already closed\n");
		return 1;
	}
	return;
}

