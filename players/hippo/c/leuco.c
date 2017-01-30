#include "/players/hippo/bs.h"
inherit"obj/monster";
#define MOV_RATE 10
int i;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("leuco");
set_alias("leucocyte");
set_short("A leucocyte");
set_alias("leucocyte");
set_long("A leucocyte, or leuco. An important blood cell."+BS);
set_level(17);
set_wc(25);
set_ac(14);
add_money(1200+random(400));    /* Fred */
set_hp(500);
set_aggressive (1);
move_object(clone_object("/players/hippo/armour/boots.c"),this_object());
for(i=0;i<2;i++){
move_object(clone_object("/players/hippo/heals/nucleus.c"),this_object());
}
  }
status random_move(){
  int n;
  if(!environment(this_object())) return 1;
  if(this_object()->query_attack()) {
    call_out("random_move",MOV_RATE);
    return 1;
}
n=random (5);
  switch(n){
    case 0 : command("up"); break;
    case 1 : command("down"); break;
    case 2 : command("left"); break;
    case 3 : command("right"); break;
  }
call_out("random_move",MOV_RATE);
  return 1;
}
