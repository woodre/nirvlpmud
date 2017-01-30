/* basically this shield just keeps players from wearing a shield while */
/* using the guild weapon, no ac or anything. */

inherit "obj/armor";
int allow_drop;
void reset(int arg) {
  if(arg) return;
  set_long(0);
  set_name("duellist_shield");
  set_type("shield");
}
id(str) { return str == "duellist_shield"; }
set_allow_drop() { allow_drop=1; }
drop(int blah) {
  if(!allow_drop) return 1;
  return ::drop(1);
}
query_name() { return "duelling knives"; }
short() { return "A pair of duelling knives (wielded)"; }
query_offwielded() { return worn; }  /* gives a better message if a player tries
                                     to wear a shield */
remove(str) {
  if(!query_verb() || query_verb()=="sheath") return ::remove(str);
}
