
inherit "obj/armor";

reset(arg) {
     if(!arg)
     ::reset(arg);
     set_name("shield");
     set_alias("metal shield");
     set_short("A metal shield");
     set_long("A medium sized shield made of metal.\n");
     set_value(200);
     set_ac(1);
     set_type("shield");
     set_weight(1);
}

