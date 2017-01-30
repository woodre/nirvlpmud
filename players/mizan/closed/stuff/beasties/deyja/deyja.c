inherit "obj/monster";

#define CREATOR      "mizan"
#define HYDRANAME    "Deyja"
#define GUILD_NAME   "polymorph"
#define NUM_HEADS    5

#define HOMEBASE              "/players/mizan/etheriel/ROOMS/tempest.c"
#define BASEPATH              "/players/mizan/closed/stuff/beasties/deyja/"
#define WEAPON_TREASURE       BASEPATH + "sword_etheriel.c"
#define ARMOR_STD_TREASURE    BASEPATH + "t_armor.c"
#define ARMOR_RING_TREASURE   BASEPATH + "t_ring.c"
#define ARMOR_HELM_TREASURE   BASEPATH + "t_helm.c"
#define ARMOR_BOOT_TREASURE   BASEPATH + "t_boots.c"
#define ARMOR_MISC_TREASURE   BASEPATH + "t_misc.c"
#define ARMOR_SHLD_TREASURE   BASEPATH + "t_shield.c"
#define ARMOR_AMUL_TREASURE   BASEPATH + "t_amulet.c"

#define ACTION_LOG            "/players/mizan/logs/HYDRA" + HYDRANAME

#define TOTAL_HIT_POINTS      15000

int head;          /* the heads of the critter */
int exp_per_head;  /* the exp each head is worth */

string head_short;           /* the string containing short descs for each head */
string head_aprechat;        /* the string containing attack prelude chats */   
string head_apostchat;       /* the string containing attack post chats */   
string head_insult;          /* the string containing attach insults. */
string head_area_attack_pre; /* prelude message in area attacks */
string head_area_attack;     /* the string used in area attacks */
int head_dam_potential;      /* the damage potential each head can do. */

object homebase;
string victim_name;
object the_victim;

reset(arg)
{
   
   /* superclass */
   ::reset(arg);
   
   if(arg) return;

   set_name(lower_case(HYDRANAME));
   set_race("hydra");
   set_alias("Mi606961");
   set_short(HYDRANAME + " the hydra");
   set_level(96);
   set_hp(TOTAL_HIT_POINTS);
   set_al(-1000);
   set_wc(64);
   set_ac(16);
/*
   set_aggressive(1);
 */

   move_object(this_object(), HOMEBASE);

   homebase = environment(this_object());

   move_object(clone_object(WEAPON_TREASURE), this_object());

   init_variables();

}

/**
 * Our long description.
 *
 */
long()
{
   int i;       /* a counter */
   int j;       /* the hitpoint value of each head */
   int hmax;    /* maximum hitpoints for each head */


   write("Standing before you is a hydra named Deyja.\n"+
      "She is about twenty meters tall, and is the youngest offspring of\n"+
      "the unholy tryst of Pulsar and the mad sorceress Ephidrena.\n"+
      "It would be in your _best_ interests to get the hell out of here\n"+
      "and as far away from as you can... NOW!!!\n");

   hmax = (TOTAL_HIT_POINTS / NUM_HEADS);

   for(i = 0; i < NUM_HEADS; i ++)
   {
      /* cycle through each head and display vital info. */
      write(head_short[i] + " ");
   
      j = query_real_hp() - (hmax * (head[i]) );

      if(j < 0)
         write("is dead.\n");
      else if(j < (hmax / 10))
         write("is in very bad shape.\n");
      else if(j < (hmax / 5))
         write("is in bad shape.\n");
      else if(j < (hmax / 2))
         write("is somewhat hurt.\n");
      else if(j < (hmax - 100))
         write("is slightly hurt.\n");
      else
         write("is in good shape.\n");
   }
}

/**
 * This function initializes the variables this object uses.
 *
 */
