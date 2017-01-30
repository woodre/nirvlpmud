/*
 * This is an updated monster.c that many of the critters in my maze use.
 * Some of the functionality of the Monster Guild will be replicated here
 * but on a smaller scale.
 */
inherit "/obj/monster.c";
#include "../definitions.h"
#include "/obj/ansi.h"

#define OBSERVATION_ROOM "/players/mizan/opl/ROOMS/observation.c"

int my_random_move_time;
int block_exits;
int num_attackers;
int called_backup;
int rounds_combat;
int total_rounds_combat;

/* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
int monster_difficulty_type = 0;

/* This just says that we are a monster for the OPL maze. Used to keep them
 * IN the maze in case they actually make it to the 'up' exit, and follow it.
 */
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

/* If this is a blocker, players cannot leave the room until this monster
 * has been properly killed. */
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
    
    /* moving this to init() - ill
    remove_call_out("make_random_move");
    call_out("make_random_move", 1);
    */

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

/*
  Adjusted so the call_out stops running if there's no player present, since the
  monster only wanders if there is a player in the room.
   - ill 2015.08.18
*/
void make_random_move()
{
    object room;
    mixed my_exits;
    int n;

    if (my_random_move_time < 1) return;

    room = environment(this_object());
    if(!room) return;

    if(this_object()->is_player_present())
    {
      my_exits = (string) call_other(room, "query_dest_dir_available");
      if(my_exits) {
          command(my_exits[random(sizeof(my_exits))], this_object());
      } else {
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
    if (block_exits &&
        this_player())
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
    
    /* ill - 2015.08.18 */
    if(this_player() && this_player()->is_player())
    {
      remove_call_out("make_random_move");
      call_out("make_random_move", 1);    
    }
}


heart_beat()
{
    object room, my_attacker, pet, my_backup;
    int attacker_health;
    int beatdown_amount;
    int beatdown_chance;
    mixed atk_health;

    room = environment(this_object());
    my_attacker = attacker_ob;

    if(my_attacker &&
       room &&
       environment(my_attacker) &&
       environment(my_attacker) == room)
    {
        rounds_combat ++;
        total_rounds_combat ++;

        /* if the attacker's health is low, we try to capitalize on it. */
        /* Dunno why i have to cast the shit out of this... but oh well. */
        attacker_health = (((int) my_attacker->query_hp()) * 100) / ((int) my_attacker->query_mhp());

        /* This amounts to a free hit every once in a while */
        if(1 == random(10) &&
          attacker_health < 20 &&
          my_attacker &&
          room &&
          environment(my_attacker) &&
          environment(my_attacker) == room &&
          !my_attacker->query_ghost())
        {
            say(HIY + query_name() + " senses weakness in " + my_attacker->query_name() + "..." + NORM + "\n");
            say(query_name() + " hits " + my_attacker->query_name() + " with a bone-shattering crunch!\n");
            my_attacker->hit_player(60 + random(40), "other|sleaze");
        }


        pet = present("pet", room);

        if(pet &&
           living(pet) &&
           pet->is_pet() && 
           !pet->query_ghost())
        {
            say(HIY + query_name() + " hates pets like " + pet->query_name() + "!" + NORM + "\n");
            say(query_name() + " hits " + pet->query_name() + " with a bone-shattering crunch!\n");
            pet->hit_player(100 + random(100));
        }
    }

    num_attackers = count_my_attackers();
    if(1 == random(80) && !called_backup && num_attackers >= 8)
    {
        my_backup = clone_object("/players/mizan/opl/beasties/easy/goliathbeano.c");
        move_object(my_backup, room);
        tell_room(room, my_backup->query_name() + " arrives.\n");
        my_backup->attack_object(my_attacker);
        called_backup = 1;
    }

    /* if we have been fighting too long, we call in backup. */
    if(rounds_combat > 250 && monster_difficulty_type < 2)
    {
        my_backup = clone_object("/players/mizan/opl/beasties/easy/cobold.c");
        move_object(my_backup, room);
        tell_room(room, my_backup->query_name() + " arrives.\n");
        my_backup->attack_object(my_attacker);
        rounds_combat = 0;
    }


    /* We are back for more. Our objective is every 50 rounds or so to send the
     * player to roughly 100 hitpoints if they have more than 250 currently. */

    /* the chance in rounds which we will offer a beatdown to the tanker */
    /* This chance increases if we have more hitpoints. */
    beatdown_chance = 50;
    /* reuse this variable */
    if(my_attacker) atk_health = my_attacker->query_hp();
    if(atk_health > 400 && monster_difficulty_type > 1) beatdown_chance = 30;
    else if(atk_health > 450 && monster_difficulty_type > 1) beatdown_chance = 15;

    if(1 == random(beatdown_chance) &&
       my_attacker && 
       room &&
       environment(my_attacker) &&
       environment(my_attacker) == room &&
       rounds_combat > 15
       )
    {

        if(atk_health > 250 && !attacker_ob->query_ghost()) 
        {
            beatdown_amount = (atk_health - 100) - random(40);

            tell_room(room, query_name() + " hits " + attacker_ob->query_name() + " with a " + HBWHT + HIR + "B O N E  S H A T T E R I N G" + NORM + " crunch!\n");
            attacker_ob->hit_player(beatdown_amount, "physical");
            
        }

    }

    /* and now back to our regularly scheduled programming */
    ::heart_beat();
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
        tripodcard = present("tripod_card", attacker_ob);
        /* If our attacker indeed does have a tripod card, we log this in as a kill. */
        if(tripodcard)
        {
            tripodcard->log_kill(monster_difficulty_type);
            tell_room(OBSERVATION_ROOM, HIY + ">> " + attacker_ob->query_name() + NORM + " is credited with the kill.\n");
        }
  
        if(room) room_filename = object_name(room);
        else room_filename = "unknown";

        /* log this death to CSV */
        obit_text = "\"" + ctime() + "\",";
        obit_text += "\"" + object_name(this_object()) + "\",";
        obit_text += "\"" + total_rounds_combat + "\",";
        obit_text += "\"" + attacker_ob->query_name() + "\",";
        obit_text += "\"" + room_filename + "\"\n";

        write_file("/players/mizan/opl/logs/monster_kills.csv", obit_text);
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


