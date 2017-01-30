#define AMMOTYPE "9.64mm"
#define BURST_POTENTIAL 5000
#define SINGLE_POTENTIAL 500

inherit "obj/weapon";

/**
 *
 * This is one of my new weapons. I didnt daemonize it because
 * I dont feel there will be many more of these made in the future.
 *
 * There are three power settings:
 *
 *    Single shot
 *    3 round burst
 *    Full auto
 *
 *
 * Drawbacks:
 *
 *    requires ammunition in the form of clips.
 *    weapon can sometimes jam in combat, which requires unjamming,
 *    which also destroys current ammunition inside the clip.
 */

int power_setting;
int total_damage;

/* single round combat mode messages */
static string single_battle_prefix;
static string single_battle_adj;
static string single_battle_verb;
static string single_battle_postfix;

/* burst combat mode messages */
static string burst_battle_prefix;
static string burst_battle_adj;
static string burst_battle_verb;
static string burst_battle_postfix;

/* full auto round combat mode messages */
static string auto_battle_prefix;
static string auto_battle_postfix;

reset(arg) 
{
   ::reset(arg);

   power_setting = 1;

   set_name("GPSD C19 'Saint' assault rifle");
   set_alias("rifle");
   set_class(16);
   set_weight(4);
   set_value(13000);
   set_hit_func(this_object());

   /*
    * single mode
    *
    *
    * strcture:
    *
    * <your name> + " " + single_battle_prefix + " and " +
    * single_battle_adj + " " + <ammo type> + " " + 
    * single_battle_verb + " " + <target name> + " " +
    * single_battle_postfix + "\n"
    *
    */
   
   single_battle_prefix = 
      ({
      "cracks off a single shot",
      "cuts cleanly with a single shot",
      "pulls the trigger softly",
      "casually pulls the trigger",
      "lets off a cap",
      "fires a single shot",
      "cuts off with a single shot",
      "pulls the trigger once",
      });

   single_battle_adj =
      ({
      "a red-hot",
      "a blazing",
      "a firey",
      "a well-placed",
      "a deftly aimed",
      "a single",
      "a nicely targetted",
      });

   single_battle_verb =
      ({
      "tears a path into",
      "digs into soft flesh of",
      "punches through the flesh of",
      "scores a direct hit on",
      "lands a clean shot on",
      "blasts a hole into",
      "burns a clean hole into",
      });

   single_battle_postfix =
      ({
      "!",
      ".",
      "leaving a neat entry wound in the chest.",
      "leaving a wicked hole spurting blood and bone chips.",
      "cracking a bone and letting chips fly.",
      "bursting a limb and letting blood rain out.",
      "slicing through an artery, showering the area with blood.",
      "penetrating a vital organ of some sort.",
      "punching a single hole in the chest.",
      "leaving a cool entry and exit wound through the torso.",
      "exploding into a small red puff in the chest.",
      "sending it rippling back in pain!",
      "cracking a bone of some sort, destroying the joint!",
      "bursting a lung.",
      "blasting through a kidney.",
      "ripping a new happy hole in the flesh.",
      });

   /*
    * burst mode messages
    *
    *
    * strcture:
    *
    * <your name> + " " + burst_battle_prefix + " and " +
    * burst_battle_adj + " " + <ammo type> + " " + 
    * burst_battle_verb + " " + <target name> + " " +
    * burst_battle_postfix + "\n"
    *
    */
   
   burst_battle_prefix = 
      ({
      "cracks off a burst",
      "cuts cleanly with a single shot",
      "pulls the trigger softly",
      "casually pulls the trigger",
      });

   burst_battle_adj =
      ({
      "a trio of",
      "a triplet of",
      "a bunch of",
      "several",
      });

   burst_battle_verb =
      ({
      "burns several holes into",
      "blasts several clean holes into",
      "pelts several good shots into",
      "lands several good shots into",
      "scores a bunch of painful hits into",
      "goes mafia with a few nice hits into",
      "caps a few rounds into",
      "caps a short burst into",
      "releases a quick burst of shots into",
      "rips away a few shots into",
      "guns a few shots into",

      });

   burst_battle_postfix =
      ({
      "!",
      ".",
      "bursting it into blood sausages!",
      "blasting it into a fine red mist.",
      "punching it into a bloody heap.",
      "smashing it into fist-sized chunks.",
      "pulping it like O.J. never could!",
      "revealing what fresh guts looked like.",
      "revealing to all just what a spleen is.",
      "cutting it up into a miasmal red doodieball.",
      "mulching it up into a messy red goo.",
      "mulching it up into a fine battered mess",
      "leaving it bloody and utterly stunned.",
      "knocking the wind and sternum out of it.",
      "bursting its ribcage from the impact.",
      "slicing it up into fine bloody ribbons.",
      "mashing it up into a wicked pile of gop.",
      });
   
   /*
    * full auto mode 
    *
    *    this_player()->query_name() +
    *    " " + auto_battle_prefix[random(sizeof(auto_battle_prefix))] +
    *    " with an entire clip of " + clip->query_ammo_plural_short() + "!\n";
    */
   auto_battle_prefix = 
      ({
      "cuts loose",
      "holds down the trigger and lets rip",
      "screams 'Woo Woo!' while holding down the trigger and lets rip",
      "grins evilly and lets it fly",
      "cackles maniacally and rips wildly",
      "grins a bloody grin and goes postal",
      "goes postal",
      });

   auto_battle_postfix = 
      ({
      "is cut to pieces by a wave of shells!",
      "is mowed down by the hellstorm of bullets!",
      "is mowed down where it was standing!",
      "is pelted with a barrage of wonderous hurt!",
      "is shot several times in the chest!",
      "is caught dead center in the crossfire!",
      "is ripped to shreds by the firestorm!",
      "is caught in the middle of the exchange!",
      "explodes into a fine red mist.",
      "is peppered with metal death!",
      "is capped off with a blizzard of shots!",
      "is peppered with a wave of rounds!",
      });
}

