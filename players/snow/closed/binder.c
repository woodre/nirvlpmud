/* Monster control object */
 
#define TP this_player()
#define TPRN TP->query_real_name()
#define ENV environment
#define TO this_object()
#define PRE present
#define RE return 1
#define CAP capitalize
 
int scanning;
object scanmon;
 
id(str) { return str == "monster control object" ||
                 str == "controlobj" || str == "binder"; }
short() { if(TPRN == "snow") return "Binder"; return "~.~"; }
long() {
  if(TPRN == "snow") { powerlist(); RE; }
  else write("A strange object with mystical powers.\n");
  RE;  }
get() { RE; }
drop() { RE; }
 
init() {
  if(TPRN != "snow" && TP->query_level() < 100) {
    write("This you cannot use.\n"); destruct(TO); RE; }
add_action("monster_attack","mattack");
add_action("monster_scan","mscan");
add_action("monster_compare","mcompare");
add_action("clear_scan","noscan");
       }
       
monster_attack(str) {
    object mon1, mon2;
    string one, two;
  if(!str) notify_fail("Usage: mattack <monster> <other monster>\n");
  if(sscanf(str,"%s %s",one,two) !=2) {
    notify_fail("Usage: mattack <monster> <other monster>\n"); }
  mon1 = PRE(one,ENV(TP));
    if(!mon1) mon1 = find_player(one);
      if(!mon1) mon1 = find_living(one);
  mon2 = PRE(two,ENV(TP));
    if(!mon2) mon2 = find_player(two);
      if(!mon2) mon2 = find_living(two);
  if(!mon1) notify_fail("First monster not present.\n");
  if(!mon2) notify_fail("Second monster not present.\n");
  write("As you wish...\n\n");
  mon1->attack_object(mon2);
  write("\n    So the battle begins...\n");
  RE;                }
  
monster_scan(str) {
    object mon;
  if(!str) {
    if(scanning == 1) {
      write("Monster scanning: OFF\n"); scanning = 0; RE; }
    if(scanmon) {
      write("Scanning resumed.\n"); scanning = 1; scan_scan(); RE; }
  notify_fail("Usage: mscan <monster>\n"); }
 
  mon = PRE(str,ENV(TP));
  if(!mon) mon = find_living(str);
  if(!mon) notify_fail("That monster is not on the mud at this time.\n");
  scanmon = mon;
  scanning = 1;
  write("Scanning begun.\n");
  scan_scan();
  RE;           }
  
scan_scan() {
    string mname, oname;
    int mhp, ohp, mmaxhp, omaxhp, msp, osp, mmaxsp, omaxsp;
    object opp;
  if(!scanmon) RE;
  call_out("scan_scan",1);
  if(scanning != 1) RE;
  mname = scanmon->query_real_name();
  mhp = scanmon->query_hp();
  mmaxhp = scanmon->query_mhp();
  msp = scanmon->query_sp();
  mmaxsp = scanmon->query_msp();
  if(scanmon->query_attack()) {
    opp = scanmon->query_attack();
    oname = opp->query_real_name();
    ohp = opp->query_hp();
    omaxhp = opp->query_mhp();
    osp = opp->query_sp();
    omaxsp = opp->query_msp();
                              }
  tell_object(find_player("snow"), "["+
CAP(mname)+"]"+" < HP: "+mhp+"/"+mmaxhp+" SP: "+msp+"/"+mmaxsp+" >\n");
  if(opp) {
  tell_object(find_player("snow"), "["+
CAP(oname)+"]"+" < HP: "+ohp+"/"+omaxhp+" SP: "+osp+"/"+omaxsp+" >\n");
          }
  RE;       }
  
clear_scan() {
  write("All scanning stopped.\n");
  remove_call_out("scan_scan"); scanning = 0;
  RE;        }
  
monster_compare(str) {
  string mon, other, output, one, two;
  if(!str) {
    if(!TP->query_attack()) 
      notify_fail("Usage: mcompare <mon1> <mon2> OR\n"+
                  "       mcompare <mon1>        OR\n"+
                  "       mcompare -while fighting-\n");
    mon = TP->query_attack()->query_real_name();
    other = TPRN;
    output = mon+" "+other;
    compare_compare(output);
    RE;    }
  if(sscanf(str,"%s %s",one,two) == 2) {
    mon = present(one,ENV(TP))->query_real_name();
      if(!mon) mon = find_living(one)->query_real_name();
    other = PRE(two,ENV(TP))->query_real_name();
      if(!other) other = find_living(two)->query_real_name();
      if(!mon) notify_fail("First monster not found.\n");
      if(!other) notify_fail("Second monster not found.\n");
      output = mon+" "+other;
    compare_compare(output);
    RE;                                }
  mon = PRE(str,ENV(TP))->query_real_name();
  if(!mon) mon = find_living(mon)->query_real_name();
  if(mon) compare_compare(mon);
  if(!mon) notify_fail("There is no "+CAP(str)+" at this time.\n");
  RE;                 }
 
compare_compare(str) {
    object mon, other;
    string mname, oname, one, two;
    int mlev, mhp, mmaxhp, msp, mmaxsp, olev, ohp, omaxhp, osp, omaxsp;
    if(sscanf(str,"%s %s",one,two) == 2) {
      mon = PRE(one,ENV(TP));
      if(!mon) mon = find_living(one);
      other = PRE(two,ENV(TP));
      if(!other) other = find_living(two);
                                          }
    if(!mon) mon = PRE(str,ENV(TP));
      if(!mon) mon = find_living(str);
    mname = mon->query_real_name();                                    
    mlev = mon->query_level();
    mhp = mon->query_hp();
    mmaxhp = mon->query_mhp();
    msp = mon->query_sp();
    mmaxsp = mon->query_msp();
    if(!other) {
      write(
      CAP(mname)+" LEV<"+mlev+"> HP<"+mhp+"/"+mmaxhp+
      "> SP<"+msp+"/"+mmaxsp+">\n"); RE; }
    if(other) {
      oname = other->query_real_name();
      olev = other->query_level();
      ohp = other->query_hp();
      omaxhp = other->query_mhp();
      omaxsp = other->query_msp();
      osp = other->query_sp();
               }
    write("-COMPARING-> "+CAP(mname)+" | "+CAP(oname)+"\n");
    write("-LEVEL->     "+mlev+" | "+olev+"\n"+
          "-HP->        "+mhp+" | "+ohp+"\n"+
          "-MAXHP->     "+mmaxhp+" | "+omaxhp+"\n"+
          "-SP->        "+msp+" | "+osp+"\n"+
          "-MAXSP->     "+mmaxsp+" | "+omaxsp+"\n");
    RE;          }
 
powerlist() {
  write(
"----------------------------------------------------\n"+
"-- mattack <mon1><mon2>   Monster attacks monster --\n"+
"-- mscan <monster>        Reports monster stats   --\n"+
"-- mcompare <mon1><mon2>  Compare monster stats   --\n"+
"-- noscan                 Stop scan reports       --\n"+
"----------------------------------------------------\n");
RE;         }
