inherit "/obj/monster.c";
object ob;
object obs;
reset(arg) {
        if(arg) return 0;
        ::reset(arg);
        set_name("tester");
        set_alias("marble tester");
        set_short("A marble tester");
        set_long("A 40 year old marble tester. He is down on his knees, trying\n"
                +"to figure out what exactly one does with marbles.\n");
        set_level(16);
        set_hp(300 + random(200));
        set_wc(24);
        set_ac(16);
        set_spell_dam(5);
        set_chance(25);
        set_spell_mess1("The old fart nails you with a marble.");
        set_spell_mess2("A marble flies into the old farts foe.");
        ob = clone_object("/players/wizardchild/objects/bm30.c");
        move_object(ob, this_object());
        obs = clone_object("/players/wizardchild/objects/fart.c");
        move_object(obs, this_object());
}
id(str) {
        return str == "tester" || str == "marble tester";
}
