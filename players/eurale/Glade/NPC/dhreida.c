/* 10/04/2006 - Rumplemintz
    Moved inherit above #include statements
*/

inherit "obj/monster.c";

#include "/players/eurale/closed/ansi.h"
#include "/players/eurale/closed/aggro_hb.h"

reset(arg)  {
    ::reset(arg);
    if(arg) return;

    set_name("dhreida");
    set_alias("elf");
    set_race("creature");
    set_short(BOLD+"Dhreida"+NORM+", the dark elf");
    set_long(
      "  You look upon a dreaded, evil creature who lives deep within the\n"+
      "dark caves and tunnels under the glade.  She has black skin and pale\n"+
      "white hair.  Dhreida is shorter and more slender than most humans,\n"+
      "barely reaching 5 feet tall and weighing 95 pounds.  She has finely\n"+
      "chiseled features and her fingers and toes are long and slender.\n"+
      "Like all elves, she is very dexterous and her presense in the room\n"+
      "negates all magic.\n");

    set_level(20);
    set_hp(600);
    set_al(0);
    if(!present("elven boots")) {
	move_object(clone_object("players/eurale/Glade/OBJ/elven_boots.c"),
	  this_object()); }
    set_wc(29);
    set_ac(18);
    set_aggressive(0);

    set_chat_chance(7);
    load_chat("Dhreida whispers, 'Leave this place while you can...\n");
    load_chat("Dhreida pierces your soul with her stare.\n");
    set_a_chat_chance(10);
    load_a_chat("Dhreida SCREAMS!\n");
    load_a_chat("Suddenly, you feel very sick to your stomach.\n");
    load_a_chat("Dhreida nimbly sidesteps your attack.\n");

    set_chance(12);
    set_spell_dam(45);
    set_spell_mess1(
      "\nIn the darkness you see Dhreida's eyes "+HIR+"GLOW RED"+NORM+"\n"+
      "and her target SCREAMS in SHEER AGONY!\n\n");
    set_spell_mess2(
      "\nIn the darkness you see Dhreida's eyes "+HIR+"GLOW RED"+NORM+"\n"+
      "and INTENSE PAIN doubles your over in SHEER AGONY!\n\n");
}
