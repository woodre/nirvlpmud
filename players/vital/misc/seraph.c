/******************************************************************************
 *	File:			seraph.c
 *	Function:		
 *	Author(s):		Vital@Nirvana
 *	Copyright:		Copyright (c) 2003 v-Dev Code Factory
 *					All Rights Reserved.
 *	Source:			11/16/03
 *	Notes:			
 *	Change History:
 *****************************************************************************/

#pragma combine_strings
#pragma strict_types

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"

inherit "/players/vital/closed/std/monster.c";

static int GlobalDivine, x;
static object GlobalMeat;
void divine_rage(object attacker_ob);
void divine_healing(object attacker_ob);

void
reset(status arg)
{
    ::reset(arg);
    if(arg) return;
    set_name("seraph");
    set_alias("angel");
    set_alt_name("Seraph");
    set_race("angel");
    set_level(19+random(3));
    set_al(400+random(100));
    set_gender("creature");
    set_short(RED+"Seraph"+NORM+", the Angel of Fire");
    set_long("\
  In the midst of the " + BOLD + "brilliance" + NORM + " radiating \
from the being in this\n place, details begin to become fuzzy.\
This entity is definitely\n humanoid in its basic shape. The size \
of this being is hard to\n determine as it " + BLINK + "shimmers"
+ NORM + " brightly. It is easily several meters\n high and \
floats a couple decimeters off the ground. It is also\n possible \
to discern several sets of what can only be described\n as wings \
that cover the upper and lower halves of the entity\n while \
others keep it aloft.\n");
    load_chats( ({
        "Wind rushes around you from the sound of wings beating.\n",
        "The " + RED + "Seraph" + NORM + 
            "'s voice booms, \"You have been judged!\"\n",
        HIR + "Fire" + NORM + " flashes and rolls around the room.\n",
        BLINK + BOLD + "Flashes" + NORM + 
            " of light burn and blind the room.\n"
    }) );
    set_a_chat_chance(15);
    set_chat_chance(7);
    load_a_chats( ({
        "The " + RED + "Seraph" + NORM + 
            "'s voice booms, \"You have been found. . .\n\tLacking.\"\n",
        "Fire flares up and the heat is unbearable.\n",
        "Evil will be judged.\n",
    }) );
    set_message_hit(
    ({
        "causes justice to rain down on","",
        HIR+"incinerated"+NORM," with blasts of righteousness",
        "slashed"," to shreds",
        "sliced"," from bone to sinew",
        "jacks"," over the head",
        "scratched"," leaving trails of blood",
        "singed"," with a staggering glare"}));
    set_chance(30+random(41));
    set_spell_mess1("");
    set_spell_mess2("");
    set_spell_dam(30+random(45));
    set_dead_ob(TO);
    set_wc_bonus(20+random(18)); /* averages 38 pts more damage with specials */
    set_ac_bonus(10+random(15)); /* healing based on player lvl, i.e. 19+6 */
    add_money(random(2000) + 5555); /* lvl 19-21, 4-6k coins */
    GlobalDivine = FALSE;
    x = 100;
    GlobalMeat = 0;
}

void
init()
{
    if ( this_player()->query_level() > 20 )
        add_action("kill_em", "fight");
    ::init();
}

int
heart_beat()
{
    x--;
    if ( !ENV() )
    {
        attacker_ob = NULL;
        GlobalDivine = FALSE;
        x = 100;
        return 1;
    }
    GlobalDivine = TRUE;
    if (attacker_ob)
    {
        GlobalMeat = attacker_ob;
        if (present(attacker_ob, ENV(TO)))
        {
            divine_rage(attacker_ob);
            divine_healing(attacker_ob);
        }
    x = 100;
    }
    ::heart_beat();
}

int
monster_died()
{
    object corpse, prize;
    corpse = present("corpse", ENV());
    corpse->set_name(short_desc);
    corpse->set_value(TO->query_level());
    write_file("/players/vital/logs/angel.death",ctime(time()) + TPN + " " + 
        " level: " + TP->query_total_level() + "\n");
    return 1;
}

