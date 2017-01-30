#include <ansi.h>

cmd_devour(str)
{
  object obj;
  if(this_player()->query_guild_rank() < 1) return 0;
  if(!str) {
    write("What do you wish your followers to devour?\n");
	return 1;
  }
  if(this_player()->query_ghost()) return 0;
  if(environment(this_player())->query_light() > 0) {
    write("It is too bright to summon your followers.\n");
	return 1;
  }
  if(!(obj = present(str, environment(this_player())))) {
    write("There is no \""+BOLD+str+NORM+"\" present.\n");
	return 1;
  }
  if(!obj->is_corpse()) {
    write("Presently your followers can only devour corpses!\n");
	return 1;
  }
  write("You close your eyes and concentrate fully on your parish.\n"+
        "Suddenly dozens of your followers converge on "+obj->short()+",\n"+
		"ripping it to shreds. You feed off of their bloodlust and malice!\n");
  say(this_player()->query_name()+" closes "+possessive(this_player())+" eyes in deep concentration.\n"+
      "Suddenly dozens of dark forms swarm on "+obj->short()+",\n"+
	  "ripping it to shreds. "+this_player()->query_name()+" seems to feed on the savagery!\n");
  this_player()->add_sp(obj->heal_value());
  this_player()->set_alignment(this_player()->query_alignment() - obj->heal_value());
  destruct(obj);
  return 1;
}
