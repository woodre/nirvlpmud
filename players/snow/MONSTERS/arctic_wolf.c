/*
Basic mid-level wolf. High spell attack damage and heal rate.
*/
 
#define MEATN capitalize(this_object()->query_attack()->query_name())
 
inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
object ob; 
int R;
string shortdesc;

R = random(4);

if(R == 0) shortdesc = "A ferocious Arctic Wolf";
if(R == 1) shortdesc = "A snarling Arctic Wolf";
if(R == 2) shortdesc = "A grizzled Arctic Wolf";
if(R == 3) shortdesc = "A wickedly intelligent Arctic Wolf";

  ob = clone_object("/obj/treasure");
call_other(ob,"set_id","pelt");
call_other(ob,"set_short","Arctic Wolf pelt");
call_other(ob,"set_value",1000);
call_other(ob,"set_alias","wolf pelt");
call_other(ob,"set_long",
"The pelt of an Arctic Wolf. It should be worth something at the shop.\n");
move_object(ob,this_object());
 
     set_name("arctic wolf");
     set_short(shortdesc);
     set_race("wolf");
     set_alias("wolf");
     set_long(
"This denizen of arctic regions stands about one meter tall at the shoulder.\n"+
"Its eyes reflect ferocious hunger and willingness to kill.\n");
     set_level(15);
     set_ac(8);
     set_wc(random(10)+14);
     set_hp(random(100)+200);
     set_heal(1,3);
     set_al(-100);
     set_aggressive(1);
     set_whimpy();
     set_chat_chance(5);
     set_a_chat_chance(7);
     load_chat("The Arctic Wolf howls at the sky...\n");
     load_chat("The Arctic Wolf looks at you hungrily...\n");
     load_a_chat("The Arctic Wolf snarls angrily.\n");
     load_a_chat("The Arctic Wolf drools in anticipation of a meal.\n");
set_chance(10);
set_spell_mess1("The Arctic Wolf chomps into its foe!\n");
set_spell_mess2("The Arctic Wolf chomps into you!\n");
set_spell_dam(25);
   }
}
 
heart_beat() {
  object bear;
  ::heart_beat();
  bear = present("beach bear", environment(this_object()));
  if(bear && bear->query_attack()) attack_object(bear->query_attack());
}
