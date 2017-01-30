/*
 * fy_guard.c
 * Guard for front_yard.c
 */

inherit "obj/monster";

void handle_arrival(string str);

void
reset(status arg)
{
  ::reset(arg);
  if (arg)
    return;
  set_name("guard");
  set_level(1);
#if 0  /* Adjusting for Nirvana monster.guide -- Rumplemintz */
  set_hp(50);
#else
  set_hp(15);
  set_wc(5);
  set_ac(3);
#endif
  set_al(50);
  set_short("A guard");
  set_long("This is a guard dressed in a grey uniform.\n"+
           "He sells tickets to the Castle, and stops\n" +
           "people without tickets from entering.\n");

  /* catch_tell setup */
  set_object(this_object());
  set_function("handle_arrival");
  set_type("arrives");
  set_match("");
}

void
handle_arrival(string str)
{
  string envstring;
  object env;
  env = environment(this_object());
  envstring = object_name(env);
  if (present("walking castle", env) &&
      envstring == "/players/padrone/outside/front_yard")
  {
    say("Guard says: Could you please move that walking castle somewhere else?\n");
    call_out("say_where", 4);
  }
}

void
say_where()
{
  say("Guard says: Try to put it in the open place east of the crossing.\n");
}
