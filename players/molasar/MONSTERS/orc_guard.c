
inherit "obj/monster";

reset(x) { if(x) return;
     set_name("orc guard");
     set_alias("orc");
     set_level(12);
     set_hp(200);
    set_wc(25);
     set_aggressive(1);
     set_al(-345);
     set_short("An orc guard");
     set_long("A well equiped guard.\n");
     ::reset(0);
}

