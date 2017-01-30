/* 10/07/05 - Earwax - Prevented it from being given to wizzes. */

inherit "/players/mizan/core/object.c";
#include "/obj/user/shout_only.c"
#include "/obj/ansi.h"

status is_lit;
int dont_init_commands;
object Giver; /* Earwax 10/07/05 */

reset(arg)
{
   ::reset(arg);
   if(arg) return;
   is_lit = 0;

   set_get(1);
   set_short("A blockbuster firecracker");
   set_name("firecracker");
   set_alias("blockbuster");
   set_weight(1);
   set_value(20);

   set_read("The blockbuster has the words 'Made in China' written on it.\n"+
            "There is a picture of a small cat being set on fire and\n"+
            "blown to bits as well. Hilarious stuff!\n"+
            "'Laughing Horse Brand Fireworks Factory',\n"+
            "Shenzen, China.\n");
   set_smell("The blockbuster smells refreshingly of gunpowder.\n");
   set_taste("The blockbuster tastes salty. Consuming it would be a very bad idea.\n");
}

short()
{

    if(is_lit)
        return my_short_desc + " " + HIR + "(lit!)" + NORM;
    else return my_short_desc;
}

long()
{
    write("This is an understated firework packaged neatly in a red cardboard tube.\n");
    write("It appears you can 'light' it or load it on a suitable catapult to hit\n");
    write("someone with. Note that after being lit is tossed to the ground. It can\n");
    write("still be picked up and thrown around after that. Holding on to the\n"+
          "firework when it goes off would not be a particularly good idea.\n");

    if(this_player() && environment(this_object()) == this_player() && is_lit)
        write(HIR + "THE FUSE IS LIT YOU NUTJOB! GET RID OF IT!!\n" + NORM + NORM);
    else if(is_lit)
        write(HIR + "THE FUSE IS LIT!!\n" + NORM + NORM);
}

/* 10/07/05 - Earwax - Check if target is a wizard. */
status give_check(string arg)
{
  string ack, ugh;
  object ob;

  if (!is_lit)
    return 0;

  if (sscanf(arg, "%s to %s", ack, ugh) != 2)
    return 0;

  ob = find_player(ugh);

  if (!ob)
    return 0;

  if ((int)ob->query_level() > 19)
  {
    write("It's a very bad idea to give lit firecrackers to wizards.\n");
    return 1;
  }

  return 0;
}

init()
{

    ::init();

    /* 10/07/05 Earwax - send it back to giver if target is a wiz. */
    if (environment(this_object())
        && (int)environment(this_object())->query_level() > 19
        && environment(this_object()) != Giver && is_lit)
    {
        dont_init_commands = 1;
        transfer(this_object(), Giver);
    }
    else dont_init_commands = 0;

    if(!dont_init_commands)
    {
        add_action("on_light", "light"); 
        add_action("give_check", "give"); /* Earwax 10/07/05 */
    }
}

on_light(arg)
{
    if(!arg) return 0;
    if(id(arg) || arg == "fuse")
    {

	    write("You light the blockbuster's fuse.\n");
	    write("YOU MIGHT WANT TO DROP THIS THING SOON.\n");

	    say((this_player()->query_name())+" lights a REALLY big firecracker...\n");
    
        is_lit = 1;
	    call_out("on_light_fuse", 6);
        Giver = this_player(); /* Earwax 10/07/05 */
        return 1;
    }
}

on_light_fuse()
{
    say("The fuse on the blockbuster burns brightly!\n");
	call_out("on_fuse_still_burning", 6);
}

on_fuse_still_burning()
{
    say("The blockbuster's fuse is almost burned through!\n");
    if(environment(this_object()))
        tell_object(environment(this_object()), "NOW would be a good time to drop the blockbuster!\n");
	call_out("on_light_explode", 3);
}

