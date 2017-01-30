inherit "obj/treasure";

reset(arg)  {
  if(arg) return;

   set_id("statue");
   set_short("A statue");
   set_alias("statue");
   set_long("A statue.\n");
   set_weight(100);
   set_value(0);
}

get()  { return 0; }
