/* plasma, ground chuck, beet juice all changed over to new heals3
cost system on 6/4/99.  (3 hits, 45 heal, 14 intox/food/soak)
3*14/3*45 = .31  11*135 = 1485 per heal
All 'dine-in' heals were reduced 15 coins as per new heals docs.
*/

inherit "room/room";
#include "check.h"
#include "/players/eurale/defs.h"
object item;
int value,m;

reset(arg) {
   if (arg) return;
   if(!present("trashcan"))
      move_object(clone_object("/players/eurale/VAMPIRES/OBJ/trashcan.c"));
   set_light(0);
   
   short_desc = "Fangtooth Cafe";
   long_desc =
   "This is the famous "+HIR+"F"+GRY+"angtooth "+HIR+"C"+GRY+"afe"+NORM+
   ".  It is a small, quaint place\n"+
   "with scarred tables and soft, worn chairs.  It has been one of the\n"+
   "favorite hangout spots of the Vampire Family members for centuries.\n"+
   "Hanging on the wall above the bar is an old rustic sign.  A doorway\n"+
   "with a large plaque above it leads to the north.\n";
   
   items = ({
         "tables","\
The cafe's tables come in many shapes and sizes, but all are marked with\n\
numerous scars from fangs, nails, and carelessly placed objects",
         "chairs","\
There are standard cafe chairs around most of the tables, along with a\n\
few larger chairs with stuffed armrests and high backs",
         "bar","\
The bar is matte black wood, with a long brass footrail",
         "sign","\
A large wooden sign painted in red with the Cafe's current offerings and\n\
prices",
         "plaque","\
A polished brass plaque lettered in blazing red",
 });
   
   dest_dir = ({
         "players/eurale/VAMPIRES/RMS/nosferatu.c","north",
         "players/eurale/VAMPIRES/RMS/vgent.c","east",
   });
   
}

realm() { return "NT"; }

exit() { if(TP) TP->clear_fight_area(); }

init() {
   ::init();
   add_action("Eject","eject");
   add_action("north","north");
   add_action("Order","order");
   add_action("read_sign","read");
   add_action("take_out","togo");
   TP->set_fight_area();
}

Eject(str) {
   object ob;
   if(!str) { write("Eject who?\n"); return 1; }
   ob = present(str,ETP);
   if(!ob) { write("Not here....\n"); return 1; }
   if(present("vampire fangs",ob)) {
      write("You may not eject vampires from this cafe!\n");
      return 1; }
   if(ob->query_level() > 19) {
      write("You may not eject wizards from the cafe!\n");
      return 1; }
   write("You eject "+capitalize(str)+" from the cafe.\n");
   ob->move_object("screaming#room/mine/tunnel_room.c");
   return 1;
}

read_sign(str) {
   if(!str) { write("Read what?\n"); return 1; }
   if(str == "plaque") {
      write("The plaque reads:\n"+
         HIR+"Nosferatu Lounge - Vampires Only!\n"+NORM);
      return 1; }
   if(str == "sign" || str == "rustic sign") { write("\n\n"+
         "The "+HIR+"F"+GRY+"angtooth "+HIR+"C"+GRY+"afe"+NORM+" Menu"+"\n\n"+
         "  "+BOLD+"You can [order] the following items here:"+NORM+"\n"+
         "    Cranblood Shot               :     125 coins\n"+
         "    Bloody Mary Cocktail         :     230 coins\n"+
         "    Blood Pudding                :     435 coins\n"+
         "    Pink Lady (virgin)           :     435 coins\n"+
         "  \n"+HIR+"  You can also order the following items [togo]:"+NORM+"\n"+
         "    Extract of Hemlock           :     400 coins\n"+
         "    Hemoglobin                   :    1200 coins\n"+
         "    Blood poppers                :    1280 coins\n"+
         "    Plasma                       :    1485 coins\n"+
         "    Ground chuck (poor guy)      :    1485 coins\n"+
         "    Fresh squeezed beet juice    :    1485 coins\n"+
         "    Raw liver                    :    1700 coins\n"+
         "    Blood crystal                :   15000 coins\n"+
         "\n        We hope you enjoyed yourself and come back soon!\n");
      return 1; }
}