init_variables()
{
   int i;

   if(!head)
   {
      head = allocate(NUM_HEADS);

      /* toggle alive values for each head */
      for(i = 0; i < NUM_HEADS; i ++)
      {
         head[i] = 1;
      }
   }

   head_short = 
      ({
         "The red hydra head",
         "The blue hydra head",
         "The green hydra head",
         "The gold hydra head",
         "The black hydra head"
      });

   head_aprechat =
      ({
         "smashes",
         "batters",
         "pummels",
         "beats",
         "spits acid on",
         "tosses a lightning bolt at",
         "pummels",
         "brutalizes",
         "martyrs",
         "bashes",
         "tosses",
         "massacres",
      });

   head_apostchat =
      ({
         "with a bone-shattering crunch.",
         "to a pile of molten slime.",
         "into a fine red mist.",
         "into a cloud of blood sausages.",
         "leaving a wicked third-degree burn.",
         "with a devastating POP!",
         "with simple ease.",
         "into a wave of fist-sized chunks.",
         "into a hopeless cause.",
         "clear across the room!",
         "around like a chew-toy.",
         "into a lump of ground beef.",
      });

   head_insult =
      ({
         "snickers at your utter incompetence.",
         "laughs at your total lack of an offense.",
         "snickers at your total and complete failure of an attack.",
         "thunders: You call that an attack?",
         "laughs: You fuckwits.",
         "sneers: You worthless suckshit.",
         "sneers mirthlessly at you.",
         "writes you off as a dead target.",
         "considers you a mere plaything.",
         "thunders: You worthless little shitballs... Prepare to die.",
         "cackles: You are utterly hopeless.",
         "ponders: I see that you won't be living much longer. Pity.",
         "exclaims: Be still, insect.",
         "says: Are you still here? You may die then.",
         "tells you: Turn back. You will lose.",
         "snickers at you.",
         "groks at your unworthiness.",
         "ponders your stupidity this day.",
         "grins biggly, anticipating yet another quick blick.",
         "wonders how many seconds this one will last.",
         "fondles your mind.",
         "laughs at you.",
         "grins evilly.",
         "smiles wickedly, sensing your feeling of impending doom.",
         "shrugs off your desperate and valiant, but pitifully weak attack.",
         "says: Pitiful beasts.",
      });

   head_area_attack_pre =
      ({
         "breathes forth a column of poison gas!",
         "belches a wide funnel of fire!",
         "spews out a cloud of toxic gas!",
         "vents out a channel of freezing spewage!",
         "sprays forth a barrage of ice chunks!",
         "spews out a raging firestorm!",
         "spits forth a flood of acid!",
         "belches a raging cloud of lava!",
      });

   head_area_attack = 
      ({
         "falls and sputters, choking on the gas!",
         "burns painfully to a searing crisp!",
         "screams in agonizing pain!",
         "collapses and freezes in an instant!",
         "is impaled by an ice shard!",
         "explodes from the searing heat!",
         "corrodes and melts to a crisp!",
         "is critically burned from the lava!",
      });

   head_dam_potential = ({ 80, 50, 40, 80, 120 });
   
   exp_per_head = ({ 755000, 554000, 457000, 858000, 1226000 });

}

init()
{
   object room;
   object ob;

   room = environment(this_object());
   ob = this_player();

   if(ob &&
      living(ob) &&
      1 == random(3) &&
      room &&
      room == homebase)
   {
      /* random chance we just start attacking outright. */
      ::attack_object(this_player());
   }

   add_action("do_block_dest","dest");
   add_action("do_block_dest","destruct");

   add_action("do_block", "mi");
   add_action("do_block", "missile");
   add_action("do_block", "sh");
   add_action("do_block", "shock");
   add_action("do_block", "fi");
   add_action("do_block", "fireball");
   add_action("do_block", "so");
   add_action("do_block", "sonic");

   add_action("do_retaliate", "kiss");
   add_action("do_retaliate", "fondle");
   add_action("do_retaliate", "punch");
   add_action("do_retaliate", "kick");
   add_action("do_retaliate", "grope");
   add_action("do_retaliate", "punt");
   add_action("do_retaliate", "smack");
   add_action("do_retaliate", "slap");
   add_action("do_retaliate", "laugh");
   add_action("do_retaliate", "poke");
   add_action("do_retaliate", "lick");
   add_action("do_retaliate", "hug");
   add_action("do_retaliate", "french");
   add_action("do_retaliate", "dkiss");
   add_action("do_retaliate", "sex");
   add_action("do_retaliate", "noogie");
   add_action("do_retaliate", "snicker");
   add_action("do_retaliate", "fart");
}

