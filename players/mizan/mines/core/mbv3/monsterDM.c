#define IS_MONSTER_DM
#include "../../definitions.h"
#include "definitions.h"
#include "router.h"

#include "/obj/ansi.h"
#include "/obj/user/shout_only.c"

/*
 * The purpose of this object is to house basic functionality used by the smart monsters.
 * Contents personal copyright Mizan@Nirvana, 2003.
 * Exclusive rights also to Boltar@Nirvana.
 * Reproduction on other muds restricted, under penalty of personal retribution.
 *
 */

/* Notes:
 *
 * it should be noted that the do_random_move() and heart_beat() functions have totally different
 * clocks and are basically completely unrelated. They are not synchronized.
 *
 * 15 nov 2003 - made it so fights don't start in query_fight_area() rooms.
 *
 * 16 nov 2003 - added set_coverage_map() which makes the monster setup a
 * primary monster it will try to protect. This happens outside of orders.
 * It's a little ghetto but i like it. it works well. The string of 'all' will
 * make the monster cover anything, without bias, like utility.
 * The set_coverage_map() should match the query_name() of the monster to cover.
 *
 * 18 nov 2003 - decided to put a lot more logic on board of the monsters.
 * remembering who hurt and harmed them will be a function of the individual
 * creature, not the statistics engine. This is a major change in the original design
 * that i had in mind. i dont know how i am going to do it yet.
 *
 * 01 dec 2003 - figured this code was good enough to be v0.8.
 * It is in the game now, in a capacity one step above the shit-flinging Beanos.
 *
 */

string directions; /* used by do_random_walk(); */
string waypoints;  /* used by do_teleport() */
string waypoints_remote; /* used by do_teleport() */



/*  contains a pool of functions used by the monsters within the guild.
 *
     */

/* member variables */

id(str) { return str == "monster-daemon" || str == "server"; }

short() { return "A network server named (monster-daemon)"; }


reset(arg)
{
    if(arg) return;
    
    move_object(this_object(), DAEMON_HOME);
    report_message("System online. Function reset(" + arg + ") called.\n");

}


/* called if mode MODE_COVERS_PRESENT_ALLIES is alive. Basically looks for a
 * lower level creature that might be in trouble in the same room, if found
 * will begin whaling away at it, but not change orders */
check_allies_presently_fighting(arg)
{
    object ob;
/* added next line - verte */
    object oc;
    object att;
    object result;
    object room;

    if(!arg) return 0;

    room = environment(arg);
    if(!room) return 0;

    /* well... if we are in a no-fight room, must return zero unfortunately */
    if(room->query_no_fight()) return 0;

    ob = first_inventory(room);

    while(ob)
    {
        /* next line by verte */
        oc = next_inventory(ob);
        /* we have an attacker? */
        att = ob->query_attack();
        
        if(att &&
           att->is_player() &&
           ob->fellow_monster() &&
           att != arg &&
           !att->fellow_monster())
        {
            /* if attacker is a non-monster member, and attacking a monster member */
            result = att;
            return result;        
        }

      /* changed from ob = next_inventory(ob); -verte */
        ob = oc;

    }

    return 0;
}

/* if a player is attacking the same thing we are attacking, we turn on the player */
check_player_stealing_kill(arg)
{
    object ob;
    object ob_att;
    object room;
    object attacker;

    if(!arg) return 0;

    attacker = arg->query_attack();
    room = environment(arg);

    if(!attacker || !room) return;

    /* if the attacker is aggro, we always return zero */
    if(attacker->query_aggressive()) return 0;

    ob = first_inventory(room);

    while(ob)
    {
        ob_att = ob->query_attack();

        if(ob_att &&
           ob != arg &&
           ob_att == attacker &&
           ob->is_player())
        {
            return ob;
        }

        ob = next_inventory(ob);
    }

    return 0;

}

/* we return 1 if we are inside something we are not supposed to move from */
check_trapped_inside_object(arg)
{
    object room;
    object roomroom;
    int i;
    string temp;

    if(!arg) return 0;

    room = environment(arg);
    if(room) roomroom = environment(room);

    /* we are stuck inside boltar's washing machine */
    if(room && room->id("washing machine"))
    {
        if(roomroom && 1 == random(10))
        {
            tell_room(roomroom, "You see " + arg->query_name() + " struggling helplessly inside the washing machine.\n");
            arg->report_message("I'm stuck inside a washing machine! Shit!\n");
            do_emote_panicked(arg);
        }
        return 1;
    }

    /* we are stuck inside boltar's stove */
    else if(room && room->id("stove"))
    {
        if(roomroom && 1 == random(10))
        {
            tell_room(roomroom, "You see " + arg->query_name() + " stuck inside a stove.\n");
            arg->report_message("I'm stuck inside a stove! Aooooooo!\n");
            do_emote_panicked(arg);
        }
        else if(1 == random(100) && roomroom)
        {
            tell_room(roomroom, HIY + "\n\nB O O M ! !\n\nSput sput sput...\n\n");
            tell_room(roomroom, HIY + "You see " + arg->query_name() + " EXPLODE inside the stove!\n" + NORM +
                      "Bits of sticky, steamy " + arg->query_name() + " go flying everywhere inside the stove.\n");
            destruct(arg);
        }
        return 1;
    }

    /* we are stuck inside a bag */
    else if(room && room->id("bag"))
    {
        if(roomroom && 1 == random(10))
        {
            tell_room(roomroom, "You see " + arg->query_name() + " struggling helplessly inside a bag.\n");
            arg->report_message("I'm stuck inside a bag! Buh!\n");
            do_emote_panicked(arg);
        }
        return 1;
    }

    /* boltar's UFO */
    else if(room && room->id("flying disc"))
    {
        if(roomroom && 1 == random(20))
        {
            tell_room(room, arg->short() + " grins evilly at you.\n");
            arg->report_message("I'm inside a flying disc! Whee!\n");
        }
        return 1;
    }

    /* something living is carrying us */
    else if(room && living(room))
    {
        if(roomroom && 1 == random(20))
        {
            tell_room(roomroom, "You see " + arg->query_name() + " being carried by " + room->query_name() + ".\n");
            arg->report_message("Ack. I'm being carried around by " + room->query_name() + ".\n");
        }
        return 1;
    }

    /* else activities for SPECIFIC rooms */

    /* Jareel's idea. The monster reads the obit, and busts out laughing! */
    else if(room && object_name(room) == "room/vill_green")
    {

        if(1 == random(10))
        {
            i = arg->query_monster_guild_level();
            temp = arg->query_name() + " reads the obituary notice.\n";

            switch(i)
            {
            case 1:
                temp = temp + arg->query_name() + " says: Go monsters! Yeehah!\n";
                break;
            case 2:
                temp = temp + arg->query_name() + " busts out laughing!\n";
                break;
            case 3:
                temp = temp + arg->query_name() + " says: BWAHAHAHAHA!!\n";
                break;
            case 4:
                temp = temp + arg->query_name() + " cackles maniacally!\n";
                break;
            case 5:
                temp = temp + arg->query_name() + " chuckles loudly.\n";
                break;
            }


            if(room) tell_room(room, temp); 
        }

    }

    /* otherwise we are not trapped */
    return 0;

}


/* this was a bug that i thought existed, and Humble confirmed its existence.
 * If a player starts combat with a monster and leaves, before a guild member starts
 * pounding on it (i.e. pillaging) the player still gets credits for the EXP because
 * they were a registered attacker.
 */
clear_attacker_bits(arg)
{
    object attacker;

    /* if the arg is a player, we don't care */
    if(!arg || !living(arg) || arg->is_player()) return;

    attacker = arg->query_attack();

    if(attacker) 
    {
        attacker->attack_object();
        attacker->attack_object();
        attacker->stop_fight();
        attacker->stop_fight();
        attacker->stop_hunter();
        attacker->stop_hunter();
    }

    arg->attack_object();
    arg->attack_object();
    arg->stop_fight();
    arg->stop_fight();
    arg->stop_hunter();
    arg->stop_hunter();

}


/**
 * This simply returns to us the number of people attacking us. 
 *
 */
count_attackers(arg)
{
    object room;
    object ob;
    int count;

    if(!arg) return 0;

    room = environment(arg);
    if(!room) return 0;

    ob = first_inventory(room);
    while(ob)
    {
        if(ob->query_attack() && ob->query_attack() == arg)
            count ++;
        ob = next_inventory(ob);
    }

    return count;
}


/* properly format the short desc of where we are */
describe_room(arg)
{
    string result;

    if(!arg) return "[somewhere unknown]";

    result = call_other(arg, "short");
    if(result) return "'" + result + "'";
    else return "'A dark room'";
    
}


/* simply a mimic of player.c functionality to clear our inventory */
destruct_inventory(arg) 
{
    object next_ob,ob;

    if(!arg) return;

    ob = first_inventory(arg);

    while(ob) 
    {
        next_ob = next_inventory(ob);
   
        /* first we move it to the home, in case its a container and has items inside */
        move_object(arg, LOCKERS_ROOM);
        destruct(ob);
        ob = next_ob;
    }
}


/* this occurs if we have our MODE_NOISY_ARRIVE set active. Basically splashes rooms
 * next to us to tell everyone we are here */
do_arrive_noisily(arg)
{
    if(!arg) return 0;
}


do_attack_mudkid(arg)
{
    object room;
    object ob;

    if(!arg) return 0;

    room = environment(arg);

    if(!room) return 0;

    /* well... if we are in a no-fight room, must return zero unfortunately */
    if(room->query_no_fight()) return 0;

    ob = first_inventory(room);

    while(ob)
    {  
        if(ob && living(ob) && ob->is_kid() && !room->query_fight_area() && ob != arg) 
        {
            /* sometimes we don't attack kids */
            if(1 == random(2))
            {
                tell_room(room, arg->query_name() + " eyes " + ob->query_name() + " suspiciously!\n");
                return 1;
            }

            /* But usually we do! */
            tell_room(room, HIR + arg->query_name() + " does not like KIDS!!\n" + NORM);
            tell_room(room, arg->query_name() + " leaps to attack " + ob->query_name() + "!\n" );
            
            /* don't need to clear attacker bits here */
            arg->attack_object(ob);
            break;
        }

        ob = next_inventory(ob);
    }
}


/* this function looks a lot like above? Why did i do this? I separated them because
 * i plan on adding other functionality in the future.
 */
do_attack_pet(arg)
{
    object room;
    object ob;

    if(!arg) return 0;

    room = environment(arg);

    if(!room) return 0;

    /* well... if we are in a no-fight room, must return zero unfortunately */
    if(room->query_no_fight()) return 0;

    ob = first_inventory(room);

    while(ob)
    {  
        if(ob && living(ob) && ob->is_pet() && !room->query_fight_area() && ob != arg) 
        {
            /* sometimes we don't attack pets */
            if(1 == random(2))
            {
                tell_room(room, arg->query_name() + " eyes " + ob->query_name() + " suspiciously!\n");
                return 1;
            }

            /* But usually we do! */
            tell_room(room, HIR + arg->query_name() + " does not like PETS!!\n" + NORM);
            tell_room(room, arg->query_name() + " leaps to attack " + ob->query_name() + "!\n" );

            /* don't need to clear attacker bits here */
            arg->attack_object(ob);
            break;
        }

        ob = next_inventory(ob);
    }
}


/* this function looks a lot like above? Why did i do this? I separated them because
 * i plan on adding other functionality in the future.
 */
do_attack_player_killer(arg)
{
    object room;
    object ob;

    if(!arg) return 0;

    room = environment(arg);

    if(!room) return 0;

    /* well... if we are in a no-fight room, must return zero unfortunately */
    if(room->query_no_fight()) return 0;

    ob = first_inventory(room);

    while(ob)
    {  
        if(ob && 
           living(ob) &&
           ob->query_pl_k() &&
           !room->query_fight_area() &&
           ob != arg &&
           ob->query_level() < 20) 
        {
            /* sometimes we don't attack pkers */
            if(1 == random(2))
            {
                tell_room(room, arg->query_name() + " eyes " + ob->query_name() + " suspiciously!\n");
                return 1;
            }

            /* But usually we do! */
            tell_room(room, HIR + arg->query_name() + " does not like PLAYER KILLERS!!\n" + NORM);
            tell_room(room, arg->query_name() + " leaps to attack " + ob->query_name() + "!\n" );

            /* don't need to clear attacker bits here */
            arg->attack_object(ob);
            break;
        }

        ob = next_inventory(ob);
    }
}


