#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

#define MISSILES	random(guild->query_total_guild_stat("evocation") / 10) + 1
#define MAX_MISSILES	5

reset(arg) {
  if(arg) return;
  set_verb("mssle");
  set_name("Magic Missile");
  set_color_name(HIM+"Magic Missile"+NORM);
  set_level(1);
  set_school("evocation");
  set_type("damage");
  set_combat_spell(1);
  set_sp_cost(MSSLE_COST);
  set_cost_string(MSSLE_COST + " sp / Missile");
  set_descrip(
	"Fire bolts of deadly magic into your enemy.  The number " +
	"of magic missiles fired will increase as the spellcaster " +
	"advances in guild rank.\n"
  );
}

query_dmg()
{
  if(present("mage_casting_obj", tp))
	return random(100) / 7;
  else
	return MSSLE_DAMAGE;
}

query_missiles()
{
  if(present("mage_casting_object", tp))
	return random(MAXGUILDRANK / 7) + 1;
  else
	return MISSILES;
}


spell()
{
  object obj;
  int missiles;
  int dmg;
  int total;
  string dtype;

  if(!spell_cast())
	return 0;

  obj = tp->query_attack();

  write("You cast a " + query_color_name() + " spell ... \n");
  say(ME + " casts a spell ... \n");

  /* NOTE: no spell_fail */

  missiles = query_missiles();
  if(missiles > MAX_MISSILES) missiles = MAX_MISSILES;

  write(
   "Lightning "+HIY+"flashes"+NORM+" across the sky and "+numer(missiles)+" "+HIR+"deadly bolts of energy"+NORM+" leap\n" +
   "from your fingertips and "+HIY+"streak"+NORM+" through the air!\n");
  say(
   "Lightning "+HIY+"flashes"+NORM+" across the sky and "+numer(missiles)+" "+HIR+"deadly bolts of energy"+NORM+" leap\n" +
   "from "+ME+"'s fingertips and "+HIY+"streak"+NORM+" through the air!\n");


  while(missiles > 0)
  {

	dmg = query_dmg();
	total += dmg;

	if(dmg < 1) {
		wild_shot(obj);
	}
	else if(dmg < 5) {
		write("  Your missile "+CYN+"grazes"+NORM+" "+IT+".\n");
		say("  "+ME+"'s missile "+CYN+"grazes"+NORM+" "+IT+".\n");
	}
	else if(dmg < 9) {
		write("  Your missile "+YEL+"hits"+NORM+" "+IT+".\n");
		say("  "+ME+"'s magic missile "+YEL+"hits"+NORM+" "+IT+".\n");
	}
	else {
		write("  Your missile "+HIY+"streaks"+NORM+" into "+IT+"'s body, ");
		write(HIC+"a direct hit!\n"+NORM);
		say("  "+ME+"'s missile flies straight into "+IT+", "+HIC+"a direct hit!\n"+NORM);
	}

	if(!present("mage_casting_object", tp))
		tp->add_spell_point(-(query_sp_cost()));
	missiles--;
  }

  if(total > 50) total = 50;
  dtype = guild->query_spell_dtype_dam();
  if( !dtype )
    dtype = "magical";
  obj->do_damage(({total}), ({ dtype }));
  if(tp->query_level() > WIZLEVEL || tp->is_testchar())
	write("Total "+dtype+" Damage: "+total+"\n");

  return 1;
}


wild_shot(target)
{
  object ob, obj;

  ob = all_inventory(env);
  obj = ob[random(sizeof(ob))];

  if(obj == tp || obj == target)
  {
	write("  Your missle "+RED+"fizzles"+NORM+" ...what a dud!\n");
	say("  "+ME+"'s missle "+RED+"fizzles"+NORM+" ...what a dud!\n");
  }
  else if(!obj->query_hp())
  {
	write("  Your missle "+HIW+"goes wild"+NORM+" and strikes "+obj->short()+"!\n");
	say("  "+ME+"'s missile "+HIW+"goes wild"+NORM+" and strikes "+obj->short()+"!\n");
  }
  else
  {
	write("  Your missile "+HIW+"goes wild"+NORM+" and strikes "+IT+" in the back!\n");
	say("  "+ME+"s magic missile goes wild and strikes "+IT+" in the back!\n");
	tell_object(obj, "  "+ME+"'s magic missile "+HIR+"strikes you in the back!"+NORM+"\n");
  }
  return 1;
}


numer(x)
{
  string tmp;
  if(x == 1) tmp = "one";
  if(x == 2) tmp = "two";
  if(x == 3) tmp = "three";
  if(x == 4) tmp = "FOUR";
  if(x == 5) tmp = "FIVE";
  if(x == 6) tmp = "SIX";
  return HIC+tmp+NORM;
}

