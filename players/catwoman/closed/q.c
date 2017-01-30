inherit "room/room";
object man;

reset(arg)
{
if (!man) {
	man = clone_object("/players/catwoman/monster/man");
	move_object(man, this_object());
}
  if (arg) return;

  set_light(1);
  short_desc = "---A tunnel---";
  no_castle_flag = 0;
                                                         
  long_desc = "\n"+"obvious exit is west.\n";

}

init ()
   {
/*    add_action ("north"); add_verb ("north");
    add_action ("west"); add_verb ("west");*/
    add_action ("west","west");
    return;
  }
catch_tell(str){
string next_out;
object next_dest;
object from;
string a;
string b;
string c;
from =this_player();

if (!from)
	return; 
	if (sscanf(str, "%s gives %s to Man.", a, b) == 2){
	object ob;
	ob = present(b, this_object());
	if (!ob || !call_other(ob, "id", "chisel"))
		return;
	next_out = "Man says: I was wondering where I put that.  You've earned your reward.\n";
	next_dest = from;
	set_heart_beat(1);
	call_other(from, "set_quest", "chisel");
	destruct(ob);
	return;
	}
}
west(){
call_other(this_player(), "move_player", "west#players/catwoman/21");
return 1;
}

query_light()
{
  return 1;
}

 

