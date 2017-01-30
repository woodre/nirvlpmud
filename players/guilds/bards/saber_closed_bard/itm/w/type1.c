/* Bardsword speical attacks */

#include "/players/saber/closed/esc2.h"
#include "/players/saber/closed/ansi.h"

#define tp this_player()->query_name()
#define ENV environment(this_object())
#define ATTACKER capitalize(attacker->query_real_name())
#define INSTR present("instrument", this_player())
#define BLVL INSTR->query_bard_level()/2

weapon_hit(attacker)  {

 if(this_player()->query_guild_name() == "bard")  {
 if(random(75) < (BLVL + this_player()->query_attrib("mag")))  {

write("The "+BOLD+"Bardsword"+NORM+" gleams with "+
            HIR+"Stormfire"+NORM+" as it cleaves through your foe.\n");
say(tp+"'s "+BOLD+"Bardsword"+NORM+" gleams with "+HIR+"Stormfire"+
         NORM+" as "+
         this_player()->query_pronoun()+" cleaves through "+
         this_player()->query_possessive()+" foe.\n");
 
  return 6;
        }
        }
        }
