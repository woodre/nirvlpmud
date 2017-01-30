inherit "/players/mizan/core/monster.c";
#include "definitions.h"
#include "router.h"

#include "/obj/user/shout_only.c"
#include "/obj/ansi.h"

/*
 * The purpose of this object is to house basic functionality used by the smart monsters.
 * Contents personal copyright Mizan@Nirvana, 2003.
 * Exclusive rights also to Boltar@Nirvana.
 * Reproduction on other muds restricted, under penalty of personal retribution.
 *
 */


int is_loaded;                  /* set this in your inherited monsters to tell the object it is loaded. */

int arr_attribs;                /* an array of our attributes */
int arr_counts;                 /* an array of all our counters... */
int arr_toggles;                /* an array of our toggles */
int arr_chances;                /* an array of chance objects */
int arr_ints;                   /* an array of general settings */
int monster_difficulty_type;

string arr_strings;             /* an array of strings for general settings */
object arr_objs;                /* an array of objects we use for pointers */

string my_monster_guild_rank;   /* a text string ranking, mostly for decoration */
string my_monster_guild_level;  /* the actual integer level we are in the guild */
string my_coverage_map;         /* an array of monster IDs that we will cover ourselves for. */
int my_money;                   /* how much cash we are carrying */
int my_composite;

/* channel stuff */
string attacked_mchannels;      /* our channel messages when under attack */
string panicked_mchannels;      /* our channel messages when panicked */
string hit_hard_mchannels;      /* our emotes when we absorb a tremendous amount of damage from players */
string taunting_mchannels;
string triumph_mchannels;
string casual_mchannels;
string scared_mchannels;
string arrival_mchannels;
string death_mchannels;         /* message played out when we die */
string shit_throw_mchannels;    /* when we hit people with shit */
string balloon_throw_mchannels;

/* emote stuff */
string attacked_emotes;         /* our emotes when under attack */
string panicked_emotes;         /* our emotes when panicked! */
string hit_hard_emotes;         /* our emotes when we absorb a tremendous amount of damage from players */
string taunting_emotes;
string triumph_emotes;
string casual_emotes;
string scared_emotes;
string arrival_emotes;
string death_emotes;            /* message played out when we die */
string shit_throw_emotes;
string balloon_throw_emotes;

/* orders related stuff */
object orders_objective_object; /* object data for orders */
string orders_objective_string; /* string data for orders */
int orders_objective_int;       /* integer data for orders */
int orders_objective_object_exp;

int my_orders;                  /* the identifier for the types of orders we have been given */
int my_orders_duration;         /* the amount of how long we are supposed to follow our orders. */


reset(arg)
{
    ::reset(arg);
    if(arg) return;

    /* init our arrays */
    arr_counts = allocate(20);
    arr_chances = allocate(20);
    arr_toggles = allocate(30);
    arr_ints = allocate(20);
    arr_strings = allocate(20); 
    arr_objs = allocate(20);
    arr_attribs = allocate(6);

    /* set our variables */
    toggle_off(MODE_ORDERS_ACHIEVED);
    toggle_on(MODE_BRIEF);
    toggle_off(MODE_HAS_CALLED_FOR_BACKUP);

    enable_commands();

    remove_call_out("do_random_move");
    call_out("do_random_move", 10);

    remove_call_out("extra_reset");
    call_out("extra_reset", 2);

}

extra_reset()
{
    if(!environment(this_object())) return 1;
    
    /* report our arrival to the boss. */
    report_event(EVENT_ARRIVAL, this_object());
    do_emote_arrival(this_object());

    /* give ourselves some goods */
/*
    call_out("recharge_shit", 4);
    call_out("recharge_balloon", 8);
    call_out("recharge_fireworks", 10);
*/

    /* set our composite */
    my_composite = calculate_worth();

    if(!environment(this_object()) && !short())
        set_heart_beat(1);

}


