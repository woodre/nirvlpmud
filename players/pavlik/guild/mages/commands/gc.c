#include "/players/pavlik/guild/mages/defs.h"
inherit "players/pavlik/guild/mages/inherit/command";

reset(arg) {
  if(arg) return;
  set_verb("gc");
  set_name("Guild Channel");
  set_color_name(HIC+"Guild Channel"+NORM);
  set_rank(1);
  set_descrip(
	"Toggle the Guild Channel on and off.\n" +
	"See Also: gt\n"
  );
}


cmd(str)
{
  if(!str && guild->query_muffled() == 0){
	write("You will no longer hear the guild channel.\n");
	guild->set_muffled(1);
  CHAND->remove_channel( CHAN_NAME, this_player() );
	return 1;
  }
  if(!str && guild->query_muffled() == 1){
	write("You will now hear the guild channel.\n");
	guild->set_muffled(0);
  CHAND->add_channel(CHAN_NAME, this_player() );
	return 1;
  }
  if(str == "off"){
	write("You will no longer hear the guild channel.\n");
	guild->set_muffled(1);
  CHAND->remove_channel( CHAN_NAME, this_player() );
	return 1;
  }
  if(str == "on"){
	write("You will now hear the guild channel.\n");
	guild->set_muffled(0);
  CHAND->add_channel(CHAN_NAME, this_player() );
	return 1;
  }
}
 