do_attack_routines(arg)
{
    int hp;
    int mhp;
    object room;
    object temp;
    object attacker;
    string attacker_name;

    if(!arg) return 0;

    hp = arg->query_hp();
    mhp = arg->query_mhp();
    attacker = arg->query_attack();
    room = environment(arg);

    /* attack routines */
    if(attacker)
    {
        /* if we are really hurt, we run */
        if(hp < (mhp / 5) &&
           !arg->is(MODE_PILLAGING) &&
           !arg->is(MODE_TO_THE_DEATH))
        {
            /* if we are insane, we will detonate against the attacker. */
            if(arg->query_monster_attrib(ATTRIB_INSANITY) > random(100))
                receive_orders(arg, ORDERS_EXPLODE_OBJECT, attacker, 1);
            else
                receive_orders(arg, ORDERS_HITFADE_OBJECT, attacker, 10);
        }


        /* init some stuff */
        attacker_name = attacker->query_name();
        if(!attacker_name) attacker_name = "Something";


        /* if we are faced with an opponent that is significantly stronger than ourselves.. 
         * Even higher level critters will run if their courage isnt high enough.
         */
        if(attacker->query_composite() &&
           attacker->query_composite() > arg->query_composite() * 2)
        {
            /* we want to check our bravery. If faced with a superior opponent we might wig out */
            if(arg->query_monster_attrib(ATTRIB_FEARLESSNESS)  < random(100) &&
               1 == random(3) &&
               attacker->query_attack() &&
               attacker->query_attack() == arg)
            {
                /* GTFO! */
                arg->report_message("Crap! " + attacker_name + " is way too strong for me... trying to run!!\n");
                arg->run_away();
                if(1 == random(3)) arg->run_away();
                return 1;
            }
            else
            {
                /* TODO: otherwise we calculate summon for help */
            }
        }
        

        /* if this is someone new attacking us */
        if(attacker != arg->query_obj(OBJ_TRAVEL_ATTACKER))
        {
            arg->report_message(BWHT + HIK + "I am being attacked by " + attacker_name + "!" + NORM + NORM + "\n");
            arg->set_obj(OBJ_TRAVEL_ATTACKER, attacker);

            /* register our contact to tacticalDM */
            register_combat_contact();

            /* reset our hunting and rounds counter */
            arg->set_count(COUNT_HUNTING_ROUNDS, 0);
            arg->set_count(COUNT_COMBAT_ROUNDS, 0);

            /* our chance of wimpy depends on fear */
            if(arg->query_monster_attrib(ATTRIB_FEARLESSNESS) < random(50) &&
               !arg->is(MODE_PILLAGING) &&
               hp < (mhp / 3))
            {
                if(1 == random(3))
                    arg->report_message("Trying to run away from " + attacker_name + "!\n");

                do_emote_panicked(arg);
                arg->run_away();
                if(1 == random(3)) arg->run_away();
            }
            else if (arg->query_chance_of(CHANCE_EMOTE_ATTACKED) > random(100))
                do_emote_attacked(arg);

            /* if we are being ballsy */
            else if(arg->query_chance_of(CHANCE_EMOTE_TAUNTING) > random(100))
                do_emote_taunting(arg);
        }

        /* this is the same person attacking us */
        else
        {
            /* increment our hunting threshold */
            arg->increment_count(COUNT_HUNTING_ROUNDS);

            /* and the total number of rounds we have fought */
            arg->increment_count(COUNT_COMBAT_ROUNDS);

            /* call our hit func, if it exists */
            arg->heartbeat_attack();

            /* if more than 2 people are attacking us, we need a new strategy */
            if(count_attackers(arg) > 10 && !arg->is(MODE_PILLAGING) && !arg->is(MODE_TO_THE_DEATH))
            {
                /* if we have less vindictiveness, we will do hit and fades by just the object */
                if(arg->query_monster_attrib(ATTRIB_VINDICTIVENESS) > random(100))
                    receive_orders(arg, ORDERS_HITFADE_NAME, attacker->query_real_name(), 15);
                else
                    receive_orders(arg, ORDERS_HITFADE_OBJECT, attacker, 10);

            }

            /* If we have been fighting this thing for 1000 rounds, it is unstoppable. We bail! */
            if(arg->query_count(COUNT_COMBAT_ROUNDS) > 1000)
            {
                arg->report_message("I have been fighting " + attacker_name + " for what seems like forever! Bailing out!\n");
                arg->run_away();
                receive_orders(arg, ORDERS_HOLD_POSITION, LOCKERS_ROOM, 5);
            }

            /* we throw fireworks at players. */
            if(arg->query_obj(OBJ_FIREWORKS) &&
               arg->is(MODE_FIREWORKS_THROWER) &&
               arg->query_chance(CHANCE_PELTING_THINGS) > random(100) &&
               attacker->query_invis() <= arg->query_level())
            {
                /* we don't hit invis players we cannot see */

                temp = arg->query_obj(OBJ_FIREWORKS);
                command("light fuse", arg);
                arg->remote_say(arg->query_name() + " gives a firecracker to " + attacker->query_name() + ".\n");
                move_object(temp, attacker);
                arg->set_obj(OBJ_FIREWORKS, 0);
                arg->do_recharge_fireworks();
            }

            /* if we have become angry enough and we have no orders.. we hunt this player */
            if(arg->query_count(COUNT_HUNTING_ROUNDS) >= arg->query_int(VAL_HUNTING_THRESHOLD) &&
               !arg->is(MODE_PILLAGING) &&
               !arg->is(MODE_TO_THE_DEATH) &&
               !arg->is(MODE_ON_ORDERS))
            {
                /* if we are truly vindictive we hunt anything named identical to attacker.
                 * otherwise we only hunt the given object.
                 */
                if(arg->query_monster_attrib(ATTRIB_VINDICTIVENESS) > random(100))
                    receive_orders(arg, ORDERS_HUNT_OBJECT, attacker, 5);
                else
                    receive_orders(arg, ORDERS_KILL_OBJECT, attacker, 60);

                /* clear our counter */
                arg->set_count(COUNT_HUNTING_ROUNDS, 0);
            }

            /* okay, if we are pillaging, and we are being attacked by a player, we wig out */
            if(arg->is(MODE_PILLAGING) &&
               attacker &&
               call_other(attacker, "is_player"))
            {
                if(arg->query_orders() == ORDERS_PILLAGECASTLE || arg->query_orders() == ORDERS_PILLAGELOITER)
                /* if we are in good shape */
                if(hp > mhp / 2)
                {
                    if(arg->query_monster_attrib(ATTRIB_VINDICTIVENESS) > random(100) &&
                       !arg->is(MODE_TO_THE_DEATH))
                        receive_orders(arg, ORDERS_HUNT_OBJECT, attacker, 5);
                    else
                        receive_orders(arg, ORDERS_KILL_OBJECT, attacker, 10);
                }
                /* else we are in bad shape, will run fades instead */
                else
                {
                    if(arg->query_monster_attrib(ATTRIB_VINDICTIVENESS) > random(100) &&
                       !arg->is(MODE_TO_THE_DEATH))
                        receive_orders(arg, ORDERS_HITFADE_NAME, attacker->query_real_name(), 30);
                    else
                        receive_orders(arg, ORDERS_HITFADE_OBJECT, attacker, 10);
                }

            }
        }
    }
    else
    {
        /* no attacker */

        /* if we have more than x gold, or every 2 hours...*/
        if(1 == random(5))
        if(arg->query_money() > arg->query_int(VAL_INFUSE_POINT) || 
           arg->query_count(COUNT_INFUSE_NEXUS) > 7200)
        {
            arg->do_infuse_nexus();
        }

        if(1 == random(2))
        {
        }

    }
    /* end attack routines */
}


do_corpse_management_routines(arg)
{
    object corpse;
    object room;

    if(!arg) return 0;

    room = environment(arg);
    if(!room) return 0;

    /* we only process one corpse at a time, per round */
    corpse = present("corpse", room);
    if(!corpse) return 0;
    
    /* loot corpses. Some monsters loot corpses. We only do it if visible however! */
    if(corpse)

    if(arg->is(MODE_PILLAGING) ||
       arg->query_chance_of(CHANCE_CORPSE_LOOTING) > random(100))

    {
        if(arg->is(MODE_CORPSE_EATER))
        {
            /* add it to our scoreboard */
            arg->increment_count(COUNT_CORPSES_LOOTED);

            /* taken from Boltar's hoth monster */
            tell_room(room, arg->query_name() + " takes "+ corpse->short() + "\n");
            tell_room(room, arg->query_name() + " consumes the corpse whole.\n");
            tell_room(room, arg->query_name() + " burps rudely.\n");
            move_object(corpse, arg);
            destruct(corpse);
        }
        else
        {
            /* add it to our scoreboard */
            arg->increment_count(COUNT_CORPSES_LOOTED);

            /* we just take the corpse but don't process it */
          if(corpse->short())
            arg->report_message(corpse->short() + " was looted.\n");
            tell_room(room, arg->query_name() + " takes corpse.\n");
            move_object(corpse, arg);

        }

    }

    /* done! */

}

do_emote_attacked(arg)
{
    string attacked_emotes;
    string attacked_mchannels;

    if(!arg) return;

    attacked_emotes = arg->query_attacked_emotes();
    attacked_mchannels = arg->query_attacked_mchannels();

    if(!attacked_emotes) return 0;

    if(environment(arg))
        tell_room(environment(arg), attacked_emotes[random(sizeof(attacked_emotes))]);

    if(!arg->is(MODE_RADIO_SILENCED) && attacked_mchannels && 1 == random(3)) 
        arg->report_message(attacked_mchannels[random(sizeof(attacked_mchannels))]);
}

do_emote_panicked(arg)
{
    string panicked_emotes;
    string panicked_mchannels;

    if(!arg) return;

    panicked_emotes = arg->query_panicked_emotes();
    panicked_mchannels = arg->query_panicked_mchannels();

    if(!panicked_emotes) return 0;

    if(environment(arg))
        tell_room(environment(arg), panicked_emotes[random(sizeof(panicked_emotes))]);

    if(!arg->is(MODE_RADIO_SILENCED) && panicked_mchannels) 
        arg->report_message(panicked_mchannels[random(sizeof(panicked_mchannels))]);
}


do_emote_taunting(arg)
{
    string taunting_emotes;
    string taunting_mchannels;

    if(!arg) return;

    taunting_emotes = arg->query_taunting_emotes();
    taunting_mchannels = arg->query_taunting_mchannels();
    
    if(!taunting_emotes) return 0;

    if(environment(arg))
        tell_room(environment(arg), taunting_emotes[random(sizeof(taunting_emotes))]);

    if(!arg->is(MODE_RADIO_SILENCED) && taunting_mchannels && 1 == random(3)) 
        arg->report_message(taunting_mchannels[random(sizeof(taunting_mchannels))]);
}


do_emote_hit_hard(arg)
{
    string hit_hard_emotes;
    string hit_hard_mchannels;

    if(!arg) return;

    hit_hard_emotes = arg->query_hit_hard_emotes();
    hit_hard_mchannels = arg->query_hit_hard_mchannels();

    if(!hit_hard_emotes) return 0;

    if(environment(arg))
        tell_room(environment(arg), hit_hard_emotes[random(sizeof(hit_hard_emotes))]);

    if(!arg->is(MODE_RADIO_SILENCED) && hit_hard_mchannels) 
        arg->report_message(hit_hard_mchannels[random(sizeof(hit_hard_mchannels))]);
}


do_emote_death(arg)
{
    string death_emotes;
    string death_mchannels;

    if(!arg) return;
    
    death_emotes = arg->query_death_emotes();
    death_mchannels = arg->query_death_mchannels();
    
    if(!death_emotes) return 0;

    if(environment(arg))
        tell_room(environment(arg), death_emotes[random(sizeof(death_emotes))]);

    if(!arg->is(MODE_RADIO_SILENCED) && death_mchannels) 
        arg->report_message(death_mchannels[random(sizeof(death_mchannels))]);
}


do_emote_triumph(arg)
{
    string triumph_emotes;
    string triumph_mchannels;

    if(!arg) return;

    triumph_emotes = arg->query_triumph_emotes();
    triumph_mchannels = arg->query_triumph_mchannels();

    if(!triumph_emotes) return 0;
    
    if(environment(arg))
        tell_room(environment(arg), triumph_emotes[random(sizeof(triumph_emotes))]);

    if(!arg->is(MODE_RADIO_SILENCED) && triumph_mchannels) 
        arg->report_message(triumph_mchannels[random(sizeof(triumph_mchannels))]);
}


do_emote_shit_throw(arg)
{
    string shit_throw_emotes;
    string shit_throw_mchannels;

    if(!arg) return;
    
    shit_throw_emotes = arg->query_shit_throw_emotes();
    shit_throw_mchannels = arg->query_shit_throw_mchannels();

    if(!shit_throw_emotes) return 0;

    if(environment(arg))
        tell_room(environment(arg), shit_throw_emotes[random(sizeof(shit_throw_emotes))]);

    if(!arg->is(MODE_RADIO_SILENCED) && shit_throw_mchannels && 1 == random(3)) 
        arg->report_message(shit_throw_mchannels[random(sizeof(shit_throw_mchannels))]);
}


do_emote_casual(arg)
{
    string casual_emotes;
    string casual_mchannels;

    if(!arg) return;

    casual_emotes = arg->query_casual_emotes();
    casual_mchannels = arg->query_casual_mchannels();

    if(!casual_emotes) return 0;

    if(environment(arg))
        tell_room(environment(arg), casual_emotes[random(sizeof(casual_emotes))]);

    if(!arg->is(MODE_RADIO_SILENCED) && casual_mchannels && 1 == random(3)) 
        arg->report_message(casual_mchannels[random(sizeof(casual_mchannels))]);
}


do_emote_balloon_throw(arg)
{
    string balloon_throw_emotes;
    string balloon_throw_mchannels;

    if(!arg) return;

    balloon_throw_emotes = arg->query_balloon_throw_emotes();
    balloon_throw_mchannels = arg->query_balloon_throw_mchannels();

    if(!balloon_throw_emotes) return 0;

    if(environment(arg))
        tell_room(environment(arg), balloon_throw_emotes[random(sizeof(balloon_throw_emotes))]);

    if(!arg->is(MODE_RADIO_SILENCED) && balloon_throw_mchannels && 1 == random(3)) 
        arg->report_message(balloon_throw_mchannels[random(sizeof(balloon_throw_mchannels))]);
}


do_emote_arrival(arg)
{
    string arrival_emotes;
    string arrival_mchannels;

    if(!arg) return;

    arrival_emotes = arg->query_arrival_emotes();
    arrival_mchannels = arg->query_arrival_mchannels();
    
    if(!arrival_emotes) return 0;

    if(environment(arg))
        tell_room(environment(arg), arrival_emotes[random(sizeof(arrival_emotes))]);

    if(!arg->is(MODE_RADIO_SILENCED) && arrival_mchannels) 
        arg->report_message(arrival_mchannels[random(sizeof(arrival_mchannels))]);
}


do_emote_scared(arg)
{
    string scared_emotes;
    string scared_mchannels;

    if(!arg) return;
    
    scared_emotes = arg->query_scared_emotes();
    scared_mchannels = arg->query_scared_mchannels();

    if(!scared_emotes) return 0;

    if(environment(arg))
        tell_room(environment(arg), scared_emotes[random(sizeof(scared_emotes))]);

    if(!arg->is(MODE_RADIO_SILENCED) && scared_mchannels) 
        arg->report_message(scared_mchannels[random(sizeof(scared_mchannels))]);
}


do_get_everything(arg)
{
    int count;
    int value;
    int corpses;
    object ob;
    object loot;
    object room;

    if(!arg) return;
    room = environment(arg);
    if(!room) return;

    ob = first_inventory(room);

    /* lootan corpsis, lootan drugs, lootan weapins, lootan beer, schmokin weed, dreenkin beer */
    while(ob)
    {
        loot = ob;
        ob = next_inventory(ob);

        /* make sure loot is valid */
        if(loot &&
           !living(loot) &&
           call_other(loot, "get") &&
           call_other(loot, "short") &&
           call_other(loot, "query_weight") &&
           call_other(loot, "query_weight") < 100)
        {

            /* we can pick this up */
            tell_room(room, loot->short() + " is taken by " + arg->query_name() + ".\n");
            move_object(loot, arg);

            count ++;
/* to prevent a hb error - ill 4 jan 2005 */ if(!loot) continue;
            value += loot->query_value();
            if(loot->id("corpse"))
            {
                corpses ++;

                /* add it to our scoreboard */
                arg->increment_count(COUNT_CORPSES_LOOTED);
            }

        }

    }

    /* if we looted anything we announce it */
    if(count && value) arg->report_message("I looted " + count + " objects worth " + value + " gold.\n");

    if(corpses == 1) arg->report_message("I looted a corpse!\n");
    else if(corpses > 1) arg->report_message("I looted " + corpses + " corpses!\n");

}

do_healing_routines(arg)
{
    int i;
    int hp;
    int mhp;
    int glevel;

    if(!arg) return 0;

    hp = arg->query_hp();
    mhp = arg->query_mhp();
    glevel = arg->query_monster_guild_level();

    /* if past our quota we do nothing here */
    if(arg->query_count(COUNT_HEALQUOTA_CUTOFF) || glevel <= 1)
        return 1;

    /* if we have a quota, and are past our quota we cannot heal either... */
    if(arg->query_int(VAL_MAX_HEAL_QUOTA) &&
       arg->query_count(COUNT_HEAL_QUOTA) > arg->query_int(VAL_MAX_HEAL_QUOTA))
    {
        arg->add_count(COUNT_HEALQUOTA_CUTOFF, 600);

        /* dependent on the monster's fearlessness they may stick around and fight to the death... */
        if(arg->query_monster_attrib(ATTRIB_FEARLESSNESS) > random(100))
        {
            if(1 == random(3))
                arg->report_message("I am out of heals, but will keep fighting!\n");
        }

        else
        {
            /* or run */
            /* tt 2009 jul - the monster tries to flee without teleport */

            arg->do_random_move();
            /*
            arg->report_message("Ack! I am past my healing quota! Retreating from lineup!\n");
            arg->do_infuse_nexus();
            receive_orders(arg, ORDERS_HOLD_POSITION, LOCKERS_ROOM, 10);
             */
            return 1;
        }
    }

    /* basically, level 1 creatures cannot heal themselves. */

    /* we heal ourselves */
     if(hp < 60 && mhp > 80 && glevel > 1 && 1 == random(3))
/* made this more fair... monsters sometimes dont cast heal as fast */
    {
        /* emergency heal */
        i = (mhp -  hp) / 2;
        request_healing(arg, i);
        arg->add_count(COUNT_HEAL_QUOTA, i);

    }
    else if(1 == random(3) && glevel > 1)
    {
        if(hp < (mhp / 2) || hp < 75)
        {
            /* we heal ourselves in 1/4 of our total hp bursts only */
            i = mhp / 4;
            if(i > (mhp - hp)) i = mhp - hp;

            request_healing(arg, i);
            /* we add up our quota */
            arg->add_count(COUNT_HEAL_QUOTA, i);
        }
    }

}


