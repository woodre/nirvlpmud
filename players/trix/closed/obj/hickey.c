#include "/players/boltar/things/esc.h"
string place,hicker;
reset(arg) {
        if(arg) return;
        place="neck";
}

id( str ) {
        if(str=="hickey") return 1;
        return 0;
}

long() {
        write("A light red mark on your "+place+", given to you by "+hicker+".\n"+
              "Rub it if you want to get rid of it.\n");
}
set_hicker(arg) { if(!arg) return;
                  hicker=capitalize(arg);
		  return hicker;
}

set_place(arg) { if(!arg) return;
		 place=arg;
		 return place;
}

init()
{
  add_action("rub","rub");
}

rub(arg)
{ if(arg!="hickey") return;
  write("You rub your hickey roughly and watch it magically disappear.\n"+
        "(Yea, I know it wouldnt work for real, but this is a mud!)\n");
  destruct(this_object());
  return 1;
}

gender()
{   return environment(this_object())->query_gender(); }


adj()
{  if(gender()=="male") return "his";
   else if(gender()=="female") return "her";
   else return "its";
}


extra_look()  {
  object who;
  who=environment(this_object())->query_name();
  write(esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m");
  write(who+" has a hickey on "+adj()+" "+place+" by "+hicker);
  write(esc+"[0m"+".\n");
       }

get() {
        return 1;
}
drop() {
        return 1;
}
