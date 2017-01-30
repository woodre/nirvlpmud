
inherit "obj/armor";

reset(arg) {
     if(!arg)
     ::reset(arg);
     set_name("boots");
     set_alias("leather boots");
     set_short("A pair of leather boots");
     set_long("A finely crafted pair of boots made from thick leather hide.\n");
     set_type("boots");
     set_ac(1);
     set_weight(1);
     set_value(500);
}

