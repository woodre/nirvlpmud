inherit "/obj/monster";

object biatch;

void reset(int arg)
{
    if(arg) return;
    ::reset();
    set_name("rufus");
    set_short("Rufus the CrimeDog");
    set_long("\
Woof foo.\n");
    set_level(1);
}

void heart_beat()
{
    /* call the inherited heart_beat [attack, heal, etc] */
    ::heart_beat();
    /* if in combat, make rufus's new biatch the enemy */
    if(attacker_ob) biatch = attacker_ob;
    /* if biatch is gone, fuggedaboudit */
    if(!biatch) return;
    /* check if they aren't already here */
    if(!present(biatch, environment()))
    {
    /* uh oh ! */
      tell_object(biatch, "\
Rufus hunts you down.\n");
      /* discontinue if biatch is logging back in */
      if(!environment(biatch)) return;
      /* move rufus to em */
      move_object(this_object(), environment(biatch));
      /* tell da room, exclude biatch cause we told em! */
      tell_room(environment(biatch), "\
Rufus runs in hunting " + (string)biatch->query_name() + ".\n",
       ({ biatch }));
      /* attack the biatch again */
      attack_object(biatch);
    }
}
