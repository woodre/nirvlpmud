inherit "/obj/treasure";
string owner;
reset(arg) {
  if(arg) return;
  owner = this_player()->query_real_name();
  set_short("St. Ryche's Storage Crucible");
  set_long("This is the storage crucible of Saint William Ryche.\n"+
"The crucible is said to have magical properties, but none actually know\n"+
"the extent of it's power.  Engraved on the side of the crucible is a form\n"+
"of a crude menu for, as far as you can tell, what the crucible can do.\n"+
"The \"menu\" reads:\n     cput .... Puts an item in the crucible.\n"+
"     cget .... Gets an item from the crucible.\n"+
"     cinv .... Checks the inventory of the crucible.\n");
  set_id("crucible");
  set_weight(0);
  set_value(0);
  set_heart_beat(1);
}

heart_beat() {
  if(!find_living(owner)) {
    quit();
  } else {
    move_object(this_object(),find_living(owner));
  }
  if(!environment(this_object())->query_interactive()) {
    gone_net_dead_damnit();
  }
}

init() {
/*
  add_action("quit","quit");
*/
  add_action("cput","cput");
  add_action("cget","cget");
  add_action("cinv","cinv");
}

cput(str) {
  string it,ln;
  object ob;
  int j,i;
  int nolock;
  nolock=1;
  if(!str) {
    write("What do you want to store in the crucible?\n");
    return 1;
  }
  if(this_player()->query_sp()<5) {
    write("You do not have enough spell points to do that.\n");
    return 1;
  }
  if(str=="crucible") {
    write("You can't put the crucible inside itself!\n");
    return 1;
  }
  if(!(ob=present(str,this_player()))) {
    write("You do not have one of those.\n");
    return 1;
  }
  if(ob->drop()) {
    write("You can't drop that item in there.\n");
    return 1;
  }
/*
  if(nolock != ob->query_save_flag()) {
    write("That item does not fit in there.\n");
    return 1;
  }
*/
  if(ob->query_auto_load()) {
    write("That item autoloads, you don't need to store it.\n");
    return 1;
  }
  if(ob->no_crucible()) {
    write("That is a specialty item that will not go in the crucible.\n");
    return 1;
  }
  i = 1;
  j = 0;
  ln = read_file("/players/grimm/closed/obj/crucible/"+owner,i);
  while(ln) {
    i++;
    ln = read_file("/players/grimm/closed/obj/crucible/"+owner,i);
    j++;
  }
  if((j==12) ||(!present("badge",this_player()) && j==10)) {
    write("The crucible is full.\n");
    return 1;
  }
  sscanf(file_name(ob),"%s#",it);
   if(sscanf(it,"obj%s",ln)) {
     write("That is a generic item.  You can't put it in there.\n");
     return 1;
   }
  this_player()->add_spell_point(-5);
  write_file("/players/grimm/closed/obj/crucible/"+owner,it+"\n");
  write("You put the "+ob->short()+" in the crucible.\n");
  say(capitalize(owner)+" put a "+ob->short()+" in his crucible.\n");
  if(ob->armor_class()) {
    ob->remove(str);
  }
  if(ob->weapon_class()) {
    ob->stopwield(str);
  }
  this_player()->add_weight(-ob->query_weight());
  destruct(ob);
return 1;
}

cget(str) {
  string it, old, ln;
  object ob;
  int i,j;
  if(!str) {
    write("What do you want to get from the crucible?\n");
    return 1;
  }
  if(this_player()->query_sp()<5) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  i = 1;
  ln = read_file("/players/grimm/closed/obj/crucible/"+owner,i);
  sscanf(ln,"%s\n",it);
  if(!(ob=clone_object(it))) ob=clone_object("/players/grimm/closed/obj/badge");
  while(ln && !ob->id(str)) {
    i++;
    ln = read_file("/players/grimm/closed/obj/crucible/"+owner,i);
    sscanf(ln,"%s\n",it);
    if(!(ob=clone_object(it))) ob=clone_object("/players/grimm/closed/obj/badge");
  }
  if(!ob->id(str)) {
    write("That item was not found in the crucible.\n");
    return 1;
  }
  this_player()->add_spell_point(-5);
  move_object(ob, this_player());
  this_player()->add_weight(ob->query_weight());
  write("Ok.\n");

  say(capitalize(owner)+" gets a "+ob->short()+" from his crucible.\n");
  old = it+"\n";
  j = 0;
  i = 1;
  ln = read_file("/players/grimm/closed/obj/crucible/"+owner,i);
  while(ln) {
    if(ln!=old) {
      write_file("/players/grimm/closed/obj/crucible/"+owner+".tmp",ln);
    } else {
      if(j!=1) {
        j = 1;
      } else {
        write_file("/players/grimm/closed/obj/crucible/"+owner+".tmp",ln);
      }
    }  
    i++;
    ln = read_file("/players/grimm/closed/obj/crucible/"+owner,i);
  }
  rm("/players/grimm/closed/obj/crucible/"+owner);
  cp("/players/grimm/closed/obj/crucible/"+owner+".tmp",
     "/players/grimm/closed/obj/crucible/"+owner);
  rm("/players/grimm/closed/obj/crucible/"+owner+".tmp");
  return 1;
}

cinv() {
  string it, ln;
  int i,j;
  object ob;
  i = 1;
  j = 0;
  write("Your crucible contains:\n");
  ln = read_file("/players/grimm/closed/obj/crucible/"+owner,i);
  while(ln) {
    sscanf(ln,"%s\n",it);
    if(ob=clone_object(it)) {
      write(ob->short()+"\n");
      j++;
    }
    i++;
    ln = read_file("/players/grimm/closed/obj/crucible/"+owner,i);
  }
  say(capitalize(owner)+" examines the contents of his crucible.\n");
  if(!j) {
    write("  Nothing.\n");
    return 1;
  }
  return 1;
}

quit() {
  int i;
  object ob;
  string ln,it;
  i = 1;
  ln = read_file("/players/grimm/closed/obj/crucible/"+owner,i);
  while(ln) {
    sscanf(ln,"%s\n",it);
    if(ob=clone_object(it)) {
      move_object(ob,environment(this_player()));
      say(capitalize(owner)+" drops a "+ob->short()+".\n");
    }
    i++;
    ln = read_file("/players/grimm/closed/obj/crucible/"+owner,i);
  }
  rm("/players/grimm/closed/obj/crucible/"+owner);
  destruct(this_object());
  return;
}

gone_net_dead_damnit() {
  int i;
  object per, ob;
  string ln, it;;
  i = 1;
  ln = read_file("/players/grimm/closed/obj/crucible/"+owner,i);
  while(ln) {
    sscanf(ln,"%s\n",it);
    if(ob = clone_object(it)) {
      move_object(ob,environment(this_object()));
    }
    i++;
    ln = read_file("/players/grimm/closed/obj/crucible/"+owner,i);
  }
  rm("/players/grimm/closed/obj/crucible/"+owner);
  write_file("/players/grimm/closed/LOGS/blah",owner+" quit droppin "+it+" last.\n");
  destruct(this_object());
}
