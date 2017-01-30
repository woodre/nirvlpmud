int main(string str)
{
  object obj;
  
  if((string)this_player()->query_real_name() != "lacar")
    return 0;
  
  if(!str) {
    write("Add who as a Newbie Helper?\n");
    return 1;
  }
  
  if(!(obj = find_player(str))) {
    write("You don't see \""+str+"\".\n");
    return 1;
  }
  
  if(present("newbie_helper", obj)) {
    write((string)obj->query_name()+" is already a newbie helper!\n");
    return 1;
  }

  if((int)obj->query_level() >= 21) {
    write("Wizards don't make Newbie Helpers.\n");
    return 1;
  }
  if((string)obj->query_guild_name()=="shardak"){
    write("Uh.\n");
    return 1;
  }
  write("Ok, added "+capitalize(str)+" as a Newbie Helper!\n");
  move_object(clone_object("/players/vertebraker/misc/newbie_helpers/noob"),
    obj);
  tell_object(obj, "Happy Happy Joy Joy! You are now a Newbie Helper!\n");
  return 1;
}
