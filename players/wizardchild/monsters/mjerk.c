inherit "/obj/monster.c";
object ob;
object obs;
int i;
string place;
reset(arg) {
        if(arg) return 0;
        ::reset(arg);
        i = random(3);
        if(i == 0) place = "ass";
        if(i == 1) place = "head";
        if(i == 2) place = "arm";
        set_name("worker");
        set_alias("unhappy worker");
        set_short("An unhappy worker");
        set_long("Someone who just isn't satisfied with their job here\n"
                +"anymore. They seem to be shooting marbles all over.\n");
        set_level(20);
        set_hp(400 + random(200));
        set_wc(30 + random(10));
        set_ac(22);
        set_spell_dam(25);
        set_chance(10);
        set_spell_mess1("You get shot in the "+place+" by the gun.");
        set_spell_mess2(this_player()->query_name() + " gets shot.");
        ob = clone_object("/players/wizardchild/objects/mgun.c");
        move_object(ob, this_object());
        obs = clone_object("/players/wizardchild/objects/bm30.c");
        move_object(obs, this_object());
}
id(str) {
        return str == "worker" || str == "unhappy worker";
}