do_help_newbies(arg)
{
    object room;
    object ob;
    int i;
    int found_newbie;

    if(!arg) return 0;

    if(arg->query_money() < 7500) return 0;

    if(arg->query_count(COUNT_HELPED_NEWBIES) > 1) return 0;

    room = environment(arg);

    if(!room) return 0;

    ob = first_inventory(room);

    while(ob)
    {  
        if(ob && 
           living(ob) &&
           !found_newbie &&
           ob->is_player() &&
           ob->query_real_name() != "guest" &&
           query_ip_number(ob) != "12.217.93.241" &&
           ob->query_level() <= 5 &&
           ob->query_composite() < 140 &&
           ob != arg &&
           ob->query_money() < 5000) 
        {
            found_newbie = 1;

            /* help the newbie */
            tell_room(room, arg->query_name() + " examines " + ob->query_name() + " very carefully.\n");
            tell_object(ob, "You are carefully examined by the monster " + arg->query_name() + ".\n" );
            
            /* calc a good amount of money to give */
            i = random(arg->query_money());
            if(i > 10000) i = 10000;
            else if(i < 5000) i = 5000;


            arg->add_money(-i);
            ob->add_money(i);

            tell_room(room, arg->query_name() + " gives " + i + " coins to " + ob->query_name() + ".\n");
            tell_object(ob, HIW + "You have been given " + i + " coins by the monster " + arg->query_name() + "!\n" + NORM );

            tell_room(room, arg->query_name() + " smiles at " + ob->query_name() + ".\n");
            tell_object(ob, arg->query_name() + " smiles at you.\n" + NORM );
            
            

            arg->add_count(COUNT_HELPED_NEWBIES, 800);

            arg->report_message("I just gave the newbie " + ob->query_name() + " " + i + " coins.\n");

            break;
        }

        ob = next_inventory(ob);
    }

}


do_look(arg)
{
    object room;
    object ob;
    int i;

    if(!arg) return 0;

    room = environment(arg);
    if(!room) return 0;

    ob = first_inventory(room);

    tell_object(arg, "Location: " + room->short() + ".\nRoom contains:\n");

    while(ob)
    {
        if(ob->short() && ob != arg) tell_object(arg, ob->short() + ".\n");

        /* kinda crazy, i have to do checking here to prevent sporadic errors */
        if(ob) ob = next_inventory(ob);
        i++;
        if(i > 10)
        {
            tell_object(arg, "[TRUNCATED]\n");
            break;
        }
    }

    return 1;

}


do_orders_cover_object(arg)
{
}


do_orders_defend_spot(arg)
{
    object room;
    object victim;
    object att;
    object victim_room;
    object ob;
    string orders_objective_string;

    int found_target;

    if(!arg) return 0;
    
    orders_objective_string = arg->query_orders_objective_string();
    room = environment(arg);
    
    /* we are not in our objective room. We must get there. */
    if(!room) return;
    if(room != find_object(orders_objective_string))
    {
        teleport_me(arg, orders_objective_string);
        return 1;
    }

    att = arg->query_attack();

    /* we are in our objective room, and we are attacking something */
    if(att) victim_room = environment(att);
    if(victim_room  && room == victim_room)
    {
        /* we flex our strength */
        if(arg->query_chance_of(CHANCE_EMOTE_TAUNTING) > random(100))
            do_emote_taunting(arg);

        if(1 == random(3))
            arg->report_message(HIW + "Following orders to defend position " + describe_room(room) + "!" + NORM + "\n");

        return 1;
    }


    /* we must check our inventory and find something to attack if it is here */
    ob = first_inventory(room);
    found_target = 0;

    while(ob)
    {
        
        if(!found_target &&
            living(ob) &&
            ob->is_player() &&
            ob != arg)
        {
            tell_object(ob, "You have stumbled onto a very defensive " + arg->query_name() + ".\n");
            tell_room(room, arg->query_name() + " goes on the defensive!\n");
            arg->report_message(HIW + "Following orders to defend position " + describe_room(room) + "!" + NORM + "\n");
            
            clear_attacker_bits(ob);
            arg->attack_object(ob);
    
            arg->report_message("I have attacked " + ob->query_name() + "!!\n");

            /* woo! */
            if(arg->query_chance_of(CHANCE_EMOTE_TAUNTING) > random(100)) 
                do_emote_taunting(arg);

            found_target = 1;
            break;
        }
        
        ob = next_inventory(ob);
    }


}


do_orders_dismiss(arg)
{
    if(!arg) return ;

    /* take us away */
    teleport_me(arg, LOCKERS);

    /* do an infusion.. a final infusion  */
    arg->do_infuse_nexus(1);
    
    /* cleanup */
    arg->report_event(EVENT_DEPARTURE);

    destruct(arg);
}


do_orders_explode_object(arg)
{
    object room;
    object victimroom;
    object orders_objective_object;
    string victimroomrealm;

    if(!arg) return 0;

    orders_objective_object = arg->query_orders_objective_object();

    /* we check if our objective object has disappeared */
    if(arg->is(MODE_ON_ORDERS) && !orders_objective_object)
    {
        arg->report_message(HIW + "My victim has disappeared. My orders have been reset.\n" + NORM);
        arg->clear_orders_data();
        return 1;
    }

    room = environment(arg);
    victimroom = environment(orders_objective_object);
    if(victimroom) victimroomrealm = victimroom->realm();

    if(!victimroom) return 0;

    /* we are not in the same room as our victim. We must join them */
    if(room != victimroom)
    {
        /* check for terms, otherwise we must wait until they are in the clear... */
        if(!victimroom->query_fight_area() &&
           victimroomrealm != "NT")
        {
            teleport_me(arg, object_name(victimroom));
            tell_room(victimroom, arg->query_name() + " arrives menacing " + orders_objective_object->query_name() + ".\n");
            return 1;
        }
        else
        {
            /* we cannot teleport to player yet. Basically sit and twiddle. */
            return 1;
        }
    }

    /* now that we are in the same room we follow them for a brief period before the bomb goes off */
    if(1 == random (6))
    {
        string orders_objective_object_name; /* by verte */
        orders_objective_object_name = (string)orders_objective_object->query_name();
        do_emote_triumph(arg);
        arg->report_message("I am near " + orders_objective_object->query_name() + " and am detona^#(@*#U...\n");
        
        arg->attack_object(orders_objective_object);
        
        /* we do damage proportional to our level */
        orders_objective_object->hit_player(arg->query_level() * 3 * random(4));

        if(orders_objective_object)
        tell_object(orders_objective_object, arg->query_name() + " lunges at you, trying to get as close as possible!\n");

        /* pow! */
        tell_room(room, HIR);
        pow_asplode(room);
        tell_room(room, NORM);

        /* now we blow ourselves up */
        chan_msg("A terrifying explosion is felt coming from the vicinity of "+orders_objective_object_name+".\n");

        tell_room(room, arg->query_name() + " is blown to bits!\n\n");
        tell_room(room, "A crushing explosion of body parts and burning shrapnel go flying everywhere!\n");

        destruct_inventory();
        destruct(arg);
        return 1;
    }
    else
    {
        tell_room(room, "Tick...\n");
        return 1;
    }
    

    return 1;
}


do_orders_explode_spot(arg)
{
    object room;
    string orders_objective_string;

    if(!arg) return 0;

    orders_objective_string = arg->query_orders_objective_string();
    if(!orders_objective_string) return 0;
    room = environment(arg);
    
    /* we are not in our objective room. We must get there. */
    if(!room) return;

    if(room != find_object(orders_objective_string))
    {
        if(1 == random(2))
            teleport_me(arg, orders_objective_string);
        return 1;
    }

    /* now that we are in the same room we follow them for a brief period before the bomb goes off */
    if(1 == random(5))
    {
        do_emote_triumph(arg);
        arg->report_message("I am near " + room->short() + " and am detona^#(@*#U...\n");
        
        tell_room(room, arg->query_name() + " sets off an explosive charge.\n");

        /* pow! */
        tell_room(room, HIR);
        pow_asplode(room);
        tell_room(room, NORM);

        /* now we blow ourselves up */
        chan_msg("A terrifying explosion is felt coming from somewhere on the MUD...\n");

        tell_room(room, arg->query_name() + " is blown to bits!\n\n");
        tell_room(room, "A crushing explosion of body parts and burning shrapnel go flying everywhere!\n");

        arg->destruct_inventory();
        destruct(arg);
        return 1;
    }
    else
    {
        tell_room(room, "Tick...\n");
        return 1;
    }
    

}


do_orders_harrass_by_ip(arg)
{
    object room;
    object victimroom;
    object victim;
    object att;
    object ob;
    string victimroomrealm;
    string orders_objective_string;
    int i;
    int victim_found;

    if(!arg) return 0;

    att = arg->query_attack();
    room = environment(arg);
    orders_objective_string = arg->query_orders_objective_string();
    if(!orders_objective_string) return 0;

    /* we pull the first ip that matches, if any */
    ob = users();
    for(i = 0; i < sizeof(ob); i ++)
    {
        if(query_ip_number(ob[i]) == orders_objective_string && !victim_found)
        {
            victim = ob[i];
            victim_found = 1;
        }
    }

    /* if we dont have a victim, we just return */
    if(!victim)
    {
        if(arg->query_chance_of(CHANCE_EMOTE_CASUAL) > random(100))
            do_emote_casual(arg);

        return 1;
    }

    victimroom = environment(victim);
    if(victimroom) victimroomrealm = victimroom->realm();

    if(!victimroom) return 0;

    /* we are not in the same room as our victim. We must join them */
    if(room != victimroom)
    {
        /* check for terms, otherwise we must wait until they are in the clear... */
        if(!victimroom->query_fight_area() &&
           victimroomrealm != "NT")
        {
            teleport_me(arg, object_name(victimroom));
            tell_room(victimroom, arg->query_name() + 
                      " arrives stalking " + victim->query_name() + ".\n");

            /* we are returning here, to give a heartbeat pause... */
            return 1;
        }
        else
        {
            if(arg->query_chance_of(CHANCE_EMOTE_CASUAL) > random(100))
                arg->do_emote_casual();

            /* we cannot teleport to player yet. Basically sit and twiddle. */
            return 1;
        }
    }

    /* now that we are in the same room, we just harrass with SHIT! */
    if(arg->query_obj(OBJ_SHITPILE) && victim->query_level() < 20)
    {
        command("fling " + victim->query_real_name(), arg);
        arg->report_message("I harrassed " + victim->query_name() + " with a pile of shit.\n");
        do_emote_triumph(arg);

        arg->do_recharge_shit();
    }
    
    /* tell others in the room if it isnt patently obvious */
    if(1 == random(30))
        tell_room(victimroom, HIW + "(It appears that " + arg->query_name() + " is taunting " + victim->query_name() + ".)\n" + NORM);

    /* and of course we taunt, too. */
    if(arg->query_chance_of(CHANCE_EMOTE_TAUNTING) > random(100))
        do_emote_taunting(arg);

    /* if our target is attacking us, we need to change our orders accordingly */
    if(att && att == victim)
    {
        if(arg->query_fearlessness() > random(100))
            receive_orders(arg, ORDERS_HUNT_OBJECT, victim, 1);
        else
            receive_orders(arg, ORDERS_KILL_OBJECT, victim, 2);
    }
    

    return 1;
}


do_orders_harrass_by_name(arg)
{
    object room;
    object victimroom;
    object victim;
    object att;
    string victimroomrealm;
    string orders_objective_string;

    if(!arg) return 0;

    orders_objective_string = arg->query_orders_objective_string();

    if(!orders_objective_string) return 0;
    
    att = arg->query_attack();
    room = environment(arg);
    victim = find_player(orders_objective_string);

    /* if we dont have a victim, we just return */
    if(!victim)
    {
        if(arg->query_chance_of(CHANCE_EMOTE_CASUAL) > random(100))
            do_emote_casual(arg);

        return 1;
    }

    victimroom = environment(victim);
    if(victimroom) victimroomrealm = victimroom->realm();

    if(!victimroom) return 0;

    /* we are not in the same room as our victim. We must join them */
    if(room != victimroom)
    {
        /* check for terms, otherwise we must wait until they are in the clear... */
        if(!victimroom->query_fight_area() &&
           victimroomrealm != "NT")
        {
            teleport_me(object_name(victimroom));
            tell_room(victimroom, arg->query_name() + " arrives stalking " + victim->query_name() + ".\n");

            /* we are returning here, to give a heartbeat pause... */
            return 1;
        }
        else
        {
            if(arg->query_chance_of(CHANCE_EMOTE_CASUAL) > random(100))
                do_emote_casual(arg);

            /* we cannot teleport to player yet. Basically sit and twiddle. */
            return 1;
        }
    }

    /* now that we are in the same room, we just harrass with SHIT! */
    if(arg->query_obj(OBJ_SHITPILE) && victim->query_level() < 20)
    {
        command("fling " + orders_objective_string, arg);
        arg->report_message("I harrassed " + victim->query_name() + " with a pile of shit.\n");
        do_emote_triumph(arg);

        arg->do_recharge_shit();
    }
    
    /* tell others in the room if it isnt patently obvious */
    if(1 == random(30))
        tell_room(victimroom, HIW + "(It appears that " + arg->query_name() + " is taunting " + victim->query_name() + ".)\n" + NORM);

    /* and of course we taunt, too. */
    if(arg->query_chance_of(CHANCE_EMOTE_TAUNTING) > random(100))
        do_emote_taunting(arg);

    /* if our target is attacking us, we need to change our orders accordingly */
    if(att && att == arg->query_orders_objective_object())
    {
        if(arg->query_fearlessness() > random(100))
            receive_orders(arg, ORDERS_HUNT_OBJECT, arg->query_orders_objective_object(), 5);
        else
            receive_orders(arg, ORDERS_HITFADE_OBJECT, arg->orders_objective_object(), 15);
    }
    
    return 1;

}


