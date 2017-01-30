#include "/players/cosmo/closed/ansi.h"
#define SYM HIR+"~"+HIY+"o"+HIR+"~"+NORM
#define RING HIY+"-"+HIW+"*"+HIY+"-"+NORM
#define TP capitalize(this_player()->query_real_name())
#define EP environment()->query_real_name()

id(str) {
    return str == "bat";
}

short() {
  if(EP=="keli") return(RING);
  else return(SYM);
}

reset(arg) {
  if(arg) return;
}

long() {
    write("Cosmo's talking bat\n");
    write("Usage: batt [msg] or batt :[emote]\n");
    write("Also, mute_bat will get rid of it.\n");
}

drop() {return 1;}
get() { return 0; }


query_auto_load() {
    return "/players/cosmo/closed/batt.c:";
}

init() {
  add_action("mute_bat","mute_bat");
  add_action("batt","batt");
  add_action("pounce","pounce");
  add_action("squeal","squeal");
  if(this_player()->query_real_name() == "cosmo") {
    add_action("bat_to","bat_to");
    add_action("bat","bat");
  }
}

mute_bat() {
  write("The bat flies home to Cosmo.\n");
  destruct(this_object());
  return 1;
}

batt (str) {
string what, who;
  if(!sscanf(str, "%s",what)) {
    write(SYM+" Usage: batt [message]\n");
    return 1;
  }
  who = find_player("cosmo");
  if(!who) {
   write(SYM+" Cosmo is unavailable.\n");
   return 1;
  }
  if(!who->query_interactive()) {
    write(SYM+" Cosmo is disconnected.\n");
    return 1;
  }
  if(what[0] == ':'){
    what = what[1..strlen(what)];
    if(!what){ return 1; }
    if(who->query_interactive()){
       write(HIB+"["+NORM+query_idle(who)+HIB+"] "+NORM);
    }
    tell_object(who,SYM+" "+TP+HIY+" "+format(what,60)+NORM+"\n");
    write(SYM+" The bat squeaks to Cosmo: "+TP
       +HIY+" "+format(what,50)+NORM+"\n");
    return 1;
  }
  if(who->query_interactive()){
     write(HIB+"["+NORM+query_idle(who)+HIB+"] "+NORM);
  }
  tell_object(who,SYM+" "+TP+": "+HIY+format(what,60)+NORM+"\n");
  write(SYM+" The bat squeaks to Cosmo: "+HIY+format(what,50)+NORM+"\n");
  who->add_tellhistory(TP+" tells you: "+what);
  return 1;
}

bat_to(str) {
object bat, target;
  target = find_living(str);
  if(!target) { write("No one on with that name.\n"); return 1; }
  bat = clone_object("players/cosmo/closed/batt.c");
  move_object(bat,target);
  tell_object(target, "Cosmo has given you a bat.\n");
  write("You gave "+str+" a bat.\n");
  return 1;
}

bat (str) {
object target;
string what, who;
  if(!sscanf(str, "%s %s",who,what)) {
    write(SYM+" Usage: bat <player> [message]\n");
    return 1;
  }
  target = find_player(who);
  if(!target) {
   write(SYM+" "+who+" is unavailable.\n");
   return 1;
  }
  if(!target->query_interactive()) {
    write(SYM+" "+target+" is disconnected.\n");
    return 1;
  }
  if(in_editor(target)) {
    write("That player is editing...\n");
    return 1;
  }
  if(what[0] == ':'){
    what = what[1..strlen(what)];
    if(!what){ return 1; }
    if(target->query_interactive()){
       write(HIB+"["+NORM+query_idle(target)+HIB+"] "+NORM);
    }
    tell_object(target,SYM+" "+TP+NORM+" "+format(what,60)+NORM+"\n");
    write(SYM+" The bat squeaks to "+capitalize(who)+": "+TP
       +HIY+" "+format(what,50)+NORM+"\n");
    return 1;
  }
  tell_object(target,SYM+" "
    +"Cosmo tells you: "+NORM+format(what,60)+NORM+"\n");
  if(target->query_interactive()){
     write(HIB+"["+NORM+query_idle(target)+HIB+"] "+NORM);
  }
  write(SYM+" The bat squeaks to "+
    capitalize(who)+": "+HIY+format(what,50)+NORM+"\n");
  target->add_tellhistory(TP+" tells you: "+what);
  return 1;
}

int pounce(string str) {
object who;
  if(!str) { write("Pounce on whom?\n"); return 1; }
  who = present(str, environment(this_player()));
  if(who && living(who)) {
    if(who == this_player()) return 0;
    write("You pounce playfully on "+capitalize(str)+".\n");
    tell_object(who, this_player()->query_name()+" playfully pounces on you!\n");
    say(this_player()->query_name()+" playfully pounces on "+capitalize(str)+".\n", who);
  }
  else {
    who = find_player(str);
    if(!who || who == this_player() || in_editor(who) || who->query_invis() >= 20)
       { write("Pounce on whom?\n"); return 1; }
    write("You pounce playfully on "+capitalize(str)+" from afar.\n");
    tell_object(who, this_player()->query_name()+" pounces on you playfully from afar.\n"); 
  }
  return 1;
}

int squeal() {
    write("You squeal with delight!\n");
    say(this_player()->query_name()+ " squeals with delight.\n");
    return 1;
}