init()
{
    ::init();

    add_action("on_raise_emotional_temp", "kick");
    add_action("on_raise_emotional_temp", "punt");
    add_action("on_raise_emotional_temp", "grope");
    add_action("on_raise_emotional_temp", "kick");
    add_action("on_raise_emotional_temp", "wedgie");
    add_action("on_raise_emotional_temp", "fondle");
    add_action("on_raise_emotional_temp", "sex");
    add_action("on_raise_emotional_temp", "foff");
    add_action("on_raise_emotional_temp", "noogie");
    add_action("on_raise_emotional_temp", "lake");
    add_action("on_raise_emotional_temp", "tackle");
    add_action("on_raise_emotional_temp", "boot");
    add_action("on_raise_emotional_temp", "ravish");
}


long()
{
    int count;

    /* call our super */
    ::long();

    if(is(MODE_PILLAGING) != 0)
        write(HIR + query_name() + " is currently in PILLAGING MODE.\n" + NORM +
              "(That basically means this creature is out to hunt other monsters.)\n");
    
    if(is(MODE_IS_PISSED_OFF))
        write(query_name() + " appears to be pretty pissed off right now.\n");

    if(query_count(COUNT_CORPSES_LOOTED) > 1)
        write(query_name() + " has looted " + query_count(COUNT_CORPSES_LOOTED) + " corpses today.\n");
    
    write("You notice that " + query_name() + " is carrying " + my_money + " coins.\n");

    count = sizeof(all_inventory(this_object()));
    if(count > 12) write("You also notice that " + query_name() + " is carrying " + count + " items.\n");

    if(this_player() && this_player()->query_name())
    {
        report_message(this_player()->query_name() + " just looked at me.\n");

        /* hit the player who looked at us with a water balloon, if we have one */
        if(query_obj(OBJ_BALLOON) && is(MODE_BALLOON_THROWER) && this_player()->query_level() < 20)
        {
            command("pelt " + this_player()->query_real_name());
            report_message("I pelted " + this_player()->query_name() + " with a water balloon.\n");
            remove_call_out("recharge_balloon");
            call_out("recharge_balloon", 50);
        }
    }
}

/*
 * A note about pillaging. We will singlemindedly kill other monsters when
 * set on pillaging mode. If a player attacks us, the pillaging flag is turned off
 * and we can revert to our normal behaviors.
 *
 *
 */
