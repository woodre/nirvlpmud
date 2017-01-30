/*
 * This is a magnificent pile of shit that people can do a variety of
 * wonderful things with. Woo yay!
 *
 *
 */

inherit "/players/mizan/core/object.c";
#include "/obj/user/shout_only.c"
#include "/obj/ansi.h"

static string shit_kungfu_messages;

object my_wedged_object;
int is_flinging;

/* as piles of shit are merged together, they get larger. */
int my_size;

/* This can be one of a variety of things */
int my_consistency;

/* This is the potentcy of the poop */
int my_density;

int my_meatiness;

int my_odor;


reset(arg) 
{
    ::reset(arg);

    if(!shit_kungfu_messages)
        shit_kungfu_messages = ({
            "Keanu-style, ",
            "With the luck of a lottery winner, ",
            "By the stroke of some crazy luck, ",
            "With total skill, ",
            "Unbelieveably, ",
            "Whiskey-Tango-Foxtrot... ",
            "With ungodly stealth, ",
            "Defying the odds, ",
            "Defying reality, ",
            "Bullet-time style, ",
        });


    if(arg) return;

    my_size = 1;
    my_consistency = 0;
    my_density = 0;
    my_meatiness = 0;
    my_odor = 0;
    
    set_name("shit");

    set_value(10);
    set_alias("pile");

    set_short("A pile of shit");
 
    update_long();   

    set_read("There is absolutely nothing worth reading here. Move along.\n");


    is_flinging = 0;

}

update_long()
{
    set_long("This is " + describe_shit() + "! You lucky bastard.\n"+
             "It appears to be " + describe_density() + ", " + describe_meatiness() + " and " + describe_consistency() + ".\n" +
             "You notice that you can 'wedge' things into this pile of shit.\n"+
             "You are also able to 'fling' this shit at someone else too.\n"+
             "Hey, and if you're stupid you can 'stomp' on this pile as well!\n"+
             "But there's more! You can 'merge shit' to make bigger piles!\n"+
             "How novel! How disgusting! If you're a really sick and twisted\n"+
             "idiot you might even try eating this stuff too! However that would\n"+
             "be a really stupid idea.\n");

    set_taste("It appears to be " + describe_density() + ", " + describe_meatiness() + " and " + describe_consistency() + ".\nYou are one disgusting nutjob though.\n");
    set_smell(describe_odor() + "\n");

}

query_weight() { return my_size; }

query_consistency() { return my_consistency; }
set_consistency(arg)
{
   if(arg > 100) my_consistency = 100;
   if(arg < (-100)) my_consistency = (-100);
   my_consistency = arg;
}

query_density() { return my_density; }
set_density(arg)
{
   if(arg > 100) my_density = 100;
   if(arg < (-100)) my_density = (-100);
   my_density = arg;
}

query_meatiness() { return my_meatiness; }
set_meatiness(arg)
{
   if(arg > 100) my_meatiness = 100;
   if(arg < (-100)) my_meatiness = (-100);
   my_meatiness = arg;
}

query_odor() { return my_odor; }
set_odor(arg)
{
   if(arg > 100) my_odor = 100;
   if(arg < (-100)) my_odor = (-100);
   my_odor = arg;
}

set_size(arg) { my_size = arg; }
query_size() { return my_size; }

init()
{
    ::init();

    update_long(); 

    add_action("on_fling","fling");
    add_action("on_wedge","wedge");
    add_action("on_eat", "eat");
    add_action("on_stomp","stomp");
    add_action("on_merge","merge");
/*
    add_action("on_ignite","ignite");
*/

    if(this_player() && 
       !is_flinging &&
       this_player()->is_player() && 
       this_player()->query_level() < 20 &&
      this_player()->query_attrib("ste") < random(30) &&
      my_size < 8 &&
       1 == random(2))
    {
        /* this idea came from someone but i forgot who! I think it was Verte...  */
        write("Ack! You stepped on " + describe_shit() + "!\n");
        if(environment())
            room_say(this_player()->query_name() + " stepped on " + describe_shit() + "! Eeewww...\n");

        if(this_player())
            tell_object(this_player(), YEL + "\nSPUT!!\n" + NORM + "Dude, you just stepped on " + describe_shit() + ".\n\n");

        leave_step_residue();
        destruct(this_object());
    }
}

