inherit "/players/mizan/core/monster.c";
#include "/obj/ansi.h"

/* follow and protect an object at all costs (object) */
#define ORDERS_PROTECT_OBJECT   4

/* attack, follow, hunt down an object (object) */
#define ORDERS_HUNT_OBJECT      5

/* specifically attack an object once encountered by chance (object)  */
#define ORDERS_KILL_OBJECT      6

/* attack ANYTHING with a matching name (string) */
#define ORDERS_KILL_BY_NAME     7

/* attack anyone with an ip address match (string) */
#define ORDERS_KILL_BY_IPADDR   8

/* defend a roomfile aggressively. Nothing gets past except fellow monsters (string) */
#define ORDERS_DEFEND_SPOT      9


string directions;
string waypoints;
string hit_player_messages;
string attacked_emotes;
string panicked_emotes;

object travel_room;
object travel_attacker;
object shit;
object balloon;

object orders_objective_object; /* object data for orders */
string orders_objective_string; /* string data for orders */
int orders_objective_int;       /* integer data for orders */
int is_orders_achieved;         /* a flag of whether or not we have accomplished our goal */
int my_orders;                  /* the identifier for the types of orders we have been given */
int is_on_orders;               /* if a monster is on orders, they cannot be bothered until the orders are finished, */

int motion_counter;
int hps;

query_is_on_orders() { return is_on_orders; }
set_is_on_orders(arg) { is_on_orders = arg; }

reset(arg)
{
    object gold, what;
    ::reset(arg);
    if(arg) return;
    set_name("Beano");
    set_race("beano");
    set_alias("xbeano");
    set_short("Beano");
    set_long("This is Beano. It is orange, fuzzy-like, and seems to be made \n"+
    "entirely of light and fuzz. He is intended for levels 3 and under, so\n"+
    "if you fit in that category, kill it with your newbie sword and you'll\n"+
    "(hopefully) get a kicking weapon :) \n");
    set_level(3);
    set_hp(39);
    set_al(0);
    set_wc(6);
    set_ac(4);
    set_chance(1);
    set_spell_dam(4);
    set_spell_mess1("Beano does something to you.");
    set_spell_mess2("Beano ebverflugs you.");
    set_chat_chance(10);
    
    load_chat("Beano quibbles.\n");
    load_chat("Beano goes: wibble.\n");
    load_chat("Beano does something.\n");
    load_chat("Beano goes: Gwak.\n");
    load_chat("Beano goes: Gwak!\n");
    load_chat("Beano goes: woot.\n");
    
    gold = clone_object("obj/money");
    gold->set_money(random(2)+10);
    move_object(gold,this_object());
    what = clone_object("players/mizan/etheriel/items/thingamajig.c");
    move_object(what, this_object());

    is_orders_achieved = 1;

    enable_commands();

    remove_call_out("do_random_move");
    call_out("do_random_move", 1);

    remove_call_out("extra_reset");
    call_out("extra_reset", 1);

}

extra_reset()
{
    /* give ourselves some goods */
    call_out("recharge_shit", 4);
    call_out("recharge_balloon", 8);
}


long()
{
    /* call our super */
    ::long();

    if(this_player() && this_player()->query_name())
    {
        report_message(this_player()->query_name() + " just looked at me.\n");

        /* hit the player who looked at us with a water balloon, if we have one */
        if(balloon && this_player()->query_level() < 20)
        {
            command("pelt " + this_player()->query_real_name());
            report_message("I pelted " + this_player()->query_name() + " with a water balloon.\n");
            remove_call_out("recharge_balloon");
            call_out("recharge_balloon", 50);
        }
    }
}


