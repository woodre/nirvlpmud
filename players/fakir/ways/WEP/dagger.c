inherit "obj/weapon";

reset(arg) {
     ::reset(arg);
     set_name("dagger");
     set_short("A Blood Stained Dagger");
     set_long("A short dagger of unknown origin, stained with blood.\n");
     set_class(15);
     set_weight(2);
     set_value(450); 
     set_save_flag(1);
     set_hit_func(this_object()); }


weapon_hit(attacker) {
     object what;
     if(random(100) < 10) {
          write("The dagger slashes a bloody gash in your victim.\n");
          environment()->add_hit_point(-1);
          environment()->add_spell_point(-2);
          return 6; }
     if(random(100) < 20) {
          what=environment()->query_attack();
          if(what) {
          write("Your dagger slashes a bloody gash in " + what->query_name() +
               " and a chunk of flesh falls.\n");
          say(environment()->query_name() + " slashes the flesh from " +
              what->query_name() + " and it falls to the ground.\n");
        }
          return 1; }
}