short()
{
    if(my_wedged_object)
     return capitalize(describe_shit()) + " (with something wedged inside it)";
    else
        return capitalize(describe_shit(this_object()));
}

long()
{
    write(my_long_desc);

    if(my_wedged_object)
        write(my_wedged_object->short() + " appears to be stuck inside this pile of shit.\n");
}


on_fling(arg)
{
    object target;
    int target_ste;

    if(!arg) return 0;
	
    if(environment(this_object()) != this_player()) return 0;

    target = present(arg, environment(this_player()));
    
    if(this_player()->query_level() > 19)
      target = find_player(arg);

    if(!target)
    {
        write("Fling shit at who (fling <creature>)?\n");
        return 1;
    }

    if(!living(target))
    {
        write("Hey genius, '" + arg + "' is not a living thing.\n");
        return 1;
    }

    /* in this case, wizzes should be immune - except me :) */
    if(target->query_real_name() != "mizan")
        if(this_player()->query_level() <= 20 && target->query_level() >= 20)
        {
            write("'Holy shit', as that would be such a stupid fricking idea.\n");
            return 1;
        }

    if(this_player() == target)
    {
        write("Don't be stupid.\n");
        return 1;
    }

    is_flinging = 1;
    this_player()->add_weight(-this_object()->query_weight());
    move_object(this_object(), environment(target));

    write("You fling the pile of shit at " + target->query_name() + "!\n");
    say(this_player()->query_name() + " flings a pile of shit at " + target->query_name() + "!\n");

 
    /* get our steath attrib */
    if(this_player()->is_player())
        target_ste = target->query_attrib("ste");
    else if(environment(this_object())->fellow_monster())
        target_ste = 70;
    else target_ste = environment(this_object())->query_level();

    
    if(target_ste > random(60))
    {
        is_flinging = 0;
        room_say(HIY + shit_kungfu_messages[random(sizeof(shit_kungfu_messages))] + target->query_name() + " dodges a pile of shit!\n" + NORM);
        tell_object(this_player(), HIY + "YOU MISSED!\n" + NORM);
        decide_fate();
        return 1;
        /* we get lucky! */
    }
    else
    {
        /* we get hit! */
        is_flinging = 0;
        room_say(this_player()->query_name() + " scores a direct hit!\n");
        on_explode(target);
		
		
        return 1;
    }

}

decide_fate()
{
    /* after we miss, the shit either breaks up, or stays in room */
    if(1 == random(2))
    {
        room_say("The pile of shit lands in the room, relatively intact.\n");
        room_say("Fascinating!\n");
        return 1;
    }
    else
    {
        room_say("The pile of shit breaks apart into a multitude of pebble sized chunks.\n");
      
/*
	if(shit_is_big_enough() && consistency_is("nutty"))
	{
	    room_say("A shower of shit-covered peanuts greets the surrounding area.\n");
	}
*/
		room_say("Now, it's totally worthless.\n");
        destruct(this_object());
        return 1;
    }

}

/* the shit pile must be on the ground */
on_stomp(arg)
{
    object target;
    if(!arg) return 0;
    if(arg != "shit") return 0;
    if(!environment(this_object()) || environment(this_object()) == this_player()) return 0;

    if(shit_is_big_enough())
    {
       write("Whoa, podner. That pile of shit is just way too big for that kind of thing.\n");
       return 1;
    }

    write("You take a mighty jump and stomp on " + describe_shit() + "!\n");
    room_say(this_player()->query_name() + " jumps into the air and stomps mightily into " + describe_shit() + "!\n");
    leave_step_residue();

    on_explode(this_player());
    return 1;
}


