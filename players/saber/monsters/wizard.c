/*
 *   A spell casting wizard.
 *
 */

inherit "/obj/monster";
#include "/players/saber/closed/esc2.h"
#include "/players/saber/closed/ansi.h"

object ob, ob2, ob6, gold;
int which;

reset(arg) {

  ::reset(arg);   
if (!arg){

  gold = clone_object("obj/money");
    gold->set_money(2050 + random(500));
    move_object(gold,this_object());

  ob = clone_object("/players/saber/weapons/warstaff.c");
    move_object(ob,this_object());
  ob2 = clone_object("/players/saber/armor/bracerpro.c");
    move_object(ob2, this_object());
  ob6 = clone_object("/players/saber/armor/ringpro.c");
    move_object(ob6, this_object());

     init_command("wield staff");
     init_command("wear ring");
     init_command("wear bracers");
     
     set_name("silent wizard");       
     set_short("The Silent Wizard");
     set_alias("wizard");      
     set_race("human");

     set_long(
      "The Silent Wizard is a might sorceror of the order of the Iron Staff,\n"+
      "renoun for his ferocity in combat and savage genius in the dark arts\n"+
      "of necromancy.  Do not cross him lightly.\n");

     set_gender("male");
     set_level(21);
     set_ac(20);
     set_wc(25);
     set_hp(650);
     set_al(-1000);
     set_heal(5,25);
     set_aggressive(0);
     set_chat_chance(5);
     set_a_chat_chance(5);
     set_dead_ob(this_object());
     load_chat("The candles flicker.\n");
     load_chat("The candles flicker.\n");
     load_chat("The Silent Wizard lights a candle.\n");
     load_chat("The Silent Wizard makes strange gestures.\n");
     load_a_chat("The Silent Wizard blows out a candle.\n");
     load_a_chat("The Silent Wizard points at you.\n");
     call_out("cast_spells",10);
 
set_object(this_object());
   set_function("hi_there");
   set_type("arrives");
   set_match("");
        }
        }

hi_there(str) {
string who;
if(sscanf(str, "%s arrives.", who) == 1)  {
  say("The silent wizard closes his book at looks up at "+who+".\n");
  }  }


monster_died()  {
object ob;
  tell_room(environment(this_object()), "\n"+
  "As the Silent Wizard slumps to the ground, a wisp of form streams from\n"+
  "his body and whirls out of the cavern.\n\n");
  return 0;
        }


