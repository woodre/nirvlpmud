#include "/players/vertebraker/guilds/meijin/defs.h"
#define COST 70
#define RANK 10
#define SKILL_NAME "judge"

/* Ok, -Bp 2352 Jul 21 21:08 xjudge.c */
/*****/
/* determine alignment of a living thing */
/*****/

void help() {
  write("\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("     Skill  : Judge \n");
  write("     Syntax : xjudge <target>\n");
  write("     Cost   : "+COST+" ep\n");
  write("     Rank   : "+RANK+"\n");
  write("     Description : \n");
  write("         Determine somethings basic alignment.\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return RANK; }
string query_skill_name() { return SKILL_NAME; }

int main(string str){
  object obj;
  string aura, aln;
  int al;

  if(!GOB->query_skill(SKILL_NAME)) return 0;

  if(GOB->query_endurance() < COST) {
	write("You are too tired.\n");
	return 1;
  }

  if(!str) { obj = (object)TP->query_attack(); }
  else { obj = present(str, environment(TP)); }

  if(!obj){
	write("That is not here.\n");
	return 1;
  }

  if(!living(obj)) {
	write("You are unable to determine "+str+"'s alignment.\n");
	return 1;
  }

  if(obj == TP) {
	write("You cannot judge yourself in this manner.\n");
	return 1;
  }

  al = (int)obj->query_alignment();
  if(al > 800){
    aura = HIW+"brilliant white"+NORM;  aln = HIW+"a Saint"+NORM; }
  else if(al > 400){
    aura = HIC+"sky blue"+NORM;  aln = HIC+"Very Good"+NORM; }
  else if(al > 200){
    aura = HIB+"blue"+NORM;  aln = HIB+"Good"+NORM; }
  else if(al > 50){
    aura = CYN+"faint blue"+NORM;  aln = CYN+"with good intentions"+NORM; }
  else if(al < 50 && al > -50){
    aura = "somber grey";  aln = "neutral";  }
  else if(al < -50){
    aura = MAG+"faint red"+NORM;  aln = MAG+"with evil intentions"+NORM; }
  else if(al < -200){
    aura = RED+"red"+NORM;  aln = RED+"Evil"+NORM; }
  else if(al < -400){
    aura = HIR+"blood red"+NORM;  aln = HIR+"Very Evil"+NORM; }
  else if(al < -800){
    aura = "jet black";  aln = "the Embodiement of Evil";  }
  else {
    aura = "somber grey";  aln = "neutral";  }

  write(PRE+"You scrutinize "+IT+" very carefully.\n");
  write(PRE+"Your study reveals a "+aura+" aura.\n");
  write(PRE+IT+" is "+aln+".\n");
  say(ME+" scrutinizes "+IT+" very carefully.\n");
  TP->add_spell_point(-5);
  GOB->add_endurance(-5);
  return 1;
}

