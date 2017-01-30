#include <ansi.h>

inherit "/obj/armor";

void reset(int x){
  ::reset(x);
  if(x) return;
  
  set_id("ancient martial arts bandana");
  set_alias("bandana");
  set_weight(1);
  set_short("An "+RED+"Ancient "+HIK+"Martial Arts "+NORM+"Bandana");
  
  set_type("helmet");
  set_ac(1);
  
  set_long("\
This is an ancient martial arts bandana worn by those who have grown\n"+
"strong in the knowledge and arts of ninjutsu. This is a symbol of\n\
great honor and power. With this armor comes alot of respect and the\n"+
"knowledge that has been gained through years of hard work.\n");
  set_params("other|laser", 1, 0, "do_special");
}

int do_special(object owner){
  if(!random(5)){
    if(owner->query_attack()){
      tell_room(environment(owner), "\n\
A blast of Chi fires from "+short()+"!\n\
\n\t"+RED+"----=====>>>>>>>>\n\n"+NORM);
      owner->query_attack()->hit_player(5+random(5), "other|laser");
    }
  }
  return 0;
}
