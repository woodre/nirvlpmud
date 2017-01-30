#include <security.h>
cmd_get(str)
{
    string item;
    string container;
    object item_o;
    object container_o;
    string power;
    
    if (!str)
    {
            write("Get what?\n");
	    return 1;
    }
    power = 0;
    if((int)this_player()->query_level() >= ITEM_OVER)
    if (sscanf(str,"! %s",power) == 1) {
            str = power;
	    power = "!";
        }
    if (this_player()->query_ghost() && !power) {
	write("Your incorporeal hand passes right through it.\n");
	return 1;
    }
    if (this_player()->test_dark() && !power)
	return 1;
    if (str == "all") {
	get_all(environment(this_player()), power);
	return 1;
    }
    if (sscanf(str, "%s from %s", item, container) != 2) {
	pick_item(str,power);
	return 1;
    }
    container_o = present(lower_case(container), environment(this_player()));
    if(!container_o) container_o = present(lower_case(container), this_player());
    if(container == "bag")
      container_o = present(lower_case(container), this_player());
    if(!container_o)
      container_o = present(lower_case(container), environment(this_player()));
    if (!container_o) {
	write("There isn't any " + container + " here.\n");
	return 1;
    }
    if (!call_other(container_o, "can_put_and_get", 0) && !power) {
	write("You can't put anything inside "+container+"!\n");
	return 1;
    }
    if (item == "all") {
        get_all(container_o, power);
	return 1;
    }
    item_o = present(item, container_o);
    if (item_o) {
	if (call_other(item_o, "id", item)) {
	    int weight;
	    if (living(container_o) &&
	        call_other(item_o, "drop", 1) && !power) {
		write("You can not take " + item + " from " +
		      container + ".\n");
		return 1;
	    }
	    if (!call_other(item_o, "get", item) && !power) {
		write("You can not take " + item + " from " +
		      container + ".\n");
		return 1;
	    }
	    weight = call_other(item_o, "query_weight");
	    if (!this_player()->add_weight(weight) && !power) {
		write("You can not carry more.\n");
		return 1;
	    }
	    call_other(container_o, "add_weight", -weight);
	    move_object(item_o, this_player());
            this_player()->set_it(item);
	    write("Ok.\n");
	    this_player()->checked_say(
	    (string)this_player()->query_name()
            + " takes " + item+ " from " + container + "\n");
	    return 1;
	}
    }
    write("There isn't any " + item + " in the " + container + ".\n");
    return 1;
}

get_all(from, power) {
    object ob, next_ob;

    ob = first_inventory(from);
    while(ob) {
	string item;
	next_ob = next_inventory(ob);
	item = call_other(ob, "short");
	if ((item &&  call_other(ob, "get")) || (power && ob != this_player())) {
	    int weight;
	    if (!living(from) || !call_other(ob, "drop", 1) || power) {
	        if (!call_other(ob, "id", "soul")) {
		    weight = call_other(ob, "query_weight");
		    if (this_player()->add_weight(weight) || power) {
		        write(item + ": Ok.\n");
			call_other(from,"add_weight",-weight);
			move_object(ob, this_player());
			this_player()->checked_say(
			 (string)this_player()->query_name() + " takes: " + item + ".\n");
		    } else {
		        write(item + ": Too heavy.\n");
		    }
		}
	    }
            this_player()->set_it(item);
	}
	ob = next_ob;
    }
}

 pick_item(obj, power) {
    object ob;
    int i;

    obj = lower_case(obj);
    ob = present(obj, environment(this_player()));
    if (!ob) {
	write("That is not here.\n");
	return 1;
    }
    if (this_player()->query_ghost() && !power) {
	write("You fail.\n");
	return 1;
    }
    if (environment(ob) == this_player()) {
	write("You already have it!\n");
	return 1;
    }
    if (!call_other(ob, "get") && !power) {
	write("You can not take that!\n");
	return 1;
    }
    i = call_other(ob, "query_weight");
    if (this_player()->add_weight(i) || power) {
	move_object(ob, this_player());
      this_player()->checked_say((string)this_player()->query_name()
        + " takes " + obj + ".\n");
            this_player()->set_it(obj);
	write("Ok.\n");
	return 1;
    }
    write("You can't carry that much.\n");
    return 1;
}
