/* 10/21/05 Earwax: Made rings 'ring' 'ring' types instead of gloves. */

/*  can only get this by going to a jeweler hand having him combine your 1997 and 1998 rings into 1 piece of armor.  It should be VERY rare, that's why i made it saveable and ac 2 */
#include "/players/jenny/define.h"
inherit "/obj/armor.c";
object ob;
int damaged;
int coinage;
#define USER environment(this_object())
#define ATT USER->query_attack()
id(str) { return str==::id(str) || str=="rings"||str=="championship rings"||str=="stanley cup championship rings"||str=="stanley cup rings"||str=="ring"||str=="jennyring19971998"||str=="championship ring"||str=="stanley cup ring"||str=="stanley cup championship ring"; }
reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("ring");
   set_ac(2);
   set_value(5000);
   set_weight(1);
   /* 10/21/05 Earwax: Changed living.c and armor.c to allow multislot
    * armors to go in just so i could make this use ring ring.
   set_type("gloves");
    */
   set_type("ring");
   add_types(({ "ring" }));
   set_long(
      "These are a pair of Stanley Cup Championship rings from the 1997 and 1998\n"+
      "seasons.  They are gold, with diamonds in the shape of a Red Wings logo.\n"+
      "Each player who was a member of one of the Wings championship seasons has\n"+
      "one of these rings.  Type "+RED+"ring_usage "+NORM+"to see what special uses\n"+
      "these rings have.\n");
}
short() {
   if(worn) { return "\n"+  "A 1997 "+BOLD+WHT+"Stanley Cup "+NORM+"Championship Ring (worn).\n"+
"A 1998 "+BOLD+WHT+"Stanley Cup "+NORM+"Championship Ring (worn)";}
else { return "\n"+ "A 1997 "+BOLD+WHT+"Stanley Cup "+NORM+"Championship Ring.\n"+
"A 1998 "+BOLD+WHT+"Stanley Cup "+NORM+"Championship Ring" ;}
}
init() {  
   ::init(); 
   add_action("blah","ring_usage");
   add_action("pawn","pawn");
   add_action("cash","cash");
}

do_special(owner)
{
   if(!owner->query_attack()) return; /* added by Vertebraker [6.2.01] */
   if(random(200) < USER->query_attrib("wil")) {
      if(ATT->is_npc()) 
         ATT->heal_self(-(4+random(3)));
      else ATT->add_hit_point(-(4+random(3)));
      tell_room(environment(USER),
      USER->query_name()+"'s rings slice into "+CAP(ATT->query_name())+"'s face.\n"+
      "\n"+
      BOLD+RED+"               Blood"+NORM+" starts to trickle from the cut.\n");
/*  taking out the part that makes them nosave if damaged, because of boltar's plane to make most stuff on the mud saveable.  added bonus is I no longer have to listen to dazed complain about this not being saveable.
     if(!random(1313)) { write("Some of the diamonds chip off of your rings.\n"); damaged = 50; }
*/
      return 0;}
   return 0;}
blah() {

write(
        "\n"+
         "These rings may be worn, pawned or cashed.\n");
   return 1;}
cash(arg) {
   if(!arg) { notify_fail("What would you like to cash?\n"); }
   if(arg == "rings" || arg == "the rings" || arg == "championship rings" || arg == "stanley cup rings" || arg == "ring") {
   if(!present("jeweler",ENVTP) && !present("jeweller",ENVTP)) { write("There is nobody here who would be interested in giving you cash for these pieces of jewelry.\n"); return 1;}
   if(worn) {write("The jeweler says: Would you mind taking them off first?\n"); return 1;}
   if(damaged > 1) {
   coinage = 6000+random(3000);
     write("The jeweler looks the rings over very carefully, and notes that they are badly damaged.\n"+

               "The jeweler says: These are still quite valuable.  I'm going to give you "+coinage+" coins for them.\n");
      TP->add_money(coinage);
     destruct(TO); TP->recalc_carry();
      return 1; }
   coinage = 13000+random(4000);
   write("The jeweler looks the rings over and is very impressed.  He gladly gives\n"+
            "you "+coinage+" coins for them.\n");
   TP->add_money(coinage);
     destruct(TO); TP->recalc_carry();
   return 1; }}

pawn(arg) {
   if(!arg) { notify_fail("What would you like to pawn?\n"); }
   if(arg == "rings" || arg == "the rings" || arg == "championship rings" || arg == "stanley cup rings" || arg == "ring") {
   if(!present("pawnbroker",ENVTP)) { write("There is nobody here who would be interested in letting you pawn these.\n"); return 1; }
   if(worn) {write("The pawnbroker says: Would you mind taking them off first?\n"); return 1;}
   if(damaged > 1) {
   coinage = 3500+random(1000);
     write("The pawnbroker looks the rings over very carefully, and notes they are badly damaged.\n"+
               "The pawnbroker says:  I'm going to give you "+coinage+" coins for them.\n");
      TP->add_money(coinage);
     destruct(TO); TP->recalc_carry();
      return 1; }
   coinage = 5500+random(1500);
   write("The pawnbroker looks the rings over and smiles shrewdly.  He gladly gives\n"+
            "you "+coinage+" coins for the them.\n");
   TP->add_money(coinage);
     destruct(TO); TP->recalc_carry();
   return 1; }}
query_save_flag() { if(damaged > 1) return 1; return 0; } 