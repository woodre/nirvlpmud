
inherit "obj/monster";

reset(x) { if(x) return;
     set_name("juggernaut");
     set_alias("naut");
     set_short("A juggernaut");
     set_long("It seems to be some kind of living machine.\n");
     set_level(17);
     set_ac(26);
     set_wc(17);
     set_hp(450);
     set_al(0);
     ::reset(0);
}

