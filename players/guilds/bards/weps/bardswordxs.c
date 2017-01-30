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
    set_short("An "+HIR+"X"+HIG+"m"+HIR+"a"+HIG+"s"+NORM+" Crystal Bardsword");
    set_long("An "+HIR+"X"+HIG+"m"+HIR+"a"+HIG+"s"+NORM+" longsword of gleaming "+
         HIR+"red"+NORM+" and "+HIG+"green"+NORM+" crystal.\n"+
       "The crystal hums softly in your hand.\n"+
       "There is a Bardic rune on the hilt.\n");
    set_class(18);
    set_weight(2);
    set_type("sword"); /* by verte 6.6.01 */
    set_value(10000);
    set_hit_func(this_object());
}

weapon_hit(attacker){

   w=random(100);
    if(!present("bard_obj", environment()) && 
   !present("KnightInvite", environment())) return 0;
   if (w>75)  {
       write("The Bardsword gleams with "+HIR+"X"+HIG+"m"+HIR+"a"+HIG+"s"+HIR+"fire"+
             NORM+" as it slices through your foe.\n");
       write(capitalize(attacker->query_real_name())+" staggers.\n");
       say(tp+"'s Bardsword gleams with "+HIR+"X"+HIG+"m"+HIR+"a"+HIG+"s"+HIR+"fire"+
           NORM+" as "+this_player()->query_pronoun()+" slices through "+
           this_player()->query_possessive()+" foe.\n"+
         capitalize(attacker->query_real_name())+" staggers.\n");
      return 7;
    }
    if(w < 5)  {
      if(!present("xmas_xmas", attacker))  {
        tell_room(environment(this_player()), "\n"+
         capitalize(attacker->query_real_name())+" "+BOLD+"bursts into song"+NORM+".\n\n");
       move_object(clone_object("/players/saber/closed/toys/xmas.c"), attacker);
	   return 3;
                }
                }
    return 0;
    }
