inherit "/obj/monster.c";
object ob;
object obs;
reset(arg) {
        if(arg) return 0;
        ::reset(arg);
                set_name("cow");
        set_alias("sugar dealer");
        set_short("A sugar dealer");
        set_long("This is a cow gone bad. He has turned to drugs in order\n"
                +"to ruin the milk of others around him. Kill that cow.\n");
        set_level(17);
        set_hp(320);
        set_wc(18);
        set_ac(9);
        set_spell_dam(10);
        set_chance(5);
        set_spell_mess1("The dealer coats you with sugar.");
        set_spell_mess2("The cow coats his foe with sugar.");
        ob = clone_object("/players/wizardchild/objects/cubes.c");
        move_object(ob, this_object());
        obs = clone_object("/players/wizardchild/objects/udder.c");
        move_object(obs, this_object());
}
id(str) {
        return str == "cow" || str == "dealer" || str == "sugar dealer";
}
