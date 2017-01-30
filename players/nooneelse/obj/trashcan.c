/*
 trashcan.c
*/

object item_obj;
string item_name, how_many, an_s;

id(str) { return(str=="trashcan" || str=="can" || str=="nooneelsetrashcan"); }

short() { return("a trashcan"); }

long() {
  write("It is a light blue trashcan.\n"
       +"You can drop items you don't need in it.\n"
       +"It is better to drop them in this can than on the ground!\n"
       +"To drop something in it type:"
       +"    toss <object>\n"
       +"Only things with a value below 20 can be dropped in it.\n"
       +"As a thanks for using it you will receive 5 coins for each\n"
       +"thing you toss.\n");
}

init() {
  if(this_player()->query_level() > 21) {
    add_action("show_log","tclog");
    add_action("reset_log","tcreset");
  }
  add_action("toss","toss");
}

toss(str) {
  if(!str) return 0;
  if(sscanf(str,"%scoin%s", how_many, an_s)==2) {
    write("Throw away money?\n");
    return 1;
  }
  item_obj=present(str,this_player());
  if(!item_obj) {
    write("You don't have that.\n");
    return 1;
  }
  if(item_obj->query_value() > 21) {
    write("That is worth 20 coins or more. You better sell it in the shop!\n");
    return 1;
  }
  if(living(item_obj)) {
    write("But...but... you don't have the heart to toss that!\n");
    return 1;
  }
  if(item_obj->drop() || !item_obj->short()) {
    write("You can't toss that!\n");
    return 1;
  }
  item_name=item_obj->query_name();
/*
  log_file("TRASH", this_player()->query_name()+" : "+item_obj->short()+
           " : "+file_name(item_obj)+" : "+creator(item_obj)+"\n");
*/
  if (item_obj->query_value() < 5)
    this_player()->add_money(item_obj->query_value());
  else
    this_player()->add_money(5);
  destruct(item_obj);
  write("You tossed it.\n");
  write("\nYou hear a crunching noise from the trashcan.\n");
  say(this_player()->query_name()+" tossed a "+item_name+" in the can.\n");
  say("\nYou hear a crunching noise from the trashcan.\n");
  return 1;
}

/*
reset_log() {
  if(this_player()->query_level() < 24) {
    write("This can be done by an archwizard only.\n");
    return 1;
  }
  rm("log/TRASH");
  log_file("TRASH","Tosser : Item : ItemFileName : ItemCreator\n");
  say(this_player()->query_name()+" resets the trashcan log.\n");
  return 1;
}
*/

/*
show_log() {
  cat("log/TRASH");
  say(this_player()->query_name()+" checks the trashcan log.\n");
  return 1;
}
*/
