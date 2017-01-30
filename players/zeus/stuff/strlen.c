inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
reset(arg){

  set_short("A pill");
  set_long(
"This is a small white pill.  The shell is made of a solid white plastic.\n"+
"Written in black lettering on the pill are the letters:  ZP1\n");
  set_weight(1);
  set_value(0);
}

id(str){ return str == "pill" || str == "kill_check_object"; }

  init(){
  ::init();
  add_action("swallow_pill", "swallow");
}


swallow_pill(){
  int x;
  string *a, b, c;

  a =({ "omfgtest01.c",0,0, });
  b = "omfgtest02.c";
  write("You swallow the pill.\n");
  for(x = 0; x < sizeof(a); x++){
#ifndef __LDMUD__ /* Rumplemintz */
    if(a[x] && sscanf(a[x], b[0..-4]+"%s", c))
#else
    if (a[x] && sscanf(a[x], b[0..<4] + "%s", c))
#endif
write("it worked\n"); else write("it didnt work\n");
}
return 1;
}