/**
 * The heartbeat of the monster.
 *
 */
heart_beat()
{
   object att;          /* our attacker */
   object room;         /* the room that we are in */
   int i;               /* our counter var, used to cycle through heads. */
   int j;               /* a random number */

   /* superclass */
   ::heart_beat();

   /* get our attacker */
   att = this_object()->query_attack();
   
   if(att)
   {
      /* yay! one exists, now get the room */
      room = environment(att);
      victim_name = att->query_name();
      the_victim = att;

      if(room && room == environment(this_object())) 
      {
         /* roor, its in the same room as us.
          * we hurt it now.
          */
         
         for(i = 0; i < NUM_HEADS; i ++)
         {
            if(head[i])
            {
               j = random(11);
               
               if(j == 1)
                  head_area_attack(i, room);
               else
                  head_single_attack(i, att);
               if(att->query_level() > 19)
                  head_wizard_attack(i, att);
            }

/*
            // we check on the conditions of each head now 
            if(query_real_hp() < (TOTAL_HIT_POINTS / NUM_HEADS) * head[i])
            {
               // the head dies! *sob*
               head[i] = 0;
               head_dies(i);
            }
 */

         }
      }
   }
}

/**
 * This function is the single attack mode of each head.
 *
 */
head_single_attack(arg, who)
{
   int i;         /* the number of the head in array */
   int j;          /* a random number */
   int dam;        /* the potential dam we will do */
   int r1;         /* a random number, which attack pre chat we use */
   int r2;         /* a random number, which attack post chat we use */
   int r3;         /* a random number, which insult we use */
   object ob;      /* the victim */
   string obname;  /* the victim's name */

   j = random(6);
   ob = who;
   i = arg;
   
   if(!ob || ob->query_ghost())
      return;

   obname = ob->query_name();
   
   if(j == 1)
   {
      /* not very scientific, but we missed our attack. */
      say(head_short[i] + " missed " + obname + ".\n");
      return;
   }
   else
   {
      /* otherwise we land a hit here */
      dam = random(head_dam_potential[i]);
      r1 = random(sizeof(head_aprechat));
      r2 = random(sizeof(head_apostchat));

      /* a chat */
      say(head_short[i] + " " + head_aprechat[r1] + " " +
         ob->query_name() + " " + head_apostchat[r2] + "\n");

      /* maybe an insult */
      j = random(12);
      if(j == 1)
      {
         r3 = random(sizeof(head_insult));
         say(head_short[i] + " " + head_insult[r3] + "\n");
      }

      /* ok, now we hit em */
      ob->hit_player(dam);
   }
}

/**
 * This function is the area attack mode of each head.
 *
 */
head_area_attack(arg, room)
{
   int i;        /* the number of the head in array */
   int j;        /* a random number */
   int k;        /* another random number, damage inflicted */
   object ob;    /* the victim (cycled through) */
   object oc;    /* the victim (cycled through) */

   i = arg;
   j = random(sizeof(head_area_attack));
   k = random(50);
   ob = first_inventory(room);

   /* the prelude */
   say(head_short[i] + " " + head_area_attack_pre[j] + "\n");

   while(ob)
   {
      oc = ob;
      ob = next_inventory(ob);

      if(oc && living(oc) && oc != this_object())
      {
         /* each hit registered here */
         say(oc->query_name() + " " + head_area_attack[j] + "\n");
         oc->hit_player(k);
      }
   }
}

