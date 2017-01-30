inherit "room/room";


reset(arg)
{
  if (arg) return;

  set_light(1);
  short_desc = "A large room";
  no_castle_flag = 0;
                                                         
  long_desc = "A hall of doors: SHOP, PUB, RUINS, superHERO, BLACK Chamber,\n"+
              "BOARDwalk, POST office, NEXUS, ADVANCE guild, revenge SHOP2,\n"+
              "LOCKERS, CHURCH, ANGEL, and WEST to where you came from.\n"+
              " (more to come mail requests to Catwoman).\n";
/*  dest_dir =
   ({ "players/catwoman/floor1/1", "north",
      "players/catwoman/floor1/2", "east",
      "players/catwoman/floor1/3", "west", });*/
}

init ()
   {
  /*  if(!present("thief guild", this_player())) {*/
  /*	write("You are not a Thief. However You could resign your guild and join us!\n");*/
  /*	move_object(this_player(),"players/catwoman/hall2");*/
  /*	return 1;*/
  /*	}*/
    add_action ("shop","shop");
    add_action ("pub","pub");
    add_action ("ruins","ruins");
    add_action ("angel","angel");
    add_action ("church","church");
    add_action ("nexus","nexus");
    add_action ("west","west");
    add_action ("guild","board");
    add_action ("post","post");
    add_action ("advance","advance");
    add_action ("lockers","lockers");
    add_action ("shop2","shop2");
    add_action ("hero","hero");
    add_action ("black","black");
    return;
  }
angel()
{
    write("The door opens.\n");
     call_other(this_player(), "move_player", "angel#/room/south/sforst45");
     return 1;
}
nexus()
 {
     write("The door opens.\n");
     call_other(this_player(), "move_player", "nexus#/players/snow/gate");
     return 1;
 }
shop()               
 {
    write("The door opens.\n");
    call_other(this_player(), "move_player", "shop#/players/catwoman/tshop");
    return 1;
 }
pub()               
 {
    write("The door opens.\n");
    call_other(this_player(), "move_player", "pub#room/pub2");
    return 1;
 }
ruins()               
 {
    write("The door opens.\n");
    call_other(this_player(), "move_player", "ruins#room/plane3");
    return 1;
 }
west()               
 {
    write("The door opens.\n");
    call_other(this_player(), "move_player", "west#players/catwoman/road2");
    return 1;
 }

hero()
 {
	write("The door opens.\n");
	call_other(this_player(), "move_player", "hero#players/catwoman/city/2");
	return 1;
 }
/*
lounge()               
 {
    write("The door opens.\n");
    call_other(this_player(), "move_player", "in#players/catwoman/lounge");
    return 1;
  }
*/
guild()               
 {
/*
if(!present("thief guild",this_player())){
write("you are not a thief!!!!\n");
return 1;
}
*/
    write("The door opens.\n");
    call_other(this_player(), "move_player", "board#players/catwoman/city/19");
    return 1;
  }
post()               
 {
    write("The door opens.\n");
    call_other(this_player(), "move_player", "post#room/post");
    return 1;
 }
church()               
 {
    write("The door opens.\n");
    call_other(this_player(), "move_player", "church#room/church");
    return 1;
 }
advance()               
 {
    write("The door opens.\n");
    call_other(this_player(), "move_player", "advance#room/adv_guild");
    return 1;
 }
lockers()               
 {
    write("The door opens.\n");
    call_other(this_player(), "move_player", "lockers#players/catwoman/tl");
    return 1;
 }
shop2()               
 {

    call_other(this_player(),"move_player", "shop2#players/catwoman/ts");
    return 1;
 }
black()
 {
    call_other(this_player(),"move_player", "black#players/saber/ryllian/portal");
    return 1;
 }
query_light()
 {
  return 1;
 }

 
