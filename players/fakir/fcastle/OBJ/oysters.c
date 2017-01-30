#include <ansi.h>
#include "std.h"
#define TP this_player()
#define tp this_player()->query_name()

int full, number;

id(str) { return str == "oysters";}

short() {
  return WHITE+"Oysters(Raw) *"+number+"*"+OFF; }

query_potence() { return 50; }
query_save_flag()  { return 1; }
query_value() { return (number * 1000); }
  
long() {
   write("A jagged oyster shell from a far off land.\n"+
     "You may 'eat' another "+number+" oysters.\n");
}

reset(arg) {
  if(arg) return;
  number = 3;
}

eat(str) {
   if(environment() != this_player()) return;
  if(id(str) || str == "from bottle") {
    if(!TP->eat_food(4)) {
      write(WHITE+"You are toxed out on oysters!\n"+OFF); return 1; }
    if(!TP->drink_soft(4)) {
      write(WHITE+"You are toxed out on oysters!\n"+OFF); return 1; }
      write(WHITE+"You eat a very tasty oyster and sip down some necter.\n"+OFF);
      number --;
  TP->heal_self(50);
  command("mon",TP);
  if (!number) {
    write(WHITE+"You eat all within the shell and throw it away.\n"+OFF);
  destruct(this_object()); }
  TP->recalc_carry();
  return 1;
 }  }

init() { add_action("eat","eat"); }

get() { return 1; }

query_weight() {
    return 1;
}
