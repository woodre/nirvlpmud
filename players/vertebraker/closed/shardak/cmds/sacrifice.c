#include "../def.h"
#include "/players/vertebraker/define.h"

status SacrificeBlood(object x)
{
    int dam;
    object MarkOb;
    string type;

    if(!(MarkOb = present(OBJID, x)))  /* this shouldn't happen */
    {
      write("You can't do this!\n");
      return 1;
    }

    if((object)x->query_attack())
    {
      write("You are too busy.\n");
      return 1;
    }

    type = (string)MarkOb->query_sacrifice_type();

    if(type != "blood")
    {
      write("\
Shardak will only refuse your sacrifice;\n\
He asks for one of " + BOLD + capitalize(type) + NORM + ".\n");
      return 1;
    }

    dam = (int)x->query_guild_rank();

    if(dam > 8) dam = 8;

    dam *= (20 + random(4));
    write( "\
You slash open your wrist, pouring blood all over.\n");
    say(TPN + " slashes open " + possessive(TP) + " wrist.\n");

    x->hit_player(dam, "other|dark");

    if((status)x->query_ghost()) /* did we die? */
    {
      write("\n\n\
Your untimely death left the sacrifice unperformed.\n\n");
      return 1;
    }
    if(!present("blood chalk", this_player()))
    {
      write("\
The sacrifice is left uncomplete.\nYou recall a tale of \"blood chalk\".\n");
      return 1;
    }
    write("\
      You trace out the blood chalk in a circular,\n\
    spiraling design.  Thoughts of dark destruction\n\
    enter your mind, and the image of a little boy\n\
    running to a horned man seep into your consciousness.\n");
    write("\
      At the last second, you jerk away...\n\
      Pain floods through your veins, and you finally\n\
    feel whole again.   Warmth fills your body and you\n\
    know your sacrifice is complete.\n");

    say((string)x->query_name() + " \
closes " + possessive(x) + " eyes and draws a\n\
    picture upon the ground.\n");

    MarkOb->add_sacrifice(18000 + random(2000));
    MarkOb->NeedSacrifice(0); /* clear sac */
    MarkOb->give_me_back_my_power_foo();

    return 1;
}
    


status
SacrificeGold(object X)
{
    int tot;
    object MarkOb;
    string type;

    MarkOb = present(OBJID, X);

    if(!MarkOb)
    {
      write("You can't do this.\n");
      return 1;
    }
    if((object)X->query_attack())
    {
      write("You are too busy.\n");
      return 1;
    }
    type = (string)MarkOb->query_sacrifice_type();
    if(type != "gold")
    {
      notify_fail("\
Shardak will only refuse your sacrifice;\n\
He asks for one of " + BOLD + capitalize(type) + NORM + ".\n");
      return 0;
    }
    tot = (int)X->query_guild_rank();
    if(tot > 8) tot = 8;
    tot = ((tot * 4000) + random(4000));
    if((int)X->query_money() < tot)
    {
      write("\
You don't have enough coins on your person to give\n\
a proper sacrifice.\n");
      return 1;
    }

    write("\
  You kneel down, praying to Shardak.\n\
  You toss a large pouch of gold coins into the air...\n\
  In a puff of red smoke, it vanishes into nothingness...\n");
    tell_room(environment(X), 
(string)X->query_name() + " kneels down, praying.\n" +
 capitalize(subjective(X)) + " tosses a pouch of gold \
coins into the air...\nIn a puff of red smoke, \
it vanishes into nothingness...\n",
      ({ X }));

    X->add_money(-tot);

    write ("\
You arise anew, filled with a feeling of warmth left by the\n\
touch of your master.\n");

    MarkOb->add_sacrifice(tot + random(12000));
    MarkOb->NeedSacrifice(0); /* clear sac */
    MarkOb->give_me_back_my_power_foo();

    return 1;
}

