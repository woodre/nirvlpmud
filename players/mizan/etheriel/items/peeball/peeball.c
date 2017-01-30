/* #include "/obj/clean.c" */

inherit "/obj/armor.c";
inherit "/obj/weapon.c";

#define PAPERTHING      "/players/mizan/etheriel/items/peeball/paperthing.c"
#define MAX_ITEMWEIGHT  5   /* not too much stuff can fit in our Pee ball. */
/*
int local_weight;           /* the local weight of items inside out Pee ball. */

int amount_of_fuel;      /* the amount of light power left in this pee ball */
status is_lighted;       /* boolean, if this pee ball is lit */
status is_wielded;       /* boolean, if this is currently wielded */
status is_worn;          /* boolean, if this is currently worn */
status is_in_mouth;      /* boolean, if this is in our mouth or not */
status is_defective;     /* boolean, if this is a defective product. */

/* some random stuff */
static string random_combat_msgsay;
static string random_combat_msgwrite;
static string random_eat_msgsay;
static string random_eat_msgwrite;
static string random_country;
static string random_company;
static string random_exclaim;

/* pointers to non-dynamic random messages */
string the_random_country;
string the_random_company;

/* used by the messaging function */
string contents;
string header;

/**
 * The ID of the object.
 */
id(str) 
{
   return str == "ball" || str == "pee_ball" || str == "peeball";
}

/**
 * The short desc of this object.
 */
short() 
{
   string temp;

   temp = "A Pee ball";

   if(is_lighted) 
   { 
      temp += "(glowing)";
   }

   if(is_worn)
   {
      temp += " (worn)";
   }

   if(is_wielded)
   {
      temp += " (wielded)";
   }

   if(is_in_mouth)
   {
      temp += " (in mouth)";
   }

   if(is_defective)
   {
      temp += " [DEFECTIVE]";
   }

   return temp;
}

/**
 * Long desc.
 */
long() 
{
   string temp;

   write("This is a Pee ball, constructed of a durable Spuck-like material.\n"+
     "It is about the size of a tennis ball, and is bright and gaudy in color.\n"+
     "A small sticker on it reads: 'Made in " + the_random_country + "'.\n"+
     "Pee ball is a trademark of Ceinwen, and licensed by " + the_random_company + "'.\n");

   write("For info on how to use your wonderful Pee ball, type 'pee help'.\n\n");
   
   temp = "The Pee ball is currently ";  

   if(is_lighted) 
      temp += "glowing, ";
   else
      temp += "not glowing, ";

   if(is_wielded)
      temp += "wielded, ";
   else
      temp += "not wielded, ";

   if(is_worn)
      temp += "worn. \n";
   else
      temp += "not worn, \n";

   if(is_in_mouth)
      temp += "is in your mouth, ";
   else
      temp += "is not in your mouth, ";

   if(is_defective)
      temp += "and is apparently DEFECTIVE!";
   else
      temp += "and appears to be in perfect working order.";

   temp += "\n";
   write(temp);

   if(first_inventory(this_object()))
   {
      write("    There are things inside the Pee ball.\n");
   } else write("The Pee ball is empty.\n");

}

/**
 * the reset function
 *
 */
reset(arg) 
{
   if(arg) return;
   ::reset(arg);
   if(!arg)
   {
      /* i really hope multiple inheritance doesnt munge this thing */
		set_name("ball");
		set_class(7);
		set_value(20);
		set_weight(1);
   	set_short("A Pee ball");
      set_hit_func(this_object());
      set_ac(1);
      set_type("misc");
   }

   randomize_stuff();

   the_random_company = random_company[random(sizeof(random_company))];
   the_random_country = random_country[random(sizeof(random_country))];


   amount_of_fuel = 600;
 
   is_lighted = 0;
   is_worn = 0;
   is_wielded = 0;
   is_in_mouth = 0;

   /* sometimes, this object can be defective :) */
    if(1 == random(15))
   {
      is_defective = 1;
   }
   else is_defective = 0;

}

/**
 * Our init function.
 *
 */
