/* 
 * rumphole.c - A room for my test character to store and retrieve equipment.
 *              Why should I use a locker or hotel room, or have to re-clone
 *              it all??  /boggle
 */
 
#pragma strong_types

#include <ansi.h>

inherit "/players/rumplemintz/room/color_room";

object ob1, ob2, ob3;

void reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_light(1);
  set_short(YEL, "Rump's Hole");
  set_long(YEL,"\n"+
"This is Rump's large yellow hole.  Test characters can store and retrieve\n"+
"items here.  There is no charge for services here, read the sign to see \n"+
"how to use the hole.\n");
  dest_dir = ({
    "/room/church", "church",
    "/room/adv_guild", "advguild",
    "/players/grimm/closed/obj/badge_stuff/guild_pr", "dopple",
    "/players/rumplemintz/workroom", "workroom",
    });
  items = ({
    "sign", "Perhaps you can read it?"
  });
}

void init() {
  ::init();
  add_action("dopple_exit", "dopple");
  add_action("read", "read");
  if (this_player()->query_level() < 20 ||
      !this_player()->is_testchar() ) {
    add_action("dig_hole", "dig");
    add_action("clear", "clear");
    add_action("withdraw_item", "hget");
    add_action("deposit_item", "hput");
    add_action("list_items", "hlist");
    add_action("bank_func", "bank");
  }
  return;
}

status dopple_exit() {
  if (this_player()->query_level() < 20 ||
      !this_player()->is_testchar() ) {
    write("Only wizards and test characters may use this exit.\n");
    return 1;
  }
  return 0;
}

status read(string str) {
  if(str != "sign")
    return 0;
  write(
"Instructions for using Rump's Hole!\n"+
"\n"+
"dig hole     - dig a new hole if you don't already have one, or dig an \n"+
"               additional one to store more items, limit of 100\n"+
"hget <item>  - gets <item> from one of your holes.\n"+
"hput <item>  - puts <item> from your inventory into a hole.\n"+
"hlist        - lists all items in all of your holes.\n\n"+
"clear <item> - Clears an item from a hole, do only if it asks.\n"+
"bank <str>   - Bank functions. Where str = deposit or withdraw \n"+
"\n");
  return 1;
}

int bank_func(string str) {
  string type;
  int amount;

  if (!str) return 0;
  if (sscanf(str, "%s %d", type, amount) != 2) return 0;
  if (amount < 0) return 0;
  if (type == "deposit") {
    if ((int)this_player()->query_money() < amount) {
      write("You do not have that much money.\n");
      return 1;
    }
    this_player()->add_money(-amount);
    this_player()->add_bank_balance(amount);
    write("You deposit " + amount + " gold coins.\n");
  } else if (type == "withdraw") {
    if ((int)this_player()->query_bank_balance() < amount) {
      write("You do not have that much in your account.\n");
      return 1;
    }
    if (((int)this_player()->query_money() + amount) > 80000) {
      write("You cannot withdraw more than " +
            (80000 - (int)this_player()->query_money()) + ".\n");
      return 1;
    }
    this_player()->add_money(amount);
    this_player()->add_bank_balance(-amount);
  } else
    return 0;    
  write("Your account balance is " + this_player()->query_bank_balance() +
        " gold coins.\n");
  return 1;
}

status dig_hole(string str) {
  string filename;
    string tempstr;
    int numitems;
    int maxitems;
    int i;

  if(!str)
    return 0;
  if (str != "hole")
    return 0;
  filename = "/players/rumplemintz/rh/";
  filename += (string)this_player()->query_real_name();
  if (tempstr = read_file(filename, 1, 1)) {
  if (!tempstr)
    return 0;
  tempstr = extract(tempstr, 0, strlen(tempstr)-2);
    sscanf(tempstr, "%d", maxitems);
    if (maxitems==100) {
      write("You can't store over 100 items, sorry.\n");
      return 1;
    }
    write("Ok, you can now store " + (maxitems+1) + " items.\n");
    rm("/players/rumplemintz/"+this_player()->query_real_name()+".temp");
    write_file("/players/rumplemintz/"+this_player()->query_real_name()+
         ".temp", maxitems+1+"\n");
    i = 2;
    while (tempstr = read_file(filename,i,1)) {
      write_file("/players/rumplemintz/"+this_player()->query_real_name()+
                 ".temp", tempstr);
      i++;
    }
    rm(filename);
    cp("/players/rumplemintz/"+this_player()->query_real_name()+".temp",
       filename);
    rm("/players/catwoman/"+this_player()->query_real_name()+".temp");
    return 1;
  }
  else {
    write("Ok, you now have a hole.  You can store one item in it.\n");
    rm("/players/rumplemintz/"+this_player()->query_real_name()+".temp");
    write_file(filename,"1\n");
    write_file(filename,"0\n");
  }
  return 1;
}

