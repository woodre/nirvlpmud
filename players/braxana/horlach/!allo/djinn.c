#include "/players/mythos/closed/ansi.h"
#define tp this_player()
#define eo environment(this_object())
#define tpn tp->query_real_name()
#define EM find_player(master)
string master;
int h;
string nameset;
inherit "players/mythos/dmon/mon";



reset(arg) {
  ::reset(arg;
  if(arg) return;
  if(h != 1) h = 0;
  set_name("djinn");
  set_alias("servant");
  set_race("spirit");
  set_short(CYN+"Djinn of the Desert Winds"+NORM);
  set_long("");
  set_level();
  set_wc();
  set_ac();
  set_hp();
}

set_nameset(str) { nameset = str; }

query_nameset() { return nameset; }

monster_died() {
  if(EM) {
    tell_object(EM,query_nameset()+" dies!\n");
    EM->zap_object(EM);
    EM->zap_object(EM);
  }
vanish();
return 1; }

set_master(str) { if(!h) master = str; }

master_check() { if(tp == EM) return 1; return 0; }

view(str) {
object ob,ob2;
int j;
  if(!master_check()) return 0;
  if(!str) {
    write(eo->short()+"\n");
    eo->long();
    ob = all_inventory(eo);
    for(j=0;j<sizeof(ob);j++) {
     if(ob[j] != this_object() && !ob[j]->query_invis() &&
        ob[j]->short()) write(ob[j]->short()+"\n");
    }
  return 1; }
  ob = present(str,this_object());
  if(!ob) ob = present(str,eo);
  if(ob->query_invis() || !ob) {
   write("Not here.\n"); return 1; }
  write(ob->short()+"\n");
  ob->long();
  ob2 = all_inventory(ob);
  for(j=0;j<sizeof(ob2);j++) {
    if(ob2[j]->short()) write(ob2[j]->short()+"\n");
  }
return 1; }

sic(str) {
object ob; 
if(!master_check()) return 0;
ob = present(str,eo);
if(!living(ob)) { write("NOt alive.\n"); return 1; }
if(ob == query_attack()) { write("Already attacking.\n");
   return 1; }
if(ob->is_player() && !present("kah",ob)) {
   write("You may not provoke an attack on a player\n"+
        "outside of the realm of the Desert.\n");
  return 1; }
attack_object(ob);
return 1; }

push(str) {
  if(!master_check()) return 0;
  command(str,this_object());
return 1; }

catch_tell(str) {
  if(str) {
   if(EM) {
     tell_object(EM,str);
     EM->add_spell_point(-1);
   }
   else vanish();
  }
}

vanish() {
  if(environment(this_object()))     
     tell_room(environment(this_object()),
    "The Djinn vanishes..\n");
  if(EM) tell_object(EM,
 "The Djinn fades back into its plane of existance.\n");
  destuct(this_object());
return 1; }