init() 
{
   /* if we have a defective pee ball, bail out. */
   if(is_defective)
      return;

   ::init();
   /* armor related actions */
   add_action("wear", "wear");
   add_action("remove", "remove");
   add_action("take_off", "unwear");

   /* weapon related actions */
   add_action("wield", "wield");
   add_action("stopwield", "unwield");

   /* general actions */
   add_action("pee_help","pee");
   add_action("display_credits", "peecredits");
   add_action("light", "peelight");
	add_action("eat","eat");

   /* notepad related actions */  
   add_action("display_current","squint");
   add_action("header_entry","peetitle");
   add_action("text_entry","scribble");
   add_action("save_message","preserve");

   /* slurring related actions */
   add_action("grobble_say", "say");
   add_action("grobble_say", "'");
   add_action("grobble","grobble");

}

/**
 * Our help function
 *
 */
pee_help(str)
{
   if(!str || str != "help") return 0;
   else
      write("You have purchased a Pee ball, proudly assembled in " + the_random_country + ".\n"+
      "The following is a very brief set of instructions documenting how to\n" +
      "use this magnificent object:\n\n"+

      "wield peeball    You can wield this Pee ball, and smite your enemies.\n" +
      "wear peeball     Yes, you can wear it as an armor too.\n" +
      "peelight <on>/<off>\n"+
      "                 It even glows. You can use it as a light if you get lost.\n" +
      "eat peeball      You can even eat it too, if you get really desperate.\n"+
      "scribble <msg>   You can even scribble things on your Pee ball too, just\n"+
      "                 perfect for those times your mouth gets all sewn up and you\n"+
      "                 go mute.\n"+
      "squint hard      This lets you read the masterpiece that you are currently\n"+
      "                 working on.\n"+
      "peetitle <msg>   This lets you title your current scribble.\n"+
      "preserve         You can even save those scribbled messages with the Pee ball's\n"+
      "                 built-in Postit [tm] note function.\n"+
      "grobble          Put the Pee ball in or out of your mouth so you can talk like\n"+
      "                 someone who has a water balloon lodged in their throat.\n"+
      "peecredits       Don't be a chump. Find out what people were responsible for this\n"+
      "                 thing. Free cash when you use this command.\n\n"+


      "Now you can see that the Pee ball is a truly revolutionary product. In fact,\n"+
      "anyone you know who does not have one yet is the scum of the earth and must\n"+
      "be destroyed, or given a Pee ball as a present, before they commit social\n"+
      "suicide.\n\n" +
      "Problems? Call 1-888-PEE-BALL for Tech Support. Our operators are standing by,\n"+
      "ready to assist you, 24 hours a day, 7 days a week, with no paid vacations.\n");
   return 1;
}

/**
 * It's edible too.
 *
 */
eat(str) 
{
   if(!str || !id(str)) return 0;
   
   if(is_worn)
   {
      write("You need to remove your Pee ball first.\n");
      return 1;
   }

   if(is_wielded)
   {
      write("You need to unwield your Pee ball first.\n");
      return 1;
   }

 	this_player()->heal_self(random(10));

   write(random_eat_msgwrite[random(sizeof(random_eat_msgwrite))] + "\n");
   say(this_player()->query_name() + " " + 
      random_eat_msgsay[random(sizeof(random_eat_msgsay))] + "\n");

   /* the objects inside */
   if(first_inventory(this_object()))
   {
      if(1 == random(3))
      {
         write("You barfle up the stuff that was inside the Pee ball.\n");
         say(this_player()->query_name() + " barfles up the contents of the Pee ball.\n");
      }
      else
      {
         object ob;
         ob = first_inventory(this_object());

         write(random_exclaim[random(sizeof(random_exclaim))] + 
            " You forgot to empty the Pee ball first.\n");
         say(this_player()->query_name() + 
            " ate the Pee ball... but ate the contents of it too!\n");
         while(ob)
         {
            object oc;
            oc = ob;
            if(oc->short())
            {
               write("You eat " + oc->short() + ".\n");
               say(oc->short() + " is eaten.\n");
            }
            ob = next_inventory(ob);
            destruct(oc);
         }
      }
   }

   /* dont forget the weight */
   this_player()->add_weight(-1);
   destruct(this_object());
	return 1;
}

