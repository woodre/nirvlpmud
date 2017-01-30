inherit "/obj/treasure.c";
reset (arg) {
	set_id("coupon");
      set_alias("paper");
	set_short("A Coupon");
	set_long("  This coupon is worth hundreds of thousands of coins!\n"+
               "Okay I'm lying it isn't worth that much.  You can\n"+
               "'redeem' this coupon.\n");
      set_weight(0);
}
init() {
	::init();
        add_action("redeem_it","redeem");
	  }

redeem_it(str) {
	if(!str){ write("Redeem what?\n"); return 1; }
      if(str == "coupon" || "paper"){
         int money;
         money = 600+random(100); 
         this_player()->add_money(money);
         say(this_player()->query_name()+ " redeems a coupon.\n"); 
         tell_object(this_player(),
         "You redeem the coupon for "+money+" coins!\n");
         destruct(this_object()); 
         return 1;
         }
	}