on_wedge(arg)
{
    object ob;
    if(environment(this_object()) != this_player()) return 0;

    if(!arg)
    {
        write("Wedge what into the pile of shit (wedge <object>)?\n");
        say(this_player()->query_name() + " stares with deep reflection into " + describe_shit() + ".\n");
        return 1;
    }

    if(my_wedged_object)
    {
        write("Something is already wedged into the shit pile.\n");
        return 1;
    }

    ob = present(arg, this_player());

    if(!ob)
    {
        write("You have no such object in possession.\n");
        return 1;
    }

    if(ob && environment(ob) != this_player())
    {
        write("You have to pick it up first.\n");
        return 1;
    }

    if(ob == this_object())
    {
        write("You can't wedge the shit into itself.\n");
        return 1;
    }

    if(ob->drop())
    {
        write("You can't wedge that into the shit pile.\n");
        return 1;
    }

    if(ob->query_weight() > this_object()->query_weight())
    {
        write("That item is too large to fit in the shit pile.\n");
        return 1;
    }

    /* put the object inside */
    move_object(ob, this_object());
    this_player()->add_weight(-ob->query_weight());
    my_wedged_object = ob;
    
    /* tell the room what happened */
    write(my_wedged_object->short() + " is carefully smushed into " + 
          describe_shit() + ".\n");
    write("That is really damn disgusting. You are a sick freak.\n");

    say(my_wedged_object->short() + " is carefully wedged into " + describe_shit() +
        " by " + this_player()->query_name() + ".\n");
    say("DISGUSTING!!!\n\n");

    return 1;
}


on_eat(arg)
{
    string temp;
    int hit_hard;
	
	if(!arg || arg != "shit") return 0;

    /* must be holding shit before tasting it. */
    if(environment(this_object()) && 
       environment(this_object()) != this_player())
    {
       write("You must be carrying " + describe_shit() + " in order to do this.\n");
       return 1;
    }

    if(shit_is_big_enough()) hit_hard = 1;
    else hit_hard = 0;

    if(!arg || !id(arg)) return 0;

    /* tell the victim */
    write("You SICK FREAK!\n\nYou eat the pile of shit whole.\n");
    write("That really was not a smart idea at all.\n");
    write("Suddenly, you don't feel too well.\n");

    /* tell the room */
    say(this_player()->query_name() + " grabs " + describe_shit() + " and EATS THE DAMN THING WHOLE!\n");
    say("That was horribly disgusting but you feel that some hilarity is about to ensue.\n");
    say(this_player()->query_name() + " suddenly does not look too well.\n");

    /* tell the log file */
    temp = ctime() + " " + this_player()->query_real_name() + " (" + this_player()->query_exp() + "exp) has eaten the shit.\n";
    log_file("mizan.SHIT_CONSUMPTION", temp);

    /* if the shit was large enough, it hurts the player with half their HP immediately */
    if(hit_hard)
    {
       write("The mere act of eating such a large quantity of shit makes you violently ill.\n");
       say(this_player()->query_name() + " ate too much shit in one sitting.\n");
       this_player()->hit_player((this_player()->query_hp() / 2));
    }

    if(!present("shit-consumption-sickness", this_player()))
        move_object(clone_object("/players/mizan/etheriel/items/shit-consumption-residue.c"), this_player());

    if(my_wedged_object)
        destruct(my_wedged_object);

    this_player()->add_weight(-this_object()->query_weight());
    destruct(this_object());

    return 1;
}

on_taste(str)
{
    if(!my_taste_msg) return 0;

    if(!str || !id(str)) return 0;

    /* must be holding shit before tasting it. */
    if(environment(this_object()) && 
       environment(this_object()) != this_player())
    {
       write("You must be carrying " + describe_shit() + " in order to do this.\n");
       return 1;
    }

    if(short())
       say(short() + " is tasted by " + this_player()->query_name() + " (DISGUSTING!)\n");

    write(my_taste_msg);

/*
   if(consistency_is("nutty")) write("You also experience the gritty, delectably nasty taste of used peanuts. YUM.\n");
*/

    write("You don't feel too well.\n");

    command("puke", this_player());
    this_player()->hit_player(20 + random(this_player()->query_level()));

    command("drop shit", this_player());
    command("scream", this_player());

    return 1;
}


