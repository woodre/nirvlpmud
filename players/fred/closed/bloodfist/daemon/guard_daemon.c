static int num;
object ob;

reset(arg){
  if(arg) return;
  num = 0;
  call_out("guard_check", 10);
}

guard_death()
{
 num += 1;
}

guard_check()
{
  if(num > 1)
  {
    ob = clone_object("/players/fred/closed/bloodfist/obj/guard_timer.c");
    move_object(ob, "/players/fred/closed/bloodfist/r/courtyard.c");
    num = 1;
  }
  call_out("guard_check", 10);
}
     
