#include <ansi.h>
inherit "obj/monster";
#define HP this_object()->query_hp()
#define attack this_object()->query_attack()
static int damage,new_hp,old_hp;
static int TotalDamage,Rounds;

object room;
reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("man");
   set_race("man");
   set_alias("old man");
   set_short("An old man");
	set_long("The man carries himself like he is very strong...Perhaps attacking\n"+
"him would be unwise.  As he looks at you his eyes seem to burn\n"+
"right through you.  Maybe he could help you train, fight him and\n"+
"when you have had enough, type 'totals.'\n");
   set_level(20);
	set_hp(500);
	set_al(1000);
   set_wc(3);
	set_ac(17);
	set_heart_beat(1);
   set_chat_chance(0);
    set_dead_ob(this_object());
	load_chat("The man looks at you and cackles.\n");
}
init() {
	add_action("totals","totals");
	add_action("clear","clear");
}
monster_died() {
  object who;
  who = this_object()->query_attack();
  if(!who) return;
  totals();
}
heart_beat(){
   ::heart_beat();
   room=environment(this_object());
    if(!old_hp) old_hp = HP;
  new_hp = HP;
  damage = (old_hp - new_hp);
  if(damage < 0) damage = 0;
  old_hp = new_hp;
  if(attack) {
    say("\t\t"+HIW+"Damage: "+damage+NORM+".\n");
    Rounds++;
    TotalDamage += damage;
  }
}
totals() {
	if(Rounds < 1) {
	write("The old man says: You have to fight me first foolish one.\n");
		return 1; }
        write("Totals are as follows:\n");
        write("Total Damage: "+TotalDamage+"\n");
        write("Total Rounds: "+Rounds+"\n");
        write("Average Damage: "+TotalDamage/Rounds+"\n");
	write("\nType 'clear' to reset the variables back to 0.\n");
        return 1;
        }
clear() {
	write("The old man says: Resetting all variables.\n");
  this_object()->heal_self(1000);
	TotalDamage = 0;
	Rounds = 0;
	return 1; }
