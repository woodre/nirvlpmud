#include "/obj/ansi.h"
#include "/players/mizan/mbv2/definitions.h"
#include "/players/mizan/mbv2/router.h"


status is_goggles_on;
object my_monster;

id(str)
{
    if(is_goggles_on)
        return str == "goggles" || str == GOGGLES_ID;
    else
        return str == "goggles" || str == GOGGLES_ID;
}

short()
{
    if(is_goggles_on)
    {
        if(my_monster)
            return "A pair of heads-up-display goggles " + HIW + "(VIEWING " + my_monster->query_name() + ")" + NORM;
        else
            return "A pair of heads-up-display goggles " + HIW + "(ON)" + NORM; 
    }
    else
        return "A pair of heads-up-display goggles"; 
}

long()
{
    write("This is a rugged, rubberized pair of goggles that as far as you can\n"+
          "tell is some sort of battlefield awareness device used by creatures\n"+
          "within the Monster's Guild. There are several commands that you can\n"+
          "use for it. Note that you do not have to 'wear' the goggles first.\n\n"+
          "'glist'       A listing of monsters available for heads-up viewing.\n"+
          "'gset <num>'  Sets the goggles to view that particular monster.\n"+
          "'goggles on'  Turns the goggles on. Be warned! It might get quite trippy.\n"+
          "'goggles off' Turns the goggles off, and consequently the display.\n");

    
    if(is_goggles_on)
        write("The heads-up-display is currently on.\n"); 
    else
        write("The heads-up-display is currently off.\n"); 


    if(my_monster)
        write("The goggles are currently set to view " + my_monster()->query_name() + ".\n");
    else
        write("The goggles are not set to view any monster in particular.\n");

}

get() { return 1; }
query_value() { return 10; }
query_weight() { return 1; }
query_save_flag() { return 1; }

init()
{
	add_action("on_glist","glist");
    add_action("on_gset","gset");
    add_action("on_goggles","goggles");
}


on_goggles(arg)
{
    object previous_viewer;

    if(!arg) return 0;


    if(arg == "on")
    {
        if(is_goggles_on)
        {
            write("The goggles are already on.\n");
            return 1;
        }
        else
        {
            write("You put the goggles on your face and switch them on.\n");
            say(this_player()->query_name() + " wears a set of HUD goggles and powers them on.\n");
            is_goggles_on = 1;


            if(my_monster)
            {
                previous_viewer = my_monster->query_obj(OBJ_SNOOP_VIEW);
                if(previous_viewer && previous_viewer->is(MODE_SNOOP_ACTIVE))
                {
                    tell_object(previous_viewer, BWHT + HIR + "\n\nYour goggles suddenly fade and wink out.\n" + NORM);
                }

                my_monster->set_obj(OBJ_SNOOP_VIEW, this_player());
                my_monster->toggle_on(MODE_SNOOP_ACTIVE);
                write("You are now viewing the world translucently through the eyes of " + my_monster->query_name() + ".\n");
            }
            else
            {
                write("Nothing happens.\n");
            }
            return 1;
        }
    }
    else if(arg == "off")
    {
        if(!is_goggles_on)
        {
            write("The goggles are already off.\n");
            return 1;
        }
        else
        {
            write("You remove the goggles and switch them off.\n");
            say(this_player()->query_name() + " removes a set of HUD goggles and powers them off.\n");
            is_goggles_on = 0;

            if(my_monster)
            {
                my_monster->toggle_off(MODE_SNOOP_ACTIVE);
                my_monster->set_obj(OBJ_SNOOP_VIEW, 0);
            }
            else
                write("The goggles seem to have been inactive already.\n");

            return 1;

        }
    }
    else return 0;
}

on_gset(arg)
{
    object whole_roster;
    int i;
    if(!arg) return;

    if(is_goggles_on)
    {
        write("You cannot do this when the goggles are already on.\n");
        return 1;
    }

    if(sscanf(arg, "%d", i) != 1) return;

    whole_roster = query_roster();
    if(i >= sizeof(whole_roster) || i < 0) return;

    if(whole_roster[i] && !environment(whole_roster[i])) return;

    my_monster = query_roster_member(i);

    if(!my_monster) return 0;

    if(my_monster->query_level() > this_player()->query_level() &&
       this_player()->query_level() < 20)
    {
        write("You are unable to get a fix on " + my_monster->query_name() + " for some reason.\n");
        say(this_player()->query_name() + " fiddles around with the settings on the goggles.\n");    
        my_monster = 0;
        return 1;
    }

    write("You have selected " + my_monster->query_name() + " to view.\n");
    say(this_player()->query_name() + " sets a pair of HUD goggles to view " + my_monster->query_name() + ".\n");
    return 1;
}

on_glist()
{
    say(this_player()->query_name() + " pushes a button a pair of HUD goggles and glances at it.\n");
    write("You push the 'glist' button on the side of the goggles and look into them.\n");
    TACTICAL_DM->on_monster_guild_who();
    return 1;
}