heart_beat()
{
    int dam;
    int i;

    object attacker;
    object ally_attacker;
    object room;
    object corpse;
    object ob;
    string attacker_name;

    if(root() || !environment()) return;
    /* initialize our variables */
    room = environment(this_object());
    attacker = this_object()->query_attack();
    ally_attacker = check_allies_presently_fighting(this_object());
    
    /* see if we steal/loot/eat corpses */
    do_corpse_management_routines(this_object());

    /* deal with our counters */
    increment_count(COUNT_INFUSE_NEXUS);
    decrement_count(COUNT_ASSISTED_ALLY);
    decrement_count(COUNT_JUNK_FLAP);
    decrement_count(COUNT_HELPED_NEWBIES);
    decrement_count(COUNT_JUNK_FLAP);
    decrement_count(COUNT_EMOTIONAL_TEMP_ANGER);
    decrement_count(COUNT_HEALQUOTA_CUTOFF);

    
    /* i dont know why this is here but obj/living.c and monster.c do it too... */
    if(!this_object()) return 0;

    if(!is_loaded)
    {
        move_object(this_object(), "room/void");
        set_heart_beat(0);
        return 1;
    }

    /* do we have orders */
    /* we should check if we are check_trapped_inside_object() in the future */
    if(my_orders && !is(MODE_ORDERS_ACHIEVED))
    {
        increment_count(COUNT_ORDERS_TIME);
        follow_orders(this_object(), my_orders);
    }
    else
    {
        /* we are not on orders and are wandering around */

    }

    /* attack kids, if we are kid killers */
    if(is(MODE_KID_KILLER) && !attacker)
        do_attack_mudkid(this_object());

    if(is(MODE_PET_KILLER) && !attacker)
        do_attack_pet(this_object());

    if(is(MODE_PK_INSTIGATOR) && !attacker)
        do_attack_player_killer(this_object());

    /* steal everything! */
    if(query_chance_of(CHANCE_TAKE_ALL_LOOT) > random(100))
        do_get_everything(this_object());

    /* this is the part where we hit people with water balloons or shit */
    /* stop tossing in 'safe' rooms, -Bp */
/*
    if(object_name(room) != "room/vill_green")
    if(object_name(room) != "room/church")
    do_pelt_routines(this_object());
*/    
    /* where we do our healing bits. */
    do_healing_routines(this_object());

    /* our attack routines */
    do_attack_routines(this_object());

    /* call our super */
    ::heart_beat();

    /* show our health, if we are being snooped. */
    if(attacker && query_obj(OBJ_SNOOP_VIEW)) do_show_combat_monitor(this_object());

    /* if we are generous and newbies are present we see if they need stuff */
    if(query_monster_attrib(ATTRIB_GENEROUSITY) > random(100))
        do_help_newbies(this_object());

    /* if an ally is present, and they are being attacked */
    if(!attacker &&
       !query_count(COUNT_ASSISTED_ALLY) &&
       is(MODE_COVERS_PRESENT_ALLIES) &&
       ally_attacker)
    {
        /* tell room of impending beatdown */
        tell_room(room, HIR + query_name() + " exclaims: Don't attack my friends!!!\n" + NORM);

        tell_room(room, HIR + "A very enraged " + query_name() + " leaps into combat attacking " + ally_attacker->query_name() + "!\n" + NORM);

        /* we start pounding on them, without affecting our orders */
        attack_object(ally_attacker);

        /* increment our assist count */
        add_count(COUNT_ASSISTED_ALLY, 30);
    }
}
/* end function heart_beat(); */


heartbeat_attack()
{
    /* deliberately nothing here */
}


is_maze_monster() { return 1; }

do_random_move()
{
    int n;
    int is_trapped;
    object corpse;
    object room;
    object roomroom;

    if(!environment(this_object())) return 1;

    /* randomly kick our own heartbeat */
    if(1 == random(10))
    {
        set_heart_beat(1);
    }

    /* if stop moving is in effect, we do not move - but we still call ourselves out
     * because this beat occurs asynchronously from heartbeat. */
    if(is(MODE_STOP_MOVING))
    {
        remove_call_out("do_random_move");
        call_out("do_random_move", 30);
        return 0;
    }

    /* if there is a corpse present, we will pause for a moment */
    corpse = present("corpse", environment(this_object()));
    if(corpse)
    {
        remove_call_out("do_random_move");
        call_out("do_random_move", 2);
        return 0;
    }
    
    /* init our travel room */
    if(!query_obj(OBJ_TRAVEL_ROOM))
        set_obj(OBJ_TRAVEL_ROOM, environment(this_object()));

    /* we see if we are trapped inside a container - like a bag */
    is_trapped = check_trapped_inside_object(this_object());

    /* if we are not fighting or stuck inside a washing machine, try moving a direction */
    if(!is_trapped && !this_object()->query_attack())
        do_walk(this_object());

    /* we are in a new room. Report it */
    if(environment() && environment() != query_obj(OBJ_TRAVEL_ROOM))
    {
        if(!is(MODE_BRIEF))
            report_message("I am now in " + describe_room(environment()) + ".\n");

        set_obj(OBJ_TRAVEL_ROOM, environment());
        set_count(COUNT_MOTION, 0);
    }

    /* We have been stuck in the same room for too long. Teleport out. */
    /* unless we are berserking, we just return to our waypoint */
/* - TODO - we need some trap protection code, perhaps a monster's guild
 inside the maze?

    if(is(MODE_PILLAGING) && !is_trapped && query_count(COUNT_MOTION) > 18)
    {   
        if(my_orders == ORDERS_PILLAGECASTLE)
            teleport_me(this_object(), get_castle_waypoint(orders_objective_string));
        else if(my_orders == ORDERS_PILLAGELOITER)
            teleport_me(this_object(), orders_objective_string);
    }
    else if(!is(MODE_PILLAGING) &&
            query_count(COUNT_MOTION) > 9 &&
            !is_trapped)
            do_teleport_waypoint(this_object());
*/

    /* increment our motion counter */
    increment_count(COUNT_MOTION);

    /* call our move again */
    remove_call_out("do_random_move");

    /* if we are pillaging, we roam around at full throttle... */
    if(is(MODE_PILLAGING))
        call_out("do_random_move", 1);
    /* if the monster doesn't have a custom frequency, we call our default */
    else if(query_int(VAL_RANDOM_MOVE_FREQUENCY))
        call_out("do_random_move", query_int(VAL_RANDOM_MOVE_FREQUENCY));
    else call_out("do_random_move", 5);
}