Order(str) {
   string name, short_desc, mess;
   int value, cost, strength, heal;
   
   if(!str) { write("Order what?\n"); return 1; }
   
   if(str == "cranblood" || str == "shot") {
      mess = "You throw back your head and slam a shot of Cranblood";
      heal = 10;
      value = 100;
      strength = 10; }
   else if(str == "cocktail" || str == "bloody mary") {
      mess = "You slurp the strong mixture down";
      heal = 25;
      value = 230;
      strength = 15; }
   else if(str == "pudding" || str == "blood pudding") {
      mess = "You eat the hardy pudding and wipe your lips";
      heal = 30;
      value = 435;
      strength = 19; }
   else if(str == "pink lady") {
      mess = "You sip, sip, sip the pink lady completely";
      heal = 30;
      value = 435;
      strength = 19; }
   else {
      write("A voice whispers, 'What is it you'd like again?'\n");
      return 1; }
   
   if (call_other(this_player(), "query_money", 0) < value) {
      write("You look in your coin purse and find too few coins.\n");
      return 1; }
   
   if(str == "cranblood" || str == "shot") {
      if(!call_other(TP, "drink_alcohol", strength)) {
         write("The bartender says, 'You're too intoxicated!'\n");
         return 1; }
      call_other(TP,"drink_alcohol",strength); }
   
   if(str == "cocktail" || str == "bloody mary") {
      if(!call_other(TP, "drink_alcohol", strength)) {
         write("A voice whispers, 'Wait a bit, you're pretty drunk.'\n");
         return 1; }
      call_other(TP, "drink_alcohol", strength);
   }
   
   if(str == "pudding" || str == "blood pudding") {
      if(!call_other(TP, "eat_food", strength)) {
         write("A voice whispers, 'You're too full for any pudding now.\n");
         return 1; }
      call_other(TP, "eat_food", strength);
   }
   
   if(str == "pink lady") {
      if(!call_other(TP,"drink_soft", strength)) {
         write("You're too full to drink any more right now.\n");
         return 1; }
      call_other(TP, "drink_solf", strength);
   }
   
   
   write("You order a "+str+".\n");
   say(capitalize(TPRN)+" orders a "+str+".\n");
   call_other(this_player(), "add_money", - value);
   call_other(this_player(), "heal_self", heal);
   write(mess + ".\n");
   return 1;
}

take_out(str) {
   m = 0;
   
  if(str == "crystal" || str == "blood crystal") {
    item = clone_object("players/eurale/VAMPIRES/OBJ/vblood.c");
    value = 15000;
    m = 1; }

  if(str == "globin" || str == "hemoglobin") {
    item = clone_object("players/eurale/VAMPIRES/OBJ/hemoglobin.c");
    value = 1200;
    m = 1; }

  if(str == "poppers" || str == "blood poppers") {
    item = clone_object("players/eurale/VAMPIRES/OBJ/poppers.c");
    value = 1280;
    m = 1; }

  if(str == "liver" || str == "raw liver") {
    item = clone_object("players/eurale/VAMPIRES/OBJ/liver.c");
    value = 1700;
    m = 1; }

   if(str == "extract" || str == "hemlock") {
      item = clone_object("players/eurale/VAMPIRES/OBJ/hemlock.c");
      value = 400;
      m = 1; }
   
   if(str == "plasma") {
      item = clone_object("players/eurale/VAMPIRES/OBJ/plasma.c");
      value = 1485;
      m = 1; }
   if(str == "chuck" || str == "ground chuck") {
      item = clone_object("players/eurale/VAMPIRES/OBJ/g_chuck.c");
      value = 1485;
      m = 1; }
   if(str == "beet juice" || str == "juice") {
      item = clone_object("players/eurale/VAMPIRES/OBJ/beetj.c");
      value = 1485;
      m = 1; }
   
   if(m) {
      if(TP->query_money() < value) {
         write("The waiter whispers, 'Sorry, you seem to be short of funds.'\n");
         return 1; }
      if(!call_other(TP,"add_weight",call_other(item,"query_weight"))) {
         write("The waiter whispers, 'Sorry, you're too burdened.'\n");
         return 1; }
      TP->add_money(-value);
      move_object(item,TP);
      write("The waiter brings you some "+HIR+str+NORM+" to go.\n");
      say(capitalize(TPRN)+" orders a "+str+" to go.\n");
   }
   
   else { write("The waiter says, 'Not available here.'\n"); }
   return 1; }

north() {
   if(!present("efangs",TP)) {
      write(HIR+"You are SLAMMED to the floor..."+NORM+" and a voice\n"+
         "whispers 'Only the most elite of vampires may enter here.'\n");
      TP->hit_player(10 + random(20));
      return 1; }
   if(TPGEXP < 670) {
      write("A ghostly vampire appears to block your way....  He whispers,\n"+
         "'You have not earned the right to enter here, come back when\n"+
         "you are NOSFERATU'..... and he disappears.\n");
      return 1; }
   TP->move_player("north#players/eurale/VAMPIRES/RMS/nosferatu.c");
   return 1;
}
