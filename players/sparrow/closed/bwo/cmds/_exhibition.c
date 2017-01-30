#include <ansi.h>
#include "../defs.h"
cmd_exhibition()
{
  object baddie,crowdObj;
  int badWorth, alignX, alignN, crowdRate, myLuc, myCha, bonus;
  /* This allows the player to draw a crowd and later can attempt
     to convert members of the crowd to his/her parish */
  if(!this_player()->query_attack()) {
    write("You must be in "+BOLD+"battle"+NORM+" to put on an exibition!!!\n");
    return 1;
  }
  /* The size of the crowd that a member can gather is determined by several
     different factors. First is the calculate_worth() of the current target.
     Next is a multiplier for the alignment of the npc. If the alignment is
     less than 100 the multiplier is 1. Greater than 100 is divided by 100
     and rounded up. This multiplier is averaged with renown of the
     player and multiplied to the worth/100. This is how many people they
     can draw per round. The longer they continue the battle, the more they
     can draw in.*/
  baddie = this_player()->query_attack();
  badWorth = baddie->calculate_worth();
  badWorth = badWorth/100;
  alignN = baddie->query_alignment();
  if(alignN < 400) {
    alignX = 1;
  }
  else {
    alignX = alignN/400;
  }
  if(badWorth < 1) {
    badWorth = 1;
  }
  bonus = 0;
  myLuc = this_player()->query_attrib("luc");
  switch(myLuc) {
    case 6..10:
	  bonus = bonus + 1;
	  break;
	case 11..20:
	  bonus = bonus + 2;
	  break;
	case 21..25:
	  bonus = bonus + 3;
	  break;
	case 26..50:
	  bonus = bonus + 4;
	  break;
  }
  myCha = this_player()->query_attrib("cha");
  switch(myCha) {
    case 6..10:
	  bonus = bonus + 1;
	  break;
	case 11..20:
	  bonus = bonus + 2;
	  break;
	case 21..25:
	  bonus = bonus + 3;
	  break;
	case 26..50:
	  bonus = bonus + 4;
	  break;
  }
  crowdRate = bonus * badWorth;
  crowdRate = (crowdRate/2) * alignX;
  /* now clone the crowd object to the room and feed it a rate */
  crowdObj = clone_object(OBJ+"crowdObj.c");
  move_object(crowdObj, environment(this_player()));
  crowdObj->buildCrowd(crowdRate, this_player());
  return 1;
}