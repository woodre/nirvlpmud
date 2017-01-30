
inherit "obj/armor";

reset(arg) {
     if(!arg)
     ::reset(arg);
     set_name("buckler");
     set_alias("small buckler");
     set_short("A small buckler");
     set_long("A small metal buckler with a spike located in the center.\n");
     set_type("shield");
     set_weight(1);
     set_ac(1);
     set_value(200);
}

