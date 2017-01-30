#include "../defs.h"
#include "/players/feldegast/std/color_pad.h"
#include "/players/feldegast/std/colorize.h"

convert_say(who,str,color,MODE){
int i,a;
string msg;
string EXTRA;

  if(!color) color = "";
  if(!MODE) MODE = "says";
  i = strlen(str)-1;
  EXTRA = " ";
  if(str[i] == ')'){
    if(str[i-1] == ':')  EXTRA = " smiles and ";
    if(str[i-1] == ';')  EXTRA = " winks and ";
  }
  if(str[i] == '('){
    if(str[i-1] == ':')  EXTRA = " frowns and ";
    if(str[i-1] == ';')  EXTRA = " sarcastically frowns and ";
  }
  if(str[i] == 'P' || str[i] == 'p'){
    if( (str[i-1] == '8') || (str[i-1] == ':') || (str[i-1] ==';') ) 
      EXTRA = " sticks out "+this_player()->query_possessive()+" tongue and ";
  }
  msg = color+who+EXTRA+MODE+", \""+OFF+str+color+"\"";
  if(MODE == "says"){
    if(str[i] == '?'){
      msg = color+who+EXTRA+"asks, \""+OFF+str+color+"\"";
      if(str[i-2..i] == "???"){
        msg = color+who+EXTRA+"wonders, \""+OFF+str+color+"\"";
      }
    } 
    if(str[i] == '!'){
      msg = color+who+EXTRA+"exclaims, \""+OFF+str+color+"\"";
      if(str[i-2..i] == "!!!"){
        msg = color+who+EXTRA+"yells, \""+OFF+str+color+"\"";
      }
    }
    if(str[i-2..i] == "..."){
      msg = color+who+EXTRA+"ponders, \""+OFF+str+color+"\"";
    }
  }
  msg = msg+" "+OFF;
  colorize(msg);
  return msg;
}

convert_tell(str,color){
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
string *npclist;
int i,a;
int forcetell;
object *pplob;
object *telltolist;
object *invislist;
object *dcedlist;
object *idlelist;
object *editlist;
object *tellblocklist;
  if(!color) color = "";
  forcetell = 0;
  if(query_verb() == "tell!")
    forcetell = 1;
  ppl = notfoundlist = ({});
  pplob = ({});
  telltolist = invislist = dcedlist = idlelist = editlist = tellblocklist = ({});
  if(!str){
    write("Who do I want to talk with?\n");
    return 1;
  }
  if(sscanf(str,"%s %s",people,msg) != 2){
    write("What do I want to say?\n");
    return 1;
  }
  while(sscanf(people,"%s,%s",arg1,arg2) == 2){
    ppl += arg1;
    people = arg2;
  }
  ppl += people; 
  
  for(i=0,a = sizeof(ppl);i<a;i++){
    if(!find_living(ppl[i]))
      notfoundlist += ppl[i];
    else{
      pplob += find_living(ppl[i]);
    }  
  }

  for(i=0,a=sizeof(pplob);i<a;i++){
    telltolist += pplob[i];
    if(!pplob[i]->query_interactive() && pplob[i]->is_player()){
      dcedlist += pplob[i];
    }
    else{
      if(pplob[i]->query_invis()){
        if(tp->query_level() < pplob[i]->query_level()){
          notfoundlist += ppl[i];
        }
        else{
          invislist += pplob[i];
        }
        if(!forcetell)
          telltolist -= pplob[i];
      }
      if(pplob[i]->is_player())
      if(query_idle(pplob[i]) > 300){
        idlelist += pplob[i];
      }
      if(in_editor(pplob[i])){
        editlist += pplob[i];
        if(!forcetell)
          telltolist -= pplob[i];
      }
      if(pplob[i]->query_tellblock()){
        tellblocklist += pplob[i];
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
  if(sizeof(tellblocklist) > 0){
    format_list(tellblocklist,"tell blocking you");
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
      theirtellmsg = color+"("+OFF+"Invis"+color+") "+tpn+" tells you";
    else
      theirtellmsg = color+tpn+" tells you";
    for(j=0,b=sizeof(newtelltolist);j<b;j++){
        if(j == (b-1))
          theirtellmsg += " and "+newtelltolist[j]->query_name();
        else  
          theirtellmsg += ", "+newtelltolist[j]->query_name();
    }  
    theirtellmsg += ", \""+OFF+msg+color+"\"\n"+OFF;
    historymsg = color+tpn+" told you, \""+OFF+msg+color+"\""+OFF;
    telltolist[i]->add_tellhistory(historymsg);
    tell_object(telltolist[i],theirtellmsg);
    telltolist[i]->Replyer((string)tp->query_real_name());
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
