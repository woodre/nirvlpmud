inherit "obj/monster";

reset(arg){
   object treasure;
   ::reset(arg);
   if(arg) return;
   set_name("Boink");
   set_race("boink");
   set_alias("boink");
   set_short("Boink");
   set_long("You are very dizzy right now, and you feel that the presence of this\n"+
	"thing has something to do with it...\n");
   set_level(6);
   set_hp(100);
   set_al(-1000);
   set_wc(12);
   set_ac(3);
   set_chance(20);
   set_spell_dam(10);
   set_spell_mess("Boink boinks.");
   set_spell_mess2("Boink makes you feel odd.");
   set_chat_chance(20);
load_chat("Boink flies through your head.\n");
load_chat("Boink makes you think strange things.\n");
   treasure=clone_object("obj/money");
   treasure->set_money(random(100)+150);
   move_object(treasure,this_object());
}
