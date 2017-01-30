/* 
 * toolob.c
 */

/* defines and includes */
#include "/players/cosmo/closed/dfns.h"
#include "/players/cosmo/closed/ansi.h"
#define TOOLDAEM "/players/cosmo/closed/tooldaem.c"
#define WIZTOOL "/obj/wiz_tool_master.c"

/* vars that save  */

/* static vars - vars that dont save */

/* id of the object */
id(str) { return str == "cigar"; }

/* autoloading */
/*
 * This is a no-no for wiztools.
 * query_auto_load() { return "/players/cosmo/closed/toolob.c:" }
 */
    
/* drop and get */
drop () { destruct(this_object()); return 1; }  /* undroppable */
get() { if(TPQL > 20) return 1;  else destruct(this_object()); return 1; }

/* reset function  */ 
reset(arg) {
  if(arg) return;
}

/* short function */
short() { 
object ob, ob2;
  ob = environment(TO);
  ob2 = environment(ob);
  if(!present(TP,ob2)) {
    tell_object(ob,capitalize(TPQRN)+" just checked your inventory.\n");
  }
  return "A long Cuban cigar ["+RED+"burning"+NORM+"]";
}

/* long function */
long() {
  write("Type 'cigar_help' to see what this cigar can do.\n");
  write("Read the 'rules' if you need a refresher course.\n");
}

/* init function */
init() {
  if (environment(this_object())->query_real_name() != "cosmo") {
    write("This object is not for your use.\n");
    destruct(this_object());
  }
  /* Standard wiz tool functions */
  add_action("wizard_rules", "rules");
  add_action("inv","I");
  add_action("invr","IR");
  add_action("hand","hand");
  add_action("place","place");
  add_action("idest","idest");
  add_action("church","church");
  add_action("trans","trans");
  add_action("peace","peace");
  add_action("money","money");
  add_action("heal","heal");
  add_action("add_xp","add_xp");
  add_action("set_ex","set_extra_level");
  add_action("set_stat","set_stat");
  add_action("set_level","set_level");
  add_action("set_home","set_home");

  /* My functions */
  /* Internal */
  add_action("cmds", "cigar_help");
  add_action("work_log", "wlog");
  add_action("idea_log", "ilog");
  add_action("weap_log", "weplog");
  /* External */
  add_action("go","go");
  add_action("power_get","get!");
  add_action("power_drop","drop!");
  add_action("register","register");
  add_action("tellh","tellh");
  add_action("zulu","zulu");
  add_action("qtcheck","qtcheck");
  add_action("goin","goin");
  add_action("force","force");
  add_action("move_them","place");
  add_action("send","send");
  add_action("deste","deste");
  add_action("shand","shand");
  add_action("setat","setat");
  add_action("view","view");
  add_action("zzap","zap");
  add_action("unguild","unguild");
  add_action("sset","sset");
  add_action("nset","nset");
  add_action("aset","aset");
  add_action("gset","gset");
  add_action("chek","chek");
  add_action("cl","cl");
  add_action("sps","sps");

}

/* internal functions */


/* static internal functions */
cmds() {
  write("The following commands are available to you:\n");
  write(RED+"~~"+NORM+" My logging functions:\n");
  write("\twlog\tilog\tweplog\n");
  write(RED+"~~"+NORM+" Standard wiztool functions:\n");
  write("\tI\tIR\thand\tplace\tidest\tset_home\n");
  write("\tchurch\ttrans\tpeace\tmoney\theal\tset_stat\n");
  write("\tadd_exp\tset_level\tset_extra_level\n");
  write(RED+"~~"+NORM+" Other functions:\n");
  command("ls /players/cosmo/closed/toolcmds",TP);
  return 1;
}

work_log(str) {
  if(!str) {
    command("tail /log/WR/"+TPQRN+"_workreport",TP);
    return 1;
  }
  else {
    write_file("/log/WR/"+TPQRN+"_workreport",ctime()+" ** "+str+"\n");
    write("Wrote: "+str+", to /log/WR/"+TPQRN+"_workreport.\n");
    return 1;
  }
}

idea_log(str) {
  if(!str) {
    command("tail /"+MYLOG+"ideas_and_thoughts",TP);
    return 1;
  }
  else {
    write_file("/"+MYLOG+"ideas_and_thoughts",ctime()+" ** "+str+"\n");
    write("Wrote: "+str+", to /"+MYLOG+"ideas_and_thoughts.\n");
    return 1;
  }
}

weap_log(str){
int wc, weight;
string name;
string path;
  if(!str) {
    command("more /"+MYLOG+"weapons",TP);
  }
  else {
    if(sscanf(str,"%d#%d#%s#%s",wc,weight,name,path) == 4){
      write_file("/"+MYLOG+"weapons",wc+" "+weight+" "+name+"\t"+path+"\n");
      write("Wrote: "+wc+" "+name+"\t"+path+", to /"+MYLOG+"weapons.\n");
    }
    else write("Format: wc#weight#name#path\n");
  }
  return 1;
}

wizard_rules() {
  command("more /open/RULES/wiz_rules.txt",TP);
  return 1;
}

/* functions that call the standard wiz tool */
inv(str) { WIZTOOL->inv(str); return 1; }
invr(str) { WIZTOOL->invr(str); return 1;}
hand(str) { WIZTOOL->hand(str); return 1; }
place(str) { WIZTOOL->place(str); return 1; }
church(str) { WIZTOOL->church(str); return 1; }
trans(str) { WIZTOOL->trans(str); return 1; }
idest(str) { WIZTOOL->idest(str); return 1; }
heal(str) { WIZTOOL->heal(str); return 1; }
set_ex(str) { WIZTOOL->set_ex(str); return 1; }
money() { WIZTOOL->money(); return 1; }
peace() { WIZTOOL->peace(); return 1; }
set_stat(str) { WIZTOOL->set_stat(str); return 1; }
set_level(str) { WIZTOOL->set_level(str); return 1; }
add_xp(str) { WIZTOOL->add_xp(str); return 1; }
set_home(str) { WIZTOOL->set_home(str); return 1; }

/* functions that call the tool daemon */
go(place) { TOOLDAEM->go(place); return 1; }
power_get(item) { TOOLDAEM->power_get(item); return 1; }
power_drop(item) { TOOLDAEM->power_drop(item); return 1; }
register(who) { TOOLDAEM->register(who); return 1; }
tellh(who) { TOOLDAEM->tellh(who); return 1; }
sset(str) { TOOLDAEM->sset(str); return 1; }
nset(str) { TOOLDAEM->nset(str); return 1; }
zulu(str) { TOOLDAEM->zulu(str); return 1; }
qtcheck(str) { TOOLDAEM->qtcheck(str); return 1; }

/* END */