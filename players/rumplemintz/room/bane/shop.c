inherit "/room/room";

void reset(int arg){
    if(arg) return;
    ::reset();
    set_short("Bane's Shop");
    set_long("You are in the shop of Lord Bane.  You can buy or sell things here.\n"+
      "Commands are: 'buy item', 'sell item', 'sell all', 'list', 'list weapons'\n"+
      "'list armors' and 'value item'.\n"+
      "There is an opening to the north, and some shimmering\n"+
      "blue light in the doorway.\n");
    dest_dir=({"/players/rumplemintz/room/bane/room12","west"});
    set_light(1);
}

query_drop_castle(){ return 1; }

object find_item_in_player(int i){
    object ob;
    ob=first_inventory(this_player());
    while(ob){
	if(ob->id(i)) return ob;
	ob=next_inventory(ob);
    }
    return 0;
}

int list(object obj){
    "/room/store"->inventory(obj);
    return 1;
}

int north(){
    if(this_player()->query_level() < 21){
	write("The shopkeeper throws you to the ground, wizards only!\n");
	say(this_player()->query_name()+" tries to go through the field, and is beaten up.\n");
	return 1;
    }
    write("The force field does not affect you...\n");
    this_player()->move_player("north#/room/store.c");
    return 1;
}

int buy(string item){
    if(!item) return 0;
    "/room/store"->buy(item);
    return 1;
}

int value(string item){
    int value;
    object name_of_item;
    if(!item) return 0;
    name_of_item = present(item);
    if(!name_of_item){
        if(call_other("/room/store", "value", item)) return 1;
	write("No such item ("+item+" here\nor in the store.\n");
	return 1;
    }
    value = (int)name_of_item->query_value();
    if(!value){
	write(item+" has no value.\n");
	return 1;
    }
    write("You would get "+value+" gold coins.\n");
    return 1;
}

int do_sell(object ob){
    int value, do_destroy;
    value = (int)ob->query_value();
    if(!value){
	write(ob->short()+" is a worthless piece of shit.\n");
	return 1;
    }
    if(environment(ob)==this_player()){
	int weight;
	if(ob->drop()){
	    write("I can't take it from you!\n");
	    return 1;
	}
        weight = (int)ob->query_weight();
	this_player()->add_weight(-weight);
    }
    if(value > 6000) do_destroy=1;
    if(value > 1500){
	write("Bane is rich, but not THAT rich...\n");
	value = 1500;
    }
    write("You get "+value+" gold coins.\n");
    say(this_player()->query_name()+" sells "+ob->query_short()+".\n");
    if(do_destroy){
	write("The valueable item is taken to Bane's private storage.\n");
	destruct(ob);
	return 1;
    }
    "/room/store"->store(ob);
    return 1;
}

int sell(string item){
    object ob;
    if(!item) return 0;
    if(item=="all"){
	object next;
	ob=first_inventory(this_player());
	while(ob){
	    next=next_inventory(ob);
	    if(!ob->drop() && ob->query_value()){
		write(ob->short()+":\t");
		do_sell(ob);
	    }
	    ob=next;
	}
	write("Ok.\n");
	return 1;
    }
    ob=present(item, this_player());
    if(!ob) ob=present(item, this_object());
    if(!ob){
	write("No such item ("+item+") here.\n");
	return 1;
    }
    do_sell(ob);
    return 1;
}

void init(){
    ::init();
    add_action("sell", "sell");
    add_action("value", "value");
    add_action("buy", "buy");
    add_action("north", "north");
    add_action("list", "list");
}
