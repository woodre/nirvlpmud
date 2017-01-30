#include "/players/forbin/define.h"
inherit "obj/treasure";

id(str) { return (::id(str) || str == "pf" || str == "personfinder"); }

int OnOff, Here;
string Target;


reset(arg) {
  if(arg) return;
  Target = "person";
}

string short() {
  object a, e;

  if((a = this_player()) && (e = environment()) && (e == a)) {
  if(OnOff) 
    return HIC+"A "+capitalize(Target)+"Finder("+HIW+"c"+HIC+") ["+NORM+"invis"+HIC+"] ("+HIW+"on"+HIC+")"+NORM; 
  else
    return HIC+"A "+capitalize(Target)+"Finder("+HIW+"c"+HIC+") ["+NORM+"invis"+HIC+"]"+NORM;
}
}

long() {
  object a, e;

  if((a = this_player()) && (e = environment()) && (e == a)) {
    write("\nThis device will notify you when it finds a "+capitalize(Target)+"!\n");
    if(OnOff) write("The "+capitalize(Target)+"Finder(c) is "+HIC+"ON"+NORM+"\n");
    else write("The "+capitalize(Target)+"Finder(c) is "+HIW+"OFF"+NORM+"\n");
    write("Commands:  pfset <target>, pfon, pfoff, pfreset.\n");    
    return 1;
  }
}

status get() { return 1; }
status drop() { return 1; }

status cmd_pfset(string str) {
  Target = str;
  tell_object(environment(this_object()), "Target set to: "+capitalize(Target)+".\n"); 
  return 1;
}

set_fake_hb(arg) {
  while(remove_call_out("fake_hb") != -1) ;
  if(arg) call_out("fake_hb", 3);
}

cmd_pfon() {
  if(Target == "person") {
    tell_object(environment(this_object()),
      "You must specify someone to watch for!\n");
    return 1;
  }
  set_fake_hb(1);
  write(capitalize(Target)+"Finder(c) switched on.\n");
  OnOff = 1;
  return 1;
}

cmd_pfoff(string silent)  {
  set_fake_hb(0);
  if(!silent)
    write(capitalize(Target)+"Finder(c) switched off.\n");
  OnOff = 0;
  return 1;
}

status cmd_pfreset(string str) {
  tell_object(environment(this_object()), capitalize(Target)+"Finder(c) reset.\n"); 
  Here = 0;
  cmd_pfoff(1); /* silent off */
  return 1;
}

fake_hb() {
  object ob, who; 
  set_fake_hb(0); 
  ob = environment(this_object());
  if(!living(ob)) set_fake_hb(0);
  who = find_player(Target);
  if(!Here) {
    if(who) {
      tell_object(ob, "\n\n\t"+HIC+capitalize(Target)+" has just logged into Nirvana.\n\n"+NORM);
      Here = 1;
    }
  }
  else {
    if(!who) {
      tell_object(ob, "\n\n\t"+HIC+capitalize(Target)+" has just logged off.\n\n"+NORM);
      Here = 0;
    }
  }  
  set_fake_hb(1);   
}

void init() {
  if((string)this_player()->query_real_name() != ("pestilence")) {
    cmd_pfoff(1);
    destruct(this_object());
  }    
  add_action("cmd_pfon", "pfon");
  add_action("cmd_pfoff", "pfoff");
  add_action("cmd_pfset", "pfset");
  add_action("cmd_pfreset", "pfreset");
}
