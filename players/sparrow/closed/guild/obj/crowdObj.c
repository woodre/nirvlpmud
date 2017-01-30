/*****************************************************************************
*  File:             crowdObj.c                                              *
*  Function:         BWO guild crowd object                                  *
*  Author:           Sparrow                                                 *
*  Copyright:        Sparrow@Nirvana                                         *
*  Source:           3/5/2011                                                *
*  Notes:                                                                    *
*  Changelog:                                                                *
*****************************************************************************/
#include <ansi.h>
inherit "obj/clean";
/* Globals */
int CrowdSize, CrowdRate;
object Exibitor;

short() {
  return "A crowd of onlookers "+HIK+"["+HIC+CrowdSize+HIK+"]"+NORM;
}
long() {
  write("This crowd of people has gathered to watch a free fight!\n");
}
get() { return 1; }
drop() { return 1; }
id(str) { return str == "BWOCROWDOBJ"; }

void init() {
  CrowdSize = 1;
  CrowdRate = 0;
  call_out("destructCrowd", 30);
}

void
destructCrowd(){
  if(!CrowdRate) {
    tell_room(environment(this_object()),
      "The crowd finally finishes dispersing.\n");
    destruct(this_object());
  }
  return;
}

void
buildCrowd(int x, object pc) {
  if(!x) {
    return;
  }
  if(!pc) {
	return;
  }
  CrowdRate = x;
  Exibitor = pc;
  CrowdSize = CrowdSize + CrowdRate;
  tell_room(environment(this_object()), "A group of people has gathered to watch the battle!\n");
  if(present(Exibitor, environment(this_object())) && Exibitor->query_attack()) {
    call_out("addCrowd",2);
    return;
  }
  return;
}

void
addCrowd() {
  string roomMessage;
  if(present(Exibitor, environment(this_object())) && Exibitor->query_attack()) {
    switch(random(5)) {
	  case 0:
	    roomMessage = "More people wander in to join the crowd watching the battle.\n";
	  break;
	  case 1:
	    roomMessage = "The crowd grows larger and larger as the battle rages on!\n";
	  break;
	  case 2:
	    roomMessage = "Cheers and jeers can be heard as the crowd grows in size.\n";
	  break;
	  case 3:
	    roomMessage = "The noise in the room spikes as more people shuffle in.\n";
	  break;
	  case 4:
	    roomMessage = "More and more stragglers fill the ranks of the crowd.\n";
	  break;
	  default:
	    roomMessage = "More and more stragglers fill the ranks of the crowd.\n";
	}
    tell_room(environment(this_object()), roomMessage);
    CrowdSize = CrowdSize + CrowdRate;
    call_out("addCrowd",2);
  }
  else {
    tell_room(environment(this_object()),
      "The crowd begins to dissapate now that the battle is over.\n");
    call_out("disperseCrowd", 2);
  }
  return;
}

void
disperseCrowd() {
  if(CrowdSize - CrowdRate < 1) {
    CrowdRate = 0;
    call_out("destructCrowd", 1);
    return;
  }
  tell_room(environment(this_object()),
    "More people wander away now that the battle has ended.\n");
  CrowdSize = CrowdSize - CrowdRate;
  call_out("disperseCrowd", 2);
  return;
}

int queryCrowdSize() {
	return CrowdSize;
}