do_infuse_nexus(arg)
{
    /* the coins we generate from looting resets our deficit to the nexus. */
    deduct_count(COUNT_HEAL_QUOTA, -(my_money * 60));

    /* add up our count to the score */
    add_count(COUNT_COINS_INFUSED, my_money);

    add_nexus_coins(my_money);
    add_money(-my_money);

    /* we have cashed in, so we aren't pissed anymore */
    toggle_off(MODE_IS_PISSED_OFF);

    set_count(COUNT_INFUSE_NEXUS, 0);
    
    /* we feed it an arg 1 to dest EVERYTHING in inventory after processing */
    if(arg)
        process_inventory(this_object(), 1);
    else
        process_inventory(this_object());

}


/* this simply resets all of our orders data */
clear_orders_data()
{
    toggle_off(MODE_ORDERS_ACHIEVED);
    my_orders = 0;
    toggle_off(MODE_ON_ORDERS);
    set_count(COUNT_ORDERS_TIME, 0);
    my_orders_duration = 0;
    toggle_off(MODE_STOP_MOVING);
    toggle_off(MODE_PILLAGING);
    toggle_off(MODE_TO_THE_DEATH);
}


/* this pisses us off */
on_raise_emotional_temp(arg)
{
    object room;

    if(!arg || !id(arg) || query_attack()) return 0;

    
    room = environment(this_object());

    add_count(COUNT_EMOTIONAL_TEMP_ANGER, 50);

    say_angry_message(query_count(COUNT_EMOTIONAL_TEMP_ANGER));

    if(query_count(COUNT_EMOTIONAL_TEMP_ANGER) > 300 &&
       this_player() &&
       room &&
       !room->query_fight_area() &&
       !query_attack()) 
    {
        report_message(this_player()->query_name() + " has harrassed me to the point of violence...\n");
        if(query_monster_attrib(ATTRIB_VINDICTIVENESS) > random(100))
            receive_orders(this_object(), ORDERS_HUNT_OBJECT, this_player(), 5);
        else
            receive_orders(this_object(), ORDERS_KILL_OBJECT, this_player(), 10);

        /* make us pissed off, too */
        toggle_on(MODE_IS_PISSED_OFF);
        return 1;
    }

    return 0;
}


say_angry_message(arg)
{
    string text;

    if(!arg) return;

    if(arg > 250) text = "I am going to kill you if you do that again.\n";
    else if(arg > 225) text = "What the hell is your problem?\n";
    else if(arg > 175) text = "Dickface, you're asking for trouble.\n";
    else if(arg > 125) text = "Asshole! Stop!\n";
    else if(arg > 100) text = "What the hell?\n";
    else if(arg > 50)
        text = "Stop that!\n";
    else text = "Uhh... what was that for?\n";

    remote_say(query_name() + " says: " + text);
}

