#define MAX_WEIGTH	120

int local_weight;

object pistol;
object rifle;
object cannon;
object blaster;
object flexgun;
object minigun;
object mortar;
object ammo;


id(str) 
{
    return str == "cabinet";
}

short() 
{
    return "A large blue rifle cabinet";
}

long() 
{
    object ob;

    write("    This is a large rifle cabinet made of Spuckstuff, and it is protected by\n"+
        "  some sort of odd humming device that you can almost hear when you get close\n"+
        "  enough to it. The cabinet itself is translucent, and seems to be very cool to\n"+
        "  the touch. Fascinating!\n");

    ob = first_inventory(this_object());

    if (ob && this_player()->query_level() < 20)
    {
        write("There is something in it.\n");

        while(ob)
        {
            if(ob->short())
                write(ob->short() + ".\n");
            ob = next_inventory(ob);
        }

    }
    else
	    write("You can put things in it.\n");

    
}

reset(arg) 
{
    if(arg) return;

    move_object(clone_object("/players/mizan/etheriel/items/spuckballs-extinf.c"), this_object());
    move_object(clone_object("/players/mizan/etheriel/items/spuckballs-extinf.c"), this_object());
    move_object(clone_object("/players/mizan/etheriel/items/spuckballs-ext3.c"), this_object());
    move_object(clone_object("/players/mizan/etheriel/items/spuckballs-ext3.c"), this_object());
    move_object(clone_object("/players/mizan/etheriel/items/spuckballs-ext3.c"), this_object());
    move_object(clone_object("/players/mizan/etheriel/items/spuckballs-ext2.c"), this_object());
    move_object(clone_object("/players/mizan/etheriel/items/spuckballs-ext2.c"), this_object());
    move_object(clone_object("/players/mizan/etheriel/items/spuckballs.c"), this_object());
    move_object(clone_object("/players/mizan/etheriel/items/spuckballs.c"), this_object());

    move_object(clone_object("/players/mizan/etheriel/items/spuckpistol.c"), this_object());
    move_object(clone_object("/players/mizan/etheriel/items/spuckpistol.c"), this_object());
    move_object(clone_object("/players/mizan/etheriel/items/spuckrifle.c"), this_object());
    move_object(clone_object("/players/mizan/etheriel/items/spuckrifle.c"), this_object());
    move_object(clone_object("/players/mizan/etheriel/items/spuckblaster.c"), this_object());
    move_object(clone_object("/players/mizan/etheriel/items/spuckcannon.c"), this_object());
    move_object(clone_object("/players/mizan/etheriel/items/spuck-minigun.c"), this_object());
    move_object(clone_object("/players/mizan/etheriel/items/spuckmortar.c"), this_object());
    move_object(clone_object("/players/mizan/etheriel/items/spuck-flexgun.c"), this_object());
    move_object(clone_object("/players/mizan/etheriel/items/spuck-flexgun.c"), this_object());


    local_weight = 0;
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
        say("The items in the cabinet clunk and clatter against one another.\n");
    return 1;
}


can_put_and_get()
{
    if(this_player() && this_player()->query_level() >= 21)
        return 1;
    else return 0; 
}

get() { return 0; }

prevent_insert() 
{
    if (local_weight > 0) 
    {
	    write("You can't when there are things in the cabinet.\n");
    	return 1;
    }
    return 0;
}
