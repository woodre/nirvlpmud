#define MAX_BEATS 8
#define DAMAGE    (20 + random(20))

int beats;

id(str) { return str=="alien_blood_poison"; }

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
      "The burning from the "+HIG+"blood"+NORM+" has subsided.\n");
    return destruct(this_object());
  }
  
  tell_object(environment(), "\
The alien's blood burns you intensely!\n");
  environment()->add_hp(-DAMAGE);
}