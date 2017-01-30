/* Stats: 5 uses, Totalheal: 150, Totaltox: 52.5(.32) Price 1500 */
/* Totaltox = 50 + random(2)*5 = slightly over 52 */
inherit "/obj/clean.c";
 
#define TP this_player()
#define TPN capitalize(TP->query_name())
#include "std.h"
#include "/players/snow/closed/cyber/color.h"
#define BLAST BROWN+"ProteinBlast"+OFF
#define MAX 5
#define NAME "ProteinBlast"
 
int shots, price;
 
id(str) { return str == "proteinblast" || str == "blast" ||
                 str == "protein" || str == "ProteinBlast"; }
 
reset(arg) {
        if (!arg) shots = 5;
        price = shots * 300;
  set_no_clean();
}
 
long() {
   write("This is a shot bottle of "+BLAST+".\n"+
  "A digital readout on the bottle flashes: "+GREEN+shots+OFF+".\n"+
  "You could 'pblast' to drink it.\n"); }
 
short() { return BLAST+" *"+shots+"*"; }
 
query_value() { return (shots * 300); }
query_weight() { return 2; }
get() { return 1; }
query_save_flag() { return 1; }
 
init() {
  if(query_ip_number(this_player()) == "134.129.239.13" && this_player()->query_real_name() != "budah") {
    command("drop blast", this_player()); return 1; }
    add_action("protein_blast","pblast");
  if(this_player()->query_level() > 50)
    add_action("do_consolidate", "consolidate");
}
 
protein_blast(){
   if(environment() != this_player()) return;
  if(!TP->drink_soft(10+random(2))) {
     write("You are too full to drink "+BLAST+" right now.\n");
     return 1; }
  shots--;
  TP->heal_self(30);
  write(
    "The "+BLAST+" goes to work on your body! Pain disappears.\n"+
    "The digital readout on the tube flashes: "+GREEN+shots+OFF+".\n");
  write(BOLD+" ~HP: "+TP->query_hp()+"  ~SP: "+TP->query_sp()+OFF+"\n");
  say(TPN+" drinks some "+BLAST+".\n");
  if(shots < 1){
      write(
      "The "+BLAST+" bottle crumbles to dust as you drink it up.\n");
     destruct(this_object()); TP->recalc_carry();
  }
  return 1;
}
is_heal() { return "soak"; }
query_potence() { return 30; }
#include "cinclude.h"