cast_spells()  {
object HERE, target, FIRE, ITEM;
int a, what_spell, AC;
string NAME, OBJ, ITEM_NAME;
 

HERE = first_inventory(environment(this_object()));

while(HERE)  {
  if(this_object()->query_attack())  {
  if(HERE->query_real_name() != "silent wizard" )  {

  if(living(HERE))  {
   
  if(20 < random(31))  {

  NAME = HERE->query_name();
  OBJ = HERE->query_objective();

  what_spell = random(11);
  
  if(what_spell == 0)  {
    tell_room(environment(this_object()),
    "\nThe Silent Wizard blasts "+NAME+" with a "+HIR+BOLD+"LIGHTNING BOLT"+NORM+".\n\n");
    HERE->hit_player(25);
        }

  if(what_spell == 1)  {
    tell_room(environment(this_object()),
    "\nThe Silent Wizard drinks a potion of healing.\n\n");
    heal_self(25);
        }

  if(what_spell == 2)  {
    tell_room(environment(this_object()),
    "\nThe Silent Wizard grabs "+NAME+" and casts "+BOLD+"SHOCKING GRASP"+NORM+".\n"+
    NAME+" stumbles and falls.\n\n");
    HERE->hit_player(25);
        }

  if(what_spell == 3)  {
    tell_room(environment(this_object()),
    "\nThe Silent Wizard casts "+HIR+"BURNING HANDS"+NORM+" on "+NAME+".\n"+
    NAME+" is covered by a sheet of roaring "+HIR+"flames"+NORM+".\n\n");
    HERE->hit_player(20);
        }

   if(what_spell == 4)  {
     tell_room(environment(this_object()),
     "\nThe Silent Wizard casts a spell of "+BOLD+"DARKNESS"+NORM+".\n\n");
     target = clone_object("/players/saber/closed/bards/dark.c");
     move_object(target,environment(this_object()));
        }

   if(what_spell == 5)  {
     tell_room(environment(this_object()),
     "\nThe Silent Wizard casts "+BOLD+"MIRROR IMAGE"+NORM+".\n"+
     "\nYou have a harder time getting a fix upon the Silent Wizard.\n\n");
     AC = this_object()->query_ac() + 1;
     this_object()->set_ac(AC);
        }

   if(what_spell == 6)  { 
     tell_room(environment(this_object()),
     "\nThe Silent Wizard casts "+BOLD+"REVERSE GRAVITY"+NORM+" on "+NAME+"\n");
     tell_room(environment(this_object()), "\n"+
     NAME+" falls up into the air and crashes into the ceiling.\n\n"+
     "The Silent Wizard ends the spell.\n\n"+
     NAME+" falls and lands with a harsh  > > SPLAT < <\n\n");
     HERE->hit_player(35);   
        }  

   if(what_spell == 7)  { 
     tell_room(environment(this_object()),
     "\nThe Silent Wizard speaks the Power Word\n\n"+
     "                                "+BOLD+"> >  S T U N  < <"+NORM+"\n\n"+
     NAME+" staggers back a step.\n");
    
      ITEM = first_inventory(HERE);
      while(ITEM)  {
        if(ITEM->armor_class()  > 0 ||
           ITEM->weapon_class() > 0 )  { 
          ITEM_NAME = ITEM->query_name();
          ITEM_NAME = lower_case(ITEM_NAME);
        command("drop "+ITEM_NAME, HERE);
        }
      ITEM = next_inventory(ITEM);
        }  
        }

  if(what_spell == 8)  {
    tell_room(environment(this_object()),
    "\nThe Silent Wizard casts summons "+HIR+"FLAME ARROW"+NORM+".\n"+
    "The Silent Wizard points at "+NAME+".\n\n"+
    HIR+""+NAME+" bursts into flames!"+NORM+"\n");
    tell_room(environment(this_object()),  ""+NORM+"\n");
    FIRE = clone_object("/players/saber/closed/toys/fire.c");
    move_object(FIRE,HERE);
    call_other(FIRE, "poison");
        }

  if(what_spell == 9)  { 
     tell_room(environment(this_object()),
     "\nThe Silent Wizard casts "+BOLD+"TELEKINESIS"+NORM+" on "+NAME+"\n");
     tell_room(environment(this_object()), "\n"+
     NAME+" is hurled back into a wall.\n\n"+
     NAME+" flies sideways into another wall.\n\n"+
     "The Silent Wizard smiles.\n\n");
     HERE->hit_player(35);   
        }

  if(what_spell == 10)  { 
    if(HERE->is_pet())  {
     tell_room(environment(this_object()),
     "\nThe Silent Wizard casts "+BOLD+"DEATH SPELL"+NORM+" on "+NAME+".\n");
     tell_room(environment(this_object()), "\n"+
     NAME+" implodes in a shower of blood.\n\n");
     HERE->hit_player(800);
        }  }
        
        }
        }
        }
        }
if(present("corpse", environment(this_object())))  animate();
HERE = next_inventory(HERE);
        }        
call_out("cast_spells",random(35));
  return 1;
        }


animate()  {
object corpse, dead;

 if(corpse = present("corpse", environment(this_object())))  {
 
 dead = clone_object("/players/saber/monsters/zombie.c");
 corpse->transfer_all_to(dead);
 move_object(dead, environment(this_object()));
 
 tell_room(environment(this_object()), "\n"+
 corpse->short()+" rises from the dead!\n\n");
 
 destruct(corpse);
 
 return 0;
 }
 }
 
