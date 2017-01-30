#define MAX_BEATS 17
#define DAMAGE    (15 + random(20))

int beats;

id(str) { return str=="constrict"; }

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
      "The huge snake slowly releases its hold on your weakened body.\n");
    return destruct(this_object());
  }
  
  tell_object(environment(), "\
You try to breathe, but cannot. The snake tightens its grip on you slightly.\n");
  environment()->add_hp(-DAMAGE);
}