#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

reset(arg) {
  if(arg) return;
  set_verb("knowal");
  set_name("Know Alignment");
  set_color_name(MAG+"Know Alignment"+NORM);
  set_level(1);
  set_school("enchantment");
  set_stat("wisdom");
  set_sp_cost(KNOWAL_COST);
  set_cost_string(KNOWAL_COST + " sp");
  set_descrip(
	"This spell will help determine the alignment of a living thing.\n"
  );
}


spell(str)
{

  object obj;
  string aura, aln;
  int al;

  if(!spell_cast())
	return 0;

  if(!str) obj = tp->query_attack();
  else obj = present(str, env);
  if(!obj || !living(obj))
  {
	notify_fail("That is not here.\n");
	return 0;
  }

  write("You cast a " + query_color_name() + " spell...\n");

  if(spell_fail(level, school, stat))
  {
	write("You "+HIR+"fail"+NORM+" the spell miserably.\n");
	say(ME+" "+HIR+" miscasts"+NORM+" a spell.\n");
	tp->add_spell_point(-5);
	return 1;
  }

  al = obj->query_alignment();

  if(al >= 800) {
	aura = HIW+"brilliant white"+NORM;
	aln = HIW+"a Saint"+NORM;
  }
  else if(al >= 400) {
	aura = HIC+"sky blue"+NORM;
	aln = HIC+"Very Good"+NORM;
  }
  else if(al >= 200) {
	aura = HIB+"blue"+NORM;
	aln = HIB+"Good"+NORM;
  }
  else if(al >= 50) {
	aura = CYN+"faint blue"+NORM;
	aln = CYN+"with good intentions"+NORM;
  }
  else if(al >= -50) {
	aura = "somber grey";
	aln = "neutral";
  }
  else if(al <= -1000) {
	aura = HIBLK+"jet black"+NORM;
	aln = "the Embodiment of Evil";
  }
  else if(al <= -400) {
	aura = HIR+"blood red"+NORM;
	aln = HIR+"Very Evil"+NORM;
  }
  else if(al <= -200) {
	aura = RED+"red"+NORM;
	aln = RED+"Evil"+NORM;
  }
  else {
	aura = MAG+"faint red"+NORM;
	aln = MAG+"with evil intentions"+NORM;
  }

  write(
   "Your spell reveals a "+aura+" aura.\n" +
   IT+" is "+aln+".\n");

  say(
   ME+" casts a spell.\n" +
   "A "+aura+" aura appears around "+IT+".\n");

  tp->add_spell_point(-(query_sp_cost()));
  return 1;

}