/**
 * Attacks wizzes, yup.
 *
 *
 */
head_wizard_attack(arg, who)
{
   int h_num;    /* the number of the head in array */
   object ob;    /* the victim */

   if(!ob) return;

   ob->destruct_inventory();
   ob->set_pretitle("[Hammered by Deyja]");
   ob->set_title("got " + ob->query_possessive() + " was defeated by " + HYDRANAME);
   ob->save_me();

   ob->destruct_inventory();
   destruct(ob);
}

/**
 * The head dies here, we just give a little message.
 *
 *
 */
static head_dies(arg)
{
   int i;
   i = arg;

   say(head_short[i] + " withers and dies!\n");
   say(head_short[i] + " is defeated!\n");
}

/**
 * This blocks certain commands.
 *
 */
do_block()
{
   write("You fail.\n");
   return 1;
}

/**
 * This function blocks commands- AND gives a certain punch back.
 *
 */
do_retaliate(str) 
{
   if(!str || !id(str)) return 0;

   write("You fail. Miserably.\n");
   ::attack_object(this_player());
   return 1;
}

/**
 * This is an overload of the original living object attack_object(),
 * which is built to protect against hitting ourselves.
 *
 */
attack_object(arg) 
{
   object ob;
   ob = arg;

   if(ob == this_object()) 
   {
      /* we penalize very hard for someone trying to force us to
       * attack ourselves. 
       */
      ::attack_object(this_player());
      this_player()->hit_player(9000);
   }
   else if(this_player() == this_object())
   {
      /* else we ordered the attack, and it is ok */
      ::attack_object(ob);
   }
   else 
     ::attack_object(this_player());
}

/**
 * Returns the attacker's guild name. Usually they are the one we
 * are concerned with anyway.
 *
 */
query_guild_name() 
{
   object ob;
   
   ob = this_object()->query_attack();
   if(ob)
   {
      /* chances are, ob is the one running away from us. */
      return ob->query_guild_name();
   }
   else return GUILD_NAME;
}

/**
 * We do not return the true hitpoint value.
 *
 */
query_mhp() 
{
   write("UNKNOWN ");
   return 1;
}

/**
 * We do not return the true sp value either.
 *
 */
query_sp() { return 666666; }

/**
 * Yup, hitpoints too.
 *
 */
query_hp() { return 1; }

/**
 * This is our real hitpoints.
 *
 */
query_real_hp() { return hit_point; }

/**
 * This function blocks stats from wizzes. I guess this is a dinosaur
 * thing to do, back in the days when we tried to hide numbers from
 * players after there were too many bogus items in circulation which
 * gave cold hard stats.
 *
 */
show_stats() 
{
   object ob;
   ob = this_player();

   if(ob && ob->query_real_name() == CREATOR) 
      return ::show_stats();
   else 
      write("Statistics are irrelevant.\n");

   return 1;
}

/**
 * We don't wimpy.
 *
 */
run_away() { return 0; }

/**
 * We protect ourselves from excessive hits.
 *
 *
 */
hit_player(arg) 
{
   object ob;
   int det;

   ob = this_player();
   det = arg;

   if(det > 50) 
   {
      write_file(ACTION_LOG,
         (ob->query_real_name()) + ", " +
         (ob->query_level()) + " hit " + HYDRANAME + 
         " [" + det + "] hitpoints on " + ctime() + "\n");
      det = 50;
   }
   
   if(1 == random(12)) 
   {
      write(HYDRANAME + " deflects your blow.\n");
      say(HYDRANAME + " deflects " + (this_player()->query_name()) + "'s attack.\n");
      return;
   }

   ::hit_player(det);
}

/**
 * We protect ourselves from negative heal self. 
 *
 */
