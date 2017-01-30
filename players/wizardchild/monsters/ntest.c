inherit "/obj/monster.c";
object ob;
object obs;
reset(arg) {
        if(arg) return 0;
        ::reset(arg);
        set_name("tester");
        set_alias("nuclear tester");
        set_short("A nuclear tester");
        set_long("A volunteer nuclear tester, jumping on top of nuclear\n"
                +"handgrenades to dampen the force of the explosion.\n"
                +"The radiation seems to have bad side effects.\n");
        set_level(12);
        set_hp(200);
        set_wc(20);
        set_ac(16);
        set_spell_dam(40);
        set_chance(20);
        set_spell_mess1("You are zapped by a lethal dose of radiation.");
        set_spell_mess2("The nuclear tester zaps his foe with radiation.");
        ob = clone_object("/players/wizardchild/objects/radsuit.c");
        move_object(ob, this_object());
        obs = clone_object("/players/wizardchild/objects/atomic.c");
        move_object(obs, this_object());
}
id(str) {
        return str == "tester" || str == "nuclear tester";
}
