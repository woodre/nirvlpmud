
inherit "obj/armor";

reset(arg) {
     if(!arg) 
     ::reset(arg);
     set_name("helmet");
     set_alias("iron helmet");
     set_short("A iron helmet");
     set_long("A dented and shoddily made helmet.\n");
     set_value(200);
     set_weight(1);
     set_type("helmet");
     set_ac(1);
}

