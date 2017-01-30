/* Fleas! */

extra_look() {
  return environment()->query_name()+" looks rather uncomfortable";
}

id(str) {
  return str=="flea_obj";
}

init() {
  while(remove_call_out("scratch")!= -1) ;
  call_out("scratch",9+random(20));
}

scratch() {
  string str;
  if(!environment() || !environment()->is_player())
    destruct(this_object());
  switch(random(3)) {
    case 0: str=environment()->query_name()+" scratches "+environment()->query_objective()+"self.\n";
            break;
    case 1: str=environment()->query_name()+" fidgets uncomfortably.\n";
            break;
    case 2: str=environment()->query_name()+" gives "+environment()->query_possessive()+" head a good scratch.\n";
            break;
  }
  tell_room(environment(environment()),str);
  call_out("scratch",10+random(30));
}

drop()  { return 1; } /* Cannot drop */
get()   { return 0; } /* Cannot get */

  