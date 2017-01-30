/* Bardsword speical attacks */

#include "/players/saber/closed/esc2.h"
#include "/players/saber/closed/ansi.h"

#define tp this_player()->query_name()
#define ENV environment(this_player())
#define ATTACKER capitalize(attacker->query_real_name())
#define INSTR present("instrument", this_player())
#define BLVL INSTR->query_bard_level()/2


weapon_hit(attacker)  {
int n;
    
 if(this_player()->query_guild_name() == "bard")  {
  if(random(75) < (this_player()->query_attrib("mag") + BLVL))  {
    
      write("The "+BOLD+"Bardsword"+NORM+" gleams with "+HIR+"crimson fire"+
            NORM+" as it cleaves through your foe.\n");
      say(tp+"'s "+BOLD+"Bardsword"+NORM+" gleams with "+HIR+"crimson fire"+
          NORM+" as "+this_player()->query_pronoun()+" slices through "+
          this_player()->query_possessive()+" foe.\n");

    n = random(8);
    
    if(n==0) tell_room(ENV, ATTACKER+" staggers.\n");
    if(n==1) tell_room(ENV, "There is a distant "+BOLD+"boom of thunder"+NORM+".\n");
    if(n==2) tell_room(ENV, ATTACKER+" is struck by a "+HIR+"bolt of lightning"+NORM+".\n");
    if(n==3) tell_room(ENV, ATTACKER+" bleeds.\n");
    if(n==4) tell_room(ENV, ATTACKER+" is knocked back by a "+HIR+"* * BURST * *"+
                                       NORM+" of "+HIR+"flame"+NORM+".\n");
    if(n==5) tell_room(ENV, ATTACKER+" is covered in a raging "+HIR+"fury of fire"+NORM+".\n");
    if(n==6) tell_room(ENV, ""+HIY+"Lightning"+NORM+" flashes across the sky.\n");
    if(n==7) tell_room(ENV, "You smell something burning.\n");

     return 5;
    }
    
   if(random(20) < 1)  {
    tell_room(environment(this_player()), "\n"+
      capitalize(attacker->query_real_name())+" "+HIR+"bursts into flames"+NORM+".\n\n");
     move_object(clone_object("/players/saber/closed/toys/fire2.c"), attacker);
                }
    return;
    }
    }
