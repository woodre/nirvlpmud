/*
 * This is a magnificent pile of shit that people can do a variety of
 * wonderful things with. Woo yay!
 *
 *
 */

inherit "/players/mizan/core/object.c";
#include "/obj/user/shout_only.c"
#include "/obj/ansi.h"

object my_wedged_object;
string kungfu_stuff;
int is_flinging;

/* as piles of shit are merged together, they get larger. */
int my_size;

reset(arg) 
{
    ::reset(arg);
    if(arg) return;

    my_size = 1;
    
    set_name("shit");
    set_value(10);
    set_alias("pile");

    set_short("A pile of shit");
    
    set_long("This is " + describe_shit() + "! You lucky bastard.\n"+
             "You notice that you can 'wedge' things into this pile of shit.\n"+
             "You are also able to 'fling' this shit at someone else too.\n"+
             "Hey, and if you're stupid you can 'stomp' on this pile as well!\n"+
             "But there's more! You can 'merge shit' to make bigger piles!\n"+
             "How novel! How disgusting! If you're a really sick and twisted\n"+
             "idiot you might even try eating this stuff too! However that would\n"+
             "be a really stupid idea.\n");

    set_read("There is absolutely nothing worth reading here. Move along.\n");

    set_smell("It is STINKY!\nWhat the hell did you expect? French perfumes?!\n");

    set_taste("You are one disgusting nutjob.\n");
    is_flinging = 0;
}


query_weight() { return my_size; }

set_size(arg) { my_size = arg; }

init()
{
    ::init();
    add_action("on_fling","fling");
    add_action("on_wedge","wedge");
    add_action("on_eat", "eat");
    add_action("on_stomp","stomp");
    add_action("on_merge","merge");

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
            tell_room(environment(), this_player()->query_name() + " stepped on " + describe_shit() + "! Eeewww...\n");

        if(this_player())
            tell_object(this_player(), YEL + "\nSPUT!!\n" + NORM + "Dude, you just stepped on " + describe_shit() + ".\n\n");

        move_object(clone_object("/players/mizan/etheriel/items/shit-step-residue.c"), this_player());
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

    
    if(target_ste > random(60000000))
    {
        if(!kungfu_stuff)
        {
            kungfu_stuff = ({
                "Keanu-style, ",
                "With the luck of a lottery winner, ",
                "By the stroke of some crazy luck, ",
                "With total skill, ",
                "Unbelieveably, ",
                "With ungodly stealth, ",
                "Defying the odds, ",
                "Defying reality, ",
                "Bullet-time style, ",
            });
        }

        is_flinging = 0;
        tell_room(environment(this_object()), HIY + kungfu_stuff[random(sizeof(kungfu_stuff))] + target->query_name() + " dodges a pile of shit!\n" + NORM);
        tell_object(this_player(), HIY + "YOU MISSED!\n" + NORM);
        decide_fate();
        return 1;
        /* we get lucky! */
    }
    else
    {
        /* we get hit! */
        is_flinging = 0;
        tell_room(environment(this_object()), this_player()->query_name() + " scores a direct hit!\n");
        on_explode(target);
		
		
        return 1;
    }

}

