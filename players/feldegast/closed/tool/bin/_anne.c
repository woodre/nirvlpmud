do_cmd(str) {
  object *list;
  int i;
  list=users();
  for(i=0; i < sizeof(list); i++) {
    tell_object(list[i],"\nA bottle of cabernet savignon falls out of the sky and lands in your hands.\n\n");
    write("You give a bottle of wine to "+list[i]->query_name()+".\n");
    move_object(clone_object("/players/feldegast/heals/anniversary.c"), list[i]);
  }
  return 1;
}