/*********************************************
 *
 * O T H E R  M E T H O D S
 *
 *********************************************/

/* for counters and stuff */
toggle_on(arg) { arr_toggles[(int) arg] = 1; }
toggle_off(arg) { arr_toggles[(int) arg] = 0; }
query_toggle(arg) { return arr_toggles[(int) arg]; }
is(arg) { return arr_toggles[(int) arg]; }

set_obj(arg, value) { arr_objs[(int) arg] = value; }
query_obj(arg) { return arr_objs[(int) arg]; }

set_int(arg, value) { arr_ints[(int) arg] = value; }
query_int(arg) { return arr_ints[(int) arg]; }

set_string(arg, value) { arr_strings[(int) arg] = value; }
query_string(arg) { return arr_strings[(int) arg]; }

set_count(arg, value)
{
    arr_counts[(int) arg] = value; 
    /* keep counts from dipping below zero */
    if(arr_counts[(int) arg] < 0) arr_counts[(int) arg] = 0;
}

query_count(arg) { return arr_counts[(int) arg]; }
add_count(arg, value) { arr_counts[(int) arg] = arr_counts[(int) arg] + value; }
increment_count(arg) { arr_counts[(int) arg] = arr_counts[(int) arg] + 1; }
decrement_count(arg)
{
    arr_counts[(int) arg] = arr_counts[(int) arg] - 1; 
    if(arr_counts[(int) arg] < 0) arr_counts[(int) arg] = 0; 
}

deduct_count(arg, value)
{
    arr_counts[(int) arg] = arr_counts[(int) arg] - value; 
    if(arr_counts[(int) arg] < 0) arr_counts[(int) arg] = 0; 
}

dump_counts()
{
    int i;
    for(i = 0; i < sizeof(arr_counts); i ++)
    {
        write("Member " + i + ": " + arr_counts[i] + "\n");
    }
}

query_monster_attrib(arg) { return arr_attribs[(int) arg]; }
set_attribute(arg, value) { arr_attribs[(int) arg] = value; }

set_chance_of(arg, value) { arr_chances[(int) arg] = value; }
query_chance_of(arg) { return arr_chances[(int) arg]; }

/* channel sets-queries */
query_attacked_mchannels() { return attacked_mchannels; }
set_attacked_mchannels(arg) { attacked_mchannels = arg; }

query_panicked_mchannels() { return panicked_mchannels; }
set_panicked_mchannels(arg) { panicked_mchannels = arg; }

query_hit_hard_mchannels() { return hit_hard_mchannels; }
set_hit_hard_mchannels(arg) { hit_hard_mchannels = arg; }

query_casual_mchannels() { return casual_mchannels; }
set_casual_mchannels(arg) { casual_mchannels = arg; }

query_scared_mchannels() { return scared_mchannels; }
set_scared_mchannels(arg) { scared_mchannels = arg; }

query_taunting_mchannels() { return taunting_mchannels; }
set_taunting_mchannels(arg) { taunting_mchannels = arg; }

query_death_mchannels() { return death_mchannels; }
set_death_mchannels(arg) { death_mchannels = arg; }

query_triumph_mchannels() { return triumph_mchannels; }
set_triumph_mchannels(arg) { triumph_mchannels = arg; }

query_shit_throw_mchannels() { return shit_throw_mchannels; }
set_shit_throw_mchannels(arg) { shit_throw_mchannels = arg; }

query_balloon_throw_mchannels() { return balloon_throw_mchannels; }
set_balloon_throw_mchannels(arg) { balloon_throw_mchannels = arg; }

query_arrival_mchannels() { return arrival_mchannels; }
set_arrival_mchannels(arg) { arrival_mchannels = arg; }


