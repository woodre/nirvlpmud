/*
 *   A demon found within the temple of Arate.
 *
 */

inherit "/obj/monster";
#include "/players/saber/closed/esc.h"
#include "/players/saber/closed/ansi.h"

object ob, ob2, ob4, ob6, gold;

reset(arg) {

  gold = clone_object("obj/money");
    gold->set_money(2300 + random(500));
    move_object(gold,this_object());
  ob4 = clone_object("/players/saber/gems/bloodstone.c");
    move_object(ob4,this_object());
  ob = clone_object("/players/saber/weapons/demonwhip.c");
    move_object(ob,this_object());
  ob2 = clone_object("/players/saber/weapons/smoke_sword.c");
    move_object(ob2, this_object());
  ob6 = clone_object("/players/saber/armor/medallion.c");
    move_object(ob6, this_object());

  ::reset(arg);   
if (!arg){

     init_command("wield sword");
     init_command("wear medallion");
     
     set_name("glabrezu");
     set_short("A glabrezu demon");
     set_race("demon");
     set_long(
      "The glabrezu is a towering, broad and well-muscled demon with four\n"+
      "arms.  Two of the glabrezus arms end in hands with wicked claws,\n"+
      "while the other two end in large and powerful pincers.  It has a dog-\n"+
      "like head, and a wide snarling mouth filled with fangs.  The glabrezu\n"+
      "has deep russet skin and penetrating violet eyes.\n");
     set_gender("creature");
     set_level(22);
     set_ac(17);
     set_wc(30);
     set_hp(625);
     set_al(-1000);
     set_heal(5,25);
     set_aggressive(0);
     set_chat_chance(6);
     set_a_chat_chance(5);
     set_dead_ob(this_object());
     load_chat("The glabrezu whips the prisoner.\n");
     load_chat("The glabrezu cracks its whip.\n");
     load_chat("The glabrezu runs its claws across the prisoner's back.\n");
     load_chat("The glabrezu growls at you.\n");
     load_chat("The prisoner screams for mercy.\n");
     load_chat("The glabrezu shakes the prisoner to make sure he is still conscious.\n"); 
     load_a_chat("The glabrezu cracks its whip.\n");
     load_a_chat("The glabrezu screams \"Kah sha fu shik ra\".\n");
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
  say("The glabrezu looks at "+who+".\n"+
  "Glabrezu whispers \"Welcome "+who+".  Welcome to hell...\"\n"+
  "The glabrezu begins to whips the prisoner.\n");
}  }


monster_died()  {
object ob;
  tell_room(environment(this_object()), "\n"+
  "The glabrezu explodes in a burst of flame as it is banished back to the Abyss.\n"+
  "The glabrezu's mortal shell falls to the ground.\n\n");
  return 0;
        }


