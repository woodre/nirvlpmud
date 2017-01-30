inherit "/players/mizan/core/object.c";
#include "/obj/ansi.h"

/** \brief Temporarily used - sets the object that the shell originates from */
object my_vehicle;

/** \brief The number of heartbeats before this goes off. Default is 0 (instant) */
int heartbeats_delay;
int base_damage;
int random_damage;

string my_spent_ammo_file;

/** AMMO SPECIFIC FUNCTIONS **/

set_vehicle(arg) { my_vehicle = arg; }
set_base_damage(arg) { base_damage = arg; }
set_random_damage(arg) { random_damage = arg; }
set_spent_ammofile(arg) { my_spent_ammo_file = arg; }

query_vehicle() { return my_vehicle; }
query_base_damage() { return base_damage; }
query_random_damage() { return random_damage; }
query_spent_ammo_file() { return my_spent_ammo_file; }


detonate(arg)
{
    object ob, oc;

    if(!arg)
        return 0;

    tell_room(environment(), boom());
    tell_room(environment(), short() + " slams violently into " + arg->query_name() + "!\n");

    arg->hit_player(base_damage + random(random_damage));

    ob = first_inventory(environment());

    while(ob)
    {
        if(ob != arg && living(ob) && ob != environment())
        {
            if(ob->is_vehicle())
            {
                if(ob->short())
                    tell_room(environment(), ob->short() + " is unaffected by the blast.\n");
            }
            else
            {
                tell_object(ob, "You are thrown clear by the blast!\n");
                ob->run_away();
                tell_room(environment(), ob->query_name() + " is thrown clear by the blast!\n");
            }
        }
        ob = next_inventory(ob);
    }

    if(my_spent_ammo_file)
    {
        oc = clone_object(my_spent_ammo_file);
        if(oc)
            move_object(oc, environment());
    }

    destruct(this_object());
    return 1;
}


boom()
{
    string result;
    result = HIY + 
      "\tBBBBBBB    OOOOOO    OOOOOO   MM     MM  !!  !!\n"+
      "\tBB    BB  OO    OO  OO    OO  MMM   MMM  !!  !!\n"+
      "\tBBBBBBB   OO    OO  OO    OO  MM MMM MM  !!  !!\n"+
      "\tBB    BB  OO    OO  OO    OO  MM  M  MM  \n"+
      "\tBBBBBBB    OOOOOO    OOOOOO   MM     MM  !!  !!\n\n" + NORM;

    return result;

}
/* end function boom() */
