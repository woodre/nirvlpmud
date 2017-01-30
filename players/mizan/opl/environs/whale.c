/*****************************************************************************
 *      File:                   whale.c
 *      Function:               There are several copies of this distributed
 *                              across the maze. Will KILL you if you are in
 *                              the same room as it.
 *                              This item is a double edged sword in that it
 *                              can soften up hard monsters if it spawned in
 *                              the same room as them, but can backfire if you
 *                              are in the same room as it.
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:
 *      Change History:         DONE Initial revision - 09 Mar 2011
 ****************************************************************************/

/* 10/07/05 - Earwax - Prevented it from being given to wizzes. */

inherit "/obj/monster.c";
#include "/obj/user/shout_only.c"
#include "/obj/ansi.h"
#include "../definitions.h"

status is_lit;
status has_exploded;

reset(arg)
{
    ::reset(arg);
    if (arg) return;
    is_lit = 0;
    has_exploded = 0;

    set_short(HBRED + HIW + "A dead whale" + NORM);
    set_race("whale");
    set_name("dead whale");
    set_alias("whale");
    set_hp(25000);
    set_ac(2500);
    set_wc(1);

/*
    set_smell("The improvised explosive device smells of gunpowder.\n");
    set_taste("The body of the car tastes salty. Consuming it would be a very bad idea.\n");
 */
}

short()
{
    if (has_exploded) return 0;
    if (is_lit)
        return short_desc + " " + HIR + "(lit!)" + NORM;
    else return short_desc;
}

long()
{
    write("This is a dead whale, probably a humpback whale by the looks of it... \n"+
          "Well who we kidding- from this perspective you really can't tell what it is\n"+
          "other than that it is indeed a whale... and that it was a male one at that.\n"+
          "How it got here is anyone's guess.\n");

    write("\nThe corpse is bloated- not due to decomposition, but due to what can be\n"+
	  "assumed is a rather large amount of explosives stuffed into it.\n"+
          "There is a fuse sticking out of a hole drilled into the skull which\n"+
          "presumably if lit would cause this... thing... to blow up sky high.\n"+
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
    call_out("on_fuse_still_burning", 6);
}

on_light(arg)
{
    if (!arg) return 0;
    if (id(arg) || arg == "fuse")
    {

        write("You light fuse sticking out of the whale's skull.\nIt burns brightly and quickly.\n");
        write(HIY + "YOU MIGHT WANT TO CLEAR THE HELL OUT OF THIS AREA.\n" + NORM);

        say((this_player()->query_name())+" lights the fuse sticking out of the dead whale's skull.\n");

        is_lit = 1;
        call_out("on_light_fuse", 8);
        return 1;
    }
}

on_light_fuse()
{
    say("The fuse in the dead whale burns brightly!\n");
    call_out("on_fuse_still_burning", 2 + random(7));
}

on_fuse_still_burning()
{
    say("The dead whale's fuse is almost burned through!\n");
    call_out("on_light_explode", 1 + random(2));
}

on_light_explode()
{
    object victim;
    object ob, oc;
    object room;
    string a,b;
    string message;
    int i;

    say(HIY);
    pow_asplode(environment());
    say(ESC + "[0m"+ ESC + "[0m");

    room = environment(this_object());
    if(!room)
    {
        destruct(this_object());
    }

    victim = first_inventory(room);
    message = HIY + "\n(junk) Something went asplode in the Proving Grounds of the OverPowerLord.\n" +
                 "Fist-sized chunks of meat rain down from the sky! INCOMING!\n" + NORM;
    chan_msg(message);
    emit_channel("junk", message);
    /* if you are silly enough to be holding the object... */

    has_exploded = 1;

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
                victim->hit_player(5000);
          }

        }

        victim = oc;

    }

    remove_call_out("meat_storm");
    call_out("meat_storm", 2);
}


meat_storm()
{
    object victim, ob, oc, room;
    int i;

    /* now lets have fun with all the players on the MUD. */
    ob = users();
    for(i = 0; i < sizeof(ob); i ++)
    {
        room = environment(ob[i]);

        if(ob[i]->query_level() <= 20 &&
           room &&
           !present("meat", room))
        {
            oc = clone_object("/players/mizan/opl/heals/whalemeat.c");
            move_object(oc, room);
            tell_room(room, "A chunk of whale meat strikes the ground nearby.\n");
        }
    }
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
    if(attacker_ob && !has_exploded) on_light_explode();
    else ::heart_beat();
}
