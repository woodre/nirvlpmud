#define cap(str) capitalize(str)
id(str){ return str == "master ring"; return 1;}
short() { return "Master ring"; }
long() { write("This is the master wedding ring.  It is  enables the you to:\n"+
               "        marry <who> <who>       replace <who> <spouse>\n");
         return 1;
}
drop() { return 1;}
get() { return 1;}
init() { 
  add_action("marry","marry");  
  add_action("replace","replace");
}
marry(str) {
  object him, her, ob, ob2;
  if(sscanf(str,"%s %s", him, her) != 2){
    write("Marry who to who?!?\n");
    return 1;
  }
  if(!find_living(her)) { write(cap(her)+" is not here.\n"); return 1; }
  if(!find_living(him)) { write(cap(him)+" is not here.\n"); return 1; }
  ob=clone_object("/players/bastion/closed/ring");
  ob->set_spouse(him);
  move_object(ob,find_living(her));
  tell_object(find_living(her),"You have just been married to "+cap(him)+".\n");
  ob2=clone_object("/players/bastion/closed/ring");
  ob2->set_spouse(her);
  move_object(ob2,find_living(him));
  tell_object(find_living(him),"You have just been married to "+cap(her)+".\n");
  write("You have just married "+him+" to "+her+".\n");
  return 1;
}
replace(str) {
  object who, spouse, ob, ob2;
  if(sscanf(str,"%s %s", who, spouse) != 2){
    write("Marry who to who?!?\n");
    return 1;
  }
  if(!find_living(who)) { write(cap(who)+" is not here.\n"); return 1; }
  ob=clone_object("/players/bastion/closed/ring");
  ob->set_spouse(spouse);
  move_object(ob,find_living(who));
  tell_object(find_living(who),"You have just received a new wedding ring.\n");
  write("You have just given "+cap(who)+" a new wedding ring.\n");
  return 1;
}



