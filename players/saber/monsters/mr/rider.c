/*
 *   A spell casting wizard on griffonback.
 *
 */

inherit "/obj/monster";
#include "/players/saber/closed/esc2.h"
#include "/players/saber/closed/ansi.h"

object ob, ob2, ob4, ob6, gold;
int which, ALIVE;

reset(arg) {
  ::reset(arg);   
if (!arg){

  gold = clone_object("obj/money");
    gold->set_money(3750 + random(500));
    move_object(gold,this_object());

  ob6 = clone_object("/players/saber/armor/lboots.c");
    move_object(ob6, this_object());
  ob4 = clone_object("/players/saber/armor/armorcloak.c");
    move_object(ob4, this_object());
  ob2 = clone_object("/players/saber/armor/lgloves.c");
    move_object(ob2, this_object());
     init_command("wear cloak");
     init_command("wear gloves");
     init_command("wear boots");
     
which = random(2);

if(which == 0)  {  set_name("a wizard riding griffonback");         }
if(which == 1)  {  set_name("an enchantress riding griffonback");    }

if(which == 0)  {  set_short("A Wizard riding Griffonback");         }
if(which == 1)  {  set_short("An Enchantress riding Griffonback");   }
     
if(which == 0)  {  set_alias("wizard");        }
if(which == 1)  {  set_alias("enchantress");   }

     set_race("griffon");

     set_long(
      "The Griffon Riders of Niva are renoun both for their ferousity and their\n"+
      "legendary spell casting ability.  They wear blue and red - blue for the\n"+
      "skies they fly and red to symbolize their infernal blood magic.\n");

if(which == 0)  {  set_gender("male");    }
if(which == 1)  {  set_gender("female");  }

     set_level(20);
     set_ac(17);
     set_wc(30);
     set_hp(600);
     set_al(-950);
     set_heal(4,25);
     set_aggressive(0);
     set_chat_chance(5);
     set_a_chat_chance(5);
     set_dead_ob(this_object());
     load_chat("The griffon drifts in the thermals.\n");
     load_chat("The warm thermals drift gently across your skin.\n");
     load_a_chat("The griffon screeches!\n");
     load_a_chat("The griffon circles round you.\n");
     call_out("cast_spells",10);
 

        }
        }



monster_died()  {
object ob;
  tell_room(environment(this_object()), "\n"+
   "\nThe Griffon staggers, blood flowing from it's numerous wounds.\n\n"+
   "The Griffon's corpse slowly drifts up towards the sun.\n\n");
  return 0;
        }


cast_spells()  {
object HERE, target, FIRE, ITEM;
int a, what_spell, AC;
string NAME, OBJ, ITEM_NAME, ALIAS;
 
if(!environment(this_object())) return 1;
if(query_hp() < 200) rider_dies();

if(ALIVE > 0)  return 1;

HERE = first_inventory(environment(this_object()));

while(HERE)  {
  if(this_object()->query_attack())  {
  if(HERE->query_real_name() != "griffon" &&
     HERE->query_real_name() != "a wizard riding griffonback" &&
     HERE->query_real_name() != "an enchantress riding griffonback" )  {

  if(living(HERE))  {
 
  if(20 < random(35))  {

  NAME = HERE->query_name();
  OBJ = HERE->query_objective();
     
  what_spell = random(7);
  
  if(what_spell == 0)  {
    tell_room(environment(this_object()),
    "\n"+short()+" blasts "+NAME+" with a "+HIR+BOLD+"LIGHTNING BOLT"+NORM+".\n\n");
    HERE->hit_player(random(50));
        }
  
   if(what_spell == 1)  {
     tell_room(environment(this_object()),
     "\n"+short()+" casts "+BOLD+"MIRROR IMAGE"+NORM+".\n"+
     "\nYou have a harder time getting a fix upon the griffon.\n\n");
     AC = this_object()->query_ac() + 1;
     this_object()->set_ac(AC);
        }

  if(what_spell == 2)  {
    tell_room(environment(this_object()),
    "\n"+short()+" casts summons "+HIR+"FLAME ARROW"+NORM+".\n"+
    ""+short()+" points at "+NAME+".\n\n"+
    HIR+""+NAME+" bursts into flames!"+NORM+"\n");
    tell_room(environment(this_object()),  ""+NORM+"\n");
    FIRE = clone_object("/players/saber/closed/toys/fire.c");
    move_object(FIRE,HERE);
    call_other(FIRE, "poison");
        }

  if(what_spell == 3)  {
    tell_room(environment(this_object()),
    "\n"+short()+" fries "+NAME+" with a "+HIR+BOLD+"FIRE BALL"+NORM+".\n\n");
    HERE->hit_player(random(50));
        }

  if(what_spell == 4)  {
    tell_room(environment(this_object()),
    "\n"+short()+" points at "+NAME+" with a one finger.\n"+
    NAME+"'s "+HIR+BOLD+"BLOOD"+NORM+" begins to "+HIR+BOLD+"BOIL"+NORM+".\n\n");
    HERE->hit_player(random(50));
        }

  if(what_spell == 5)  {
    tell_room(environment(this_object()),
    "\n"+short()+" stuns "+NAME+" with a "+HIB+BOLD+"GUST OF WIND"+NORM+".\n\n");
    HERE->hit_player(random(30));
        }

  if(what_spell == 6)  {
    tell_room(environment(this_object()),
    "\n"+short()+" points at "+NAME+".\n"+
    NAME+" slams into a "+HIB+BOLD+"WALL OF AIR"+NORM+".\n\n");
    HERE->hit_player(random(30));
        }   
       
        }
        }
        }
        }
   
HERE = next_inventory(HERE);
        }        
   
call_out("cast_spells",random(35));
  return 1;
        }


rider_dies()  {

   ALIVE = 1;

   tell_room(environment(this_object()), "\n"+
   short()+" slumps in "+query_possessive()+" straps, "+
   "mortally wounded.\n"+
   "The Griffon mount screams in rage!\n\n");
   
   set_name("griffon");
   set_short("A large Griffon"); 
   set_alias("griffon"); 
   set_gender("creature");
   set_long("A large griffon with dusky wings and a blood tipped beak.\n"+
            "Strapped to it's back is a figure dressed in blue and red.\n");

        }
