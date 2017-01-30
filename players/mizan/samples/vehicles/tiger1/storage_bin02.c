#define MAX_WEIGTH	12

int local_weight;

id(str) 
{
    return str == "bin";
}

short() 
{
    return "A metal storage bin";
}

long() 
{
    write("This is a box made of thick sheet metal used for storage.\n");

    if (first_inventory(this_object()))
	    write("There is something in it.\n");
    else
	    write("You can put things in it.\n");
}

reset(arg) 
{
    if(arg) return;
    local_weight = 0;
}

query_weight()
{
    return 1;
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
        say("The items in the bin clunk and clatter against one another.\n");
    return 1;
}


can_put_and_get() { return 1; }

get() { return 0; }

prevent_insert() 
{
    if (local_weight > 0) 
    {
	    write("You can't when there are things in the bin.\n");
    	return 1;
    }
    return 0;
}

query_save_flag() { return 1; }
