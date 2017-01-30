#ifndef forbinlogging
#ifndef forbindefine
/* 
//  This file controls logging in my realm.
//  To stop logging for a specific thing, simply comment out the
//  given logfile define delow and logging will stop.
*/

#define LOGDIR "/players/forbin/logs/"

#define log_it(x,y) write_file(x, ctime()[4..15]+" "+ctime()[20..23]+" "+y+"\n");
/*
#define log_this(file, what) { string who, lev, xlev; if(this_player()) { who = (string)this_player()->query_real_name(); lev = (int)this_player()->query_level(); xlev = (int)this_player()->query_extra_level(); } else { who = "Unknown"; lev = "?"; xlev = "?"; }     write_file(file, ctime()[4..15]+" "+ctime()[20..23]+" "+((lev < 20 || lev == "?") ? pad(capitalize(who), 12)+" "+pad("("+lev+"+"+xlev+")", 8) : pad(capitalize(who), 12)+" "+pad("("+lev+")", 8))+" "+(string)what+"\n"); }
#define mon_log(file) { string fname, fnum, who, lev, xlev; if(this_player()) { who = (string)this_player()->query_real_name(); lev = (int)this_player()->query_level(); xlev = (int)this_player()->query_extra_level(); } else if(attacker_ob) { who = (string)attacker_ob->query_name(); lev = (int)attacker_ob->query_level(); xlev = (int)attacker_ob->query_extra_level(); } else { who = "Unknown"; lev = "?"; xlev = "?"; } if(sscanf((string)file_name(this_object()), "%s#%s", fname, fnum) < 2) fname = (string)file_name(this_object()); write_file(file, ctime()[4..15]+" "+ctime()[20..23]+" "+((lev < 20 || lev == "?") ? pad(capitalize(who), 18)+" "+pad("("+lev+"+"+xlev+")", 8)+" "+pad("killed:",7) : pad(capitalize(who), 18)+" "+pad("("+lev+")", 8)+" "+pad("killed:",7))+" "+(string)this_object()->query_name()+" ["+fname+"]\n"); }
*/

#define mon_log(f) write("")
#define log_this(f,x) write("")
#define ENTERLOG "/players/forbin/logs/enter.log"
#define CRYSTALSLOG "/players/forbin/logs/crystals.log"
#define KILLLOG "/players/forbin/logs/kill.log"
#define BIGKILLLOG "/players/forbin/logs/bigkill.log"
#define HEALSLOG "/players/forbin/logs/heals.log"
#define TIPSLOG "/players/forbin/logs/tips.log"
#define DEBUGLOG "/players/forbin/logs/debug.log"
#define RUINSLOG "/players/forbin/logs/ruins.log"
#define SALLOG "/players/forbin/logs/sal.log"

/* Debugging command for monsters */
#define mdmsg(x) { if(find_player("forbin")) tell_object(find_player("forbin"), HIW+"["+HIR+"debug"+HIW+"] "+NORM+upper_case(this_object()->query_name())+" "+HIR+":: "+NORM+x+"\n"); log_file("forbin."+lower_case(delete_spaces(this_object()->query_name()))+".debug", "[debug] "+upper_case(this_object()->query_name())+" :: "+x+"\n"); } 

/* Debugging command */
#define dmsg(file, x) { if(find_player("forbin")) tell_object(find_player("forbin"), HIW+"["+HIR+"debug"+HIW+"] "+NORM+x+"\n"); log_file("forbin."+file+".debug", "[debug] "+upper_case(file)+" :: "+x+"\n"); } 
#define forbinlogging BLAH
#endif
#endif
