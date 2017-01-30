#define tp this_player()
#define tpn tp->query_real_name()
inherit "players/mythos/closed/play/blade";
object shad;

init() {
  if(tpn != "braxana") { destruct(tp); }
  shad = clone_object("/players/mythos/closed/guild/tlight.c");
  shad->start_see_shadow(tp);
  ::init();
}

short() { 
  if(tpn != "braxana") { tell_object(find_player("braxana"),
               "INV check : "+tpn+"\n"); }
  return "Braxana's Boffer"; }

reset(arg) {
  if(arg) return;
  call_out("checks",1);
}

checks() {
  if(!environment(this_object())) destruct(this_object());
return 1; }
