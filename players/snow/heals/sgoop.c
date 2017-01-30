/* Stats: 5 uses, Totalheal: 150, Totaltox: 52.5(.32), Price 1500 */
/* Totaltox = 50 + random(2)*5 = slightly over 52 */
inherit "/obj/clean.c";
 
#define TP this_player()
#define TPN capitalize(TP->query_name())
#include "std.h"
#include "/players/snow/closed/cyber/color.h"
#define GOOP GREEN+"SuperGoop"+OFF
 
int shots, price;
 
id(str) { return str == "supergoop" || str == "goop" ||
                 str == "SuperGoop"; }
 
reset(arg) {
        if (!arg) shots = 5;
        price = shots * 300;
  set_no_clean();
}
 
long() {
   write("This is a tube of "+GOOP+".\n"+
  "A digital readout on the tube flashes: "+GREEN+shots+OFF+".\n"+
  "You could 'squeeze goop' to eat it.\n"); }
 
short() { return GOOP+" *"+shots+"*"; }
 
query_value() { return (shots * 300); }
query_weight() { return 2; }
get() { return 1; }
query_save_flag() { return 1; }
 
init() {
  add_action("squeeze_goop", "squeeze");
}
 
squeeze_goop(arg){
   if(environment() != this_player()) return;
  if(!arg) notify_fail("Squeeze what?\n"); 
  if(arg != "goop") return 0;
  if(!TP->eat_food(10+random(2))) {
     write("You are too full to eat SuperGoop right now.\n");
     return 1; }
  if(arg == "goop"){
  shots--;
  TP->heal_self(30);
  write(
    "The "+GOOP+" goes to work on your body! Pain disappears.\n"+
    "The digital readout on the tube flashes: "+GREEN+shots+OFF+".\n");
  write(BOLD+" ~HP: "+TP->query_hp()+"  ~SP: "+TP->query_sp()+OFF+"\n");
        say(TPN+" eats some "+GOOP+".\n");
    if(shots < 1){
      write(
      "The tube crumbles to dust as you squeeze the last bit of "+
       GOOP+".\n");
     destruct(this_object()); TP->recalc_carry(); }
  return 1;
  }
}
is_heal() { return "stuff"; }
query_potence() { return 30; }
