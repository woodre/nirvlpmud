/* 
   wocket did this 
   This is a wiztell mainly for new wizards
   It impliments multiple target tell and forcetells.
   Forcetells are tells that go though editor or invisibility
   while the normal tell would not. ie. tell and tell!
   To make your own wiztell simply inherit this file
   and in reset set owner, cap_name, color, and extra_look.
   the new wiztell will then only be used by you and 
   includes security measures to prevent maluse
   10.1.99
*/
#include "/players/wocket/closed/ansi.h"

string owner;
string cap_owner;
string color;
string extra_look;

id(str){ return (str == owner+"_wiztell" || str == "wiztell"); }
long(){
 write(
   HIR+"Wiztell"+OFF+"(c) V1.0 coded by Wocket 10.1.99\n"+
       "\n"+
   HIR+"Comands:\n"+OFF+
       "  tell <name>,<name2>,...,<nameN>       Multiple tell to players\n"+
       "  tell! <name>,<name2>,...,<nameN>      Force tell to players\n"+
       "                                      (goes through invis and edit)\n"+
       "  say <msg>                             Say to room  \n"+
       "  ' <msg>                                  \"        \n");
       
}
extra_look(){ if(extra_look) return extra_look; }

get(){ return 1; }
drop(){ write("Wiztell is cannot be dropped.\n"); return 1; }

reset(){
 owner = "wocket";
 cap_owner = "Wocket";
 extra_look = "Wocket's eyes glitter in the light";
 color = GRN;
}

init(){
  if (!this_player() || this_player()->is_kid()) return;
  if(this_player()->query_real_name() != owner){
    write("You may not have this!\n");
    write("Destructing object.\n");
    destruct(this_object());
  }
  else{
    add_action("xtell","tell");
    add_action("xtell","tell!");
    add_action("xsay","say");
#ifndef __LDMUD__ /* Rumplemintz */
    add_action("xsay");add_xverb("'");
    add_action("xsay","'");
#else
    add_action("xsay", "'", 3);
#endif
  }
}

