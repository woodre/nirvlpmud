inherit "/obj/weapon.c";
object attacker_ob;
reset(arg) {
        if(arg) return 0;
        ::reset(arg);
        set_name("atomic particle");
        set_short("particle");
        
        set_short("An atomic particle");
        set_long("A single use atomic particle. It appears that you could\n"
                +"'throw' it at a monster during combat.\n");
        set_value(1600);
        set_class(8);
        set_weight(1);
}
id(str) { return str == "particle" || str == "atomic particle"; }
init() {
        add_action("throw", "throw");
        ::init();
}
throw(str) {
        object ob;
        string blah;
        blah = "radiation suit";
        ob = present(blah, this_player());
        if(str != "particle" && str != "atomic particle") return 0;
        write("You hurl the particle at your foe! It does deadly damage.\n"); 
        say(this_player()->query_name() + " hurls an atom at his foe.\n");
        if(!ob || (call_other(ob, "query_rad_protected") != 1)) {
                write("Your weapon turns against you! You are hit by radiation!\n");
                this_player()->reduce_hit_point(30);
        }
        (this_player()->query_attack())->reduce_hit_point(50);
	destruct(this_object());
        return 1;
}
