/* This is a heal. Stats: 3 uses, Heal 50, Soak 14, Price 1500 */
inherit "/obj/clean.c";
 
#define TP this_player()
#define TPN capitalize(TP->query_name())
#include "std.h"
#include "/players/snow/closed/cyber/color.h"
#define BLAST BROWN+"ProteinBlast"+OFF
 
int shots, price;
 
id(str) { return str == "proteinblast" || str == "blast" ||
                 str == "lblast" ||
                 str == "protein" || str == "ProteinBlast"; }
 
reset(arg) {
        if (!arg) shots = 3;
        price = shots * 500;
  set_no_clean(1);
}
 
long() {
   write("This is a large dose bottle of "+BLAST+".\n"+
  "A digital readout on the bottle flashes: "+GREEN+shots+OFF+".\n"+
  "You could 'pblast' to drink it.\n"); }
 
short() { return "Large dose "+BLAST+" *"+shots+"*"; }
 
query_value() { return (shots * 500); }
query_weight() { return 1; }
get() { return 1; }
query_save_flag() { return 1; }
 
init() {
    add_action("protein_blast","pblast");
}
 
protein_blast(){
   if(environment() != this_player()) return;
  if(!TP->drink_soft(14)) {
     write("You are too full to drink "+BLAST+" right now.\n");
     return 1; }
/*
  if(shots == 3) {
    write_file("/players/snow/log/heals",ctime(time())+" "+
      this_player()->query_real_name()+" used a ProteinBlast.\n"); }
*/
  shots--;
  TP->heal_self(50);
  write(
    "The "+BLAST+" goes to work on your body! Pain disappears.\n"+
    "The digital readout on the tube flashes: "+GREEN+shots+OFF+".\n");
  write(BOLD+" ~HP: "+TP->query_hp()+"  ~SP: "+TP->query_sp()+OFF+"\n");
  say(TPN+" drinks some "+BLAST+".\n");
  if(shots < 1) {
      write(
      "The "+BLAST+" bottle crumbles to dust as you drink it up.\n");
     destruct(this_object()); TP->recalc_carry(); }
  return 1;
}
is_heal() { return "soak"; }
query_potence() { return 50; }
