#include "/players/guilds/bards/def.h"

string get_message(object obj,string str) {
  string message,info;
  mixed *params;
  int wc,ac,wt,val,sav;
 
  message = " *** "+(obj->short()?(string)obj->short():str)+" ***\n";
  wc=(int)obj->weapon_class();
  ac=(int)obj->armor_class();
  wt=(int)obj->query_weight();
  val=(int)obj->query_value();
  if(wc > 0) {
    message+= "It is a weapon, of quality: ";
    switch(wc) {
      case 1..7: message+="Inferior"; break;
      case 8..12: message+="Below Average"; break;
      case 13..15: message+="Average"; break;
      case 16..18: message+="Above Average"; break;
      case 19..21: message+="Superior"; break;
      default: message+="Grandmaster"; break;
    }
    message+= "\n";
    if(obj->query_hit_func())
      message+= "It may also possess a mysterious power.\n";
  }
  if(ac > 0) {
    message+= "It is armor, of type "+(string)obj->query_type()+" and quality: ";
    if((string)obj->query_type()=="armor") {
      switch(ac) {
        case 1: message+="Inferior"; break;
        case 2: message+="Below Average"; break;
        case 3: message+="Average"; break;
        case 4: message+="Above Average"; break;
        default: message+="Grandmaster"; break;
      }
    } else {
      switch(ac) {
        case 1: message+="Average"; break;
        case 2: message+="Above Average"; break;
        default: message+="Grandmaster"; break;
      }
    }
    message+="\n";
    if(obj->query_size())
      message+="It's size "+obj->query_size()+".\n";
  }
  params=(mixed)obj->query_params();
  if(params) {
    int x,s;
    string cat, subcat;
    s=sizeof(params);
    for(x=0;x<s;x+=(wc?3:4))
      if(params[x]!="physical") {
        if(params[x]=="magical")
          message+="It has a damage effect of type: magical\n";
        else if(sscanf(params[x],"%s|%s",cat,subcat)==2)
          message+="It has a damage effect of type: "+subcat+"\n";
      }
  }
  message+="You judge its weight to be: ";
  switch(wt) {
    case -10..1: message+= "very light"; break;
    case 2: message+= "average"; break;
    case 3..4: message+= "heavy"; break;
    case 5..6: message+= "very heavy"; break;
    default: message+= "a lead weight"; break;
  }
  message+="\nIt's worth "+val+" coins.\n";
  sav=(int)obj->query_save_flag();
  if(!sav)
    message+="It seems to be savable.\n";
  else
    message+="It may not be possible to save this.\n";
  if(info=(string)obj->query_info())
    message+="You're able to divine some special information:\n"
           +info+"\n";
  return message;
}

status main(string str) {
  string strwho,strwhat;
  object who,what;
  
  if(spell(-100,3,15) == -1)
    return 0;
  
  if(!str)
    FAIL("identify <what> -or- identify <what> on <who>\n");

  if(sscanf(str, "%s on %s", strwhat, strwho) == 2){
    who = present(strwho, environment(USER));
    if(!who)
      FAIL("You don't see "+strwho+" here.\n");
    what = present(strwhat, who);
    if(!what)
      FAIL(NAME(who)+" has no "+strwhat+".\n");
  } else {
    strwhat=str;
    what = present(strwhat, TP);
    if(!what)
      FAIL("You have no "+str+".\n");
  }
  write(get_message(what,strwhat));
  TP->add_spell_point(-15);
  return 1;
}
