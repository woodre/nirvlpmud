/*
 * museum_guard.c
 * guard in museum.c
 */

object ticket;

inherit "obj/monster";

void
reset(status arg)
{
  if (arg)
    return;
  monster::reset(arg);
  set_name("guard");
  set_level(1);
#if 0  /* Adjusting for Nirvana monster.guide -- Rumplemintz */
  set_maile();
  set_hp(50);
#else
  set_hp(15);
  set_wc(5);
  set_ac(3);
#endif
  set_al(50);
  set_short("A guard");
  set_long("This is a guard dressed in a grey uniform.\n"+
           "He used to guard the museum, and has not received his new orders yet.\n");
  
  /* Give him a ticket */
  ticket = (object)"/players/padrone/outside/front_yard"->make_ticket();
  move_object(ticket, this_object());
}