on_merge(arg)
{
   object ob;
   object oc;
   object room;
   object mergee;
   object carrier;
   int shit_found;
   
   shit_found = 0;
   
   if(!arg || arg != "shit") return 0;
   
   carrier = environment(this_object());
   
   /* should not happen */
   if(!carrier) return 0;
   
   if(carrier != this_player())
   {
      write("You must be carrying both piles of shit first.\n");
      return 1;
   }
   
   room = environment(carrier);
   
   /* should not happen */
   if(!room) return 0;
   
   ob = first_inventory(this_player());
   
   /* we recurse through player's inventory to see if they have more shit */
   while(ob)
   {
      if(ob->id("shit") && ob != this_object())
      {
         mergee = ob;
         shit_found = 1;
         break;
      }
      ob = next_inventory(ob);
   }
   
   if(!shit_found)
   {
      write("No other piles of shit were found in your inventory!\n");
      say(this_player()->query_name() + " stares at a pile of shit in amazement and wonder.\n");
      return 1;
   }

   ob = first_inventory(mergee);
   
   /* we need to purge the inventory inside the shit. */
   while(ob)
   {
      oc = ob;
      ob = next_inventory(ob);
      
      if(oc->short())
         tell_room(room, oc->short() + " falls to the ground, from " +
            describe_shit(mergee) + ".\n");
      
      move_object(oc, room);      
   }
   
   tell_room(room, this_player()->query_name() +
      " merges "  + describe_shit() + " with " +
      describe_shit(mergee) + "!\n");

   /* now get the weight of the one shit, add it to this one */
   my_size += mergee->query_weight();

   if(1 == random(3))
   {
      write("Most excellent. However, you get some shit on your hands by doing so.\n");
      if(!present("shit-hand-residue", this_player()))
         move_object(clone_object("/players/mizan/etheriel/items/shit-hand-residue.c"), this_player());
      
   }

   my_short_desc = capitalize(describe_shit());
   
   /* finally, destruct the other pile, and clean weights */
   this_player()->add_weight(-mergee->query_weight());
   destruct(mergee);
   
   return 1;      
}


on_explode(arg)
{
    object ob;
    int hit_hard;

    if(shit_is_big_enough()) hit_hard = 1;
    else hit_hard = 0;

    if(!environment(this_object()))
    {
        return 0;
    }

    room_say(YEL);
    room_say(sput());
    room_say(ESC + "[0m"+ ESC + "[0m");

    if(arg && living(arg))
    {
      chan_msg( capitalize(describe_shit_size()) + " of fecal matter has just struck " + (arg->query_name()) + ".\n");


        room_say(arg->query_name() + " is hit with " + describe_shit() + "!\n");
    }

    room_say("Fecal matter explodes and flies everywhere in a circular pattern.\n");
	
    if(shit_is_big_enough())
	{
	   room_say("You see " + describe_shit() + " explode into a magnificent\nshower of brown and yellow chunks.....\n");
	   
      if(!present("shit-rain-residue", environment()))
         move_object(clone_object("/players/mizan/etheriel/items/shit-rain-residue.c"), environment());
    }

    ob = first_inventory(environment());
    while(ob)
    {
        if(arg && living(ob) && ob != arg)
        {
            move_object(clone_object("/players/mizan/etheriel/items/shit-nearmiss-residue.c"), ob);
        }
        else
        {
            move_object(clone_object("/players/mizan/etheriel/items/shit-directhit-residue.c"), ob);
        }
        ob = next_inventory(ob);
    }

    /* put something in our environment too */
    if(environment() && living(environment()))
    {
        tell_object(environment(), "You are hit point-blank by an explosive wave of shit.\nDelightful!\n");
        move_object(clone_object("/players/mizan/etheriel/items/shit-directhit-residue.c"), environment());
    }

    if(my_wedged_object)
    {
        move_object(my_wedged_object, environment());
/*
        if(my_wedged_object)
        call_other(my_wedged_object, "weapon_breaks");
        if(my_wedged_object)
        call_other(my_wedged_object, "armor_breaks");
*/
    }

    if(environment(this_object()) && environment(environment(this_object())))
        call_other(environment(this_object()), "on_explode");


    if(arg && living(arg))
    {
        /* wimpy the player if the shit is large enough, and the room isnt a no-fight one */
        if(hit_hard &&
           1 == random(2) &&
           environment())
        {
           chan_msg("Being hit by " + capitalize(describe_shit()) + " sends " + arg->query_name() + " sprawling!\n");
           arg->run_away(); 
        }
    }
	
	
    destruct(this_object());
    return 1;
}


