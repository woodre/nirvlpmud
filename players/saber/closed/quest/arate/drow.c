/*
 *   A drow warrior found within the temple of Arate.
 *
 */

inherit "/obj/monster";
#include "/players/saber/closed/esc.h"
#include "/players/saber/closed/ansi.h"

object ob, ob2, ob3, ob4, ob5, ob6, ob7, ob8;

reset(arg) {

  ob = clone_object("/players/saber/weapons/drow_dagger.c");
    move_object(ob,this_object());
  ob2 = clone_object("/players/saber/weapons/drow_ss.c");
    move_object(ob2, this_object());
  ob3 = clone_object("/players/saber/weapons/drow_hc.c");
    move_object(ob3, this_object());
  ob4 = clone_object("/players/saber/armor/drow_boots.c");
    move_object(ob4, this_object());
  ob5 = clone_object("/players/saber/armor/drow_cloak.c");
    move_object(ob5, this_object());
  ob6 = clone_object("/players/saber/armor/medallion.c");
    move_object(ob6, this_object());
  ob7 = clone_object("/players/saber/armor/drow_shield.c");
    move_object(ob7, this_object());
  ob8 = clone_object("/players/saber/armor/drow_chainmail.c");
    move_object(ob8, this_object());

  ::reset(arg);   
if (!arg){

     init_command("wield sword");
     init_command("wear chainmail");
     init_command("wear shield");
     init_command("wear boots");
     init_command("wear cloak");
     init_command("wear medallion");
     
     set_name("drow warrior");
     set_short("A drow warrior");
     set_alias("warrior");
     set_race("drow");
     set_long(
        BOLD+"The drow warrior is a dark shadow, hidden within the depths\n"+
        "of its inky black cloak.  From beneith the darkness you can\n"+
        "just descern a pair of "+HIR+"crimson"+NORM+""+BOLD+" eyes, "+
        "staring directly at you.  \nBeware the power of the Drow..."+NORM+"\n");
     set_gender("male");
     set_level(21);
     set_ac(17);
     set_wc(30);
     set_hp(575);
     set_al(-1000);
     set_heal(5,25);
     set_aggressive(0);
     set_chat_chance(5);
     set_a_chat_chance(5);
     set_dead_ob(this_object());
     load_chat("The drow laughs \"This is how you hold court?  You let that in?\"\n");
     load_chat("The drow studies you.\n"); 
     load_chat("The drow hisses \"Would you like me to dispose of this for you?\"\n");
     load_a_chat("The drow dodges your attack.\n");
     load_a_chat("The drow slams another bolt into his hand crossbow.\n");
     set_chance(10);
     set_spell_dam(35);
     set_spell_mess1("The drow warrior fires a hand crossbow at his foe.");
     set_spell_mess2("The drow warrior fires his hand crossbow at you.");
     call_out("cast_spells",10);
    enable_commands();
 
set_object(this_object());
   set_function("hi_there");
   set_type("arrives");
   set_match("");
        }
        }

hi_there(str) {
string who;
if(sscanf(str, "%s arrives.", who) == 1)  {
  say("The drow warrior studies "+who+".\n");
}  }


monster_died()  {
object ob;
  tell_room(environment(this_object()), "\n"+
  "The drow warrior slumps to the ground, blood dripping from his dark lips.\n\n");
  return 0;
        }


cast_spells()  {
object HERE, spider, target;
int a, what_spell;
string NAME;
 
 if(this_object()->query_attack())  {
 if(present("spider", environment(this_object())))  {
   spider = present("spider", environment(this_object()));
     if(!spider->query_attack())  {   
     target = this_object()->query_attack();
     spider->attack_object(target);
     tell_room(environment(this_object()),
         "The drow warrior orders the spider to attack.\n");
     if(living(target)) target->attack_object(this_object());
        }  
        }
        }
 
HERE = first_inventory(environment(this_object()));

while(HERE)  {
  if(this_object()->query_attack())  {
  if(HERE->query_real_name() != "drow warrior"  &&
     HERE->query_real_name() != "giant spider"      )  {
  if(living(HERE))  {
   
  if(20 < random(34))  {
  NAME = HERE->query_name();
  what_spell = random(8);
  
  if(what_spell == 0 || what_spell == 1)  {
    tell_room(environment(this_object()),
    "\nThe drow warrior slashes "+NAME+" with his adamantite dagger.\n\n");
    HERE->hit_player(15);
        }
  if(what_spell == 2)  {
    tell_room(environment(this_object()),
    "\nThe drow warrior fires a poisoned bolt into "+NAME+".\n\n");  
    target = clone_object("/players/saber/closed/poison.c");
    move_object(target,HERE);
    call_other(target, "poison");
        }
  if(what_spell == 3)  {
    tell_room(environment(this_object()),
    "\nThe drow warrior casts "+HIM+"faerie fire"+NORM+" on "+NAME+".\n"+
    HIM+""+NAME+""+NORM+" begins to glow."+NORM+"\n\n");
        }
   if(what_spell == 4)  {
     tell_room(environment(this_object()),
     "\nThe drow warrior casts a spell of "+BOLD+"darkness"+NORM+".\n\n");
     target = clone_object("/players/saber/closed/toys/dark.c");
     move_object(target,environment(this_object()));
        }
   if(what_spell == 5)  {
     tell_room(environment(this_object()),
     "\nThe drow warrior casts a spell.\n"+
     "\nThree balls of "+HIR+"flame"+NORM+" materialize and surround "+NAME+".\n\n");
     target = clone_object("/players/saber/effects/dancing_lights.c");
     move_object(target,environment(this_object()));
        }
   if(what_spell == 6)  { 
     tell_room(environment(this_object()),
     "\nThe drow warrior casts "+BOLD+"levitate"+NORM+" on "+NAME+"\n");
     tell_room(environment(this_object()), "\n"+
     NAME+" rises up into the air.\n\n"+
     "The drow warrior ends the spell.\n\n"+
     NAME+" falls and lands with a harsh >>THUD<<\n\n");
     HERE->hit_player(35);   
        }  
   if(what_spell == 7)  {
     tell_room(environment(this_object()),
     "\nThe drow warrior takes a potion from his pouch and drinks it.\n"+
     "The drow warrior looks stronger.\n\n");
     this_object()->heal_self(40);
        }
    
        }
        }
        }
        }
HERE = next_inventory(HERE);
        }        
call_out("cast_spells",random(32));
  return 1;
        }
