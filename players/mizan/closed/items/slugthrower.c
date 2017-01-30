inherit "obj/weapon";

/**
 *
 * Copyright Glue Spodware Inc.
 *
 *
 */

/*
 * configurables
 */

/* the short desc of this object */
string my_short_desc;

/* the long desc for this object */
string my_long_desc;

/* a one word name for this weapon, must also be the ID. */
string my_short_alias;

/* this is a toggle, if set the weapon will recoil and occasionally bounce the
 * player out of the room. Otherwise there is no recoil.
 */
int not_recoilless;

/*
 * whether this weapon can be used like a club when ammo runs dry.
 */
int usable_without_ammo;

/*
 * whether or not this weapon uses a bayonet.
 * usable_without_ammo MUST be set or nothing will happen.
 */
int uses_bayonet;

/*
 * the array of strings specifying legitimate
 * types of bayonet this weapon can use.
 */
string my_bayonet_type;

/*
 * whether or not this weapon can accept a thumper.
 */
int uses_thumper;

/*
 * the ID of the thumper type this weapon can use.
 *
 */
string my_thumper_type;

/*
 * whether or not this weapon uses a gadget.
 */
int uses_gadget;

/*
 * the name of the gadget type it can accept.
 */
string my_gadget_type;

/*
 * the ID matching the type of ammo this weapon uses. REQUIRED.
 */
string my_ammotype;

/*
 * the amount of damage this weapon can do in a burst
 */
int my_burst_potential;

/*
 * the amount of damage this weapon can do in a single fire mode
 */
int my_single_potential;

/*
 * the weapon class of this weapon
 */
int my_weaponclass;

/*
 * non-settables
 *
 */
int power_setting;
int total_damage;

static string plugin_types;
static string plugin_tags;

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
static string auto_battle_postalmode;


/* hand-to-hand fighting mode messages */
static string hand_battle_prefix;
static string hand_battle_postfix;

reset(arg) 
{
   ::reset(arg);

   power_setting = 1;

   set_name("GPSD C19 'Saint' assault rifle");
   set_alias("rifle");
   set_class(my_weaponclass);
   set_weight(4);
   set_value(13000);
   set_hit_func(this_object());


   initialize_variables();
}

initialize_variables()
{
   /* initialize the plugin masks */
   plugin_types =
      ({
      "ammo",
      "bayonet",
      "thumper",
      "gadget",
      });

   plugin_tags =
      ({
      "plugin_ammo",
      "plugin_bayonet",
      "plugin_thumper",
      "plugin_gadget",
      });

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

   auto_battle_postalmode =
      ({
      "is caught in the middle of the barrage.",
      "is the first unlucky idiot tonight.",
      "stares helplessly at the end of the barrel.",
      "is the first loser to get hosed.",
      });


      /*
       * hand-to-hand fighting mode
       *
       *  this_player()->query_name() + 
       *  " " + hand_battle_prefix[random(sizeof(hand_battle_prefix))] +
       *  " " + capitalize(attacker->query_name()) + 
       *  " " + hand_battle_postfix[random(sizeof(hand_battle_postfix))] + "!\n";
       *
       */
   hand_battle_prefix =
      ({
      "grips the stock of the weapon and takes a swing at",
      "wields the weapon like a baseball bat and takes a wild swing at",
      "swings the weapon at",
      "takes a sweeping swing at",
      "hunches down and swings the weapon at",
      "charges violently at",
      });

   hand_battle_postfix =
      ({
      "landing in the head with a clean *THWAK!*",
      "scoring a 'Bust da Pinata' hit!",
      "smashing cleanly in the torso!",
      "!",
      });

}

init() 
{
  ::init();
  add_action("load_ammo","load");
  add_action("adjust_dial","adjust");
  add_action("attach_plugin","attach");

  /* this triggers either a gadget or a thumper */
  add_action("activate_thumper","fire");
  add_action("activate_gadget","use");
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
   ob = present(plugin_tags[0], this_object());

   /*
    * figure out what kind of ammo we are using
    */
   if(ob) 
   {
      ammo = ob->query_ammo();
      ammo_type = ob->query_ammo_type();
   }
   else ammo_type = "none";

   doh = my_short_desc + " [" + ammo + ", " + ammo_type + "]";
   
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
      " carefully inspects the " + this_object()->query_name() + ".\n");
 
   write(my_long_desc);

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
load_ammo(str) 
{
   object ammo;
   int round_weight;
   int rounds2;

   if(!str || !id(str)) return 0;
   
   /*
    * unlike the spuck weapons, we can only load one clip at a time. 
    */
   ammo = present(plugin_tags[0], this_object());

   if(ammo) 
   {
      write("There is already a clip loaded.\n");
      say(this_player()->query_name() + " tries loading the " +
         this_object()->query_name() + " when it was already loaded.\n");
      return 1;
   }

   /*
    * check for player having ammo- and the right type.
    */
   ammo = present(plugin_tags[0], this_player());

   if(!ammo)
   {
      write("You don't have any clips.\n");
      return 1;
   }

   if(!verify_compatible(ammo, 0))
   {
      write("That kind of ammunition is not compatible with this weapon.\n");
      say(this_player()->query_name() + " tries loading the " +
         this_object()->query_name() + " with the wrong type of ammunition.\n");
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
      " into the " + this_object()->query_name() + ".\n");
   return 1;
}

