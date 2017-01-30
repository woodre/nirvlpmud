#define MAX_BEATS 2
#define DAMAGE 15

int beats;
int damage;

id(str) { return str=="poison_damage_yo2"; }

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
 "+ob->query_name()+" screams in agony as the poison sears through their blood stream!\n");
  ob->do_damage(DAMAGE);
}