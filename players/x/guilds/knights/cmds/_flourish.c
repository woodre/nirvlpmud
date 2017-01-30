int main(string str){
  object obj;
  if(!str){
    notify_fail("What would you like to flourish?\n");
    return 0;
  }
  if(!(obj = present(str, this_player()))){
    notify_fail("You don't have \""+str+"\".\n");
    return 0;
  }
  if(!obj->id("knight_object")){
    notify_fail("You may only flourish your Coat of Arms.\n");
    return 0;
  }
  if(obj->query_flourished()){
    write("Your Coat of Arms is already flourished.\n");
    return 1;
  }
  command("bow", this_player());
  write("You display your Coat of Arms ["+(string)obj->query_emblem()+"] with a flourish.\n");
  say((string)this_player()->query_name()+" displays "+possessive(this_player())
  +" Coat of Arms ["+(string)obj->query_emblem()+"] with a flourish.\n");
  obj->set_flourished(1);
  return 1;
}
