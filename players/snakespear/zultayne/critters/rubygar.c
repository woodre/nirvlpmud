#include "/players/snakespear/closed/ansi.h"
inherit "/obj/monster.c";

reset(arg) {
 object gold;
   ::reset(arg);
   if(arg) return;


set_name("gargoyle");
set_short(HIR+"Ruby "+NORM+"Gargoyle");
set_alias("ruby");
set_race( "spirit");
set_long(
  "  A beautiful gargoyle that almost shines in the light.  The surface of\n"+
  "the gargoyle's skin is a very bright red.  Her large wings are spread\n"+
  "wide and she peers about the room.  The gargoyle looks very tough and\n"+
  "ready to defend her home from anyone to revenge her mother's death.\n");
set_level(17);
set_ac(14);
set_wc(24);
set_al(-100+random(100));
set_hp(450+random(50));
set_aggressive(1);
set_dead_ob(this_object());

set_chat_chance(5);
  load_chat("Ruby waits, insane with anger!\n");
  load_chat("The gargoyle kicks around the bones.\n");
     
set_chance(15);
set_spell_dam(30);

set_spell_mess1(
  "Bright light shines from Ruby's body.\n");
set_spell_mess2(
  "A painful light burns you!\n");

gold = clone_object("obj/money");
gold->set_money(650);
move_object(gold,this_object());
 }

monster_died() {
  move_object(clone_object("/players/snakespear/zultayne/treasure/ruby.c"),
      environment(this_object()));
  tell_room(environment(this_object()),
      "\n\tRuby cries out to Lady Turton as she falls...\n");
return 0; }
