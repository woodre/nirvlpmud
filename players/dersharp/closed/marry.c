Marry(str){
string who, name;
object ob, ob2;
  sscanf(str,"%s %s",who,name);
  ob = find_player(who);
  if (ob) {
    if (!present("wedding_ring",ob)) {
      ob2 = clone_object("/players/dersharp/wedding.c");
      ob2->local_set_spouse(name);
      move_object(ob2,ob);
    }
  }
  ob = find_player(name);
  if (ob) {
    if (!present("wedding_ring",ob)) {
      ob2 = clone_object("/players/dersharp/wedding.c");
      ob2->local_set_spouse(who);
      move_object(ob2,ob);
    }
  }
  write("They are now married.\n");
  return(1);
}
