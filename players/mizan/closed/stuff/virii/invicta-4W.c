inherit "players/mizan/closed/stuff/virii/base.c";

/**
 *
 *     i n v i c t a - 4W
 *
 *
 *    Boosts weaponclass of attacking monster temporarily.
 *    Dropped to annoying players (those with extended histories)
 */

#pragma strict
#define USE_RANDOM

#undef VIRUSNAME
#define VIRUSNAME "invicta-4W"

void fake_beat()
{
   object att;
   object victim;

   victim = environment(this_object());
   if(victim)
   {
      att = victim->query_attack();
#ifdef USE_RANDOM
      if(att && 1 == random(40))
#else
      if(att)
#endif
      {
         boost_attacker(att);
      }
   }

   ::fake_beat();
}

void boost_attacker(object mons)
{
   mons->set_wc(mons->query_wc() + 390);

   log_it("struck by [invicta-4W] at " + ctime() + " (" + object_name(mons) + ")\n");

   remove_call_out("remove_boost");
   call_out("remove_boost", random(6), mons);
}

void remove_boost(object mons)
{
   if(mons)
      mons->set_wc(mons->query_wc() - 390);
}
