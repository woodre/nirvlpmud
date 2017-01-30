#include <ansi.h>
#include "../defs.h"
/* Wounding ability gained at level 10
   Must have evil alignment
   rank/100 chance of hitting   */
int main(object atk){
  int rank, dam, aln;
  string *msg;
  string part;
  object wound;
  rank = (int)this_player()->query_guild_rank();
  aln = (int)this_player()->query_alignment();
  if(rank < 10 || aln > -100 || random(100) > rank) {
    return 0;
  }
  msg = ({"face", "neck", "chest", "shoulder", "forearm", "wrist",
          "hand", "stomach", "groin", "thigh", "knee", "shin",
		  "calf", "ankle", "foot", "head"});
  wound = present("BWOwound", atk);
  if(wound) {
    if(wound->query_infection()) {
	  wound->increase_duration();
	  return 0;
	}
	wound->start_infection();
	return 0;
  }
  part = msg[random(sizeof(msg))];
  tell_room(environment(atk),
    "The "+HIK+"shadows"+NORM+BOLD+" LASH OUT"+NORM+" at "+atk->query_name()+"'s "+BOLD+part+NORM+" causing a "+HIR+"grevious"+NORM+" wound!\n");
  wound = clone_object(OBJ+"wound.c");
  move_object(wound, atk);
  wound->start_wound(part, rank);
  return 0;
}
