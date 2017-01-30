#include "/players/linus/def.h"
id(str) { return str == "teller" || str == "wiztell" || str == "patch"; }
extra_look() { write("A small patch bearing the words:  "+HIR+"Linus Rules!\n"+NORM); }
long() {
 write(" You are now an official member of the "+HIR+"\n"+
 "     International Linus Fan Club"+NORM+"\nUse 'lt' to communicate with your idol.\n"); }
init() {
  add_action("cmd_st", "lt");
  add_action("cmd_tell", "tell");
  add_action("cmd_say","say");
  add_action("cmd_say"); add_xverb("'");
}
cmd_tell(str) {
  object plyr;
  string myname, who, what;
  if(!str) {
    write("Huh?!?\n");
    return 1;
  }
  if(sscanf(str,"%s %s",who,what) < 2)
    {
      write("Tell <who> <what>.\n");
 return 1;
    }
  plyr = find_living(who);
  myname = capitalize(this_player()->query_real_name());
  if(!plyr) { write(capitalize(who)+" is not on now.\n");
  return 1;
  }
if(this_player()->query_invis()){
plyr->Replyer("linus");
plyr->add_tellhistory("Linus told you: "+what);
tell_object(plyr,HIK+"(invis)"+NORM+RED+" Linus"+HIK+": "+HIR+what+NORM+"\n");
  write(HIK+"(invis)"+NORM+RED+" You whisper to "+capitalize(who)+": "+HIR+what+NORM+"\n");
return 1; }
plyr->Replyer("linus");
plyr->add_tellhistory("Linus told you: "+what);
tell_object(plyr,RED+"Linus"+HIK+":"+NORM+HIR+what+NORM+"\n");
  write(RED+"You whisper to "+capitalize(who)+": "+HIR+what+NORM+"\n");
  return 1;
}
cmd_say(str) {
int X, CK, JK, Z;
  if(!str) {
    notify_fail("Huh?!?\n");
    return 0;
  }
  write(RED+"You whisper: "+HIR+str+NORM+"\n");
  say(RED+"Linus whispers: "+HIR+str+NORM+"\n");
  return 1;
}

drop(){
  write("No drop!\n");
  return 1;
}

cmd_st(str) {
  object sob;
  string what;
sob = find_player("linus");
  if(!sob)
    {
      notify_fail(HIY+"Linus isn't logged on.  "+RED+"Heartbreaking, isn't it?"+NORM+"\n");
      return 0;
    }
  if(in_editor(sob)) {
    notify_fail(HIR+"Linus is busy.\nTry again later."+NORM+"\n");
    return 0;
  }
  write(HIR+"You tell Linus: "+HIY+str+NORM+"\n");
  what = RED+this_player()->query_name()+NORM+": "+HIR+str+NORM;
  tell_object(sob,what+"\n");
  return 1;
}
