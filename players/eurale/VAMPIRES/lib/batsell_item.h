/*
  translate_item.h
*/

#include "/players/eurale/defs.h"

int recurse_flag;

/* -------- sell an item to vamp shop at a distance ---------- */
batsell_item(str) {
  object obj;
  int value,value2,item_weight;
  string these;

if(!str) {
  write("What item would you like the bat to sell?\n");
  return 1; }

if(TPL < 19 || TPGEXP < 670) {
  write("Only Nosferatu may use this ability.\n");
  return 1; }

if(TPSP < 5) {
  write("You lack the spell points to accomplish this.\n");
  return 1; }

if(TPBPTS < 1) {
  write("You lack the blood energy to summon a bat.\n");
  return 1; }

obj = present(str, TP);
if(!obj) {
  write("A "+HIY+"golden bat"+NORM+" flies in for a "+str+" and then "+
        "flies away empty.\n");
  return 1; }

value = obj->query_value();
if(environment(obj) == TP) {
if(obj->drop() || !obj->short() || obj->query_auto_load()) {
    write("The "+HIY+"bat"+NORM+" squeaks, 'I can't take that'.\n");
    return 1; }

  item_weight = obj->query_weight();
  TP->add_weight(-item_weight);
}

if(value > 1000) {
  value2 = 1000 + random(100);
  if(value > value2) { value = value2; }
}

FANGS->tell_my_room(
  "A "+HIY+"golden bat"+NORM+" flies in and takes a "+obj->short()+
  " from "+capitalize(TPRN)+".\n"+
  "It flies off and returns a few moments later with coins for "+
  TP->query_objective()+".\n");
write(
  "A "+HIY+"golden bat"+NORM+" flies in and takes a "+obj->short()+
  " from you.\n"+
  "It returns momentarily with "+value+" coins and then flies off.\n");
TP->add_money(value);
TP->add_spell_point(-5);
PFANGS->add_BLOODPTS(-1);
destruct(obj);
return 1;
}