xtell(str){
string people;
string msg;
string arg1;
string arg2;
string notfoundmsg;
string dcedmsg;
string idlemsg;
string invismsg;
string editmsg;
string mytellmsg;
string theirtellmsg;
string *ppl;
string *notfoundlist;
int i,a;
int forcetell;
object *pplob;
object *telltolist;
object *invislist;
object *dcedlist;
object *idlelist;
object *editlist;

  forcetell = 0;
  if(query_verb() == "tell!")
    forcetell = 1;
  ppl = notfoundlist = ({});
  pplob = ({});
  telltolist = invislist = dcedlist = idlelist = editlist = ({});
  if(!str){
    notify_fail("Who do I want to talk with?\n");
    return 0;
  }
  if(sscanf(str,"%s %s",people,msg) != 2){
    notify_fail("What do I want to say?\n");
    return 0;
  }
  while(sscanf(people,"%s,%s",arg1,arg2) == 2){
    ppl += arg1;
    people = arg2;
  }
  ppl += ({ people });
  
  for(i=0,a = sizeof(ppl);i<a;i++){
    if(!find_player(ppl[i]))
      notfoundlist += ppl[i];
    else{
      pplob += find_player(ppl[i]);    
    }  
  }

  for(i=0,a=sizeof(pplob);i<a;i++){
    telltolist += pplob[i];
    if(!pplob[i]->query_interactive()){
      dcedlist += pplob[i];
    }
    else{
      if(pplob[i]->query_invis()){
        invislist += pplob[i];
      }
      if(query_idle(pplob[i]) > 300){
        idlelist += pplob[i];
      }
      if(in_editor(pplob[i])){
        editlist += pplob[i];
        if(!forcetell)
          telltolist -= pplob[i];
      }
      
    }
  } 
  
  if(sizeof(notfoundlist) > 0){
    for(i=0,a=sizeof(notfoundlist);i<a;i++){
      if(!notfoundmsg)
        notfoundmsg = capitalize(notfoundlist[i]);
      else{
        if(i == (a-1))
        notfoundmsg += " and "+capitalize(notfoundlist[i]);
        else
        notfoundmsg += ", "+capitalize(notfoundlist[i]);
      }
    }
    if(sizeof(notfoundlist) == 1)
      notfoundmsg += " was ";
    else
      notfoundmsg += " were ";
    notfoundmsg += "not found.\n";
    write(notfoundmsg);
  }
 
  if(sizeof(dcedlist) > 0){
    format_list(dcedlist,"disconnected");
  } 
  
  if(sizeof(idlelist) > 0){
    format_list(idlelist,"idle");
  } 
   
  if(sizeof(editlist) > 0){
    format_list(editlist,"editing right now");
  } 
   
  if(sizeof(invislist) > 0){
    format_list(invislist,"invisible");
  }
    
  if(sizeof(telltolist) == 0){
    write("No tell sent.\n");
    return 1;
  }

  mytellmsg = color+"You tell ";
  for(i=0,a=sizeof(telltolist);i<a;i++){
    if(i==0)
     mytellmsg += capitalize(telltolist[i]->query_real_name());
    else{
      if(i==(a-1))
        mytellmsg += " and "+capitalize(telltolist[i]->query_real_name());
      else
        mytellmsg += ", "+capitalize(telltolist[i]->query_real_name());
    }
  }
  mytellmsg += ", \""+OFF+msg+color+"\"\n"+OFF;
  write(mytellmsg);

  for(i=0,a=sizeof(telltolist);i<a;i++){
  int j,b;
  string historymsg;
  object *newtelltolist;
    newtelltolist = allocate(sizeof(telltolist));
    newtelltolist = telltolist;
    newtelltolist -= telltolist[i];
    if(this_player()->query_invis())
      theirtellmsg = color+"("+OFF+"Invis"+color+") "+cap_owner+" tells you";
    else
      theirtellmsg = color+cap_owner+" tells you";
    for(j=0,b=sizeof(newtelltolist);j<b;j++){
        if(j == (b-1))
          theirtellmsg += " and "+newtelltolist[j]->query_name();
        else  
          theirtellmsg += ", "+newtelltolist[j]->query_name();
    }  
    theirtellmsg += ", \""+OFF+msg+color+"\"\n"+OFF;
    historymsg = color+cap_owner+" told you, \""+OFF+msg+color+"\"\n"+OFF;
    telltolist[i]->add_tellhistory(historymsg);
    tell_object(telltolist[i],theirtellmsg);
      telltolist[i]->Replyer((string)this_player()->query_real_name());
  } 
  return 1;
}


format_list(object *oblist,string ending){
int i,a;
string returnmsg;
    for(i=0,a=sizeof(oblist);i<a;i++){
      if(!returnmsg)
        returnmsg = capitalize(oblist[i]->query_real_name());
      else{
        if(i == (a-1))
        returnmsg += " and "+capitalize(oblist[i]->query_real_name());
        else
        returnmsg += ", "+capitalize(oblist[i]->query_real_name());
      }
    }
    if(sizeof(oblist) == 1)
      returnmsg += " is ";
    else
      returnmsg += " are ";
      returnmsg += ending+".\n";
    write(returnmsg); 
} 
 
xsay(str){
  int i;
  string verb,verb2;
  if(!str){
    notify_fail("What do I want to say?\n");
    return 0;
  }
    verb = "says"; verb2 = "say";
  i = strlen(str)-1;
  if(str[i] == '?'){
    verb = "asks"; verb2 = "ask";
  }
  if(str[i] == '!'){
    verb="exclaims"; verb2 = "exclaim";
  }
  say(color+this_player()->query_name()+" "+verb+", \""+OFF+str+color+"\" \n"+OFF);
  write(color+"You "+verb2+", \""+OFF+str+color+"\" \n"+OFF);
  return 1;
}
