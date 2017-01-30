#include "/players/pavlik/guild/mages/defs.h"

#define INSIDE_ROOMS ({"top", "join", "party", "bar", "vault", "library", "train", "shop",\
                       "spell", "advance", "lobby", "summon",  })
#define INSIDE_DEST ({ "guild_room5", "join_room", "party_room", "mage_bar", "vault_room",\
                       "library", "train_room", "mage_shop", "ante_room", "ante_room",\
                       "mage_lobby", "summon_room", })
mage_check(){
  if(present("mageobj_OLD", tp))
  {
	write("You feel a shift in the world around you.\n");
	move_object(tp, "players/pavlik/guild/mages/rooms/guild_room5");
	return 0;
  }
  return 1;
}

/*
  object obj;

  if(this_player()->query_npc() == 0){

    if(this_player()->query_mage_pet() == 1){
      return 1;
    }

    if(this_player()->query_guild_name() != "mage"){
      if(this_player()->query_level() > 20) {
        write("Okay, your a wiz so you can stay.\n");
        write("Doesn't mean I have to be happy about it though.\n");
        return 1;
      }
      write(
      "A huge hand spring from the floor and wraps around your body.\n"+
      "With a mighty pull the magical hand pulls you down into the\n"+
      "floor!  When you can see again, you discover you are being held\n"+
      "about 500 feet above the ground!  The hand lets you go and you\n"+
      "tumble back to the earth.\n"+
      "THUD!\n");
      say("A huge hand springs from the floor and grabs "+
      capitalize(this_player()->query_real_name())+"!\n"+
      "The hand yanks its surprised victim into the ground!\n"+
      capitalize(this_player()->query_real_name())+" is gone.\n");
      move_object(this_player(), "players/pavlik/guild/mages/rooms/tower");
      return 1;
    }
    if(this_player()->query_guild_name() != "mage"){
      this_player()->set_guild_name("mage");
    }
    if(!present("mageobj", this_player())){
      obj = clone_object("players/pavlik/guild/mages/mageobj2");
      move_object(obj, this_player());
      command("renew", this_player());
    }
  }
}
*/

guild_move(str)
{
  int idx;
  object obj;
  string who;

  if(!str)
  {
	list_gm_destinations();
	return 1;
  }

  obj = this_player();
  who = capitalize(obj->query_name());

  idx = member( INSIDE_ROOMS, str );
  if( idx >= 0 ) {
    move_object(obj, ROOM_DIR+INSIDE_DEST[idx]);
  }
  idx = member( OUTSIDE_ROOMS, str );
  if( idx >= 0 ) {
    move_object(obj, OUTSIDE_DEST[idx] );
  }
  if(str == "council"){
	if(tp->query_guild_rank() > MAXGUILDRANK)
		move_object(obj, ROOM_DIR+"council_room");
  }
  if(str == "who")
  {
	local_mages();
	return 1;
  }
  if(find_player(str) && find_player(str)->query_invis() < 1)
  {
	goto_mage(str);
	return 1;
  }
  if(present(obj, this_object()))
  {
	write("Guild Move: Destination Unreachable.\n");
	return 1;
  }

  write(
    "You concentrate briefly and the walls around you glow with magical energy.\n"+
    "You are magically teleported across space.\n");

  if(str == "council"){
	write("\n"+
	"You feel different as your body is transported beyond the normal "+
	"universe.\n\n");
  }
  command("look", obj);
  tell_room(this_object(),
  who+" concentrates briefly and disappears.\n");
  say(who+" suddenly appears.\n");
  return 1;
}


local_mages()
{
  object ob;
  int i;
  string where;

  write("\n");
  write("---------------------------------------------------\n");
  ob = users();
  for(i=0; i<sizeof(ob); i++){
    if(ob[i]->query_invis() < 20){
    if( (environment(ob[i])) &&
        (environment(ob[i])->query_mguild() != 0) ){
      write("- "+ob[i]->query_name()+"\t\t\t["+
      environment(ob[i])->query_mguild()+"]\n");
    }
    }
  }
  write("---------------------------------------------------\n");
  return 1;
}


goto_mage(str)
{
  object obj;
  string where, jack;

  obj = find_player(str);
  jack = capitalize(this_player()->query_name());
  
  if(!obj)
	return 0;

  if(environment(obj)->query_mguild() == 0)
  {
	write("You cannot guild move to this person.\n"+
	capitalize(str)+" is beyond the walls of the Tower.\n");
	return 1;
  }

  where = environment(obj)->query_mguild();

  if(where == "War Room" || where == "Council Room")
  {
	write("Sorry, you cannot guild move to this person.\n");
	return 1;
  }

  write("You concentrate briefly and teleport across space.\n");
  say(jack+" concentrates briefly and disappears.\n");
  move_object(this_player(), environment(obj));
  command("look", this_player());
  say(jack+" suddenly appears.\n");
  return 1;
}


list_gm_destinations()
{
  int i, siz;

  write(
   "Places to go:\n"+
   CYN+"Outside the tower:"+NORM+" ");

  siz = sizeof(OUTSIDE_ROOMS);
  for( i=0; i < siz; i++ ) {
    write( OUTSIDE_ROOMS[i] + ( siz - i > 1 ? ", " : "" )  );
    if( i%6 == 5 )
      write( "\n"+pad("",19) );
  }
  write("\n");
  write( CYN+"Inside the tower :"+NORM+" ");

  siz = sizeof(INSIDE_ROOMS);
  for( i=0; i < siz; i++ ) {
    write( INSIDE_ROOMS[i] + ( siz - i > 1 ? ", " : "" )  );
    if( i%5 == 4 )
      write( "\n"+pad("",19) );
  }
  write("\n");
  
  write( CYN+"Also:"+NORM+" <player>\n" +
  "      ('gm who' lists all players in the tower)\n"+
  "\n");
  return 1;
}
