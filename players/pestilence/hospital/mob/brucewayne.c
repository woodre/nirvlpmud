/* Based on Maledicta's Fireangel */
#include <ansi.h>
inherit "obj/monster.c";
int changed;
reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("Bruce Wayne");
set_alt_name("bruce");
set_alias("bruce wayne");
set_race("human");
set_short("Bruce Wayne");
set_long(
  "   This is a man in a suit.  Obviously comes from a lot \n"+
  "of money.  Though oddly enough here he is, in the insane\n"+
  "part of the hospital.  He appears to be sane.  But that could\n"+
  "be just an ellaborate facad.\n");

set_level(15);
set_hp(300);
set_al(300);
set_wc(25);
set_ac(8);
set_heart_beat(2);
set_aggressive(0);
set_dead_ob(this_object());
set_changed(0);
set_chat_chance(5);
  load_chat("Bruce Wayne says: I'm Batman\n");
 }

set_changed(int n){ changed = n; }
query_changed(){ return changed; }

heart_beat() {
	object attacked;
	::heart_beat();
	attacked=(this_object()->query_attack());
  if(attacked && query_changed() == 0){
  	tell_room(environment(this_object()),
  	"\n\n\n\n   Bruce Wayne disappears in a  "+HIK+"SMOKEY"+NORM+""+
      " Explosion!\n\n\n\n"+
  	"          Now standing before you is "+
      " "+BLU+"Batman."+NORM+"\n");
  	this_object()->set_short(BLU+"Batman"+NORM);
  	this_object()->set_long(
  	"This is the famous crime fighter Batman.  Obviously Bruce Wayne\n"+
  	"was telling the truth all along.  Batman stands here in his patented\n"+
  	"armor, pointed helmet and the famous utility belt.\n");
  	this_object()->set_race("batman"); 
	this_object()->set_changed(1);
      this_object()->set_level(20);
	  this_object()->set_alt_name("batman");
	  this_object()->set_name(BLU+"Batman"+NORM);
	  this_object()->set_wc(55);
	  this_object()->set_ac(38);
	  this_object()->set_hp(800);
      this_object()->set_heal(5,5);
	  this_object()->set_chat_chance(0);
	  this_object()->add_spell("slash",
"\n"+HIY+"                    _,    _   _    ,_ \n"+
"               .o888P     Y8o8Y     Y888o. \n"+
"              d88888      88888      88888b \n"+
"             d888888b_  _d88888b_  _d888888b \n"+
"             8888888888888888888888888888888 \n"+
"             8888888888888888888888888888888 \n"+
"             YJGS8P*Y888P*Y888P*Y888P*Y8888P \n"+
"              Y888   '8'   Y8P   '8'   888Y \n"+
"               '8o          V          o8' \n"+
"                 `                     `. "+NORM+"\n",
"\n"+HIY+" /(_M_)\\ \n"+
"|       | \n"+
" \\/~V~\\/"+NORM+"\n",
 30,"40-75","other|magic",0);
	  
	  
	  
	}
}
monster_died() {
  object corpse;
  corpse = present("corpse", environment()); 
  tell_room(environment(this_object()),
  "As Batman dies, with his last breath he says: I'm Bruce .... Wa  yne.\n");	
  /*
  move_object(clone_object("/players/maledicta/ruins/weapons/flaming_sword.c"),
      environment(this_object()));
	  */

return 1; }