init() 
{
  ::init();
  add_action("load","load");
  add_action("adjust_dial","adjust");
}

/**
 * our short desc.
 *
 *
 */
short() 
{
   string doh;
   string ammo_type;
   int ammo;
   object ob;
 
   /* check to see if any ammo is in the weapon, if so we display
    * some information about it.
    */
   ob = present(AMMOTYPE, this_object());

   /*
    * figure out what kind of ammo we are using
    */
   if(ob) 
   {
      ammo = ob->query_ammo();
      ammo_type = ob->query_ammo_type();
   }
   else ammo_type = "none";

   doh = "A GPSD C19 'Saint' assault rifle [" + ammo + ", " + ammo_type + "]";
   
   if(wielded) doh = doh + " (wielded)";

   /*
    * tack on some wizard information
    */
   if(this_player() && this_player()->query_level() > 39)
      doh = doh + " <Total damage inflicted: [" + total_damage + "]>";

   return doh;
}

/**
 * our long desc.
 *
 *
 */
long() 
{
   if(this_player()) say(capitalize(this_player()->query_name()) + 
      " carefully inspects the C19 assault rifle.\n");
 
   write("  This is a sleek, durable weapon of excellent design clearly meant\n"+
      "for giving someone a bad day. The crisp lines make the weapon's\n" +
      "definition clear and simple.\n"+
      "  Not only is the coldwave industrial appearance an effective fashion\n"+
      "statement, but merely holding it makes you want to engage in some \n"+
      "cruel and mindless slaughter.\n");

   write("\n  Etched into the grip of the weapon are:\n"+
      "[GPSD Corporation : Model C19]\n");

   write("\nThere is a solid knob which you can adjust on this weapon.\n");
   
   /* display info about the status of the weapon */
   switch(power_setting)
   {
   case (4):
      write("The knob setting says 'FA'.\n");
   break;

   case (2):
      write("The knob setting says 'B'.\n");
   break;

   case (1):
      write("The knob setting says 'S'.\n");
   break;

   }
}

/**
 *
 * loads the weapon.
 *
 */
load(str) 
{
   object ammo;
   object all_in_ob;
   int round_weight;
   int rounds2;

   if(!str || str != "rifle") return 0;
   
   /*
    * unlike the spuck weapons, we can only load one clip at a time. 
    */
   all_in_ob = all_inventory(this_object());
   if(sizeof(all_in_ob) >= 1) 
   {
      write("There is already a clip loaded.\n");
      return 1;
   }
   
   /*
    * check for player having ammo 
    */
   ammo = present(AMMOTYPE, this_player());
   if(!ammo) 
   {
      write("You don't have the proper ammunition for this weapon.\n");
      return 1;
   }
   
   /*
    * handle the transaction here
    */
   move_object(ammo, this_object());
   round_weight = ammo->query_weight();
   this_player()->add_weight(-round_weight);
   rounds2 = ammo->query_ammo();
   
   if(!rounds2 || rounds2 > 99990) 
   {
      destruct(ammo);
      write("This is not certified ammunition. It is rejected.\n");
   }

   /*
    * now display what we just loaded into the weapon */
   write("You slide a clip of " + ammo->query_ammo_name() + 
      " into the weapon.\n");
   write("There are [" + rounds() + "] rounds remaining.\n");
   say(capitalize(this_player()->query_name()) + 
      " locks and loads a clip of " + ammo->query_ammo_name() +
      " into the assault rifle.\n");
   return 1;
}

