inherit "obj/weapon";

reset(arg) {
     ::reset(arg);
     set_name("blade");
     set_short("A Tarnished Blade");
     set_long("An ancient blade of tarnished steel.  It remains very sharp.\n");
     set_class(19);
     set_weight(3);
     set_value(2650); 
     set_save_flag(1);
     set_hit_func(this_object()); }


weapon_hit(attacker) {
     object what;
     if(random(100) < 20) {
          write("The tarnished blade bites into soft flesh.\n");
          environment()->add_hit_point(-1);
          environment()->add_spell_point(-2);
          return 6; }
     if(random(100) < 30) {
          what=environment()->query_attack();
          write("Your tarnished blade slices into " + what->query_name() +
               " and blood flows from the wound.\n");
          say(environment()->query_name() + " slices the flesh from " +
              what->query_name() + " and blood flows from the wound.\n");
          return 1; }
}
