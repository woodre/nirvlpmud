#include "/players/jareel/define.h"
inherit "obj/weapon.c";
int bladesharp;
int energize;
int MAGIC;

reset(arg) {
   ::reset(arg);
   if (arg) return;
   set_name("lightning sword");
   set_alias("sword");
   set_type("sword");
   get_short();
   set_class(21);
   set_weight(2);
   set_value(1500);
   set_long("A bastard sword with a razor sharp steel blade.\n"+
      "The blade of the crackles with arcs of "+BOLD+"electrisity"+NORM+"\n"+
      "crackling in the air.  A charge matrix rests on the blades hilt\n");
   set_hit_func(this_object());}
      weapon_hit(attacker){
      int i;
      if(energize != 1){
      return 0;   }
      i = random(13);
      if(i<3){
      tell_room(environment(this_player()),"\nThe sword releases arcing energy...\n"+
      this_player()->query_attack()->query_name()+" ignites as...\n\n"+
      HIB+"                 L I G H T N I N G\n"+ 
      "                   F L A S H E S\n\n"+NORM+"\n     from the swords blade.....\n");
      return 7;  }
      if(i<7){
      write("\nThe sword"+HIC+" GLOWS"+NORM+" as it "+HIB+"SMASHES"+NORM+" into "+this_player()->query_attack()->query_name()+".\n\n");
      return 5; }}



status wield(string str) {
   
   int x,s;
   if(!id(str)) return 0;
   if(environment()!=TP) return 0;
   if(TP->query_extra_level() < 20){ write("Nope.\n"); return 1; }
   if(present("notweapon",this_player())) {
      write("For some reason you are unable to wield this weapon.\n");
      return 1;
   }
   
   if (wielded) {
      write("You already wield it!\n");
      return 1;
   }
   
   wielded_by = this_player();
   call_other(this_player(), "wield", this_object(), silentwield);
   wielded = 1;
   
   return 1; }
   
init(){
   ::init();
   add_action("bladesharp","charge");
   
   }
   
check_wielded(){
   if(this_player()->query_weapon() == this_object()){
   return 1; }
   
   else {
   notify_fail(BOLD+"You must be wielding the sword to use its powers.\n"+NORM);
   return 0;  }}
   
check_magic(){
   int i;
   i = this_player()->query_attrib("int");
   if(i > 30) i = 30;
   if(i < 0) i = 0;
   return i; }

bladesharp(){
   int time;
   MAGIC = check_magic();
   if(check_wielded() == 0) return 0;
   if(this_player()->query_spell_point() < 50){
   notify_fail(BOLD+"You lack the energy to charge the scimitar.\n"+NORM);
   return 0;  }
   this_player()->add_spell_point(-50);
   energize = 1;

get_short();
   time = ((500+random(500))*MAGIC)/20;
   call_out("remove_energy",time);
   write("\nYou surge energy into the blade.\n\n"+
   "        "+BOLD+BLINK+"L I G H T N I N G "+NORM+"arcs over your blade.\n\n");
   return 1;  }
   
remove_energy(){
   write("The lightning sword energy fades.\n");
   say("The arcs from the sword subsides.\n");
   energize = 0;
   get_short();
   return 1;  }
   
get_short(){
   string str;
   str = ""+BOLD+BLU+"Lightning Sword"+NORM+"";
   if(energize == 1){
   str += ""+BLU+"  ("+NORM+BOLD+"Lightning Charged"+NORM+BLU+")"+NORM+"";
   }
set_short(str);
}


