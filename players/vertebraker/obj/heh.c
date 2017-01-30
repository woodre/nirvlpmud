id(str)
{
  return str=="heh";
}

init(){
  if(environment() && environment()->is_player())
  {
    environment()->RegisterWeapon(
      this_object(),
      ({
      "other|fire",
      0,
      "do_attack_special",
      })
    );
    
  }
}

int do_attack_special(){
  /* we test this out, i think this is 1000wc:)*/
  return 1000;
}

drop(){
 return 1;
}
