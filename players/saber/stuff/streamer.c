inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("streamer");
   set_short("a streamer");
   set_long("A multicolored streamer.\n");
   set_weight(0);
   set_value(1);
   call_out("bye", 120);
}

bye()  {
  destruct(this_object());
        }
