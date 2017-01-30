inherit "/players/guilds/necro/obj/misc/bookstd.c";

#define DOCS "/players/guilds/necro/docs"

reset(){
    ::reset();
    set_title("History of the Necromancers");
    set_alt_title("history of the necromancers");
    add_page(DOCS+"/histintro.txt");
    add_page(DOCS+"/hist1.txt");
    add_page(DOCS+"/hist2.txt");
    add_page(DOCS+"/hist3.txt");
    add_page(DOCS+"/hist4.txt");
}

query_necro_book(){ return 1;}
