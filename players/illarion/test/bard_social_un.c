/* bard_social.c 
 * Controls the use of Bard-specific socials
 * Illarion 6/04
 * based on Vertebraker's social code
 */
#include "/players/guilds/bards/lib/ansi_pad.h"
#define SDIR "/players/guilds/bards/socials/"
#define QN(x) (string)x->query_name()
#define OBJ(x) (string)x->query_objective()
#define PRO(x) (string)x->query_pronoun()
#define POS(x) (string)x->query_possessive()

string *verbs;
mixed *info;
string *creators;

reset(arg) {
  if(!verbs)
    restore_me();
  if(!verbs) {
    verbs=({});
    info=({});
    creators=({});
  }
}

string *get_verbs() {
  return verbs;
}

varargs string replace_code(string str,object a,object b) {
  string tmp;
  status cap;
  if(!str)
    return "";
  if(sscanf(str,"C%s",tmp)) {
    str=tmp;
    cap=1;
  }
  switch(str) {
    case "MN": str=QN(a);
      break;
    case "MP": str=POS(a);
      break;
    case "MS": str=PRO(a);
      break;
    case "MO": str=OBJ(a);
      break;
    case "INST": if(a=present("instrument",a)) str=(string)a->query_instrument();
      break;
    case "TN": if(b) str=QN(b);
      break;
    case "TP": if(b) str=POS(b);
      break;
    case "TS": if(b) str=PRO(b);
      break;
    case "TO": if(b) str=OBJ(b);
      break;
    case "RET": str="\n";
      break;
  }
  return cap?capitalize(str):str;
}

varargs string process_codes(string str,object user,object targ) {
  string before,mid,after;
  while(sscanf(str,"%s#%s#%s",before,mid,after))
    str=(before?before:"")+replace_code(mid,user,targ)+(after?after:"");
  while(sscanf(str,"%s$%s$%s",before,mid,after))
    str=(before?before:"")+replace_code(mid,user,targ)+(after?after:"");

  return str;
}

status try_social(string verb, string arg) {
  object me,target,room;
  string temp;
  int x;
  string *stuff;
  status didsomething;
  me=this_player();
  if(!me) 
    return 0;
  room=environment(me);
  if(!room) 
    return 0;
  if(!verb) 
    return 0;
  x=member_array(verb,verbs);
  if(x==-1)
    return 0;
  stuff=info[x];
  if(!stuff || sizeof(stuff)!=7) {
      notify_fail("Bad social.  Inform the guild wizard.\n");
      return 0;
  }
  if(!arg || arg=="" ) {
    if(stuff[0] && stuff[0]!="" && stuff[0]!="none") {
      tell_object(me,ansi_format(process_codes(stuff[0],me)));
      didsomething=1;
    }
    if(stuff[1] && stuff[1]!="" && stuff[1]!="none") {
      tell_room(room,
                ansi_format(process_codes(stuff[1],me)),
                ({me}));
      didsomething=1;
    }
    return didsomething;
  }
  target=present(arg,room);
  if(target && (int)target->query_invis() <= (int)me->query_level()) {
    if(!living(target)) {
      notify_fail("The effect would be lost on an inaminate object.\n");
      return 0;
    }
    if(target==me) {
      notify_fail("A little daftness in a Bard is good, but please!\n");
      return 0;
    }
    if(stuff[2] && stuff[2]!="" && stuff[2]!="none") {
      tell_object(me,ansi_format(process_codes(stuff[2],me,target)));
      didsomething=1;
    }
    if(stuff[3] && stuff[3]!="" && stuff[3]!="none") {
      tell_room(room,ansi_format(process_codes(stuff[3],me,target)),({me,target}));
      didsomething=1;
    }
    if(stuff[4] && stuff[4]!="" && stuff[4]!="none") {
      tell_object(target,ansi_format(process_codes(stuff[4],me,target)));
      didsomething=1;
    }
  } else {
    target=find_player(arg);
    if(!target || (int)target->query_invis() > (int)me->query_level()) {
      notify_fail("Your target is not in the Realms of Magic.\n");
      return 0;
    }
    if(stuff[5] && stuff[5]!="" && stuff[5]!="none") {
      tell_object(me,ansi_format(process_codes(stuff[5],me,target)));
      didsomething=1;
    }
    if(stuff[6] && stuff[6]!="" && stuff[6]!="none") {
      tell_object(target,ansi_format(process_codes(stuff[6],me,target)));
      didsomething=1;
    }
  }
  return didsomething;
}

restore_me() {
  restore_object(file_name(this_object()));
}

save_me() {
  save_object(file_name(this_object()));
}

set_social(name,nfo,creator) {
  int x;
  x=member_array(name,verbs);
  if(x==-1) {
    verbs+=({name});
    info+=({nfo});
    creators+=({creator});
  } else {
    info[x]=nfo;
  }
  save_me();
}

get_creator(name) {
  int x;
  x=member_array(name,verbs);
  if(x==-1) {
    return 0;
  } else {
    return creators[x];
  }
}

get_social(name) {
  int x;
  x=member_array(name,verbs);
  if(x==-1) {
    return 0;
  } else {
    return info[x];
  }
}

remove_social(name) {
  int x,s;
  x=member_array(name,verbs);
  if(x!=-1) {
    s=sizeof(verbs);
    verbs=(x==0?({}):verbs[0..x-1])+(x==s-1?({}):verbs[x+1..s-1]);
    info=(x==0?({}):info[0..x-1])+(x==s-1?({}):info[x+1..s-1]);
    creators=(x==0?({}):creators[0..x-1])+(x==s-1?({}):creators[x+1..s-1]);
    /*
    verbs-=({verbs[x]});
    info[x]="TEMPORARY_REMOVAL_STRING";
    info-=({info[x]});
    creators[x]="TEMPORARY_REMOVAL_STRING";
    creators-=({creators[x]});
    */
  } 
  save_me();
}
