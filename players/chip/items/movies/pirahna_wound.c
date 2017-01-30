#define MAX_BEATS 10
#define DAMAGE    (20 + random(20))

int beats;

id(str) { return str=="pirahna_wound"; }

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
      "The deep bite in your skin "+RED+"scabs"+NORM+" over.\n");
    return destruct(this_object());
  }
  
  tell_object(environment(), "\
The gaping bite in your body pours out blood!\n");
  environment()->add_hp(-DAMAGE);
}