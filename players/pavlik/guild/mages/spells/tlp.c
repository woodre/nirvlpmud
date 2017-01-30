#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

reset(arg) {
  int i,siz;
  string dests;

  if(arg) return;
  set_verb("tlp");
  set_name("Teleport");
  set_color_name(HIB+"Teleport"+NORM);
  set_level(6);
  set_school("conjuration");
  set_stat("intelligence");
  set_sp_cost(TLP_COST);
  set_cost_string(TLP_COST + " sp");
  
  siz = sizeof(OUTSIDE_ROOMS);
  dests = NORM;
  for( i=0; i < siz; i++ ) {
    dests += OUTSIDE_ROOMS[i] + ( siz - i > 1 ? ", " : "" );
    if( i%6 == 5 )
      dests += "\n";
  }
 
  set_descrip(
	"The Teleport spell magically transports a player across time and " +
	"space.  The target of the transportation must accept the Teleport " +
	"spell in order for it to succeed.\n" +
	"\n" +
	"Use 'tlp to <player>' to teleport to another player.\n" +
	"Use 'tlp <player>' to bring that player to your location.\n" +
	"\n" +
	"Use 'tlp setmark #' to mark your current location.\n" +
	"Use 'tlp showmark' to show your marked locations.\n" +
  "Use 'tlp showmark #' to show your marked location.\n" +
	"use 'tlp tomark #' to teleport to your marked location.\n" +
    CYN+"Other destinations: \n"+ dests
  );
}

do_tlp_move( object play, object dest ) {
  write(
    "You close your eyes in "+CYN+"concentration"+NORM+".\n" +
    "You feel the Universe around you "+HIM+"warp"+NORM+" as you "+HIB+"Teleport"+NORM+" across time and space.\n" +
    "When you reopen your eyes you are "+HIW+"someplace else"+NORM+" ... \n\n");
  say(
    ME+" closes "+PO+" eyes in "+CYN+"concentration"+NORM+".\n" +
    "There is a sudden '"+HIY+"POP!"+NORM+"' and "+ME+" "+HIW+"disappears"+NORM+"!\n");

  move_object( play, dest );

  tell_room(environment(play),
    ME+" appears in a sudden "+HIW+"flash of light"+NORM+" and a loud '"+HIB+"Bang!'"+NORM+"'\n",
   ({play}));

  play->add_spell_point(-TLP_COST);
  command("look", tp);
}

showmark( int tlp_nbr, int show_message ) {
  string tlpmark, what;
 
  if( tlp_nbr > 0 && tlp_nbr < query_level() )
  {
    tlpmark = "tlpmark"+tlp_nbr;
  }
  else
  {
    tlp_nbr = 1;
    tlpmark = "tlpmark1";
  }
 
  if(!guild->query_guild_var( tlpmark ))
    {
      if( show_message )
        write("You have not marked location "+tlp_nbr+" for teleportation.\n");
      return 0;
    }

    what = call_other(guild->query_guild_var( tlpmark ), "short", 0);

    if(!what)
    {
      write("You are unable to recall your marked location.\n");
      return 0;
    }

    write("Your teleportation mark "+tlp_nbr+" is located at: "+what+"\n");
    return 1; 
}

