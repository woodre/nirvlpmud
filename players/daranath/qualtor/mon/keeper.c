inherit "/obj/monster";

#include "/players/saber/closed/esc.h"
#include <ansi.h>

reset(arg) {
  object gold;
   ::reset(arg);
   if (!arg) {

move_object(clone_object("/players/daranath/qualtor/obj/keep_armor.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/obj/keep_gaunt.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/obj/keep_helm.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/wep/battle_ch.c"),this_object());

     set_name("Keeper of the Red Tower");
     set_short("A man stands before the hearth");
     set_alias("man");
     set_alt_name("keeper");
     set_race("human");
     set_gender("male");
     set_long("The man lounging upon the soft furniture seems to have been awaiting\n"+
              "your approach. He is fully armored in a dark burnished metal, \n"+
              "while the only object he is holding is a small\n"+
              "metallic ball. He glares at your approach.\n");
     set_level(24);

     init_command("wear armor");
     init_command("wield charger");
     init_command("wear gauntlets");
     init_command("wear helm");

     set_ac(26);
     set_wc(44 + random(4));
     set_hp(1200 + random(120));
/* NEW CODE -Snow 5/00 */
set_wc_bonus(23);
     set_al(-1200);
     set_aggressive(0);
     set_dead_ob(this_object());
     set_chat_chance(12);
     set_a_chat_chance(20);
     load_chat("The Keeper speaks: So, you saw through my little illusion. I'm impressed.\n");
     load_chat("The Keeper speaks: What brings you to my home?\n");
     load_chat("The Keeper growls: Begone!!!  You are not welcome here.\n");
     load_a_chat("The Battle Charger hums with a life of its own.\n");
     load_a_chat("The Battle Charger flashes with an electrical energy.\n");
     load_a_chat("The Keeper of the Tower growls at you in a language you cannot understand.\n");

     set_spell_mess1("Keeper of the Tower casts a spell at his foe!\n");
     set_spell_mess2("\nKeeper of the Tower casts an electrical spark at you!!!\n\n");
     set_chance(15);
     set_spell_dam(80);
     call_out("use_spell",15);

     gold = clone_object("obj/money");
     gold->set_money(random(3000)+2500);
     move_object(gold,this_object());
   }
  }


monster_died()  {
  write_file("/players/daranath/closed/log/keep_death",ctime(time())+"\t"+
    (this_object()->query_attack())->query_real_name()+"\t\t"+
    (this_object()->query_attack())->query_level()+"\n");
}

use_spell()  {
object target, HERE;
int a;

  if(!environment(this_object())) return 1;

HERE = first_inventory(environment(this_object()));

if(!environment(this_object())) {return 1; }
if(this_object()->query_attack())  {
tell_room(environment(this_object()),
  "\nKeeper of the Tower casts a spell and unleashes a\n\n"+
  "        "+YEL+"BOLT OF LIGHTNING"+NORM+"      \n\n");


while(HERE)  {
  if(this_object()->query_attack())  {
  if(HERE->query_name() != "Keeper of the Red Tower")  {
  if(living(HERE))  {
  if(call_other(HERE, "query_attrib", "luc") < random(41))  {
  tell_room(environment(this_object()),
  "\n"+HERE->query_name()+" staggers from the electrical blast.\n");
/*
   HERE->heal_self(-(random(90)+35));
*/
/* Feldegast 10-15-01 */
   HERE->do_damage(35+random(90), "other|electricity");
        }
        }
        }
        }
/* if(HERE) check added [5.23.2001] by Vertebraker */
if(HERE) HERE = next_inventory(HERE);
        }
        }
call_out("use_spell",random(45));
  return 1;
        }