/* emote set-queries */
query_attacked_emotes() { return attacked_emotes; }
set_attacked_emotes(arg) { attacked_emotes = arg; }

query_panicked_emotes() { return panicked_emotes; }
set_panicked_emotes(arg) { panicked_emotes = arg; }

query_hit_hard_emotes() { return hit_hard_emotes; }
set_hit_hard_emotes(arg) { hit_hard_emotes = arg; }

query_casual_emotes() { return casual_emotes; }
set_casual_emotes(arg) { casual_emotes = arg; }

query_scared_emotes() { return scared_emotes; }
set_scared_emotes(arg) { scared_emotes = arg; }

query_taunting_emotes() { return taunting_emotes; }
set_taunting_emotes(arg) { taunting_emotes = arg; }

query_death_emotes() { return death_emotes; }
set_death_emotes(arg) { death_emotes = arg; }

query_triumph_emotes() { return triumph_emotes; }
set_triumph_emotes(arg) { triumph_emotes = arg; }

query_shit_throw_emotes() { return shit_throw_emotes; }
set_shit_throw_emotes(arg) { shit_throw_emotes = arg; }

query_balloon_throw_emotes() { return balloon_throw_emotes; }
set_balloon_throw_emotes(arg) { balloon_throw_emotes = arg; }

query_arrival_emotes() { return arrival_emotes; }
set_arrival_emotes(arg) { arrival_emotes = arg; }

/* others */

set_coverage_map(arg) { my_coverage_map = arg; } 
query_coverage_map() { return my_coverage_map; }

set_monster_guild_rank(arg) { my_monster_guild_rank = arg; } 
query_monster_guild_rank() { return my_monster_guild_rank; }

set_monster_guild_level(arg) { my_monster_guild_level = arg; } 
query_monster_guild_level() { return my_monster_guild_level; }

/* for our orders */
set_orders_objective_string(arg) { orders_objective_string = arg; }
query_orders_objective_string() { return orders_objective_string; }

set_orders_objective_object(arg) { orders_objective_object = arg; }
query_orders_objective_object() { return orders_objective_object; }

set_orders_objective_object_exp(arg) { orders_objective_object_exp = arg; }
query_orders_objective_object_exp() { return orders_objective_object_exp; }

set_orders_objective_int(arg) { orders_objective_int = arg; }
query_orders_objective_int() { return orders_objective_int; }

query_orders_duration() { return my_orders_duration; }
set_orders_duration(arg) { my_orders_duration = arg; }

set_orders(arg) { my_orders = arg; }
query_orders() { return my_orders; }


