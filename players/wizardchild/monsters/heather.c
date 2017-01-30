inherit "/obj/monster.c";
string player;
reset(arg) {
        if(arg) return 0;
        ::reset(arg);
        set_name("heather");
        set_alias("lockleer");
        set_short("Heather Lockleer");
        set_long("Heather Lockleer. I dunno who she is, but she looks good enough to eat.\n");
        set_level(15);
        set_wc(5);
        set_ac(5);
        load_chat("Oh, Jay, You are just sooo funny!.");
        load_chat("Ooo! "+player+" you make me so hot!");
        set_chat_chance(50);
}
id(str) { return str == "heather" || str == "heather lockleer"; }        
catch_tell(str) {
        string junk;
        if(sscanf(str, "%s %s", player, junk) == 2) {
                return 1;
        } else {
                player = "";
                return 1;
        }
}
