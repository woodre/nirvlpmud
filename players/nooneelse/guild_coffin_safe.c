/*
  guild_coffin_safe.c - allow vamps to store stuff in their coffins
                        <<< this item was copied from catwoman's lockers and
                            modified for use by the vampire guild >>>
*/

inherit "obj/treasure";

#define NUMBER_OF_ITEMS 3

int inventory_number, safe_is_open;
string item_filenames;

init() {
  add_action("open",          "open");
  add_action("close",         "close");
  add_action("read_label",    "read");
  add_action("place_item",    "place");
  add_action("remove_item",   "remove");
  add_action("reset_safe",    "reset");
}

open(str) {
  if (!str || str != "safe") return 0;
  if (this_player()->query_real_name()!=
       environment(this_object())->query_coffin_owner_name()) {
    write("Only "+environment(this_object())->query_coffin_owner_name()+
          " can open the safe.\n");
    say(this_player()->query_name()+" starts fiddling with the safe and receives "+
        "an electric shock.\n");
    return 1;
  }
  if (safe_is_open==1) {
    write("You start to focus your powerful mind on your safe but stop when you\n"+
          "realize it is already open.\n");
    return 1;
  }
  else {
    write("You focus your mind on the safe for a moment and its door"+
          " swings open.\n");
    safe_is_open = 1;
    return 1;
  }
}

close(str) {
  if (!str || str != "safe") return 0;
  if (this_player()->query_real_name()!=
        environment(this_object())->query_coffin_owner_name()) {
    write("Only "+environment(this_object())->query_coffin_owner_name()+
          " can close the safe.\n");
    say(this_player()->query_name()+" starts fiddling with the safe and receives "+
        "an electric shock.\n");
    return 1;
  }
  if (safe_is_open!=1) {
    write("You start to focus your powerful mind on your safe but stop when you\n"+
          "realize it is already closed.\n");
    return 1;
  }
  else {
    write("You focus your mind on the safe for a moment and its door"+
          " swings closed.\n");
    safe_is_open = 0;
    return 1;
  }
}

read_label(str) {
  if (!str || str != "label") return 0;
  write("To use the coffin safe:\n\n"+
        "  read label on safe      - to see these instructions\n"+
        "  open safe               - open the safe so you can use it\n"+
        "  close safe              - close the safe\n"+
        "  place <item> in safe    - places <item> into your safe\n"+
        "  remove <item> from safe - removes <item> from your safe\n"+
        "  reset safe              - empties your safe\n\n\n"+
        "                  Adapted from the lockers created\n"+
        "                  by Catwoman. Brought to you by:\n"+
        "                  Nooneelse's Doodads Inc.\n\n");
  return 1;
}

