#include <ansi.h>

string name;
int glvl;
int gxp;
int *skills;
int skill_pts;
int stamina_bonus;
int strength_bonus;
int stealth_bonus;
int paladin;
int knight;
int assassin;
int berserker;
string chosen_align;
int monk;
int touch;
int blood;
int time;
int mind;
int xsta;

short(){ return "Warrior Tool"; }
long(){
write("To load up a warriors stats for review: wload <name>\n"+
      "To clear a warrior from the tool:       clear_war\n");
return 1;
}

id(str){ return str == "tool" || str == "warrior tool"; }

init(){
 add_action("load_warrior", "wload");
 add_action("clear_warrior", "clear_war");
 add_action("view_warrior", "view");
 add_action("tell_war", "wtell");
 }

load_warrior(str){
 if(!str) return 1;
 name = str;
 restore_object("players/guilds/warriors/member/"+str+"");
 write("loaded "+str+".\n");
 return 1;
 }

clear_warrior(){
 name = 0;
 glvl = 0;
 gxp = 0;
 skills = 0;
 skill_pts = 0;
 stamina_bonus = 0;
 strength_bonus = 0;
 stealth_bonus = 0;
 paladin = 0;
 knight = 0;
 assassin = 0;
 berserker = 0;
 chosen_align = 0;
 monk = 0;
 touch = 0;
 blood = 0;
 time = 0;
 mind = 0;
 write("Cleared.\n");
 return 1;
 }

view_warrior(){
 write("NAME: "+name+"\n");
 write("GLVL: "+glvl+"\n");
 write("GXP : "+gxp+"\n");
 write("SKILL PTS: "+skill_pts+"\n");
 if(knight)   write("KNIGHT: YES  ");
 else         write("KNIGHT: NO   ");
 if(monk)     write("MONK: YES\n");
 else         write("MONK: NO\n");
 if(assassin) write("ASSASSIN: YES ");
 else         write("ASSASSIN: NO  ");
 if(berserker) write("BERSERKER: YES\n");
 else          write("BERSERKER: NO \n");
 if(paladin)   write("PALADIN: YES\n");
 else          write("PALADIN: NO \n");
 write(
		"\n\n\n                         -[  "+HIB+"Weapon Skills"+NORM+" ]-\n"+
		"  Blunt Weapon    "+skills[1]+"/10\t\t"+
		"Edged Weapon    "+skills[2]+"/10\n"+
		"  Polearm Weapon  "+skills[3]+"/10\t\t"+
		"Archery Weapon  "+skills[4]+"/10\n"+
		"  Exotic Weapon   "+skills[5]+"/10\t\t"+
		"Small Weapon    "+skills[6]+"/10\n"+
		"                          -[ "+HIR+"Attack Moves"+NORM+" ]-\n"+
		"  Throw           "+skills[15]+"/5\t\t"+
		"Strike          "+skills[16]+"/5\n"+
		"  Punch           "+skills[17]+"/5\t\t"+
		"Kick            "+skills[18]+"/5\n"+
		"  Charge          "+skills[19]+"/5\t\t"+
		"Bash            "+skills[20]+"/5\n"+
		"  Finish          "+skills[41]+"/3\t\t"+
	   "Blindfight      "+skills[70]+"/2\n");
	write(
		"                         -[ "+HIG+"Defensive Moves"+NORM+" ]-\n"+
		"  Dodge           "+skills[30]+"/5\t\t"+
		"Parry           "+skills[31]+"/5\n"+
		"  Offhand Parry   "+skills[32]+"/5\t\t"+
		"Block           "+skills[33]+"/5\n"+
		"                          -[ "+HIM+"Miscellaneous"+NORM+" ]-\n"+
		"  Pummel          "+skills[40]+"/5\t\t"+
		"First Aid       "+skills[50]+"/5\n"+
    	"  Run             "+skills[60]+"/3\n\n\n");
   if(monk){
write(
      HIW+"                         -[ "+HIB+"Monk Skills"+HIW+" ]-\n"+
      "  Hand-to-Hand      "+HIB+skills[80]+"/5  "+HIW);

if(skills[30] > 5) write("  Advanced Dodge    "+HIB+(skills[30] - 5)+"/5\n"+HIW);
else write("  Advanced Dodge    "+HIB+"0/5\n"+HIW);
write(
      "  Touch             "+HIB+skills[81]+"/5"+HIW+"  "+
      "  Advanced Punch    "+HIB+skills[21]+"/5"+HIW+"\n"+
      "  Advanced Kick     "+HIB+skills[22]+"/5"+HIW+"  "+
      "  Meditate          "+HIB+skills[85]+"/5"+HIW+"\n\n"+
      "                         -[ "+HIB+"Disciplines"+HIW+" ]-\n");
if(blood) write("  Discipline of Blood    "+HIB+"YES\n"+HIW);
else      write("  Discipline of Blood    "+HIB+"NO\n"+HIW);
if(time) write("  Discipline of Time     "+HIB+"YES\n"+HIW);
else     write("  Discipline of Time     "+HIB+"NO\n"+HIW);
if(mind) write("  Discipline of Mind     "+HIB+"YES\n\n"+NORM);
else     write("  Discipline of Mind     "+HIB+"NO\n\n"+NORM);
}
if(paladin){
write(
      BLU+"                         -[ "+HIB+"Paladin Skills"+NORM+BLU+" ]-\n"+
      HIY+" AURA POWERS"+HIW+"\n"+
      "  Regeneration          "+HIB+skills[92]+"/5"+HIW+"  "+
      "  Protection from Good  "+HIB+skills[90]+"/5"+HIW+"\n"+
      "  Protection from Evil  "+HIB+skills[91]+"/5"+HIW+"\n"+
      HIY+" HOLY POWERS"+HIW+"\n"+         
      "  Holy Bolt (good)      "+HIB+skills[93]+"/5"+HIW+"  "+
      "  Release               "+HIB+skills[94]+"/1"+HIW+"\n"+
      "  Redeem    (good)      "+HIB+skills[96]+"/5"+HIW+"  "+
      "  Corrupt   (evil)      "+HIB+skills[98]+"/5"+HIW+"\n"+
      "  Plague    (evil)      "+HIB+skills[99]+"/5"+HIW+"  "+
      "  Cleanse               "+HIB+skills[95]+"/1"+HIW+"\n"+
      "  Detect                "+HIB+skills[89]+"/1"+HIW+"  "+
      "  Sacrifice             "+HIB+skills[97]+"/5"+HIW+"\n\n"+NORM);
}
if(knight){
write(
      BOLD+"                         -[ "+HIW+"Knight Skills"+NORM+BOLD+" ]-\n"+
      " SKILLS"+HIW+"\n"+
      "  Bcommand              "+HIB+skills[104]+"/5"+HIW+"  "+
      "  Defend                "+HIB+skills[100]+"/1"+HIW+"\n"+
      "  Xstrike               "+HIB+skills[103]+"/5"+HIW+"  "+
      "  Xbash                 "+HIB+skills[102]+"/5"+HIW+"\n"+
      "  Study                 "+HIB+skills[101]+"/5"+HIW+"  "+
      "  Advanced Stamina      "+HIB+xsta+"/5"+HIW+"\n\n"+NORM);
}
return 1;
}