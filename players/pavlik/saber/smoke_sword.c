/*
 *    The smoke sword of the Glabrezu demon.
 */

#define tp this_player()->query_name()
#include "/players/saber/closed/esc.h"
#include "/players/saber/closed/ansi.h"

int w, NUMBER;
object smoke;
inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("smoke sword");
    set_alias("sword");
    set_type("sword");         /* set type added by Pavlik */
    set_short("The two bladed "+BOLD+"smoke sword"+NORM+" of Kyorlin");
    set_long("A cold steel adamantite alloy forged into a two bladed sword.\n"+
             "The two blades of the smoke sword are joined in a common hilt\n"+
             "in the fashion of a pole sword.  One blade of the smoke sword\n"+
             "is covered in runes of silver, while the other has runes which\n"+
             "appear to have been written in smoke.\n");
    set_read("The silver runes are of evocation.\n"+
             "The runes of smoke are of illusion.\n");
    set_class(18);
    set_weight(3);
    set_value(1500);
    set_hit_func(this_object());
}

weapon_hit(attacker){
   w=random(60);
   
   if(w > 58)  {
     write("\nThe two bladed "+BOLD+"smoke sword"+NORM+" of Kyorlin "+
              "grows hot in your hand.\n\n");
     this_player()->heal_self(-random(6));
        }
        
   if(w > 55 && w < 57)  {
     write(BOLD+"Smoke explodes from the mist runed blade of the "+BOLD+"smoke sword"+NORM+" of Kyorlin.\n");
     say(BOLD+"Smoke explodes from the mist runed blade of the "+BOLD+"smoke sword"+NORM+" of Kyorlin.\n");
     smoke = clone_object("/players/saber/closed/toys/smoke.c");
     move_object(smoke, environment(this_player()));
        }
     
   if(w<5)    {
      tell_room(environment(this_player()),
     "The "+BOLD+"silver runes"+NORM+" on the "+BOLD+"smoke sword"+NORM+" gleam.\n"+
     "The "+BOLD+"mist runes"+NORM+" on the "+BOLD+"smoke sword"+NORM+" shimmer.\n");
   NUMBER = 9;
              }
     
   if(w > 4 && w < 10)  {
     tell_room(environment(this_player()),
     "The "+BOLD+"silver runes"+NORM+" on the "+BOLD+"smoke sword"+NORM+" gleam.\n");
   NUMBER = 8;
               }
               
   if(w > 9 && w < 15)  {
     tell_room(environment(this_player()),
     "The "+BOLD+"mist runes"+NORM+" on the "+BOLD+"smoke sword"+NORM+" shimmer.\n");
   NUMBER = 6;
               }

 if(w > 14 && w < 20)  {
     tell_room(environment(this_player()),
     "A "+BOLD+"dark aura"+NORM+" surrounds "+tp+".\n");
    NUMBER = 5;
               }

   if(w < 20) return NUMBER;
          
      return;
        }
