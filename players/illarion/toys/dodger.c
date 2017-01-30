#include "/players/illarion/dfns.h"

int just_dodged;

static id(str) {
  return str=="dodger";
}

init() {
  if(!environment() || !TP) return;
  if(environment() != TP) return;
  TP->RegisterArmor(this_object(),({"physical",0,0,"do_special"}));
}

int do_special(object owner) {
  if(!environment() || environment() != owner)
    owner->RemoveArmor(this_object());
  if(just_dodged) {
    tell_object(owner,"You recover from your dodge.\n");
    just_dodged=0;
    owner->RegisterArmor(this_object(),({"physical",0,0,"do_special"}));
  }
  if(!random(4)) {
    tell_object(owner,"Moving with blinding speed, you dodge!\n");
    owner->RegisterArmor(this_object(),({"physical",100,0,"do_special"}));
    just_dodged=1;
  }
  return 0;
}
get() {
  return 1;
}