/**
 * This makes the Pee ball glow on and off.
 * People can turn it on and off even if wielded or worn.
 *
 */
light(str) 
{
   int i;
   if(!str) return 0;

   /* turn the pee ball on */
   if(str == "on") 
   {
      if(amount_of_fuel == 0)
      {
         write("You squeeze the Pee ball but nothing happens.\n");
         return 1;
      }

      if(is_lighted) 
      {
	       write("Your Pee ball is already glowing.\n");
          return 1;
      }
      
      call_out("out_of_fuel", amount_of_fuel * 2);
      if(set_light(1) == 1) 
      {
	       write("You squeeze the Pee ball and it begins to glow.\n");
	       say(this_player()->query_name() + " squeezes a Pee ball and it begins to glow.\n");
      } else
	      write("Ok.\n");

      is_lighted = 1;
      return 1;
   }
   
   /* turn the pee ball off */
   if(str == "off");
   if (!is_lighted)
   {
      write("Your Pee ball is not glowing.\n");
      return 1;
   }
   i = remove_call_out("out_of_fuel");
   
   /* pee ball is whacked */
   if (i == -1) 
   {
     write("Your Pee ball is defective. Contact Tech support at 1-888-PEE-BALL.\n");
     is_defective = 1;
     return 1;
   }

   amount_of_fuel = i/2;
   if (set_light(-1) == 0) 
   {
      write("It turns dark.\n");
	   say(this_player()->query_name() + " squeezes a Pee ball and its stops glowing.\n");
   } else
	   write("Ok.\n");
   is_lighted = 0;
   return 1;
}



/*
 * INTERNAL FUNCTIONS
 */

/**
 * Performs a special attack on a creature
 */
weapon_hit(attacker)
{
   if(random(17) < 3)  
   {
	   write(random_combat_msgwrite[random(sizeof(random_combat_msgwrite))] + "\n");
   	say((this_player()->query_name())+ " " +
         random_combat_msgsay[random(sizeof(random_combat_msgsay))] + "\n");
	   return 1;
	}
}

/**
 * This is a callout used by the light() function.
 *
 */
out_of_fuel() 
{
   if(set_light(-1) == 0)
	   say("Darkness settles in as the Pee ball suddenly stops glowing.\n");
    else
      say("The Pee ball stops glowing.\n");
    amount_of_fuel = 0;
}

/**
 * This is here to attempt to defeat the efun clean_up()
 * which has a nasty side effect of whacking all the objects
 * inside this container when it checks for unreferenced
 * objects 
 */
clean_up() 
{

  if(local_weight) 
  {
     say("The Pee ball makes a squeaking noise.\n");
  }
  return 1;
}

/*
 * Some loose functions
 */
query_value() { return 20; }
query_weight() { return 1; }
get() { return 1; }

drop()
{
   if(is_in_mouth)
   {
      write("You pull the Pee ball out of your mouth.\n");
      is_in_mouth = 0;
   }
   return 0;
}
weapon_class() { return 7; }

/**
 * Used when someone puts something in the Pee ball.
 */
add_weight(w) 
{
  if(local_weight + w > MAX_ITEMWEIGHT) return 0;
     local_weight += w;
  return 1;
}

can_put_and_get()
{
  return 1;
}


/*
 * 'Overloaded' functions- required for armor and weapon 'inheritance'
 * to work properly.
 */

/**
 * Hmm, i cant argue with this one.
 * TAKE_OFF is called when a player is unwearing an ARMOR
 */
take_off()
{

   if(is_wielded)
   {
      write(random_exclaim[random(sizeof(random_exclaim))] +  
         " You can't. You are currently wielding the Pee ball.\n");
      return 1;
   }

   is_wielded = 0;
   write("You remove the Pee ball from your nose.\n");
   ::take_off();
   return 1;
}

