/* Bardsword speical attacks */

#include "/players/saber/closed/esc2.h"
#include "/players/saber/closed/ansi.h"

#define tp this_player()->query_name()
#define ENV environment(this_object())
#define ATTACKER capitalize(attacker->query_real_name())
#define BLVL INSTR->query_bard_level()/2
#define INSTR present("instrument", this_player())

weapon_hit(attacker)  {
    
 if(this_player()->query_guild_name() == "bard")  {
  if(random(75) < (this_player()->query_attrib("mag") + BLVL))  {
  
       write("The "+BOLD+"Bardsword"+NORM+" gleams with "+HIR+"X"+HIG+"m"+HIR+"a"+
             HIG+"s"+HIR+"fire"+NORM+" as it slices through your foe.\n");
       write(capitalize(attacker->query_real_name())+" staggers.\n");
       say(tp+"'s "+BOLD+"Bardsword"+NORM+" gleams with "+HIR+"X"+HIG+"m"+HIR+"a"+
           HIG+"s"+HIR+"fire"+
           NORM+" as "+this_player()->query_pronoun()+" slices through "+
           this_player()->query_possessive()+" foe.\n"+
         capitalize(attacker->query_real_name())+" staggers.\n");
      return 5;
    }
    
    if(random(30) < 1)  {
      if(!present("xmas_xmas", attacker))  {
        tell_room(environment(this_player()), "\n"+
         capitalize(attacker->query_real_name())+" "+BOLD+"bursts into song"+NORM+".\n\n");
       move_object(clone_object("/players/saber/closed/toys/xmas.c"), attacker);
                }
                }
    return;
    }
    }
