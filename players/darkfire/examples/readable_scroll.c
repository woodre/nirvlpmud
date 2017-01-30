#include <ansi.h>

int active;

id(string str) {
   return str == "scroll" || str == "wisdom" || str == "scroll of wisdom";
}
short() {
	return "A Scroll of "+(active ? HIB : NORM)+"Wisdom"+NORM;
}

long() {
write(YEL+
" _________________________________\n\
/  _\\                             \\\n\
\\ (_/_____________________________/\n\
 \\                             \\\n\
  \\                             \\\n\
   \\   "+HIB+"\\  X  / o  _ _ ) _   _ _"+NORM+YEL+"  \\ \n\
    \\   "+HIB+"\\/ \\/  ( ( (_( (_) ) ) )"+NORM+YEL+"  \\\n\
     \\  "+HIB+"         _)             "+NORM+YEL+"   \\\n\
      \\                             \\\n\
       \\                             \\\n\
      __\\ "+NORM+"Reading of this scroll will"+YEL+" \\\n\
     / )_\\  "+NORM+"invoke the power within"+YEL+"    \\\n\
     \\___/_____________________________/\n"+NORM);
}

reset(arg){
  if(arg) return;
}

init() {
  add_action("read_scroll","read");
}

int read_scroll(string str) {
  if( !str || !id(str) )
    return 0;
  
  if( present("double_xp_object", this_player() ) ) {
    write("Your level of wisdom prevents you from invoking the scroll.\n");
    return 1;    
  }
  write("You read the ancient words on the scroll and feel blessed by great wisdom!\n");
  say(this_player()->query_name()+" says some ancient words and looks more wise.\n");
  move_object(clone_object("/obj/secure/double_obj.c"), this_player() );
  destruct( this_object() );
  return 1;
}

get() { return 1; }
drop() { return 0; }
query_weight() { return 0; }
query_value() { return 0; }
