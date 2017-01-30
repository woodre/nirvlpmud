inherit "obj/treasure";
int level;
static int startedcallout;

reset(arg)
{
  if(arg) return;
  level = 1;
  set_save_flag(1);
/* ld don't like this in preloads... move to init -Bp
  call_out("ouch", 25);
*/
}

init() {
  if(!startedcallout) {
    startedcallout = 1;
    call_out("ouch", 25);
  }
}
id(str){   return str == "poison" || str == "scorpion_z_p";  }
long(){ return 0; }
short(){ if(this_player()->query_real_name() == "zeus")
         return "poison: ["+level+"]"; }
query_auto_load()
{ 
	return "/players/zeus/desert/OBJ/scorpion_poison.c:"; 
}
drop(){
  if(environment() && environment()->query_ghost())
	  destruct(this_object());
  else 
	  return 1; 
}

get(){  return 0; }
can_put_and_get(){   return 0;  }
query_level(){ return level; }
add_level(x){ level += x; }
set_level(x){ level = x; }

ouch()
{
  if(!environment())
    return;
  if(!environment()->is_player())
  {
    destruct(this_object());
    return;
  }
environment()->hit_player((level * -1), "other|poison");
  tell_object(environment(), "The venom from the scorpion burns...\n");
  level -= 2+random(4);
  if(environment()->query_hp() <= 0)
  {
    environment()->hit_player(66, "other|poison");
    destruct(this_object());
    return;
  }
  if(level <= 0)
  {
    tell_object(environment(), 
      "The venom from the scorpion leaves your system...\n");
    destruct(this_object());
    return;
  }
  call_out("ouch", 22+random(18));
}