cast_spells()  {
object HERE, target, FIRE, ITEM;
int a, what_spell, AC;
string NAME, OBJ, ITEM_NAME;
 

HERE = first_inventory(environment(this_object()));

while(HERE)  {
  if(this_object()->query_attack())  {
  if(HERE->query_real_name() != "drow priestess"  &&
     HERE->query_real_name() != "giant spider"    &&
     HERE->query_real_name() != "artist"          &&
     HERE->query_real_name() != "initiate"        &&
     HERE->query_real_name() != "glabrezu"      )  {
  if(living(HERE))  {
   
  if(20 < random(31))  {
  NAME = HERE->query_name();
  OBJ = HERE->query_objective();
  what_spell = random(11);
  
  if(what_spell == 0 || what_spell == 1)  {
    tell_room(environment(this_object()),
    "\nThe glabrezu demon slashes "+NAME+" with its huge pincers.\n\n");
    HERE->hit_player(random(30)+1);
        }
  if(what_spell == 2)  {
    tell_room(environment(this_object()),
    "\nThe glabrezu demon grabs "+NAME+" and lifts "+OBJ+" off the ground.\n"+
    "Glabrezu rakes "+NAME+" with its huge pincers, and then hurls "+OBJ+" across the room.\n\n");
    HERE->hit_player(random(25)+1);
    HERE->hit_player(random(15)+1);
        }
  if(what_spell == 3)  {
    tell_room(environment(this_object()),
    "\nThe glabrezu demon casts "+HIR+"burning hands"+NORM+" on "+NAME+".\n"+
    NAME+" is covered by a sheet of roaring flames.\n\n");
    HERE->hit_player(random(30)+1);
        }
   if(what_spell == 4)  {
     tell_room(environment(this_object()),
     "\nThe glabrezu demon casts a spell of "+BOLD+"darkness"+NORM+".\n\n");
     target = clone_object("/players/saber/closed/bards/dark.c");
     move_object(target,environment(this_object()));
        }
   if(what_spell == 5)  {
     tell_room(environment(this_object()),
     "\nThe glabrezu demon casts a "+BOLD+"Mirror Image"+NORM+".\n"+
     "\nYou have a harder time getting a fix upon the glabrezu demon .\n\n");
     AC = this_object()->query_ac() + 1;
     this_object()->set_ac(AC);
        }
   if(what_spell == 6)  { 
     tell_room(environment(this_object()),
     "\nThe glabrezu demon casts "+BOLD+"reverse gravity"+NORM+" on "+NAME+"\n");
     tell_room(environment(this_object()), "\n"+
     NAME+" falls up into the air and crashes into the ceiling.\n\n"+
     "The glabrezu demon ends the spell.\n\n"+
     NAME+" falls and lands with a harsh >>SPLAT<<\n\n");
     HERE->hit_player(random(15) + 30);   
        }  
   if(what_spell == 7)  { 
     tell_room(environment(this_object()),
     "\nThe glabrezu demons speaks the power word\n\n"+
     "                                "+BOLD+"> >  S T U N  < <"+NORM+"\n\n"+
     NAME+" staggers back a step.\n");
    
      ITEM = first_inventory(HERE);
      while(ITEM)  {
        if(ITEM->armor_class()  > 0 ||
           ITEM->weapon_class() > 0 )  { 
          ITEM_NAME = ITEM->query_name();
          ITEM_NAME = lower_case(ITEM_NAME);
        command("drop "+ITEM_NAME, lower_case(NAME));
        }
      ITEM = next_inventory(ITEM);
        }  
        }
  if(what_spell == 8)  {
    tell_room(environment(this_object()),
    "\nThe glabrezu demon casts summons "+HIR+"FLAME"+NORM+".\n"+
    "The glabrezu demon points at "+NAME+".\n\n"+
    HIR+""+NAME+" bursts into flames!"+NORM+"\n");
    tell_room(environment(this_object()),  ""+NORM+"\n");
    FIRE = clone_object("/players/saber/closed/toys/fire.c");
    move_object(FIRE,HERE);
    call_other(FIRE, "poison");
        }
  if(what_spell == 9)  { 
     tell_room(environment(this_object()),
     "\nThe glabrezu demon casts "+BOLD+"telekinesis"+NORM+" on "+NAME+"\n");
     tell_room(environment(this_object()), "\n"+
     NAME+" is hurled back into a wall.\n\n"+
     NAME+" flies sideways into another wall.\n\n"+
     "The galbrezu demon laughs.\n\n");
     HERE->hit_player(random(15) + 30);   
        }
  if(what_spell == 10)  { 
    if(HERE->is_pet())  {
     tell_room(environment(this_object()),
     "\nThe glabrezu demon grabs "+NAME+" and rips its head off.\n");
     tell_room(environment(this_object()), "\n"+
     "The glabrezu demon drains "+NAME+"'s blood.\n"+ 
     "Laughing, the glabrezu hurls the corpse across the room.\n"+ 
     "The galbrezu demon laughs.\n\n");
     HERE->hit_player(500);
        }  }
        
        }
        }
        }
        }
HERE = next_inventory(HERE);
        }        
call_out("cast_spells",random(35));
  return 1;
        }
