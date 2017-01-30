int main(string str){
  object obj;
  if(!str){
    notify_fail("What would you like to unflourish?\n");
    return 0;
  }
  if(!(obj = present(str, this_player()))){
    notify_fail("You don't have \""+str+"\".\n");
    return 0;
  }
  if(!obj->id("knight_object")){
    notify_fail("You may only unflourish your Coat of Arms.\n");
    return 0;
  }
  if(!obj->query_flourished()){
    write("Your Coat of Arms isn't currently flourished.\n");
    return 1;
  }
  command("bow", this_player());
  write("You remove your Coat of Arms from its prominent position.\n");
  say((string)this_player()->query_name()+" removes "+possessive(this_player())
  +" Coat of Arms from its prominent position.\n");
  obj->set_flourished(0);
  return 1;
}
