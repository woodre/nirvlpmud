#include "/players/hippo/bs.h"
#define MOV_RATE 25
inherit"obj/monster";
object heal;
void reset (int arg) {
  :: reset (arg);
    if (arg) return;
set_name("ery");
  set_alias("erythrocyte");
set_short("An erythrocyte");
set_alias("erythrocyte");
set_long(
   "This is an erythrocyte, in short: an ery. It is the main "+BS+
   "substance of blood."+BS);
set_level(13);
set_wc(17);
set_ac(10);
set_hp(195);
money = 300;
heal = clone_object("/players/hippo/heals/nucleus");
if (heal) {
move_object(heal,this_object());
}
/* Taking random move out to avoid log errors. -Snow 3/99
    call_out("random_move",MOV_RATE);
*/
}
status random_move(){
  int n;
  if(!environment(this_object())) return 1;
n=random(4);
  switch(n){
    case(0) : command("up"); break;
    case(1) : command("down"); break;
    case(2) :command("west"); break;
    case(3) :command("east"); break;
  }
call_out("random_move",MOV_RATE);
  return 1;
}
