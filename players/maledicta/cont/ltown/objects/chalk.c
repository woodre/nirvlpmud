inherit "obj/treasure";
#include "/players/maledicta/ansi.h"
int uses;

reset (arg) {
if(!arg){
  uses = 20;
  set_id("colored chalk");
  set_alias("chalk");
  set_short(HIR+"C"+NORM+BLU+"o"+HIY+"l"+NORM+YEL+"o"+HIB+"r"+NORM+RED+"e"+HIM+"d"+NORM+" Chalk");
  set_long(
  "A slender set of colored chalk that will allow you to mark\n"+
  "your surroundings. Simply, 'mark' the 'area'.\n");
  set_weight(1);
  set_value(5);
    }
  }

  init(){
  ::init();
  add_action("mark_it", "mark");
  }

mark_it(str){
object mark;
if(environment() != this_player()) return 0;
if(!str){
write("Mark what?\n");
return 1;
}
if(str != "area"){
write("Mark what?\n");
return 1;
}
uses -= 1;
if(!present("chalk_markings", environment(this_player()))){
mark = clone_object("/players/maledicta/cont/ltown/objects/mark.c");
move_object(mark, environment(this_player()));
write("You draw a simple mark on the ground.\n");
if(!uses){
	write("The chalk is now used up. You dust off your hands.\n");
	destruct(this_object());
	this_player()->recalc_carry();
}
return 1;
}
write("There is already a mark here!\n");
return 1;
}

