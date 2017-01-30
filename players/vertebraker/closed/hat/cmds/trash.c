int main(string str)
{
  object ob;
  if(str && (ob = find_player(str)))
  {
    move_object(ob, present("trashcan", find_object("/room/vill_green")));
    tell_room(environment(ob), "Garbageman arrives.\n");
    tell_room(environment(ob), "Garbageman looks at "+(string)ob->query_name()+"\n");
    tell_room(environment(ob), "Garbageman dumps "+(string)ob->query_name()+" into a trashcan.\n");
    write("Done.\n");
    return 1;
  }
  write("Wrong move Pal!\n");
  return 1;
}
