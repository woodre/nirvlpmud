inherit "/players/mizan/core/object.c";
#include "/obj/ansi.h"

string emotes;

reset(arg) 
{
    ::reset(arg);
    if(arg) return;

    set_name("cylinder");
    set_value(1600);
    set_weight(1);
    set_alias("uranium-238");
    add_alias("uranium");
    set_save_flag(1);

    set_short("A cylinder of Uranium-238 " + BBLK + HIG + "[RADIOACTIVE]" + NORM + NORM);
    set_long(
        "  This is a cylinder of glass containing a highly radioactive sample of uranium.\n"+
        "  It might be in your best interest to get rid of this thing and put some\n"+
        "  serious frigging distance between yourself and this crazy thing.\n");

    set_read("The cylinder has the following inscribed on it:\n"+
             "'55.2g sample. Sandia Laboratories.'\n");
    set_smell("The cylinder smells like nothing in particular.\n");
    set_taste("The cylinder tastes like nothing in particular.\n");

    emotes = ({
        "The cylinder of Uranium-238 gives off a soft, sickening glow.\n",
        "You notice a soft glow coming from the cylinder of Uranium-238.\n",
        "You are worried by the strange glow coming from the cylinder of Uranium-238.\n",
        "You almost feel as if heat is eminating from the cylinder of Uranium-238.\n",
        "Perhaps being so close to a vial of unshielded Uranium-238 is not a good idea.\n",
        "You are very concerned about being so close to fissile nuclear material.\n",
    });


}

init()
{
    ::init();
    add_action("on_give","give");
    /* 03/20/06 Earwax: no need for these to have been in reset() */
    remove_call_out("fake_beat");
    call_out("fake_beat", 10);
}

fake_beat()
{
    object env;
    object poison;


    env = environment(this_object());
    if(env && living(env) && env->is_player() && env->query_level() < 21)
    {
        poison = present("radiation-sickness", env);
        if(!poison) move_object(clone_object("/players/mizan/etheriel/items/uranium-238-sickness.c"), env);
    }
    else
    {
        if(1 == random(8) && env)
            tell_room(env, emotes[random(sizeof(emotes))]);
    }

    remove_call_out("fake_beat");
    call_out("fake_beat", 10);
}

/* taken from the nitro */
on_give(str) 
{
    string item,dest;
    if(!str) return 0;
    if (sscanf(str, "%s to %s", item, dest) != 2) return 0;

    if(!item) return 0;
    if(!dest) return 0;
    
    if(item)
        if(item && !id(item)) return 0;
    
        if(!find_player(dest)) 
        {
            write(short() + " cannot be given to a non-player.\n"); 
            return 1; 
        }

    if(!find_player(dest)->query_interactive()) 
    {
        write(short() + " cannot be given to the disconnected.\n");
        return 1;
    }

    return 0;
}
