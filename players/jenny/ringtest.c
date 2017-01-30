#include "/players/jenny/define.h"
inherit "/obj/armor.c";
object ob;
int damaged;
int coinage;
#define USER environment(this_object())
#define ATT USER->query_attack()
id(str) { return str == "ring" ||  str == "championship ring" || str == "stanley cup championship ring" || str == "stanley cup ring" || str == "jennyring1997"; } 
reset(arg) {
   if(arg) return;
   set_name("ring");
   set_ac(1);
   set_value(2000);
   set_weight(1);
   set_type("ring");
   set_short("A "+BOLD+WHT+"Stanley Cup "+NORM+"Championship Ring");
   set_long(
      "This is a championship ring from the 1997 season.  These beautiful gold rings,\n"+
      "with the diamonds in the shape of a Red Wings logo, were given to each member\n"+
      "of the 1997 Stanley Cup Champion Detroit Red Wings.  Type "+RED+"ring_usage"+NORM+"\n"+
      "to see what special uses this ring has.\n");
}
init() {  
   ::init(); 
   add_action("blah","ring_usage");
   add_action("pawn","pawn");
   add_action("cash","cash");
}

do_special(owner)
{
   if(random(225) < USER->query_attrib("wil")) {
      if(ATT->is_npc()) 
         ATT->heal_self(-(3+random(3)));
      else ATT->add_hit_point(-(3+random(3)));
      tell_room(environment(USER),
      USER->query_name()+"'s ring slices into "+CAP(ATT->query_name())+"'s face.\n"+
      "\n"+
      BOLD+RED+"               Blood"+NORM+" starts to trickle from the cut.\n");
     if(!random(1000)) { damaged = 50; }
      return 0;}
   return 0;}
blah() {

write(
        "\n"+
         "This ring may be worn, pawned, cashed, or even combined with the 1998\n"+
         "championship ring into one piece of armor.\n");
   return 1;}
cash(arg) {
   if(!arg) { notify_fail("What would you like to cash?\n"); }
   if(arg == "ring" || arg == "the ring" || arg == "championship ring" || arg == "stanley cup ring") {
   if(!present("jeweler",ENVTP) && !present("jeweller",ENVTP)) { write("There is nobody here who would be interested in giving you cash for this piece of jewelry.\n"); return 1;}
   if(worn) {write("The jeweler says: Would you mind taking that off first?\n"); return 1;}
   if(damaged > 1) {
   coinage = 4000+random(2000);
     write("The jeweler looks the ring over very carefully, and notes that it is badly damaged.\n"+
               "The jeweler says: This is still quite valuable.  I'm going to give you "+coinage+" coins for it.\n");
      TP->add_money(coinage);
     destruct(TO); TP->recalc_carry();
      return 1; }
   coinage = 10000+random(4000);
   write("The jeweler looks the ring over and is very impressed.  He gladly gives\n"+
            "you "+coinage+" coins for the ring.\n");
   TP->add_money(coinage);
     destruct(TO); TP->recalc_carry();
   return 1; }}

pawn(arg) {
   if(!arg) { notify_fail("What would you like to pawn?\n"); }
   if(arg == "ring" || arg == "the ring" || arg == "championship ring" || arg == "stanley cup ring") {
   if(!present("pawnbroker",ENVTP)) { write("There is nobody here who would be interested in letting you pawn this.\n"); return 1; }
   if(worn) {write("The pawnbroker says: Would you mind taking that off first?\n"); return 1;}
   if(damaged > 1) {
   coinage = 2500+random(1000);
     write("The pawnbroker looks the ring over very carefully, and notes that it is badly damaged.\n"+
               "The pawnbroker says:  I'm going to give you "+coinage+" coins for it.\n");
      TP->add_money(coinage);
     destruct(TO); TP->recalc_carry();
      return 1; }
   coinage = 4500+random(1000);
   write("The pawnbroker looks the ring over and is smiles shrewdly.  He gladly gives\n"+
            "you "+coinage+" coins for the it.\n");
   TP->add_money(coinage);
     destruct(TO); TP->recalc_carry();
   return 1; }}
query_save_flag() { if(damaged > 1) return 1; return 0; } 
