#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("seamstress");
set_race("human");
set_short("Seamstress");
set_long(
	"  This hearty woman is dressed in a frock and bonnet.  The apron\n"+
	"she wears carries the tools of her trade... needles, awls, thread,\n"+
	"pliers and other assorted articles.  She goes about her business\n"+
	"of outfitting the local folk with gusto and cheerfulness.\n");

  set_hp(425);
  set_level(17);
  set_al(10);
  set_wc(24);
  set_ac(14);
  set_aggressive(0);
  set_dead_ob(this_object());

set_chat_chance(15);
  load_chat("The seamstress says: Good day to you, Sir.\n");
  load_chat("The seamstress wipes her hands on  her apron.\n");
  load_chat("Can I help you? asks the seamstress\n");
  load_chat("The seamstress smiles at you....\n");
set_a_chat_chance(15);
  load_a_chat("The seamstress yells: You dirty no-gooder!\n");
  load_a_chat("The seamstress stabs at you with a huge needle..\n");
  load_a_chat("The seamstress kicks at your groin...\n");

gold = clone_object("obj/money");
gold->set_money(900+random(100));
move_object(gold,this_object());
}

monster_died() {
  tell_room(environment(this_object()),
  "\n\nGod save the King from the likes of you! crys the seamstress\n\n");
return 0; }
