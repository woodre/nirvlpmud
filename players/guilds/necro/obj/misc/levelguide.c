inherit "/players/guilds/necro/obj/misc/bookstd.c";

#define DOCS "/players/guilds/necro/docs"

reset(){
    ::reset();
    set_title("Guide to the Levels of Necromancy");
    set_alt_title("guide to the levels of necromancy");
    add_page(DOCS+"/levelguideintro.txt");
    add_page(DOCS+"/basic.txt");
    add_page(DOCS+"/level1.txt");
    add_page(DOCS+"/level2.txt");
    add_page(DOCS+"/level3.txt");
    add_page(DOCS+"/level4.txt");
    add_page(DOCS+"/level5.txt");
    add_page(DOCS+"/level6.txt");
    add_page(DOCS+"/level7.txt");
    add_page(DOCS+"/level8.txt");
    add_page(DOCS+"/level9.txt");
}

query_necro_book(){ return 1;}
