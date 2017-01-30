/*
 *  A Pet that you can find.
 *  The only command that it accepts is to attack (no backing off, etc.)
 *  It automaticially eats any corpse in the room (doesn't ask)
 *  The Drake automaticially takes off after a certain amount of time.
 *
 *  By Saber / Geoffrey Z.
 *
 */

inherit "/obj/monster";
#include "/players/saber/closed/ansi.h"

string master_name;
object mark;
int BYE_BYE;

#define OB this_object()
#define MASTER this_object()->query_master()
#define OWNER capitalize(this_object()->query_master())

reset(arg)  {
mark = clone_object("/players/saber/closed/bard/itm/bard_mark.c");
move_object(mark,this_object());
   ::reset(arg);
   if (!arg){
     set_name( "sun drake" );
     set_alias("pet");
     set_short("A Young Sun Drake");
     set_gender("creature");
     set_alt_name("drake");
     set_race(s"dragon");
     set_long("The Young Sun Drake is a creature of greyhound size, with golden scales\n"+
              "and molten claws.  It's tail is spiked, and breath emerges hot as the sun.\n"+
              "To command your Drake to attack, type < sicem > < monster >\n"+
              "To release your Drake, type < goodbye >\n");
     set_level(10);
     set_heal(3,20);
     set_ac(8);
     set_wc(14);
     set_hp(150);
     set_al(-500);
     set_aggressive(0);
     set_chat_chance(5);
     set_a_chat_chance(8);
     load_chat("The Young Sun Drake drifts on the thermals.\n");
     load_chat("The Young Sun Drake glances down at you.\n");
     load_a_chat("The Young Sun Drake ROARS!!!\n");
     load_a_chat("The Young Sun Drake lashes at it's foe with its tail.\n");
     load_a_chat("The Young Sun Drake buffets it's foe with it's wings.\n");
     set_spell_mess1("The Young Sun Drake breaths "+HIY+BOLD+"FLAME"+NORM+".");
     set_spell_mess2("The Young Sun Drake breaths "+HIY+BOLD+"FLAME"+NORM+" at you.");
     set_chance(10);
     set_spell_dam(10);
     enable_commands();
     set_dead_ob(this_object());
call_out("pet_follow",6);
   }
}


init()  {
  ::init();
  if(this_player()->query_real_name() == MASTER)  {

   add_action("bye","goodbye");
   add_action("sic","sicem");

        }
        }


bye()  {
object ob;
  say("The Young Sun Drake looks over at "+OWNER+".\n");
  say("The Drake screams once and flies off into the sky.\n");

  ob = present(MASTER, environment(OB));
    if(ob)  { transfer_all_to(ob);  }
  remove_call_out("pet_follow");
  destruct(OB);
  return 1;
        }


sic(str)  {
object ob;

  if(!str)  {  
    write("What would you like your Sun Drake to attack?\n");  return 1;  }
    
  if(!(ob = present(str, environment(this_object()))))  {
    write("There is no "+str+" here to attack.\n");  return 1;  }
    
  if(ob->is_player())  {
    write("The Sun Drake won't attack players.\n");  return 1;  }
    
  say(OWNER+" yells \""+Sic'em!\"\n");
  say("The Young Sun Drake screeches and lunges towards "+capitalize(str)+".\n");
  this_object()->attack_object(ob);
  return 1;
       }


monster_died()  {

  tell_room(environment(this_object()),
     "\nThe young Sun Drake falls to the ground in a pool of golden blood.\n\n");
  remove_call_out("pet_follow");

return 0;
        }


munch()  {
object corpse;
int heal;

  if(present("corpse", environment(OB)))  {

  corpse = present("corpse", environment(OB));

  say("\nThe Young Sun Drake descends upon the corpse and rips out its throat.\n"+
      "The Sun Drake laps up the blood with a tiny golden tongue.\n\n");

  heal=corpse->heal_value();
  destruct(corpse);
  heal_self(heal);
  return 1;
         }
         }


pet_follow()  {
string there, master;
object ob;
int HP_LVL;

there = find_player(MASTER);

if(!find_player(MASTER))  { bye(); }

  ob = find_player(MASTER);

if(!present(MASTER,environment(this_object())))  {
  say("The Young Sun Drake flies from the room after its master.\n");
  move_object(this_object(),environment(there));
  say("A Young Sun Drake flies into the room.\n");
        }

if(present("corpse", environment(this_object())))  munch();

BYE_BYE++;

if(BYE_BYE > 1000)  bye();

call_out("pet_follow",6);
  return 1;
        }


set_master(str)  {  master_name = str;  }
query_master()   {  return master_name; }
is_pet()         {  return 1; }
