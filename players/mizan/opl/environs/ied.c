/*****************************************************************************
 *      File:                   ied.c
 *      Function:               An explosive item based on the blockbuster
 *                              which kills players and monsters near it
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:
 *      Change History:
 ****************************************************************************/

inherit "/obj/monster.c";
#include "/obj/user/shout_only.c"
#include "/obj/ansi.h"
#include "../definitions.h"

status is_lit;
string random_car;

reset(arg)
{
    ::reset(arg);
    if (arg) return;
    is_lit = 0;

    set_short(HBRED + HIW + "An improvised explosive device" + NORM);
    set_race("device");
    set_name("Improvised Explosive Device");
    set_alias("ied");
    set_hp(25000);
    set_ac(2500);
    set_wc(1);

    random_car = RANDOBJ_DM->get_random_car();
}

short()
{

    if (is_lit)
        return short_desc + " " + HIR + "(lit!)" + NORM;
    else return short_desc;
}

long()
{
    write("This improvised explosive device was once a " + random_car + " whose engine\n");
    write("bay and passenger compartment are now completely sealed and filled up\n");
    write("with bags of smokeless gunpowder and magnesium dust.\n");
    write("There is a fuse sticking out of a hole drilled into the roof which\n"+
          "presumably if lit would cause this device to blow up sky high.\n"+
          "It doesn't take much thinking to realize that anything which was once\n"+
          "living in the immediate surrounding area would be instantly rendered dead.\n");

    if (is_lit)
        write(HIR + "THE FUSE IS LIT!! RUN FOR YOUR LIVES, YOU BLOCKHEADS!\n" + NORM + NORM);
}


init()
{
    ::init();

    add_action("on_light", "light");
}

/* a quiet way to light the fuse */
light_me()
{
    is_lit = 1;
    call_out("on_light_fuse", 4);
}

on_light(arg)
{
    if (!arg) return 0;
    if (id(arg) || arg == "fuse")
    {

        write("You light fuse sticking out of the roof.\nIt burns brightly and quickly.\n");
        write(HIY + "YOU MIGHT WANT TO CLEAR THE HELL OUT OF THIS AREA.\n" + NORM);

        say((this_player()->query_name())+" lights the fuse sticking out of the improvised explosive device.\n");

        is_lit = 1;
        call_out("on_light_fuse", 8);
        return 1;
    }
}

on_light_fuse()
{
    say("The fuse on the improvised explosive device burns brightly!\n");
    call_out("on_fuse_still_burning", 2 + random(7));
}

on_fuse_still_burning()
{
    say("The improvised explosive device's fuse is almost burned through!\n");
    call_out("on_light_explode", 1 + random(2));
}

on_light_explode()
{
    object victim;
    object ob, oc;
    object room;
    string a,b;
    string message;

    say(HIY);
    pow_asplode(environment());
    say(ESC + "[0m"+ ESC + "[0m");

    room = environment(this_object());
    if(!room)
    {
        destruct(this_object());
    }

    victim = first_inventory(room);
    message = "\n" + HIY + "(junk) Something went asplode in the Proving Grounds of the OverPowerLord.\n" +
                 "Fist-sized parts of what was once a " + random_car + " rain from the sky." + NORM + "\n";
    chan_msg(message);
    emit_channel("junk", message);
    /* if you are silly enough to be holding the object... */
    while(victim)
    {
        oc = next_inventory(victim);

        if(living(victim) && victim != this_object())
        {

            /* make them wimpy for fun */
 
           if (victim->is_player() && 1 == random(5))
            {
                tell_room(room, victim->query_name() + " is thrown clear!\n");
                tell_object(victim, "That was insane!\n");
                victim->run_away();
            }
            else
            {

                tell_room(room, victim->query_name() + " is blown to bits by the blast!\n");
                /* victim->hit_player(5000 | "fire");*/
                call_other(victim, "hit_player", 5000);
          }

        }

        victim = oc;

    }

    if (environment(this_object()) && environment(environment(this_object())))
        call_other(environment(this_object()), "on_explode");

    destruct(this_object());
}


/* for the vehicles */
detonate(arg)
{
    return on_explode(arg);
}

pow_asplode(arg)
{
    tell_room(arg, "\nPPPPPPPP         OOOOOOOOOO      WWW                WWW     !!!  \n");
    tell_room(arg, "PPPPPPPPPP      OOOOOOOOOOOO     WWW                WWW    !!!!! \n");
    tell_room(arg, "PPP     PPP    OOOO      OOOO     WWW     WWWW     WWW     !!!!! \n");
    tell_room(arg, "PPP     PPP    OOO        OOO     WWW    WWWWWW    WWW     !!!!! \n");
    tell_room(arg, "PPPPPPPPPP     OOO        OOO      WWW  WWWWWWWW  WWW      !!!!! \n");
    tell_room(arg, "PPPPPPPP       OOO        OOO      WWW  WWW  WWW  WWW       !!!  \n");
    tell_room(arg, "PPP            OOOO      OOOO       WWWWWW    WWWWWW             \n");
    tell_room(arg, "PPP             OOOOOOOOOOOO        WWWWW      WWWWW        !!!  \n");
    tell_room(arg, "PPP              OOOOOOOOOO          WWW        WWW         !!!  \n\n");
}

get() {
    return 0;
}

heart_beat()
{
    if(attacker_ob) on_light_explode();
    else ::heart_beat();
}
