inherit "/players/mizan/core/object.c";
#include "/obj/user/shout_only.c"
#include "/obj/ansi.h"

id(str) { return str == "vial" || str == "nitro"; }

short() { return "A vial of nitroglycerin " + HIR + HBYEL + "[UNSTABLE]" + NORM + NORM; }

long() {
  write("Whoa! This vial is labelled: " + HIR + "'DO NOT SHAKE OR DROP'" + NORM + ".\n"+
        "Hmm... You can assume that it would be very bad if you shaked\n"+
        "or dropped this thing... or even drank it... It would also\n"+
        "be a rather silly idea to even pick up this thing it seems.\n");
  write("You could 'put down nitro' if you wanted.\n");
}

get() { 
    if(caller()->query_npc()) 
        return 0;
    return 1;
}

query_save_flag() { return 1; }
query_weight() { return 1; }
query_zok() { return "BOOOOM!!"; }


init() 
{

    if(environment(this_object()) && environment(this_object())->is_player()) 
    {
        if(!environment(this_object())->query_interactive()) 
        {
            move_object(this_object(), environment(this_object()));
        }
    }

    add_action("drinkme_and_die","drink");
    add_action("give","give");
    add_action("shakeme_and_die","shake");
    add_action("just_die","jump");
    add_action("just_die","skip");
    /*
    add_action("just_die","laugh");
    */
    add_action("just_die","dance");
    add_action("just_die","hiccup");
    add_action("just_die","kick");
    add_action("just_die","wiggle");
    add_action("just_die","skip");
    add_action("just_die","poke");
    add_action("just_die","tackle");
    add_action("just_die","punt");
    add_action("down_nitro","put");
}

down_nitro(str) 
{
    if(!str) return 0;
    if(str != "down nitro") return 0;
    
    write("You carefully put the vial of nitroglycerin on the ground.\n");
    say(this_player()->query_name()+" puts a vial of nitro on the ground.\n");
    move_object(this_object(), environment(this_player()) );
    return 1; 
}

drinkme_and_die(str) 
{
    if(!str || !id(str)) return 0;
    if(this_player()!=environment(this_object())) return 0;
    
    write("You pop open the cap and slam some nitroglycerin.\n\n");
    tell_room(environment(this_player()),
    (this_player()->query_name()) + " stupidly drinks a vial of nitroglycerin.\nBOOM!!\n");
    zok_player();
    write("You feel like you have just given birth to an elephant.\n");
    destruct(this_object());
    return 1;
}

shakeme_and_die(str) 
{
    if(!str || str != "nitroglycerin") return 0;
    if(this_player()!=environment(this_object())) return 0;
    write("You stupidly shake the vial of nitroglycerin.\nYou moron...\n\n");
    tell_room(environment(this_player()),
    (this_player()->query_name()) + " stupidly shakes a vial of nitroglycerin.\nBOOM!!\n");
    zok_player();
    destruct(this_object());
    return 1;
}

just_die(str) 
{
    if(1 == random(3)) return 0;
    if(this_player()!=environment(this_object())) return 0;
    write("You agitated the vial of nitroglycerin!\nIt detonates.\n");
    tell_room(environment(this_player()),
    (this_player()->query_name()) + " excites a vial of nitroglycerin, like a total friggin idiot.\n");
    zok_player();
    destruct(this_object());
    return 1;
}

drop(strg)
{
    if(strg) return 0;
    if(environment(this_object()) != this_player()) return;
    write("You drop the vial of nitroglycerin. You idiot!\n\n");
    zok_player();
    destruct(this_object());
}

zok_player()
{
    string temp;
    string name;

    int a;
    if(environment(this_object()) != this_player()) return;

    if(this_player()->query_real_name() == "mizan") return;
    name = this_player()->query_name();

    chan_msg("You hear a tremendous explosion coming from somewhere on the MUD.\n");    
    pow_asplode();

    if(1 == random(2)) 
    {
        chan_msg(this_player()->query_name() + " was just blown to fist-sized chunks by a vial of nitroglycerin.\n");
        this_player()->hit_player(50000, this_player());
        
        if(this_player()->query_level() < 20)
            chan_msg("You may now refer to " + name + " as 'some stinky red mist'.\n");

        say("Fist sized chunks of flesh explode in a circular pattern around the room.\n");
        
        write_file("/players/mizan/logs/NITROGLYCERIN", this_player()->query_real_name() + 
            " exp:" + this_player()->query_exp() + 
            " absorbed 50000 damage at " + ctime() + "\n");
    }

    write_file("/players/mizan/logs/NITROGLYCERIN", this_player()->query_real_name() + " triggered the nitro at " + ctime() + "\n");

    a = this_player()->query_hp();
    this_player()->add_hit_point(-a);
    return 1;
}

on_explode(arg)
{
    object room;

    if(!arg || !environment(arg))
    {
        return 0;
    }

    room = environment(arg);
    move_object(this_object(), room);    

    chan_msg("You feel the shockwave of tremendous explosion far off in the distance.\n");

    pow_asplode();

    tell_room(environment(),"A vial of nitro-glycerin explodes right near " + arg->query_name() + "!\n");

    tell_room(environment(),"Everything goes blank from the force of the terrific explosion!\n");
    tell_room(environment(),"Your ears start ringing. Ouch!\n");

    move_object(clone_object("/players/mizan/etheriel/items/blockbuster-nearmiss-residue.c"), arg);

    destruct(this_object());
    return 1;
}

/* for the vehicles */
detonate(arg)
{
    return on_explode(arg);
}

status pow_asplode()
{

    object room;
    room = environment(environment(this_object()));

    if(!room) return 0;

    tell_room(room, HIR + HBYEL + "\n");
    tell_room(room, "PPPPPPPP         OOOOOOOOOO      WWW                WWW     !!!  \n");
    tell_room(room, "PPPPPPPPPP      OOOOOOOOOOOO     WWW                WWW    !!!!! \n");
    tell_room(room, "PPP     PPP    OOOO      OOOO     WWW     WWWW     WWW     !!!!! \n");
    tell_room(room, "PPP     PPP    OOO        OOO     WWW    WWWWWW    WWW     !!!!! \n"); 
    tell_room(room, "PPPPPPPPPP     OOO        OOO      WWW  WWWWWWWW  WWW      !!!!! \n");
    tell_room(room, "PPPPPPPP       OOO        OOO      WWW  WWW  WWW  WWW       !!!  \n");
    tell_room(room, "PPP            OOOO      OOOO       WWWWWW    WWWWWW             \n");
    tell_room(room, "PPP             OOOOOOOOOOOO        WWWWW      WWWWW        !!!  \n");
    tell_room(room, "PPP              OOOOOOOOOO          WWW        WWW         !!!  \n");
    tell_room(room, NORM + NORM + "\n");
    return 1;
}

give(str) 
{
    string item,dest;
    if(!str) return 0;
    if (sscanf(str, "%s to %s", item, dest) != 2) return 0;
    if(!item) return 0; if(!dest) return 0;
    if(item)
    if (item && !id(item)) return 0;
    
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

    if(this_player()->query_level() < 10) 
    {
        zok_player();
        return 1;
    }

    if(!random(3))
    {
        just_die();
        return 1; 
    }
    return 0;
}
