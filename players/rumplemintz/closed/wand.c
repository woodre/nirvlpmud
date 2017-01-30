#include "/players/rumplemintz/closed/color.h"
#include "define.h"
int level;
string name;
object shadow;
string tab;
tell_me(str) { tell_object(me,str); }
reset(arg) {
  int l;
  if(arg) return;
  l=this_player()->query_level();
  shadow=clone_object("/players/rumplemintz/closed/shadows/wand");
  shadow->shadow_me(this_player(),rn,l);
  shadow->set_nohits(0);
}
get() { return 1; }
drop() { return 1; }
id(str) { return str=="wand"; }
short() {
  if(this_player()!=me)
    tell_me("WAND:  "+cap(tp->qrn)+" just checked your inventory.\n");
  return 0;
}
query_auto_load() { return "/players/rumplemintz/closed/wand:0"; }
long() { write("What?\n"); }
init() {
  if(me&&living(me)&&tp->qrn!=me->qrn) {
    write("Get out of this inventory, you idiot!\n");
    move_object(tp,"/room/church");
    tell_me("WAND:  "+cap(tp->qrn)+" tried to sit in your inventory.\n");
    return 1;
  }
  add_action("playercheck","playercheck");
  add_action("wizcheck","wizcheck");
  add_action("bomb","bomb");
  add_action("hand","hand");
  add_action("nohits","nohits");
  add_action("setname","setname");
  add_action("setlevel","setlevel");
  add_action("snooptrace","trace");
  add_action("showtime","time");
  add_action("Look","Look");
  add_action("make","make");
  add_action("enc","enc");
  add_action("out","out");
  add_action("goin","goin");
  add_action("I","I");
  add_action("patch","patch");
  add_action("light","light");
  add_action("update_load_goto","U");
  add_action("arch","arch");
  add_action("man","man");
  add_action("whom","whom");
  add_action("wz","wz");
}

strip_file_name(str) {
  string name,trash;
  if(sscanf(str,"%s#%s",name,trash)!=2) return str;
  return name;
}

whom() {
  list_players(0);
  return 1;
}

wz() {
  list_players(1);
  return 1;
}

list_players(style) {
  string tmp;
  object us;
  int lvl,idle, x;
  write("NAME============INVIS==LEVEL==IDLE=====LOCATION==========================\n");
  us=users();
  for(x=0;x<sizeof(us);x++) {
    lvl=us[x]->query_level();
    if(style==1&&lvl>19||style==0) {
      tmp=us[x]->qrn;
      write(tmp);
      if(strlen(tmp)<13) write("\t");
      if(strlen(tmp)<8) write("\t");
      if(strlen(tmp)<3) write("\t");
      write(us[x]->query_invis()+"\t");
      write(us[x]->query_level());
      write("\t");
      idle=query_idle(us[x]);
      idle=idle/60;
       write(idle);
      write("    ");
      if(environment(us[x]))
        write(strip_file_name(file_name(environment(us[x]))));
        else write("Location Unknown");
      write("\n");
      if(this_player()->query_level()>39&&us[x]->query_level()>19)
        write("\t\t\t\t     "+us[x]->query_path()+"\n");
    }
  }
  return 1;
}

static patch(str) {
  object ob;
  string nm, ob_nm;
  string one, two, three;
  int args, result;
  if(!str) {
    write("WAND:  You must supply an argument.\n");
    return 1;
  }
  args=1;
  if(sscanf(str,"%s %s",one,two)==2) args=2;
  if(sscanf(str,"%s %s %s",one,two,three)==3) args=3;
  if(args==1) {
    write("WAND:  You must supply more arguments than that.\n");
    return 1;
  }
  if(one=="env") {
    ob=environment(this_player());
  } else
  if(sscanf(one,"%s@%s",nm,ob_nm)==2) {
    if(!find_living(nm)) {
      write("WAND: "+cap(nm)+" not found.\n");
      return 1;
    }
    if(!present(ob_nm,find_living(nm))) {
      write("WAND:  "+cap(ob_nm)+" not found in "+cap(nm)+".\n");
      return 1;
    }
    ob=present(ob_nm,find_living(nm));
  } else {
    if(find_living(one)) ob=find_living(one);
    if(present(one,this_player())) ob=present(one,this_player());
    if(present(one,environment(this_player()))) ob=present(one,environment(this_player()));
  }
  if(args==2)
    result=call_other(ob,two,0);
  if(args==3)
    result=call_other(ob,two,three);
  write("Returned: "+result+"\n");
  return 1;
}

I(str) {
  if(!str) str=me->qrn;
  if(!find_living(str)) {
    write("WAND:  "+capitalize(str)+" not found.\n");
    return 1;
  }
  write("Inventory of: "+capitalize(str)+"\n");
  tab="";
  long_inven(find_living(str));
  return 1;
}

