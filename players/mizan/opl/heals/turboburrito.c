#include "/sys/ansi.h"
inherit "/obj/generic_heal.c";
int is_decayed;

void reset(int arg)
{
    ::reset(arg);
    if (arg) return;
    is_decayed = 0;
    set_name("burrito");
    add_alias("bean burrito");
    set_short("An "+ HBWHT + RED + "insanely spicy" + NORM  + " " + HBYEL + HIK + "TURBO" + NORM + " bean burrito");
    set_long("This is a burrito roughly the size of three fists, filled with steaming\n"+
	     "chunks of spicy pork goodness, beans, cheese, guacamole... the works!\n"+
             "It has a rather spicy aroma to it, and you must wonder if the heat\n"+
             "from the burrito going in will be as bad as the heat of it going out...\n");
    set_type("bites");
    set_type_single("bite");
    set_msg(HIY+"You take a bite out of " + HIR + "FLAMING HOT, INSANELY SPICY" + NORM + " " + HBYEL + HIK + "TURBO" + NORM + " burrito.\n");
    set_msg2(" takes a bite out of a " + HIR + "FLAMING HOT, INSANELY SPICY" + NORM + " " + HBYEL + HIK + "TURBO" + NORM + " burrito.\n");
    add_cmd("eat");
    set_heal(75,75);
    set_charges(4);
    set_soak(7);
    set_stuff(13);
    set_value(500);
    call_out("decay", 1800);
}


query_save_flag()
{
    return 1;
}


decay()
{
    say(short() + " seems to be decaying.\n");
    call_out("decompose", 10);
}

decompose()
{
    say(short() + " appears to have decayed significantly.\nIt no longer looks tasty.\n");
    set_short("A decayed spicy bean burrito");
    set_long("This is a burrito roughly the size of three fists, filled with steaming\n"+
             "chunks of spicy pork goodness, beans, cheese, guacamole... the works!\n"+
             "However, it seems to have decayed significantly since it was made.\n"+
             "This should not be surprising as the half life of a burrito is quite small.\n");
    set_type("bites");
    set_msg(HIY+"You take a bite out of a decayed burrito.\n");
    set_msg2(" takes a bite out of a decayed burrito.\n");
    add_cmd("eat");
    set_heal(-10,-10);
    set_stuff(13);
    set_value(18);
    is_decayed = 1;
}

cmd_imbibe(str)
{
    object room, shit;
    int retval;
    retval = ::cmd_imbibe(str);

    if(retval == 1 && charges == 1 && this_player() && id(str))
    {
        /* we leave some poop */
        room = environment(this_player());
        if(room)
        {
            shit = clone_object("/players/mizan/etheriel/items/shit.c");
            move_object(shit, room);
            tell_room(room, 
                this_player()->query_name() + " has an uncontrollable bowel movement.\n" +
                "It must have been that " + HIR + "FLAMING HOT, INSANELY SPICY" + NORM + " " +
                HBYEL + HIK + "TURBO" + NORM + " burrito.\n");
            tell_object(this_player(), "Wow. That was embarrassing.\n");
            return 1; 
        }

    }

    return retval;
}