string
get_spell_mess1()
{
    string message, meat;
    meat = (string)TPN;
    (meat == "Seraph") ? (meat) : (meat = "Monster");
    switch ( random(5) )
    {
        case 0:
            message = "The " + RED + "Seraph" + NORM + 
                "'s voice booms, You will Die, " + meat +"!";
            break;
        case 1:
            message = "The " + RED + "Seraph" + NORM + 
                "'s voice booms, Judgement has come to " + meat +"!";
            break;
        case 2:
            message = "The power of " + random( (int)LVL ) + 
                " flares of light attack " + meat + ".";
            break;
        case 3:
            message = RED + "Seraph" + NORM + " reaches into " +
                meat + "'s soul and twists.";
            break;
        case 4:
            message = meat + " falls to the floor quivering.";
            break;
        default:
            message = "This should never happen. Write Vital!";
    }
    return message;
}

string
get_spell_mess2()
{
    string message;
    switch ( random(5) )
    {
        case 0:
            message = "The " + RED + "Seraph" + NORM + 
                "'s voice booms, You will Die!";
            break;
        case 1:
            message = "The " + RED + "Seraph" + NORM + 
                "'s voice booms, Judgement has come to you!";
            break;
        case 2:
            message = "The power of " + random( (int)LVL ) + 
                " flares of light attack you.";
            break;
        case 3:
            message = RED + "Seraph" + NORM + 
                " reaches into your soul and twists.";
            break;
        case 4:
            message = "You fall to the floor quivering.";
            break;
        default:
            message = "This should never happen. Write Vital!";
    }
    return message;
}

void
divine_rage(object attacker_ob)
{
    int stamina, lvl, al;
    
    if ( !(lvl = (int)attacker_ob->query_total_level()) )
        lvl = (int)attacker_ob->query_level();
/* check if attacker has a total_level and if not returns the */
/* plain, vanilla level of the attacker. This is mainly for  */
/* times when attacking pets and other assorted npcs. */

    if ( !(stamina = (int)TP->query_attrib("sta")) )
        stamina = 25;
/* check if attacker has a stamina attrib and if not sets it to */
/* a standardized value of 25. again, mainly for pets, npcs. */
    
    if ( !(al = (int)attacker_ob->query_alignment()) )
        al = 0;
/* check if attacker has an alignment and if not sets it to */
/* a standardized value of 0. again, mainly for pets, npcs. */

    if (GlobalDivine)
    {
        if ( !random(3) )
            do_damage(stamina + stamina,"other|fire");
        else do_damage(random(stamina), "other|fire");
        if (al < -25) do_damage( random( (-1) * (al) ), "other|divine");
        write(get_spell_mess2() + "\n");
        say(get_spell_mess1() + "\n");
    }
    if (random(stamina) > 13) set_ac( random(lvl) );
}

void
divine_healing(object attacker_ob)
{
    int lvl;
    if ( (lvl = (int)attacker_ob->query_total_level()) )
        lvl = (int)attacker_ob->query_level();
/* check if attacker has a total_level and if not returns the */
/* plain, vanilla level of the attacker. This is mainly for  */
/* times when attacking pets and other assorted npcs. */

    if ( GlobalDivine && (hit_point < 100) )
    {
        if ( random(4) ) hit_point += (hit_point);
        write(short_desc + " reaches toward heaven and begins to glow.\n");
        say(short_desc + " reaches toward heaven and begins to glow.\n");
    }
    hit_point += random( lvl + 10 );
    tell_object(TP, short_desc + 
        "whispers to you, \"I am disabused of your attempts to kill me.\"\n");
    if (hit_point > max_hp) hit_point = max_hp;
}

mixed
query_environment(int a)
{
    if (!environment(this_object())) 
        return short_desc + " does not have an environment.\n";
    return environment(this_object());
}

int
kill_em(string mob_id)
{
    object bob;
    if (this_player()->query_level() < 20 ) return 0;
    if (!mob_id)
    {
        notify_fail(short_desc + "says, \"What did you want me to whack?\"\n");
        return 0;
    }
    if ( (mob_id == "seraph") || (mob_id == "angel") )
    {
        notify_fail(short_desc + "says, \"I cannot attack myself.\"\n");
        return 0;
    }
    if ( bob = present(mob_id, environment(this_object())) );
    {
        if (!query_attack()) attack_object(bob);
    }
    return 1;
}