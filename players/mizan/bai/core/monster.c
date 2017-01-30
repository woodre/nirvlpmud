/*
 * This is an updated monster.c that many of the critters in my maze use.
 * Some of the functionality of the Monster Guild will be replicated here
 * but on a smaller scale.
 */
inherit "/obj/monster.c";
#include "../definitions.h"
#include "/obj/ansi.h"

#define OBSERVATION_ROOM "/players/mizan/bai/ROOMS/control.c"

int my_random_move_time;
int block_exits;
int num_attackers;
int called_backup;
int rounds_combat;
int total_rounds_combat;

/* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
int monster_difficulty_type = 0;

int is_maze_monster() { return 1; }

void set_random_move_time(int arg)
{
    if (!arg || arg < 0) return;
    my_random_move_time = arg;
}

void set_block_exits(int arg)
{
    block_exits = arg;
}

int is_exit_blocker()
{
    if (block_exits) return 1;
    else return 0;
}

int unblock_exits_temporarily()
{
    object room;

    if(!block_exits) return 0;

    room = environment(this_object());
    if(room) tell_room(room, query_name() + " suddenly looks more peaceful and less violent...'\n");

    block_exits = 0;

    remove_call_out("block_exits");
    call_out("block_exits", 600);
    return 1;
}

void block_exits()
{
    object room;
    room = environment(this_object());
    if(room) tell_room(room, query_name() + " blinks and begins blocking exits again.\n");

    block_exits = 1;
}

void reset(int arg)
{
    ::reset(arg);

    /* blank out our variables */
    my_random_move_time = 0;
    called_backup = 0;
    rounds_combat = 0;


    enable_commands();
    remove_call_out("make_random_move");
    call_out("make_random_move", 1);

    if(!arg)
    {
        remove_call_out("announce_arrival");
        call_out("announce_arrival", 1);
    }

}

/* This announce to our observation room that we are here. 
 * We also take the opportunity to do a bit of setup. 
 */
void announce_arrival()
{
    if(this_object()->short() &&
       environment(this_object()))
        tell_room(OBSERVATION_ROOM, HIY + ">> " + (this_object()->query_name()) + NORM + " is added to the roster.\n");

    /* Some extra combat spells that ALL monsters have. */

    /* if this monster isn't a blocker, give it wimpy */
    if(!block_exits) 
    {
        wimpy_health = 3;
        wimpy_chance = 10;
        whimpy = 1;
    }
}


/**
 * This simply returns to us the number of people attacking us. 
 *
 */
int count_my_attackers()
{
    object room;
    object ob;
    object me;
    int count;

    me = this_object();

    room = environment();
    if(!room) return 0;

    ob = first_inventory(room);
    while(ob)
    {
        if(ob->query_attack() && (object) ob->query_attack() == me)
            count ++;
        ob = next_inventory(ob);
    }

    return count;
}


void make_random_move()
{
    object room;
    mixed my_exits;
    int n;

    if (my_random_move_time < 1) return;

    room = environment(this_object());
    if(!room) return;

    my_exits = (string) call_other(room, "query_dest_dir_available");
    if(my_exits &&
       this_object()->is_player_present())
    {
        command(my_exits[random(sizeof(my_exits))], this_object());
    }

    else if (this_object()->is_player_present())
    {
        /* if we are not fighting, we move */
            n = random(5);
            if (n == 1)
                command("west");
            if (n == 2)
                command("east");
            if (n == 3)
                command("south");
            if (n == 4)
                command("north");
    }

    remove_call_out("make_random_move");
    call_out("make_random_move", my_random_move_time);

}

int is_player_present()
{
    object room;
    object ob, oc;

    room = environment(this_object());
    if(!room) return 0;

    ob = first_inventory(room);
    while(ob)
    {
        oc = next_inventory(ob);
        if(ob->is_player()) return 1;
        ob = oc;
    }
    return 0;
}

void init()
{
    ::init();

    /* if this is an exit blocker monster */
    if (block_exits)
    {
        add_action("block_exit", "north");
        add_action("block_exit", "n");
        add_action("block_exit", "south");
        add_action("block_exit", "s");
        add_action("block_exit", "east");
        add_action("block_exit", "e");
        add_action("block_exit", "west");
        add_action("block_exit", "w");
    }
}


int block_exit()
{
    /* exclude wizards from block */
    if (this_player() &&
            this_player()->is_player() &&
            this_player()->query_level() < 20 &&
            block_exits)
    {
        write(this_object()->query_name() + " blocks you.\n");
        say(this_object()->query_name() + " blocks " + this_player()->query_name() + " from leaving.\n");
        return 1;
    }
    else return 0;
}

void death(string str)
{
    object tripodcard;
    object room;
    string obit_text;
    string room_filename;

    room = environment(this_object());
    tell_room(OBSERVATION_ROOM, HIY + ">> " + this_object()->query_name() + NORM + " was killed in combat.\n");

    if(attacker_ob)
    {
        tell_room(OBSERVATION_ROOM, HIY + ">> " + attacker_ob->query_name() + NORM + " is credited with the kill.\n");
  
        if(room) room_filename = object_name(room);
        else room_filename = "unknown";

        /* log this death to CSV */
        obit_text = "\"" + ctime() + "\",";
        obit_text += "\"" + object_name(this_object()) + "\",";
        obit_text += "\"" + total_rounds_combat + "\",";
        obit_text += "\"" + attacker_ob->query_name() + "\",";
        obit_text += "\"" + room_filename + "\"\n";

        write_file("/players/mizan/bai/logs/monster_kills.csv", obit_text);
    }

    ::death(str);
}

void attack_object(object arg)
{
    if(arg && living(arg))
    {
        tell_room(OBSERVATION_ROOM, HIY + ">> " + NORM + (this_object()->short()) + " is now attacking " +
        arg->query_name() + "!\n");
    }

    ::attack_object(arg);
}


