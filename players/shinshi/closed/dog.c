#include <ansi.h>

inherit "obj/monster";

static object Remembered;
object owner;
int stay;

reset(arg) {
   ::reset(arg);
   if(!arg) {
      set_name("dog");
      set_alias("wicketdoggy");
      set_short("A vicious fucking dog");
      set_race("canine");
      set_long(
      	 "This dog will bite your nuts off\n");
      set_level(1);
      set_hp(35000);
      set_ac(60);
      set_wc(1);
      set_heal(35000,1);
      set_al(0);
      set_dead_ob(this_object());
      set_chance(25);
      if(!root()) call_out("chase", 2);
    }
}

grab_exit()
{
  string *exits, *rand;
  int    x, y;
  exits = environment()->query_dest_dir();
  y     = sizeof(exits);
  rand = ({ });
  for(x = 1; x < y; x += 2)
  {
    rand += exits[x];
  }
  return rand[random(sizeof(rand))];
}

heart_beat()
{
	if(root()) return;
	if(!owner) return;
	::heart_beat();
	
	if(owner && stay != 1)
	{
		if(environment(this_object()) != environment(owner))
		{
			say("The dog follows after "+capitalize(owner->query_name())+".\n");
			move_object(this_object(), environment(owner));
			set_heart_beat(1);
		}
	}
	
	if(attacker_ob)
	{
		Remembered = attacker_ob;
	}
}

chase()
{
  object ob;
  object env;
  if((!attacker_ob || !present(attacker_ob, environment())) && (ob = Remembered))
  {
    if(!present(ob, environment()))
    {
      env = environment(ob);
      tell_room(env,
        query_name()+" comes running into the room, chasing "+ob->query_name()+"!\n");
      move_object(this_object(), env);
      attack_object(ob);
    }
  }
  call_out("chase", 2);
}

monster_died()
{
	object tool;
	
	tool = present("az2009chipblowsdick", find_player("wicket"));
	
	tool->set_doggypresent(0);
	return 1;
}


set_stay(int x) { stay = x; }
query_stay() { return stay; }
patch_owner(o) { owner = o; }