hit_player(arg, type1, dam2, type2)
{
    /* we only report damage to wizzes */
    if(this_player() && living(this_player()))
        tell_room(LISTENING_ROOM,
             HIK + ">> " + query_name() + " " + (query_hp() * 100) / query_mhp() + "%HP fighting " +
             this_player()->query_name() + " " + 
             (this_player()->query_hp() * 100) / this_player()->query_mhp() + "%HP\n" + NORM);

    /* If the thing attacking us is a player, we turn off our pillaging flag */
    if(is(MODE_PILLAGING) && this_player() && this_player()->is_player())
    {
        /* kinda redundant, stole it from heartbeat function */

        if(my_orders == ORDERS_PILLAGECASTLE || my_orders == ORDERS_PILLAGELOITER)
        /* if we are in good shape */
        if(query_hp() > query_mhp() / 2 && !is(MODE_TO_THE_DEATH))
        {
            if(query_monster_attrib(ATTRIB_VINDICTIVENESS) > random(100))
                receive_orders(this_object(), ORDERS_HUNT_OBJECT, this_player(), 5);
            else
                receive_orders(this_object(), ORDERS_KILL_OBJECT, this_player(), 10);
        }
        /* else we are in bad shape, will run fades instead */
        else
        {
            if(query_monster_attrib(ATTRIB_VINDICTIVENESS) > random(100) && !is(MODE_TO_THE_DEATH))
                receive_orders(this_object(), ORDERS_HITFADE_NAME, this_player()->query_real_name(), 30);
            else
                receive_orders(this_object(), ORDERS_HITFADE_OBJECT, this_player(), 10);
        }
    }

/* debug
    if(previous_object()) say("prev: " + previous_object()->query_name() + "\n");
    if(this_player()) say("this: " + this_player()->query_name() + "\n");
 */

    if(arg && arg > 60)
    {

        
        if(this_player()) log_file("mizan.monsterplus.log", ctime() + " " + this_player()->query_real_name() + " hit_player on " + query_name() + " of " + arg + "\n");

        /* if we get hit with something very unreasonable, we call for help asap */
        if(arg > 100 &&
           is(MODE_CALLS_FOR_BACKUP) &&
           !is(MODE_HAS_CALLED_FOR_BACKUP) &&
           !is(MODE_PILLAGING))
        {
            toggle_on(MODE_IS_PISSED_OFF);
            request_backup_for(this_object());
            remove_call_out("reset_backup_call");
            call_out("reset_backup_call", 300);
            toggle_on(MODE_HAS_CALLED_FOR_BACKUP);
            do_emote_panicked(this_object());
        }

        do_emote_hit_hard(this_object());

        /* i am uncapping the damage a player can do to a monster - miz */
        return ::do_damage(({arg,dam2}),({type1,type2}));
    }
    else 
    {

        /* if we are afraid, we call for backup */
        if(query_monster_attrib(ATTRIB_FEARLESSNESS) < random(100) && 
           is(MODE_CALLS_FOR_BACKUP) &&
           !is(MODE_HAS_CALLED_FOR_BACKUP) &&
           !is(MODE_PILLAGING) &&
           1 == random(4))
        {
              request_backup_for(this_object());
              remove_call_out("reset_backup_call");
              call_out("reset_backup_call", 360);
              toggle_on(MODE_HAS_CALLED_FOR_BACKUP);
              do_emote_scared(this_object());
        }

        /* important to return this entire array to the super... visualization messages depend on it */
        return ::do_damage(({arg,dam2}),({type1,type2}));
    }
}


attack_object(arg)
{
    /* we are basically checking against attacking other fellow monsters */
    if(arg && arg->fellow_monster()) return 0;
    
    /* and checking against attacking ourselves */
    else if(arg && arg == this_object()) return 0;

    else return ::attack_object(arg);
}


heal_me(arg)
{
    if(!arg || arg < 0) return;
    hit_point += arg;
}


/* this is how we display messages on the monster channel */
report_message(arg)
{
    object ob;
    object room;
    string message;
    int i;

    if(is(MODE_RADIO_SILENCED)) return 0;

    message = HIY + ">> " + query_name() + NORM + " reports: " + arg;

    ob = users();

    for(i = 0; i < sizeof(ob); i ++)
    {
       if(ob[i])
        if(present(RADIO_ID, ob[i]))
            tell_object(ob[i], message);
    }

    tell_room(LISTENING_ROOM, message);
}


/* we give ourselves a new lump of shit */
do_recharge_shit()
{
    remove_call_out("recharge_shit");
    call_out("recharge_shit", 50 + random(50));
}


do_recharge_balloon()
{
    remove_call_out("recharge_balloon");
    call_out("recharge_balloon", 50 + random(50));
}

do_recharge_fireworks()
{
    remove_call_out("recharge_fireworks");
    call_out("recharge_fireworks", 50 + random(50));
}

recharge_shit()
{
    object shit;
    if(query_obj(OBJ_SHITPILE)) return;

    shit = clone_object("/players/mizan/etheriel/items/shit.c");
    move_object(shit, this_object());
    if(my_monster_guild_level < 2) report_message("I received a new pile of shit!\n");
    say("A pile of shit materializes into " + query_name() + "'s inventory.\n");
    set_obj(OBJ_SHITPILE, shit);
}
    

