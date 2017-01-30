/* This is a heal. Stats: 3 uses, Heal 50, Stuff 6, Price 3000 */
inherit "/obj/clean.c";
 
#define TP this_player()
#define TPN capitalize(TP->query_name())
#include "std.h"
#include "/players/snow/closed/cyber/color.h"
#define GOOP REV_GREEN+"SuperGoop"+OFF
 
int shots, price;
 
id(str) { return str == "supergoop" || str == "goop" ||
                 str == "lgoop" || str == "SuperGoop"; }
 
reset(arg) {
        if (!arg) shots = 3;
        price = shots * 1000;
  set_no_clean(1);
}
 
long() {
   write("This is a high density tube of "+GOOP+".\n"+
  "A digital readout on the tube flashes: "+GREEN+shots+OFF+".\n"+
  "You could 'squeeze goop' to eat it.\n"); }
 
short() { return "High density "+GOOP+" *"+shots+"*"; }
 
query_value() { return (shots * 1000); }
query_weight() { return 1; }
get() { return 1; }
query_save_flag() { return 1; }
 
init() {
  add_action("squeeze_goop", "squeeze");
}
 
squeeze_goop(arg){
   if(environment() != this_player()) return;
  if(!arg) notify_fail("Squeeze what?\n"); 
  if(arg != "goop") return 0;
  if(!TP->eat_food(6)) {
     write("You are too full to eat SuperGoop right now.\n");
     return 1; }
  if(arg == "goop"){
/*
    if(shots == 3) {
      write_file("/players/snow/log/heals",ctime(time())+" "+
        this_player()->query_real_name()+" used a SuperGoop.\n"); }
*/
  shots--;
  TP->heal_self(50);
  write(
    "The "+GOOP+" goes to work on your body! Pain disappears.\n"+
    "The digital readout on the tube flashes: "+GREEN+shots+OFF+".\n");
  write(BOLD+" ~HP: "+TP->query_hp()+"  ~SP: "+TP->query_sp()+OFF+"\n");
        say(TPN+" eats some "+GOOP+".\n");
    if(shots < 1) {
      write(
      "The tube crumbles to dust as you squeeze the last bit of "+
       GOOP+".\n");
     destruct(this_object()); TP->recalc_carry(); }
  return 1;
  }
}
is_heal() { return "stuff"; }
query_potence() { return 50; }