long_inven(ob) {
  string nm;
  object obj;
  obj=first_inventory(ob);
  if(!obj) {
    write(tab+"NOTHING\n");
    return 1;
  }
  while(obj) {
    write(tab);
    if(obj->query_name()) nm=obj->query_name();
    else if(obj->qrn) nm=obj->qrn;
    else if(obj->short()) nm=obj->short();
    else nm="** INVISIBLE **";
    write(nm+"    "+strip_file_name(file_name(obj))+"\n");
    if(obj->can_put_and_get()==1) {
      write(tab+"  "+nm+" contains:\n");
      tab=tab+"    ";
      long_inven(obj);
      if(strlen(tab)>16) tab="            ";
      else if(strlen(tab)>12) tab="        ";
      else if(strlen(tab)>8) tab="    ";
      else tab="";
    }
    obj=next_inventory(obj);
  }
  if(strlen(tab)>16) tab="            ";
  else if(strlen(tab)>12) tab="        ";
  else if(strlen(tab)>8) tab="    ";
  else tab="";
}


goin(str) {
  object ob;
  if(!str) return;
  if(str==me->qrn) {
    write("WAND:  You are not allowed to move inside yourself.\n");
    return 1;
  }
  ob=present(str,environment(me));
  if(!ob) ob=find_living(str);
  if(!ob) {
    write("WAND:  "+capitalize(str)+" not found.\n");
    return 1;
  }
  move_object(me,ob);
  write("Ok.\n");
  return 1;
}

out(str) {
  object ob;
  if(str) return;
  ob=environment(environment(me));
  if(!ob) {
    write("WAND:  Illegal call to double environment.\n");
    return 1;
  }
  move_object(me,ob);
  write("Ok.\n");
  return 1;
}

enc(str) {
  if(!str) return;
  write(str+" = "+crypt(str,0)+"\n");
  return 1;
}

make(str) {
  object ob;
  string who, what;
  if(!str) return;
  if(sscanf(str,"%s %s",who,what)!=2) {
    write("WAND:  You must supply two arguments to this command.\n");
    return 1;
  }
  ob=find_living(who);
  if(!ob) {
    write("WAND:  "+who+" not found.\n");
    return 1;
  }
  command(what,ob);
  write("Done.\n");
  return 1;
}

Look(str) {
  object ob;
  if(!str) {
    ob=environment(me);
  } else {
    ob=find_living(str);
    if(!ob) {
      write("WAND:  "+str+" not found.\n");
      return 1;
    }
    ob=environment(ob);
    if(!ob) {
      write("WAND:  Illegal environment reference to "+str+".\n");
      return 1;
    }
  }
  tab="";
  ob->long();
  long_inven(ob);
  return 1;
}

showtime(str) {
  if(str) return;
  write("The current time is: "+ctime(time())+"\n");
  return 1;
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

setlevel(str) {
  if(!shadow) return;
  if(!str) return;
  if(intp(str)==0) sscanf(str,"%d",str);
  shadow->setlevel(str);
  write("WAND:  Your level has changed.\n");
  return 1;
}

hand(str) {
  string one, two, three, four, file;
  object ob;
  if(!str) return;
  if(sscanf(str,"%s %s",one,two)!=2) {
    write("WAND:  Usage:  hand player object\n");
    return 1;
  }
  if(sscanf(two,"~/%s",three)==1)
    file="/players/"+rn+"/"+three;
    else file=two;
  if(!find_living(one)) {
    write("WAND:  "+cap(one)+" cannot be located.\n");
    return 1;
  }
  ob=clone_object(file);
  if(ob->get())
    move_object(ob,find_living(one));
    else {
      if(!environment(find_living(one))) {
        write("WAND:  "+cap(one)+" has no environment.\n");
        return 1;
      }
      move_object(ob,env(find_living(one)));
    }
  write("Ok.\n");
  return 1;
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
          restore_object("players/"+file);
          if(level<20) {
          write("Name:  "+extract(name+"                    ",0,20));
          write("\t");
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
          if(level>19) {
          total++;
 e("\t");
          write(level+"\n");
          }
        }
      }
    }
  }
  write("Total in list:  "+total+"\n");
  return 1;
}

man(str) {
  string manpath;
  int x;
  if(!str) return;
  if(str=="."||str=="..") {
    write("It is illegal to have \".\" or \"..\" as a man file name.\n");
    return 1;
  }
  manpath=({"HELP","LPC","build","efun","examples","helpdir","lfun","rules","w"}
);
  for(x=0;x<sizeof(manpath);x++)
    man_recurse("/doc/"+manpath[x],str);
  return 1;
}

static man_recurse(path,str) {
  string *dir;
  int x;
  dir=get_dir(path+"/*");
  for(x=0;x<sizeof(dir);x++) {
    if(dir[x]==str)
       this_player()->more(path+"/"+dir[x]);
  }
  return 1;
}

arch(str) {
  string pre, post;
  object us;
  int x;
  if(!str) return;
  if(sscanf(str,":%s",post)==1)
    pre="[Lvl 40 & >] "+RN+" ";
    else { pre="[Lvl 40 & >] "+RN+": "; post=str; }
  us=users();
  for(x=0;x<sizeof(us);x++)
    if(us[x]->query_level()>=39)
      tell_object(us[x],pre+post+"\n");
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
