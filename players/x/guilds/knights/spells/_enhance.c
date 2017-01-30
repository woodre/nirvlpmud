int main(string str){
  if(!str) {
    write("Enhance what ?\n");
  }
  else {
    object shld;
    string shld_nm;
    
    if(!(shld = present(str, this_player()))){
      write("You do not have \""+str+"\".\n");
    }
    shld_nm = (string)shld->query_name();
    else if(!shld->is_armor() || 
           (string)shld->query_type() != "shield"){
      write(shld_nm+" is not a shield.\n");
    }
    else if(shld->query_worn()){
      write("You must first remove "+shld_nm+".\n");
    }
    else {
      string shd;
      object sh;
      
      shd = (string)shld->short();
      
      write("You cast \"enhance shield\" upon "+shd+".\n");
      say((string)this_player()->query_name()
        +" casts \"enhance shield\" upon "+shd+".\n");
      if(shld->knight_enhanced()){
        shld->stop_enhance_shadow();
      }
      
      sh = clone_object("\
/players/x/guilds/knights/obj/enhance_shadow");
      sh->start_enhance_shadow(shld);
    }
  }
  return 1;
}
      