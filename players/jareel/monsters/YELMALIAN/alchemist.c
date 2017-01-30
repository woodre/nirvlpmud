#include "/players/jareel/define.h"
inherit "obj/monster.c";
int a,b,c,d,e,f,g,h,i;
reset(arg)  {
   a = 6000;
   b = 4000;
   c = 10000;
   d = 6000;
   e = 4000;
   f = 10000;
   g = 6000;
   h = 4000;
   i = 10000;
   ::reset(arg);
   if(arg) return;
   
   set_name("Corlando - "+HIY+"Y"+NORM+BOLD+"elmalian"+NORM+HIY+" A"+NORM+HIY+"l"+NORM+BOLD+"chemist"+NORM);
   set_alias("alchemist");
   set_race("human");
   set_alt_name("corlando");
   set_short("Corlando - "+HIY+"Y"+NORM+BOLD+"elmalian"+NORM+HIY+" A"+NORM+HIY+"l"+NORM+BOLD+"chemist"+NORM);
   set_long(
      "You see a psychotic delusional old man standing\n"+
      "with his head down looking over some potions.  His teeth\n"+
      "dazzle in the light, and his grin looks a little fake.\n");
   
   set_level(20);
   set_hp(850);
   set_al(0);
   set_wc(50);
   set_ac(18);
   set_heal(35,1);
   set_aggressive(0);
   set_dead_ob(this_object());
   add_money(5400);
}
init() { 
   ::init(); 
   add_action("heals","buy");
}
heals(arg) {
   
   if(!arg) { return 0; }
   
   if(arg == "1" || arg == "one") {
      if(!this_player()->add_weight(1)) {
         write("You can't carry that wussy.\n");
         return 1; }
      if(this_player()->query_money() < a) {
         write("Your broke punk get out of here!\n");
         return 1; }
      TP->add_money(-a);
      write("Corlando hands you a potion.\n");
      say(TPN+" buys a potion from Corlando.\n");
      move_object(clone_object("/players/jareel/heals/YELMALIAN/heal"), this_player());
      return 1; 
   }
   
   if(arg == "2" || arg == "two") {
      if(!this_player()->add_weight(1)) {
         write("You can't carry that wussy.\n");
         return 1; }
      if(this_player()->query_money() < b) {
         write("Your broke punk get out of here!\n");
         return 1; }
      TP->add_money(-b);
      write("Corlando hands you a potion.\n");
      say(TPN+" buys a potion from Corlando.\n");
      move_object(clone_object("/players/jareel/heals/YELMALIAN/htheal"), this_player());
      return 1;
   }
   
   if(arg == "3" || arg == "three") {
      if(!this_player()->add_weight(1)) {
         write("You can't carry that wussy.\n");
         return 1; }
      if(this_player()->query_money() < c) { 
         write("You broke punk get out of here!\n");
         return 1; }
      TP->add_money(-c); 
      write("Corlando hands you a potion.\n");
      say(TPN+" buys a potion from Corlando.\n");
      move_object(clone_object("/players/jareel/heals/YELMALIAN/ltheal"), this_player());
      return 1; 
   }
   
   if(arg == "4" || arg == "four") {
      if(!this_player()->add_weight(1)) {
         write("You can't carry that wussy.\n");
         return 1; }
      if(this_player()->query_money() < d) {
         write("Your broke punk get out of here!\n");
         return 1; }
      TP->add_money(-d);
      write("Corlando hands you a potion.\n");
      say(TPN+" buys a potion from Corlando.\n");
      move_object(clone_object("/players/jareel/heals/YELMALIAN/hpts"), this_player());
      return 1; 
   }
   
   if(arg == "5" || arg == "five") {
      if(!this_player()->add_weight(1)) {
         write("You can't carry that wussy.\n");
         return 1; }
      if(this_player()->query_money() < e) {
         write("Your broke punk get out of here!\n");
         return 1; }
      TP->add_money(-e);
      write("Corlando hands you a potion.\n");
      say(TPN+" buys a potion from Corlando.\n");
      move_object(clone_object("/players/jareel/heals/YELMALIAN/hthpts"), this_player());
      return 1;
   }
   
   if(arg == "6" || arg == "six") {
      if(!this_player()->add_weight(1)) {
         write("You can't carry that wussy.\n");
         return 1; }
      if(this_player()->query_money() < f) {
         write("Your broke punk get out of here!\n");
         return 1; }
      TP->add_money(-f);
      write("Corlando hands you a potion.\n");
      say(TPN+" buys a potion from Corlando.\n");
      move_object(clone_object("/players/jareel/heals/YELMALIAN/lthpts"), this_player());
      return 1;
   }
   
   if(arg == "7" || arg == "seven") {
      if(!this_player()->add_weight(1)) {
         write("You can't carry that wussy.\n");
         return 1; }
      if(this_player()->query_money() < g) {
         write("Your broke punk get out of here!\n");
         return 1; }
      TP->add_money(-g);
      write("Corlando hands you a potion.\n");
      say(TPN+" buys a potion from Corlando.\n");
      move_object(clone_object("/players/jareel/heals/YELMALIAN/mana"), this_player());
      return 1;
   }
   
   if(arg == "8" || arg == "eight") {
      if(!this_player()->add_weight(1)) {
         write("You can't carry that wussy.\n");
         return 1; }
      if(this_player()->query_money() < h) {
         write("Your broke punk get out of here!\n");
         return 1; }
      TP->add_money(-h);
      write("Corlando hands you a potion.\n");
      say(TPN+" buys a potion from Corlando.\n");
      move_object(clone_object("/players/jareel/heals/YELMALIAN/htmana"), this_player());
      return 1;
   }
   
   if(arg == "9" || arg == "nine") {
      if(!this_player()->add_weight(1)) {
         write("You can't carry that wussy.\n");
         return 1; }
      if(this_player()->query_money() < i) {
         write("Your broke punk get out of here!\n");
         return 1; }
      TP->add_money(-i);
      write("Corlando hands you a potion.\n");
      say(TPN+" buys a potion from Corlando.\n");
      move_object(clone_object("/players/jareel/heals/YELMALIAN/ltmana"), this_player());
      return 1;
   }
}
