inherit "/players/mizan/core/object.c";

int my_local_weight;
int my_max_weight;

long() 
{
    int percentage;

    ::long();

    if(!is_inactive)
    {
        if(first_inventory(this_object()))
        {
            percentage = (my_local_weight * 100) / my_max_weight;
            write(short() + " is " + percentage + "% full.\n");
        }
        else write("You can put things in it.\n");
    }
}

reset(arg) 
{
    ::reset(arg);
    if (arg) return;

    /* a default value */
    if(!my_local_weight) my_max_weight = 5;
    local_weight = 0;
}

clean_up() 
{
    if(my_local_weight) 
        say("You hear noises of things clinking around inside the " + query_name() + ".\n");
    return 1;
}


add_weight(arg) 
{
    if (my_local_weight + arg > my_max_weight)
	    return 0;
    
    my_local_weight += arg;
    return 1;
}

can_put_and_get() { return 1; }

prevent_insert() 
{
    if (my_local_weight > 0) 
    {
	    write(short() + " has items inside of it.\n");
	    return 1;
    }
    return 0;
}

/* properties */

set_max_container_weight(arg) { my_max_weight = arg; }
query_max_container_weight() { return my_max_weight; }
