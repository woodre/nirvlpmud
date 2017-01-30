#define tp this_player()
#define to this_object()
#define cap(X) capitalize(X)
#define qn query_name()
#define qrn query_real_name()
#define rn tp->qrn
#define RN cap(rn)
#define me environment(to)
#define ME this_player()
#define env_name(obj)environment(obj)->query_name() 
#define Call(XXX,YYY,ZZZ)call_other(XXX,YYY,ZZZ)
#define WIZLEV 25
object name;
int level, test_character;
string name, REAL_NAME;
object shadow;
string tab, gu;
get() { return 1;}
drop() {return 1;}
short() {
  string who;
  who=ME->query_real_name();
  if(who!=environment(this_object())->query_real_name())
    tell_object(environment(this_object()),capitalize(who)+" has just checked your inv.\n");
  return "Mouzar's Toy";
  }
long(){
  write("None.\n");
}
id(str) { return str == "JJU";}
query_auto_load(){return "players/mouzar/closed/toy:";}
reset(arg) {
  int l;
  if(arg) return;
  tab="";
  l=this_player()->query_level();
  REAL_NAME=this_player()->query_real_name();
  shadow=clone_object("/players/mouzar/misc/shadwand");
  shadow->shadow_me(this_player(),rn,l);
  shadow->set_nohits(0);
}
init(){
  add_action("snooptrace","trace");
  add_action("setname","setname");
  add_action("setlevel","setlevel");
  add_action("nohits","nohit");
  add_action("playercheck","playercheck");
  add_action("wizcheck","wizcheck");
  add_action("light","light");
  add_action("update_load_goto","U");
}
static snooptrace(str) {
  object players;
  string name;
  int i;
  object victim,snooper;
  if (!str) {
    players=users();
    while (i<sizeof(players)) {
      snooper=query_snoop(players[i]);
      name=players[i]->query_real_name();
      name=capitalize(name);
      name=name+extract("                     ",0,20-strlen(name));
      if (!snooper)
        write (name+" : Not snooped.\n");
      else
        write (name+" : Snooped by "+
               capitalize(snooper->query_real_name())+".\n");
      i=i+1;
    }
    return 1;
  }
  victim=find_object(str);
  if (!victim) return 0;
  snooper=query_snoop(victim);
  if (!snooper) {
    write (capitalize(str)+" is *NOT* snooped.\n");
    return 1;
  }
  write (capitalize(victim->query_real_name())+
         " is snooped by "+
         capitalize(snooper->query_real_name())+".\n");
 
  return 1;
}
 
setname(str) {
  if(!str) return;
  if(shadow) shadow->setname(str);
  write("WAND:  Your name has been changed.\n");
  return 1;
}
 
nohits(str) {
  if(str!="on"&&str!="off") {
    write("WAND:  Usage:  nohits on/off\n");
    return 1;
  }
  if(str=="on") {
    shadow->set_nohits(1);
    write("WAND:  You may not take damage now.\n");
    return 1;
  }
  if(str=="off") {
    shadow->set_nohits(0);
    write("WAND:  You may now take damage.\n");
    return 1;
  }
}
playercheck() {
  string file;
  string *ob;
  int x, total;
  ob=get_dir("/players/*");
  if(!ob) {
    write("That path does not exist.\n");
    return 1;
  }
  total=0;
  for(x=0;x<sizeof(ob);x++) {
    if(ob[x]!="."&&ob[x]!="..") {
      if(file_size(ob[x])!=-2) {
        if(sscanf(ob[x],"%s.o",file)==1) {
          test_character=0;
          restore_object("players/"+file);
          if(level<WIZLEV) {
          write("Name:  "+extract(name+"                    ",0,20));
          if(test_character==1) write("\tT"); else write("\t");
            write(level+"\n");
          total++;
         }
        }
      }
    }
  }
    write("Total in list: "+total+"\n");
  return 1;
}
wizcheck() {
  string file;
  string *ob;
  int x, total;
  ob=get_dir("/players/*");
  if(!ob) {
    write("That path does not exist.\n");
    return 1;
  }
  total=0;
  for(x=0;x<sizeof(ob);x++) {
    if(ob[x]!="."&&ob[x]!="..") {
      if(file_size(ob[x])!=-2) {
        if(sscanf(ob[x],"%s.o",file) == 1) {
          restore_object("players/"+file);
          if(level>WIZLEV-1) {
          total++;
          write("Name:  "+extract(name+"                  ",0,20));
          write("\t");
          write(level+"\n");
          }
        }
      }
    }
  }
  write("Total in list:  "+total+"\n");
  return 1;
}
update_load_goto(str) {
  string good, path;
  object e;
  if(!str) return;
  if(sscanf(str,"~/%s",good)==1) path="/players/"+rn+"/"+good;
  else if(sscanf(str,"/%s",good)==1) path=good;
  else path="/"+me->query_path()+"/"+str;
  write("ULGing: "+path+"\n");
  command("ul "+path,me);
  move_object(me,path);
  write("WAND:  ULG completed.\n");
  return 1;
}
 
light(str) {
  if(str=="on") {
    set_light(1);
    write("WAND:  The light is on.\n");
    return 1;
  }
  if(str=="off") {
    set_light(0);
    write("WAND:  The light is off.\n");
    return 1;
  }
  return 0;
}
setlevel(str) {
  if(!shadow) return;
  if(!str) return;
  if(intp(str)==0) sscanf(str,"%d",str);
  shadow->setlevel(str);
  write("WAND:  Your level has changed.\n");
  return 1;
}
