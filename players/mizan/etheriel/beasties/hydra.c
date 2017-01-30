inherit "/players/mizan/core/monster.c";
int head1,head2,head3,head4,head5;
int hps;
string directions;
string waypoints;
object travel_room;
object travel_attacker;
int motion_counter;


/* Based pretty much on Sweetness' code.
 * Pretty much all of it, that is.
 *
 * This stuff is credited elsewhere though.
 */

reset(arg)
{
   object weapon;
   object gold;
   ::reset(arg);
   if(arg) return;
   set_name("hydra");
   set_race("dragon");
   set_alias("hydra");
   set_short("Hydra");
   set_level(29);
   set_hp(5000);
   set_al(-1000);
   set_wc(85);
   set_ac(40);
   gold=clone_object("obj/money");
   gold->set_money(random(6000)+46000);
   move_object(gold,this_object());
   enable_commands();
   
   remove_call_out("make_random_move");
   call_out("make_random_move", 1);
}

long()
{
    write("This is a five-headed Hydra.\n"+
          "Luckily, it is not aggressive and merely wants to explore the MUD.\n"+
          "Normally it would want to be killing players but today it is a tourist.\n"+
          "Still. You really should just leave right now.\n" + 
          extra_long());

    if(this_player() && this_player()->query_name())
        report_message(this_player()->query_name() + " just looked at me.\n");
}


heart_beat()
{
   int dam;
   object attacker;
   object room;
   string attacker_name;

   hps=this_object()->query_hp();
   room=environment(this_object());
   attacker=this_object()->query_attack();

   ::heart_beat();

   if(attacker)
   {
      attacker_name=attacker->query_real_name();
      if(attacker != travel_attacker)
      {
         report_message("I am now attacking " + attacker_name + ".\n");
         travel_attacker = attacker;
      }

      if(present(attacker_name,environment(this_object()))){
         if(head1 == 0)
         {
            if(1 == random(2))
            {
               tell_room(room,"The head of electricity slams a lightning bolt at "+capitalize(attacker_name)+".\n");
               dam=random(35);
               attacker->hit_player(dam);
            }
            else 
            {
               tell_room(room,"The head of electricity missed "+capitalize(attacker_name)+".\n");
            }
            if(this_object()->query_hp() < 4000)
            {
               head1 = 1;
               tell_room(room,"The head of electricity is destroyed!\n");
               attacker->add_exp(30000);
            }
         }

         if(head2 == 0)
         {
            if(1 == random(3))
            {
               tell_room(room,"The head of frost shoots a freezing blast at "+capitalize(attacker_name)+".\n");
               dam=random(36);
               attacker->hit_player(dam);
            }
            else 
            {
               tell_room(room,"The head of frost missed "+capitalize(attacker_name)+".\n");
            }
            if(this_object()->query_hp() < 3000)
            {
               head2 = 1;
               tell_room(room,"The head of frost is destroyed!\n");
               attacker->add_exp(40000);
            }
         }

         if(head3 == 0)
         {
            if(1 == random(3))
            {
               tell_room(room,"The head of acid belches boiling acid at "+capitalize(attacker_name)+".\n");
               dam=random(40);
               attacker->hit_player(dam);
            }
            else 
            {
               tell_room(room,"The head of acid missed "+capitalize(attacker_name)+".\n");
            }
            if(this_object()->query_hp() < 2000)
            {
               head3 = 1;
               tell_room(room,"The head of acid is destroyed!\n");
               attacker->add_exp(50000);
            }
         }

         if(head4 == 0)
         {
            if(1 == random(2))
            {
               tell_room(room,"The head of fire blows a blast of flame at "+capitalize(attacker_name)+".\n");
               dam=random(25);
               attacker->hit_player(dam);
            }
            else 
            {
               tell_room(room,"The head of fire missed "+capitalize(attacker_name)+".\n");
            }
            if(this_object()->query_hp() < 1000)
            {
               head4 = 1;
               tell_room(room,"The head of fire is destroyed!\n");
               attacker->add_exp(20000);
            }
         }

         if(head5 == 0)
         {
            if(1 == random(2))
            {
               tell_room(room,"The head of death spews forth rotten corpses at "+capitalize(attacker_name)+".\n");
               dam=random(45);
               attacker->hit_player(dam);
            }
            else 
            {
               tell_room(room,"The head of death missed "+capitalize(attacker_name)+".\n");
            }
         }
      }
   }
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
            tell_room(environment(), "Hydra disappears in a puff of smoke.\n");
            move_object(this_object(), room);
            tell_room(room, "Hydra fades into view.\n");
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

    ob = find_player("mizan");
    if(ob)
        tell_object(ob, "Hydra tells you: " + arg);
}


extra_long()
{
    string desc1,desc2,desc3,desc4,desc5;
    string temp;
    int hp;

    hp=this_object()->query_hp();
    desc1 = "in good shape.";
    desc2 = "in good shape.";
    desc3 = "in good shape.";
    desc4 = "in good shape.";
    desc5 = "in good shape.";

    if(hp < 5000){desc1 = "slightly hurt.";}
    if(hp < 4500){desc1 = "somewhat hurt.";}
    if(hp < 4250){desc1 = "in bad shape.";}
    if(hp < 4000){desc1 = "dead."; desc2 = "slightly hurt.";}
    if(hp < 3500){desc2 = "somewhat hurt.";}
    if(hp < 3250){desc2 = "in bad shape.";}
    if(hp < 3000){desc2 = "dead."; desc3 = "slightly hurt.";}
    if(hp < 2500){desc3 = "somewhat hurt.";}
    if(hp < 2250){desc3 = "in bad shape.";}
    if(hp < 2000){desc3 = "dead."; desc4 = "slightly hurt.";}
    if(hp < 1500){desc4 = "somewhat hurt.";}
    if(hp < 1250){desc4 = "in bad shape.";}
    if(hp < 1000){desc4 = "dead"; desc5 = "slightly hurt.";}
    if(hp <  500){desc5 = "somewhat hurt.";}
    if(hp <  250){desc5 = "somewhat hurt.";}
    if(hp <  100){desc5 = "in very bad shape.";}

    temp = "The head of electricity is " + desc1 + "\n" +
          "The head of frost is " + desc2 + "\n" +
          "The head of acid is " + desc3 + "\n" +
          "The head of fire is " + desc4 + "\n" +
          "The head of death is " + desc5 + "\n";

    return temp;
}