heart_beat()
{
   int dam;
   int hit_someone;

   object attacker;
   object room;
   object corpse;
   object ob;

   string roomfile;
   string attacker_name;

   /* initialize our variables */
   hit_someone = 0;
   hps = this_object()->query_hp();
   room = environment(this_object());
   attacker = this_object()->query_attack();

   /* init our variables, with dependencies */
   if(room)
   {
       corpse = present("corpse", room);
       roomfile = object_name(room);
   }

   /* do we have orders */
   if(my_orders && !is_orders_achieved)
       follow_orders(my_orders);


   /* call our super */
   ::heart_beat();

   /* loot corpses */
   if(corpse)
   {
       report_message(corpse->short() + " was looted.\n");
       tell_room(room, "Beano takes corpse.\n");
       move_object(corpse, this_object());
   }

   /* pelt players with things */
   if(1 == random(5) && roomfile != "/room/post")
   {
       ob = first_inventory(room);

       while(ob)
       {
           /* if living creature is right, and we feel like it. */
           if(living(ob) &&
              1 == random(2) &&
              !hit_someone &&
              ob != this_object() &&
              ob->query_name() != this_object()->query_name())
           {
               if(ob->query_level() > 19)
               {
                   if(1 == random(3))
                       say("Beano cringes fearfully at the sight of " + ob->query_name() + ".\n");
                       report_message("I am very scared of " + ob->query_name() + "...\n");
               }
               else
               {
                   /* we throw things at players. One at a time.*/
                   if(shit)
                   {
                       if(ob->query_pl_k() || query_ip_number(ob) == "12.217.93.241")
                       {
                           command("fling " + ob->query_real_name());
                           say("Beano grins evilly.\n");
                           report_message("I hit " + ob->query_name() + " with a pile of shit.\n");
                           remove_call_out("recharge_balloon");
                           call_out("recharge_shit", 50 + random(50));
                           hit_someone = 1;
                       }
                   }

                   /* we throw things at players. One at a time. */
                   if(!hit_someone && balloon)
                   {
                       command("pelt " + ob->query_real_name());
                       report_message("I pelted " + ob->query_name() + " with a water balloon.\n");
                       say("Beano grins biggly.\n");
                       remove_call_out("recharge_balloon");
                       call_out("recharge_balloon", 50 + random(20));
                       hit_someone = 1;

                   }
               }
               
           }

           ob = next_inventory(ob);
       }
       hit_someone = 0;
   }
   

   /* attack routines */
   if(attacker)
   {
      attacker_name=attacker->query_real_name();
      if(attacker != travel_attacker)
      {
         report_message("I am being attacked by " + attacker_name + "!\n");
         travel_attacker = attacker;

/*
         if(query_ip_number(attacker_name) == "12.217.93.241")
         {
             report_message("I am in TURBO MODE.\n");
             this_object()->set_wc(100);
         }
         else
             this_object()->set_wc(6);
*/

         if(1 == random(2))
         {
             report_message("Weet! Weet! Trying to run away from " + attacker_name + "!\n");
             say("Beano panics!\n");
             run_away();
         }
         else if (1 == random(3))
         {
             do_emote_attacked();
         }

      }
   }
}


do_emote_attacked()
{
    if(!attacked_emotes)
    {
        attacked_emotes = ({
            "Beano screams wildly!\n",
            "Beano goes: GWAK!\n",
            "Beano squits itself against the ground.\n",
            "Beano squints nervously.\n",
        });
    }

    if(environment())
        tell_room(environment(), attacked_emotes[random(sizeof(attacked_emotes))]);
    report_message("I am under attack and very nervous.\n");
}

do_emote_panicked()
{
    if(!panicked_emotes)
    {
        panicked_emotes = ({
            "Beano wails wildly!\n",
            "Beano goes: Buh!\n",
            "Beano squits itself nervously.\n",
            "Beano screams loudly.\n",
        });
    }

    if(environment())
        tell_room(environment(), panicked_emotes[random(sizeof(panicked_emotes))]);
    report_message("Crap! Crap! Crap!\n");
}

do_random_move()
{
    int n;
    int is_trapped;
    object room;
    object roomroom;

    /* init our travel room */
    if(!travel_room)
        travel_room = environment(this_object());

    /* we see if we are trapped inside a container - like a bag */
    is_trapped = check_trapped_inside_object();

    /* if we are not fighting or stuck inside a washing machine, try moving a direction */
    if(!is_trapped && !this_object()->query_attack())
        do_walk();

    /* we are in a new room. Report it */
    if(environment() && environment() != travel_room)
    {
        report_message("I am now in " + object_name(environment()) + ", MC: " + motion_counter + ".\n");
        travel_room = environment();
        motion_counter = 0;
    }

    /* We have been stuck in the same room for too long. Teleport out. */
    if(motion_counter > 9 && !is_trapped)
        do_teleport_waypoint();

    /* increment our motion counter */
    motion_counter ++;

    /* call our move again */
    remove_call_out("do_random_move");
    call_out("do_random_move", 3);
}


/* we teleport one direction */
do_teleport_waypoint()
{
    object room;

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
        });
    }

    room = find_object(waypoints[random(sizeof(waypoints))]);
    
    report_message("I am teleporting to " + object_name(room) + ".\n");
    say("Beano disappears in a puff of smoke.\n");
    move_object(this_object(), room);
    tell_room(room, "Beano fades into view.\n");
    motion_counter = 0;

}

