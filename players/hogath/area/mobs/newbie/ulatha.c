/******************/
/* Monster        */
/* Hogath         */
/* cc 2004        */ 
/**************** */

#include <ansi.h>

inherit "/obj/monster";

reset(arg) {
    ::reset(arg);
    if (!arg)  {
      

        set_name("Ulatha");
        set_alt_name("ulatha");
        set_alias("ulatha");
        set_short("Ulatha");
        set_race("gnome");
        set_long(
"This gnome is the owner of the house.  He is wearing a finely\n"+
"tailored shirt and seems to be he relaxing in his favorite chair.\n");
        set_gender("male");
        set_level(9);
        set_ac(7);
        set_wc(13);
        set_hp(135);
        set_al(50);}
        move_object(clone_object("/players/hogath/area/items/fshirt.c"));
        move_object(clone_object("obj/newspaper.c"));
        init_command("wear armor");
        set_chat_chance(5);
        load_chat("Ulatha reads a newspaper.\n");
        load_chat("Ulatha stares glassy eyed into the fire.\n");
        set_a_chat_chance(5);
        load_a_chat(BOLD+"Ulatha YELLS: \"WHY HAVE YOU DISTURBED ME!?!\"\n"+NORM);
}

