#include "/players/brittany/ansi"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("demon");
set_alias("childling");
set_alt_name("demonkind");
set_race("creature");
set_short("Dream Demon");
set_long("This creature is a barbaric savage and not better than\n"+
"animals by higher standards.  They have an intensely\n"+
"violent and cunning nature able to shapeshift into human\n"+
"form to lull others into that false sense of security.\n"+
"They are ruled completely by their true Nature, which\n"+
"is wild, predatory and unhampered by any kind of moral\n"+
"framework.\n");

set_level(10);
   set_hp(150);
   set_wc(14);
   set_ac(8);
   set_al(0);
   set_aggressive(0);
   set_dead_ob(this_object());
   
set_chat_chance(5);
load_chat("Childling says:  I will eat your heart out.\n");
load_chat("Childling asks:  Who are you?\n");
load_chat("Childling says:  Four times must I ask and four times be refused\n"+
"before I kill you.\n");
load_chat("Childling exclaims:  Tonight I will suck the marrow from your bones!\n");
  
   gold = clone_object("obj/money");
gold->set_money(50+random(17));
   move_object(gold,this_object());
}

monster_died() {
move_object(clone_object("/players/brittany/amber/OBJ/Ransword.c"),
      environment(this_object()));
   tell_room(environment(this_object()),
     "Ganelon wimpers as he falls dead.\n");
   return 0; }