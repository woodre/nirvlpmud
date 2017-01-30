inherit "/obj/monster.c";
object ob;
reset(arg) {
        if(arg) return 0;
        ::reset(arg);
        set_name("thrower");
        set_alias("grenade thrower");
        set_short("The nuclear grenade thrower");
        set_long("This is the man who throws the nuclear handgrenades for\n"
                +"others to jump on. It appears he has not experienced as\n"
                +"much radiation as the others, but it does do a number on\n"
                +"his face, none the less.\n");
        set_level(18);
        set_hp(420);
        set_wc(26);
        set_ac(16);
        set_spell_dam(25);
        set_chance(15);
        set_spell_mess1("You feel a burning sensation.");
        set_spell_mess2("The grenade thrower touches his foe.");
        ob = clone_object("/players/wizardchild/objects/hnuke.c");
        move_object(ob, this_object());
}
id(str) {
        return str == "thrower" || str == "grenade thrower";
}
