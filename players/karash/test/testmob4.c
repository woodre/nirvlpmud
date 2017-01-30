
inherit "/obj/monster.c";
#include <ansi.h>

reset(arg) {
  ::reset(arg);
  if(arg) return;
   
  set_name("mob");
  set_race("critter");

  set_short("A test mob");
  set_long(
    "  A test mob.\n"+
    "  A test mob.\n");
  set_al(0);

  set_level(27);
  set_hp(1900);
  set_wc(58);
  set_ac(27);
  set_wc_bonus(26);
  set_hp_bonus(600);


  set_gender("male");
  /*set_dead_ob(this_object());*/
  set_aggressive(0);
  set_chat_chance(0);
   load_chat("chat 1.\n");
   load_chat("chat 2.\n");
   load_chat("chat 3.\n");
   
   
  }
  
  
init() {
  ::init();

  tell_room(environment(), "INIT CHECK 1\n");

  
}

heart_beat() {
    ::heart_beat();

}


void catch_tell(string str)
{
    string who, what;
	int praise, crit;
	
    if (sscanf(str, "%s says: %s\n", who, what) == 2 ||
	sscanf(str, "%s exclaims: %s\n", who, what) == 2 ||
	sscanf(str, "%s tells you: %s\n", who, what) == 2) 
	{
	 what = lower_case(what);
     tell_room(environment(),"WHO = "+who+"\n");
     tell_room(environment(),"WHAT = "+what+"\n");
      
	  if(what == "daikatana is great" || what == "daikatana was great" || what == "daikatana is awesome" || 
	     what == "daikatana was awesome" || what == "daikatana rocks" || what == "daikatana rocked" || 
		 what == "i like daikatana" || what == "i love daikatana" ||
		 what == "i liked daikatana" || what == "i loved daikatana"  )
      {
        if(this_object()->query_attack() || hit_point < max_hp)
		{
		  tell_room(environment(),"John says, 'You can't hit me and then expect I listen to your rubbish!'\n");
		}
		else tell_room(environment(),"HERE COMES ROMERO THE PROUD\n");	 
        return;		
	  }
	  else if(what == "daikatana sucks" || what == "daikatana sucked" || what == "daikatana is bad" || 
	     what == "daikatana was bad" || what == "i don't like daikatana" || what == "i do not like daikatana" || 
		 what == "i hate daikatana" || what == "i hated daikatana" ||
		 what == "i did not like daikatana" )
      {
         if(this_object()->query_attack() || hit_point < max_hp)
		{
		  tell_room(environment(),"John says, 'You can't hit me and then expect I listen to your rubbish!'\n");
		} 
		else tell_room(environment(),"HERE COMES ROMERO THE CRITICIZED\n");	  
		return;
	  }
	
    else return;
    tell_room(environment(),"SCAN CHECK 3\n");
    tell_room(environment(),"WHO = "+who+"\n");
    tell_room(environment(),"WHAT = "+what+"\n");
  }
}