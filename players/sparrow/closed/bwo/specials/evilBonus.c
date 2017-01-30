#include <ansi.h>
/* Evil damage bonus begining at rank 5 
   player must be evil, more evil more damage
   Piety is also involved*/
int main(object atk){
  int rank, dam, aln;
  string *msg;
  rank = (int)this_player()->query_guild_rank();
  aln = (int)this_player()->query_alignment();
  if(rank < 2 || aln > -100) {
    return 0;
  }
  msg = ({"Pure "+RED+"EVIL"+NORM+" lends power to "+this_player()->query_name()+"'s attacks!\n",
          HIM+"Evil energies"+HIK+" course through "+this_player()->query_name()+"'s body into "+atk->query_name()+"!\n"+NORM,
		  this_player()->query_name()+" radiates "+HIR+"pure evil"+NORM+", sickening "+atk->query_name()+"!\n",
		  this_player()->query_name()+"'s hands glow with "+HIM+"e"+HIK+"vil "+HIM+"p"+HIK+"ower"+NORM+"!\n"});
  
  switch(rank) {
    case 1..2:
	  dam = 1;
	  break;
	case 3..4:
	  dam = 2;
	  break;
	case 5..7:
	  dam = 3;
	  break;
	case 8..11:
	  dam = 4;
	  break;
	case 12..15:
	  dam = 5;
	  break;
	case 16..18:
	  dam = 6;
	  break;
	case 19:
	  dam = 7;
	  break;
	default:
	  dam = 10;
  }
  switch(aln) {
    case -250..0:
	  dam = dam + random(2);
	  break;
	case -500..-251:
	  dam = dam + random(3);
	  break;
	case -750..-501:
	  dam = dam + random(5);
	  break;
	case -1000..-751:
	  dam = dam + random(7);
	  break;
	case -1250..-1001:
	  dam = dam + random(9);
	  break;
	case -1500..-1251:
	  dam = dam + random(12);
	  break;
	default:
	  dam = dam + random(15);
	}
  dam = dam + random((int)this_player()->query_attrib("pie")/3);
  tell_room(environment(this_player()),
  "["+HIM+dam+NORM+"] "+msg[random(sizeof(msg))]);
  atk->hit_player(dam, "other|evil");
  return 0;
}
