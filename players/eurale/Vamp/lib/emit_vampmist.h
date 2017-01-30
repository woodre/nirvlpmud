/*
  emit_mist.h
*/

#include "/players/eurale/defs.h"

/* -------- Emit a mist that makes it dark ---------- */
emit_vampmist(str) {
if(!str || str != "mist") return 0;

if(TPXL < 3 || TPGEXP < 670 ||
  TP->query_attrib("sta") < 20 || TP->query_attrib("mag") < 20 ||
  TP->query_attrib("str") < 20 || TP->query_attrib("wil") < 20 ||
  TP->query_attrib("luc") < 20 || TP->query_attrib("pie") < 20 ||
  TP->query_attrib("ste") < 20 || TP->query_attrib("int") < 20) {
  write("You lack the necessary skill for this ability.\n");
  return 1; }

if(TPSP < 150) {
  write("You lack the magic to emit a mist.\n");
  return 1; }

if(EFANGS->query_vampire_mist()) {
  write("A vampire mist already surrounds you.\n");
  return 1; }

TP->add_spell_point(-150);
EFANGS->set_vampire_mist(1);
EFANGS->tell_my_room(HIR+
  "A dark red mist begins to surround "+capitalize(TPRN)+", obscuring "+
  "your vision."+NORM+"\n");
write(HIR+
  "A dark red mist creeps in and SWIRLS around you."+NORM+"\n");
return 1;
}
