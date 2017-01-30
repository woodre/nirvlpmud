inherit "obj/treasure.c";
#include "/players/tristian/lib/ansi.h"


reset(arg) {
  if(arg) return;
  set_short("A fun slot machine");
  set_alias("slots");
set_long("The proverbial one armed bandit.  Pull the 'arm' for a try\n");
set_value(0);
set_weight(2);
}

init() {

  ::init();

  add_action("pull","pull");
}

		pull(str)  {
			
			if(!str) {

				write("Pull the 'arm' dummy!\n");
					return 1; 
}

			if(str == "arm") {
				int x;
				x = (random (20));
}
			if(x < 10){
				write("  !     #     !\n");
				write("Sorry, You lose\n");
}
			if(x < 20 && x > 10){
   				write("@     @     @\n");
				write("YOU WIN!!!!\n");
}

return;
}