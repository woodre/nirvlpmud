#include "../scar.h"
#define TEMPLE "players/beck/MortalKombat/Temple"
#define DEST "via Mortal Kombat#players/beck/MortalKombat/Temple.c"
#define MSG "The time for Mortal Kombat has arrived!"
#define TIME 300      /* Time before moving to Temple */
#define TIME2 60      /* Time to wait if Temple is busy */
#define TIME3 10      /* Delay for move */

object *List;

reset(arg) {
  if(arg) return;
  if(!List) List = ({ });
}

AddQue(object ob1, object ob2) {
  List += ({ ob1, ob2 });
  call_out("MKStart", random(TIME));
}

MKStart() {
  if(!List[0] || !List[1]) {
    ListReset();
    return;
  }
  if(TEMPLE->QInKombat()) {
    remove_call_out("MKStart");
    call_out("MKStart", random(TIME2));
    return;
  }
  tell_object(List[0], MSG+"\n\n");
  tell_object(List[1], MSG+"\n\n");
  TEMPLE->SInKombat();
  call_out("MKMove",random(TIME3));
}

MKMove() {
  object scar1, scar2;

  scar1 = present("bloodscar",List[0]);
  scar2 = present("bloodscar",List[1]);
  List[0]->move_player(DEST);
  List[1]->move_player(DEST);
  scar1->ChallengeReset();
  scar2->ChallengeReset();
  ListReset();
}

ListReset() {
  List -= ({ List[0], List[1] });
}
