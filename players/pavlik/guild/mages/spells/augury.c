#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "players/pavlik/guild/mages/inherit/spell";
/******************************************************************************
 * Program: augury.c
 * Path: /players/pavlik/guild/mages/spells
 * Type: Guild Spell
 * Created:
 *
 * Purpose: The mage augury spell creates a shadow object on the player that
 *          forces all healing to be turned into spell points.
 * History:
 *          08/09/2013 - Dragnar
 *            Fix issue when player has more than 1 object shadowing them.
 ******************************************************************************/

reset(arg) {
  if(arg) return;
  set_verb("augury");
  set_name("Augury");
  set_color_name(HIG+"Augury"+NORM);
  set_level(5);
  set_school("evocation");
  set_sp_cost(AUGURY_COST);
  set_cost_string("none");
  set_descrip(
	"When this spell is in effect any healing of hit points will be " +
	"converted into spell point healing instead.  For example, If you " +
	"consume a heal that would normally restore 50 hit points you will " +
	"heal 50 spell points instead.\n" +
	"\n" +
	"Use 'augury' to start and stop this spell.\n"
  );
}


spell()
{
  object ob;

  if(!spell_cast())
	return 0;

  ob = shadow( tp, 0 );
  if( ob && ob->query_spell_name() == "augury" )
  {
    write("You "+MAG+"stop"+NORM+" the "+query_color_name()+" spell.\n");
    ob->end_spell();
    if(guild)
      guild->remove_spell_object("augury");
  }
  else
  {
	write("You cast an " + query_color_name() + " spell ... \n");
	write("You feel a "+HIM+"shift"+NORM+" in your body as the "+query_color_name()+" spell goes into effect.\n");
	say(ME+" casts a "+HIC+"spell"+NORM+" and you feel the air tingle with "+HIM+"magic"+NORM+".\n");
	ob = clone_object(OBJ_DIR + "augury");
	ob->set_spell_name("augury");
	ob->do_spell(tp);
	if(guild)
		guild->add_spell_object("augury", ob);
  }

  return 1;

}
