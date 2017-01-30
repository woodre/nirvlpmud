#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
inherit "/obj/treasure";
short() { return "Teller"; }

long() { write("    A teller. 'wt <msg>' to use\n"); }

id(str) { return str == "teller"; }

init() {
        add_action("wiz_tell", "wt");
/*call_out("check",1);*/
}

wiz_tell(str) {
object plyr;
string who;
string what;
string myname;
if(!str) { write("Tell what?\n"); return 1; }
  if(sscanf(str,"%s %s",who,what) != 2) {
    write("Tell <who> <what>.\n"); return 1; }
    plyr = find_living(who);
    myname = capitalize(this_player()->query_real_name());
  if(!plyr) { write(capitalize(who)+" is not online now.\n");
              return 1; }
  plyr->add_tellhistory(myname + " tells you: " + what);
  tell_object(plyr, myname+" whispers to you: "+GRN+what+NORM+"\n");
 write("You whisper to "+capitalize(who)+": "+GRN+what+NORM+"\n");
return 1;
}
/*check () {
object target;
object envto;
envto=environment(this_object());
target=first_inventory(envto);
  while(target) {
    if(living(target)) {
    destruct(target);
    write("You just dested someone who entered your inventory\n");
}
           target=next_inventory(target);
}
call_out("check",1);
return 1;
}*/
