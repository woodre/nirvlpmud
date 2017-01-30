inherit "room/room";

object stonedragon;
reset(arg)
{
  if (!stonedragon) {
	stonedragon = clone_object("obj/monster.talk");
	call_other(stonedragon,"set_name","dragon");
	call_other(stonedragon,"set_level",20);
	call_other(stonedragon,"set_short","A Stone Dragon");
	call_other(stonedragon,"set_long","Its big and made of stone.\n");
	call_other(stonedragon,"set_al",0);
	call_other(stonedragon,"set_race","stonedragon");
	call_other(stonedragon,"set_agressive",0);
	call_other(stonedragon,"set_hp",5000);
	call_other(stonedragon,"set_wc",35);
	call_other(stonedragon,"set_ac",20);
	call_other(stonedragon,"set_alias","dragon");
	call_other(stonedragon,"add_money",2000);
	move_object(stonedragon, this_object());
	}
  if (arg) return;

  set_light(1);
  short_desc = "---A tunnel---";
  no_castle_flag = 0;
                                                         
  long_desc = "A tunnel\n"+"obvious exits are east and west.\n";

}

init ()
   {
/*    add_action ("north"); add_verb ("north");*/
    add_action ("west","west");
    add_action ("east","east");
    return;
  }
west(){
call_other(this_player(), "move_player", "west#players/catwoman/19");
return 1;
}
east(){
if(present("stonedragon",this_object())){
	write ("the statue blocks your way.\n");
	return 1;
	}
call_other(this_player(), "move_player", "east#players/catwoman/24");
return 1;
}


query_light()
{
  return 1;
}


