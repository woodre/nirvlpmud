#include <ansi.h>
/* Dark damage bonus begining at rank 2 
   Room must be dark*/
int main(object atk){
  int rank, dam;
  string *msg;
  rank = (int)this_player()->query_guild_rank();
  if(rank < 2 || environment(this_player())->query_light() > 0) {
    return 0;
  }
  msg = ({this_player()->query_name()+HIR+" SLICES "+NORM+atk->query_name()+" with a blade of "+HIK+"darkness"+NORM+"!\n",
          this_player()->query_name()+" fires a volley of "+BOLD+"D"+HIK+"ARK "+NORM+BOLD+"M"+HIK+"ISSILES"+NORM+" at "+atk->query_name()+"!\n",
		  this_player()->query_name()+" causes the "+HIK+"darkness"+NORM+" to strangle "+atk->query_name()+"!\n",
		  atk->query_name()+" is pummeled by a wave of "+HIK+"dark spheres"+NORM+"!\n",
		  "A giant "+HIK+"wall"+NORM+" of "+HIK+"darkness"+NORM+" crashes down on top of "+atk->query_name()+"!\n"});
  
  switch(rank) {
    case 1..2:
	  dam = 1;
	  break;
	case 3..4:
	  dam = 2;
	  break;
	case 5..7:
	  dam = 4;
	  break;
	case 8..11:
	  dam = 5;
	  break;
	case 12..15:
	  dam = 7;
	  break;
	case 16..18:
	  dam = 9;
	  break;
	case 19:
	  dam = 10;
	  break;
	default:
	  dam = 12;
  }
  dam = dam + random((int)environment(this_player())->query_light()*-1);
  tell_room(environment(this_player()),
  "["+HIR+dam+NORM+"] "+msg[random(sizeof(msg))]);
  atk->hit_player(dam, "other|dark");
  return 0;
}