/* we walk one step. */
do_walk()
{
    if(!directions)
    {
        directions = ({
            "up",
            "down",
            "out",
            "east",
            "leave",
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

    command(directions[random(sizeof(directions))], this_object());
}


/*********************************************
 *
 * O R D E R S
 *
 *********************************************/

/* meant to be called internally. The argument given are the orders we
 * have been passed along.
 */
follow_orders(arg)
{
    switch(arg)
    {
    case ORDERS_KILL_OBJECT:
        return do_orders_kill_object();
        break;
    case ORDERS_KILL_BY_NAME:
        return do_orders_kill_by_name();
        break;
    default:
        my_orders = 0;
        break;
    }
}


/* we can be told to attack other objects
 *
 * Note that these orders do not ever 'finish'. The monster
 * will keep trying to kill objects named 'X' until it dies.
 *
 */
do_orders_kill_by_name()
{
    object room;
    object victim;
    object att;
    object victim_room;

    /* remember that we are being given a string name to attack */
    att = this_object()->query_attack();

    room = environment(this_object());
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
            say(short() + " goes on the attack!\n");
            report_message(HIW + "Following orders to kill anything named " + orders_objective_string + "!" + NORM + "\n");
            this_object()->attack_object(victim);
            report_message("I have attacked " + victim->query_name() + "!!\n");
            return 1;
        }
        else return 0;
    }
    return 0;
}

do_orders_kill_object()
{

}

do_orders_holdposition()
{
}

do_orders_loiter()
{
}


receive_orders(code, data)
{
    /* once we are given orders, we take them. No questions asked. */

/*
    orders_objective_object = 0;
    orders_objective_string = "";
    orders_objective_int = 0;
*/
    is_orders_achieved = 0;
    my_orders = code;
    is_on_orders = 1;

    switch(code)
    {
    case ORDERS_KILL_OBJECT:
        orders_objective_object = data;
        report_message("I am ordered to kill object '" + data->short() + "'\n");
        break;
    case ORDERS_KILL_BY_NAME:
        orders_objective_string = data;
        report_message("I am ordered to kill anything named '" + data + "'\n");
        break;
    default:
        report_message("What do you want? I'm just a fucking BEANO!\n");
        return 0;
        break;
    }
}

/*********************************************
 *
 * O T H E R  M E T H O D S
 *
 *********************************************/

query_hbflag() { return "hbstayon"; }

/* we return 1 if we are inside something we are not supposed to move from */
check_trapped_inside_object()
{
    object room;
    object roomroom;

    room = environment(this_object());
    if(room) roomroom = environment(room);

    /* we are stuck inside boltar's washing machine */
    if(room && room->id("washing machine"))
    {
        if(roomroom && 1 == random(10))
        {
            tell_room(roomroom, "You see a Beano struggling helplessly inside the washing machine.\n");
            report_message("I'm stuck inside a washing machine! Shit!\n");
            do_emote_panicked();
        }
        return 1;
    }

    /* we are stuck inside boltar's stove */
    if(room && room->id("stove"))
    {
        if(roomroom && 1 == random(10))
        {
            tell_room(roomroom, "You see a Beano stuck inside a stove.\n");
            report_message("I'm stuck inside a stove! Aooooooo!\n");
            do_emote_panicked();
        }
        return 1;
    }

    /* we are stuck inside a bag */
    else if(room && room->id("bag"))
    {
        if(roomroom && 1 == random(3))
        {
            tell_room(roomroom, "You see a Beano struggling helplessly a bag.\n");
            report_message("I'm stuck inside a bag! Buh!\n");
            do_emote_panicked();
        }
        return 1;
    }

    return 0;

}

hit_player(arg)
{
    if(arg) report_message("Ow! Ow! Ow! I just took " + arg + " damage from " + this_player()->query_name() + "!\n");
    
    if(arg && arg > 60)
    {

        ::hit_player(60);
    }
    else 
        ::hit_player(arg);
}

report_message(arg)
{
    object ob;
    object room;
    room = find_object("/players/mizan/core/02h/room02.c");

    if(room)
        tell_room(room, HIY + "Beano" + NORM + " reports from the field: " + arg);
}

recharge_shit()
{
    if(shit) return;

    shit = clone_object("/players/mizan/etheriel/items/shit.c");
    move_object(shit, this_object());
    report_message("I received new shit! Woot!\n");
    say("A pile of shit materializes into Beano's inventory.\n");
}
    

recharge_balloon()
{
    if(balloon) return;

    balloon = clone_object("/players/mizan/etheriel/items/water-balloon.c");
    move_object(balloon, this_object());
    report_message("I received a new water balloon! Gwak!\n");
    say(balloon->short() + " materializes into Beano's inventory.\n");
}


death()
{
    report_message("Buh! I died...\n");
    ::death();
}

/* eof */
