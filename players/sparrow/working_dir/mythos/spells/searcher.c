#include "/players/mythos/closed/guild/def.h"
id(str) {return str == "searcher" || str == "messenger";}
string own, dir_dest;
int j, g, i, h;
object fio;

set_own(str) { own = str; fio = find_player(own);}
query_own() { return own;}

get() { return 0;}

reset(arg) {
  if(arg) return;
  enable_commands();
  call_out("shs",3);
}

seea() {
object ob;
ob = environment(this_object());
  tell_object(fio,BOLD+"SEARCH\n"+NORM+ob->long());
  if(ob->realm() && ob->realm() == "NT") { 
  tell_object(fio,HIR+"\nNo-Teleport\n"+NORM); }
  ob = first_inventory(ob);
  while(ob) {
    if (ob != this_object()) {
      string short_str;
      short_str = call_other(ob, "short");
      if (short_str)
	tell_object(fio,short_str + ".\n");
    }
    ob = next_inventory(ob);
  }
return 1;}

sees(str) {
object targ;
targ = present(str,ep);
  if(!targ) { 
    tell_object (fio,capitalize(str)+" is not in the room you wish to know.\n"); 
  return 1;}
  tell_object(fio,BOLD+"SEARCH\n"+NORM+targ->long());
return 1;}

assess(str) {
object ob;
ob = present(str,ep);
  if(!ob) { 
    tell_object (fio,capitalize(str)+" is not in the room you wish to know.\n"); 
  return 1;} 
  if(!living(ob)) { write("You can not assess the non-living!\n"); return 1;}
  if(present("misknow",ob)) { 
  tell_object(fio,present("misknow",ob)->set_up()); } 
  else {
  tell_object(fio,"\n~");
  tell_object(fio,"\n~ Short: "+ob->short()+"\n");
    tell_object(fio,"~ Level: "+ob->query_level()+"\n");
    tell_object(fio,"~ Race: "+ob->query_race()+"    \n");
    j = 100*(ob->query_hp())/(ob->query_mhp());
    i = ob->query_mhp();
    if(j > 89) { g = "Excellent";}
    if(j < 90 && j > 74) { g = "Sound";}
    if(j < 75 && j > 49) { g = "Okay";}
    if(j < 50 && j > 24) { g = "Not Good"; }
    if(j > 9 && j < 25) { g = "Bad";}
    if(j < 10) { g = "Dire"; }
    if(i > 1000) { h = "Godlike <1000~>";}
    if(i < 1001 && i > 800) { h = "Supernatural <800~1000>";}
    if(i < 801 && i > 600) { h = "Powerful <600~800>";}
    if(i < 601 && i > 400) { h = "Strong <400~600>";}
    if(i < 401 && i > 200) { h = "Above <200~400>";}
    if(i < 201 && i > 99) { h = "Average <100~200>";}
    if(i < 100) { h = "Low <~100>";}
    tell_object(fio,"~ Health [Phys]: "+g+"   Range [Max]: "+h+"\n");
    tell_object(fio,"~ Where: "+environment(ob)->short()+"  Create: "+
          creator(environment(ob))+"\n");
    tell_object(fio,"~");
    if( environment(ob)->realm() && environment(ob)->realm() == "NT") {
    tell_object(fio,"   No-Teleport   \n~"); }
    j = ob->query_wc();
    i = ob->query_ac();
    if(j > 45) { g = "Godlike";}
    if(j > 35 && j < 46) { g = "Supernatural";}
    if(j > 29 && j < 36) { g = "Extremely Dangerous";}
    if(j > 25 && j < 30) { g = "Powerful";}
    if(j < 26 && j > 19) { g = "Strong";}
    if(j < 20 && j > 14) { g = "Okay";}
    if(j < 15 && j > 10) { g = "Mild"; }
    if(j < 11) { g = "Not";}
    if(i > 20) { h = "Godlike";  }
    if(i > 16 && i < 21) { h = "Extremely Tough";}
    if(i < 17 && i > 12) { h = "Tough";}
    if(i < 13 && i > 4) { h = "Mild";}
    if(i < 5) { h = "Not";}
    tell_object(fio," Offense: "+g+"   Defense: "+h+"\n");
    if(ob->query_weapon()) { tell_object(fio,"~ Wielding: "+(ob->query_weapon())->short()+"\n"); }
    tell_object(fio,"\n"); }
return 1;}

off() {
  tell_object(fio,"The knowing vanishes!\n");
  destruct(this_object());
return 1;}

shs() {
  if(!fio) { destruct(this_object()); return 1;}
call_out("shs",3);
return 1;}

query_shatter_proof() { return 1;} 
