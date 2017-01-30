#include "/players/mythos/closed/ansi.h"
#define DEST "/players/mythos/prac/test.c"
#define MEM "players/mythos/closed/AI/now"
#define NUM 1000
string loc;
string mon;
int moo;
string backup_loc;
string backup_mon;
static object base;
static string who;
static object mon2;
static object current;

id(str) { return str == "master_AI" ||
                 str == "master" ||
                 str == "AI"; }

query_prevent_shadow() { return 1; }

drop() { return 1; }
get() { return 0; }

init() { add_action("ref","ref"); }

short() { return BOLD+"Master_AI"+NORM; }

long() { int j; j = 0;
         write(RED+"STATUS: \n"+NORM); 
         write(BLU+"'''''''''''''''''''''''''''\n"+NORM+
               "Current:\t\t\t\tStore:\t\t\t\tBackup:\n"+
               "Mon\t\tLoc\t\tMon\t\tLoc\t\tMon\t\tLoc\n"+
            BLU+"'''''''''''''''''''''''''''''\n\n"+NORM);
         while(j<(NUM - 1)){
            if(mon2[j]) {
            write(mon2[j]); write("\t");
            write(current[j]); }
            if(mon[j]) {
            write(mon[j]+"\t"+loc[j]);
            } else { write("\t"); }
            if(backup_mon[j])) {
            write(backup_mon[j]+"\t"+backup_loc[j]); }
            write("\n");
            j++;
         }}

reset(arg) { if(arg) return;
  move_object(this_object(),DEST);
  base = allocate(NUM);
  who = allocat(NUM);
  mon2 = allocate(NUM);
  current = allocate(NUM);
  if(restore_object(MEM)) {
    call_out("loadup",1);
  } else {
    mon = allocate(NUM);
    loc = allocate(NUM);
    moo = 0;
    backup_loc = allocate(NUM);
    backup_mon = allocate(NUM);
  }
  call_out("tracking",3);
}

setup(string cre,string place) {
int h;
h = find_zero(mon);
mon[h] = cre;
loc[h] = place; 
return 1; }

refer(object x,object y,arg) { 
/* is player, y is from loc */
int h;
if(!arg) {
h = find_zero(base);
if(h == -1) return 0;
who[h] = x->query_real_name();
base[h] = y; }
else {
if(member_array(arg,who) != -1) 
  who[member_array(arg,who)] = 0;
  base[member_array(arg,who)] = 0;
} else return 0;
return 1; }

ref() { 
int h; h = 0;
   write(RED+"Status players:\n"+NORM);
   while(h<sizeof(who)) {
      if(who[h]) {
        write(who[h]+"\t");
        if(strlen(who[h]) < 8) write("\t");
        write(base[h]+"\n");
      }
  h++; }
return 1; }

static find_zero(string what) {
  int j,i;
  j = i = 0;
  while(j<sizeof(what) && !i) {
    if(!base[j]) i = 1;
  j++; }
  if(!i) return -1;
return j-1; }

static loadup() {
  int j,i;
  object gr;
  j = 0;
  if(moo) {
  while(j<sizeof(loc)) {
    i = find_zero(loc);
    if(loc[j] && i != -1) {
       gr = clone_object("/"+mon[j]+".c");
       if(gr){
       move_object(gr,loc[j]);
       if(environment(gr)) { current[i] = environment(gr);
       mon2[i] = gr; } }
    }
  j++; } }
  else {
    while(j<sizeof(backup_loc)) {
    i = find_zero(backup_loc);
    if(backup_loc[j] && i != -1) {
       gr = clone_object("/"+backup_mon[j]+".c");
       if(gr){
       move_object(gr,backup_loc[j]);
       if(environment(gr)) { current[i] = environment(gr);
       mon2[i] = gr; } }
    }
  j++; } }
return 1; }

tracking() {
int j,i,h;
string where,null;
 j = 0;
 i = 0;
 h = 0;
 moo = 0;
 backup_mon = mon;
 backup_loc = loc;
 mon = allocate(NUM);
 loc = allocate(NUM);
  while(j<sizeof(mon2)) {
   i = 0;
    if(mon2[j]) {
       if(environment(mon2[j])) { 
       i = 1; 
       current[j] = environment(mon2[j]); 
       sscanf(mon2[j],"%s#%s",mon[h],null);
       if(sscanf(current[j],"%s#%s",where,null)) {}
       else sscanf(current[j],"%s",where);
       loc[h] = where;}
    if(!i) { mon2[j] = 0;
             current[j] = 0;
           }
   j++; }
   moo = 1;
call_out("tracking",10);
return 1; }
