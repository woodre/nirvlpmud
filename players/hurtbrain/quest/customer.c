inherit "obj/monster";
reset(arg){
        object ob1, ob2, ob3 ,gold;
        ::reset(arg);
   if(arg) return;
	set_short( "The customer") ;
        set_long("This is the customer. If you want to start the quest you\n"+
		 "have to give him the passport.\n") ;
        set_name ("customer") ;
        set_gender( "male") ;
        set_level(21);
        set_hp(5000);
  	set_al(200);
  	set_wc(32);
  	set_ac(18);
        set_race("human") ;
        set_chat_chance (25);
        load_chat("Customer says: 'Passport, give me your passport!'\n");
        load_chat("Customer yell: 'Hey, where are you going?'\n");
}
catch_tell(str)
{
  object obj,from;
  object who,what,wh2;
  string a;
  string b;
  string c;
  from = this_player();
  if (!from)
    return;     /* Not from a real player. */
    if (sscanf(str, "%s gives passport %s Customer.", a, b) == 2) {
        who = present("passport", this_object());
	if(!who)
		{
		write("Customer says: 'Hey, don't joke guy!'\n");
		return 1;
		}
	if(call_other(who,"short") == "A true passport")
		{
		write("Ok Mr. Bond..You can pass. Have cool holidays.\n");
		write("Ah...someone left 100 $ for you. Here they are.\n");
		obj=clone_object("/players/hurtbrain/quest/dollars.c") ;
		move_object(obj,this_player());
		destruct(who);
		return 1;
		}
	else if(call_other(who,"short") == "A false passport")
		{
		write("Someone left 100 $ for you. Here they are.\n");
		obj=clone_object("/players/hurtbrain/quest/dollars.c") ;
		move_object(obj,this_player());
		write("But.. but this passport is false!! Ok man..prison waits for you!\n");
		write("The guards get your armors and weapons\n");
		what = first_inventory(this_player());
		if(what)  {
			while(what)  {
				wh2=next_inventory(what);
				if((call_other(what,"weapon_class"))+(call_other(what,"armor_class"))!=0)
					move_object(what,"/players/hurtbrain/quest/prison4.c");
				what=wh2;
				}
			}
		move_object(this_player(),"/players/hurtbrain/quest/prison.c");
		command("look",this_player());
		destruct(who);
		return 1;
  		}
	}
}
