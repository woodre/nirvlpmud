/*
 *
 */

/* #include "/players/languilen/langdefs.h" */
#include "/players/languilen/closed/ansi.h"
#define TP this_player()
inherit "obj/monster.c";

reset(arg)  {
     object gold;
     ::reset(arg);
     if(arg) return;

     set_name("Old man");
     set_alias("man");
     set_race("human");
     set_short("An old man");
     set_long(
"    The old man has a glint in his eye, as if he knows something\n\
no one else does.\n");

     set_level( 5 );
     set_hp( 100 );
     set_al( 20 );
     set_wc( 5 );
     set_ac( 15 );
     set_heal(10,2);
     set_aggressive(0);
     set_dead_ob(this_object());

/*     set_chat_chance(15);
 *        load_chat("some bs in italian \n");
 *     set_a_chat_chance(15);
 *        load_a_chat("Whaddaya nuts?   You think you're some kinna wiseguy? \n");
 */

}
init(){
     ::init();
     add_action("join_mobster","join");
}

join_mobster(str){
     object new;
     if(!str){
        write("What do you want to join?\n");
        return 1;
     }
     if(str != "mob"){
        write("Then what are you wasting my time for?  Get lost!\n");
        return 1;
     }
     if(TP->query_guild() || TP->query_guild_rank()){
        write("Naah, we need loyal people not two faced rats.  Get outta\n\
that other organization first.\n");
        return 1;
     }
     write("Well... awright, you seem ok.  For now take this twenty two.\n\
You can get somethiing bigger later.  Good luck in your new life of crime!\n");
     new = clone_object("/players/languilen/guild/mob/gob.c");
     new->add_guns("22");
     move_object(new, TP );
     return 1;
}
