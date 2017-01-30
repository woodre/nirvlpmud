#define MAX_BEATS 12
#define DAMAGE    (10 + random(20))

int beats;

id(str) { return str=="rabies"; }

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
      "The effects of the rabies virus subside.\n");
    return destruct(this_object());
  }
  
  tell_object(environment(), "\
The rabies in your bloodstream drives you mad, causing you to punch yourself in the head.\n");
  environment()->add_hp(-DAMAGE);
}