do_orders_harrass_object(arg)
{
    object room;
    object victimroom;
    object att;
    object orders_objective_object;
    string victimroomrealm;

    if(!arg) return 0;

    orders_objective_object = arg->query_orders_objective_object();

    /* we check if our objective object has disappeared */
    if(arg->is(MODE_ON_ORDERS) && !orders_objective_object)
    {
        arg->report_message(HIW + "My victim has disappeared. My orders have been reset.\n" + NORM);
        arg->clear_orders_data();
        return 1;
    }

    att = arg->query_attack();
    room = environment(arg);
    victimroom = environment(orders_objective_object);
    if(victimroom) victimroomrealm = victimroom->realm();

    if(!victimroom) return 0;

    /* we are not in the same room as our victim. We must join them */
    if(room != victimroom)
    {
        /* check for terms, otherwise we must wait until they are in the clear... */
        if(!victimroom->query_fight_area() &&
           victimroomrealm != "NT")
        {
            teleport_me(arg, object_name(victimroom));
            tell_room(victimroom, arg->query_name() + " arrives stalking " + orders_objective_object->query_name() + ".\n");

            /* we are returning here, to give a heartbeat pause... */
            return 1;
        }
        else
        {
            /* we cannot teleport to player yet. Basically sit and twiddle. */
            return 1;
        }
    }

    /* now that we are in the same room, we just harrass with SHIT! */
    if(arg->query_obj(OBJ_SHITPILE) && orders_objective_object->query_level() < 20)
    {
        command("fling " + orders_objective_object->query_real_name(), arg);
        arg->report_message("I harrassed " + orders_objective_object->query_name() + " with a pile of shit.\n");
        do_emote_triumph(arg);

        arg->do_recharge_shit();
    }
    
    /* tell others in the room if it isnt patently obvious */
    if(1 == random(30))
        tell_room(victimroom, HIW + "(It appears that " + arg->query_name() + " is taunting " + orders_objective_object->query_name() + ".)\n" + NORM);

    /* and of course we taunt, too. */
    if(arg->query_chance_of(CHANCE_EMOTE_TAUNTING) > random(100))
        do_emote_taunting(arg);

    /* if our target is attacking us, we need to change our orders accordingly */
    if(att && att == orders_objective_object)
    {
        if(arg->query_fearlessness() > random(100))
            receive_orders(arg, ORDERS_HUNT_OBJECT, orders_objective_object, 10);
        else
            receive_orders(arg, ORDERS_HITFADE_OBJECT, orders_objective_object, 15);
    }
    

    return 1;
}


do_orders_heal_object(arg)
{
}


do_orders_hitfade_name(arg)
{
    object victim;
    object room;
    object victimroom;
    object att;
    int chance;
    int att_exp;
    int orders_objective_int;
    string victimroomrealm;
    string orders_objective_string;

    if(!arg) return 0;

    orders_objective_string = arg->query_orders_objective_string();
    if(!orders_objective_string) return 0;
    victim = find_player(orders_objective_string);

    if(!victim) return 1;

    /* init our exp */
    att_exp = victim->query_exp();
    room = environment(arg);
    victimroom = environment(victim);
    if(victimroom) victimroomrealm = victimroom->realm();

    /* if we are not in a room, bail... */
    if(!room || !victimroom) return 0;


    /* if our objective has less exp now, they must have died. we break off */
    if(victim->is_player() && 
       att_exp < arg->query_orders_objective_object_exp())
    {
        arg->report_message(HIW + "My objective object has DIED... bahaha!\n" + NORM);
        arg->clear_orders_data();
        do_emote_triumph(arg);
        do_get_everything(arg);

        /* send ourselves out of the way */
        teleport_me(arg, LOCKERS);
        
        /* TODO if we are vindictive, start hunting other members of the victim's guild */
        return 1;
    }
    
    /* set this */
    arg->set_orders_objective_object_exp(att_exp);

    /* depending on our mode, our actions will differ */
    /* We are using our orders_objective_int as a temp variable */
    if(orders_objective_int)
    {
        /* this means we are actively hunting */

        if(room != victimroom)
        {
            /* if we are not in the same room as our target... we join them */
            teleport_me(arg, object_name(victimroom));

            clear_attacker_bits(victim);
            arg->attack_object(victim);
        }

        /* our chance of teleport */
        if(arg->is(MODE_SLOW_HITFADES))
            chance = 30;
        else
            chance = 15;

        if(1 == random(chance))
        {
            /* we GTFO! */
            arg->report_message("Fading from attack! Going to safepoint...\n");
            teleport_me(arg, LOCKERS);
            arg->set_orders_objective_int(0);
            return 1;
        }
        return 1;
    }
    else
    {
        /* this means we are on fade... recovering */
        if(room != find_object(LOCKERS_ROOM))
        {
            /* if we are not in our safe location, we must go there */
            teleport_me(arg, LOCKERS);
            return 1;
        }
        else if(1 == random(30) &&
                victimroom &&
                !victimroom->query_no_fight() &&
                victimroomrealm != "NT")
        {
            /* we decide to run our fade */
            teleport_me(arg, object_name(victimroom));
            tell_object(victim, arg->query_name() + " is attacking you!\n");
            tell_room(victimroom, HIY + "A very spirited " + arg->query_name() + 
                      " begins attacking " + victim->query_name() + "!\n" + NORM);
            
            clear_attacker_bits(victim);
            arg->attack_object(victim);
            arg->set_orders_objective_int(1);
            arg->report_message("I am going to attack player named " + victim->query_name() +
                                ", coming out of a fade!\n");
            return 1;
        }
        else return 1;
            /* otherwise, we just chill out */
    }

    /* we go flexy */
    if(arg->query_chance_of(CHANCE_EMOTE_TAUNTING) > random(100))
        do_emote_taunting(arg);

}


/* the hit and fade attack occurs when we have fought a large number of
 * combat rounds or have discovered multiple players are fighting us.
 */
do_orders_hitfade_object(arg)
{
    object room;
    object victimroom;
    object orders_objective_object;
    object att;
    int chance;
    int att_exp;
    int orders_objective_int;
    string victimroomrealm;

    if(!arg) return 0;

    orders_objective_object = arg->query_orders_objective_object();
    orders_objective_int = arg->query_orders_objective_int();

    /* we check if our objective object has disappeared */
    if(arg->is(MODE_ON_ORDERS) && !orders_objective_object)
    {
        arg->report_message(HIW + "My objective object has disappeared. My orders have been reset.\n" + NORM);
        arg->clear_orders_data();
        return 1;
    }

    /* init our exp */
    att_exp = orders_objective_object->query_exp();
    room = environment(arg);
    victimroom = environment(orders_objective_object);
    if(victimroom) victimroomrealm = victimroom->realm();

    /* if we are not in a room, bail... */
    if(!room || !victimroom) return 0;

    /* if our objective has less exp now, they must have died. we break off */
    if(orders_objective_object->is_player() && 
       att_exp < arg->query_orders_objective_object_exp())
    {
        arg->report_message(HIW + "My objective object has DIED... bahaha!\n" + NORM);
        arg->clear_orders_data();
        do_emote_triumph(arg);
        do_get_everything(arg);

        /* send ourselves out of the way */
        teleport_me(arg, LOCKERS);
        return 1;
    }

    /* set this */
    arg->set_orders_objective_object_exp(att_exp);

    /* depending on our mode, our actions will differ */
    /* We are using our orders_objective_int as a temp variable */
    if(orders_objective_int)
    {
        /* this means we are actively hunting */

        if(room != victimroom)
        {
            /* if we are not in the same room as our target... we join them */
            teleport_me(arg, object_name(victimroom));
            clear_attacker_bits(orders_objective_object);
            arg->attack_object(orders_objective_object);
        }
        
        /* our chance of teleport */
        if(arg->is(MODE_SLOW_HITFADES))
            chance = 40;
        else
            chance = 20;

        if(1 == random(chance))
        {
            /* we GTFO! */
            arg->report_message("Fading from attack! Going to safepoint...\n");
            teleport_me(arg, LOCKERS);
            arg->set_orders_objective_int(0);
            return 1;
        }
        return 1;
    }
    else
    {
        /* this means we are on fade... recovering */
        if(room != find_object(LOCKERS_ROOM))
        {
            /* if we are not in our safe location, we must go there */
            teleport_me(arg, LOCKERS);
            return 1;
        }
        else if(1 == random(30) &&
                victimroom && 
                !victimroom->query_no_fight() &&
                victimroomrealm != "NT")
        {
            /* we decide to run our fade */
            teleport_me(arg, object_name(victimroom));
            arg->tell_object(orders_objective_object, arg->query_name() + " is attacking you!\n");
            
            tell_room(victimroom, HIY + "A very spirited " + arg->query_name() + 
                " begins attacking " + orders_objective_object->query_name() + "!\n" + NORM);
            
            clear_attacker_bits(orders_objective_object);
            arg->attack_object(orders_objective_object);
            arg->set_orders_objective_int(1);
            arg->report_message("I am going to attack " + orders_objective_object->query_name() + ", coming out of a fade!\n");
        }
        else return 1;
            /* otherwise, we just chill out */
    }

    /* we go flexy */
    if(arg->query_chance_of(CHANCE_EMOTE_TAUNTING) > random(100))
        do_emote_taunting(arg);

}


/* this one is easier to code */
do_orders_hold_position(arg)
{
    object room;
    string orders_objective_string;

    if(!arg) return;

    orders_objective_string = arg->query_orders_objective_string();
    if(!orders_objective_string) return 0;
    room = environment(arg);
    
    /* we are not in our objective room. We must get there. */
    if(!room) return;

    /* TODO: add code to check for room's existence and repeated failure resets orders */
    if(room != find_object(orders_objective_string))
    {
        if(1 == random(2))
            teleport_me(arg, orders_objective_string);
        return 1;
    }

    /* we chill */
    if(arg->query_chance_of(CHANCE_EMOTE_CASUAL) > random(100))
        do_emote_casual(arg);

    /*
    if(1 == random(50))
        arg->report_message(HIW + "Following orders to hold at " + describe_room(room) + "..." + NORM + "\n");
    */
}


/*
 * Hounding is similar to a hit and fade. The main difference is that the 'hit'
 * part tends to last a little longer, and that the monster waits until the
 * player has engaged in prior combat before running the 'hit' part.
 *
 */
do_orders_hound_object(arg)
{
    object room;
    object victimroom;
    object att;
    object attroom;
    object orders_objective_object;
    int att_exp;
    int orders_objective_int;
    string victimroomrealm;

    if(!arg) return 0;

    orders_objective_object = arg->query_orders_objective_object();
    orders_objective_int = arg->query_orders_objective_int();

    /* we check if our objective object has disappeared */
    if(arg->is(MODE_ON_ORDERS) && !orders_objective_object)
    {
        arg->report_message(HIW + "My objective object has disappeared. My orders have been reset.\n" + NORM);
        arg->clear_orders_data();
        return 1;
    }

    /* init our exp */
    att_exp = orders_objective_object->query_exp();
    room = environment(arg);
    victimroom = environment(orders_objective_object);
    if(victimroom) victimroomrealm = victimroom->realm();
    att = orders_objective_object->query_attack();
    if(att) attroom = environment(att);

    /* if we are not in a room, bail... */
    if(!room || !victimroom) return 0;

    /* if our objective has less exp now, they must have died. we break off */
    if(orders_objective_object->is_player() && 
       att_exp < arg->query_orders_objective_object_exp())
    {
        arg->report_message(HIW + "My objective object has DIED... bahaha!\n" + NORM);
        arg->clear_orders_data();
        do_emote_triumph(arg);
        do_get_everything(arg);

        /* send ourselves out of the way */
        teleport_me(arg, LOCKERS);
        return 1;
    }

    /* set this */
    arg->set_orders_objective_object_exp(att_exp);

    /* depending on our mode, our actions will differ */
    /* We are using our orders_objective_int as a temp variable */
    if(orders_objective_int)
    {
        /* this means we are actively hunting */

        if(room != victimroom)
        {
            /* if we are not in the same room as our target... we join them */
            teleport_me(arg, object_name(victimroom));
            clear_attacker_bits(orders_objective_object);
            arg->attack_object(orders_objective_object);
        }
        if(1 == random(12))
        {
            /* we GTFO! */
            arg->report_message("Fading from attack! Going to safepoint...\n");
            teleport_me(arg, LOCKERS);
            arg->set_orders_objective_int(0);
            return 1;
        }
        return 1;
    }
    else
    {
        /* this means we are on fade... recovering */
        if(room != find_object(LOCKERS_ROOM))
        {
            /* if we are not in our safe location, we must go there */
            teleport_me(arg, LOCKERS);
            return 1;
        }
        else if(1 == random(10) &&
                victimroom &&
                !victimroom->query_no_fight() &&
                victimroomrealm != "NT" &&
                att &&
                attroom == victimroom)
        {
            /* we decide to run our fade */
            teleport_me(arg, object_name(victimroom));
            arg->tell_object(orders_objective_object, arg->query_name() + " is attacking you!\n");

            tell_room(victimroom, HIY + "A very spirited " + arg->query_name() +
                      " begins attacking " + orders_objective_object->query_name() + "!\n" + NORM);

            clear_attacker_bits(orders_objective_object);
            arg->attack_object(orders_objective_object);
            
            arg->set_orders_objective_int(1);
            
            arg->report_message("I am going to attack " + orders_objective_object->query_name() + ", coming out of a fade!\n");
        }
        else return 1;
            /* otherwise, we just chill out */
    }

    /* we go flexy */
    if(arg->query_chance_of(CHANCE_EMOTE_TAUNTING) > random(100))
        do_emote_taunting(arg);

}


do_orders_hunt_object(arg)
{
    object att;
    object room;
    object victimroom;
    object orders_objective_object;
    int att_exp;
    int orders_objective_object_exp;
    string victimroomrealm;

    if(!arg) return 0;

    orders_objective_object_exp = arg->query_orders_objective_object_exp();
    orders_objective_object = arg->query_orders_objective_object();

    /* we check if our objective object has disappeared */
    if(arg->is(MODE_ON_ORDERS) && !orders_objective_object)
    {
        arg->report_message(HIW + "My objective object has disappeared. My orders have been reset.\n" + NORM);
        arg->clear_orders_data();
        return 1;
    }

    /* init our exp */
    att_exp = orders_objective_object->query_exp();
    room = environment(arg);
    victimroom = environment(orders_objective_object);
    if(victimroom) victimroomrealm = victimroom->realm();

    /* if we are not in a room, bail... */
    if(!room || !victimroom) return 0;


    /* if our objective has less exp now, they must have died. we break off */
    if(orders_objective_object->is_player() && 
       att_exp < orders_objective_object_exp)
    {
        arg->report_message(HIW + "My objective object has DIED... bahaha!\n" + NORM);
        arg->clear_orders_data();
        do_emote_triumph(arg);
        do_get_everything(arg);

        /* send ourselves out of the way */
        teleport_me(arg, LOCKERS);
        
        return 1;
    }
    
    /* set this */
    arg->set_orders_objective_object_exp(att_exp);

    /* we are not in our objective's room. We must get there. */
    if(room != victimroom)
    {
        /* check for realm nt only on players */
        if(orders_objective_object->is_player() && room->realm() == "NT")
            return 1;

        teleport_me(arg, object_name(victimroom));
        return 1;
    }

    att = arg->query_attack();

    if(!att)
    {
        /* if we aren't in a no-fight room, we can start combat */
        if(!room->query_no_fight())
        {
            tell_object(orders_objective_object, arg->query_name() + " is trying to hunt you down!\n");
            tell_room(room, HIR + "A very spirited " + arg->query_name() +
                      " begins attacking " + orders_objective_object->query_name() + "!\n" + NORM);
            clear_attacker_bits(orders_objective_object);
            arg->attack_object(orders_objective_object);
        }
        else
        {
            if(arg->query_chance_of(CHANCE_EMOTE_TAUNTING) > random(100))
                do_emote_taunting(arg);
            return 1;
        }
    }

    /* we go flexy */
    if(arg->query_chance_of(CHANCE_EMOTE_TAUNTING) > random(100))
        do_emote_taunting(arg);

}



