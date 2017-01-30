inherit "/obj/treasure.c";
object ob;

reset(arg)
{
  call_out("guard_summons", 60+random(120));
}

id(str) { return str == "bf_guard_timer"; }

short(){ return 0; }

drop(){               return 1; }
get() {               return 0; }
can_put_and_get(){    return 0; }

guard_summons()
{
  ob = clone_object("/players/fred/closed/bloodfist/NPC/guard1.c");
  move_object(ob, "/players/fred/closed/bloodfist/r/courtyard");
  tell_room("/players/fred/closed/bloodfist/r/courtyard",
    ob->short()+" rushes in and surveys the room...\n"); 
  move_object(this_object(), "/room/void");
  destruct(this_object());
  return 1;
}  

