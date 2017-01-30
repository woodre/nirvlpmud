
inherit "obj/armor";

reset(arg) {
     if(!arg)
     ::reset(arg);
     set_name("ring");
     set_alias("platinum ring");
     set_short("A platinum ring");
     set_long("A simple lookin platinum ring.\n");
     set_ac(1);
     set_type("ring");
     set_arm_light(1);
     set_value(2000);
}

