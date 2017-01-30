inherit "obj/weapon";

reset(arg) {
     ::reset(arg);
     set_name("rapier");
     set_short("A Worn Rapier");
     set_long("Lightest of blades, it is worn and has seen its better days.\n");
     set_class(16);
     set_weight(1);
     set_value(300);
     add_wear(500); 
     set_save_flag(1);
     set_hit_func(this_object()); }