heal_self(n) 
{
   if(n < -1) return 0;
   ::heal_self(n);
}

/**
 * All too often, a wiz has tried to dest us.
 *
 *
 */
do_block_dest(str) 
{
   object ob;
   ob = this_player();

   if(!str) return 0;

   if(id(str) && (ob->query_level()) > 999) 
   {
      destruct(this_object());
      return 1;
   }
   else if(ob->query_level() > 19)
   {
      /* not us... */
      if(!id(str)) return 0;

      write_file(ACTION_LOG, capitalize(ob->query_real_name())+
      ", level ["+ (ob->query_level()) + "] tried desting at " + ctime() + ".\n");

      write("Nope!\n");
      shout(short() + " shouts: "+capitalize(ob->query_real_name())+" is a genuine fuckwit.\n");
      shout(short() + " shouts: Silly wizard. Dests are for kids.\n");
      return 1;
   }
   else return 0;
}

/**
 * This we use to track players fleeing in the jello
 *
 *
 */

catch_tell(str) 
{
   string a, b, c;       /* temp pieces of the catch tell */
   object ob, att;       /* this player, and attacker */

   ob = this_player();
   att = this_object()->query_attack();

   if(!ob) return 1;
   if(att) 
   {
      /* scan for regular leave msgs */
      if(sscanf(str, "%s leaves %s.", a, b) == 2) 
      {
         if(b != "up" || b != "wimpy") 
         {
            tell_object(att,
               this_object()->query_name() + " tracks you.\n");
            
            call_out("track_player", random(3), b);
         }
      }
   }

   if(sscanf(str, "%s tells you: %s", a, b) == 2) 
   {
      /* if someone tells us something, we bring them to us, and then
       * have a whacking fest
       */
      if(find_player(a) && 1 == random(3))
         call_out("bring_player", random(3), a);
   }
}

/**
 * This function follows a player around in the jello.
 *
 */
track_player(str) 
{
   object victim;
   object room;

   room = environment(this_object());
   
   if(!homebase || !room) return;

   call_other("players/mizan/closed/LiquidRoomDM.c","bleat",
      "(bleat) You feel a distant rumble as " +
      HYDRANAME + " moves to destination " + str + "!!!\n");

   say(HYDRANAME + " fades from view.\n");
   
   /* to be safe, we load the room first */
   call_other("/players/mizan/etheriel/ROOMS/" + str, "???");
   move_object(this_object(), "/players/mizan/etheriel/ROOMS/" + str);
   
   say(HYDRANAME + " fades into view.\n");

   if(victim_name)
      victim = present(victim_name, room);

   if(victim)
      this_object()->attack_object(victim);

   if(the_victim)
      this_object()->attack_object(the_victim);

   call_out("return_home", 15);
}


return_home() 
{
   object victim;
   object room;

   room = environment(this_object());
   
   if(!homebase || !room) return;
   
   if(victim_name)
      victim = present(victim_name, room);

   if(victim)
      this_object()->attack_object(victim);

   if(the_victim)
      this_object()->attack_object(the_victim);

   call_other("players/mizan/closed/LiquidRoomDM.c","bleat",
      "(bleat) You feel a distant rumble as " +
      HYDRANAME + " moves to destination back home...\n");

   say(HYDRANAME + " fades from view.\n");
   
   move_object(this_object(), homebase);
   
   say(HYDRANAME + " fades into view.\n");

}

/**
 * This function we use to bring a player to us.
 * and then pound the crap out of it.
 *
 *
 */
bring_player(str)
{
   object toast;
   toast = find_player(str);

   if(toast && toast->query_level() > 6) 
   {
      tell_room(environment(toast), (toast->query_name()) + " is blown to bits.\n");
      
      say((toast->query_name()) + " is summoned.\n");
      move_object(toast, environment(this_object()));

      ::attack_object(toast);
   }
}

zap_object()
{
   this_player()->destruct_inventory();
   return 1;
}
