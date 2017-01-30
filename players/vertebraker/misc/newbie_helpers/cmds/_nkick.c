int main(string str)
{
  object obj, gob;
  
  if((string)this_player()->query_real_name() != "lacar")
    return 0;
  
  if(!str) {
    write("Kick out who as a Newbie Helper?\n");
    return 1;
  }
  
  if(!(obj = find_player(str))) {
    write("You don't see \""+str+"\".\n");
    return 1;
  }
  
  if(!(gob=present("newbie_helper", obj))) {
    write((string)obj->query_name()+" is NOT a newbie helper!\n");
    return 1;
  }

  write("Ok, booted "+capitalize(str)+" as a Newbie Helper!\n");
  destruct(gob);
  tell_object(obj, "Sad days. You are no longer a Newbie Helper. :(\n");
  return 1;
}
