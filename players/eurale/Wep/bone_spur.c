#define tpn this_player()->query_name()
#include "/players/eurale/closed/ansi.h"
inherit "obj/weapon.c";
int num;  /* number of poisons  */

reset(arg){
  ::reset(arg);
  if (arg) return;
num = 3;

set_name("bone sliver");
set_alias("bone");
set_alt_name("sliver");
set_short("a filthy bone sliver");
set_long(
  "desc. \n");
set_type("knife");  /*  sword/knife/club/axe/bow/polearm  */
  set_class(2);
  set_weight(1);
  set_value(3);
set_save_flag();
}

init() {
  ::init();
  add_action("puncture","puncture");
  add_action("cash","cash");
}

puncture(str) {
object ob;

if(!str) {
  write("You make a quick stab with your bone sliver but in your\n"+
	"haste, you miss your target and nick yourself instead.\n");
  say(tpn+ "nicks himself with the bone sliver...\n");
  move_object(clone_object("players/eurale/Misc/bone_poison.c"),
     this_player());
  num = num - 1;
  return 1; }

ob = find_player(str);
if(!ob) { write("No such player!\n"); return 1; }
if(!present(ob,environment(this_player()))) {
  write(capitalize(str)+" is too far away to do that!\n"); return 1; }
if(this_player()->query_fight_area() != 1) {
  write("You must be in a PK area to infect another player.\n");
  return 1; }
if(present(ob,environment(this_player()))) {
  write("You puncture "+capitalize(str)+" with the filthy bone sliver.\n");
  say(tpn+" punctures you with his filthy bone sliver...\n");
  move_object(clone_object("players/eurale/Misc/bone_poison.c"),ob);
  num = num - 1;
  return 1; }
if(num == 0) {
  write("As you puncture your target, the sliver breaks off\n"+
	"and disappears beneath the skin...\n");
  destruct(this_object());
  return 1; }
}

cash(str) {
int val;
if(!str) { write("Cash what?\n"); return 1; }
val = num * (1300 + random(300));
if(str == "bone" || str == "sliver") {
  write("You cash in your filthy bone sliver...\n"+
	"and you get an amazing "+val+" coins for it.\n");
  this_player()->add_money(val);
  destruct(this_object());
  return 1; }
}
