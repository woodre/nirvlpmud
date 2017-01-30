inherit "/obj/armor";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("amulet");
  set_short("A glistening amulet");
  set_long(
   "  A small charm that becomes embedded in the owner's chest.  A\n"+
   "small onyx with a symbol of a hand with a drop of blood falling\n"+
   "is engraved on the top of the gem.\n");
  set_type("amulet");
  set_ac(2);
  set_weight(1);
  set_value(1000);
 }
 drop()
  {
    write("The amulet can not be dropped.\n");
    return 1;
  }
 remove()
  {
    write("You can not remove the amulet.\n");
    return 1;
  }

do_special(USER)		/*thanks go to jaraxle for the help*/
{
   if(random(20) >= 10)
   {
      tell_object(USER,
	  "\nYou feel a jolt from the amulet.\n\n");
      
      if(USER->query_hp() >=10)
	{
         USER->add_hp(-7);
         return 1;
	}
      return 0;
   }
}

