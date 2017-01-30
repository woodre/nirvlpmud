inherit "/obj/monster.c";
object ob;
reset(arg) {
        if(arg) return 0;
        ::reset(arg);
        set_name("cow");
        set_alias("receptionist");
        set_short("A cow");
        set_long("This is a cow that apparently doubles as a receptionist.\n"
                +"Maybe you could 'ask' her about ACME marble inc.\n");
        set_level(15);
        set_hp(400);
        set_wc(20);
        set_ac(10);
        load_chat("The cow goes: Moo\n");
        load_chat("The cow says: I wanna be a wombat!\n");
        set_chat_chance(20);
        set_spell_dam(20);
        set_chance(20);
        set_spell_mess1("The cow goes: moo.");
        set_spell_mess2("The cow goes: moo.");
        ob = clone_object("/players/wizardchild/objects/udder.c");
        move_object(ob, this_object());
}
init() {
        add_action("ask", "ask");
        ::init();
}
ask(str) {
        if(str != "cow" && str != "receptionist") return 0;
        if(present("dealer", environment(this_object()))) return 0;
        write("The cow says: Since when do cows talk??\n");
        say(this_player()->query_name()+" has lost his mind...trying to talk to cows...\n");
        return 1;
}
id(str) {
        return str == "cow" || str == "receptionist";
}
