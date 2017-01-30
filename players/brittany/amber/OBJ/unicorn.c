inherit "obj/treasure";
#include "/players/brittany/ansi"

reset(arg) {
  set_id("unicorn");
set_short("A "+WHT+"Unicorn"+NORM);
  set_long(
"A large white unicorn with a single horn on its forehead.\n"+
"In medieval times it was said the unicorn was endowed with\n"+
"symbolic qualities.  Although, it is rumored that a unicorn\n"+
"needs to be tamed by the touch of a virgin, maybe you could\n"+
"'touch' its horn.\n");
  set_weight(1000);
  set_value(0);
}
get() { return 0; }  
