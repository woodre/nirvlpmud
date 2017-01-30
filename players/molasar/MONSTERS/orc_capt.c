
inherit "obj/monster";

reset(x) { if(x) return;
     set_name("orc captain");
     set_alias("orc");
     set_level(15);
     set_hp(225);
     set_wc(36);
     set_aggressive(1);
     set_al(-345);
     set_short("An orc captain");
     set_long("A fierce and well trained captain of the orcs.\n");
     ::reset(0);
}

