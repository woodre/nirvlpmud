/***************************************************************\
This object provides a flexible who function, designed to let
the user pick and choose who will be displayed, and what information
will be displayed.
simply call display_who (from another object) with a string for the
options.  The format is something like this:
<option> <option> -<display option>
That's a bit unclear, so here are some examples:
female ninja -weapon will show all the female cyberninjas on, and
                what weapons they are wielding
The number of options is unlimited, but only one display option will do 
anything.
***********************************************************/

inherit "obj/clean";
#include "/players/illarion/dfns.h"

string spacing(string str,int max) {
  int n;
  string ret_val;
  ret_val="";
  n=max-strlen(str);
  while(n>0) {
    ret_val+=" ";
    n--;
  }
  return ret_val;
}
int comp_str(string str1,string str2) {
  if(!str1 || !str2) return 0;
  return extract(str2,0,strlen(str1)-1)==str1;
}
filter_ppl(object ob,string opt) {
  int i,j;
  int tmp;
  if(ob->query_invis()>18) return 0;
  if(ob->query_level()==-1) return 0;
  if(!opt) return 1;
  if(sscanf(opt,"<%d",i)) return ob->query_level()<i;
  if(sscanf(opt,">%d",i)) return ob->query_level()>i;
  if(sscanf(opt,"=%d",i)) return ob->query_level()==i;
  switch(opt) {
    case "male": return ob->query_gender()=="male";
    case "female": return ob->query_gender()=="female";
    case "combat": return objectp(ob->query_attack());
    case "player": return ob->query_level()<20;
    case "wiz": return ob->query_level()>19;
    case "knight": return ob->query_guild_name()=="Knights Templar";
    case "vampire": return ob->query_guild_name()=="vampire";
    case "ninja": return ob->query_guild_name()=="cyberninja";
    case "poly": return ob->query_guild_name()=="polymorph";
    case "mage": return ob->query_guild_name()=="mage";
    default: return comp_str(opt,ob->query_real_name());
  }
  return 1;
}
special_col(object ob,string disp) {
  string tmp;
  object tmpob;
  int n;
  if(!disp) return 0;
  switch(disp) {
    case "title": return ob->query_title();
    case "pretitle":
      return (tmp=ob->query_pretitle())?tmp:"no pretitle";
    case "weapon":
      if(ob->query_name_of_weapon())
         tmp=(tmp=ob->query_name_of_weapon()->short())?tmp:"invis weapon";
      else tmp="No weapon";
      return tmp+" ("+ob->query_wc()+")";
    case "idle": return (n=query_idle(ob))/60+"min "+n%60+"sec";
    case "attacker":
      return (tmpob=ob->query_attack())?tmpob->short()+" hp "+
             tmpob->query_hp()+"("+tmpob->query_mhp()+")":"No attacker";
    case "ipnum":
    case "file":
      return (tmpob=environment(ob))?file_name(tmpob):0;
    case "ip":
      return query_ip_name(ob);
      return query_ip_number(ob); 
    case "status":
      return (tmp="hp "+ob->query_hp()+"("+ob->query_mhp()+")")+
           spacing(tmp,18)+(tmp="sp "+ob->query_sp()+"("+ob->query_msp()+")")+
           spacing(tmp,18)+" wc:"+ob->query_wc()+spacing(""+ob->query_wc(),3)+
           " ac:"+ob->query_ac();
  }
  return 0;
}
display_who(string opt) {
  object *ppl;
    string *opts;
  int size,n;
  string tmpstr,display;
  int tmpint;
  ppl=users();
  if(opt) {
    opts=explode(opt," ");
    size=sizeof(opts);
    for(n=0;n<size;n++)
      if(sscanf(opts[n],"-%s",tmpstr)) display=tmpstr;
      else ppl=filter_array(ppl,"filter_ppl",this_object(),opts[n]);
  }
  ppl=filter_array(ppl,"filter_ppl",this_object(),0);
  size=sizeof(ppl);
  if(!size) {
    write("No users found.\n");
    return 1;
  }
  if(opt)
  for(n=0;n<size;n++) {
    write((tmpstr=ppl[n]->query_name()));
    write(spacing(tmpstr,13));
    if((tmpint=ppl[n]->query_level())>19)
      tmpstr="|"+tmpint;
    else
      tmpstr="|"+tmpint+((tmpint=ppl[n]->query_extra_level())?"+"+tmpint:"");
    write(tmpstr+spacing(tmpstr,7));
    tmpstr=ppl[n]->query_guild_name();
    if(!tmpstr) tmpstr="|none";
    else tmpstr="|"+extract(tmpstr,0,3);
    write(tmpstr);
  write((tmpstr=ppl[n]->query_gender())=="male"?"|M|":tmpstr=="female"?
      "|F|":"|N|");
  if(display) {
    tmpstr=special_col(ppl[n],display);
    if(!tmpstr) tmpstr="No "+display;
  } else {
    if(environment(ppl[n])) tmpstr=environment(ppl[n])->short();
    else tmpstr="No environment";
  }
  write(" "+tmpstr);
    write(NORM+"\n");
  }  return;
}
