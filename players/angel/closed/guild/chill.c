
/** Chill touch object **/


set_duration(d)
{
  call_out("dispel",d);
  environment()->add_tmp_str(-3);
  tell_object(environment(),"You feel your muscles weaken!\n");
}

dispel()
{
  environment()->add_tmp_str(3);
  tell_object(environment(),"You feel strong again.\n");
  destruct(this_object());
}
