 inherit "obj/treasure";
 reset(arg)  {
  if(arg) return;
    set_id("cup");
   set_short("A Silver Cup");
   set_long("A cup, handcrafted of fine silver.\n"+
     "You think that it would be worth a few coins.\n");
   set_weight(0);
   set_value(35);
}