/* similar to kill by name, just operates on guilds... */
do_orders_kill_by_guildname(arg)
{
    object room;
    object victim;
    object att;
    object victim_room;
    string orders_objective_string;

    if(!arg) return 0;

    /* remember that we are being given a string name to attack */
    att = arg->query_attack();
    orders_objective_string = arg->query_orders_objective_string();

    room = environment(arg);
    if(room)
    {
        victim = get_object_matching_guildname(orders_objective_string, room);
        /* if the victim is not alive, we bail. */
        if(!victim || !living(victim)) return 0;
        

        /* if we are already in combat, or the victim happens to be our attacker, we bail. */
        if(att || att == victim) return 0;

        victim_room = environment(victim);
        /* victim is in the same room as us */
        if(victim_room && room == victim_room)
        {
            /* if we aren't in a no-fight room, we can start combat */
            if(!room->query_no_fight())
            {
                tell_object(victim, arg->query_name() + " does not like your guild.\n");
                tell_room(room, arg->query_name() + " goes on the attack!\n");
                arg->report_message(HIW + "Following orders to kill '" + orders_objective_string + "' guild members!" + NORM + "\n");
            
                clear_attacker_bits(victim);
                arg->attack_object(victim);
                /* we are happy! */
                return 1;
            }
            else
            {
                if(arg->query_chance_of(CHANCE_EMOTE_TAUNTING) > random(100))
                    do_emote_taunting(arg);
                return 1;
            }


        }
        else return 0;
    }
    return 0;
}



/*
 * These orders don't normally finish either.
 *
 */
do_orders_kill_by_ipaddr(arg)
{
    object room;
    object victim;
    object att;
    object victim_room;
    string orders_objective_string;

    if(!arg) return 0;

    /* remember that we are being given a string ipaddress to attack */
    att = arg->query_attack();
    orders_objective_string = arg->query_orders_objective_string();

    room = environment(arg);
    if(room)
    {
        victim = get_object_matching_ipaddress(orders_objective_string, room);
        /* if the victim is not alive, we bail. */
        if(!victim || !living(victim)) return 0;
        

        /* if we are already in combat, or the victim happens to be our attacker, we bail. */
        if(att || att == victim) return 0;

        victim_room = environment(victim);
        /* victim is in the same room as us */
        if(victim_room && room == victim_room)
        {

            /* if we aren't in a no-fight room, we can start combat */
            if(!room->query_no_fight())
            {
                tell_room(room, arg->query_name() + " goes on the offensive!\n");
                arg->report_message(HIW + "Following orders to kill matching IP " + orders_objective_string + "!" + NORM + "\n");
                clear_attacker_bits(victim);
                arg->attack_object(victim);
                arg->report_message("I have attacked " + victim->query_name() + "!!\n");
                return 1;
            }
            else
            {
                if(arg->query_chance_of(CHANCE_EMOTE_TAUNTING) > random(100))
                    do_emote_taunting(arg);
                return 1;
            }
        }
        else return 0;
    }
    return 0;
}


/* we can be told to attack other objects
 *
 * Note that these orders do not ever 'finish'. The monster
 * will keep trying to kill objects named 'X' until it dies.
 *
 */
do_orders_kill_by_name(arg)
{
    object room;
    object victim;
    object att;
    object victim_room;
    string orders_objective_string;

    if(!arg) return 0;
    
    /* remember that we are being given a string name to attack */
    att = arg->query_attack();
    orders_objective_string = arg->query_orders_objective_string();

    room = environment(arg);
    if(room)
    {
        victim = present(orders_objective_string, room);
        /* if the victim is not alive, we bail. */
        if(!victim || !living(victim)) return 0;
        

        /* if we are already in combat, or the victim happens to be our attacker, we bail. */
        if(att || att == victim) return 0;

        victim_room = environment(victim);
        /* victim is in the same room as us */
        if(victim_room && room == victim_room)
        {
            /* if we aren't in a no-fight room, we can start combat */
            if(!room->query_no_fight())
            {

                tell_room(room, arg->query_name() + " goes on the attack!\n");
                arg->report_message(HIW + "Following orders to kill anything named " + orders_objective_string + "!" + NORM + "\n");
                clear_attacker_bits(victim);
                arg->attack_object(victim);
                arg->report_message("I have attacked " + victim->query_name() + "!!\n");
                return 1;
            }
            else
            {
                if(arg->query_chance_of(CHANCE_EMOTE_TAUNTING) > random(100))
                    do_emote_taunting(arg);
                return 1;
            }
        }
        else return 0;
    }
    return 0;
}


/* we are still wandering aimlessly, but targetting a specific object if we run into it */
do_orders_kill_object(arg)
{
    object room;
    object victimroom;
    object att;
    object orders_objective_object;

    if(!arg) return 0;

    orders_objective_object = arg->query_orders_objective_object();
    
    /* we check if our objective object has disappeared */
    if(arg->is(MODE_ON_ORDERS) && !orders_objective_object)
    {
        arg->report_message(HIW + "My objective object has disappeared. My orders have been reset.\n" + NORM);
        arg->clear_orders_data();
        return 1;
    }

    room = environment(arg);
    victimroom = environment(orders_objective_object);

    if(!room || !victimroom) return 0;

    att = arg->query_attack();

    if(room == victimroom && !att)
    {
        /* if we aren't in a no-fight room, we can start combat */
        if(!room->query_no_fight())
        {
            tell_object(orders_objective_object, HIR + arg->query_name() + " is trying to hunt you down!\n" + NORM);
            tell_room(room, HIR + "A very spirited " + arg->query_name() + " begins attacking " + 
                      orders_objective_object->query_name() + "!\n" + NORM);

            clear_attacker_bits(orders_objective_object);
            arg->attack_object(orders_objective_object);
        }
        else
        {
            if(arg->query_chance_of(CHANCE_EMOTE_TAUNTING) > random(100))
                do_emote_taunting(arg);
            return 1;
        }
    }

}


/* Similarly coded to holding position, just randomly we 
 * can walk away and around, but not too far. 
 */
do_orders_loiter(arg)
{
    object room;
    object obj_room;
    string orders_objective_string;

    if(!arg) return;

    orders_objective_string = arg->query_orders_objective_string();
    
    room = environment(arg);
    obj_room = find_object(orders_objective_string);

    /* we are not in our objective room. We must get there. */
    if(!room) return;
    
    if(1 == random(10) && room != find_object(orders_objective_string))
    {
        teleport_me(arg, orders_objective_string);
        return 1;
    }

    /* we chill */
    if(arg->query_chance_of(CHANCE_EMOTE_CASUAL) > random(100))
        do_emote_casual(arg);

    if(1 == random(50) && obj_room)
        arg->report_message(HIW + "Following orders to loiter near " + describe_room(obj_room) + "..." + NORM + "\n");
}


/* similar to harrass but we merely emote a LOT */
do_orders_pester(arg)
{
    object room;
    object victimroom;
    object att;
    object orders_objective_object;
    string victimroomrealm;

    if(!arg) return 0;

    orders_objective_object = arg->query_orders_objective_object();

    /* we check if our objective object has disappeared */
    if(arg->is(MODE_ON_ORDERS) && !orders_objective_object)
    {
        arg->report_message(HIW + "My victim has disappeared. My orders have been reset.\n" + NORM);
        arg->clear_orders_data();
        return 1;
    }

    att = arg->query_attack();
    room = environment(arg);
    victimroom = environment(orders_objective_object);
    if(victimroom) victimroomrealm = victimroom->realm();

    if(!victimroom) return 0;

    /* we are not in the same room as our victim. We must join them */
    if(room != victimroom)
    {
        /* check for terms, otherwise we must wait until they are in the clear... */
        if(!victimroom->query_fight_area() &&
           victimroomrealm != "NT")
        {
            teleport_me(arg, object_name(victimroom));

            /* we are returning here, to give a heartbeat pause... */
            return 1;
        }
        else
        {
            /* we cannot teleport to player yet. Basically sit and twiddle. */
            return 1;
        }
    }

    /* we don't do anything particularly harmful... just follow. */
   
    /* and of course we emote, too. */
    if(arg->query_chance_of(CHANCE_EMOTE_CASUAL) > random(100))
        do_emote_casual(arg);

    /* if our target is attacking us, we need to change our orders accordingly */
    if(att && att == orders_objective_object)
    {
        if(arg->query_fearlessness() > random(100))
            receive_orders(arg, ORDERS_HUNT_OBJECT, orders_objective_object, 10);
        else
            receive_orders(arg, ORDERS_HITFADE_OBJECT, orders_objective_object, 15);
    }
    
    return 1;
}


do_orders_pester_name(arg)
{
    object room;
    object victimroom;
    object victim;
    object att;
    string victimroomrealm;
    string orders_objective_string;

    if(!arg) return 0;

    orders_objective_string = arg->query_orders_objective_string();

    if(!orders_objective_string) return 0;
    
    att = arg->query_attack();
    room = environment(arg);
    victim = find_player(orders_objective_string);

    /* if we dont have a victim, we just return */
    if(!victim)
    {
        if(arg->query_chance_of(CHANCE_EMOTE_CASUAL) > random(100))
            do_emote_casual(arg);

        return 1;
    }

    victimroom = environment(victim);
    if(victimroom) victimroomrealm = victimroom->realm();

    if(!victimroom) return 0;

    /* we are not in the same room as our victim. We must join them */
    if(room != victimroom)
    {
        /* check for terms, otherwise we must wait until they are in the clear... */
        if(!victimroom->query_fight_area() &&
           victimroomrealm != "NT")
        {
            teleport_me(object_name(victimroom));

            /* we are returning here, to give a heartbeat pause... */
            return 1;
        }
        else
        {
            if(arg->query_chance_of(CHANCE_EMOTE_CASUAL) > random(100))
                do_emote_casual(arg);

            /* we cannot teleport to player yet. Basically sit and twiddle. */
            return 1;
        }
    }

    /* and of course we taunt, too. */
    if(arg->query_chance_of(CHANCE_EMOTE_CASUAL) > random(100))
        do_emote_casual(arg);

    /* if our target is attacking us, we need to change our orders accordingly */
    if(att && att == arg->query_orders_objective_object())
    {
        if(arg->query_fearlessness() > random(100))
            receive_orders(arg, ORDERS_HUNT_OBJECT, arg->query_orders_objective_object(), 5);
        else
            receive_orders(arg, ORDERS_HITFADE_OBJECT, arg->orders_objective_object(), 15);
    }
    
    return 1;

}


do_orders_pillagecastle(arg)
{
    object room;
    object att;
    object victim;
    object ob;
    object graffiti;
    object victim2;

    int is_victim_picked;
    string roomrealm;
    string orders_objective_string;


    if(!arg) return 0;

    orders_objective_string = arg->query_orders_objective_string();
    if(!orders_objective_string) return 0;
    att = arg->query_attack();
    room = environment(arg);
    if(room) roomrealm = room->realm();

    if(!room) return 0;

    /* check that the castle we are given is supported */
    if(!match_castle(orders_objective_string))
    {
        arg->report_message("I don't know the castle you have instructed me to pillage...\n");
        arg->clear_orders_data();
        return 0;
    }

    /* we need to see that we are in the same realm as creator designated */
    if(creator(room) != orders_objective_string)
    {
        /* take us there */
        if(1 == random(2))
            teleport_me(arg, get_castle_waypoint(orders_objective_string));
        else
            return 0;
    }

    /* we always loot corpses hard */
    do_corpse_management_routines(arg);

    /* if no graffiti is here, we make some */

    /* we dont do this in the mines usually */ 
        
    graffiti = present("graffiti", room);
    
    if(!graffiti &&
       creator(room) == orders_objective_string &&
       room == find_object(get_castle_waypoint(orders_objective_string)))
    {
        move_object(clone_object(GRAFFITI_RESIDUE), room);
        tell_room(room, "A green can of Krylon [tm] spray paint materializes into " +
                  arg->query_name() + "'s inventory.\n");

        tell_room(room, arg->query_name() + " sprays some graffiti on the ground.\n");
        tell_room(room, "A green can of Krylon [tm] spray disappears.\n");
        do_emote_triumph(arg);
    }


    /* otherwise we look for any monsters in this room... and start bashing */
    ob = first_inventory(room);
    while(ob)
    {
        if(1 == random(2) &&
           !att &&
           !is_victim_picked &&
           living(ob) && 
           !ob->fellow_monster() &&
           ob != arg &&
           !room->query_no_fight() &&
           creator(ob) == orders_objective_string)
        {
            /* this is a valid target */
            is_victim_picked = 1;
            victim = ob;
        }

        ob = next_inventory(ob);
    }

    /* if we have picked a victim, let's attack it */
    if(is_victim_picked)
    {
        if(arg->query_chance_of(CHANCE_EMOTE_TAUNTING) > random(100))
            do_emote_taunting(arg);

        tell_room(room, HIR + "A berserking " + arg->query_name() + " begins attacking " + victim->query_name() + "!\n" + NORM);

        clear_attacker_bits(victim);
        arg->attack_object(victim);
    }
    
    /* we loot like mad. if it isn't nailed down we take it. */
    if(1 == random(2))
        do_get_everything(arg);

    /* our chance of taunting is lowered in this case, to not spam channel */
    if(arg->query_chance_of(CHANCE_EMOTE_TAUNTING) > random(200))
        do_emote_taunting(arg);

    /* if someone is stealing our kill we attack them (dont change the order tho) */
    victim2 = check_player_stealing_kill(arg);
    if(victim2)
    {
        /* if the monster is vindictive they will do something evil */
        if(arg->query_monster_attrib(ATTRIB_VINDICTIVENESS) > random(100))
        {

            tell_room(room, "\n\n" + HIR + arg->query_name() + " says: Stealing my kill, " + victim2->query_name() + "?\n\n\n" + NORM);
            tell_room(room, HIR + "A berserking " + arg->query_name() + " begins attacking " + victim2->query_name() + "!\n" + NORM);

            clear_attacker_bits(victim2);
            arg->attack_object(victim2);
        }
        else
        {
            tell_room(room, "\n\n" + HIR + arg->query_name() + " says: Stealing my kill, " + victim2->query_name() + "?\n\n\n" + NORM);
            tell_room(room, HIR + victim2->query_name() + " is hit with a storm wind!\n" + NORM);
            victim2->run_away();
        }

    }

    return 1;
}


/*
 * We will pillage from a central location.
 *
 *
 */
do_orders_pillageloiter(arg)
{
    object room;
    object att;
    object victim;
    object ob;
    int is_victim_picked;
    string roomrealm;
    string orders_objective_string;
    string orders_objective_creator;

    if(!arg) return 0;

    att = arg->query_attack();

    /* we are fed a filename to pillage from */
    orders_objective_string = arg->query_orders_objective_string();
    if(!orders_objective_string) return 0;
    room = environment(arg);
    if(room) roomrealm = room->realm();
    orders_objective_creator = creator(room);

    if(!room) return 0;

    /* if we are not near our loiter point, randomly teleport us there. */    
    if(1 == random(15) && room != find_object(orders_objective_string))
    {
        teleport_me(arg, orders_objective_string);
        return 1;
    }

    /* we always loot corpses hard */
    do_corpse_management_routines(arg);
    
    /* otherwise we look for any monsters in this room... and start bashing */
    ob = first_inventory(room);

    /* it is important that we only attack things that have the same creator as the room */
    while(ob)
    {
        if(1 == random(2) &&
           !att &&
           !is_victim_picked &&
           living(ob) && 
           !ob->fellow_monster() &&
           ob != arg &&
           !room->query_no_fight() &&
           creator(ob) == orders_objective_creator)
        {
            /* this is a valid target */
            is_victim_picked = 1;
            victim = ob;
        }

        ob = next_inventory(ob);
    }

    /* if we have picked a victim, let's attack it */
    if(is_victim_picked)
    {
        if(arg->query_chance_of(CHANCE_EMOTE_TAUNTING) > random(100))
            do_emote_taunting(arg);

        tell_room(room, HIR + "A berserking " + arg->query_name() + " begins attacking " + victim->query_name() + "!\n" + NORM);

        clear_attacker_bits(victim);
        arg->attack_object(victim);
    }

    /* we loot like mad. if it isn't nailed down we take it. */
    if(1 == random(2))
        do_get_everything(arg);

    /* our chance of taunting is lowered in this case, to not spam channel */
    if(arg->query_chance_of(CHANCE_EMOTE_TAUNTING) > random(200))
        do_emote_taunting(arg);

    return 1;
}