/**
 * Remove is called when someone is removing an ARMOR
 */
remove(str)
{
   if(!id(str)) return 0;

   /* if the pee ball is busy doing other things, we cant wield it. */
   if(is_in_mouth)
   {
      write(random_exclaim[random(sizeof(random_exclaim))] + 
         " The Pee ball is in your mouth. Take it out, jackass.\n");
      return 1;
   }

   if(is_wielded)
   {
      write(random_exclaim[random(sizeof(random_exclaim))] +  
         " You can't. You are currently wielding the Pee ball.\n");
      return 1;
   }

   is_worn = 0;
   write("You remove the Pee ball from your nose.\n");
   ::remove(str);
   return 1;
}

wear(str)
{
   if(!id(str)) return 0;
   
   if(is_in_mouth)
   {
      write(random_exclaim[random(sizeof(random_exclaim))] + 
         " The Pee ball is in your mouth. Take it out, stupid.\n");
      return 1;
   }

   if(is_wielded)
   {
      write(random_exclaim[random(sizeof(random_exclaim))] + 
         " You are already wielding the Pee ball as a weapon!\n");
      return 1;
   }
   write("You put the Pee ball on your nose. Wicked.\n");
   is_worn = 1;
   ::wear(str);
   return 1;
}

wield(str)
{
   if(!id(str)) return 0;
   
   /* if the pee ball is busy doing other things, we cant wield it. */
   if(is_in_mouth)
   {
      write(random_exclaim[random(sizeof(random_exclaim))] + 
         " The Pee ball is in your mouth. Take it out, dummy.\n");
      return 1;
   }

   if(is_worn)
   {
      write(random_exclaim[random(sizeof(random_exclaim))] + 
         " You are already wearing your Pee ball as armor!\n");
      return 1;
   }

   write("You clutch the Pee ball tightly with one fist.\nNow you are ready to kill anything! (small)\n");
   is_wielded = 1;
   ::wield(str);
   return 1;
}

/**
 * Cant argue with this one too.
 */
stopwield()
{
   /* if the pee ball is busy doing other things, we cant wield it. */
   if(is_in_mouth)
   {
      write(random_exclaim[random(sizeof(random_exclaim))] + 
         " The Pee ball is in your mouth. Take it out, dummy.\n");
      return 1;
   }

   if(is_worn)
   {
      write(random_exclaim[random(sizeof(random_exclaim))] +  
         " You can't. You are wearing the Pee ball on your nose.\n");
      return 1;
   }

   is_wielded = 0;
   ::stopwield();
   return 1;
}

/**
 * This function prepares some strings for randomization use.
 *
 */