on_ignite(arg)
{
}


/* for the vehicles */
detonate(arg)
{
    return on_explode(arg);
}


sput()
{
    string my_result;

    my_result =
      "\t SSSS   PPPPP   UU   UU  TTTTTTTT  !!  !!\n"+
      "\tSS      PP  PP  UU   UU     TT     !!  !!\n"+
      "\t SSSS   PPPPP   UU   UU     TT     !!  !!\n"+
      "\t    SS  PP      UU   UU     TT\n"+
      "\t SSSS   PP       UUUUU      TT     !!  !!\n\n";

    return my_result;

}


shit_is_big_enough()
{
   if(my_size > 20 && 3 > random(4)) return 1;
   else return 0;
}


describe_consistency(arg)
{
   int i;
   object ob;
   string result;

   if(!arg) ob = this_object();
   else ob = arg;

   i = ob->query_consistency();
   if(i > 100) result = "";
   else if(i > 80) result = "nuttier than a peanut gallery";
   else if(i > 60) result = "";
   else if(i > 40) result = "disgustingly peanut-fortified";
   else if(i > 25) result = "somewhat peanutty";
   else if(i > 10) result = "gritty like ground up peanuts";
   else if(i > 5) result = "grainy and gritty";
   else if(i >= 0) result = "grainy";
   else if(i > (-5)) result = "";
   else if(i > (-10)) result = "";
   else if(i > (-25)) result = "";
   else if(i > (-40)) result = "";
   else if(i > (-60)) result = "";
   else if(i > (-80)) result = "";
   else if(i > (-100)) result = "";

   return result;
}


describe_density(arg)
{
   int i;
   object ob;
   string result;

   if(!arg) ob = this_object();
   else ob = arg;

   i = ob->query_density();
   if(i > 100) result = "hard as a fistful of uncut diamonds";
   else if(i > 80) result = "extraordinarily brick-like";
   else if(i > 60) result = "very brick-like";
   else if(i > 40) result = "somewhat brick-like";
   else if(i > 25) result = "extremely clumpy";
   else if(i > 10) result = "very clumpy";
   else if(i > 5) result = "somewhat clumpy";
   else if(i >= 0) result = "sticky";
   else if(i > (-5)) result = "soggy";
   else if(i > (-10)) result = "pretty soggy";
   else if(i > (-25)) result = "somewhat porous";
   else if(i > (-40)) result = "very porous";
   else if(i > (-60)) result = "extremely porous";
   else if(i > (-80)) result = "almost powder-like";
   else if(i > (-100)) result = "flaky and dusty like a dirt hand grenade";

   return result;
}


describe_meatiness(arg)
{
   int i;
   object ob;
   string result;

   if(!arg) ob = this_object();
   else ob = arg;

   i = ob->query_meatiness();
   if(i > 100) result = "overloaded with bacon";
   else if(i > 80) result = "porkiliciously meaty";
   else if(i > 60) result = "disgustingly meaty";
   else if(i > 40) result = "frighteningly meaty";
   else if(i > 25) result = "burgery meat-rich";
   else if(i > 10) result = "somewhat meaty";
   else if(i > 5) result = "meaty";
   else if(i >= 0) result = "neutral brown";
   else if(i > (-5)) result = "corn-kernelly";
   else if(i > (-10)) result = "very corn-kernelly";
   else if(i > (-25)) result = "somewhat soy-like";
   else if(i > (-40)) result = "very soy-like";
   else if(i > (-60)) result = "completely soy-infested";
   else if(i > (-80)) result = "disgustingly vegan";
   else if(i > (-100)) result = "pure concentrated vegan terror";

   return result;
}



