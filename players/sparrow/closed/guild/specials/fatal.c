#include <ansi.h>
/* Fatality special gained at level 2
   Must have evil alignment
   Does rank*10 hps of damage, max 200 at rank 20 (subject to nerfing)
   costs rank*2 sps   */
int main(object atk){
  int rank, dam, aln;
  string *msg;
  rank = (int)this_player()->query_guild_rank();
  aln = (int)this_player()->query_alignment();
  if(rank < 2 || aln > -100 || (int)atk->query_hp() > (rank*10) || (int)this_player()->query_sp() < (rank*2)) {
    return 0;
  }
  dam = (int)atk->query_hp() + 10;
  msg = ({HIK+this_player()->query_name()+HIR+" R I P S "+HIK+atk->query_name()+"'s head off of "+atk->query_possessive()+" shoulders!\n",
          HIK+this_player()->query_name()+HIR+" T E A R S "+HIK+atk->query_name()+"'s jawbone off savagely!\n",
		  HIK+this_player()->query_name()+HIR+" R I P S "+HIK+atk->query_name()+"'s esophagus out violently!\n",
		  HIK+this_player()->query_name()+HIR+" S N A P S "+HIK+atk->query_name()+"'s neck with a loud crack!\n"});
  
  tell_room(environment(atk),
    "\n\n          "+HIK+"["+HIY+"D"+HIK+"]   ["+HIY+"E"+HIK+"]   ["+HIY+"A"+HIK+"]   ["+HIY+"T"+HIK+"]   ["+HIY+"H"+HIK+"]       ["+HIY+"B"+HIK+"]   ["+HIY+"L"+HIK+"]   ["+HIY+"O"+HIK+"]   ["+HIY+"W"+HIK+"]\n"+NORM);
  tell_room(environment(atk),
    "          "+msg[random(sizeof(msg))]+" ["+HIB+dam+NORM+"]\n");
  atk->add_hp(-dam);
  return 0;
}