status SacrificeSoul(object X)
{
    object MarkOb;
    string type;

    MarkOb = present(OBJID, X);
    if(!MarkOb)
    {
      write("You can't do this.\n");
      return 1;
    }
/*
    if((object)X->query_attack())
    {
      write("You are too busy.\n");
      return 1;
    }
*/
    type = (string)MarkOb->query_sacrifice_type();
    if(type != "soul")
    {
      notify_fail("\
Shardak will only refuse your sacrifice;\n\
He asks for one of " + BOLD + capitalize(type) + NORM + ".\n");
      return 0;
    }
    if((int)X->query_alignment() > -400)
    {
      notify_fail ("\
Your soul is not dark enough to perform this most unholy act.\n");
      return 0;
    }
    write("\
You wave your hands in a circular motion and speak forth\n\
the words that the Master gave you.\n\
>What enemy's soul dare you retrieve for the Master?\n\
>Type it forth now, or forever hold your silence;\n\
> ");
    input_to("dark_secret");
    return 1;
}

status dark_secret(string str)
{
    object Sheep;

    if(!str || !(Sheep = present(str, environment(this_player())))
       || Sheep == this_player() || !living(Sheep))
    {
        write("\
You have angered your master, and you suffer..\n");
        TP->hit_player(60 + random(30), "other|dark");
        return 1;
    }

    write("\
The incantations flow from your mouth evenly...\n");
    say("Incantations flow from " + TPN + "'s mouth...\n");

   tell_room(environment(this_player()),
BOLD + BLK + "\t\tA cyclone of dark energy builds around the room...\n"
+ NORM);
    if((status)Sheep->is_player())
      write(capitalize(str) + " is under some sort of protection...\n");
    else if((int)Sheep->query_hp() > 60 || ((int)Sheep->query_hp() > ((int)Sheep->query_mhp() / 10)))
      write(capitalize(str) + " is too powerful...\n");
    else if((int)Sheep->query_alignment() < 0 || (int)Sheep->query_level() < 14)
      write(capitalize(str) + " is unfazed by the dark energy.\n");
    else
    {
      object c;

      tell_room(environment(this_player()),
capitalize(str) + " whirls about in the chaos...\n\
A look of horror engulfs " + possessive(Sheep) + " face...\n\
Suddenly, the life is sucked right out of " + possessive(Sheep)
+ " veins...\n");

      if(!random(3))
        tell_room(environment(this_player()),
"Arteries burst and blood is ripped loose...\n");

      Sheep->attacked_by(TP);
      Sheep->death();

      if(c = present("corpse", environment(TP)))
        destruct(c);

      tell_room(environment(this_player()), "\
  In the aftermath, a fading spectral whisp floats up into\n\
  the air..  A red circle forms from " + TPN + "'s hands.\n", ({ TP }));
           tell_object(this_player(), "\
  In the aftermath, a fading spectral whisp floats up into\n\
  the air..  A red circle forms from your hands.\n");
      tell_room(environment(TP), "\
The whisp floats into the circle, and a ghostly scream is\n\
heard..\n");
      write("\
Warmth fills your body, and you know your sacrifice\n\
is again complete.\n");
      present(OBJID, TP)->add_sacrifice(96000 + random(35000));
      present(OBJID, TP)->NeedSacrifice(0); /* clear sac */
      present(OBJID, TP)->give_me_back_my_power_foo();
    }

    tell_room(environment(TP), BOLD + BLK + "\
The dark energy fades...\n" + NORM);
    return 1;
}    

status main(string str)
{
    object a;

    if((status)(a = this_player())->query_ghost())
    {
      notify_fail("You're dead!\n");
      return 0;
    }
    if(!present(OBJID, a)->query_sacrifice_type())
    {
      notify_fail("\
You don't currently need to make a sacrifice to Lord Shardak.\n");
      return 0;
    }

    if(!str) return (notify_fail("You must make a sacrifice of: " + BOLD + (string)present(OBJID, a)->query_sacrifice_type() + NORM + ".\n"), 0);
    str = lower_case(str);

    if(str == "gold" || str == "money")
      return SacrificeGold(this_player());

    else if(str == "self" || str == "blood")
      return SacrificeBlood(this_player());
    
    else if(str == "soul" || str == "life")
      return SacrificeSoul(this_player());

    else return 0;
}
