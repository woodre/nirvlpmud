#include "/players/mythos/closed/guild/def.h"
int extell;

query_auto_load() {
    return "/players/mythos/closed/guild/gob.c:"; }

id(str) {return str == "dgc" || str == "clasp"; }

short() { return "A small silver clasp";}

reset(arg) {
  if(arg) return 1;
  extell = 1;
}

extra_look() {
string atmos;
  if(epn == "mythos") { atmos = "An Aura of "+BOLD+"POWER"+NORM+" surrounds the Prophet"; }
  else { atmos = "An Aura of "+HIR+"Blood"+NORM+" surrounds the Guild Commander"; }
  return atmos;
  }
  
long() {
  write("This clasp is for GCs only.  Use the powers carfully.\n"+
        "Type ghelp for more.\n");
  if(epn == "mythos") {
    write("And mhelp.\n");
  }
}

drop() {return 1;}
get() {return 0;}

init() {
  add_action("ghelp","ghelp");  
  add_action("mhelp","mhelp"); 
  add_action("xtell_toggle","xtoggle");
  add_action("giver","giver");
  add_action("change_title","change_title");
  if(epn=="mythos") {
  add_action("dset","dset");
  add_action("dquery","dquery");
  }
}

ghelp() {
  write("The powers of a GC are as follows:\n"+
        "  xtoggle   toggles the information given to you through => \n"+
        "  giver     gives the player indicated thir empowered weapon back\n"+
      "");
return 1;}

change_title(str) {
  pp->set_dark_title(str);
return 1;}

xtell_toggle() {
  extell = !extell;
  if(extell == 0) {
  write("Extra tell is off.\n");
  return 1;}
  write("Extra tell is on.\n");
return 1;}
query_xtell() {return extell;}
  
giver(str) {
object blade;  
  if(!str) { write("Usage: giver <name>\n"); return 1;}
   if(!find_player(str)) { write("That person is not on the mud.\n"); return 1;}
   if(!read_file("/players/mythos/closed/guild/room/backup/"+str+".o")) {
     write("That person does not have an empowered weapon on backup.\n");
   return 1;}
   blade = clone_object("/players/mythos/closed/guild/spells/dwep.c");
   blade->restore_thing("players/mythos/closed/guild/room/backup/"+str);
   move_object(blade,environment(find_player(str)));
   write_file("/players/mythos/closed/guild/GIVE",ctime(time())+"  "+tpn+
           " gave "+str+" back weapon.\n");
   tell_object(find_player(str),"You feel a tapping in your soul...\n");
   command("look",find_player(str));
   write("You have given "+capitalize(str)+" back the empowered weapon.\n"+
         "Action done and logged.\n");
return 1; }
   
mhelp() {
write("Commands for Prophet:\n"+
      "dset  dquery  \n");
return 1;}

dset(str) {
string who, what;
int num;
object ob;
if(!str) { write("Usage: dset <who> <what> <num>\n"); 
write("settables:\n"+
      "fae  talent   sacrifice  dark_level  defence  dates  tides\nSpells:\n");
write("sim  ward  c_area  shatter  bow  image  curse  ban  send\n"+
      "pow  tsoul  hunts  pact1  pact2  devil  dblade  dring  rev\n"+
      "help sif\n");
      return 1;}
sscanf(str,"%s %s %d",who,what,num);
if(!find_player(who)) { write("Not here.\n"); return 1;}
if(!present(fear,find_player(who))) { write("No object.\n"); return 1;}
ob= present(fear,find_player(who));
if(what == "all") {
  ob->set_talent(num); ob->set_sim(num); ob->set_ward(num);
  ob->set_c_area(num); ob->set_shatter(num); ob->set_bow(num);
  ob->set_image(num); ob->set_curse(num); ob->set_ban(num);
  ob->set_send(num); ob->set_pow(num); ob->set_tsoul(num);
  ob->set_hunts(num); ob->set_pact1(num); ob->set_pact2(num);
  ob->set_devil(num); ob->set_dblade(num); ob->set_dring(num);
  ob->set_rev(num); ob->set_help(num);  ob->set_sif(num);
  write(who+" all "+num+"\n"); return 1;}
call_other(ob,"set_"+what,num);
write(who+" "+what+" "+num+"\n");
return 1;}

dquery(str) {
string who, what;
int num;
object ob;
if(!str) { write("Usage: dquery <who> <what>\n"); 
write("queriables:\n"+
      "  dark_title, sacrifice, dates, md\n"+
      "  defence, tides, talent, fae, help\n");
      return 1;}
sscanf(str,"%s %s",who,what);
if(!find_player(who)) { write("Not here.\n"); return 1;}
if(!present(fear,find_player(who))) { write("No object.\n"); return 1;}
ob= present(fear,find_player(who));
write(who+" "+what+" "+call_other(ob,"query_"+what,0)+"\n");
return 1;}
