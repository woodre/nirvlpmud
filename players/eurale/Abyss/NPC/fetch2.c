#define tp this_player()
#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("fetch");
set_alias("guardian");
set_alt_name("fetch guardian");
set_race("creature");
set_short("Fetch Guardian");
set_long(
  "This large fetch with the lifeless eyes and the frigid flesh stands\n"+
  "ready to stop all intruders from traveling deeper into its beloved\n"+
  "abyss.  It presents an eerie opponent as it stands there neither\n"+
  "breathing or speaking...\n");

set_level(20);
set_hp(500 + random(50));
  set_al(-300 + random(300));
  set_wc(33);
  set_ac(18);
  set_aggressive(1);
  set_dead_ob(this_object());

set_chat_chance(6);
  load_chat("The fetch looks through you and smiles wickedly..\n");
set_a_chat_chance(10);
  load_a_chat("The fetch lays its ICY FINGERS against your flesh!\n");

gold = clone_object("obj/money");
gold->set_money(4000 + random(1000));
move_object(gold,this_object());
}

monster_died() {
  tell_object(this_player(),
  "As you see the fetch fall, a thought runs through your mind...\n"+
  "blue requires, 'time flows but you must hold your course'...\n");
  write_file("/players/eurale/Abyss/LOG/abyss",
  tp->query_real_name()+"     "+ctime(time())+"     fetch2\n");
return 0; }
