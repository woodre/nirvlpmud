inherit "/obj/monster.c";
reset(arg) {
        if(arg) return 0;
        ::reset(arg);
        set_name("chicken");
        set_alias("nuclear chicken");
        set_short("A nuclear chicken");
        set_long("This is a farmland chicken gone bad. It seems it spent\n"
                +"too much time around Hanford, and has developed 3 eyes\n"
                +"because of it.\n");
        set_level(16);
        set_hp(150);
        set_wc(13);
        set_ac(6);
        set_spell_dam(10);
        set_chance(22);
        set_spell_mess1("The chicken fries you with a dose of radiation.");
        set_spell_mess2("The chicken nukes his foe.");
}
id(str) {
        return str == "chicken" || str == "nuclear chicken";
}