static randomize_stuff()
{
   random_combat_msgsay = ({
      "screams: Whhooooaaaa! Pee ball Fu!",
      "looks awfully dangerous wielding that Pee ball.",
      "leaves you in utter awe, skillfully fighting with a Pee ball.",
      "makes a valiant charge, Pee ball in hand.",
      "does a dance like an angry pro wrestler.",
      "babbles incessantly about the merits of a Pee ball.",
      "acts like the Lord of the Jungle starts shrumping around like a gorilla!",
      "winds up and throws the Pee ball! It bounces back harmlessly.",
      "goes: 'Wubuda Wubuda Wubuda!'",
      "screams: 'You fool! You will be smite to shit under the infinite might of my Pee ball!'",
      "thunders: 'I wield a Pee ball. You don't and have committed social suicide.",
      "booms: 'Pee ball, Pee ball, my happy happy friend...",
      "sings: 'Pee ball, Pee ball, the fun just never ends...",
      "sings: 'Pee ball, Pee ball, I will kick your ass with it...",
      "imitates Barney and says: 'Hello shitheads! Time to die!",
      "exclaims: 'Snap me down! I will whip your fugly de-evolved be-hind with my Pee ball!",
      "barks: 'Who wants some Pee ball?'",
      "screams: 'Wazoo!'",
      "begins singing the fearsome march of the Canadian Armed Forces...",
      "makes a menacing gesture, Pee ball in hand.",

   });

   random_combat_msgwrite = ({
      "You scream loudly! The sheer mighty image of the Pee ball\nmakes you fight harder!",
      "You pelt your opponent viciously with your trusty Pee ball!",
      "'Not only is this the ultimate toy and happy friend...' you cry,\n'But I can kick your ass with it!",
      "You suddenly act like Tarzan, beating your chests and bleating to\nthe good merits of the mighty Pee ball!",
      "You suddenly get the urge to sing about the good merits of a Pee ball.",
      "You sing: 'Pee ball, Pee ball, my bumpy little friend!",
      "You sing: 'Pee ball, Pee ball, The fun just never ends...",
      "You sing: 'Pee ball, Pee ball, You dont have one so you SUCK...",
      "You cry: 'Behold! I will bust your nutless guts to hell with my... Pee ball!",
      "You make menacing and threatening poses, Pee ball in hand.",
      "Life just is infinitely more fun with a Pee ball.",
      "Ahhh, the taste of battle. It is only complete with bashing your enemy with a Pee ball.",
   });
   
   random_eat_msgsay = ({
      "eats a Pee ball.",
      "shoves a Pee ball into its nose and gurgles.\nYou watch in amazement as it is ingested.",
      "ingests a Pee ball, burping and making weird giggling noises in the process.",
      "eats a Pee ball, and then proceeds to let out a loud BELCH.",
      "forces a Pee ball into its ear, and swallows it. Most fascinating.",
      "absorbed a Pee ball. Frock!",
      "absorbes a Pee ball through the navel. You only wish you could be so cool.",
   });
   
   random_eat_msgwrite = ({
      "You eat a Pee ball. Somehow, it tastes like chicken.",
      "You force the Pee ball down your throat.\nIt felt like eating a water balloon.",
      "You shove a Pee ball into your nose. It pleases you greatly snorting loudly,\ntrying to get the Pee ball to go down your throat.",
      "You swallow the Pee ball whole.",
      "You filthy Spodmonger! You swallowed the Pee ball whole.",
   });

   random_country = ({
      "North Korea",
      "The Republic of Yemen",
      "Newark, NJ",
      "Spork Valley, CA",
      "Saudi Arabia",
      "Iraq",
      "Wisconsin",
      "The country formerly known as East Germany",
      "The Empire of Canada",
      "Bob's Garage",
      "Indonesia",
      "Nebraska",
      "Iceland",
      "Saskatoon",
      "Wichita, Kansas",
      "Poland",
      "Somewhere",
      "A giant meatball drifing in space",
      "The Cambell Soup Factory",
      "The Cheesenub Testing Facility, Needles CA",
      "Olympus Mons, Mars",
      "Surtur Mons, Io",
      "Surtsey, Iceland",
      "one of Kathy Lee Gifford's sweatshops",
      "Somewhere in India",
      "Bombay",
      "Jackie Martling's basement",
      "Lake Titicaca",
      "North Dakota",
      "Sarawak, Malaysia",
      "Hasibabombe, Zaire",
      "Germany",
      "Denmark",
      "Cuba", 
   });

    random_company = ({
      "Pee Ball International",
      "Pee Ball Global",
      "Spumco [tm]",
      "Slow Dog Manufacturing",
      "Roadkill Productions",
      "PickleWorks Portfolio",
      "Spod Bros. Industries",
      "Dead Horse Mfg.",
      "Exploding Cat Productions",
      "Gritty Kitty Litter Inc.",
      "Dog Water LLC",
      "Two Stiffs and a Tree, Inc.",
      "Gas-O-Matic",
      "You Suck, Inc.",
      "Bjorky Playthings, Inc.",
      "Alpofod LLC", 
      "The Mighty Canadian Armed Forces",
      "The Iraqi Republican Guard",
      "Loafy Hussein, Inc.",
    });

    random_exclaim = ({
       "Bonehead!",
        "How infuriatingl stupid!",
       "Doh!",
       "Snap me down!",
       "Mommy yes! It's Sniz & Fondue!",
       "Dope!",
       "Steep bogglement!",
       "Mild bogglement!",
       "Snap me silly with a yo-yo!",
       "Spod this!",
       "Well that's just peachy keen!",
       "Baf!",
       "Putz!",
       "Schmuck!",
       "Spoo-brain!",
       "Half-wit!",
       "Cheese-for-brains!",
       "Bababooie!",
       "Nutless horse!",
       "Holy fruits!",
       "Tanya Donnelly laughs at you, you spod!",
       "Well break a fish over my neck!",
       "Well shove a bowling pin down my throat!",
       "Spod sucker!",
       "Spod eater!",
       "Spod shoveler!",
       "Suspension bridge!",
       "You spod loving pig-farmer!",
       "Wow! Suck on a torpedo!",
    });
}


