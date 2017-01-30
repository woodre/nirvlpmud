inherit "/obj/treasure.c";
reset (arg) {
	set_id("snakeskin");
        set_alias("skin");
	set_short("A large Snakeskin");
	set_long(
        "  A large piece of snakeskin that could fetch a hefty price\n"+
        "if you were to 'redeem' it.\n");
      set_weight(0);
}
init() {
	::init();
        add_action("redeem_it","redeem");
	  }

redeem_it(str) {
	if(!str){ write("Redeem what?\n"); return 1; }
        if(str == "snakeskin" || str == "skin"){
         int money;
         money = 900+random(200); 
         this_player()->add_money(money);
         say(this_player()->query_name()+ " redeems a snakeskin.\n"); 
         tell_object(this_player(),
         "You redeem the snakeskin for "+money+" coins!\n");
         destruct(this_object()); 
         return 1;
         }
	}

