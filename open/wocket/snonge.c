#include "/players/wocket/closed/ansi.h"

inherit "/obj/monster.c";

reset(arg){
  ::reset(arg);
  if(arg) return;
move_object(clone_object("/players/wocket/mushrooms/shroom.c"),this_object());
set_name("nonge");
set_race("seussian");
get_short();
set_long("A very timid nonge.  He seems to have wandered down here by accident\n"+
         "and now is running aimlessly though the caverns.  His fur is very dirty\n"+
         "while his ears are pointing down.  He is shaking violently.\n");
set_level(13);
set_hp(195);
set_wc(17);
set_ac(10);
set_al(200);
}


get_short(){
int i;
i = random(4);
switch(i){
case 0:   set_short("A "+HIY+"timid"+NORM+" nonge");
break;
case 1:   set_short("A "+HIR+"scared"+NORM+" nonge");
break;
case 2:   set_short("A "+HIG+"frightened"+NORM+" nonge");
break;
case 3:   set_short("A "+HIM+"shivering"+NORM+" nonge");
break;
}
}
