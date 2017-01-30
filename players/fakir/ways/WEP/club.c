inherit "obj/weapon";

reset(arg) {
     ::reset(arg);
     set_name("club");
     set_short("A Spiked Club");
     set_long("A large club with rusty iron spikes.\n");
     set_class(16);
     set_weight(3);
     set_value(750); 
     set_hit_func(this_object()); }


