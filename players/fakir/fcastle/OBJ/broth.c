/* Heal does "soak" and uses heal_self of 50
   cost is 2700, and there are 3 "charges"
*/
#include <ansi.h>
#include "std.h"
#define TP this_player()
#define tp this_player()->query_name()

int full, number;

id(str) { return str == "broth";
 }


short() {
  return BROWN+"Enchanted Gizzard Broth *"+number+"*"+OFF; }

is_heal() { return "soak"; }
query_potence() { return 50; }
query_save_flag()  { return 1; }

query_value() { return (number * 900); }
  
long() {
   write("A small goat bladder of enchanted gizzard broth.\n"+
     "You may 'sip' another "+number+" servings of broth.\n");
}

reset(arg) {
  if(arg) return;
  number = 3;
}

sip(str) {
   if(environment() != this_player()) return;
  if(id(str) || str == "from bottle") {
    if(!TP->drink_soft(7)) {
      write(WHITE+"You are too full of broth to sip anymore!\n"+OFF); return 1; }
  write(WHITE+"You sip a serving of gizzard broth.\n"+OFF);
     number --;
  TP->heal_self(50);
  command("mon",TP);
  if (!number) {
    write(WHITE+"You empty the bladder of broth and toss it away.\n"+OFF);
  destruct(this_object()); }
  TP->recalc_carry();
  return 1;
 }  }

init() { add_action("sip","sip"); }

get() { return 1; }

query_weight() {
    return 1;
}
