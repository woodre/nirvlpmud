#include "/players/softly/misc/ansi.h"
inherit "/obj/monster";

reset(arg) 
{
   ::reset(arg);
   if (arg) return;   
   move_object(clone_object("/players/softly/point/obj/ering.c"),this_object());  
   move_object(clone_object("/players/softly/point/obj/ashawl.c"),this_object());  
   set_name("aralie");
   set_alt_name("Aralie");   
   set_alias("widow");
   set_long("A thin beautiful young woman, brown ringlets cascading over\n"+
            "her deep blue shawl, stands staring out at the sea.  Her thin\n"+
            "dress barely protects her from the wind.  A glance at her face\n"+
            "reveals a deep sadness behind her dark eyes.\n");
   set_short("The Widow Aralie");
   set_race("human");
   set_level(18);
   set_wc(26);
   set_ac(18);
   set_hp(850);
   set_al(0);
   set_aggressive(0);
   add_money(1200+random(500));
   set_a_chat_chance(5);
   load_a_chat("Aralie whispers: Please do not do this..\n");
   load_a_chat("Aralie says: I do not wish to hurt you..\n");
}

void heart_beat()
{
    ::heart_beat();
    if(!attacker_ob) return;
    if(random(100) < 35)
    {
      tell_object(attacker_ob, BLU + "\n\t\t\
Aralie reaches out and touches you.\n\t\t\
A deep pain penetrates your soul.\n" + BOLD
+ "\t\tYou begin to cry.\n\n" + NORM);
      tell_room(environment(), BLU + "\n\t\
Aralie reaches out and touches " + 
(string)attacker_ob->query_name() + ", who begins to cry.\n" + NORM,
      ({ attacker_ob }));
      attacker_ob->hit_player(random(35));
    }
}


