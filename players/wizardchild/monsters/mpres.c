inherit "/obj/monster.c";
object ob;
object obs;
reset(arg) {
        if(arg) return 0;
        ::reset(arg);
        set_name("president");
        set_short("The marble company President");
        set_long("This is the Pres. He's proud of the high quality work\n"
                +"environment he has created here. He seems to enjoy playing\n"
                +"with marbles himself...maybe because he's lost his...\n");
        set_level(20);
        set_hp(420 + random(200));
        set_wc(28);
        set_ac(16);
        set_spell_dam(20);
        set_chance(10);
        set_spell_mess1("The president shouts: You'll never take me away!");
        set_spell_mess2("The president shouts: You'll never take me away!");
        ob = clone_object("/players/wizardchild/objects/bm30.c");
        move_object(ob, this_object());
        obs = clone_object("/players/wizardchild/objects/mlost.c");
        move_object(obs, this_object());
}
id(str) {
        return str == "president";
}
