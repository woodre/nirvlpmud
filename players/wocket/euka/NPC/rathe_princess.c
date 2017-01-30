#include "/players/wocket/closed/ansi.h"
#include "../Def.h"
inherit "/obj/monster.c";

reset(arg){
  ::reset(arg);
  if(arg) return;
  set_name("rathe");
  switch(random(5)){
    case 0:  set_short(HIR+"Sarah"+OFF+", the rathe princess");  set_alt_name("serah"); break;
  case 1:  set_short(HIR+"Sera"+OFF+", the rathe princess");  set_alt_name("sera"); break;
  case 2:  set_short(HIR+"Serra"+OFF+", the rathe princess"); set_alt_name("serra"); break;
  case 3:  set_short(HIR+"Sara"+OFF+", the rathe princess"); set_alt_name("sara"); break;
  case 4:  set_short(HIR+"Serah+OFF+", the rathe princess"); set_alt_name("serah"); break;
  }
  set_alias("guard");
  set_long("A small young girl of unimaginable beauty.  Her long flowing amber\"+
           "hair contrasts against her dark ash grey skin.  small pointy ears\n"+
           "peer out and large green eyes encapture your soul.\n");
  set_hp(425);
  set_wc(26+random(5));
  set_ac(15);
  set_level(18);
  set_al(-500);
  set_race("rathe");
  set_chat_chance(3);
  load_chat("Princess smiles.\n");
  load_chat("Princess grins.\n");
  load_chat("Princess laughs playfully.\n");
  set_dead_ob(this_object());
}


monster_died(){   
 if(present("corpse",environment(this_object()))){
      destruct(present("corpse",environment(this_object())));
  move_object(clone_object(EPATH+"OBJ/rathe_corpse.c"),environment(this_object()));
    }
return 1;
}

