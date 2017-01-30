/******************/
/* FLUFFY         */
/* Hogath         */
/* cc 2004        */ 
/**************** */

#include <ansi.h>

inherit "/obj/monster";

reset(arg) {
    ::reset(arg);
    if (!arg)  {
      

        set_name("Fluffy");
        set_alt_name("dog");
        set_alias("fluffy");
        set_short(HIK+"F"+WHT+"l"+HIK+"u"+HIW+"f"+HIK+"f"+WHT+"y"+NORM);
        set_race("dog");
        set_long(
"This is Fluffy, a rather large Black labrador.  He\n"+
"is currently lazing  at his master Ulatha's feet.\n"+
"You should be careful of waking him lest he bite you!\n");
        set_gender("male");
        set_level(12);
        set_ac(16);
        set_wc(9);
        set_hp(180);
        set_al(0);}
        move_object(clone_object("/players/hogath/area/items/dcollar.c"));
        init_command("wear armor");
        set_chat_chance(5);
        load_chat(HIK+"F"+WHT+"l"+HIK+"u"+HIW+"f"+HIK+"f"+WHT+"y"+NORM+" growls.\n");
        add_spell("dog bite",
                  ""+BOLD+"#MN# "+BOLD+""+HIW+"K N A W S"+NORM+" on your arm.\n\n"+
                  "Dark Red"+HIR+" B L O O D"+NORM+" runs down your arm.\n",  
                  ""+BOLD+"#MN# "+NORM+""+HIR+"B I T E S"+NORM+" #TN#.\n\n"+
                  "Dark Red "+HIR+" B L O O D"+NORM+" runs down #TP# arm.\n",
                  30,20,"physical",6);
                  }

