inherit "/obj/monster.c";
reset(arg) {
        if(arg) return 0;
        ::reset(arg);
        set_name("snake");
        set_alias("rattlesnake");
        set_short("A rattlesnake");
        set_long("This is one of three rattlesnakes lying in the middle of\n"
                +"the road. Why they are here, you may never know.\n");
        set_level(14);
        set_hp(210);
        set_wc(18);
        set_ac(4);
        set_spell_dam(10);
        set_chance(15);
        set_spell_mess1("The snake bites you, and blood flows from the wound.");
        set_spell_mess2(this_player()->query_name() + " is bitten by the snake.");
}
id(str) {
        return str == "snake" || str == "rattlesnake";
}
