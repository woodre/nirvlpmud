inherit "obj/treasure";
 reset(arg)  {
  if(arg) return;
    set_id("orange");
   set_short("An Orange");
   set_long("This appears to be some kind of orange.\n"+
     "I believe it was lost somewhere on the internet....\n");
   set_weight(0);
   set_value(0);
}
