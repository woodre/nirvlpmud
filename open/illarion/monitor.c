/* 
 * Code intended for use as a configurable hit point/spell point monitor
 * It allows the calling object to determine the look of the monitor,
 * and even to set up calls to another object, for the display of guild
 * stats.
 * The way it's set up now, it just adds to the current monitor code
 * Basically, a guild or other object would call set_monitor during its
 * initialization.  the second argument is the alternate object that
 * the monitor would call for extra info.  The first argument is the
 * monitor that will be displayed to the player.
 * The string is displayed as is, except for pieces in the following
 * form : ^^hp^^  (see below for the full list)
 * or, if the option is to be called from the monitor_object, it
 * the syntax is: ^^->function^^
 * So, a monitor string of "<< HP: ^^hp^^ SP: ^^sp^^ GP: ^^->query_guild^^"
 * would display something like:
 * << HP: 100 SP: 45 GP: 10 >>
 *
 * The main problem I can see with it is the eval cost of lots of sscanfs
 * every heartbeat in battle.  I don't know how much the eval cost is,
 * but I assume it's not negligable.  I'm sure something better could
 * be found, perhaps an explode(mstring,"^^") or something similar
 */
 
 
static string monitor_string;
static object monitor_object;

set_monitor(string str,object ob) {
  monitor_object=ob;
  monitor_string=str;
}
get_replace(string fun) {
  switch(fun) {
    case "hp":    return hit_point+"";
    case "mhp":   return max_hp+"";
    case "sp":    return spell_points+"";
    case "msp":   return max_spell+"";
    case "intox": return intoxicated*100/(level+3)+"%";
    case "soak":  return soaked*100/(level*8)+"%";
    case "stuf":  return stuffed*100/(level*8)+"%";
    case "inf":   return infuse*100/(INFUSE_LIMIT)+"%";
    default: return 0;
  }
}
get_other(string fun) {
  if(!sscanf(fun,"->%s",fun)) return 0;
  return call_other(monitor_object,fun)+"";
}
monitor(str) {
     if(str=="on") {mon = 0;
       write("Monitor on.\n");
     }
     if(str=="off") {mon = 1;
       write("Monitor off.\n");
     }
     if(str=="ansi") {
       mon = 2;
       write("ANSI Monitor on.\n");
     }
     if(monitor_string && monitor_object) {
       string mstring,beg,end,fun,replace;
       mstring=monitor_string;
       while(sscanf(mstring,"%s^^%s^^%s",beg,fun,end")>=2) {
         replace=get_replace(fun);
         if(!replace) replace=get_other(fun);
         mstring=(beg?beg:"")+(replace?replace:"")+(end?end:"");
       }
       tell_object(this_object(),mstring+"\n");
       return 1;
     }
     if(mon < 2)
      tell_object(this_object(),"<<<<  HP "+hit_point+"/"+max_hp+" SP "+
            spell_points+"/"+max_spell+" I "+
            intoxicated*100/(level+3)+"% F "+stuffed*100/(level*8)+"% "+
              "S "+soaked*100/(level*8)+"%"+
            " T "+infuse*100/(INFUSE_LIMIT)+"%"+
            "  >>>>"+
            "\n");
     else
      tell_object(this_object(),esc+"[0m"+esc+"[0m"+esc+"[31m<<<<  HP "+hit_point+"/"+max_hp+" SP "+
            spell_points+"/"+max_spell+" I "+
            intoxicated*100/(level+3)+"% F "+stuffed*100/(level*8)+"% "+
            "S "+soaked*100/(level*8)+"%"+
            " T "+infuse*100/(INFUSE_LIMIT)+"%"+
            "  >>>>"+esc+"[0m"+
            "\n");
        return 1;
}
