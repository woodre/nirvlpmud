give_object(str) {
    string item, dest;
    object item_ob, dest_ob;
    int weight;
    int maxflag,coins,dest_coin;

    private;
    power = 0;
    if (level >= ITEM_OVER)
        if (sscanf(str,"! %s",power) == 1) {
            str = power;
	    power = "!";
        }
    if (!str)
	return 0;
    if (this_object()->test_dark())
	return 1;
    if (sscanf(str, "%d coins to %s", coins, dest) == 2)
	item = 0;
    else if ( sscanf(str, "1 coin to %s", dest) == 1)
	coins = 1;
    else if ( sscanf(str, "coin to %s", dest) == 1)
	coins = 1;
    else if (sscanf(str, "one coin to %s", dest) == 1)
	coins = 1;
    else if (sscanf(str, "%s to %s", item, dest) != 2) {
	write("Give what to whom?\n");
	return 1;
    }
    dest = lower_case(dest);
    if (item) {
	item = lower_case(item);
	item_ob = present(item, this_player());
	if (!item_ob) {
	    write("There is no " + item + " here.\n");
	    return 1;
	}
	it = item;
	if (environment(item_ob) == this_object() &&
	    call_other(item_ob, "drop", 1) && !power) {
	    return 1;
	} else if (!item_ob || (!call_other(item_ob, "get") && !power)) {
	    write("You can't get that !\n");
	    return 1;
	}
    }
    dest_ob = present(dest, environment(this_player()));
    if (!dest_ob) {
	write("There is no " + capitalize(dest) + " here.\n");
	return 1;
    }
    if (!living(dest_ob) && !power) {
	write("You can't do that.\n");
	return 1;
    }
    if (!item) {
   if (no_give) {
    write("You cannot give money while another copy is logging in.\n");
    return 1;
    }
	if (coins <= 0 && !power)
	    return 0;
	if (money < coins && !power) {
	    write("You don't have that much money.\n");
	    return 1;
	}
	if (!power) money -= coins;
	/* Checkpoint the character, to prevent cheating */
	if (coins > 1 && !power)
	    save_me();
        dest_coin = dest_ob->query_money();
        if(dest_coin  > MAXCOINS) maxflag = 1;
	call_other(dest_ob, "add_money", coins);
        if(!maxflag && dest_ob->query_money() == MAXCOINS) maxflag = 2; 
        if(!maxflag)
        if (coins != 1)
	    checked_say(cap_name + " gives " + coins + " coins to " + capitalize(dest) +
	    ".\n");
	else
	    checked_say(cap_name + " gives 1 coin to " + capitalize(dest) + ".\n");
        if(maxflag == 2)
           checked_say(cap_name + " gives " + (MAXCOINS - dest_coin) +
           " coins to " + capitalize(dest) + ".\n");
	write("Ok.\n");
	return 1;
    }
   if(!item_ob) return 1;
    weight = call_other(item_ob, "query_weight");
    if (!call_other(dest_ob, "add_weight", weight) && !power) {
	write(capitalize(dest) + " can't carry any more.\n");
	return 1;
    }
    add_weight(-weight);
    if(dest_ob == this_object()) {
      if(item_ob->id("moneyXX")) {
        if(!weight) { 
           add_weight(-item_ob->query_oldwt());
       }
        if(weight < item_ob->query_olderwt()) {
          add_weight(-item_ob->query_olderwt());
          item_ob->clear_olderwt();
          add_weight(weight);
        }
      }
    }
    move_object(item_ob, dest_ob);
    checked_say(cap_name + " gives " + item + " to " + capitalize(dest) + ".\n");
    write("Ok.\n");
    return 1;
}

