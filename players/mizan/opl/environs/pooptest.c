/*****************************************************************************
 *      File:                   poop-volcano.c
 *      Function:               An unkillable monster based on autocannon.c
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:
 *      Change History:
 ****************************************************************************/

inherit "/players/mizan/opl/core/monster.c";
#include "../definitions.h"
#include "/obj/ansi.h"

int power_enabled;

/*
 * This is a monster which cannot normally be killed.
 * It can be deactivated temporarily with a power cut key.
 */

reset(arg)
{
    ::reset(arg);
    if (arg) return;
    power_enabled = 1;

    set_name("poop volcanogun");
    set_race("volcanogun");
    set_alias("volcano");
    set_short(HIR + "A poop volcanogun" + NORM);
    set_long("    This is a heavily armored, steel and reinforced concrete obelisk\n"+
             "  with a large mortar barrel type thing poking out of it. There appears to\n"+
             "  be no easy way to take this 'volcanogun' down. It is far too heavily armored\n"+
             "  to breach- luckily it appears to be immoveable so putting some distance\n"+
             "  between yourself and this horrible thing is probably the best strategy.\n"+
             "  The only possible weakness appears to be some sort infared sensor near\n"+
             "  gun barrels, but even that is covered in inches of transparent aluminum.\n"+
             "\n    In any event, the best way to simply describe this crazy weapons platform\n"+
             "  is as follows: It is an armored mechanical asshole capable of fully automatic\n"+
             "  weapons fire and shoots poop as its primary round. WONDERFUL!\n");
    set_level(19);
    set_hp(50000);
    set_al(0);
    set_wc(160);
    set_ac(1000);
    set_heal(200, 1);
    enable_commands();
}

short()
{
    if(power_enabled) return HIR + "A poop volcanogun" + NORM;
    else return HIR + "A poop volcanogun" + NORM + " (dormant)";
}

disable_volcanogun()
{
    object ob, oc;
    object room;

    room = environment(this_object());

    if(!power_enabled || !room) return;

    ob = first_inventory(room);
    
    tell_room(environment(this_object()), "You hear a loud click coming from the volcanogun.\nIt appears to have powered down temporarily.\n");

    call_other(this_object(), "attack_object");
    call_other(this_object(), "attack_object");
    call_other(this_object(), "stop_fight");
    call_other(this_object(), "stop_fight");
    call_other(this_object(), "stop_hunter");
    call_other(this_object(), "stop_hunter");

    while(ob)
    {
        oc = next_inventory(ob);

        if(living(ob) &&
           ob->query_attack() &&
           ob->query_attack() == this_object())
        {
            ob->attack_object();
            ob->attack_object();
            ob->stop_fight();
            ob->stop_fight();
            ob->stop_hunter();
            ob->stop_hunter();
        }

        ob = oc;
    }

    power_enabled = 0;
    remove_call_out("activate_volcanogun");
    call_out("activate_volcanogun", 600);
}

activate_volcanogun()
{
    tell_room(environment(this_object()), "The green LED on the volcanogun's dome shuts off. It starts blinking red again.\n");
    power_enabled = 1;
}

init()
{
    object room;

    if (!this_player()) return;

    room = environment(this_player());

    if (room &&
            power_enabled &&
            room == environment(this_object()) &&
            this_player()->is_player() &&
            this_player()->query_level() < 20 &&
            !this_player()->query_invis())
    {
        say(HIY + "The Poop volcanogun swivels to attack " + this_player()->query_name() + "!\n" + NORM);
        this_object()->attack_object(this_player());
    }
}

heart_beat()
{
    object poop;

    if (attacker_ob && 1 == random(2))
    {
        say("A hail of rabbit poop pellets come streaming from the volcanogun!\n");
        say(HIY + "BLAM! BLAM! BLAM! BLAM! BLAM! BLAM! BLAM!\n" + NORM);
    }
    
    if (attacker_ob && 1 == random(4) && environment(this_object()))
    {
        poop = clone_object("/players/mizan/etheriel/items/shit.c");
        move_object(poop, environment(this_object()));
/*        poop->set_size(random(50) + 5); */
        call_other(poop, "set_size", random(50) + 5);
        call_other(poop, "on_explode", attacker_ob);
    }

    if(attacker_ob && !power_enabled)
    {
        power_enabled = 1;
        say("The poop volcanogun powers back up near-instantly!\n");
    }

    ::heart_beat();
}

is_volcanogun() { return 1; }