/* we protect whatever is fighting our charge. We don't care what
 * the victim has gone through, how many times they have died, etc.
 * They have no business attacking our charge :)
 */
do_orders_protect_object(arg)
{
    object room;
    object orders_objective_object;
    object protectroom;
    object victimroom;
    object victim;
    object att;

    if(!arg) return 0;

    att = arg->query_attack();
    orders_objective_object = arg->query_orders_objective_object();

    /* we check if our objective object has disappeared */
    if(arg->is(MODE_ON_ORDERS) && !orders_objective_object)
    {
        arg->report_message(HIW + "My charge has disappeared. My orders have been altered.\n" + NORM);

        /* if we are attacking something, we should be allowed to continue to do so */
        if(att)
        {
            receive_orders(arg, ORDERS_HUNT_OBJECT, att, 5);
            return 1;
        }

        else
        {
            /* we have failed our mission! */

            /* todo: something more interesting here */
            arg->attack_object();
            arg->attack_object();
            arg->stop_fight();
            arg->stop_fight();
            arg->stop_hunter();
            arg->stop_hunter();
            receive_orders(arg, ORDERS_HOLD_POSITION, LOCKERS, 10);
        }

        return 1;
    }

    room = environment(arg);
    protectroom = environment(orders_objective_object);

    if(!protectroom) return 0;

    /* we are not in the same room as our charge. We must join them */
    if(room != protectroom)
    {
        /* teleport room checking is not in effect here */
        teleport_me(arg, object_name(protectroom));
        arg->tell_room(protectroom, arg->query_name() + " is following " +
                       orders_objective_object->query_name() + ".\n");
        return 1;
    }

    /* now that we are in the same room, check if anyone is fighting our charge */
    victim = orders_objective_object->query_attack();
    if(!victim)
    {
        if(arg->query_chance_of(CHANCE_EMOTE_CASUAL) > random(100))
            do_emote_casual(arg);

        return 1;
    }
    /* if so, we must fight that creature as well, irregardless of our personal safety */
    else
    {
        victimroom = environment(victim);

        /* they are fighting our charge? F'em! */
        /* WE ARE NOT CONCERNED ABOUT NO FIGHT AREA rooms */
        if(victimroom && 
           victimroom == protectroom &&
           victimroom == room)
        {
            clear_attacker_bits(victim);
            arg->attack_object(victim);
            tell_room(protectroom, arg->query_name() + " leaps in to defend " + orders_objective_object->query_name() + "!\n");
            do_emote_taunting(arg);
        }
    }
}


do_orders_stealkills_name(arg)
{
    object room;
    object victimroom;
    object att;
    object victim;
    object attroom;
    object orders_objective_string;
    int att_exp;
    int orders_objective_int;
    string victimroomrealm;

    if(!arg) return 0;

    orders_objective_string = arg->query_orders_objective_string();
    orders_objective_int = arg->query_orders_objective_int();
    victim = find_player(orders_objective_string);
    if(!victim) victim = find_living(orders_objective_string);

    /* we check if our objective object has disappeared */
    if(!victim)
    {
        /* No victim, we twiddle. */
        return 1;
    }

    /* init our exp */
    att_exp = victim->query_exp();
    room = environment(arg);
    victimroom = environment(victim);
    if(victimroom) victimroomrealm = victimroom->realm();
    att = victim->query_attack();
    if(att) attroom = environment(att);

    /* if we are not in a room, bail... */
    if(!room || !victimroom) return 0;


    /* depending on our mode, our actions will differ */
    /* We are using our orders_objective_int as a temp variable */
    if(orders_objective_int)
    {
        /* this means we are actively hunting */

        if(room != attroom)
        {
            /* if we are not in the same room as our target... we join them */
            teleport_me(arg, object_name(victimroom));

            if(att)
                arg->attack_object(att);
        }
        if(!att)
        {
            /* we GTFO! */
            arg->report_message("Fading from attack! Going to safepoint...\n");

            /* we always loot corpses hard */
            do_corpse_management_routines(arg);

            teleport_me(arg, LOCKERS);
            arg->set_orders_objective_int(0);
            return 1;
        }
        return 1;
    }
    else
    {
        /* this means we are on fade... recovering */
        if(room != find_object(LOCKERS_ROOM))
        {
            /* if we are not in our safe location, we must go there */
            teleport_me(arg, LOCKERS);
            return 1;
        }
        else if(1 == random(2) &&
                att &&
                att->query_hp() < 150 &&
                victimroom &&
                /* we don't check for this */
                /* victimroomrealm != "NT" && 
                !victimroom->query_no_fight() &&
                */
                attroom == victimroom)
        {
            /* we decide to run our fade */
            teleport_me(arg, object_name(victimroom));
            arg->tell_object(att, arg->query_name() + " is attacking you!\n");

            tell_room(victimroom, HIY + arg->query_name() +
                      " begins attacking " + att->query_name() + "!\n" + NORM);

            arg->attack_object(att);
            
            arg->set_orders_objective_int(1);
            
            arg->report_message("I am going to steal " + victim->query_name() + "'s kill, coming out of a fade!\n");

            /* we always loot corpses hard */
            do_corpse_management_routines(arg);
        }
        else return 1;
            /* otherwise, we just chill out */
    }

    /* note: if we are here it means we are engaged in combat */
   
    /* we go flexy */
    if(arg->query_chance_of(CHANCE_EMOTE_TAUNTING) > random(100))
        do_emote_taunting(arg);

    /* We play dirty, we deprive the victim the closing shots of their kill by wimpying.
     * I did this to defeat the players who run triggers */
    if(att &&
       att->query_hp() < 30 &&
       victim &&
       victimroom == attroom)
    {
        tell_room(attroom, HIY + arg->query_name() + " casts a spell of general preclusion!\n" + NORM);
        victim->run_away();
    }

    /* we always loot corpses hard */
    do_corpse_management_routines(arg);

}


/* structurally similar to hound... but attacks the creature our objective is fighting instead. */
do_orders_stealkills_object(arg)
{
    object room;
    object victimroom;
    object att;
    object attroom;
    object orders_objective_object;
    int att_exp;
    int orders_objective_int;
    string victimroomrealm;

    if(!arg) return 0;

    orders_objective_object = arg->query_orders_objective_object();
    orders_objective_int = arg->query_orders_objective_int();

    /* we check if our objective object has disappeared */
    if(arg->is(MODE_ON_ORDERS) && !orders_objective_object)
    {
        arg->report_message(HIW + "My objective object has disappeared. My orders have been reset.\n" + NORM);
        arg->clear_orders_data();
        return 1;
    }

    /* init our exp */
    att_exp = orders_objective_object->query_exp();
    room = environment(arg);
    victimroom = environment(orders_objective_object);
    if(victimroom) victimroomrealm = victimroom->realm();
    att = orders_objective_object->query_attack();
    if(att) attroom = environment(att);

    /* if we are not in a room, bail... */
    if(!room || !victimroom) return 0;


    /* set this */
    arg->set_orders_objective_object_exp(att_exp);

    /* depending on our mode, our actions will differ */
    /* We are using our orders_objective_int as a temp variable */
    if(orders_objective_int)
    {
        /* this means we are actively hunting */

        if(room != attroom)
        {
            /* if we are not in the same room as our target... we join them */
            teleport_me(arg, object_name(victimroom));

            if(att)
                arg->attack_object(att);
        }
        if(!att)
        {
            /* we GTFO! */
            arg->report_message("Fading from attack! Going to safepoint...\n");

            /* we always loot corpses hard */
            do_corpse_management_routines(arg);

            teleport_me(arg, LOCKERS);
            arg->set_orders_objective_int(0);
            return 1;
        }
        return 1;
    }
    else
    {
        /* this means we are on fade... recovering */
        if(room != find_object(LOCKERS_ROOM))
        {
            /* if we are not in our safe location, we must go there */
            teleport_me(arg, LOCKERS);
            return 1;
        }
        else if(1 == random(2) &&
                att &&
                att->query_hp() < 120 &&
                victimroom &&
                /* we don't check for this */
                /* victimroomrealm != "NT" && 
                !victimroom->query_no_fight() &&
                */
                attroom == victimroom)
        {
            /* we decide to run our fade */
            teleport_me(arg, object_name(victimroom));
            arg->tell_object(att, arg->query_name() + " is attacking you!\n");

            tell_room(victimroom, HIY + arg->query_name() +
                      " begins attacking " + att->query_name() + "!\n" + NORM);

            arg->attack_object(att);
            
            arg->set_orders_objective_int(1);
            
            arg->report_message("I am going to steal " + orders_objective_object->query_name() + "'s kill, coming out of a fade!\n");

            /* we always loot corpses hard */
            do_corpse_management_routines(arg);
        }
        else return 1;
            /* otherwise, we just chill out */
    }

    /* note: if we are here it means we are engaged in combat */
   
    /* we go flexy */
    if(arg->query_chance_of(CHANCE_EMOTE_TAUNTING) > random(100))
        do_emote_taunting(arg);

    /* We play dirty, we deprive the victim the closing shots of their kill by wimpying.
     * I did this to defeat the players who run triggers */
    if(att &&
       att->query_hp() < 30 &&
       orders_objective_object &&
       victimroom == attroom)
    {
        tell_room(attroom, HIY + arg->query_name() + " casts a spell of general preclusion!\n" + NORM);
        orders_objective_object->run_away();
    }

    /* we always loot corpses hard */
    do_corpse_management_routines(arg);

}

/**
 * This is the stuff that happens to annoy players. They can be pelted with
 * either water balloons or piles of shit. Only player killers get hit with
 * the shit piles.
 *
 *
 */
do_pelt_routines(arg)
{
    int hit_someone;
    object room;
    object ob;

    if(!arg) return;

    /* dunno why i have to put a this_object() but i get errors here without it */
    if(arg) room = environment(arg);

    /* if we are supposed to do it, pelt players with things */
    if(arg->is(MODE_BALLOON_THROWER) || arg->is(MODE_SHIT_THROWER))

    
    if(arg->query_chance_of(CHANCE_PELTING_THINGS) > random(250) &&
       room &&
       room!= find_object("room/post"))
    {
         ob = first_inventory(room);

         while(ob)
         {
             /* if living creature is right nearby, and we feel like it. */
             if(living(ob) &&
                1 == random(4) &&
                !hit_someone &&
                ob != arg &&
                !ob->fellow_monster())
             {
                 if(ob->query_level() > 19  && !ob->fellow_monster())
                 {
                     /* if a superior level creature is present, we get worried. */
                     if(arg->query_chance_of(CHANCE_EMOTE_SCARED) > random(100))
                     {
                         arg->report_message(ob->query_name() + " is present...\n");
                         do_emote_scared(arg);
                     }
                 }
                 else if(ob->query_level() < 6 && !arg->is(MODE_SPARING_NEWBIES))
                 {
                     /* otherwise we do our standard casual emotes */
                    if(arg->query_chance_of(CHANCE_EMOTE_CASUAL) > random(100))
                        do_emote_casual(arg);
                 }
                 else
                 {
                     /* we throw things at players. One at a time.*/
                     if(arg->query_obj(OBJ_SHITPILE) && 
                        arg->is(MODE_SHIT_THROWER) && 
                        !ob->fellow_monster() &&
                        ob->query_invis() <= arg->query_level())
                     {
                         if(ob->query_pl_k() || query_ip_number(ob) == "12.217.93.241")
                         {

                             command("fling " + ob->query_real_name(), arg);

                             arg->report_message("I hit " + ob->query_name() + " with a pile of shit.\n");
                             do_emote_shit_throw(arg);
                             arg->do_recharge_shit();
                             hit_someone = 1;
                         }
                     }
                     
                     /* we throw things at players. One at a time. */
                     if(!hit_someone &&
                        arg->query_obj(OBJ_BALLOON) &&
                        arg->is(MODE_BALLOON_THROWER) &&
                        !ob->fellow_monster() &&
                        ob->query_invis() <= arg->query_level() &&
                        room!= find_object("room/vill_green"))
                     {
                         /* we don't hit invis players we cannot see */
                         command("pelt " + ob->query_real_name(), arg);
                         arg->report_message("I pelted " + ob->query_name() + " with a water balloon.\n");

                         do_emote_balloon_throw(arg);
                         arg->do_recharge_balloon();
                         hit_someone = 1;

                     }
                 }
             }

           ob = next_inventory(ob);
        }
        hit_someone = 0;
    }
}


do_show_combat_monitor(arg)
{
    int hp;
    int mhp;
    int ahp;
    int amhp;
    object att;

    if(!arg) return 0;

    att = arg->query_attack();

    if(!att) return 0;

    hp = arg->query_hp();
    mhp = arg->query_mhp();

    ahp = att->query_hp();
    amhp = att->query_mhp();
    
    tell_object(arg, HIW + ">> " + arg->query_name() + ": " + (hp * 100) / mhp + "%HP, " +
                att->query_name() + ": " + (ahp * 100) / amhp + "%HP\n" + NORM);

    return 1;
}

/* we teleport one direction */
do_teleport_waypoint(arg)
{
    object room;
    object oldroom;
    string my_new_dest;

    if(!arg) return 0;

    if(!waypoints)
    {
        waypoints = ({
            "/room/church.c",
            "/room/lanceroad4.c",
            "/room/adv_guild.c",
            "/room/wild1.c",
            "/room/southroad1.c",
            "/room/eastroad1.c",
            "/room/vill_green.c",
            "/room/pub3.c",
        });
    }

    if(!waypoints_remote)
    {
        waypoints_remote = ({
            "/room/plane13.c",
            "/room/mount_top.c",
            "/room/tunnel6.c",
            "/room/forest11.c",
            "/room/south/sforst12.c",
            "/room/south/sforst19.c",
            "/room/south/sforst45.c",
            "/room/sunalley2.c",
        });
    }

    /* if we are a monster told to use remote waypoints, it means we are to avoid
     * highly populated areas. */
    if(arg->is(MODE_USE_REMOTE_WAYPOINTS))
        my_new_dest = waypoints_remote[random(sizeof(waypoints_remote))];
    else
        my_new_dest = waypoints[random(sizeof(waypoints))];

    room = find_object(my_new_dest);
    oldroom = environment(arg);
    
    /* if we cannot find our dest we try to load it, and return */
    if(!room)
    {
        catch(call_other("my_new_dest","???"));
        return 0;
    }


    arg->report_message("I am teleporting to " + describe_room(room) + ".\n");

    if(oldroom)
        tell_room(oldroom, arg->query_name() + " disappears in a puff of smoke.\n");
    
    move_object(arg, room);
    tell_room(room, arg->query_name() + " fades into view.\n");

    /* clear our motion counter */
    arg->set_count(COUNT_MOTION, 0);
    return 1;
}


