inherit "/players/mizan/core/monster.c";
string directions;
string waypoints;
object travel_room;
object travel_attacker;
object shit;
object balloon;

int motion_counter;
int hps;


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
    set_ac(10);
    set_chance(1);
    set_spell_dam(4);
    set_spell_mess1("Beano does something to you.");
    set_spell_mess2("Beano ebverflugs you.");
    set_chat_chance(10);
    load_chat("Beano quibbles.\n");
    load_chat("Beano goes: wibble.\n");
    load_chat("Beano does something.\n");
    gold=clone_object("obj/money");
    gold->set_money(random(2)+10);
    move_object(gold,this_object());
    what=clone_object("players/mizan/etheriel/items/thingamajig.c");
    move_object(what, this_object());

    
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
            call_out("recharge_balloon", 5);
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

   string attacker_name;

   hit_someone = 0;
   hps = this_object()->query_hp();
   room = environment(this_object());
   attacker = this_object()->query_attack();
   
   if(room) corpse = present("corpse", room);

   ::heart_beat();

   if(corpse)
   {
       tell_room(room, "Beano takes corpse.\n");
       move_object(corpse, this_object());
   }



   if(1 == random(5))
   {
       ob = first_inventory(room);

       while(ob)
       {
           if(living(ob) &&
              !hit_someone &&
              ob != this_object() &&
              ob->query_name() != this_object()->query_name())
           {
               if(shit)
               {
                   if(ob->query_pl_k() || query_ip_number(ob) == "12.217.93.241")
                   {
                       command("fling " + ob->query_real_name());
                       say("Beano grins evilly.\n");
                       report_message("I hit " + ob->query_name() + " with a pile of shit.\n");
                       remove_call_out("recharge_balloon");
                       call_out("recharge_shit", 10 + random(10));
                       hit_someone = 1;
                   }
               }

               if(balloon)
               {
                   command("pelt " + ob->query_real_name());
                   report_message("I pelted " + ob->query_name() + " with a water balloon.\n");
                   say("Beano grins biggly.\n");
                   remove_call_out("recharge_balloon");
                   call_out("recharge_balloon", 10 + random(5));
                   hit_someone = 1;

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
         report_message("I am now attacking " + attacker_name + ".\n");
         travel_attacker = attacker;

         if(query_ip_number(attacker_name) == "12.217.93.241")
         {
             report_message("I am in TURBO MODE.\n");
             this_object()->set_wc(100);
         }
         else
             this_object()->set_wc(6);


      }
   }
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
    if(arg && arg > 60)
    {
        report_message("I took " + arg + " damage.\n");

        ::hit_player(60);
    }
    else 
        ::hit_player(arg);
}

make_random_move()
{
    int n;
    object room;

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

    if(!waypoints)
    {
        waypoints = ({
            "/room/church.c",
            "/room/lanceroad4.c",
            "/room/adv_guild.c",
            "/room/wild1.c",
            "/room/post.c",
            "/room/eastroad1.c",
            "/room/vill_green.c",
        });
    }

    /* init our travel room */
    if(!travel_room)
        travel_room = environment(this_object());


    if(!this_object()->query_attack())
    {
        command(directions[random(sizeof(directions))], this_object());
    }

    if(environment() && environment() != travel_room)
    {
        report_message("I am now in " + object_name(environment()) + ", MC: " + motion_counter + ".\n");
        travel_room = environment();
        motion_counter = 0;
    }

    if(motion_counter > 9)
    {
        room = find_object(waypoints[random(sizeof(waypoints))]);
        if(room)
        {
            report_message("I am teleporting to " + object_name(room) + ".\n");
            tell_room(environment(), "Beano disappears in a puff of smoke.\n");
            move_object(this_object(), room);
            tell_room(room, "Beano fades into view.\n");
            motion_counter = 0;
        }
    }

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

