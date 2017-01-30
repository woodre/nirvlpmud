/*
 *   A vampire mist found within the temple of Arate.
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
     
     set_name( "vampire mist" );
     set_short();
     set_alias("mist");
     set_alt_name("spirit");
     set_race("undead");
     set_long(
        ""+BOLD+"A deep "+HIR+"crimson"+NORM+""+BOLD+" and "+
        HIM+"purple"+NORM+""+BOLD+" vampire mist."+NORM+"\n");
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
     load_a_chat("The distant sound of chanting washes over you.\n");
     load_a_chat("The musky sweet smell of incense invades your senses.\n");
     set_chance(10);
     set_spell_dam(35);
     set_spell_mess1("The vampire mist saps the strength of its foe.");
     set_spell_mess2("The vampire mist saps your strength.");
     call_out("cast_spells",10);
 
        }
        }


monster_died()  {
object ob;
  tell_room(environment(this_object()), "\n"+
  "The vampire mist dissipates into the surrounding incense.\n"+
  "A blood filled corpse drops to the ground with a thud.\n\n");
  return 0;
        }


cast_spells()  {
object HERE, target;
int a, what_spell, HEAL;
string NAME;
  
  
HERE = first_inventory(environment(this_object()));

while(HERE)  {
  if(this_object()->query_attack())  {
  if(HERE->query_real_name() != "vampire mist")  {
 
  if(living(HERE))  {
   
  if(20 < random(28))  {
  NAME = HERE->query_name();
  what_spell = random(7);
  
  if(what_spell < 6)  {
    tell_room(environment(this_object()),
    "The "+HIM+"vampire mist"+NORM+" sends incandescent tendrils into "+NAME+".\n"+
    NAME+" looks weaker...\n");
    HEAL = random(20) + 1;
    HERE->heal_self(-HEAL);
    HERE->hit_player(1);
    this_object()->heal_self(HEAL);
        }
   if(what_spell == 6)  {
     tell_room(environment(this_object()),
     "The "+HIM+"vampire mist"+NORM+" surrounds you in "+BOLD+"darkness"+NORM+".\n");
     target = clone_object("/players/saber/closed/toys/dark.c");
     move_object(target,environment(this_object()));
        }
    
        }
        }
        }
        }
HERE = next_inventory(HERE);
        }        
call_out("cast_spells",random(20));
  return 1;
        }
