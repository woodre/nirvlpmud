/*****************************************************************************
 *      File:                   autocannon.c
 *      Function:               An unkillable monster
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

    set_name("Anti-personnel Autocannon");
    set_race("autocannon");
    set_alias("cannon");
    set_short(HIR + "An Anti-personnel Autocannon" + NORM);
    set_long("    This is a heavily armored, steel and reinforced concrete obelisk\n"+
             "  with a large multibarreled machine gun poking out of it. There appears to\n"+
             "  be no easy way to take this autocannon down. It is far too heavily armored\n"+
             "  to breach- luckily it appears to be immoveable so putting some distance\n"+
             "  between yourself and this horrible thing is probably the best strategy.\n"+
             "  The only possible weakness appears to be some sort infared sensor near\n"+
             "  gun barrels, but even that is covered in inches of transparent aluminum.\n");
    set_level(19);
    set_hp(50000);
    set_al(0);
    set_wc(80);
    set_ac(100);
    set_heal(200,1);
}

short()
{
    if(power_enabled) return HIR + "An Anti-personnel Autocannon" + NORM;
    else return HIR + "An Anti-personnel Autocannon" + NORM + " (powered off)";
}

disable_autocannon()
{
    object ob, oc;
    object room;

    room = environment(this_object());

    if(!power_enabled || !room) return;

    ob = first_inventory(room);
    
    tell_room(environment(this_object()), "You hear a loud click coming from the Autocannon.\nIt appears to have powered down temporarily.\n");

    this_object()->attack_object();
    this_object()->attack_object();
    this_object()->stop_fight();
    this_object()->stop_fight();
    this_object()->stop_hunter();
    this_object()->stop_hunter();

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
    remove_call_out("activate_autocannon");
    call_out("activate_autocannon", 600);
}

activate_autocannon()
{
    tell_room(environment(this_object()), "The green LED on the Autocannon's dome shuts off. It starts blinking red again.\n");
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
        say(HIY + "The Anti-personnel Autocannon swivels to attack " + this_player()->query_name() + "!\n" + NORM);
        this_object()->attack_object(this_player());
    }
}

heart_beat()
{
    if (attacker_ob && 1 == random(2))
    {
        say("A hail of bullets come streaming from the Autocannon!\n");
        say(HIY + "BLAM! BLAM! BLAM! BLAM! BLAM! BLAM! BLAM!\n" + NORM);
    }

    if(attacker_ob && !power_enabled)
    {
        power_enabled = 1;
        say("The Anti-personnel Autocannon powers back up near-instantly!\n");
    }

    ::heart_beat();
}

is_autocannon() { return 1; }
