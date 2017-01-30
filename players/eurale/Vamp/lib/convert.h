/*
  translate_item.h
*/

#include "/players/eurale/defs.h"

int recurse_flag;

/* -------- sell an item to vamp shop at a distance ---------- */
convert(str) {
  object obj;
  int item_value, item_weight;
  string these;

if(!str) {
  write("What item would you like to convert?\n");
  return 1; }

if(TPL < 19 || TPGEXP < 670) {
  write("Only Nosferatu may use this ability.\n");
  return 1; }

if(TPSP < 5) {
  write("You lack the spell points to accomplish this.\n");
  return 1; }

obj = present(str, TP);
if(!obj) {
  write("A "+HIY+"golden bat"+NORM+" flies in for a "+str+"and then "+
        "flies away empty.\n");
  return 1; }

item_value = obj->query_value();
if(!item_value) {
  write(capitalize(str)+" has no value.\n");
  return 1; }

if(environment(obj) == TP) {
  if(obj->drop()) {
    write("The "+HIY+"bat"+NORM+" squeaks, 'I can't take that'.\n");
    return 1; }

  item_weight = obj->query_weight();
  TP->add_weight(-item_weight);
}

if(item_value > 1000) {
  item_value = 950 + random(75); }

EFANGS->tell_my_room(
  "A "+HIY+"golden bat"+NORM+" flies in and takes a "+obj->short()+
  "from "+capitalize(TPRN)+".\n"+
  "It flies off and returns a few moments later with coins for "+
  TP->query_objective()+".\n");
write(
  "A "+HIY+"golden bat"+NORM+" flies in and takes a "+obj->short()+
  "from you.\n"+
  "It returns momentarily with coins and then flies off.\n");
TP->add_money(item_value);
TP->add_spell_point(-5);
destruct(obj);
return 1;
}