/**
 * our hit function.
 *
 *
 */
weapon_hit(attacker) 
{
   object clip;
   int damage;
   int ammo;
   string attack_message;

   /*
    * i dont want newbies using this thing. Sorry.
    */
   if(this_player()->query_level() < 15)
   {
      write("You are too weak to even flip the safety knob of this weapon.\n"+
         "Nothing happens.\n");
      
      return -16;
   }
   
   clip = present(AMMOTYPE,this_object());
   
   if(clip)
   {
    
      if(!rounds()) 
      {
         destruct(clip);
         write("The weapon has no ammo!\n");
         return -16;
      }

      /*
       * if there are not enough rounds for this power setting,
       * we just burn off the clip.
       */

      if(rounds() < 3 && power_setting == 2) 
      {
         attack_message =
            this_player()->query_name() + 
            " " + burst_battle_prefix[random(sizeof(burst_battle_prefix))] +
            " and " + burst_battle_adj[random(sizeof(burst_battle_adj))] + 
            " " + clip->query_ammo_plural_short() + 
            " " + burst_battle_verb[random(sizeof(burst_battle_verb))] +
            " " + capitalize(attacker->query_name()) + "!\n";

         tell_room(environment(this_player()), attack_message);
         checked_hit(BURST_POTENTIAL / 2);

         clip->lose_ammo(rounds());


      }

      if(!rounds()) 
      {
         destruct(clip);
         write("You've shot the last round of the clip!\n" +
            "It is hastily ejected and disintegrates midair.\n");

         /*
          * a neat feature here, we let the player 'autoload' the weapon
          * in the middle of combat. The drawbacks are that the chance of
          * jamming the weapon are MUCH higher.
          */
         write("You search for another clip...");

         clip = present(AMMOTYPE, this_player());
         
         if(clip)
         {
            write("Found one!\n" +
               "You quickly eject the spent clip and try loading a new one.\n");
            command("load rifle", this_player());
         }
         else
         {
            write("NOT FOUND!\n");
         }
         
      }

      /*
       * ok, we handle the attack part here.
       * single, burst, or full auto.
       *
       */
      switch(power_setting)
      {
      case(1):
         
         attack_message =
            this_player()->query_name() + 
            " " + single_battle_prefix[random(sizeof(single_battle_prefix))] +
            " and " + single_battle_adj[random(sizeof(single_battle_adj))] + 
            " " + clip->query_ammo_single_short() + 
            " " + single_battle_verb[random(sizeof(single_battle_verb))] +
            " " + capitalize(attacker->query_name()) + "!\n";

         tell_room(environment(this_player()), attack_message);
         
         damage = SINGLE_POTENTIAL + ((SINGLE_POTENTIAL * clip->query_power_index()) / 100);

         checked_hit(damage);
         clip->lose_ammo(1);

         break;

      case(2):

         attack_message =
            this_player()->query_name() + 
            " " + burst_battle_prefix[random(sizeof(burst_battle_prefix))] +
            " and " + burst_battle_adj[random(sizeof(burst_battle_adj))] + 
            " " + clip->query_ammo_plural_short() + 
            " " + burst_battle_verb[random(sizeof(burst_battle_verb))] +
            " " + capitalize(attacker->query_name()) + "!\n";

         tell_room(environment(this_player()), attack_message);
         
         damage = BURST_POTENTIAL + ((BURST_POTENTIAL * clip->query_power_index()) / 100);

         checked_hit(damage);
         clip->lose_ammo(3);

         break;

      case(4):

         attack_message =
            this_player()->query_name() +
            " " + auto_battle_prefix[random(sizeof(auto_battle_prefix))] +
            " with an entire clip of " + clip->query_ammo_plural_short() + "!\n";

         tell_room(environment(this_player()), attack_message);
         say(capitalize(attacker->query_name()) + 
            " is caught in the middle of the barrage.\n");

         damage = SINGLE_POTENTIAL + ((SINGLE_POTENTIAL * clip->query_power_index()) / 100);
            
         area_checked_hit(damage);
         clip->lose_ammo(rounds());

         break;
      }

    
      /*
       * the recoil can make players wimpy.
       */
      if(1 == random(10) &&
         power_setting > 1 &&
         this_player()->query_level() < 20)
      {
         write("The recoil of the blast knocks you off your feet!\n");
         say((this_player()->query_name())+ 
            " is rocketed clear across the room from the recoil.\n");

         this_player()->run_away();
         return 1;
      }

      return 1;
   }
   
   write("Your weapon is unloaded!\n");
   return -16;
}

