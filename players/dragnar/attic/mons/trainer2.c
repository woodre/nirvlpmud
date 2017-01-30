#include <ansi.h>
inherit "obj/monster";
int hps, ohps, dmg1, dmg2;
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
	set_hp(1000);
	set_al(-10);
   set_wc(3);
	set_ac(17);
	set_heart_beat(1);
   set_chat_chance(0);
	load_chat("The man looks at you and cackles.\n");
}
init() {
	add_action("totals","totals");
	add_action("clear","clear");
}
heart_beat(){
        int HPS;
   ::heart_beat();
   HPS=this_object()->query_hp();
   room=environment(this_object());
        if(this_player()->query_attack()) {
        hps  = 1000 - HPS;
  if(hps > 0) {
        dmg1 = hps + dmg1;
        dmg2 = 1 + dmg2;
		say("Your "+hps+" damage did nothing to me.  You'll never be MK Champion.\n");
   }
  this_object()->heal_self(1000);
        }
}
totals() {
	if(dmg2 < 1) {
	write("The old man says: You have to fight me first foolish one.\n");
		return 1; }
        write("Totals are as follows:\n");
        write("Total Damage: "+dmg1+"\n");
        write("Total Rounds: "+dmg2+"\n");
        write("Average Damage: "+dmg1/dmg2+"\n");
	write("\nType 'clear' to reset the variables back to 0.\n");
        return 1;
        }
clear() {
	write("The old man says: Resetting all variables.\n");
	dmg1 = 0;
	dmg2 = 0;
	return 1; }
