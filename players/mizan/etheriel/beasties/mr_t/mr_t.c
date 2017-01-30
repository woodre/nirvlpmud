inherit "obj/monster";

#define LIQUID_R "players/mizan/closed/LiquidRoomDM.c"
#define MASTER_R "players/mizan/closed/RandomRoomDM.c"

reset(arg)
{
   object gold,armor,wrench;
   ::reset(arg);

   if(arg) return;
   
   /* descriptions */
   set_name("Mr. T");
   set_race("human");
   set_alias("t");
   set_short("Mr. T");
   set_long("This is Mr. T.\n"+
    "He is an intimidating looking individual, wearing approximately\n"+
   "fifty pounds of gold chains, and a mohawk-like hairdo inspired by the\n"+
   "African Mandinka tribe. He is not the biggest man you have met but he has\n"+
   "easily thrown around those much heavier than himself.\n"+
   "Despite his appearances, Mr. T is a humble man, preferring not to use\n"+
   "his fists at all, and would rather stop trouble from even happening\n"+
   "than getting people all bloodied sorting it out afterwards.\n");
   
   /* vital stats */
   set_level(21);
   set_hp(5600 + random(800));
   set_al(870);
   set_wc(54);
   set_ac(82);
   set_chance(10);
   
   /* combat spell stuff */
   set_spell_dam(40);
   set_spell_mess1("Mr. T throws a jaw... hell-  WALL shattering punch.\n");
   set_spell_mess2("Mr. T boots you in the head!\n");
   
   /* attack chats */
   set_a_chat_chance(10);
   load_a_chat("Mr. T growls: 'You dead, fool!'\n");
   load_a_chat("Mr. T says: 'You betta start fighing suckah, not throwing useless punches like dead man!\n");
   load_a_chat("Mr. T says: 'You gonna be educated suckah! You cant fight, so you gonna learn how ta HURT!\n");
   load_a_chat("Mr. T says: 'You dont goto school, you gonna be a hoodlum you crazy fool!'\n");
   load_a_chat("Mr. T says: 'Its fair that i warn you, my temper is only as short as the hair on my bald head!\n");
   load_a_chat("Mr. T thunders: 'I pity the fool who messes with Mr. T!'\n");
   load_a_chat("Mr. T exclaims: 'You aint got no BALLS, suckah!'\n");
   load_a_chat("Mr. T says: 'You crazy fool! Sit down before I make a mess out of you!'\n");
   load_a_chat("Mr. T says: 'You aint nothing but a crazy fool.'\n");
   load_a_chat("Mr. T says: 'Talk or fight, not both.'");
   load_a_chat("Mr. T says: 'Don't gimme none of that jibber-jabba fool, Fight like a man!'\n");
   load_a_chat("Mr. T says: 'You aint got no respect, fool!'");
   load_a_chat("Mr. T says: 'You talkin finale to your life, suckah!'\n");

   /* chat related stuff */
   set_chat_chance(10);
   load_chat("Mr. T says: 'BE SOMEBODY, or you gonna be somebody's fool.'\n");
   load_chat("Mr. T says: 'Just close your eyes, and imagine POSITIVE images...'\n");
   load_chat("Mr. T says: 'Daydreaming... If you can see it, you can BE it!'\n");
   load_chat("Mr. T says: 'You can't know where you're going if you don't know where you're from...'\n");
   load_chat("Mr. T says: 'I know you Beanos can do it. You gotta have FAITH.'\n");
   load_chat("Mr. T says: 'If you're sick of all the bullying, you gotta help youselves as much as I can help you. Hold ya head up HIGH.'\n");
   load_chat("Mr. T says: 'I dont like violence, but if that's what it means, some suckah is gonna PAY!'\n");
   load_chat("Mr. T says: 'You Beanos gotta have strenfh and confidence in youselves...'\n");
   load_chat("Mr. T says: 'Don't let anyone tell you otherwise, there is greatness in all of you!'\n");
   load_chat("Mr. T says: 'You gotta have the WILL to succeed, Be proud of who you are, Be proud youse are all Beanos!'\n");
   load_chat("Mr. T says: 'Aint nobody gonna hurt you while I'm around. Only GOD protects people better than me.'\n");
   load_chat("Mr. T says: 'What's that? I agree, but you gotta stand tough, look straight.'\n");
   load_chat("Mr. T says: 'Don't let anyone tell you you're a harmless suckah. If they do i'll throw the crazy fool!'\n");

   /* gold */
   gold = clone_object("obj/money");
   gold->set_money(random(5400));
   move_object(gold,this_object());

   /* treasures */
   armor = clone_object("players/mizan/etheriel/beasties/mr_t/mr_t_chains");
   move_object(armor, this_object());

   wrench = clone_object("players/mizan/etheriel/beasties/mr_t/mr_t_wrench");
   move_object(wrench, this_object());

}