place_item(arg) {
  object ob;
  int maxitems,numitems;
  int i;
  string filename, tempfile;
  string obfile;
  string tempstr;
  string item;
  string junk;

  if (!arg) return 0;
  arg = arg + " xxx";
  sscanf(arg, "%s %s", item, junk);
  if (junk == " xxx" || junk != "in safe xxx") return 0;
  if (this_player()->query_real_name()!=
        environment(this_object())->query_coffin_owner_name()) {
    write("Only "+environment(this_object())->query_coffin_owner_name()+
          " can use the safe.\n");
    say(this_player()->query_name()+" starts fiddling with the safe and receives "+
        "an electric shock.\n");
    return 1;
  }
  if (!present(item, this_player())) {
    write("You don't have "+item+"!\n");
    return 1;
  }
  ob = present(item,this_player());
  sscanf(file_name(ob), "%s#%s", tempfile, tempstr);
  if (tempfile=="obj/weapon" ||
      (tempfile=="obj/armor" || tempfile=="obj/armour") ||
      tempfile=="obj/container" || tempfile=="obj/treasure" ||
      (ob->query_save_flag() && ob->query_save_flag() != 3) ||
      ob->drop()) {
    write("The '"+item+"' cannot be stored here.\n");
    return 1;
  }
  filename = "/players/nooneelse/black/safes/"+
             environment(this_object())->query_coffin_owner_name();
  tempfile = "/players/nooneelse/black/safes/temp/"+
             environment(this_object())->query_coffin_owner_name()+".temp";
  tempstr = read_file(filename, 1, 1);
  if (!tempstr) {
    write("You dont have a safe! Mail Nooneelse that there is a problem\n"+
          "with the coffin safes (error # P1)\n");
    return 1;
  }
  sscanf(tempstr, "%d", maxitems);
  tempstr = read_file(filename, 2, 1);
  sscanf(tempstr, "%d", numitems);
  if (numitems==maxitems) {
    write("You have already stored the maximum number of items.\n");
    return 1;
  }
  rm(tempfile);
  write_file(tempfile, maxitems+"\n");
  write_file(tempfile, (numitems+1)+"\n");
  for (i=3 ; i<numitems+3 ; i++) {
    tempstr = read_file(filename, i, 1);
    write_file(tempfile, tempstr);
  }
  obfile = file_name(ob);
  sscanf(obfile, "%s#%s", obfile,tempstr);
  obfile = obfile + "#" + ob->safe_arg();
  write_file(tempfile, "/"+obfile+"\n");
  rm(filename);
  cp(tempfile, filename);
  rm(tempfile);
  write("Ok, you place "+item+" into the safe.\n");
/*
  write_file("/players/nooneelse/black/safes/logs/",
             this_player()->query_name()+" "+obfile+" "+ctime(time())+".\n");
*/
  say(this_player()->query_name()+" places "+item+" into the safe.\n");
  this_player()->add_weight(-(ob->query_weight()));
  move_object(ob, "room/void");
  destruct(ob);
  return 1;
}


remove_item(arg) {
  int x;
  int i;
  object ob;
  string a,b,filename;
  string tempstr;
  string tempstr2;
  int numitems;
  string item;
  string junk;

  if (!arg) return 0;
  arg = arg + " xxx";
  sscanf(arg, "%s %s", item, junk);
  if (junk == " xxx" || junk != "in safe xxx") return 0;
  if (this_player()->query_real_name()!=
        environment(this_object())->query_coffin_owner_name()) {
    write("Only "+environment(this_object())->query_coffin_owner_name()+
          " can use the safe.\n");
    say(this_player()->query_name()+" starts fiddling with the safe and receives "+
        "an electric shock.\n");
    return 1;
  }

  sscanf(item, "%d", x);
  tempstr = read_file("/players/nooneelse/black/safes/"+
                      environment(this_object())->query_coffin_owner_name(), 2, 1);
  if (!tempstr) {
    write("You dont have a safe! Mail Nooneelse that there is a problem\n"+
          "with the coffin safes (error # R1)\n");
    return 1;
  }
  tempstr = extract(tempstr, 0, strlen(tempstr)-2);
  sscanf(tempstr, "%d", numitems);
  if (x>numitems || x<1) return 0;
  x+=2;
  tempstr = read_file("/players/nooneelse/black/safes/"+
                      this_player()->query_real_name(), x, 1);
  tempstr=extract(tempstr, 0, strlen(tempstr)-2);
  sscanf(tempstr, "%s#%s", tempstr, tempstr2);
  if (sscanf(tempstr, "%slancer%s",a,b) == 2) tempstr = a+"cyrex"+b;
  ob = clone_object(tempstr);
  if (tempstr2) ob->safe_init(tempstr2);
  write("You remove "+ob->short()+" from your safe.\n");
  say(this_player()->query_name()+" removes "+ob->short()+" from the safe.\n");
  move_object(ob, this_player());
  tempstr = "/players/nooneelse/black/safes/"+
            environment(this_object())->query_coffin_owner_name()+".temp";
  rm(tempstr);
  filename = "/players/nooneelse/black/safes/"+
             environment(this_object())->query_coffin_owner_name();
  tempstr2 = read_file(filename, 1, 1);
  write_file(tempstr, tempstr2);
  write_file(tempstr, (numitems-1)+"\n");
  for (i=3 ; i<numitems+3 ; i++) {
    tempstr2 = read_file(filename, i, 1);
    if (!tempstr2) break;
    tempstr2 = extract(tempstr2, 0, strlen(tempstr2)-2);
    if (i!=x) write_file(tempstr, tempstr2+"\n");
  }
  rm(filename);
  cp(tempstr, filename);
  rm(tempstr);
  return 1;
}

