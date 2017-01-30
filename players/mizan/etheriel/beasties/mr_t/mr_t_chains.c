inherit "obj/armor";
reset(arg)
{
   ::reset(arg);
   if(arg) return 0;

	set_name("chains");
	set_short("50 pounds of gold chains");
	set_long("This is nearly fifty pounds of gold chains.\n"+
      "If you are holding it, you had to be helluva tough to take\n"+
      "them from its previous owner, the toughest man in the world, Mr. T.\n"+
      "Wear them with pride, hombre. They obviously were not easy to come by.\n");
	
   set_value(90000);
	set_ac(2);
	
   set_type("misc");
	set_alias("gold");
}

query_save_flag()
{
   return 1;
}