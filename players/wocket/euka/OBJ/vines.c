#include "/players/wocket/closed/ansi.h"
string dir;

id(str){ return (str == "vine" || str == "vines" ); }
short(){ return YEL+"Some hanging dried vines ["+OFF+dir+YEL+"]"+OFF; }
long(){ 
  write("Some dried vines hanging from the branches above.  They appear\n"+
  "very strong and sturdy, though very dry.  You may want to try\n"+
  "'swing'ing on them.\n");
}

set_dir(a){ dir = a; }