describe_odor(arg)
{
   int i;
   object ob;
   string result;

   if(!arg) ob = this_object();
   else ob = arg;

   i = ob->query_odor();
   if(i > 100) result = "";
   else if(i > 80) result = "";
   else if(i > 60) result = "";
   else if(i > 40) result = "It smells like an open dumpster filled with burning diapers.";
   else if(i > 25) result = "This pile smells pretty rank.";
   else if(i > 10) result = "It smells STINKY!\nWhat the hell did you expect? French perfumes?!";
   else if(i > 5) result = "It smells like a poop parade!";
   else if(i > 0) result = "It smells pretty gamey, like any other pile of shit you have sniffed.";
   else if(i > (-5)) result = "This poop doesn't smell quite as bad as some of the others you have tried out.";
   else if(i > (-10)) result = "";
   else if(i > (-25)) result = "";
   else if(i > (-40)) result = "";
   else if(i > (-60)) result = "You've never encountered pleasant smelling poop before.\nThis pile smells like a box of ripe strawberries. Whiskey Tango Foxtrot!";
   else if(i > (-80)) result = "";
   else if(i > (-100)) result = "";

   return result;
}


describe_shit_size(arg)
{
   int i;
   object ob;
   string result;

   if(!arg) ob = this_object();
   else ob = arg;
     
   i = ob->query_weight();
   
   if(i > 1500) result = "a Mars-sized";
   else if(i > 1000) result = "a Moon-sized";
   else if(i > 750) result = "a Rosie O'Donnell's head sized";
   else if(i > 500) result = "a Soviet Russia sized";
   else if(i > 350) result = "an Alaska sized";
   else if(i > 200) result = "a Texas sized";
   else if(i > 150) result = "a Paris Hilton's vajayjay sized";
   else if(i > 100) result = "a New Jersey sized";
   else if(i > 90) result = "a Battlestar Galactica (RDM) sized";
   else if(i > 85) result = "a Battlestar Galactica (original series) sized";
   else if(i > 80) result = "an oil tanker sized";
   else if(i > 60) result = "a supremely MASSIVE";
   else if(i > 50) result = "a fucking STUPENDOUS";
   else if(i > 40) result = "a supremely GIGANTIC";
   else if(i > 37) result = "a stupendously GIGANTIC";
   else if(i > 33) result = "a GIGANTIC";
   else if(i > 30) result = "a supremely ENORMOUS";
   else if(i > 27) result = "a stupendously ENORMOUS";
   else if(i > 23) result = "an ENORMOUS";
   else if(i > 20) result = "a supremely massive";
   else if(i > 17) result = "a stupendously massive";
   else if(i > 13) result = "a massive";
   else if(i > 10) result = "an extra-extra large";
   else if(i > 7) result = "an extra large";
   else if(i > 5) result = "a very large";
   else if(i > 3) result = "a large";
   else if(i > 1) result = "a big";
   else result = "a";

   result +=" pile";
   return result;
}


describe_shit(arg)
{
   int i;
   object ob;
   string result;

   if(!arg) ob = this_object();
   else ob = arg;

   i = ob->query_weight();

   /* this used to be stupid, and replicated the contents of the describe_shit_size() function */
   result = describe_shit_size(this_object());
   return result + " of shit";
}



/*
consistency_is(arg)
{
   string a;
   string input;

   input = shit_consistency[my_consistency];

   if((sscanf(arg, "%s", input) == 1) ||
      (sscanf(arg, "%s %s", input, a) == 2))
      return 1;
   else
      return 0;
}
*/

room_say(arg)
{
	if(!arg) return;

	if(environment(this_object()))
		tell_room(environment(this_object()), arg);
}

leave_step_residue()
{
	move_object(clone_object("/players/mizan/etheriel/items/shit-step-residue.c"), this_player());
}
