inherit "/players/mizan/core/object.c";
#include "/obj/ansi.h"

/** \brief Temporarily used - sets the object that the shell originates from */
object my_vehicle;

/** \brief The number of heartbeats before this goes off. Default is 0 (instant) */
int heartbeats_delay;

string my_room_residue_file;
string my_player_residue_file;

/** AMMO SPECIFIC FUNCTIONS **/

set_vehicle(arg) { my_vehicle = arg; }
set_room_residue_file(arg) { my_room_residue_file = arg; }
set_player_residue_file(arg) { my_player_residue_file = arg; }

query_vehicle() { return my_vehicle; }
query_room_residue_file() { return my_room_residue_file; }
query_player_residue_file() { return my_player_residue_file; }



detonate(arg)
{
    object ob, oc, od;

    if(!arg || !environment())
    {
        return 0;
    }

    tell_room(environment(), boom());
    tell_room(environment(), (short() + " crashes down right next to " + arg->query_name() + "!\n"));
    tell_room(environment(), "Luckily, it is only filled with dye.\n");

    /* put residue in room */
    if(my_room_residue_file)
    {
        oc = clone_object(my_room_residue_file);
        if(oc)
            move_object(oc, environment());
    }

    ob = first_inventory(environment());

    while(ob)
    {
        if(living(ob) && !ob->is_vehicle())
        {
            /* put residue on players */
            if(my_player_residue_file)
            {
                od = clone_object(my_player_residue_file);
                if(od)
                    move_object(od, ob);
            }

        }
        ob = next_inventory(ob);
    }

    destruct(this_object());
    return 1;
}


boom()
{
    string result;
    result = ESC + "[32m" +
      "\tBBBBBBB    OOOOOO    OOOOOO   MM     MM  !!  !!\n"+
      "\tBB    BB  OO    OO  OO    OO  MMM   MMM  !!  !!\n"+
      "\tBBBBBBB   OO    OO  OO    OO  MM MMM MM  !!  !!\n"+
      "\tBB    BB  OO    OO  OO    OO  MM  M  MM  \n"+
      "\tBBBBBBB    OOOOOO    OOOOOO   MM     MM  !!  !!\n\n" + ESC + "[0m";

    return result;

}