heart_beat()
{
   protect_beanos();

   ::heart_beat();
}

protect_beanos()
{
   object room;
   object ob;
   object att;

   room = environment(this_object());
   if(!room) return;

   ob = first_inventory(room);
   
   while(ob)
   {
      att = ob->query_attack();

      if(living(ob) && ob->query_name() == "Beano" 
         && !ob->is_pet() && att)
      {
         /* I pity the fool who messes with the Beanos */
         beat_the_suckah_up(att);

         /* only heal the beanos a tiny bit, in case this is found to
          * be abusable... Then again Beanos dont have many hps.
          */
         ob->heal_self(20);
      }
      ob = next_inventory(ob);
   }
}

beat_the_suckah_up(att)
{
   /* One of three things happens here...
    *
    * the player is thrown clear across the jello (lucky) and takes
    * a boatload of damage...
    *
    * the player is dealt a triple-massacre blow... and takes a boatload
    * of damage...
    *
    * the player is plainly attacked by Mr. T.... and takes a boatload
    * of damage...
    *
    */

   if(!att) return;

   say(random_fact() + "\n");

   if(1 == random(3))
   {
      att->hit_player(random(120));
      /* triple massacre hit */

      this_object()->attack(att);

      att->run_away();
      att->run_away();
      att->run_away();
      att->run_away();

      LIQUID_R->bleat("Mr. T bleats: Come back " + att->query_name() + " and fight like a MAN!\n");

   }
   else if(1 == random(3))
   {
      string the_room;

      the_room = MASTER_R->one_random();

      say("Mr. T dealt a devastating blow to " + att->query_name() + ".\n");
      att->hit_player(random(180));
      /* thrown */

      LIQUID_R->bleat("You cringe as you see the shattered body of " +
         (att->query_name()) + " fly across the ether-muck...\n" +
         "Mr. T bleats: You crazy fool! I pity the fool who messes with me or the Beanos!\n");

      tell_object(att, "You are grabbed by the neck and THROWN by Mr. T!\n");
      att->move_player("thrown by Mr. T#players/mizan/etheriel/ROOMS/" + the_room);

   }
   else
   {
      say("Not a wise thing, attacking Mr. T.\n");

      att->hit_player(random(65));
      /* attacked */

      this_object()->attack(att);
      this_object()->attack(att);
      this_object()->attack(att);
   }
}

/*
 * its not a threat, its a fact :)
 */
string random_fact_string;

random_fact()
{

   if(!random_fact_string)
   {
      random_fact_string =
         ({
            "Mr. T thunders: 'YOU CRAZY FOOL! I PITY THE FOO WHO MESSES WITH THE BEANOS!\n",
            "Mr. T thunders: 'LEAVE THE BEANO ALONE!'\n",
            "Mr. T thunders: 'You DEAD MEAT fool!'\n",
            "Mr. T thunders: 'Your trademark is STUPIDITY suckah!'\n",
            "Mr. T thunders: 'You one crazy fool!\n",
         });
   }

   return random_fact_string[random(sizeof(random_fact_string))];
}

attack_object(ob)
{
   if (ob == this_object()) return;

   ::attack_object(ob);
}
