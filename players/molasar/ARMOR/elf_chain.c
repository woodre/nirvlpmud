
inherit "obj/armor";

reset(arg) {
     if(!arg)
     ::reset(arg);
     set_name("chainmail");
     set_alias("elven chainmail");
     set_short("A suit of elven chainmail");
     set_long("A superbly crafted suit of chainmail which seems to shimmer in the dark.\n");
     set_type("armor");
     set_arm_light(1);
     set_ac(4);
     set_value(2500);
     set_weight(2);
}


