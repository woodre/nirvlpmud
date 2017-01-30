/*  A sword that sets people on fire  */


#define tp this_player()->query_name()

#include "/players/saber/closed/esc.h"
#include "/players/saber/closed/ansi.h"

int w,n,ahp;

inherit "obj/weapon.c";

reset(arg) {
  ::reset(arg);
    if (arg) return;
    set_name("bardsword");
    set_alias("sword");
    set_short("A "+BOLD+"Dark Crystal"+NORM+" Bardsword");
    set_long("An "+BOLD+"ebony black"+NORM+" longsword of gleaming crystal.\n"+
       "The crystal "+HIY+"glows"+NORM+" with an inner "+HIR+"crimson fire"+NORM+".\n"+
       "There is a Bardic rune on the hilt.\n");
    set_class(17);
  set_type("sword");
/* Added by Snow 1/99 */
    set_weight(2);
    set_value(10000);
    set_hit_func(this_object());
}

weapon_hit(attacker){

   w=random(15);
    
   if (w>11)  {
       write("The Bardsword gleams with "+HIR+"dark crimson fire"+
             NORM+" as it cleaves through your foe.\n");
       write(capitalize(attacker->query_name())+" staggers.\n");
       say(tp+"'s Bardsword gleams with "+HIR+"dark crimson fire"+
           NORM+" as "+this_player()->query_pronoun()+" slices through "+
           this_player()->query_possessive()+" foe.\n"+
         capitalize(attacker->query_name())+" staggers.\n");
      return 5;
    }
    if(w < 1)  {
       tell_room(environment(this_player()), "\n"+
         capitalize(attacker->query_name())+" "+HIR+"bursts into flames"+NORM+".\n\n");
       move_object(clone_object("/players/saber/closed/toys/fire2.c"), attacker);
                }
    return;
    }
