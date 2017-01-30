#include "/players/cosmo/closed/ansi.h"
#define SYM HIY+"-"+HIC+"*"+HIY+"-"+NORM
#define tp this_player()->query_real_name()
#define TP capitalize(tp)
#define EP environment()->query_real_name()

object spouse;
string name;

id(str) { return str == "ring" || str == "wedding ring"; }

reset(arg) {
  if(arg) return;
  name = "vacant";
}

short() { 
    return(SYM+" ["+BOLD+capitalize(name)+NORM+"] (eternally worn)");
}

long() {
  write("A beautiful diamond wedding ring.\n");
  write("Type 'ring_help' for a list of commands.\n");
}

extra_look() {
  write(capitalize(EP)+" is wearing a stunning diamond wedding ring "+SYM+"\n");
}

drop() {return 1;}
get() {return 0;}

query_auto_load() { return "/players/cosmo/closed/ring.c:"+name; }

init_arg(str) { 
string so;
  sscanf(str,"%s",so);
  name = so;
}

init() {
  if(!environment()) return;
  if(this_player()->is_player()){
    spouse = find_player(name);
    add_action("ring_help","ring_help");
    add_action("crush_ring","crush_ring");
    add_action("restore_ring","restore");
    add_action("rt","rt");
  }
}

ring_help() {
   write(HIB+"Commands you can use:\n"+NORM+
      "\trt              talk\n"+
      "\trt :            emote\n"+
      "\trt @            echo\n"+
      "\trestore ring    restores your spouse's ring\n"+
      "\tcrush_ring      divorce\n"+NORM);
   return 1;
}

crush_ring() {
  write("You stomp on the ring in disgust and it disappears forever.\n");
  destruct(this_object());
  return 1;
}

restore_ring(str) {
object newring;
  if(!str) { write("Usage: restore ring\n"); return 1; }
  if(!find_player(name)) { 
    write("Your spouse must be here to restore your ring.\n");
    return 1;
  }
  spouse = find_player(name);
  if(present("wedding ring",spouse)){
    write("You spouse already has their ring.\n");
    return 1;
  }
  newring = clone_object("/players/cosmo/closed/ring.c");
  newring->set_spouse(tp);
  move_object(newring,spouse);
  write(SYM+"Restoring spouse's ring...\n");
  tell_object(spouse,SYM+"Your ring has been restored.\n");
  return 1;
}

rt(str) {
string what, verb, msg;
int i;
  if(!sscanf(str, "%s",what)) {
    write(SYM+" Usage: rt [message], rt :[emote], or rt @[echo]\n");
    return 1;
  }
  spouse = find_player(name);
  if(!spouse) {
   write(SYM+" "+capitalize(name)+" is not logged on.\n");
   return 1;
  }
  if(!spouse->query_interactive()) {
    write(SYM+" "+capitalize(name)+" is disconnected.\n");
    return 1;
  }
  msg = SYM;
  i = strlen(what)-1;
  if(what[0] == ':') {
    what = what[1..i];
    if(!what){ return 1; }
    msg += " "+BOLD+TP+" "+format(what,50)+NORM+"\n";
  }
  else if(what[0] == '@') {
    what = what[1..i];
    if(!what){ return 1; }
    msg += " "+BOLD+format(what,50)+NORM+"\n";
  }
  else {
    if(what[i] == '?') verb = " asks: ";
    else if(what[i] == '!') verb = " exclaims: ";
    else verb = " says: ";
    msg += " "+BOLD+TP+verb+format(what,50)+NORM+"\n";
  }
  tell_object(spouse,msg);
  write(HIB+"["+NORM+query_idle(spouse)+HIB+"] "+NORM+msg);
  return 1;
}

set_spouse(str) { name = str; }
query_spouse(str) { return name; }
