#include "/players/mythos/closed/play/m.h"
#define MAXSTAT 30
#define PLAYLEV 0
#define WIZLEV 20

id(str) { return str == "aller"; }
long() { write("To use: checks [type]\n"); 
         write("Other commands: II, groups, greps\n");}

drop() { return 1; }
query_prevent_shadow() { return 1; } 

init() {
  if(this_player()->query_real_name() != "arrina" && 
     this_player()->query_real_name() != "mythos" &&
        this_player()->query_real_name() != "daranath" &&
      this_player()->query_real_name() != "priest" &&
     this_player()->query_real_name() != "braxana") {
  destruct(this_object());
return 1;}
add_action("checks","checks");
add_action("checkt","checkt");
add_action("groups","groups");
add_action("checkall","checkall");
add_action("checkp","checkpwd");
add_action("greps","greps");
add_action("exgrep","exgrep");
add_action("II","II");
}

checks(arg) {
object ob;
int h;

ob = users();

for(h=0;h<sizeof(ob);h++) {
    write(ob[h]->query_real_name()+"  "+arg+"  ");
    write(call_other(ob[h],arg));
    write("\n");
}
write("done\n");
return 1;}

checkp() {
int h;
object ob;
ob = users();
for(h=0;h<sizeof(ob);h++) {
  if(ob[h]->query_level() > 19) write(ob[h]->query_real_name()+"  PWD: "+ob[h]->query_pwd()+"\n");
}
write("done pwd\n");
return 1; }

checkall(arg) {
object all;
int l;
  all = users();
  for(l=0;l<sizeof(all);l++) {
    if(environment(all[l]) && all[l]->query_level() < PLAYLEV) {
    if(all[l]->query_attrib("sta") > MAXSTAT) 
      write(all[l]->query_real_name()+" sta: "+all[l]->query_attrib("sta")+
      "  guild: "+all[l]->query_guild_name()+"\n");
    if(all[l]->query_attrib("str") > MAXSTAT) 
      write(all[l]->query_real_name()+" str: "+all[l]->query_attrib("str")+
      "  guild: "+all[l]->query_guild_name()+"\n");
    if(all[l]->query_attrib("mag") > MAXSTAT) 
      write(all[l]->query_real_name()+" mag: "+all[l]->query_attrib("mag")+
      "  guild: "+all[l]->query_guild_name()+"\n");
    if(all[l]->query_attrib("pie") > MAXSTAT) 
      write(all[l]->query_real_name()+" pie: "+all[l]->query_attrib("pie")+
      "  guild: "+all[l]->query_guild_name()+"\n");
    if(all[l]->query_attrib("ste") > MAXSTAT) {
      write(all[l]->query_real_name()+" ste: "+all[l]->query_attrib("ste")+
      "  guild: "+all[l]->query_guild_name());
      if(present("meow_obj",all[l])) write("  FELINE");
      write("\n");
      }
    if(all[l]->query_attrib("int") > MAXSTAT) 
      write(all[l]->query_real_name()+" int: "+all[l]->query_attrib("int")+
      "  guild: "+all[l]->query_guild_name()+"\n");
    if(all[l]->query_attrib("luc") > MAXSTAT) 
      write(all[l]->query_real_name()+" luc: "+all[l]->query_attrib("luc")+
      "  guild: "+all[l]->query_guild_name()+"\n");
    if(all[l]->query_attrib("wil") > MAXSTAT) 
      write(all[l]->query_real_name()+" wil: "+all[l]->query_attrib("wil")+
      "  guild: "+all[l]->query_guild_name()+"\n");
    if(all[l]->query_sp() > all[l]->query_msp()) 
      write(all[l]->query_real_name()+" sp: "+
         all[l]->query_sp()+"/"+all[l]->query_msp()+"\n");
    if(all[l]->query_hp() > all[l]->query_mhp()) 
      write(all[l]->query_real_name()+" hp: "+
         all[l]->query_hp()+"/"+all[l]->query_mhp()+"\n");
    if(all[l]->query_wc() > 18) 
      write(all[l]->query_real_name()+" wc: "+all[l]->query_wc()+"\n");
    if(all[l]->query_alignment() >  1000 || all[l]->query_alignment() < -1000) 
      write(all[l]->query_real_name()+" align: "+all[l]->query_alignment()+"\n");
    if(all[l]->query_weight() < 1) 
      write(all[l]->query_real_name()+" weight: "+all[l]->query_weight()+"\n");
    if(all[l]->query_money() > 80000 || all[l]->query_money() < 0) 
      write(all[l]->query_real_name()+" money: "+all[l]->query_money()+"\n");
 } else
    if(environment(all[l]) && all[l]->query_level() > WIZLEV-1) {
     if(!arg) {
  if(in_editor(all[l])) write("~");
   if(all[l]->query_invis()) write("*");
   write("* "+all[l]->query_real_name()+"  ["+all[l]->query_level()+"]  curr_pwd: "+all[l]->query_pwd()+"\n"); } 
 }
}
  write("done\n");
return 1; }


