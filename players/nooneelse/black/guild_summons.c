/*
  guild_summons.c
*/

inherit "obj/treasure";

string summons_owner_name, str;

init() {
  add_action("check_summons",  "check");
  add_action("accept_summons", "accept");
  add_action("drop", "drop");
  add_action("drop", "give");
  add_action("quit", "quit");
}

check_summons(str) {
  object target_obj, obj;
  string str1, str2, str3, dest_dir;
  int i, n;
  if(!str) return 0;
  if (!str || str != "summons") return;
  target_obj=find_player(summons_owner_name);
  if (!target_obj) {
    write(capitalize(summons_owner_name)+
          " is no longer playing.  Summons revoked.\n");
    destruct(this_object());
    return 1;
  }
  write(environment(target_obj)->short()+".\n");
  dest_dir=environment(target_obj)->query_dest_dir();
  if (sizeof(dest_dir) > 0) {
    if (sizeof(dest_dir)==1)
      write("Exit: ");
    else
      write("Exits: ");
    n=1;
    while (n < sizeof(dest_dir)) {
      write(dest_dir[n]);
      if (n < (sizeof(dest_dir) - 2) && sizeof(dest_dir) > 1) write(", ");
      n++;
      n++;
    }
  }
  else
    write("Exit(s):  The summons cannot determine the exits in\n"+
          "          "+capitalize(summons_owner_name)+"'s room.\n");
  write("\n\n");
  obj = first_inventory(environment(target_obj));
  while(obj) {
    if (obj->short()) write(obj->short()+".\n");
    obj = next_inventory(obj);
  }
  return 1;
}

accept_summons(str) {
  object target_obj;
  string wheree;
  string str1, str2, str3;
  int i;
  if (!str || str != "summons") return;
  target_obj=find_player(summons_owner_name);
  if (!target_obj) {
    write(capitalize(summons_owner_name)+
          " is no longer playing.  Summons revoked.\n");
    destruct(this_object());
    return 1;
  }
  if (environment(target_obj)->realm()=="NT") {
    write(capitalize(summons_owner_name)+" is in an area that prevents that.\n");
    return 1;
  }
  if (environment(this_player())->realm()=="NT") {
    write("You are in an area that prevents that.\n");
    return 1;
  }
  say(this_player()->query_name()+" glows for a moment, then disappears.\n",
      this_player());
  if(wheree = call_other("obj/base_tele","teleport")) {
      this_player()->move_player("with an astonished look#"+wheree); 
      tell_object(target_obj,"Something has gone wrong with the summons!\n"); }
  else {
  move_object(this_player(), environment(target_obj));
  write("You are transported to "+capitalize(summons_owner_name)+".\n");
  if (this_player()->query_brief())
    tell_object(this_player(), environment(this_player())->short()+".\n");
  else
    command("look", this_player());
  tell_object(target_obj, this_player()->query_name()+
              " has accepted your summons and is now here.\n"); }
  destruct(this_object());
  return 1;
}

drop(str) {
  string str2;
  str2=0;
    if(!str) return 0;
  if (str) sscanf(str, "summons%s", str2);
  if (str=="summons" || str=="all" || str2) {
    write("As you drop your summons, it crumbles to dust.\n");
    say("As "+this_player()->query_name()+
        " drops a piece of black paper, it crumbles to dust.\n");
    destruct(this_object());
    if (str=="summons") return 1;
    if (str=="all") return;
  }
}

quit(str) {
  drop("summons");
  return;
}

query_save_flag() { return 1; }

reset(arg) {
  if (arg) return;

  set_value(0);
  set_weight(0);
}

short() {
  if (summons_owner_name)
    return "A summons from "+capitalize(summons_owner_name);
  else
    return "A summons from someone";
}

long() {
  write(short()+".\n"+
    "You have been given a summons to "+capitalize(summons_owner_name)+".\n"+
    "You can:\n"+
    "  use it by typing 'accept summons' to go to "+
    capitalize(summons_owner_name)+"'s location\n"+
    "  get rid of it by typing 'drop summons'\n"+
    "  check out "+capitalize(summons_owner_name)+
    "'s location before deciding with 'check summons'\n");
}

prevent_insert() {
  write("You don't really want to hide your summons do you?\n");
  return 1;
}

set_summons_owner(str) { summons_owner_name=str; }

id(str) { return str=="summons" ||
                 str=="vampire summons" ||
                 str==summons_owner_name+" summons"; }
