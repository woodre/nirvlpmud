#define MAX_WEIGTH	6

int local_weight;

id(str) 
{
    return str == "pouch";
}

short() 
{
    return "A small leather pouch";
}

long() 
{
    write("This is a small brown pouch, made out of something that was probably endangered.\n");

    if (first_inventory(this_object()))
	    write("There is something in it.\n");
    else
	    write("You can put things in it.\n");
}

reset(arg) 
{
    object key1;
    object key2;
    object manual;

    if(arg) return;
    local_weight = 3;

    if(!key1) key1 = move_object(clone_object("/players/mizan/etheriel/subrealms/h2_dealership/items/can_key.c"), this_object());
    if(!key2) key2 = move_object(clone_object("/players/mizan/etheriel/subrealms/h2_dealership/items/can_ignition_key.c"), this_object());
    if(!manual) manual = move_object(clone_object("/players/mizan/etheriel/subrealms/h2_dealership/items/can_manual.c"), this_object());

}

query_weight()
{
    return local_weight;
}

add_weight(w) 
{
    if (local_weight + w > MAX_WEIGTH) return 0;
    
    local_weight += w;
    return 1;
}

clean_up() 
{
    if(local_weight) 
        say("The items in the pouch clink against one another.\n");
    return 1;
}


can_put_and_get() { return 1; }

get() { return 1; }

prevent_insert() 
{
    if (local_weight > 0) 
    {
	    write("You can't when there are things in the pouch.\n");
    	return 1;
    }
    return 0;
}

query_save_flag() { return 1; }