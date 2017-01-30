inherit "/obj/monster";
#include "/players/jenny/define.h"
object ob;
reset(arg)
{
   ::reset(arg);
   if (arg) return;
   set_name("security guard");
   set_alt_name("guard");
   set_alias("security");
   set_race("human");
   set_gender("male");
   set_al(30+random(15));
   set_level(15);
   set_hp(220+random(70));
   if(random(100) < 38) {
   MOCO("/players/jenny/wings/items/nightstick.c"),TO);}
   init_command("wield nightstick");
   set_wc(25+random(5));
   set_ac(9+random(3));
   add_money(650+random(400));
   set_aggressive(1);
   set_short("A Security Guard");
   set_long(
      "This is a Joe Louis Arena security guard.  He is a burly guy wearing\n"+
      "black pants, a white shirt, and a hat.  A nightstick hangs from his belt.\n");
}
init() {
  ::init();
add_action("stop","north");
add_action("stop","south");
add_action("stop","west");
add_action("stop","east");
add_action("stop","enter");
add_action("stop","leave");
}
stop() {
if(TP->query_ghost() == 1 || TPL > 20) { return 0; }
else {
write("The security guard detains you.\n");
return 1; }}
heart_beat(){
if(!environment()) return;
if(ob = present("ken holland", environment())) { if(ob->query_attack()) attack_object(ob->query_attack()); } 

::heart_beat();
}
