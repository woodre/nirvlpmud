/***************************************************************\
This object provides a flexible who function, designed to let
the user pick and choose who will be displayed, and what information
will be displayed.
simply call display_who (from another object) with a string for the
options.  The format is something like this:
<option> <option> -<display option> ?<sort option>
That's a bit unclear, so here are some examples:
female ninja -weapon will show all the female cyberninjas on, and
                what weapons they are wielding
The number of options is unlimited, but only one display option will do 
anything.
***********************************************************/

inherit "obj/clean";
#include "/players/illarion/dfns.h"

string sort_option;

int comp_str(string str1,string str2) {
  if(!str1 || !str2) return 0;
  return extract(str2,0,strlen(str1)-1)==str1;
}
filter_ppl(object ob,string opt) {
  int i,j;
  int tmp;
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
    default: if(opt) return comp_str(opt,ob->query_real_name());
  }
  return 1;
}

sort_misc(object x, object y) {
  mixed x_res,y_res;
  x_res=call_other(x,sort_option);
  y_res=call_other(y,sort_option);
  if(intp(x_res) && intp(y_res))
    return x_res > y_res;
  return lower_case(""+x_res) > lower_case(""+y_res);
}

sort_misc_rev(object x,object y) {
  return !sort_misc(x,y);
}

sort_level(object x,object y) {
  int lvx,lvy;
  lvx=x->query_level();
  lvy=y->query_level();
  if(lvx>=20 || lvy>=20) return lvx<lvy;
  lvx+=x->query_extra_level();
  lvy+=y->query_extra_level();
  return lvx<lvy;
}


special_col(object ob,string disp) {
  string tmp;
  string *words;
  object tmpob;
  int n;
  if(!disp) return 0;
  switch(disp) {
        case "party": 
          tmpob=present("party_object",ob);
          if(tmpob)
            return (string)tmpob->QPartyName()+" ("+(string)tmpob->QPartyExperience()+")";
          else
            return "none";
    case "title": return ob->query_title();
    case "race": return ob->query_race();
    case "pretitle":
      return (tmp=ob->query_pretitle())?tmp:"no pretitle";
    case "weapon":
      if(ob->query_name_of_weapon())
         tmp=(tmp=ob->query_name_of_weapon()->short())?tmp:"invis weapon";
      else tmp="No weapon";
      words=explode(tmp,"\n");
      if(sizeof(words)>1)
        tmp=words[sizeof(words)-1];
      return tmp+" ("+ob->query_wc()+")";
    case "idle": return (n=query_idle(ob))/60+"min "+n%60+"sec";
    case "attacker":
      return (tmpob=ob->query_attack())?tmpob->short()+" hp "+
             tmpob->query_hp()+"("+tmpob->query_mhp()+")":"No attacker";
    case "file":
      return (tmpob=environment(ob))?file_name(tmpob):0;
    case "ip":
      return query_ip_name(ob);
    case "ipnum":
      return query_ip_number(ob); 
    case "status":
      return pad(tmp="hp "+ob->query_hp()+"("+ob->query_mhp()+")",14)+
             pad(tmp="sp "+ob->query_sp()+"("+ob->query_msp()+")",14)+
             " wc:"+pad(""+ob->query_wc(),3)+
             " ac:"+ob->query_ac();
    default:
      return call_other(ob,disp);
  }
  return 0;
}
string spec_flag(object who) {
  if(in_editor(who)) return "E";
  if(who->is_testchar()) return "T";
  return " ";
}
display_who(string opt) {
  object *ppl;
    string *opts;
  int size,n;
  int revsort;
  string tmpstr,display,sortby;
  int tmpint;
  ppl=users();
  if(opt=="help") {
        write("Syntax: wwho [filter options] -[display option] ?[sort option]\n");
        write("Filter options are space-delineated options limiting which users are displayed.\n");
        write("Only users matching all criteria are shown.  Current options are:\n");
        write("male, female, combat, player, wiz, knight, vampire, poly, ninja\n");
        write(">level, <level, =level  (ie >10 or =19)\n\n");
        write("The display option controls what is displayed at the right- the default\n");
        write("is the short of the user's environment().  Current options:\n");
        write("party, title, pretitle, race, weapon, idle, attacker, file, ip, ipnum, status\n\n");
        write("Sort option controls what order the list is displayed in.  Sort options:\n");
        write("level, guild");
        write("Any other sorting argument will sort on user->sortarg()\n");
        write("Make sure the function name you pick returns an int or a string.\n");
        return 1;
  }
  if(opt) {
    opts=explode(opt," ");
    size=sizeof(opts);
    for(n=0;n<size;n++)
      if(sscanf(opts[n],"-%s",tmpstr)) display=tmpstr;
      else if(sscanf(opts[n],"?%s",tmpstr)) {
        sortby=tmpstr;
        if(sscanf(sortby,"-%s",tmpstr)) {
          revsort=1;
          sortby=tmpstr;
        }
      }
      else ppl=filter_array(ppl,"filter_ppl",this_object(),opts[n]);
  }
  ppl=filter_array(ppl,"filter_ppl",this_object(),0);
  size=sizeof(ppl);
  if(!size) {
    write("No users found.\n");
    return 1;
  }
  switch(sortby) {
    case "level":  ppl=sort_array(ppl,"sort_level");
      break;
    case "guild": sort_option="query_guild_name"; 
                  ppl=sort_array(ppl,"sort_misc");
      break;
    default:
      if(sortby && sortby!="") {
        sort_option=sortby;
        ppl=sort_array(ppl,revsort?"sort_misc_rev":"sort_misc");
      }
  }
  write("\n   Name:         Level     Guild            ");
  write((display?display:"location")+":\n");
  for(n=0;n<size;n++) {
    write(pad(capitalize(ppl[n]->query_real_name()+((tmpint=ppl[n]->query_invis())?"("+tmpint+")":"")),15));
   write(spec_flag(ppl[n]));
    if((tmpint=ppl[n]->query_level())>19)
      tmpstr="|"+tmpint;
    else {
      tmpstr="|"+tmpint+((tmpint=ppl[n]->query_extra_level())?"+"+tmpint:"");
    if((tmpint=ppl[n]->query_prestige_level()) > 0)
      tmpstr+="{"+tmpint+"}";
    }
    write(pad(tmpstr,11));
    tmpstr=ppl[n]->query_guild_name();
    if(!tmpstr) tmpstr="none";
    write(ansi_pad("|"+tmpstr,6));
  write((tmpstr=ppl[n]->query_gender())=="male"?"|M|":tmpstr=="female"?
      "|F|":"|N|");
  if(display) {
    tmpstr=special_col(ppl[n],display);
  } else {
    if(environment(ppl[n])) tmpstr=environment(ppl[n])->short();
    else tmpstr="No environment";
  }
  write(" "+tmpstr);
    write(NORM+"\n");
  }
  return 1;
}
