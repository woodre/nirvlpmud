#define MAX_WEIGTH	120

int local_weight;

id(str) 
{
    return str == "shelf";
}

short() 
{
    return "A dampened metal shelf";
}

long() 
{
    write("This is a sturdy metal shelf used for storing 88mm shells.\n");
    write("It has rubber dampers and catches to prevent them from rolling off.\n");

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
    return 1;
}


can_put_and_get() { return 1; }

get() { return 0; }

prevent_insert() 
{
    if (local_weight > 0) 
    {
	    write("You can't when there are things in the shelf.\n");
    	return 1;
    }
    return 0;
}
