inherit "/obj/treasure.c";
reset (arg) {
	set_id("feather");
      set_alias("paper");
	set_short("A large feather");
	set_long(
        "  A bright pink feather from one of the large \n"+
        "Flamingos. It might just be worth something if\n"+
        "you 'redeem' it.\n");
      set_weight(0);
}
init() {
	::init();
        add_action("redeem_it","redeem");
	  }

redeem_it(str) {
	if(!str){ write("Redeem what?\n"); return 1; }
      if(str == "feather"){
         int money;
         money = 400+random(100); 
         this_player()->add_money(money);
         say(this_player()->query_name()+ " redeems a feather.\n"); 
         tell_object(this_player(),
         "You redeem a feather for "+money+" coins!\n");
         destruct(this_object()); 
         return 1;
         }
	}