decide_fate()
{
    /* after we miss, the shit either breaks up, or stays in room */
    if(1 == random(2))
    {
        tell_room(environment(this_object()), "The pile of shit lands in the room, relatively intact.\n");
        tell_room(environment(this_object()), "Fascinating!\n");
        return 1;
    }
    else
    {
        tell_room(environment(this_object()), "The pile of shit breaks apart into a multitude of pebble sized chunks.\n");
        tell_room(environment(this_object()), "Now, it's totally worthless.\n");
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
    tell_room(environment(), this_player()->query_name() + " jumps into the air and stomps mightily into " + describe_shit() + "!\n");
    move_object(clone_object("/players/mizan/etheriel/items/shit-step-residue.c"), this_player());

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

    tell_room(environment(), YEL);
    tell_room(environment(), sput());
    tell_room(environment(), ESC + "[0m"+ ESC + "[0m");

    if(arg && living(arg))
    {
      chan_msg( capitalize(describe_shit_size()) + " of fecal matter has just struck " + (arg->query_name()) + ".\n");


        tell_room(environment(), arg->query_name() + " is hit with " + describe_shit() + "!\n");
    }

    tell_room(environment(), "Fecal matter explodes and flies everywhere in a circular pattern.\n");
	
    if(shit_is_big_enough())
	{
	   tell_room(environment(), "You see " + describe_shit() + " explode into a magnificent\nshower of brown and yellow chunks.....\n");
	   
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


describe_shit(arg)
{
   int i;
   object ob;

   if(!arg) ob = this_object();
   else ob = arg;
     
   i = ob->query_weight();


   if(i > 1000) return "a Moon-sized pile of shit";
   else if(i > 750) return "a Rosie O'Donnell's head sized pile of shit";
   else if(i > 500) return "a Soviet Russia sized pile of shit";
   else if(i > 350) return "an Alaska sized pile of shit";
   else if(i > 200) return "a Texas sized pile of shit";
   else if(i > 100) return "a New Jersey sized pile of shit";
   else if(i > 80) return "an oil tanker sized pile of shit";
   else if(i > 60) return "a supremely MASSIVE pile of shit";
   else if(i > 50) return "a fucking STUPENDOUS pile of shit";
   else if(i > 40) return "a supremely GIGANTIC pile of shit";
   else if(i > 37) return "a stupendously GIGANTIC pile of shit";
   else if(i > 33) return "a GIGANTIC pile of shit";
   else if(i > 30) return "a supremely ENORMOUS pile of shit";
   else if(i > 27) return "a stupendously ENORMOUS pile of shit";
   else if(i > 23) return "an ENORMOUS pile of shit";
   else if(i > 20) return "a supremely massive pile of shit";
   else if(i > 17) return "a stupendously massive pile of shit";
   else if(i > 13) return "a massive pile of shit";
   else if(i > 10) return "an extra-extra large pile of shit";
   else if(i > 7) return "an extra large pile of shit";
   else if(i > 5) return "a very large pile of shit";
   else if(i > 3) return "a large pile of shit";
   else if(i > 1) return "a big pile of shit";
   else return "a pile of shit";
}


describe_shit_size(arg)
{
   int i;
   object ob;

   if(!arg) ob = this_object();
   else ob = arg;
     
   i = ob->query_weight();
   
   if(i > 1000) return "a Moon-sized pile";
   else if(i > 750) return "a Rosie O'Donnell's head sized pile";
   else if(i > 500) return "a Soviet Russia sized pile";
   else if(i > 350) return "an Alaska sized pile";
   else if(i > 200) return "a Texas sized pile";
   else if(i > 100) return "a New Jersey sized pile";
   else if(i > 80) return "an oil tanker sized pile";
   else if(i > 60) return "a supremely MASSIVE pile";
   else if(i > 50) return "a fucking STUPENDOUS pile";
   else if(i > 40) return "a supremely GIGANTIC pile";
   else if(i > 37) return "a stupendously GIGANTIC pile";
   else if(i > 33) return "a GIGANTIC pile";
   else if(i > 30) return "a supremely ENORMOUS pile";
   else if(i > 27) return "a stupendously ENORMOUS pile";
   else if(i > 23) return "an ENORMOUS pile";
   else if(i > 20) return "a supremely massive pile";
   else if(i > 17) return "a stupendously massive pile";
   else if(i > 13) return "a massive pile";
   else if(i > 10) return "an extra-extra large pile";
   else if(i > 7) return "an extra large pile";
   else if(i > 5) return "a very large pile";
   else if(i > 3) return "a large pile";
   else if(i > 1) return "a big pile";
   else return "a pile";

}
