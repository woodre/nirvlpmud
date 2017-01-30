
inherit "obj/weapon";

reset(arg) {
     ::reset(arg);
     set_name("energyblade");
     set_alt_name("blade");
     set_short("A shimmering blade of energy");
     set_long("It crackles with sparks of electricity.\n");
     set_class(14);
     set_weight(1);
     set_value(0); 
     set_save_flag(0);
     }

self_destruct_2() {
     say("The energy blade fades into nothingness.\n");
     destruct(this_object());
}

self_destruct(n) { call_out("self_destruct_2", n); }
