/* Heal does "stuff" and uses heal_self of 50
   cost is 1800, and there are 3 "charges"
*/
#include <ansi.h>
#include "std.h"
#define TP this_player()
#define tp this_player()->query_name()

int full, number;

id(str) { return str == "liver";
 }


short() {
  return BROWN+"Condensed goose liver *"+number+"*"+OFF; }

is_heal() { return "stuff"; }
query_potence() { return 50; }
query_save_flag()  { return 1; }

query_value() { return (number * 900); }
  
long() {
   write("A leather bag of condensed goose liver.\n"+
     "You may 'eat' another "+number+" servings of liver.\n");
}

reset(arg) {
  if(arg) return;
  number = 3;
}

eat(str) {
   if(environment() != this_player()) return;
  if(id(str) || str == "from bottle") {
    if(!TP->eat_food(7)) {
      write(WHITE+"You are too full of liver to eat more!\n"+OFF); return 1; }
  write(WHITE+"You eat a serving of goose liver.\n"+OFF);
     number --;
  TP->heal_self(50);
  command("mon",TP);
  if (!number) {
    write(WHITE+"You empty the leather bag of liver and toss it away.\n"+OFF);
  destruct(this_object()); }
  TP->recalc_carry();
  return 1;
 }  }

init() { add_action("eat","eat"); }

get() { return 1; }

query_weight() {
    return 1;
}
