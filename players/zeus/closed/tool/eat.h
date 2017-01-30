
int eat(string str){
  object p;
  if(!str) return 0;
  if(!(p = (present(str, environment(this_player()))))) return 0;
  if(p == this_player()) return 0;
  write("You eat "+p->query_name()+".\n");
  say(this_player()->query_name()+" grabs "+p->short()+" and eats "+p->short()+".\n");
  move_object(p, this_player());
  return 1;
}