/* we walk one step. */
do_walk(arg)
{
    object room,temproom;
    string exits,tempg,temph,tempi;
    int i, j;
    string my_cmd;

    if(!arg) return;

    if(!directions)
    {
        directions = ({
            "up",
            "down",
            "out",
            "east",
            "leave",
            "back",
            "exit",
            "west",
            "east",
            "north",
            "south",
            "northeast",
            "northwest",
            "southeast",
            "southwest",
            "in",
            "enter",
        });
    }

    /* we try to walk by using two ways... the sophisticated, and the stupid. 
     * the brute force way looks bad but it actually has a good purpose.
     *
     * When we are pillaging we want to use the smart way. Normally
     * we can use the stupid way, as it is more optimized to keep us from
     * getting caught up in rooty mazes.
     */

    room = environment(arg);
    exits = room->query_dest_dir();
   
    /* we must use the stupid way. */
    if(!exits || !arg->is(MODE_PILLAGING))
    {
        my_cmd = directions[random(sizeof(directions))]; 
        tell_object(arg, ">> Brute force/random command: '" + my_cmd + "'\n");
        command(my_cmd, arg);
        do_look(arg);
        return 1;
    }
   
    /* we need to determine if we are in the jello */
    temph = environment(this_player())->short();
   
    if(temph && sscanf(temph, "Plane of Etherie%s", tempi) == 1) 
    {
        /* we are inside the jello. The room system is a bit different here. */
        my_cmd = random(sizeof(exits));
        tell_object(arg, ">> Jello command: '" + exits[my_cmd] + "'\n");
        command(exits[my_cmd], arg);
        do_look(arg);
        return 1;
    } 
    else 
    {
        /* we are inside a room/room.c room. */
        i = 1;
        j = sizeof(exits);
        while(i < j) 
        {
            my_cmd = exits[i];
            if(1 == random(j)) break;
            i += 2;
        }

        tell_object(arg, ">> Standard room command: '" + my_cmd + "'\n");
            catch(command(my_cmd, arg));
        do_look(arg);
        return 1;
    }

}


follow_orders(arg, orders)
{
    if(!arg) return;

    /* we have followed our orders long enough. */
    if(arg->query_count(COUNT_ORDERS_TIME) >= (arg->query_orders_duration() * 60))
    {
        arg->report_message(HIW + "Orders expired. Objective time of " + arg->query_orders_duration() + " minutes completed.\n" + NORM);
        arg->clear_orders_data();
        return;
    }

    /* now we actually check our orders cycle */
    switch(orders)
    {
    case ORDERS_HARRASS_OBJECT:
        return do_orders_harrass_object(arg);
        break;

    case ORDERS_PROTECT_OBJECT:
        return do_orders_protect_object(arg);
        break; 

    case ORDERS_HUNT_OBJECT:
        return do_orders_hunt_object(arg);
        break;

    case ORDERS_KILL_OBJECT:
        return do_orders_kill_object(arg);
        break;
    
    case ORDERS_KILL_BY_NAME:
        return do_orders_kill_by_name(arg);
        break;
    
    case ORDERS_KILL_BY_IPADDR:
        return do_orders_kill_by_ipaddr(arg);
        break;
    
    case ORDERS_KILL_BY_GUILDNAME:
        return do_orders_kill_by_guildname(arg);
        break;
    
    case ORDERS_HOLD_POSITION:
        return do_orders_hold_position(arg);
        break;
    
    case ORDERS_DEFEND_SPOT:
        return do_orders_defend_spot(arg);
        break;
    
    case ORDERS_LOITER:
        return do_orders_loiter(arg);
        break;

    case ORDERS_HARRASS_NAME:
        return do_orders_harrass_by_name(arg);
        break;

    case ORDERS_HARRASS_IP:
        return do_orders_harrass_by_ip(arg);
        break;

    case ORDERS_HOUND_OBJECT:
        return do_orders_hound_object(arg);
        break;

    case ORDERS_HITFADE_OBJECT:
        return do_orders_hitfade_object(arg);
        break;

    case ORDERS_HITFADE_NAME:
        return do_orders_hitfade_name(arg);
        break;

    case ORDERS_EXPLODE_OBJECT:
        return do_orders_explode_object(arg);
        break;

    case ORDERS_EXPLODE_SPOT:
        return do_orders_explode_spot(arg);
        break;

    case ORDERS_PILLAGECASTLE:
        return do_orders_pillagecastle(arg);
        break;

    case ORDERS_PILLAGELOITER:
        return do_orders_pillageloiter(arg);
        break;
    
    case ORDERS_STEALKILLS_OBJECT:
        return do_orders_stealkills_object(arg);
        break;

    case ORDERS_STEALKILLS_NAME:
        return do_orders_stealkills_name(arg);
        break;

    case ORDERS_PESTER_NAME:
        return do_orders_pester_name(arg);
        break;

    case ORDERS_PESTER_OBJECT:
        return do_orders_pester(arg);
        break;

    case ORDERS_COVER_OBJECT:
        return do_orders_cover_object(arg);
        break;

    case ORDERS_HEAL_OBJECT:
        return do_orders_heal_object(arg);
        break;

    case ORDERS_DISMISS:
        return do_orders_dismiss(arg);
        break;

    default:
        arg->set_orders(0);
        break;
    }
}


/* used to find players matching guild name x */
get_object_matching_guildname(name, room)
{
    object ob;

    if(!room || !name) return 0;
    /* make sure we have a player to check */

    ob = first_inventory(room);
    while(ob)
    {
        if(ob->is_player() && ob->query_guild_name() == name)
            return ob;
        ob = next_inventory(ob);
    }

    return 0;

}

/* If we find something matching the ip address given to us in a room, we
 * return that object. Otherwise we return 0.
 */
get_object_matching_ipaddress(ipaddr, room)
{
    object ob;

    if(!room || !ipaddr) return 0;
    /* make sure we have an IP */

    ob = first_inventory(room);
    while(ob)
    {
        if(ob->is_player() && query_ip_number(ob) == ipaddr)
            return ob;
        ob = next_inventory(ob);
    }

    return 0;

}



get_heaviest_player_present(arg)
{
    object room;
    object ob;
    object result;
    int weight_value;
    int i;

    if(!arg) return 0;

    room = environment(arg);
    
    if(!room) return 0;

    /* now we loop */
    ob = first_inventory(room);

    while(ob)
    {
        if(living(ob) &&
           ob->is_player() &&
           ob != arg)
        {
            i = ob->query_phys_at(3);

            if(i > weight_value)
            {
                result = ob;
                weight_value = i;
            }
        }

        ob = next_inventory(ob);
    }


    if(result)
        return result;
    else
        return 0;
}


/* This merely tries to find the strongest player in the room. */
get_strongest_player_present(arg) 
{
    object room;
    object ob;
    object result;
    int composite_value;
    int i;

    if(!arg) return 0;

    room = environment(arg);
    
    if(!room) return 0;

    /* now we loop */
    ob = first_inventory(room);

    while(ob)
    {
        if(living(ob) &&
           ob->is_player() &&
           ob != arg)
        {
            i = ob->query_composite();

            if(i > composite_value)
            {
                result = ob;
                composite_value = i;
            }
        }

        ob = next_inventory(ob);
    }

/*
    if(find_player("mizan") && result)
        tell_object(find_player("mizan"), result->query_name() + " determined to be strongest.\n");
*/

    if(result)
        return result;
    else
        return 0;
}

get_weakest_player_present(arg) 
{
    object room;
    object ob;
    object result;
    int composite_value;
    int i;

    composite_value = 10000000;

    if(!arg) return 0;

    room = environment(arg);
    
    if(!room) return 0;

    /* now we loop */
    ob = first_inventory(room);

    while(ob)
    {
        if(living(ob) &&
           ob->is_player() &&
           ob != arg)
        {
            i = ob->query_composite();

            if(i < composite_value)
            {
                result = ob;
                composite_value = i;
            }
        }

        ob = next_inventory(ob);
    }

/*
    if(find_player("mizan") && result)
        tell_object(find_player("mizan"), result->query_name() + " determined to be weakest.\n");
 */

    if(result)
        return result;
    else
        return 0;
}

get_wealthiest_player_present(arg)
{
    object room;
    object ob;
    object result;
    int gold_value;
    int i;

    if(!arg) return 0;

    room = environment(arg);
    
    if(!room) return 0;

    /* now we loop */
    ob = first_inventory(room);

    while(ob)
    {
        if(living(ob) &&
           ob->is_player() &&
           ob != arg)
        {
            i = ob->query_money();

            if(i > gold_value)
            {
                result = ob;
                gold_value = i;
            }
        }

        ob = next_inventory(ob);
    }


/*
    if(find_player("mizan") && result)
        tell_object(find_player("mizan"), result->query_name() + " determined to be wealthiest.\n");
 */

    if(result)
        return result;
    else
        return 0;
}


pow_asplode(arg)
{
    object room;

    if(!arg)
        room = environment();
    else
        room = arg;

    if(!room) return;

    tell_room(room, "\nPPPPPPPP         OOOOOOOOOO      WWW                WWW     !!!  \n");
    tell_room(room, "PPPPPPPPPP      OOOOOOOOOOOO     WWW                WWW    !!!!! \n");
    tell_room(room, "PPP     PPP    OOOO      OOOO     WWW     WWWW     WWW     !!!!! \n");
    tell_room(room, "PPP     PPP    OOO        OOO     WWW    WWWWWW    WWW     !!!!! \n"); 
    tell_room(room, "PPPPPPPPPP     OOO        OOO      WWW  WWWWWWWW  WWW      !!!!! \n");
    tell_room(room, "PPPPPPPP       OOO        OOO      WWW  WWW  WWW  WWW       !!!  \n");
    tell_room(room, "PPP            OOOO      OOOO       WWWWWW    WWWWWW             \n");
    tell_room(room, "PPP             OOOOOOOOOOOO        WWWWW      WWWWW        !!!  \n");
    tell_room(room, "PPP              OOOOOOOOOO          WWW        WWW         !!!  \n\n");
}


/* used to generate strings describing attributes in the 100 scale.
 * For example, return "Totally zero" + " ruthlessness"... etc.
 */
quantify_attribute(arg)
{
    if(!arg) return "Zero";

    switch(arg)
    {
    case 1..10:
        return "Microscopic";
        break;
    case 11..20:
        return "Very small amounts of";
        break;
    case 21..30:
        return "Somewhat";
        break;
    case 31..40:
        return "A decent amount";
        break;
    case 41..50:
        return "A fair portion";
        break;
    case 51..60:
        return "Greater portions of";
        break;
    case 61..70:
        return "High amounts of";
        break;
    case 71..80:
        return "Incredible amounts of";
        break;
    case 81..90:
        return "Extraordinary amounts of";
        break;
    case 91..99:
        return "VERY exceptionally high";
        break;
    default:
        return "Absolutely - 100%";
        break;
    }
}


/* meant to be called internally. The argument given are the orders we
 * have been passed along.
 */


