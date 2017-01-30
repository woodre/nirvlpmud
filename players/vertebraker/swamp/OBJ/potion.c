#include "../define.h"
int c, hits;
inherit ITEM;


reset(arg) {
   if(arg) return;
   set_id("potion");
   set_alias("bubbling potion");
   set_short("A bubbling potion");
   set_value(500);
   set_weight(1); 
   hits = 1+random(3); }

init() {
   ::init();
   add_action("uncork","uncork");
   add_action("uncork","cork");
   add_action("gulp","gulp"); }

uncork(str) {
   if(id(str)) {
      if(!c) {
         write("You uncork the tiny potion.\n");
         say(TPN+" uncorks the tiny potion.\n");
         c = 1; return 1; }
      else {
         write("You cork the tiny potion.\n");
         say(TPN+" corks the tiny potion.\n");
         c = 0; return 1; } } }

gulp(str) {
   if(id(str)) {
      if(!c) {
         write("You fail.\n"+
            "The potion is still corked.\n");
         return 1; }
      if(!hits) {
         write("There is no more fluid left in the potion.\n");
         return 1; }
      hits -= 1;
      write("You gulp down a hit of the potion......\n"+
         GRN+"...a burning sensation grips your throat...\n"+NORM+
         "You feel much better now.\n");
      say(TPN+" gulps down a hit of the potion......\n");
      TP->eat_food(-(TP->query_stuffed()));
      TP->drink_alcohol(-1000);
      TP->drink_soft(-(TP->query_soaked()));
      if(!hits) {
         write("You have now finished the potion.\n");
         write("You toss the small flask into the wilderness,\n"+
            " as you have no use for it now.\n");
         TP->add_weight(-1);
         destruct(TO); }
      return 1; } }

long() {
   if(!c)   write(
         " This is a tiny corked flask, with a green,\n"+
      "viscous bubbling fluid within.  You can \"uncork\"\n"+
      "it and gulp a bit.\n");
   else write(
         "This is a tiny open flask, with a green,\n"+
      "viscous bubbling fluid within.  You can \"cork\"\n"+
      "it back up, or take a \"gulp\".\n");
}

locker_init(x) {
  sscanf(x, "%d", hits);
}

locker_arg() {
  return ""+hits;
}
