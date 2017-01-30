inherit "room/room";
object birds;
object heather;
object button;

reset(arg)
{
if (!heather){
        heather = clone_object("/players/catwoman/monster/heather");
        move_object(heather, this_object());
        }
if (!birds){
	birds = clone_object("/players/catwoman/monster/birds");
	move_object(birds, this_object());
	}
if (!button){
	button = clone_object("/players/catwoman/obj/button");
	move_object(button, this_object());
	}
  if (arg) return;
  set_light(1);
  short_desc = "A dark room";
  no_castle_flag = 0;

  long_desc = "A private place for Catwoman's friends to socialize\n"+"obvious exits are study, post, church and play.\n";

}

realm() 
{
}

init ()
   {
    add_action ("post","post");
    add_action ("church","church");
    add_action ("play","play");
    return;
  }
post(){
call_other(this_player(), "move_player", "in#room/post");
return 1;
}
church(){
call_other(this_player(), "move_player", "in#room/church");
return 1;
}
play(){
call_other(this_player(), "move_player", "in#players/catwoman/play");
return 1;
}


query_light()
{
  return 1;
}


