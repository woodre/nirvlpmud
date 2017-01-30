#include "std.h"
int drinks, price;
 
id(str) { return str == "fat"; }
 
reset(arg) {
        if (!arg) drinks = 6;
        price = drinks * 1000;
}
 
long() {
        write("A large hunk of fat. There are "+drinks+" chunks left to gobble.\n");
}
 
short() {
        return "A hunk of polar bear fat";
}
 
alias() {
          return "fat";
}
 
query_value()
{
    return price;
}
 
init() {
  add_action("use", "gobble");
}
 
use(arg){
object tp;
tp = this_player();
if(!arg || arg != "fat"){
        return 0;
}else{
        if(arg == "fat"){
drinks=drinks - 1;
this_player()->heal_self(30);
        write("You stuff a huge chunk of fat in your mouth. Some drips down your chin.\n"+
                 "There are "+drinks+"  chunks left.\n")
;
        say(capitalize(tp->query_name()) + " gobbles a chunk of fat.\n");
if(drinks< 1){
        destruct(this_object());
        write("You just gobbled the last chunk of fat.\n");
                }
return 1;
                }
        }
}
 
get() {
    return 1;
}
 
query_weight() {
    return 2;
}
 
 
query_save_flag() { return 1; }