receive_orders(arg, code, data, duration)
{
    object room;

    if(!arg) return 0;

    /* we need to check our data. Check objects first. */
    if(code > ORDER_OBJECT_START &&
       code < ORDER_OBJECT_END)
    {
        /* object does not exist */
        if(!data || !environment(data))
        {
            arg->report_message("Huh? My target objective does not exist...\n");
            return 0;
        }

        /* object cannot be ourselves */
        else if(data == arg)
        {
            arg->report_message("What? I can't be ordered to do that on myself!\n");
            return 0;
        }
        
        /* now see if the orders are harmful ones, and check. */
        if(code > ORDER_HARM_OBJECT_START &&
           code < ORDER_HARM_OBJECT_END)
        {    
            if(data->query_level() > 1000 && data->is_player())
            {
                arg->report_message("What? Are you Nucking FUTS!?!?\n");
                return 0;
            }
            /* check to see if it does damage */
            else if(data->fellow_monster())
            {
                arg->report_message("Uh... i cannot be ordered to harm a fellow monster.\n");
                return 0;
            }
        }

    }


    /* once we are given orders, we take them. No questions asked. */
    arg->set_orders_achieved(0);
    arg->set_orders(code);
    arg->toggle_on(MODE_ON_ORDERS);
    arg->set_count(COUNT_ORDERS_TIME, 0);
    arg->set_to_the_death(0);
    arg->toggle_off(MODE_STOP_MOVING);
    arg->toggle_off(MODE_PILLAGING);

    /* if we are given 0 as duration, make it 'forever'. */
/*
    if(!duration || duration > 0)
        arg->set_orders_duration(1000);
    else
        arg->set_orders_duration(duration);
*/
    arg->set_orders_duration(duration);


    /* now send things out */
    switch(code)
    {

    case ORDERS_HARRASS_OBJECT:
        arg->set_orders_objective_object(data);
        arg->report_message("I am ordered to harrass " + data->query_name() + "!\n");
        if(arg->query_chance_of(CHANCE_EMOTE_TRIUMPH) > random(100)) 
            do_emote_triumph(arg);

        report_orders_duration(arg);
        break;

    case ORDERS_PROTECT_OBJECT:
        arg->set_to_the_death(1);
        arg->toggle_on(MODE_STOP_MOVING);
        arg->set_orders_objective_object(data);

        arg->report_message("I am ordered to protect " + data->query_name() + "!\n");
        
        if(arg->query_chance_of(CHANCE_EMOTE_TRIUMPH) > random(100)) 
            do_emote_triumph(arg);

        report_orders_duration(arg);
        break;

    case ORDERS_HUNT_OBJECT:
        arg->set_orders_objective_object(data);
        arg->report_message("I am ordered to hunt and kill " + data->query_name() + "!\n");
        
        if(arg->query_chance_of(CHANCE_EMOTE_TRIUMPH) > random(100))
            do_emote_triumph(arg);

        report_orders_duration(arg);
        break;

    case ORDERS_KILL_OBJECT:
        arg->set_orders_objective_object(data);
        arg->report_message("I am ordered to kill " + data->query_name() + "!\n");
        
        if(arg->query_chance_of(CHANCE_EMOTE_TRIUMPH) > random(100))
            do_emote_triumph(arg);

        report_orders_duration(arg);
        break;
    
    case ORDERS_KILL_BY_NAME:
        arg->set_orders_objective_object(data);
        arg->report_message("I am ordered to kill anything named '" + data + "'\n");
        report_orders_duration(arg);
        break;

    case ORDERS_KILL_BY_IPADDR:
        arg->set_orders_objective_string(data);
        arg->report_message("I am ordered to kill anything originating from '" + data + "'\n");
        report_orders_duration(arg);
        break;

    case ORDERS_KILL_BY_GUILDNAME:
        arg->set_orders_objective_string(data);
        arg->report_message("I am ordered to kill any '" + data + "' guild members.\n");
        report_orders_duration(arg);
        break;

    case ORDERS_HOLD_POSITION:
        room = find_object(data);
        arg->set_orders_objective_string(data);
        arg->toggle_on(MODE_STOP_MOVING);
        arg->report_message("I am ordered to hold position in " + describe_room(room) + ".\n");

        report_orders_duration(arg);
        break;
    
    case ORDERS_DEFEND_SPOT:
        arg->set_orders_objective_string(data);
        arg->set_to_the_death(1);
        arg->toggle_on(MODE_STOP_MOVING);

        room = find_object(data);
        arg->report_message("I am ordered to hold position in " + describe_room(room) + ".\n");

        /* we are happy to get this order */
        if(arg->query_chance_of(CHANCE_EMOTE_TRIUMPH) > random(100))
            do_emote_triumph(arg);
        report_orders_duration(arg);
        break;

    case ORDERS_LOITER:
        arg->set_orders_objective_string(data);

        room = find_object(data);
        arg->report_message("I am ordered to loiter around " + describe_room(room) + ".\n");
        report_orders_duration(arg);
        break;
    
    case ORDERS_HARRASS_NAME:
        arg->set_orders_objective_string(data);
        arg->toggle_on(MODE_STOP_MOVING);
        arg->report_message("I am ordered to harrass any player named '" + data + "'.\n");
        report_orders_duration(arg);
        break;

    case ORDERS_HARRASS_IP:
        arg->set_orders_objective_string(data);
        arg->toggle_on(MODE_STOP_MOVING);
        arg->report_message("I am ordered to harrass any player originating from '" + data + "'.\n");
        report_orders_duration(arg);
        break;

    case ORDERS_HOUND_OBJECT:
        arg->set_orders_objective_object(data);
        arg->toggle_on(MODE_STOP_MOVING);
        arg->report_message("I am ordered to hound and shadow kill " + data->query_name() + "!\n");
        if(arg->query_chance_of(CHANCE_EMOTE_TRIUMPH) > random(100))
            do_emote_triumph(arg);

        report_orders_duration(arg);
        break;

    case ORDERS_HITFADE_OBJECT:
        arg->set_orders_objective_object(data);
        arg->report_message("I am ordered to hit and fade attack " + data->query_name() + "!\n");
        
        if(arg->query_chance_of(CHANCE_EMOTE_TRIUMPH) > random(100))
            do_emote_triumph(arg);

        report_orders_duration(arg);
        break;

    case ORDERS_HITFADE_NAME:
        arg->set_orders_objective_string(data);

        arg->report_message("I am ordered to persistently hit and fade attack '" + data + "'.\n");
        report_orders_duration(arg);
        break;

    case ORDERS_EXPLODE_OBJECT:
        arg->set_orders_objective_object(data);
        arg->toggle_on(MODE_STOP_MOVING);
        
        arg->report_message("I am ordered to detonate myself as close to " + data->query_name() + " as possible!\n");
        arg->report_message("I understand that this is my final order. Over and out.\n");
        
        if(arg->query_chance_of(CHANCE_EMOTE_TRIUMPH) > random(100))
            do_emote_triumph(arg);
        break;

    case ORDERS_EXPLODE_SPOT:
        room = find_object(data);
        arg->set_orders_objective_string(data);
        arg->toggle_on(MODE_STOP_MOVING);

        arg->report_message("I am ordered to detonate myself in " + describe_room(room) + ".\n");
        arg->report_message("I understand that this is my final order. Over and out.\n");

        if(arg->query_chance_of(CHANCE_EMOTE_TRIUMPH) > random(100))
            do_emote_triumph(arg);
        break;

    case ORDERS_PILLAGECASTLE:
        arg->set_orders_objective_string(data);
        arg->toggle_on(MODE_PILLAGING);
        arg->report_message("I am ordered to pillage the castle created by " + capitalize(data) + ". Yes!\n");
        report_orders_duration(arg);
        break;

    case ORDERS_PILLAGELOITER:
        room = find_object(data);
        arg->set_orders_objective_string(data);
        arg->toggle_on(MODE_PILLAGING);
        arg->report_message("I am ordered to loiter and pillage the position " + describe_room(room) + ".\n");
        report_orders_duration(arg);
        break;

    case ORDERS_STEALKILLS_OBJECT:
        arg->set_orders_objective_object(data);
        arg->toggle_on(MODE_STOP_MOVING);
        arg->report_message("I am ordered to trace and steal kills from " + data->query_name() + "!\n");
        if(arg->query_chance_of(CHANCE_EMOTE_TRIUMPH) > random(100))
            do_emote_triumph(arg);

        report_orders_duration(arg);
        break;

    case ORDERS_STEALKILLS_NAME:
        arg->set_orders_objective_string(data);
        arg->toggle_on(MODE_STOP_MOVING);
        arg->report_message("I am ordered to trace and steal kills from anything named " + data + "!\n");
        if(arg->query_chance_of(CHANCE_EMOTE_TRIUMPH) > random(100))
            do_emote_triumph(arg);

        report_orders_duration(arg);
        break;

    
    case ORDERS_PESTER_NAME:
        arg->set_orders_objective_string(data);
        arg->toggle_on(MODE_STOP_MOVING);
        arg->report_message("I am ordered to pester anything named " + data + "!\n");
        if(arg->query_chance_of(CHANCE_EMOTE_TRIUMPH) > random(100))
            do_emote_triumph(arg);

        report_orders_duration(arg);
        break;

    
    case ORDERS_PESTER_OBJECT:
        arg->set_orders_objective_object(data);
        arg->toggle_on(MODE_STOP_MOVING);
        arg->report_message("I am ordered to pester " + data->query_name() + "!\n");
        if(arg->query_chance_of(CHANCE_EMOTE_TRIUMPH) > random(100))
            do_emote_triumph(arg);

        report_orders_duration(arg);
        break;


    case ORDERS_COVER_OBJECT:
        arg->set_orders_objective_object(data);
        arg->toggle_on(MODE_STOP_MOVING);
        arg->report_message("I am ordered to cover " + data->query_name() + "!\n");
        if(arg->query_chance_of(CHANCE_EMOTE_TRIUMPH) > random(100))
            do_emote_triumph(arg);

        report_orders_duration(arg);
        break;


    case ORDERS_HEAL_OBJECT:
        arg->set_orders_objective_object(data);
        arg->toggle_on(MODE_STOP_MOVING);
        arg->report_message("I am ordered to persistently heal " + data->query_name() + "!\n");
        if(arg->query_chance_of(CHANCE_EMOTE_TRIUMPH) > random(100))
            do_emote_triumph(arg);

        report_orders_duration(arg);
        break;
    

    case ORDERS_DISMISS:
        arg->report_message("I have been dismissed. Laters all!\n");
        break;

    default:
        arg->report_message("What do you want? I don't understand the order!\n");
        return 0;
        break;
    }
}



receive_task(arg, code, data)
{
}


/* This is a little function that merely tells on channels how long we will be following
 * our orders for.
 */
report_orders_duration(arg)
{
    int duration;
    object room;

    if(!arg) return;
    
    room = environment(arg);
    duration = arg->query_orders_duration();
    
    if(room) 
        tell_room(room, arg->query_name() + " has received new operating orders.\n");


    if(duration == 0)
        arg->report_message("Following orders for infinite period.\n");
    else
        arg->report_message("Following orders for " + duration + " minutes.\n");

}


/* We report our status to the system. */
report_status(arg)
{
    object att;
    object orders_objective_object;
    string verb;
    string noun;
    string result;
    string orders_objective_string;
    int orders_objective_int;

    if(!arg) return 0;

    orders_objective_object = arg->query_orders_objective_object();
    orders_objective_string = arg->query_orders_objective_string();
    orders_objective_int = arg->query_orders_objective_int();

    switch(arg->query_orders())
    {
    case ORDERS_HARRASS_OBJECT:
        verb = "harrassing";
        noun = call_other(orders_objective_object, "query_name");
        break;
    
    case ORDERS_PROTECT_OBJECT:
        verb = "protecting";
        noun = call_other(orders_objective_object, "query_name");
        break;
    
    case ORDERS_HUNT_OBJECT:
        verb = "hunting";
        noun = call_other(orders_objective_object, "query_name");
        break;
    
    case ORDERS_KILL_OBJECT:
        verb = "killing";
        noun = call_other(orders_objective_object, "query_name");
        break;
    
    case ORDERS_KILL_BY_NAME:
        noun = "'" + orders_objective_string + "'";
        verb = "killing anything named";
        break;
    
    case ORDERS_KILL_BY_IPADDR:
        noun = orders_objective_string;
        verb = "killing by IP address matching";
        break;
    
    case ORDERS_KILL_BY_GUILDNAME:
        noun = "'" + orders_objective_string + "'";
        verb = "killing members of the guild";
        break;
    
    case ORDERS_HOLD_POSITION:
        noun = describe_room(find_object(orders_objective_string));
        verb = "holding position at";
        break;

    case ORDERS_DEFEND_SPOT:
        noun = describe_room(find_object(orders_objective_string));
        verb = "defending spot at";
        break;

    case ORDERS_LOITER:
        noun = describe_room(find_object(orders_objective_string));
        verb = "loitering near";
        break;

    case ORDERS_HARRASS_NAME:
        noun = "'" + orders_objective_string + "'";
        verb = "harrassing a player matching";
        break;

    case ORDERS_HOUND_OBJECT:
        verb = "hounding and shadowing";
        noun = call_other(orders_objective_object, "query_name");
        break;

    case ORDERS_HITFADE_OBJECT:
        verb = "running hit and fade attacks on";
        noun = call_other(orders_objective_object, "query_name");
        break;

    case ORDERS_EXPLODE_OBJECT:
        verb = "detonating myself as close as possible to";
        noun = call_other(orders_objective_object, "query_name");
        break;

    case ORDERS_EXPLODE_SPOT:
        noun = describe_room(find_object(orders_objective_string));
        verb = "detonating myself at";
        break;

    case ORDERS_PILLAGECASTLE:
        noun = capitalize(orders_objective_string);
        verb = "pillaging and looting the castle of";
        break;

    case ORDERS_PILLAGELOITER:
        noun = describe_room(find_object(orders_objective_string));
        verb = "pillaging from loiter point at";
        break;

    case ORDERS_STEALKILLS_OBJECT:
        noun = call_other(orders_objective_object, "query_name");
        verb = "stealing kills from";
        break;

    case ORDERS_STEALKILLS_NAME:
        noun = capitalize(orders_objective_string);
        verb = "stealing kills from anything named";
        break;

    case ORDERS_PESTER_NAME:
        noun = capitalize(orders_objective_string);
        verb = "pestering anything named";
        break;

    case ORDERS_PESTER_OBJECT:
        noun = call_other(orders_objective_object, "query_name");
        verb = "pestering";
        break;

    case ORDERS_COVER_OBJECT:
        noun = call_other(orders_objective_object, "query_name");
        verb = "covering";
        break;

    case ORDERS_HEAL_OBJECT:
        noun = call_other(orders_objective_object, "query_name");
        verb = "instructed to heal";
        break;

    default:
        noun = "doing absolutely nothing,";
        verb = "just wandering around...";
        break;
    }

    result = "I am currently " + verb + " " + noun + ".\n";
    arg->report_message(result);

    att = arg->query_attack();
    /* report if we are being attacked */
    if(att)
    {
        result = "I am also in combat with '" + att->query_name() + 
            "' and it has " + (att->query_hp() * 100) / att->query_mhp() + "% health.\n"; 
        arg->report_message(result);
    }

    return 1;
}


/* takes us somewhere on the mud */
teleport_me(arg, dest)
{
    object room;
    object current_room;
    string temp;
    string travel_previous_roomname;

    if(!arg) return 0;

    /* if we are pillaging we dont want to teleport unless not fighting */
    if(arg->is(MODE_PILLAGING) && arg->query_attack())
    {
        /* we give the monster time to finish the job if in pillage */
        if(14 >= random(15)) return 1;
    }

    travel_previous_roomname = arg->query_string(STR_TRAVEL_PREVIOUS_ROOMNAME);

    /* the purpose of this slice is to see if we have been issued the command to
     * teleport here before. More than once, yarr.
     */
    if(!travel_previous_roomname || travel_previous_roomname != dest)
        /* since we are going somewhere different, we reset our counter. */
        arg->set_count(COUNT_TRAVEL_FUTILITY, 0);

    else if(travel_previous_roomname == dest)
        /* but we keep finding ourselves in this room... */
        arg->increment_count(COUNT_TRAVEL_FUTILITY);

    /* if we have been banging our heads against this room for some time, we need
     * to take a check and figure out wtf is wrong.
     */
    if(arg->query_count(COUNT_TRAVEL_FUTILITY) > 8 && arg->query_count(COUNT_JUNK_FLAP) <= 1)
    {
        /* we are hiding somewhere - the time and space hotel */
        if(sscanf(dest, "players/boltar/hotel%s", temp) == 1)
        {
            if(!arg->query(COUNT_JUNK_FLAP))
                chan_msg(arg->query_name() + " junks: Someone's trying to avoid me by hiding in their hotel room... CHICKEN!\n");
            else
                chan_msg(arg->query_name() + " junks: SOMEONE IS SCARED of me. Heh!\n");

            arg->set_count(COUNT_TRAVEL_FUTILITY, 0);
            arg->add_count(COUNT_JUNK_FLAP, 300);
        }

        /* we are hiding somewhere - the casino */
        else if(sscanf(dest, "players/boltar/casino%s", temp) == 1)
        {
            if(!arg->query_count(COUNT_JUNK_FLAP))
                chan_msg(arg->query_name() + " junks: Hiding in the casino from me won't help. You know who you are.\n");
            else
                chan_msg(arg->query_name() + " junks: All your corpse are belong to us!\n");

            arg->set_count(COUNT_TRAVEL_FUTILITY, 0);
            arg->add_count(COUNT_JUNK_FLAP, 300);
        }

        /* we are hiding somewhere - the motel */
        else if(sscanf(dest, "players/boltar/motel%s", temp) == 1)
        {
            if(!arg->query_count(COUNT_JUNK_FLAP))
                chan_msg(arg->query_name() + " junks: Hiding in the motel from me? Yarr!\n");
            else
                chan_msg(arg->query_name() + " junks: Feh! Hiding in the motel is so TEH LOSE!\n");

            arg->set_count(COUNT_TRAVEL_FUTILITY, 0);
            arg->add_count(COUNT_JUNK_FLAP, 300);
        }


    }

    room = find_object(dest);
    /* if we cannot find it, we try loading it first */
    if(!room)
    {
        /* A neat little trick from /room/church.c */
        /* verte added catch() and room = find_object() .. */
        catch(call_other(dest, "???"));
        room = find_object(dest);
    }

    /* If we still can't access it, there's an error... */
    if(!room)
    {
        arg->report_message("I was supposed to teleport but the destination doesn't exist...\n");
        arg->report_message("Going to try and reload it again...\n");
        return 0;
    }

    /* do the dirty work */
    current_room = environment(arg);
    if(current_room)
        arg->remote_say(arg->query_name() + " disappears in a puff of smoke.\n");
    tell_object(arg, "You move by teleport...\n");

    move_object(arg, room);
    
    arg->remote_say(arg->query_name() + " arrives in a puff of smoke.\n");
    do_look(arg);

    /* update our counter variable */
    arg->set_string(STR_TRAVEL_PREVIOUS_ROOMNAME, dest);

    /* tell everyone where we are */
    if(!arg->is(MODE_BRIEF)) 
        arg->report_message("Direct teleport to " + describe_room(room) + ".\n");

    return 1;
}




/* used internally... */
report_message(arg)
{
    object ob;
    object room;
    string message;
    int i;


    message = HIY + ">> " + HIR + "*" + HIY + "System.monster" + NORM + NORM + " reports: " + arg;

    ob = users();

    for(i = 0; i < sizeof(ob); i ++)
    {
        if(present(RADIO_ID, ob[i]))
            tell_object(ob[i], message);
    }
    tell_room(LISTENING_ROOM, message);

}

/* eof */
