id(str){return str=="goto";}

init(){
 add_action("goto","goto");
}

goto(str)
{
  object ob;
  if(!str || !(ob=find_player(str))) return 0;
  move_object(this_player(), environment(ob));
  return 1;
}

drop() { return 1; }
get() { return 1; }
