inherit "obj/treasure";
 reset(arg)
{   if (arg) return;
   set_id("ugly");
   set_short();
   set_long();
   call_out("bye", 1000);
}
 bye()  {
  destruct(this_object());
        }
 extra_look()  {
object ex_look;
  ex_look = environment(this_object())->query_name();
  write(ex_look+" must have been whacked with an ugly stick!  FRIGHTFUL!\n");
        }
 drop()  { return 1; }
