main(object user, object wep, string name, string short){
  if(!user->query_attack()) return;
  tell_object(user, "It works!\n");
  tell_room(environment(user), "woo.\n", ({ user }));
  return 1;
}