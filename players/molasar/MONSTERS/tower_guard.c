


inherit "obj/monster";

reset(arg) {
    if(arg) return;
    set_name("tower guard");
    set_alias("guard");
    set_short("A tower guard");
    set_long("A strong looking soldier clad in a suit of leather armor.\n");
    set_level(17);
    set_hp(425);
      set_ac(12);
     set_wc(29);
    set_al(200);
    ::reset();
}

