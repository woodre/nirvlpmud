/* ditch all armor reqs, move to negative resistance */
/* Armor-restricting id() */

id(str) {
/*
  if(previous_object()) {
  if(!test_my_wear(previous_object())) {
    return str == "dervish_tattoo" || str == "tattoo" ||
    str == "no_spell" || str == "generic_wc_bonus" ||
    str == "pro_object" || str == "notarmor"; }
  }
*/
  return str == "dervish_tattoo" || str == "tattoo" ||
  str == "no_spell" || str == "generic_wc_bonus" ||
  str == "pro_object" || str == "GI"; }

test_my_wear(ob) {
  int me, mylevel, aweight;
  string atype;
  me = environment();
  if(!me) return;
  mylevel = me->query_level();
  if(mylevel < 7) return 1;
  atype = ob->query_type();
  aweight = ob->query_weight();
  if(!atype) return;
  if(atype == WHIRLWIND) return 1;
  if(mylevel < 10) {
    if(atype == "armor" || aweight > 1) return 0;
    else return 1; }
  if(mylevel < 14) {
    if(atype == "armor" || atype == "shield" || 
       atype == "helmet" || aweight > 1) return 0;
    else return 1; }
  if(mylevel < 16) {
    if(atype == "armor" || atype == "shield" ||
       atype == "helmet" || atype == "boots" ||
       aweight > 1) return 0;
    else return 1; }
  if(mylevel < 20) {
    if(atype == "armor" || atype == "shield" ||
       atype == "helmet" || atype == "boots" ||
       atype == "gloves" || aweight > 1) return 0;
    else return 1; }
  else return 1; }