/*
 * This stuff is used by the note-taking abilities of the Pee ball.
 *
 */
text_entry(str) 
{
   if(!str) return 0;

   if(!contents) contents = "";

   contents = contents + str + "\n";
   say(capitalize(this_player()->query_name())+" scribbles something with a fingernail on a Pee ball.\n");
   write("Ok.\n");
   return 1;
}

header_entry(str) 
{
   if(!str) 
   {
      write("Pee ball scribble title cleared.\n");
      header = 0;
      return 1;
   }
   header = str;
   write("Ok.\n");
   return 1;
}

display_current(str) 
{
   if(!str || str != "hard") return 0;
   say(capitalize(this_player()->query_name())+" examines a Pee ball intently.\n");
   if(header) 
   {
      write("You squint and see:\n\nScribble titled: "+header+"\n");
   }
   else
      write("You squint and see an untitled scribble:\n\n");

   write(contents);
   return 1;
}

save_message(str)
{
   object ob;
   if(!contents)
   {
      write(random_exclaim[random(sizeof(random_exclaim))] +
         " You have no text scribbled!\n");
      return 1;
   }
   ob=clone_object(PAPERTHING);
   ob->set_text(contents);
   if(header) 
   {
      ob->set_header(header);
   }
   move_object(ob, this_player());
   write("You tear off piece of your Pee ball with saved scribbles on it.\n");
   say(capitalize(this_player()->query_name())+" tears a sliver of goop from a Pee ball.\n");
   contents=0;
   header=0;
   return 1;
}

/**
 * The slurring part
 */

grobble()
{
   if(!is_in_mouth)
   {
      if(is_worn)
      {
         write(random_exclaim[random(sizeof(random_exclaim))] + 
            " You need to remove your Pee ball first.\n");
         return 1;
      }

      if(is_wielded)
      {
         write(random_exclaim[random(sizeof(random_exclaim))]   +
            " You need to unwield your Pee ball first.\n");
         return 1;
      }

      is_in_mouth = 1;
      write("You shove the Pee ball into your throat. Not only do you now look\n"+
         "incredibly stupid, but you will sound dopey as well. Cheers!\n");
      say(this_player()->query_name() + " gobbles up a Pee ball, without swallowing it.\n");
      return 1;
   }
   else
   {
      /* ok, now yank it out of the mouth. */
      is_in_mouth = 0;
      write("You pull the Pee ball out of your mouth.\n"+
         "It is sopping wet, dripping with saliva and phlegm.\n");
      say((this_player()->query_name()) + " pulls a Pee ball out of its mouth.\n");
      return 1;
   }
}

grobble_say(str)
{
   string temp;

   if(!is_in_mouth || is_wielded || is_worn)
   {
      return 0;
   }

   temp = distort(str);

   say(this_player()->query_name() + " says: " + temp + "\n");
   write("You say: " + temp + "\n");
   return 1;
}

/**
 * This function I got from one of sado's things
 */
