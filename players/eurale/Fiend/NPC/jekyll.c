#define TO this_object()
#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("jekyll");
set_alias("doctor");
set_alt_name("doctor jekyll");
set_race("creature");
set_short("Doctor Jekyll");
set_long(
	"  The 1932 film Dr. Jekyl and Mr. Hyde was one of the most \n"+
	"important films of the year.  The handsome Jekyll transforms \n"+
	"into the apelike Hide right before your eyes.  Fredric March\n"+
	"played both parts and won the only Academy Award ever given to\n"+
	"an actor in a monster film.  To this day, Paramount has not yet\n"+
	"revealed how the transformation was done.\n");

set_level(20);
  set_hp(500);
  set_al(100);
move_object(clone_object("players/eurale/Fiend/OBJ/scalpel"),TO);
init_command("wield scalpel");
  set_wc(30);
  set_ac(17);
  set_aggressive(0);

set_chat_chance(15);
  load_chat("Dr. Jekyll says: Oh no! I think it's happening again..\n");
  load_chat("Jekyll looks under the table...\n");
set_a_chat_chance(15);
  load_a_chat("Jekyll screams: You dare to interrupt my work?\n");
  load_a_chat("Jekyll slashes at you with his scalpel....\n");

set_chance(15);
set_spell_dam(20);

set_spell_mess1(
  RED+"BLOOD SPLASHES"+NORM+" from the deep cut Jekyll makes...\n");
set_spell_mess2(
  RED+"BLOOD GUSHES"+NORM+" from the cut you receive from Jekyll..\n");

gold = clone_object("obj/money");
gold->set_money(4200);
move_object(gold,this_object());
}

heart_beat() {
  ::heart_beat();
if(query_attack()) {
    if(query_attack()->query_attrib("luc") < random(24)
      && !present("toxin",query_attack())) {
      move_object(clone_object("players/eurale/Keep/OBJ/poison.c"),
        query_attack());
    return 1; }
  }
}