/**
 * this performs a 'safe' hit on a creature, never killing it but
 * allowing for the natural hit to do so.
 *
 */
checked_hit(arg) 
{
   int a_hp,a_dam;
   object a_attack;
   a_attack = this_player()->query_attack();
   
   /*
    * we want the natural hit to do the actual killing here, to minimize
    * the liklihood of the respawned monster at 3/10 bug.
    */
   if(a_attack) 
   {
      a_hp = a_attack->query_hp();
      a_dam = random(arg);

      if(!a_attack->query_npc() && a_dam > 49) a_dam = 50;
      if(a_hp < a_dam || a_hp == a_dam) a_dam = a_hp - 1;
      a_attack->hit_player(a_dam);
      total_damage = total_damage + a_dam;
   }
}

/**
 * this performs a 'safe' hit on all critters designated as suitable targets.
 *
 */
area_checked_hit(arg) 
{
   object foo;
   int dam_divisor,dam_charges;
   dam_divisor = count_livings();
   if(dam_divisor > 2) dam_divisor = dam_divisor - 1;
   dam_charges = 200 / dam_divisor;
   foo=first_inventory(environment(this_player()));
   
   while(foo) 
   {
      object foo2;
      foo2 = foo;
      foo = next_inventory(foo);
      if(living(foo2)) 
      {
         if(foo2->query_npc() && !foo2->is_kid() && !foo2->is_pet()) 
         {
            int foo_hp,foo_damage;

            foo_hp = foo2->query_hp();
            foo_damage = random(dam_charges);
            
            if(foo_hp < foo_damage || foo_hp == foo_damage) 
               foo_damage = foo_hp - 1;
            
            tell_room(environment(this_player()),
               capitalize(foo2->query_name()) + " " +
               auto_battle_postfix[random(sizeof(auto_battle_postfix))] + "\n");

        /* CHECK FOR FIGHT TOO */
            foo2->attack_object(this_player());

            foo2->hit_player(foo_damage);
            total_damage = total_damage + foo_damage;

         } 
         else 
         {
            tell_room(environment(this_player()),
            capitalize(foo2->query_name()) + " escapes harm.\n");
         }
      }
   }
   return 1;
}

/**
 * this just counts the number of suitable targets to shoot at in
 * area attack situations.
 *
 */
count_livings() 
{
   object moo;
   int mmmrugs,whees;
   moo=first_inventory(environment(this_player()));
   while(moo) 
   {
      object squish;
      squish = moo;
      moo = next_inventory(moo);
     if(living(squish)) whees = whees + 1;
   }
   return whees;
}

adjust_dial(str) 
{
   int temp_power_setting;
   if(str != "knob" || !str) return 0;
   
   if(environment(this_object()) != this_player()) 
   {
      write("You have to get the weapon first.\n");
      return 1;
   }
   
   say(capitalize(this_player()->query_name()) + 
      " adjusts a knob on the C19 assault rifle.\n");
   
   write("You adjust the knob which determines the rate of fire.\n");

   switch(power_setting)
   {
   case(4):
      write("The weapon is now set for single-fire mode.\n");
      say("You hear a 'click' and the weapon is switched to single-fire mode.\n");
      temp_power_setting = 1;
   break;

   case(2):
      write("The weapon is now fully automatic.\n");
      say("You hear a 'click' and the weapon is now switched into fully automatic mode.\n" +
         "You twitch nervously.\n");
      temp_power_setting = 4;
   break;
   
   case(1):
       write("The weapon is now in three-round burst mode.\n");
       say("You hear a 'click' and the weapon is switched into three-round burst mode.\n");
       temp_power_setting = 2;
   break;

   }
   
   power_setting = temp_power_setting;
   return 1;
}

/**
 * this just counts the number of rounds in the clip.
 * it's disjointed, i dont know why i separated this object and
 * put the method here... hmmm...
 *
 */
rounds() 
{
  object rc;
  int i;
  rc = present(AMMOTYPE, this_object());
  i = rc->query_ammo();
  return i;
}

/*
 * they can take clips from the gun when its loaded.
 */
can_put_and_get() { return 1; }

/*
 * NOT saveable under ANY circumstances.
 */
query_save_flag() { return 1; }

