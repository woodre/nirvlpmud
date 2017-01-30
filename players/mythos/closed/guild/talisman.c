#include "/players/mythos/closed/guild/def.h"

id(str) { return str == "talisman" || str == "blood"; }

short() { return HIR+"Pool of Blood"+NORM; }

long() {
  write("");
}

reset(arg) {
  if(arg) return;
}

init() {
  if(tp->id("dread") && !present("dread",this_object())) {
    move_object(clone_object("/players/braxana/horlach/mon/dreadlord.c"),this_object());
  }
  add_action("invoke","invoke");
  add_action("ssymbol","symbol");
  add_action("kkill","kill");
}

invoke() {
  tp->zap_object(tp);
}
kkill(str) {
  if(!str) return 0;
  if(str == tpn) {
  return 1;}
}
ssymbol(str) {
  if(!str) return 0;
  if(str == "death") {
  return 1; }
  if(str == "fear") {
  return 1; }
}
realm() { return "NT"; }