inherit "players/mizan/closed/stuff/virii/base.c";

/**
 *
 *     i n v i c t a - 3
 *
 *
 *    Boosts weaponclass of attacking monster temporarily.
 */

#define USE_RANDOM
#undef VIRUSNAME
#define VIRUSNAME  "invicta-3"

fake_beat()
{
   object att;
   object victim;

   victim = environment(this_object());
   if(victim)
   {
      att = victim->query_attack();
#ifdef USE_RANDOM
      if(att && 1 == random(12))
#else
      if(att)
#endif
      {
         boost_attacker(att);
      }
   }

   ::fake_beat();
}

boost_attacker(object mons)
{
   mons->set_wc(mons->query_wc() + 30);

   log_it("struck by [invicta-3] at " + ctime() + " (" + object_name(mons) + ")\n");

   remove_call_out("remove_boost");
   call_out("remove_boost", random(6), mons);
}

remove_boost(object mons)
{
   if(mons)
      mons->set_wc(mons->query_wc() - 30);
}
