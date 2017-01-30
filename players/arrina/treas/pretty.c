inherit "obj/treasure";
 reset(arg)
{   if (arg) return;
   set_id("pretty");
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
  write(ex_look+" must have been swatted with a pretty paddle!  CUTE!\n");
        }
 drop()  { return 1; }
