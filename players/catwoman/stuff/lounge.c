inherit "room/room";
object cat1;

reset(arg)
{
 /* if (!cat1){
        cat1 = clone_object("/players/catwoman/monster/cat1");
        move_object(cat1, this_object());
        }
  if (arg) return;
*/
  set_light(1);
  short_desc = "The Lounge";
  no_castle_flag = 0;

  long_desc = "A private place for Catwoman's friends to socialize\n"+"obvious exits are study, post, church and play.\n";

}

realm() 
{
/*       return "NM"; */
/*       return "NT"; */
}

init ()
   {
    add_action ("study","study");
    add_action ("post","post");
    add_action ("church","church");
    add_action ("play","play");
    return;
  }
study(){
call_other(this_player(), "move_player", "in#players/catwoman/study");
return 1;
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


