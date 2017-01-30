#define MAX_BEATS 3
#define DAMAGE 30

int beats;
int damage;

id(str) { return str=="bleed_damage_yo"; }

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
      "Your wound stops bleeding and seals up.\n");
    return destruct(this_object());
  }
  
  tell_object(ob, "\
Your blood pours out of your open wound.\n");
  tell_room(environment(ob), "\
"+ob->query_name()+"'s blood pours from the open wound.\n");
  ob->do_damage(DAMAGE);
}

/*ob->add_hp(-damage);*/