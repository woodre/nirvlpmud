#define MAX_BEATS 8
#define DAMAGE    (27 + random(23))

int beats;

id(str) { return str=="spider_venom"; }

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
      "Your immune system suddenly fights off the vemon.\n");
    return destruct(this_object());
  }
  
  tell_object(environment(), "\
The venom burns through your veins.\n");
  environment()->add_hp(-DAMAGE);
}