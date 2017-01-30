
inherit "obj/armor";

reset(arg) {
     if(!arg) 
     ::reset(arg);
     set_name("helmet");
     set_alias("metal helmet");
     set_short("A metal helmet");
     set_long("A dull metal helmet with a spike on the top.\n");
     set_value(300);
     set_weight(1);
     set_type("helmet");
     set_ac(1);
}

