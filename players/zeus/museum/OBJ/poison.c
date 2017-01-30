inherit "obj/treasure";
object wep;
string xy;
static int startedcallout;

reset(arg)
{
  if(arg) return;
  set_weight(0);
  set_value(0);
  set_save_flag(1);
 /* ld don't like call_outs in reset -Bp
  call_out("mommy", 18);
*/
}

init() {
 if(!startedcallout) {
   call_out("mommy", 18);
   startedcallout = 1;
 }
}
id(str)
{ 
  return str == "poison" || str == "bs_z_p"; 
}

query_auto_load()
{ 
	return "/players/zeus/museum/OBJ/poison.c:"; 
}

drop()
{
  if(environment() && environment()->query_ghost())
	  destruct(this_object());
  else 
	  return 1; 
}

get()
{
  return 0; 
}

can_put_and_get()
{ 
  return 0; 
}

mommy()
{
  if(!environment())
	return;
  if(!environment()->is_player()){ destruct(this_object());
  return; }
  if(!sscanf(file_name(environment(environment())), 
    "players/zeus/museum/arena/%s", xy)){
    tell_object(environment(), "Your poison is gone.\n");
    destruct(this_object()); return;
  }
  if(!random(3))
  {
	tell_object(environment(), "Your stomach is gripped with pain!\n");
  }
  else if(!random(6))
  {
	wep = environment()->query_weapon();
	if(wep && !wep->drop())
	{
	  tell_object(environment(), "You grab your stomach in pain...\n"+
		                         "Your weapon falls to the ground.\n");
	  wep->drop();
	  move_object(wep, environment(environment()));
	}
  }
  environment()->hit_player(25+random(15));
  environment()->add_spell_point(-random(40));
  call_out("mommy", 12+random(18));
}

