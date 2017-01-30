inherit "/obj/monster.c";
object ob;
object obs;
reset(arg) {
        if(arg) return 0;
        ::reset(arg);
        set_name("mutant");
        set_alias("tester");
        set_alt_name("mutant tester");
        set_short("A mutant tester");
        set_long("A mutant handgrenade tester. Though he is weak, he has\n"
                +"experienced enough radiation to kill anyone in one blow.\n");
        set_level(16);
        set_hp(200);
        set_wc(18);
        set_ac(14);
        set_spell_dam(100);
        set_chance(25);
        set_spell_mess1("Your body begins to burn and you collapse to the ground.");
        set_spell_mess2("The mutant eliminates his foe.");
        ob = clone_object("/players/wizardchild/objects/hnuke.c");
        move_object(ob, this_object());
        obs = clone_object("/players/wizardchild/objects/radsuit.c");
        move_object(obs, this_object());
}
id(str) {
        return str == "mutant" || str == "tester" || str == "mutant tester" ;
}
