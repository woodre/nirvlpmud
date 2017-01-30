/******************/
/* FLUFFY         */
/* Hogath         */
/* cc 2004        */ 
/**************** */

#include <ansi.h>;

inherit "/obj/monster";

reset(arg) {
    ::reset(arg);
    if (!arg)  {
      

        set_name("Chowder");
        set_alt_name("dog");
        set_alias("chowder");
        set_short(HIW+"Cho"+HIK+"wder"+NORM);
        set_race("dog");
        set_long(
"This is Chowder, a White and Black labrador.  He is a little\n"+
"bit small but makes up for this by being fiesty.  He is currently\n"+
"taking a lazing in the doorway.\n");
        set_gender("male");
        set_level(10);
        set_ac(14);
        set_wc(8);
        set_hp(150);
        set_al(0);}
        move_object(clone_object("/players/hogath/area/items/dcollar.c"));
        init_command("wear armor");
        set_chat_chance(1);
        load_chat("Chowder pants.\n");
        load_chat("Chowder wags his tail.\n");
        add_spell("dog bite",
                  ""+BOLD+"#MN# "+BOLD+""+HIW+"C H O M P S "+NORM+" on your arm.\n\n"+
                  "Dark Red"+HIR+" B L O O D"+NORM+" runs down your arm.\n",  
                  ""+BOLD+"#MN# "+NORM+""+HIR+"B I T E S"+NORM+" #TN#.\n\n"+
                  "Dark Red "+HIR+" B L O O D"+NORM+" runs down #TP# arm.\n",
                  30,20,"physical",6);
}

