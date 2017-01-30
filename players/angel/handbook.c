inherit "/players/guilds/necro/obj/misc/bookstd.c";

reset(){
    ::reset();
    set_title("Handbook for the Necromancer");
    set_alt_title("handbook for the necromancer");
    add_page("/players/guilds/necro/docs/necro_rules.txt");
    add_page("/players/guilds/necro/docs/necro_rod.txt");
    add_page("/players/guilds/necro/docs/necro_value.txt");
    add_page("/players/guilds/necro/docs/necro_parts.txt");
    add_page("/players/guilds/necro/docs/necro_tool.txt");
    add_page("/players/guilds/necro/docs/necro_pouch.txt");
    add_page("/players/guilds/necro/docs/necro_commands.txt");
    add_page("/players/guilds/necro/docs/necro_others.txt");
    add_page("/players/guilds/necro/docs/necro_leaveguild.txt");
}

query_necro_book(){ return 1;}