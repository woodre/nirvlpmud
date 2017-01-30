inherit "obj/monster";
int head1,head2,head3,head4,head5;
int hps;

/* Based pretty much on Sweetness' code.
 * Pretty much all of the multiheaded part, that is.
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
   set_aggressive(0);
   gold=clone_object("obj/money");
   gold->set_money(random(6000)+46000);
   move_object(gold,this_object());
   enable_commands();

   /* This function is what enables us to randomly move */
   remove_call_out("make_random_move");
   call_out("make_random_move", 1);

   remove_call_out("make_random_theft");
   call_out("make_random_theft", 1);

}

long()
{
write("This is a five-headed Hydra.\nOkay. You really should just leave right now.\n" + extra_long());
}

heart_beat()
{
   int dam;
   object attacker,room;
   string attacker_name;

   hps=this_object()->query_hp();
   room=environment(this_object());
   attacker=this_object()->query_attack();

   ::heart_beat();

   if(attacker)
   {
      attacker_name=attacker->query_real_name();
      if(present(attacker_name,environment(this_object()))){
         if(head1 == 0)
         {
            if(1 == random(2))
            {
               tell_room(room,"The head of electricity slams a lightning bolt at "+capitalize(attacker_name)+".\n");
               dam=random(70);
               attacker->hit_player(dam);
            }
            else 
            {
               tell_room(room,"The head of electricity missed "+capitalize(attacker_name)+".\n");
            }
            if(this_object()->query_hp() < 4000){
               head1 = 1;
               tell_room(room,"The head of electricity is destroyed!\n");
               attacker->add_exp(3000);
            }
         }

         if(head2 == 0)
         {
            if(1 == random(3))
            {
               tell_room(room,"The head of frost shoots a freezing blast at "+capitalize(attacker_name)+".\n");
               dam=random(60);
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
               attacker->add_exp(4000);
            }
         }

         if(head3 == 0)
         {
            if(1 == random(3))
            {
               tell_room(room,"The head of acid belches boiling acid at "+capitalize(attacker_name)+".\n");
               dam=random(85);
               attacker->hit_player(dam);
            }
            else 
            {
               tell_room(room,"The head of acid missed "+capitalize(attacker_name)+".\n");
            }
            if(this_object()->query_hp() < 2000){
               head3 = 1;
               tell_room(room,"The head of acid is destroyed!\n");
               attacker->add_exp(5000);
            }
         }

         if(head4 == 0)
         {
            if(1 == random(2))
            {
               tell_room(room,"The head of fire blows a blast of flame at "+capitalize(attacker_name)+".\n");
               dam=random(90);
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
               attacker->add_exp(5000);
            }
         }

         if(head5 == 0)
         {
            if(1 == random(2))
            {
               tell_room(room,"The head of death spews forth rotten corpses at "+capitalize(attacker_name)+".\n");
               dam=random(95);
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


make_random_move()
{
   int n;
   int is_safe;
   object room;

   if(!this_object()->query_attack())
   {
      n = random(6);
      if (n == 0)
      command("up");
      if (n == 1)
      command("down");
      if (n == 2)
      command("south");
      if (n == 3)
      command("north");
      if (n == 4)
      command("west");
      if (n == 5)
      command("east");
   }
   
   /* This is a fraidy hydra. If it is in a room that isn't filled with sand, it freaks out
    * and returns to its 'spawn point' */
   room = environment(this_object());

   if(room)
   {
      /* ok, why do we use call_other() instead of directly calling the function?
       * its because if the room doesnt have this function we are checking against
       * it wont throw an error */
      is_safe = call_other(room, "is_shit_free");

      if(!is_safe)
      {
         say(query_name() + " disappears in a puff of smoke.\n");
         move_object(this_object(), "/open/mizan/hydra/hydrahome.c");
         say(query_name() + " appears in a puff of smoke.\n");

      }
   }


   remove_call_out("make_random_move");
   call_out("make_random_move", 1);

}


/* We do this periodically */
make_random_theft()
{
   object sucker;
   object heal;

   if(!this_object()->query_attack())
   {
      sucker = get_random_player();

      if(sucker)
      {
         /* todo - make for chance of success or failure of theft */
         heal = pick_random_heal(sucker);
         if(heal)
         {
            move_object(heal, this_object());
            /* correct player's weight */
            sucker->add_weight(-heal->query_weight());

            /* tell room of our bastardliness */
            say( heal->short() + " has been stolen by " + query_name() + " from " + sucker->query_name() + "!\n");
         }
      }
   }
   
   remove_call_out("make_random_theft");
   call_out("make_random_theft", 5);

}

/* This is a function used by the above, to get a random player in the room */
get_random_player()
{
   object victim;
   object room;
   object ob;

   room = environment(this_object());
   if(!room) return 0;

   /* we grab the first object in the room... */
   ob = first_inventory(room);

   /* and cycle through it! */
   while(ob)
   {
      /* a bunch of conditions to pass through it */
      if(ob && 
         living(ob) &&
         ob != this_object() &&  /* must not be ourselves. kinda silly, stealing from self! */
         ob->is_player() &&
         ob->query_level() < 50 &&   /* dont steal from wizzes! */
/* todo: dont let invis players get hit          ob->query_invis() < 1 && */
         1 == random(3))      /* some randomness! */
      {
         victim = ob;
      }
      /* recurse! */
      ob = next_inventory(ob);

   }

   if(victim) return victim;
   else return 0;
}


pick_random_heal(object who)
{
   object ob;
   object result;

   if(!who) return 0;

   ob = first_inventory(who);

   /* recurse through the inventory */
   while(ob)
   {
      if(ob->is_heal())
      {
         result = ob;
         break;
      }

      ob = next_inventory(ob);
   }

   if(result) return result;
   else return 0;
}


/* This just builds a big string of the health for each head */
extra_long()
{
   string desc1,desc2,desc3,desc4,desc5;
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
   return "The head of electricity is "+desc1+"\n"+"The head of frost is "+desc2+"\n"+
"The head of acid is "+desc3+"\n"+"The head of fire is "+desc4+"\n"+"The head of death is "+desc5+"\n";
}
