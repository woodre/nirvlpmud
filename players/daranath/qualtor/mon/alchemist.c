inherit "players/mythos/amon/forest/monster1";

#include "/players/saber/closed/esc.h"
#include <ansi.h>

reset(arg) {
  object gold;
   ::reset(arg);
   if (!arg) {

move_object(clone_object("/players/daranath/qualtor/obj/zyagx_coat.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/obj/zyagx_boots.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/wep/zyagx_dag.c"),this_object());

     set_name("Zyagx the Mad Alchemist");
     set_short("A strange looking individual");
     set_alias("individual");
     set_alt_name("zyagx");
     set_race("human");
     set_gender("male");
     set_long("The strange looking individual stares at you with a hatred for\n"+
              "the living. He is wearing a blood stained lab coat that trails\n"+
              "along the floor and a pair of boots made from rubber, that\n"+
              "is covered in grime and blood.\n");
     set_level(20);

     init_command("wear coat");
     init_command("wield dagger");
     init_command("wear boots");

     set_ac(17);
     set_wc(36 + random(4));
     set_hp(500 + random(100));
/* NEW CODE -Snow 5/00 */
     set_wc_bonus(16);
     set_al(-1200);
     set_aggressive(0);
     set_dead_ob(this_object());
     set_chat_chance(20);
     set_a_chat_chance(15);
     load_chat("Zyagx looks up at you from his work and grins.\n");
     load_chat("Zyagx mutters something about a fresh test subject.\n");
     load_a_chat("Zyagx slashes at you with his white dagger.\n");

     set_spell_mess1("Zyagx throws a bunch of chemicals at his foe!\n");
     set_spell_mess2("\nZyagx reaches into a pocket of his lab coat and douses you in chemicals!!!\n");
     set_chance(15);
     set_spell_dam(65);
     call_out("use_spell",15);

     gold = clone_object("obj/money");
     gold->set_money(random(2000)+1000);
     move_object(gold,this_object());
   }
  }


monster_died()  {
object ob;
   /* typo fix 4-01  verte */
  tell_room(environment(this_object()),
  "\nZyagx cackles insanely as he dies, glad for the release you have given him.\n");
  tell_room(environment(this_object()),
  "\nA howl is heard in the far off distance....\n");
  return 0;
        }


/* this func fixed by verte 4-01 */
use_spell()
{
    object target, HERE, e;
    int a;
    string foo;

    if(!(e = environment())) return;
    HERE = first_inventory(e);

    if(attacker_ob)
    {
      tell_room(e,
  "\nZyagx grabs for some chemicals and produces a huge ball of\n\n"+
  "        "+HIR+"FIRE"+NORM+"      \n\n");

      while(HERE)
      {
        if(attacker_ob && 
         ((foo = (string)HERE->query_name()) != "Zyagx the Mad Alchemist")
         && living(HERE) && ((int)HERE->query_attrib("luc") < random(30)))
        {
          tell_room(e,
   "\n" + foo + " staggers from the fury of the flame.\n");
   HERE->heal_self(-(random(60)+25));
        }
        
        if(HERE) HERE = next_inventory(HERE);
      }
    }

    call_out("use_spell", random(45));
}

