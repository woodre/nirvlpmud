 inherit "obj/treasure";
 reset(arg)  {
  if(arg) return;
    set_id("horseshoe");
   set_short("A Silver Horseshoe");
   set_long("A horseshoe finely crafted of silver.\n"+
     "You think that it may be valuable.\n");
   set_weight(1);
   set_value(400);
}
