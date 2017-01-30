inherit "/obj/armor";

reset(arg) {
  if(arg) return;
   ::reset(arg);
  set_name("helmet");
  set_short("A sturdy helmet");
  set_long(
   "  A very strong helmet ornamented with several jewels.  On one\n"+
   "side of the helmet a picture of a face in agony can be seen.\n");
  set_type("helmet");
  set_ac(2);
  set_weight(1);
  set_value(1000);
 }
drop()
  {
    write("The helmet can not be dropped.\n");
    return 1;
  }
 remove()
  {
    write("You can not remove the helmet.\n");
    return 1;
  }

do_special(USER)		/*thanks go to jaraxle for the help*/
{
   if(random(20) >= 17)
   {
      tell_object(USER,
	  "\nYou feel the helmet pull at you mentally.\n\n");
      
      if(USER->query_sp() >=10)
	{
         USER->add_sp(-5);
         return 1;
	}
      return 0;
   }
}
