inherit "/obj/monster.c";
object ob;
object obs;
reset(arg) {
        if(arg) return 0;
        ::reset(arg);
        set_name("worker");
        set_alias("factory worker");
        set_short("A factory worker");
        set_long("A distracted factory worker. It seems her attention is\n"
                +"focused on the man with the marble gun.\n");
        set_level(18);
        set_hp(400);
        set_wc(24);
        set_ac(15);
        set_spell_dam(15);
        set_chance(12);
        set_spell_mess1("The worker throws a marble at you.");
        set_spell_mess2(this_player()->query_name() + " gets hit with a marble.");
        ob = clone_object("/players/wizardchild/objects/bm30.c");
        move_object(ob, this_object());
        obs = clone_object("/players/wizardchild/objects/mmaker.c");
        move_object(obs, this_object());
}
id(str) {
        return str == "worker" || str == "factory worker";
}
