#include "/players/boltar/things/esc.h"
reset(arg) {
        if(arg) return;
}

id( str ) {
        if(str=="fixer") return 1;
        return 0;
}

long() {
         write( "This is a guild fixer, if you are an Undead and u lost your life\n"+
		"type 'rejoin' to get your guild object back.\n");
}

short()
  { return esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40mUndead"+esc+"[0m"+" Guild Fixer"; }
init()
{
  add_action( "fix","rejoin");
}
fix()
{ object this,life;
  this=this_player();
  if(this->query_guild_name()!="undead")
   {
	write("You are not an Undead, forget about it!\n");
	return 1;
   }
  if(present("soul-undead",this))
   {
	write("You already have a life!!!\n");
	return 1;
   }
  life=clone_object("/players/hurtbrain/life");
  move_object(life,this);
  command("renew",this);
  return 1;
}  
get() {
        return 0;
}
drop() {
        return 0;
}
