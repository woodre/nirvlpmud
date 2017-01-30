/*
 *   A wraith found within the temple of Arate.
 *
 */

inherit "/obj/monster";
#include "/players/saber/closed/esc.h"
#include "/players/saber/closed/ansi.h"

object ob;
int gem;

reset(arg) {

  for(gem = 0; gem < 5; gem++)  { 
  ob = clone_object("/players/saber/gems/ruby.c");
    move_object(ob,this_object());
        }

  ::reset(arg);   
if (!arg){
     
     set_name("wraith");
     set_short("A "+BOLD+"shadowy"+NORM+" wraith");
     set_alias("spirit");
     set_race("undead");
     set_long(
        BOLD+"A shadowy wraith from the negative material plane.\n"+
        "The wraith radiates an aura of cold evil."+NORM+"\n");
     set_gender("creature");
     set_level(21);
     set_ac(17);
     set_wc(30);
     set_hp(525);
     set_al(-1000);
     set_heal(5,25);
     set_aggressive(0);
     set_chat_chance(5);
     set_a_chat_chance(5);
     set_dead_ob(this_object());
     load_chat("The distant sound of chanting washes over you.\n");
     load_chat("The musky sweet smell of incense invades your senses.\n");
     load_chat("The wraith hisses \"\Feeeeedssssss meeeeessssss\"\n"); 
     load_a_chat("The distant sound of chanting washes over you.\n");
     load_a_chat("The musky sweet smell of incense invades your senses.\n");
     load_a_chat("The wraith fades into a shadow.\n");
     load_chat("The wraith hisses \"\Feeeeedssssss meeeeessssss\"\n"); 
     call_out("drain_life",10);
 
        }
        }


monster_died()  {
object ob;
  tell_room(environment(this_object()), "\n"+
  BOLD+"The wraith explodes in a burst of negative plane energy."+NORM+"\n"+
  "A bloodless corpse drops to the ground with a thud.\n\n");
  return 0;
        }


drain_life()  {
object HERE, target;
int a, HEAL, XP_LOSS;
string NAME;
  
  
HERE = first_inventory(environment(this_object()));

while(HERE)  {
  if(this_object()->query_attack())  {
  if(this_object()->query_name() != "wraith")  {
  if(living(HERE))  {
   
  if(20 < random(28))  {

  NAME = HERE->query_name();
 
    tell_room(environment(this_object()),
    "The "+BOLD+"wraith"+NORM+" touches "+NAME+".\n"+
    "There is an explosion of "+BOLD+" negative plane energy."+NORM+"\n"+
    NAME+" looks weaker..."+NORM+"\n");

  if(HERE->is_player())  {
    HEAL = HERE->query_level();
    XP_LOSS = HEAL * (random(135) + 1);
    HERE->add_exp(-XP_LOSS);
    this_object()->add_hit_point(HEAL * (random(6) + 1));
  }  else  {
    HEAL = HERE->query_level() * 2;
    HERE->hit_player(HEAL);
    this_object()->heal_self(HEAL);
        }
    
        }
        }
        }
        }
HERE = next_inventory(HERE);
        }        
call_out("drain_life",random(100));
  return 1;
        }
