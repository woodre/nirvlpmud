inherit "obj/treasure";
int cashout;
int money;
reset(arg) {
  if(arg) return;
  set_id("Satchel");
  set_alias("satchel");
  set_short("Satchel");
  set_long(
"   A thick and strong leather satchel.  There is a large strap \n"+
"of leather so you can swing it over your shoulder.  There is \n"+
"small strap keeping the satchel closed.\n");
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
	if(arg=="satchel"|arg=="strap"){
			if(cashout==0){
				write("You open up the satchel and search inside.  You find "+money+" in coins!\n");
				this_player()->add_money(money);
				cashout=1;
				money=0;
				return 1;
			}
			write("You look through the satchel but find nothing of interest.\n");
			return 1;
	}
	return;
}