on_light_explode()
{
    object victim;
    object room;
    string a,b;

    say(HIY);
    pow_asplode(environment());
    say(ESC + "[0m"+ ESC + "[0m");

    if ((int)environment(this_object())->query_level() > 19
    && environment(this_object()) != Giver)
      transfer(this_object(),Giver);

    victim = environment(this_object());


    /* if you are silly enough to be holding the object... */
    if(victim && living(victim))
    {
        chan_msg("You hear a very large explosion coming from the vicinity of " + (victim->query_name()) + ".\n");
        room = environment(victim);

        move_object(clone_object("/players/mizan/etheriel/items/blockbuster-directhit-residue.c"), victim);
        tell_room(room, victim->query_name() + " was HOLDING the blockbuster firecracker!\n");

        tell_room(room, "A trail of smoke and steam erupts from " + victim->query_name() + "'s smouldering hair.\n");
        tell_room(room, "\nMuch hilarity has ensued.\n");

        /* make them wimpy for fun */
        if(victim->is_player())
        {
            tell_room(room, victim->query_name() + " is thrown clear!\n");
            tell_object(victim, "That was insane!\n");
            if(!room->query_lock() && !room->query_no_fight())
            /* no wimpy in locked hotel/motel/casino */
            /* also no wimpy in safe rooms */
                victim->run_away(); 
        }

    }

    if(environment(this_object()) && environment(environment(this_object())))
        call_other(environment(this_object()), "on_explode");

    destruct(this_object());
}

on_explode(arg)
{
    object room;

    if(!environment(this_object()))
    {
        return 0;
    }

    if(!arg) room = environment();
    room = environment(arg);

    if(!room) return 0;
    move_object(this_object(), room);    

    if(!is_lit)
    {
        tell_room(environment(), "A blockbuster firecracker (unlit) lands harmlessly on the ground next to you.\n");
        write("You forgot to light the fuse first. Doh!\n");
        return 1;
    }

    chan_msg("You feel the shockwave of a large explosion.\n");
    tell_room(environment(),HIY);
    pow_asplode(environment());
    tell_room(environment(),ESC + "[0m"+ ESC + "[0m");


    if(arg)
        tell_room(environment(),"A blockbuster firecracker explodes right near " + arg->query_name() + "!\n");

    tell_room(environment(),"Smoke and bits of unburnt cardboard shrapnel go flying all over the place.\n");
    tell_room(environment(),"Your ears start ringing. Ouch!\n");

    if(arg)
        move_object(clone_object("/players/mizan/etheriel/items/blockbuster-nearmiss-residue.c"), arg);

    if(environment() && environment(environment()))
        call_other(environment(), "on_explode");

    destruct(this_object());
    return 1;
}

/* for the vehicles */
detonate(arg)
{
    return on_explode(arg);
}

pow_asplode(arg)
{
    tell_room(arg, "\nPPPPPPPP         OOOOOOOOOO      WWW                WWW     !!!  \n");
    tell_room(arg, "PPPPPPPPPP      OOOOOOOOOOOO     WWW                WWW    !!!!! \n");
    tell_room(arg, "PPP     PPP    OOOO      OOOO     WWW     WWWW     WWW     !!!!! \n");
    tell_room(arg, "PPP     PPP    OOO        OOO     WWW    WWWWWW    WWW     !!!!! \n"); 
    tell_room(arg, "PPPPPPPPPP     OOO        OOO      WWW  WWWWWWWW  WWW      !!!!! \n");
    tell_room(arg, "PPPPPPPP       OOO        OOO      WWW  WWW  WWW  WWW       !!!  \n");
    tell_room(arg, "PPP            OOOO      OOOO       WWWWWW    WWWWWW             \n");
    tell_room(arg, "PPP             OOOOOOOOOOOO        WWWWW      WWWWW        !!!  \n");
    tell_room(arg, "PPP              OOOOOOOOOO          WWW        WWW         !!!  \n\n");
}

