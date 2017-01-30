
inherit "obj/monster";

reset(x) { if(x) return;
     set_name("orc soldier");
     set_alias("orc");
     set_level(9);
     set_hp(150);
     set_wc(14);
     set_aggressive(1);
     set_al(-345);
     set_short("An orc soldier");
     set_long("A regular orc soldier.\n");
     ::reset(0);
}