checkt(arg) {
object ob; 
string arg1,arg2;
int h; 
if(!arg) { return 0; }
if(sscanf(arg,"%s %s",arg1,arg2) != 2) return 0;
ob = users();
for(h=0;h<sizeof(ob);h++) {
  write(ob[h]->query_real_name()+"  "+arg+"  ");
   write(call_other(ob[h],arg1,arg2));
    write("\n");
}
write("done\n");
return 1;}

II(str) {
object ob;
int h;
  if(!str) return 0;
if(!find_player(str)) { write("not in.\n"); return 1;}
ob = all_inventory(find_player(str));
  write("In "+str+" inventory: \n");
for(h=0;h<sizeof(ob);h++) {
if(str != "mythos" || !ob[h]->id(gemmer)) {
  write(ob[h]);
  write("\n"); }
}
write("done\n");
return 1; }

groups(str) {
object ob;
int h,i;
ob = users();
if(!str) str = 0;
h = 0;
write("~~~~~~~~~~~~~~~~~~~~~~~~~  "+str+"  ~~~~~~~~~~~~~~~~~~~~~~~~~\n");
write("Name\t\tLevel\tHP/MHP\tSP/MSP\tAC\tWEAPON\n\n");
for(i=0;i<sizeof(ob);i++) {
  if(ob[i]->query_guild_name() == str) {
  write(ob[i]->query_real_name());
  if(strlen(ob[i]->query_real_name()) < 8) write("\t");
  write("\t"+ob[i]->query_level()+"\t"+ob[i]->query_hp()+"/"+ob[i]->query_mhp());
  write("\t"+ob[i]->query_sp()+"/"+ob[i]->query_msp());
  write("\t"+ob[i]->query_ac());
  if(ob[i]->query_weapon()) write("\t"+(ob[i]->query_weapon())->short()+"\n");
  else write("\tWC"+ob[i]->query_wc()+"\n");
  h = h + 1; 
} }
write("\n");
write("There are "+h+" out of "+(sizeof(ob))+" people are members\n");
write("~~~~~~~~~~~~~~~~~~~~~~~~~  "+str+"  ~~~~~~~~~~~~~~~~~~~~~~~~~\n");
return 1; }

greps(str) {
object ob;
int h,i;
ob = users();
if(!str) return 0;
h = 0;
write("~~~~~~~~~~~~~~~~~~~~~~~~~  "+str+"  ~~~~~~~~~~~~~~~~~~~~~~~~~\n");
write("Name\t\tLevel\tHP/MHP\tSP/MSP\tWC\tAC\n\n");
for(i=0;i<sizeof(ob);i++) {
  if(present(str,ob[i])) {
  write(ob[i]->query_real_name());
  if(strlen(ob[i]->query_real_name()) < 8) write("\t");
  write("\t"+ob[i]->query_level()+"\t"+ob[i]->query_hp()+"/"+ob[i]->query_mhp());
  write("\t"+ob[i]->query_sp()+"/"+ob[i]->query_msp());
  write("\t"+ob[i]->query_wc()+"\t"+ob[i]->query_ac()+"\n");
  h = h + 1; 
} }
write("\n");
write("There are "+h+" out of "+(sizeof(ob))+" people who have the item.\n");
write("~~~~~~~~~~~~~~~~~~~~~~~~~  "+str+"  ~~~~~~~~~~~~~~~~~~~~~~~~~\n");
return 1; } 

exgrep(str) {
object wo,mo;
int h,i;
   if(!str) { write("exgrep <obj>\n"); return 1; }
wo = users();
write("-------------EXGREP    ITEM: "+str+" --------------------\n");
for(h=0;h<sizeof(wo);h++) {
  if(environment(wo[h]))
   if(present(str,environment(wo[h])))
    {
     write(wo[h]->query_real_name()+"    ");
    write(environment(wo[h]));
   write("\n");
}
}
write("-------------------------EXGREP-------------------------\n");
return 1; }