status list_items() {
  string tempstr, tempstr2;
  string err;
  object ob;
  int linenum;
  int maxitems,numitems;

  if (!read_file("/players/rumplemintz/storage/"+
                 this_player()->query_real_name(),1,1)) {
    write("You don't have a locker.\n");
    return 1;
  }
  tempstr = read_file("/players/rumplemintz/storage/"+
                      this_player()->query_real_name(),1,1);
  tempstr=extract(tempstr,0,strlen(tempstr)-2);
  sscanf(tempstr,"%d",maxitems);
  tempstr = read_file("/players/rumplemintz/storage/"+
                      this_player()->query_real_name(),2,1);
  tempstr=extract(tempstr,0,strlen(tempstr)-2);
  sscanf(tempstr,"%d",numitems);
  write("You can store up to "+maxitems+" items.  You are currently\n"+
        "storing "+numitems+" items.\n\n");
  for (linenum=3; linenum<numitems+3; linenum++) {
    tempstr = read_file("/players/rumplemintz/storage/"+
                        this_player()->query_real_name(),linenum,1);
    tempstr = extract(tempstr,0,strlen(tempstr)-2);
    sscanf(tempstr,"%s#%s$",tempstr,tempstr2);
    write(linenum-2+"\t");

    if ( err = catch(ob = clone_object(tempstr)) )
      write("E R R O R - Clear This Locker Number!\n");
    else {
      if (tempstr2)
        ob->locker_init(tempstr2);
      write(ob->short()+"\n");
      destruct(ob);
    }
  }
  return 1;
}

status withdraw_item(string item) {
  int x, i, hits, misses;
  object ob;
  string err,a,b,filename;
  string tempstr;
  string tempstr2;
  int numitems;

  if (!item)
    return 0;
  sscanf(item,"%d",x);
  tempstr = read_file("/players/rumplemintz/storage/"+
                      this_player()->query_real_name(),2,1);
  if (!tempstr) {
    write("You don't own a locker.\n");
    return 1;
  }
  tempstr = extract(tempstr,0,strlen(tempstr)-2);
  sscanf(tempstr,"%d",numitems);
  if (x>numitems || x<1)
    return 0;
  x += 2;
  tempstr = read_file("/players/rumplemintz/storage/"+
                      this_player()->query_real_name(),x,1);
  tempstr=extract(tempstr,0,strlen(tempstr)-2);
  sscanf(tempstr,"%s#%s$%d@%d",tempstr,tempstr2,hits,misses);
  if (sscanf(tempstr, "%slancer%s", a, b) == 2)
    tempstr=a+"cyrex"+b;
  if ( err = catch(ob = clone_object(tempstr)) ) {
    write("Your item has been mangled beyond use. Clear This Locker Number!\n");
    return 1;
  }
  if (tempstr2)
    ob->locker_init(tempstr2);
  if(hits)
    ob->set_hits(hits);
  if(misses)
    ob->set_misses(misses);
  write("You pull "+ob->short()+" from a hole.\n");
  say(this_player()->query_name()+" pulls "+ob->short()+" from a hole.\n");
  move_object(ob,this_player());
  tempstr = "/players/rumplemintz/"+this_player()->query_real_name()+".temp";
  rm(tempstr);
  filename = "/players/rumplemintz/storage/"+this_player()->query_real_name();
  tempstr2 = read_file(filename,1,1);
  write_file(tempstr,tempstr2);
  write_file(tempstr,(numitems-1)+"\n");
  for (i=3 ; i<numitems+3 ; i++) {
    tempstr2 = read_file(filename,i,1);
    if (!tempstr2)
      break;
    tempstr2 = extract(tempstr2,0,strlen(tempstr2)-2);
    if (i!=x)
      write_file(tempstr,tempstr2+"\n");
  }
  rm(filename);
  cp(tempstr,filename);
  rm(tempstr);
  return 1;
}

