/*
  make_servant.h
*/

#include "/players/eurale/defs.h"

/* -------- Make a servant from a corpse ---------- */
make_servant(str) {
  object target_obj, servant_obj;
  int i;

if(EFANGS->query_servant_obj()) {
  write("You can only make one servant at a time.\n");
  return 1; }

if(TPL < 12 || TPGEXP < 668 || TP->query_attrib("luc") < 16) {
  write("You lack the skills to make a servant.\n");
  return 1; }

if(TPSP < 100) {
  write("You lack the magic to make a servant.\n");
  return 1; }

target_obj = present("corpse", ROOM);
if(!target_obj) {
  write("A corpse must be present to do that.\n");
  return 1; }

TP->add_spell_point(-100);
destruct(target_obj);
servant_obj = clone_object(SERVANT);
EFANGS->set_servant_obj(servant_obj);
servant_obj->set_master_name(TPRN);
  servant_obj->set_name(lower_case(str));
  servant_obj->set_servant_name(lower_case(str));
write_file("/players/eurale/Vamp/lib/SERVANTS",ctime(time())+"  "+
  capitalize(TPRN)+" resurrected a servant named "+capitalize(str)+"\n");
i = TPL;
servant_obj->set_level(i);
servant_obj->set_hp(666);
servant_obj->set_ac(99);
if(i < 10) i = 4;
servant_obj->set_wc(i);
move_object(servant_obj, ROOM);
command("fix servant", TP);
write("The corpse raises as a servant and says: 'My name is "+
      capitalize(servant_obj->query_name())+"'.\n");
EFANGS->tell_my_room(
          "The corpse raises and says: 'My name is "+
          capitalize(servant_obj->query_name())+"'.");
str = "bow "+TPRN;
command(str, servant_obj);
return 1;
}
