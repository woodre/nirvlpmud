/*
 *    Wind as a Weapon.
 *    By Saber / Geoffrey Z.
 */

#define tp this_player()->query_name()
#include "/players/saber/closed/ansi.h"

int w, NUMBER;
object smoke;
inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("wind");
    set_alias("sword");
    set_type("element");         /* set type added by Pavlik */
    set_alt_name("globe");
    set_short(BOLD+"Wind"+NORM);
    set_long("You hold living wind, forged into a globe by the Air Elves of Niva.\n"+
             "In you hand the globe emits the low whistle of drifting leaves.\n");
    set_read("Who are you to read the wind?.\n");
    set_class(18);
    set_weight(0);
    set_value(2000);
    set_hit_func(this_object());
}

weapon_hit(attacker){
   w=random(60);
   
   if(w > 58)  {
     write("\nYou briefly lose control of the "+BOLD+"WIND"+NORM+".\n\n");
     this_player()->heal_self(-random(6));
        }
     
   if(w<5)    {
      tell_room(environment(this_player()), "\n"+
      "\nA great "+BOLD+"WIND"+NORM+" blows "+attacker->query_name()+" high up into"+
      " the air and then\n   > > >  S M A S H E S  < < <  "+attacker->query_objective()+
      "  into the ground.\n\n");
   NUMBER = 9;
              }
     
   if(w > 4 && w < 10)  {
     tell_room(environment(this_player()),
      "\nHowling "+BOLD+"WIND"+NORM+" > >  S L A M S  < <  "+attacker->query_name()+
      " backwards into a solid wall of air.\n\n");
   NUMBER = 8;
               }
               
   if(w > 9 && w < 15)  {
     tell_room(environment(this_player()),
      "\nThundering "+BOLD+"WIND"+NORM+" picks "+attacker->query_name()+
      " high up into the air and then\n    > > >  H A M M E R S  < < <    "
      +attacker->query_objective()+" into the ground.\n\n");
   NUMBER = 6;
               }

 if(w > 14 && w < 20)  {
     tell_room(environment(this_player()),
      "\nScreaming "+BOLD+"WIND"+NORM+" > > >  T E A R S  < < <  into "
      +attacker->query_name()+"'s skin.\n\n");
    NUMBER = 5;
               }

   if(w < 20) return NUMBER;
          
      return;
        }