/* we give ourselves a new water balloon */
recharge_balloon()
{
    object balloon;
    if(query_obj(OBJ_BALLOON)) return;

    balloon = clone_object("/players/mizan/etheriel/items/water-balloon.c");

    move_object(balloon, this_object());
    if(my_monster_guild_level < 2) report_message("I received a new water balloon!\n");
    say(balloon->short() + " materializes into " + query_name() + "'s inventory.\n");
    set_obj(OBJ_BALLOON, balloon);
}


/* we give ourselves a new water balloon */
recharge_fireworks()
{
    object fireworks;
    if(query_obj(OBJ_FIREWORKS)) return;

    fireworks = clone_object("/players/mizan/etheriel/items/blockbuster.c");

    move_object(fireworks, this_object());
    if(my_monster_guild_level < 2) report_message("I received a new firecracker!\n");
    say(fireworks->short() + " materializes into " + query_name() + "'s inventory.\n");
    set_obj(OBJ_FIREWORKS, fireworks);
}


/* resets our call for backup */
reset_backup_call()
{
    toggle_off(MODE_HAS_CALLED_FOR_BACKUP);
}


fellow_monster() { return 1; }

is_monsterplus() { return 1; }

add_money(arg)
{
    if(!arg) return;

    my_money += arg;

}

/* to keep monster heartbeats on */
query_player_shell() { return 1; }

query_money() { return my_money; } 

query_hbflag() { return "hbstayon"; }

/* i noticed some monsters use this as an attack. Fargh. */
set_hp(arg) { return 1; }


remote_say(str, ignore) 
{
    if(ignore)
        say(str, ignore);
    else
        say(str);
}


/* We died.. tell the others. */
death()
{
    object tripodcard;
    object room;
    string room_filename;
    string obit_text;

    room = environment(this_object());
    report_message(this_object()->query_name() + NORM + " was killed in combat.\n");

    if(attacker_ob)
    {
        tripodcard = present("tripod_card", attacker_ob);
        /* If our attacker indeed does have a tripod card, we log this in as a kill. */
        if(tripodcard)
        {
            report_message(attacker_ob->query_name() + NORM + " is credited with the kill.\n");
            tripodcard->log_kill(monster_difficulty_type);
        }

        if(room) room_filename = object_name(room);
        else room_filename = "unknown";

        /* log this death to CSV */
        obit_text = "\"" + ctime() + "\",";
        obit_text += "\"" + object_name(this_object()) + "\",";
        obit_text += "\"" + query_count(COUNT_TOTAL_COMBAT_ROUNDS) + "\",";
        obit_text += "\"" + attacker_ob->query_name() + "\",";
        obit_text += "\"" + room_filename + "\"\n";

        write_file("/players/mizan/opl/logs/monster_kills.csv", obit_text);

    }
/*
    if(alt_attacker_ob)
    {
        tripodcard = present("tripod_card", alt_attacker_ob);
        if(tripodcard)
        {
            tripodcard->log_assist(monster_difficulty_type);
        }
    }
*/
    if(!death_emotes)
        report_message("Buh! I died...\n");
    else
        do_emote_death(this_object());

    report_event(EVENT_DEPARTURE, this_object());
    ::death();
}


catch_tell(str)
{
    object ob;
    object from;
    object dest;

    from = this_player();

    if(!from) return 1;

    dest = query_obj(OBJ_SNOOP_VIEW);

    /* we want to prevent recursion errors */
    if(dest &&
       str &&
       is(MODE_SNOOP_ACTIVE) &&
       environment(this_object()) &&
       environment(this_object()) != dest)
       tell_object(dest,  BWHT + BLK + "%" + str + NORM);


    ::catch_tell(str);
    return 1;

}

exit() 
{
    report_message("Hmm, something was inside my inventory...\n");
    return 0;
}


/* eof */