spell(str)
{
  object ob, obj;
  string who, what, tlpmark;
  int failed, tlp_nbr, i, total;

  if(!spell_cast())
	return 0;

  if(tp->query_attack())
  {
	notify_fail("You can't concentrate enough.\n");
	return 0;
  }

  if(!str)
  {
    command("mhelp tlp", this_player() );
    return 1;
  }

  
  /** Set Defaults **/
  tlp_nbr = 1;
  tlpmark = "tlpmark1";
  
  /*
   * Set teleport destination marker.
   */
  if( sscanf(str, "%s %d", what, tlp_nbr) == 2 )
  {
    if( tlp_nbr >= 1 && tlp_nbr < query_level() ) 
    {
      tlpmark = "tlpmark" + tlp_nbr;
    }
    else
    {
      notify_fail( "You are unable to concentrate enough to remember this location\n" );
      return 0;
    }
  }
  
  if( str == "setmark" )
  {
    what = "setmark";
  }
  if( what == "setmark" )
  {
    if(env->realm() == "NT")
    {
      notify_fail("Something "+RED+"prevents"+NORM+" you from "+CYN+"marking"+NORM+" this location.\n");
      return 0;
    }

    /*
     * no dropping a teleport mark on an object, must be an actual room
     */
    if(sscanf(object_name(env), "%s#%s", who, what) == 2)
    {
      notify_fail("This location cannot be marked.\n");
      return 0;
    }

    if(guild->query_guild_var( tlpmark ))
      write("Removing previous teleport mark ... ok.\n");

    write(
      "You "+CYN+"concentrate"+NORM+" for a moment and "+MAG+"memorize"+NORM+" this location.\n" +
      "You will now be able to "+HIB+"Teleport"+NORM+" to this spot at a later time.\n");
    say(
      ME+" closes "+PO+" eyes in concentration.\n" +
      ME+" reopens "+PO+" eyes.\n");

    guild->set_guild_var( tlpmark, object_name(env));
    return 1;
  }

  if( str == "showmark" )
  {
    what = "XX";
    for( i=1; i < query_level(); i++ )
      total += showmark( i, 0 );
    if( total < 1 )
      write("You have not marked any location for teleportation.\n");
    return 1;
      
  }
  if( what == "showmark" )
  {
    showmark( tlp_nbr, 1 );
    return 1;
  }

  /*
   * Teleport to destination marker.
   */
  if( str == "tomark" )
  {
    what = "tomark";
    tlp_nbr = 1;
    tlpmark = "tlpmark1";
  }
  if( what == "tomark" )
  {

	if(!guild->query_guild_var( tlpmark ))
	{
		notify_fail("You have not marked location "+tlp_nbr+" for teleportation.\n");
		return 0;
	}

	/* make sure the location is still valid... */
	what = call_other(guild->query_guild_var( tlpmark ), "short", 0);
	if(!what)
	{
		notify_fail("You are unable to recall your marked location.\n");
		return 0;
	}

        do_tlp_move( this_player(), guild->query_guild_var( tlpmark ) );
/*
	write(
	  "You close your eyes in "+CYN+"concentration"+NORM+".\n" +
	  "You feel the Universe around you "+HIM+"warp"+NORM+" as you "+HIB+"Teleport"+NORM+" across time and space.\n" +
	  "When you reopen your eyes you are "+HIW+"someplace else"+NORM+" ... \n\n");
	say(
	  ME+" closes "+PO+" eyes in "+CYN+"concentration"+NORM+".\n" +
	  "There is a sudden '"+HIY+"POP!"+NORM+"' and "+ME+" "+HIW+"disappears"+NORM+"!\n");

	move_object(tp, guild->query_guild_var( tlpmark ));

	tell_room(env,
	  ME+" appears in a sudden "+HIW+"flash of light"+NORM+" and a loud '"+HIB+"Bang!'"+NORM+"'\n",
	  ({tp}));

	tp->add_spell_point(-TLP_COST);
	command("look", tp);
*/
	return 1;
  }

  if(sscanf(str, "%s %s", what, who) == 2)
  {
    obj = find_player(who);
    what = "goto";
  }
  else
  {
    obj = find_player(str);
    who = str;
    what = "bring";
  }

  if(!obj || obj->query_invis())
  {
    int idx;

    idx = member( OUTSIDE_ROOMS, who );
    if( idx >= 0 ) {
      do_tlp_move( this_player(), OUTSIDE_DEST[idx] );
      return 1;
    }
    notify_fail(capitalize(who)+" is Unreachable.\n");
    return 0;
  }

  if(obj->query_level() >= WIZLEVEL && tp->query_real_name() != "pavtest")
  {
    notify_fail("You decide not to try this...\n");
    return 0;
  }

  if(present("mage_teleport", obj))
  {
    notify_fail(IT+" already has a pending teleport request.\n");
    return 0;
  }

  write("You cast a "+query_color_name()+" spell ... "+HIC+"asking "+capitalize(who)+NORM+".\n");
  failed = 0;

  if(spell_fail(level, school, stat))
	failed = 1;

  ob = clone_object(OBJ_DIR + "teleport");
  move_object(ob, obj);
  ob->set_what(what);
  ob->set_owner(tp);
  ob->set_spell_fail(failed);
  ob->set_spell_cost(TLP_COST);
  ob->do_tlp();
  return 1;

}

