#define MAX_WEIGTH	10

int local_weight;

id(str) 
{
    return str == "box";
}

short() 
{
    return "A cardboard box labelled 'BOX OF FUN!'";
}

long() 
{
    write("This is a box made of cheap cardboard. It is very flimsy but can still hold some\n"+
          "amount of things fairly effectively. It really smells like mushrooms, oddly enough.\n");

    if (first_inventory(this_object()))
	    write("There is something in it.\n");
    else
	    write("You can put things in it.\n");
}

reset(arg) 
{
    if(arg) return;
    local_weight = 10;

    move_object(clone_object("/players/mizan/etheriel/items/water-balloon.c"), this_object());
    move_object(clone_object("/players/mizan/etheriel/items/water-balloon.c"), this_object());
    move_object(clone_object("/players/mizan/etheriel/items/water-balloon.c"), this_object());
    move_object(clone_object("/players/mizan/etheriel/items/blockbuster.c"), this_object());
    move_object(clone_object("/players/mizan/etheriel/items/blockbuster.c"), this_object());
    move_object(clone_object("/players/mizan/etheriel/items/trick-brick.c"), this_object());
    move_object(clone_object("/players/mizan/etheriel/items/cap.c"), this_object());

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
        say("The items in the box bump against one another.\n");
    return 1;
}


can_put_and_get() { return 1; }

get() { return 1; }

prevent_insert() 
{
    if (local_weight > 0) 
    {
	    write("You can't when there are things in the box.\n");
    	return 1;
    }
    return 0;
}

query_save_flag() { return 1; }