status deposit_item(string item) {
  object ob;
  int nolock;
  int maxitems,numitems;
  int i;
  string filename, tempfile;
  string obfile;
  string tempstr;

  nolock = 0;
  if(!item)
    return 0;
  if (!present(item, this_player())) {
    write("You don't have "+item+"!\n");
    return 1;
  }
  ob = present(item,this_player());
  sscanf(file_name(ob), "%s#%s",tempfile,tempstr);
  if (tempfile=="obj/weapon" || tempfile=="obj/armor" ||
      (ob->generic_object() && !ob->locker_arg()) ) {
    write("It doesn't fit.\n");
    return 1;
  }
  if (tempfile=="obj/armor" || tempfile == "obj/armour") {
    write("It doesn't fit.\n");
    return 1;
  }
  if (tempfile == "obj/container" || tempfile == "obj/treasure") {
    write("It doesn't fit.\n");
    return 1;
  }
/* Don't care about save flags for test characters - we can save anything -- Rump
  if(ob->query_save_flag() && ob->query_save_flag() != 3) {
        write("That item cannot be stored here.\n");
        return 1;
    }
*/
  if (ob->drop()) {
    write("You can't deposit that item.\n");
    return 1;
  }
  filename = "/players/rumplemintz/storage/"+this_player()->query_real_name();
  tempfile = "/players/rumplemintz/"+this_player()->query_real_name()+".temp";
  tempstr = read_file(filename,1,1);
  if(!tempstr) {
    write("You dont have a locker!\n");
    return 1;
  }
  sscanf(tempstr,"%d",maxitems);
  tempstr = read_file(filename,2,1);
  sscanf(tempstr,"%d",numitems);
  if (numitems==maxitems) {
    write("You don't have any space to put more items.\n");
    return 1;
  }
  rm(tempfile);
  write_file(tempfile,maxitems+"\n");
  write_file(tempfile,(numitems+1)+"\n");
  for (i=3 ; i<numitems+3 ; i++) {
    tempstr = read_file(filename,i,1);
    write_file(tempfile,tempstr);
  }
  obfile = file_name(ob);
  sscanf(obfile,"%s#%s",obfile,tempstr);
  obfile = obfile + "#" + ob->locker_arg();
  obfile = obfile + "$" + ob->query_hits();
  obfile = obfile + "@" + ob->query_misses();
  write_file(tempfile,"/"+obfile+"\n");
  rm(filename);
  /* 11/27/06 Earwax: fix for ldmud */
#ifdef __LDMUD__
  copy_file(tempfile,filename);
#else
  cp(tempfile,filename);
#endif
  rm(tempfile);
  write("Ok, you put "+item+" into a hole.\n");
  say(this_player()->query_name()+" puts "+item+" into a hole.\n");
  this_player()->add_weight( - ((int)ob->query_weight()) );
  move_object(ob,"room/void");
  destruct(ob);
  return 1;
}

status clear(string item) {
  int x;
  int i;
  object ob;
  string a,b,filename;
  string tempstr;
  string tempstr2;
  int numitems;

  if (!item)
    return 0;
  sscanf(item,"%d",x);
  tempstr = read_file("/players/rumplemintz/storage/"+
                      this_player()->query_real_name(),2,1);
  if (!tempstr) {
    write("You must dig a hole first.\n");
    return 1;
  }
  tempstr = extract(tempstr,0,strlen(tempstr)-2);
  sscanf(tempstr,"%d",numitems);
  if (x>numitems || x<1)
    return 0;
  x += 2;
  tempstr = read_file("/players/rumplemintz/storage/"+
                      this_player()->query_real_name(),x,1);
  tempstr=extract(tempstr,0,strlen(tempstr)-2);
  sscanf(tempstr,"%s#%s",tempstr,tempstr2);
  if(sscanf(tempstr, "%slancer%s",a,b) == 2)
    tempstr=a+"cyrex"+b;
  tempstr = "/players/rumplemintz/"+this_player()->query_real_name()+".temp";
  write("Object cleared.\n");
  rm(tempstr);
  filename = "/players/rumplemintz/storage/"+this_player()->query_real_name();
  tempstr2 = read_file(filename,1,1);
  write_file(tempstr,tempstr2);
  write_file(tempstr,(numitems-1)+"\n");
  for (i=3 ; i<numitems+3 ; i++) {
    tempstr2 = read_file(filename,i,1);
    if (!tempstr2)
        break;
    tempstr2 = extract(tempstr2,0,strlen(tempstr2)-2);
    if (i!=x)
      write_file(tempstr,tempstr2+"\n");
  }
  rm(filename);
  cp(tempstr,filename);
  rm(tempstr);
  return 1;
}
