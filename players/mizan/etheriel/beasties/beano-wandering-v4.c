inherit "/players/mizan/core/monster.c";
string directions;
string waypoints;
string hit_player_messages;
string attacked_emotes;
string panicked_emotes;

object travel_room;
object travel_attacker;
object shit;
object balloon;

int motion_counter;
int hps;

status is_invisible;


reset(arg)
{
    object gold, what;
    ::reset(arg);
    if(arg) return;
    set_name("Beano");
    set_race("beano");
    set_alias("beano");
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
    gold=clone_object("obj/money");
    gold->set_money(random(2)+10);
    move_object(gold,this_object());
    what=clone_object("players/mizan/etheriel/items/thingamajig.c");
    move_object(what, this_object());

    is_invisible = 0;

    enable_commands();

    remove_call_out("make_random_move");
    call_out("make_random_move", 1);

    remove_call_out("extra_reset");
    call_out("extra_reset", 1);

}

extra_reset()
{
    call_out("recharge_shit", 1);
    call_out("recharge_balloon", 2);
}


long()
{
    ::long();

    if(this_player() && this_player()->query_name())
    {
        report_message(this_player()->query_name() + " just looked at me.\n");

        if(balloon)
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

   
   if(room)
   {
       corpse = present("corpse", room);
       roomfile = object_name(room);
   }


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
                   /* we throw things at players */
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

                   if(balloon)
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


on_kill()
{
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

make_random_move()
{
    int n;
    object room;
    object roomroom;

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


    /* init our travel room */
    if(!travel_room)
        travel_room = environment(this_object());


    /* if we are not fighting or stuck inside a washing machine, try moving a direction */
    if(is_inside_filename("players/boltar/things/washingmachine"))
    {
        if(1 == random(3))
        {
            roomroom = environment(room);
            if(roomroom)
                tell_room(roomroom, "You see a Beano struggling helplessly inside the washing machine.\n");
            report_message("I'm stuck inside a washing machine! Shit!\n");
            do_emote_panicked();
        }
    }
    else if(!this_object()->query_attack())
    {
        command(directions[random(sizeof(directions))], this_object());
    }

    /* we are in a new room. Report it */
    if(environment() && environment() != travel_room)
    {
        report_message("I am now in " + object_name(environment()) + ", MC: " + motion_counter + ".\n");
        travel_room = environment();
        motion_counter = 0;
    }

    /* We have been stuck in the same room for too long. Teleport out. */
    if(motion_counter > 9 && !is_inside_filename("players/boltar/things/washingmachine"))
        teleport_waypoint();

    motion_counter ++;

    remove_call_out("make_random_move");
    call_out("make_random_move", 3);
}

report_message(arg)
{
    object ob;
    object room;
    room = find_object("/players/mizan/core/02h/room02.c");

    if(room)
        tell_room(room, "Beano reports from the field: " + arg);
}

teleport_waypoint()
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

is_inside_filename(arg)
{
    string objfile;
    string temp;

    if(!environment(this_object())) return 0;

    temp = object_name(environment(this_object()));

    if(sscanf("%s#", objfile) == 1)
    {
        if(arg == objfile)
            return 1;
        else
            return 0;
    }
    else
    {
        if(arg == temp)
            return 1;
        else
            return 0;
    }

}
