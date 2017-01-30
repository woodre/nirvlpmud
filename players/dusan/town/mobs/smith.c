#include "/players/dusan/ansi.h"
inherit "obj/monster.c";

reset(arg) {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("Alan");
set_alias("smith");
set_alt_name("blacksmith");
set_race("human");
set_short("A large blacksmith.");
set_long(
  "A very large man stands here.  He is dirty and covered in blacksoot. \n"+
  "The only time he stops forging things with his hammer is to wipe the sweat \n"+
  "from his brow.  He looks very troubled, maybe you should ask if you can help. \n"
);

set_level(10);
set_hp(200);
set_al(400);
set_wc(20);
set_ac(8);
set_heal(2,40);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(15);
  load_chat("The smith says 'You here to clean up the swamp?' \n");
set_a_chat_chance(15);
  load_a_chat("The smith says 'Your going to pay for this!' \n");

set_chance(10);
set_spell_dam(10);

set_spell_mess1(
  "Your head snaps back as the smith rocks you with a solid punch to your head \n");
set_spell_mess2(
  " \n");

gold = clone_object("obj/money");
gold->set_money(500);
move_object(gold,this_object());
}

monster_died() {
object hammer;
hammer = clone_object("/players/dusan/area1/weapons/hammer.c");
move_object(hammer,present("corpse", environment()));
  tell_room(environment(this_object()),
	"Smith died \n");
return 0; }