distort(str) 
{
   string msg,temp,letter;
   int i;
   msg = "";
   for(i = 0; i < strlen(str); i++)
   {
      letter = extract(str, i, i);
         if(lower_case(letter) == "u") temp="urble";
         else if(lower_case(letter)=="r") temp="rum";

/*
         else if(letter=="l" && extract(str, i - 1, i - 1) == "l" && random(3) == 1) temp = "lor";
         else if(letter=="l" && extract(str, i - 1, i - 1) == "l" && random(3) == 1) temp = "ll";
         else if(letter=="o" && extract(str, i - 1, i - 1) == "o" && random(3) == 1) temp = "orp";
         else if(letter=="o" && extract(str, i - 1, i - 1) == "o" && random(3) == 1) temp = "oop";
         else if(letter=="o" && extract(str, i - 1, i - 1) == "o" && random(3) == 1) temp = "oolp";
         else if(letter=="u" && extract(str, i - 1, i - 1) == "u" && random(3) == 1) temp = "ug";
         else if(letter=="e" && extract(str, i - 1, i - 1) == "e" && random(3) == 1) temp = "eep";
         else if(letter=="e" && extract(str, i - 1, i - 1) == "e" && random(3) == 1) temp = "eee";
         else if(letter=="e" && extract(str, i - 1, i - 1) == "e" && random(3) == 1) temp = "ere";
         else if(letter=="a" && extract(str, i - 1, i - 1) == "e" && random(3) == 1) temp = "arg";
         else if(letter=="a" && extract(str, i - 1, i - 1) == "e" && random(3) == 1) temp = "aah";
         else if(letter=="a" && extract(str, i - 1, i - 1) == "e" && random(3) == 1) temp = "urr";
*/
         else if(letter==" " && random(9) == 1) temp="(glug) ";
         else if(letter==" " && random(9) == 1) temp="(bloop) ";
         else if(letter==" " && random(9) == 1) temp="(nog) ";
         else if(letter==" " && random(9) == 1) temp="(ploof) ";
         else if(letter==" " && random(9) == 1) temp="(glop) ";
         else if(letter==" " && random(4) == 1) temp="(moo) ";
         else temp = "";
         if((letter == "'" && str[i + 1] == 't') ||
               (letter == "s" && str[i + 1] == 's')) i++;
         msg = msg + letter + temp;
      }
    msg = msg + letter;
   return msg;
}

display_credits()
{
   write("Wicked, you non Spod-like creature, taking in the time to watch\n"+
      "the credits. Actually there will be some self-congratulatory promotion\n"+
      "mixed in, and I lied. No free cash when you use this command, so\n"+
      "don't fret your steamy hippos over it.\n\n"+
      ">> 'Pee ball' is a phrase that came from Ceinwen, and her cat Merlin.\n"+
      "    A pee ball is a combination of hairball, wet kitty litter, and aged\n"+
      "    sawdust. Don't worry, you'll get used to the taste. Just think of\n"+
      "    cement when you're eating it.\n"+
      ">> 'Spod' is a registered trademark of Mizan. \n"+
      ">> Mumble code (grobble stuff) provided by Sado.\n"+
      "   Other wizzes contributed in collective ways with code too. This object\n"+
      "   shows all the evils of multiple inheritance, and the Spod-like ways of LPC.\n"+
      ">> Hear what people are saying about the Pee ball!\n"+
      "   'NO NO NO NO! ...For the love of SATAN' - Pain 'Boom Boom' Pantaloozo\n"+
      "   'Heh. Its a pee ball.' - Sado, 'The Cheeks' Palermino\n"+
      "   'This is a piece of crap, you flap happy fuckwit' - Requested anonymous\n"+
      "   'You are a sick man.' - Mythos 'The Crowbar' Lupo\n"+
      "   'Why did you give me this shit? I did'nt want it!' - Guest\n\n"+
      ">> The reviews are in! Unanimous rave critiques and social acceptance of the\n"+
      "   Hot New Toy for the next three seasons! You are one lucky bastard to own a\n"+
      "   Pee ball and when the world is destroyed in the great jihad of Doom, only\n"+
      "   those who have Pee balls will be saved. Act Now! Order another Pee ball\n"+
      "   for your friend, and avoid a tormented existence stuck in the armpits of\n"+
      "   evil and suffering for an eternity!\n"+
      "   CALL US... We are waiting for you at 1-888-PEE-BALL!\n");
   return 1;
}