reset_safe(arg) {
  int x;
  int i;
  object ob;
  string a,b,filename;
  string tempstr;
  string tempstr2;
  int numitems;

  if (!arg || arg!="safe") return 0;
  if (this_player()->query_real_name()!=
        environment(this_object())->query_coffin_owner_name()) {
    write("Only "+environment(this_object())->query_coffin_owner_name()+
          " can use the safe.\n");
    say(this_player()->query_name()+" starts fiddling with the safe and receives "+
        "an electric shock.\n");
    return 1;
  }
  rm("/players/nooneelse/black/safes/temp/"+
     environment(this_object())->query_coffin_owner_name()+".temp");
  write_file(filename, "1\n");
  write_file(filename, "0\n");
  write("Your safe has been reset. Anything that may have been in it is now gone.\n");
  return 1;
}


reset(arg) {
  if (arg) return;

  set_value(0);
  set_weight(666);
}

id(str) { return str=="safe" || str=="coffin safe"; }

get() {
  write("It is secured to the floor.\n");
  return 0;
}

short() { return "A sturdy little safe with a label on one side"; }

long() {
  string tempstr, tempstr2;
  object ob;
  int linenum;
  int maxitems, numitems;

  if (!read_file("/players/nooneelse/black/safes/"+
                 environment(this_object())->query_coffin_owner_name(), 1, 1)) {
    write("You don't have a safe! Mail Nooneelse that there is a problem\n"+
          "with the coffin safes! (error # L1)\n");
    return 1;
  }
  if (safe_is_open!=1) {
    write("It is a sturdy looking box made of the finest stainless steel.\n"+
          "There is what appears to be a door on the front, but no knobs or "+
          "handles.\n"+
          "There is a small label on the side that you can read\n");
    return 1;
  }
  tempstr = read_file("/players/nooneelse/black/safes/"+
                      environment(this_object())->query_coffin_owner_name(), 1, 1);
  tempstr = extract(tempstr, 0, strlen(tempstr)-2);
  sscanf(tempstr, "%d", maxitems);
  tempstr = read_file("/players/nooneelse/black/safes/"+
                      environment(this_object())->query_coffin_owner_name(), 2, 1);
  tempstr = extract(tempstr, 0, strlen(tempstr)-2);
  sscanf(tempstr, "%d", numitems);
  write("You can store up to "+maxitems+" items.  You are currently "+
        "storing "+numitems+" items.\n\n");
  for (linenum=3; linenum<numitems+3; linenum++) {
    tempstr = read_file("/players/nooneelse/black/safes/"+
                        environment(this_object())->query_coffin_owner_name(),
                        linenum, 1);
    tempstr = extract(tempstr, 0, strlen(tempstr)-2);
    sscanf(tempstr, "%s#%s", tempstr, tempstr2);
    ob = clone_object(tempstr);
    if (tempstr2) ob->safe_init(tempstr2);
    write(linenum-2+"\t");
    write(ob->short()+"\n");
    destruct(ob);
  }
  return 1;
}

/* ------------------------------------------------------------------- */
/* create safe - put this in the coffin so it happens each time coffin is created */
create_safe(str) {
  string *filename;

  filename = "/players/nooneelse/black/safes/"+
             environment(this_object())->query_coffin_owner_name();
  rm("/players/nooneelse/black/safes/temp/"+
     environment(this_object())->query_coffin_owner_name()+".temp");
  write_file(filename, NUMBER_OF_ITEMS + "\n");
  write_file(filename, "0\n");
  return 1;
}
