inherit "obj/treasure";
#include "/players/illarion/dfns.h"

object worn_by;

reset(int arg) {
  if(arg) return;
  
  set_id("ring");
  set_short("An "+CYN+"oddly glowing"+NORM+" ring");
  set_long(
"A slim mithril band carved with a few small runes, and glowing with an\n"+
"odd light.");
}
get(int s) {
  if(TP->query_real_name()!="illarion") {
    destruct(this_object());
    return 1;
  }
  return 0;
}
drop(int s) {
  return 1;
}
init() {
  if(TP->query_real_name()!="illarion") return;
  ::init();
  add_action("cmd_wear","wear");
  add_action("cmd_remove","remove");
  add_action("cmd_tell","tell");
  add_action("cmd_tell","telle");
  add_action("cmd_say","say");
  add_action("cmd_scarf","scarf");
}
void check_wear() {
  object ob;
  if(!worn_by) return;
  if(!(ob=environment(this_object())) || ob!=worn_by) {
    worn_by=0;
    return;
  }
}
short() {
  object ob,ob2;
  if((ob=environment(this_object()))) 
    if(TP && TP!=ob && (ob2=environment(ob)) && (!present(TP,ob2)))
      if(!present(TP,ob2)) {
        write("     NOSY       NOSY!\n");
        tell_object(ob,capitalize(TP->query_real_name())+" is being nosy.\n");
      }
  check_wear();
  return ::short()+(worn_by?" (worn)":"");
}
cmd_wear(string str) {
  if(!str || present(str,TP)!=this_object())
    FAIL("Wear what?\n");
  check_wear();
  if(worn_by) {
    write("You already wear it!\n");
    return 1;
  }
  write("You slip on the engagement ring.\n");
  say(TPN+" slips on an engagement ring.\n");
  worn_by=TP;
  return 1;
}
cmd_remove(string str) {
  if(!str || present(str,TP)!=this_object())
    FAIL("Remove what?\n");
  check_wear();
  if(!worn_by) {
    write("You aren't wearing it.\n");
    return 1;
  }
  write("You slip off the engagement ring.\n");
  say(TPN+" takes off an engagement ring!\n");
  worn_by=0;
  return 1;
}
cmd_scarf(string str) {
  object ob;
  if(!str) FAIL("To who?\n");
  if(!(ob=find_player(lower_case(str)))) FAIL(capitalize(str)+" is not on.\n");
    if(present("scarf",ob)) {
      write(ob->query_name()+" already has a scarf.\n");
      return 1;
    }
  tell_object(ob,
    "A piece of cloth seperates from the shadows and lands in your hand.\n"+
    "It can be used to "+BLD("itell(e)")+" Illarion something.\n");
  write("Scarf placed on "+ob->query_name()+".\n");
  transfer(clone_object("/players/illarion/obj/bscarf"),ob);
  return 1;
}
cmd_tell(string str) {
  string who; string what; string verb;
  string final;
  object ob;
  verb=query_verb();
  if(!str) FAIL(capitalize(verb)+" who what?\n");
  if(!sscanf(str,"%s %s",who,what))
    FAIL("Tell "+capitalize(str)+" what?\n");
  if(!(ob=find_player(lower_case(who))))
    FAIL(capitalize(who)+" is not here.\n");
  if(ob->query_level() > TP->query_level() && in_editor(ob))
    FAIL("Not while they're editing.\n");
  if(!ob->query_interactive()) 
    write(capitalize(who)+" is linkdead, and won't hear this.\n");
  final=call_other(CLF,"colorformat",BOLD+"From the shadows"+NORM+", "+TPN+
    (verb=="tell"?" tells you: ":" ")+what,78);
  tell_object(ob,final);
  if(verb=="tell")
    write(call_other(CLF,"colorformat",
      "You shadowtell "+ob->query_name()+": "+what+"\n",78));
  else
    write(call_other(CLF,"colorformat",
      "(telle=>"+ob->query_name()+") "+TPN+" "+what+"\n",78));
  return 1;
}
cmd_say(string str) {
  string output;
  string sverb,rverb,modifier;
  string temp,temp2;
  rverb="says";
  sverb="say";
  if(!str) {
    write("Say what?");
    return 1;
  }
  if((temp=extract(str,strlen(str)-2))=="?!" || temp == "!?") {
    sverb="demand";
    rverb="demands";
  } else if(extract(str,strlen(str)-1)=="?") {
    sverb="inquire";
    rverb="inquires";
  } else if(extract(str,strlen(str)-1)=="!") {
    sverb="exclaim";
    rverb="exclaims";
  }
  if(sscanf(str,"%s:)",temp)) {
    modifier=" with a smile";
  } else if(sscanf(str,"%s;)",temp)) {
    modifier=" with a wink";
  } else if(sscanf(str,"%s:(",temp)) {
    modifier=" with a frown";
  }
  write(call_other(CLF,"colorformat",
    "You "+(modifier?sverb+modifier:"softly "+sverb)+", \""+
    CYN+str+NORM+"\"\n",78));
  say(call_other(CLF,"colorformat",
    TPN+" "+(modifier?rverb+modifier:"softly "+rverb)+", \""+
    str+"\"\n",78));
  return 1;
}
