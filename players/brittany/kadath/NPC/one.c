#include "/players/brittany/ansi"
inherit "obj/monster.c";

object staff;
object helmet;

reset(arg)  {
object gold, ob, ob2;
   ::reset(arg);
   if(arg) return;
   
set_name("great one");
   set_alias("great");
   set_alt_name("one");
   set_race("human");
set_short("The Great One");
set_long("     A bearded lean figure, with a dark very regular contoured\n"+
    "face, with a high turban on his head, and having night-black eyes.\n"+
    "His eyes almost irisless seem to gaze out into a vast distance.\n"+
    "He wears a black robe with hieroglyphics on it, which look like\n"+
    "shapes dancing around a pentagram.  His hands are covered with\n"+
    "gloves and looks abnormally large.  He speaks in a hoarse alien\n"+
    "voice.\n");
   set_gender("male");
set_level(20);
set_hp(500);
ob=clone_object("/players/brittany/kadath/OBJ/shakujo.c");
move_object(ob,this_object());
ob2=clone_object("/players/brittany/kadath/OBJ/turban.c");
move_object(ob2,this_object());
  init_command("wear turban");
  init_command("wield staff");
set_wc(30);
set_ac(17);
set_heal(15,2);
set_al(-50);
   set_aggressive(-1);
   set_dead_ob(this_object());
   
   set_chat_chance(7);
load_chat(
"The Great One speaks in a hoarse tone,\n"+
"How did you get here?\n\n");

load_chat(
"The Great One speaks in a hoarse tone,\n"+
"Why have you disturbed me?\n\n");

   set_chance(17);
  set_spell_dam(35+random(40));
   
set_spell_mess1(
"The Great One slams his staff deeply into its opponent, sparks fly wildly.\n");
set_spell_mess2(
"The Great One slams his staff deeply into you, sparks fly wildly.\n");

   gold = clone_object("obj/money");
gold->set_money(random(950)+ 4000);
   move_object(gold,this_object());
}

monster_died() {
destruct(present("staff",present("corpse",environment())));
destruct(present("helmet",present("corpse",environment())));
   tell_room(environment(this_object()),
"The Great One speaks one last time:\n\n"+
      "One day we will meet again...\n\n"+
       "At the ULTIMATE Gate!!\n\n");

return 0; }
