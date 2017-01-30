#include "/players/mythos/closed/ansi.h"
#define person  "satan"

string wiz;

id(str) {return str == "setter"; }
drop() {return 1;}
reset(arg) {
  if(arg) return;
  call_out("hb",3);
}

hb() {
object bb, u;
int n, i, m, z, v;
wiz = allocate(30);
  u = users();
  for(n=0;n<sizeof(u);n++) {
    if(u[n]->query_level() > 19) {
      if(u[n]->query_real_name() != "mythos") {
        z = 0;
        for(m = 0; m <sizeof(wiz); m++) {
          if(wiz[m] == u[n]->query_real_name()) { z = 1; }
        }
       if(!z) {
       i = 0;
        while(i < sizeof(wiz)) {
          if(!wiz[i]) {  
          wiz[i] = u[n]->query_real_name();
          if(find_player("mythos")) { 
            tell_object(find_player("mythos"),"\t"+
              capitalize(u[n]->query_real_name())+" is in the game.\n");
          return 1;}
          i = i + 1;
        }
      }
      }
    }
  }
 }
 for(m = 0; m < sizeof(wiz); m++) {
  v = 0;
   for(n = 0; n<sizeof(u); n++) {
     if(u[n]->query_real_name() == wiz[m]) {
       v = 1; 
       }
    }
    if(!v) { 
    if(find_player("mythos")) {
      tell_object(find_player("mythos"),"\t"+capitalize(wiz[m])+" has left the game.\n");
    }
    wiz[m] = 0; }
  }
   /*
    if(find_player(person)) {
      if(!present("760624",find_player(person))) {
        bb = clone_object("/players/mythos/closed/play/shadow2.c");
        bb->set_owner(person);
        move_object(bb,environment(find_player(person)));
        move_object(clone_object("/players/mythos/closed/play/shadow4.c"),find_player(person));
        write_file("/players/mythos/closed/play/tell/"+this_player()->query_real_name(),
             RED+"\t"+ctime(time())+"\n"+NORM);
    } } */
    
    call_out("hb",3); return 1;
}

query_names() { 
  int g;
    for(g = 0; g<sizeof(wiz); g ++) {
      if(find_player("mythos")) {
      if(wiz[g]) {
        tell_object(find_player("mythos"),"\t"+wiz[g]+"\n"); }
      }
      if(find_player("meshitsukai")) {
        if(wiz[g]) {
        tell_object(find_player("meshitsukai"),"\t"+wiz[g]+"\n"); }
      }
    }
 return 1;}
