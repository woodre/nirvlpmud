#include "/players/pavlik/guild/mages/defs.h"
inherit "/players/pavlik/guild/mages/inherit/room";
inherit "room/room";

#define SUMM capitalize(summoner->query_name())
#define SC GRN+"The "+NORM+HIBLK+"Summoning"+NORM+GRN+" Chamber"+NORM
#define HS RED+"Heart"+NORM+HIBLK+"Stone"+NORM

object summoner;
int heart_count;

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc=SC;
  long_desc=
	"You are "+GRN+"deep"+NORM+" within the Earth, under the Tower of Mages.  Flickering\n"+
	"torches cast dancing shadows across this cavernous chamber.  This is the\n"+
	SC+" where powerful magic-users evoke mystic forces to\n"+
	"thier aid.  "+CYN+"Runes"+NORM+" of "+MAG+"summoning"+NORM+" are drawn carefully on the ground.\n"+
	"There is a shimmering portal before the south wall.\n";

  dest_dir=({
	ROOM_DIR+"dragon_room",		"west",
  });

  summoner = 0;
  heart_count = 0;

}

realm(){ return "NT"; }

init(){
  ::init();
  add_action("guild_move","gm");
  add_action("enter_portal","portal");
  add_action("enter_portal", "enter");
  add_action("summon_dragon","summon");
  add_action("drop_stone","drop");
}


enter_portal(str)
{
  if(!str || str == "portal")
  {
	write("You step into the portal.\n");
	write("You are "+HIM+"magically teleported"+NORM+" back up into the Mage's Tower.\n");
	say(ME+" steps into the "+HIM+"portal"+NORM+" and "+HIC+"disappears"+NORM+".\n");
	move_object(this_player(), "players/pavlik/guild/mages/room/library");
	command("look", tp);
	say(ME+" steps out of the shimmering "+HIM+"portal"+NORM+".\n");
	return 1;
  }
}


summon_dragon(str)
{
  object ob, obj;

  if(str == "dragon")
  {
	if(!present("mageobj", tp) || !present("mageobj", tp)->query_spell_learned("summon"))
	{
		write("You have not learned the dragon summoning spell.\n");
		return 1;
	}

        ob = find_living(tp->query_real_name()+"'s dragon");
	if( ob )
	{
	  write("You summon your living dragon to your side.\n");
          move_object( ob, this_object() );
	  return 1;
	}

	ob = present("heartstone", environment(this_player()));
	if(!ob && present("heartstone", tp) && tp->query_level() < WIZLEVEL)
	{
		write("You must place the heartstone on the ground first.\n");
		return 1;
	}

	if(!ob && tp->query_level() < WIZLEVEL)
	{
		write("You don't have the proper spell components to try this.\n");
		return 1;
	}

	if(tp->query_spell_point() < 100)
	{
		write("You are too tired to attempt this right now.\n");
		return 1;
	}

	if(summoner && present(summoner, this_object()))
	{
		write("Someone else is casting a summoning spell right now.\n");
		write("You shudder at the thought of disrupting thier spell.\n");
		return 1;
	}

	write(
	  "You begin to trace the runes of summoning around the mystic "+HS+".\n");
	say(
	  ME+" begins to trace runes of summoning around the mystic "+HS+".\n");

	if(ob)
		ob->set_summon(tp->query_real_name());

	summoner = tp;
	heart_count = 0;
	set_heart_beat(1);
	return 1;
  }
}


finish_summon()
{
  object obj;

  if(!summoner || !present(summoner, this_object()))
  {
	tell_room(this_object(), "The heartstone disappears.\n");
	if(present("heartstone", this_object()))
		destruct(present("heartstone", this_object()));
	set_heart_beat(0);
	summoner = 0;
	heart_count = 0;
	return 1;
  }

  tell_room(this_object(),
    "\n" +
    SC+" glows hotly with awesome power!\n"+
    "Out of a swirling mist a "+HIC+"Magnificent Dragon"+NORM+" appears.\n"+
    "The "+HIC+"Dragon"+NORM+" bends and swallows the "+HS+" in a single bite.\n");

  if(present("heartstone", this_object()))
	destruct(present("heartstone", this_object()));

  if(!(obj = clone_object(OBJ_DIR+"dragon")))
  {
	tell_room(this_object(), "BUG: dragon clone failed.\n");
	set_heart_beat(0);
	summoner = 0;
	heart_count = 0;
	return 1;
  }

  move_object(obj, this_object());
  obj->set_owner(summoner);
  obj->configure_dragon();
  move_object(obj, this_object());
 

  tell_room(this_object(), capitalize(obj->query_name())+" bows low before "+SUMM+".\n");
  summoner->add_spell_point(-100);
  summoner = 0;
  heart_count = 0;
  set_heart_beat(0);
  return 1;
}


heart_beat()
{
  string pos;

  if(!summoner || !present(summoner, this_object()))
  {
	tell_room(this_object(), "The "+HS+" disappears.\n");
	if(present("heartstone", this_object()))
		destruct(present("heartstone", this_object()));
	set_heart_beat(0);
	heart_count = 0;
	summoner = 0;
	return 1;
  }

  pos = summoner->query_possessive();

  if(heart_count == 8)
  {
	finish_summon();
	set_heart_beat(0);
  }
  else if(heart_count == 6)
  {
	tell_room(this_object(),
	  "\n" +
	  SUMM+" clenches "+pos+" fists and thrusts "+pos+" arms toward the ceiling.\n" +
	  "The "+HS+" begins to "+HIC+"spin"+NORM+" faster and faster within the circle.\n" +
	  "The stone begins to "+MAG+"grow"+NORM+" and "+MAG+"change"+NORM+" shape ... \n");
  }
  else if(heart_count == 4)
  {
	tell_room(this_object(),
	  "\n" +
	  SUMM+" completes the "+HIB+"runes"+NORM+" and begins to chant softly.\n" +
	  "The chamber "+HIBLK+"darkens"+NORM+" and the "+HIB+"air"+NORM+" around you "+HIM+"crackles"+NORM+" with magic.\n");
  }
  else if(heart_count == 2)
  {
	tell_room(this_object(),
	  "\n" +
	  SUMM+" continues to carefully trace "+HIB+"runes"+NORM+" around the "+HS+".\n");
  }
  heart_count++;
}


drop_stone(str)
{
  if(str == "stone" || str == "heartstone")
  {
	if(!present("heartstone", this_player())) return 0;
	if(present("heartstone", this_object()))
	{
		write("There is already a "+HS+" in the circle.\n");
		return 1;
	}
	write("You place the "+HS+" in the middle of the Summoning Circle.\n");
	say(ME+" places a "+HS+" in the Summoning Circle.\n");
	transfer(present("heartstone", this_player()), this_object());
	return 1;
  }
}

