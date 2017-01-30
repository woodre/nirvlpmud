#include "/players/brittany/ansi"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("unicorn");
set_alias("horse");
set_alt_name("animal");
set_race("creature");
set_short("A Unicorn");
set_long("It looks like an apparition, soft, shimmering and white as\n"+
"if it is covered with down rather than fur and manning.  It\n"+
"has tiny cloven hooves that are golden and a whorled horn\n"+
"that rose from its narrow head.  It's eyes are a bright emerald\n"+
"color.\n");

set_level(5);
   set_hp(75);
   set_wc(9);
   set_ac(5);
   set_al(0);
   set_aggressive(0);
   set_dead_ob(this_object());
   
set_chat_chance(5);
load_chat("The unicorn looks your way.\n");
load_chat("The unicorn's horn glows brightly.\n");
 
   gold = clone_object("obj/money");
gold->set_money(200);
   move_object(gold,this_object());
}

monster_died() {
move_object(clone_object("players/brittany/amber/OBJ/horn.c"),
      environment(this_object()));
   tell_room(environment(this_object()),
"The unicorn collapses to the ground gracefully.\n");
   return 0; }