/*
 * attaches a plugin to this weapon.
 *
 */
attach_plugin(str)
{
   /*
    * we have several different types of objects that can be attached
    * to this weapon as a plugin.
    *
    * bayonets      - enhances the weapon when fighting without ammo.
    * thumpers      - grenade launchers or similar weaponry.
    * gadgets       - devices with a free degree of usage.
    *
    */

   object ob;        /* our plugin-to-be */
   object nog;       /* temp object, checks if plugin exists */
   string ob_type;   /* the type of plugin this is */
   int i;            /* loop counter */

   /* we werent told what to attach */
   if(!str)
   {
      write("Attach what?\n");
      return 1;
   }

   ob = present(str, this_player());

   if(!ob)
   {
      write("You have no such item.\n");
      return 1;
   }

   ob_type = ob->query_plugin_type();

   /* now we cycle through trying to determine what kind 
    * of attachment this is.
    *
    */

   for(i = 1; i < sizeof(plugin_types); i++)
   {
      if(ob->query_plugin_type() == plugin_types[i])
      {
         /*
          * if a plugin exists we bust out of the loop, thank you, drive thru 
          */
         if(present(plugin_tags[i], this_object()))
         {
            write("There is already a component of that type attached to the weapon.\n");
            return 1;
         }
         else
         {
            /* this is the ugly, not so loop friendly part */
            switch(i)
            {
            case(1):
               if(uses_bayonet) break;

            case(2):
               if(uses_thumper) break;

            case(3):
               if(uses_gadget) break;

            default:
               write("This weapon does not accept " + lower_case(ob->short()) + ".\n");
            }

            /* now we need to verify if the weapon can accept this plugin's model
             * type.
             */
            if(!verify_compatible(ob, i))
            {
               write("This object is not compatible with the weapon.\n");
               return 1;
            }

            this_player()->add_weight(-(ob->query_weight()));
            move_object(ob, this_object());

            write("You attach the " + str + " to the weapon.\n");
            say(this_player()->query_name() + " attaches " + 
               lower_case(ob->short()) + " to " + this_object()->query_name() + "\n");

            return 1;
         }
      }

   }
   
   write("You are not quite sure how to use this object on the weapon.\n");
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
   object bayonet;
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
      
      return -my_weaponclass;
   }
   
   clip = present(plugin_tags[0],this_object());
   
   if(clip)
   {
    
      if(!rounds()) 
      {
         destruct(clip);
         write("The weapon has no ammo!\n");
         return -my_weaponclass;
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
         checked_hit(my_burst_potential / 2);

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

         clip = present(plugin_tags[0], this_player());
         
         if(clip)
         {
            write("Found one!\n" +
               "You quickly eject the spent clip and try loading a new one.\n");
   
            command("load " + my_short_alias, this_player());
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
         
         /* we missed */
         if(random(call_other(this_player(), "query_attrib", "luc")) < 4)
         {
         
         }
         else
         {
            /* we hit */
            attack_message =
               this_player()->query_name() + 
               " " + single_battle_prefix[random(sizeof(single_battle_prefix))] +
               " and " + single_battle_adj[random(sizeof(single_battle_adj))] + 
               " " + clip->query_ammo_single_short() + 
               " " + single_battle_verb[random(sizeof(single_battle_verb))] +
               " " + capitalize(attacker->query_name()) + "!\n";

            tell_room(environment(this_player()), attack_message);
         
            damage = my_single_potential + ((my_single_potential * clip->query_power_index()) / 100);

            checked_hit(damage);
         }

         /* we lose ammo regardless */
         clip->lose_ammo(1);

         break;

      case(2):

         /* we missed */
         if(random(call_other(this_player(), "query_attrib", "luc")) < 2)
         {

         }
         else
         {
            /* we hit */
            attack_message =
               this_player()->query_name() + 
               " " + burst_battle_prefix[random(sizeof(burst_battle_prefix))] +
               " and " + burst_battle_adj[random(sizeof(burst_battle_adj))] + 
               " " + clip->query_ammo_plural_short() + 
               " " + burst_battle_verb[random(sizeof(burst_battle_verb))] +
               " " + capitalize(attacker->query_name()) + "!\n";

            tell_room(environment(this_player()), attack_message);
   
            damage = my_burst_potential + ((my_burst_potential * clip->query_power_index()) / 100);

            checked_hit(damage);
         }
         clip->lose_ammo(3);

         break;

      case(4):

         /* nobody misses with full auto :) */
         attack_message =
            this_player()->query_name() +
            " " + auto_battle_prefix[random(sizeof(auto_battle_prefix))] +
            " with an entire clip of " + clip->query_ammo_plural_short() + "!\n";

         tell_room(environment(this_player()), attack_message);
         say(capitalize(attacker->query_name()) + 
            " " + auto_battle_postalmode[random(sizeof(auto_battle_postalmode))] + "\n");

         /*
         damage = my_single_potential + ((my_single_potential * clip->query_power_index()) / 100);
         */
        
         damage = (my_single_potential * rounds()) / count_livings();
            
         area_checked_hit(damage);
         clip->lose_ammo(rounds());

         break;
      }

    
      /*
       * the recoil can make players wimpy.
       */
      if(not_recoilless && 
         1 == random(10) &&
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
   
   /* 
    * if this weapon is usable without ammo, swing it around like
    * a club, or see if it has a bayonet
    */
   if(usable_without_ammo)
   {
      bayonet = present(plugin_tags[1], this_object());
      
      /* check to see if a bayonet is plugged in */   
      if(uses_bayonet && bayonet)
      {
         damage = bayonet->weapon_hit(attacker);
         return (bayonet->weapon_class() + damage) - my_weaponclass;
      }
      else
      {
         /* otherwise we attack wielding the weapon like a baseball bat. */
         
         attack_message =
            this_player()->query_name() + 
            " " + hand_battle_prefix[random(sizeof(hand_battle_prefix))] +
            " " + capitalize(attacker->query_name()) + 
            " " + hand_battle_postfix[random(sizeof(hand_battle_postfix))] + "!\n";

         tell_room(environment(this_player()), attack_message);
         
         /* the damage inflicted is very light */
         damage = random(my_single_potential / 3) - my_single_potential;

         return damage;

      }
   
   }
   else
   {
      /* the weapon isnt configured for use like a bat.
       * we do nothing. 
       */
      write("Your weapon is unloaded!\n");
      return -my_weaponclass;
   }
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
   
   moo = first_inventory(environment(this_player()));

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
      " adjusts a knob on the " + this_object()->query_name() + ".\n");
   
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
  rc = present(plugin_tags[0], this_object());
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


verify_compatible(obj, arg)
{
   object ob;
   string ob_type;
   int ok;
   int i;

   ob = obj;

   if(!ob)
      return 0;

   ok = 0;
   ob_type = ob->query_plugin_type();

   if(arg == 0)
   {
      for(i = 0; i < sizeof(my_ammotype); i++)
      {
         if(ob->query_plugin_name() == my_ammotype[i])
         {
            ok = 1;
            break;
         }
      }
   }
   else if(arg == 1)
   {
      for(i = 0; i < sizeof(my_bayonet_type); i++)
      {
         if(ob->query_plugin_name() == my_bayonet_type[i]) 
         {
            ok = 1;
            break;
         }
      }
   }     
   else if(arg == 1)
   {
      for(i = 0; i < sizeof(my_thumper_type); i++)
      {
         if(ob->query_plugin_name() == my_thumper_type[i]) 
         {
            ok = 1;
            break;
         }
      }
   }
   else if(arg == 1)
   {
      for(i = 0; i < sizeof(my_gadget_type); i++)
      {
         if(ob->query_plugin_name() == my_gadget_type[i]) 
         {
            ok = 1;
            break;
         }
      }
   }

   if(!ok)
      return 0;
   else return 1;
}

/*
 * this activates the thumper plugin.
 */
activate_thumper(str)
{
   object thumper;

   thumper = present(plugin_tags[2], this_player());

   if(thumper)
      return thumper->activate(str);
   else
   {
      write("Nothing happens.\n");
      return 1;
   }

}

/*
 * this activates the gadget plugin.
 */
activate_gadget(str)
{
   object gadget;

   gadget = present(plugin_tags[3], this_player());

   if(gadget)
      return gadget->activate(str);
   else
   {
      write("Nothing happens.\n");
      return 1;
   }
}

