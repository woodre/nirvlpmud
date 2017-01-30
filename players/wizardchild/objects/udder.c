inherit "/obj/weapon.c";
reset(arg) {
        if(arg) return 0;
        ::reset(arg);
        set_name("udder");
        set_alias("cows udder");
        set_short("A cows udder");
        set_long("A moo cows udder. It looks like it could be wielded by\n"
                +"grabbing and pointing the tits towards the enemy.\n");
        set_value(1600);
        set_class(16);
        set_weight(5);
}
id(str) { return str == "udder" || str == "cows udder"; }
init() { add_action("wield", "wield"); ::init(); }
wield(str) {
        if(str != "udder" && str != "cows udder") return 0;
        write("As you wield the udder, you wonder what kind of pervert\n");
        write("designed such a moronic thing.\n");
        ::wield(str);
        return 1;
}
