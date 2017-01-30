#include "/players/wocket/closed/ansi.h"
#include "../Def.h"
inherit "/obj/monster.c";

reset(arg){
  ::reset(arg);
  if(arg) return;
  set_name("rathe");
  switch(random(4)){
    case 0:  set_short(HIR+"Aamoth"+OFF+", a rathe guard");  set_alt_name("aamoth"); break;
  case 1:  set_short(HIR+"Faltker"+OFF+", a rathe guard");  set_alt_name("faltker"); break;
  case 2:  set_short(HIR+"Zepht"+OFF+", a rathe guard"); set_alt_name("zepht"); break;
  case 3:  set_short(HIR+"Hassi"+OFF+", a rathe guard"); set_alt_name("hassi"); break;
  }
  set_alias("guard");
  set_long("A tall and lanky guard.  Long pointy ears stick out through\n"+
           "the dark long hair.  Fine beautiful fetures adorn this gorgious\n"+
           "creature.  Long somewhat raggid cloths hang genlty over the\n"+
           "slender physique.  Strange tattoos cover his arms.\n");
  set_hp(450);
  set_wc(28+random(5));
  set_ac(16+random(3));
  set_level(19);
  set_al(-500);
  set_race("rathe");
  set_chat_chance(3);
  load_chat("Rathe smiles.\n");
  load_chat("Rathe grins.\n");
  set_dead_ob(this_object());
}


monster_died(){   
 if(present("corpse",environment(this_object()))){
      destruct(present("corpse",environment(this_object())));
  move_object(clone_object(EPATH+"OBJ/rathe_corpse.c"),environment(this_object()));
    }
return 1;
}

