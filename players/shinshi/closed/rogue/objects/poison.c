#define MAX_BEATS 4
#define DAMAGE 20 + random(9)

int beats;
int damage;

id(str) { return str=="poison_damage_yo"; }

drop() { return 1; }

start_it()
{
  set_heart_beat(1);
}

heart_beat()
{
  object ob;
  
  ob = environment();
  if(++beats == MAX_BEATS)
  {
    tell_object(ob,
      "You feel the poison exit your body.\n");
    return destruct(this_object());
  }
  
  tell_object(ob, "\
You double over as the poison sears your blood.\n");
  tell_room(environment(ob), "\
"+ob->query_name()+" doubles over in pain as the poison sears their blood.\n");
  ob->do_damage(DAMAGE);
}

/*ob->add_hp(-damage);*/