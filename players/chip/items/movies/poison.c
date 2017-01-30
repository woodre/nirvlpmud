#define MAX_BEATS 8
#define DAMAGE    (10 + random(10))

int beats;

id(str) { return str=="alien_poison"; }

drop() { return 1; }

start_it()
{
  set_heart_beat(1);
}

heart_beat()
{
  if(++beats == MAX_BEATS)
  {
    tell_object(environment(),
      "You overcome your sickness.\n");
    return destruct(this_object());
  }
  
  tell_object(environment(), "\
You suffer from the poison.\n");
  environment()->add_hp(-DAMAGE);
}