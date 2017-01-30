#include "/players/jaraxle/define.h"
inherit "/players/vertebraker/closed/std/monster.c";
int num;
string *rooms;

reset(arg)  {
   num = random(sizeof(rooms));
   rooms = ({
         "entrance","roomw","roomw2","roomw3","room2","room3","roome","roome2","roome3","tree","tree2","tree3","treew","treew2","treew3","treee","treee2","treee3" });
   ::reset(arg);
   if(arg) return;
   call_out("move_me", 40);
   set_alias("tower");
   set_name("Tower of the "+RED+"["+HIR+"Pho"+BLK+"e"+HIR+"nix"+NORM+RED+"]"+NORM);
   set_alt_name("tower of the phoenix");
   set_can_kill(0);
   set_level(10000);
   set_hp(1000000+random(101));
   set_al(0);
   set_ac(10000000);
   
}
long(){ write("\n"); }
short(){
   if(random(2)){
      return "Tower of the "+RED+"["+HIR+"Pho"+BLK+"e"+HIR+"nix"+NORM+RED+"]"+NORM; }
   return 0; }

init(){
   ::init();
   add_action("enter","enter");
   add_action("kill","kill");
}
enter(str){
   if(!str) return (notify_fail("You may enter the tower.\n"), 0);
   if(str == "tower" || str == "tower of the phoenix"){
      write("You enter the Tower of the "+RED+"["+HIR+"Pho"+BLK+"e"+HIR+"nix"+NORM+RED+"]"+NORM+"\n");
      this_player()->move_player("into the tower#/players/jaraxle/closed/phoenix/rooms/floor1a");
      return 1; }
   notify_fail("Enter what?\n"); return 0; }

move_me(){
   num = random(sizeof(rooms));
   rooms = ({
         "entrance","roomw","roomw2","roomw3","room2","room3","roome","roome2","roome3","tree","tree2","tree3","treew","treew2","treew3","treee","treee2","treee3" });
   if(!environment()) return;
   say("Tower of the "+RED+"["+HIR+"Pho"+BLK+"e"+HIR+"nix"+NORM+RED+"]"+NORM+" disappears!\n");
   move_object(this_player(),"/players/jaraxle/3rd/warrior/rooms/"+rooms[num]+"");
   say("Tower of the "+RED+"["+HIR+"Pho"+BLK+"e"+HIR+"nix"+NORM+RED+"]"+NORM+" appears!\n");
   call_out("move_me", 40);
}

kill(str){
   if(id(str)){ write(str+" is not a living thing!\n"); return 1; }
}

calm(){
   object b;
   b = TO->query_attack();
   if(b){
      TO->stop_fight();
      b->stop_fight();
      b->stop_fight();
      TO->stop_fight();
   }
}
heart_beat(){
   ::heart_beat();
   if(this_object()->query_attacked()){ calm(); heal(); }
}
