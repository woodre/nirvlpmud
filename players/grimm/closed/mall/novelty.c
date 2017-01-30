inherit "room/room";
reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc = "Omar's Novelty Shop";
    no_castle_flag = 0;
    long_desc = 
    "You have just entered Omar's Novelty Shop.  This is a place to purchase\n"+
    "\"odd\" items that are either usefull, interesting, or just plain fun\n"+
    "to use.  Omar is a nice guy, but he CAN be a bit rude at times.\n"+
     "You can \"list\" or \"buy <number>\".\n";
    dest_dir = 
        ({
         "/players/grimm/closed/mall/hall2", "west",
       });
}
 
query_light() {
    return 1;
}
 
init() {
  if(this_player()->query_level()>20) {
    add_action("add_item","add");
    write("Welcome Wizard! Type \"add help\" for a command set up just for you.\n");
  }
  add_action("west","west");
  add_action("list","list");
  add_action("buy","buy");
}
 
west() {
  this_player()->move_player("west#/players/grimm/closed/mall/hall2");
  return 1;
}
 
list() {
  int i,j;
  string ln, it;
  object ob;
  j = 0;
  i = 1;
  ln = read_file("/players/grimm/novelty_items",i);
  write("Omar shows you an inventory sheet that has the following on it:\n");
/*
  write("[1]\t1000\tSt. Ryche's Storage Crucible\n");
  write("[2]\t1000\tA Super Speedster\n");
*/
  while(ln) {
    sscanf(ln,"%s\n",it);
    if(ob = clone_object(it)) {
      write("["+i+"]\t");
      write(ob->query_value()*2);
      if(ob->query_value()*2>999999) write(" ");
      else write("\t");
      write(ob->short()+"\n");
      j++;
    }
    i++;
    ln = read_file("/players/grimm/novelty_items",i);
  }
  if(!j) {
    write("Nothing! Everything has been sold out.\n");
  }
return 1;
}
 
buy(str) {
  int x;
  object ob;
  string ln, it;
  int amt;
  sscanf(str,"%d",x);
  if(!x) {
    write("Omar says: What the hell is the number of the item you wanna buy?\n");
    return 1;
  }
/*
  if(x==1) {
    if(present("crucible",this_player())) {
      write("You already have one.\n");
      return 1;
    }
    if(this_player()->query_money()<1000) {
      write("Omar says: You do not have enough money for that! Be off with you.\n");
      return 1;
    }
    this_player()->add_money(-1000);
    ob = clone_object("/players/grimm/closed/obj/crucible");
    move_object(ob, this_player());
    ob->reset(1);
    write("Omar says: Oh a thousand thanx on you! Now I can get my wife that mink she\nhas always wanted.\n");
    say(capitalize(this_player()->query_real_name())+" bought a "+ob->short()+".\n");
    return 1;
  }
  if(x==2) {
    if(present("speedster",this_player())) {
      write("You already have a speedster.  You don't need another.\n");
      return 1;
    }
    if(this_player()->query_money()<1000) {
      write("Omar says: You do not have enough money for that! Be off with you!\n");
      return 1;
    }
    this_player()->add_money(-1000);
    ob = clone_object("/players/grimm/closed/obj/speed");
    move_object(ob, this_player());
    write("Omar hands you a new speedster.\n");
    say(capitalize(this_player()->query_real_name())+" bought a "+ob->short()+".\n");
    return 1;
  }
*/
  ln = read_file("/players/grimm/novelty_items",x);
  sscanf(ln,"%s\n",it);
  ob = clone_object(it);
  if(!ln || !ob) {
    write("Omar says: I can't seem to find that item. Try something else.\n");
    return 1;
  }
  amt = ob->query_value()*2;
  if(amt>this_player()->query_money()) {
    write("Omar says: You don't have enough money for that. Be off with you you scum!\n");
    return 1;
  }
  this_player()->add_money(-amt);
  write("Omar says: Oh a thousand thanx on you! Now I can get my wife that mink she\nhas always wanted.\n");
  say(capitalize(this_player()->query_real_name())+" bought a "+ob->short()+".\n");
  move_object(ob,this_player());
  this_player()->add_weight(ob->query_weight());
  return 1;
}
 
add_item(str) {
  string it;
  object ob;
  it = str;
  if(this_player()->query_level()<20) {
    write("Omar says: You are not a wizard! Be off with you!\n");
    return 1;
  }
  if(!it) {
    write("Omar says: What do you want to add?\n");
    write("Omar says: type \"add help\" for help.\n");
    return 1;
  }
  if(it=="help") {
    write("Omar jumps out in front of you.\nOmar says: Greetings oh powerful wizard!\nOmar whipes his nose to get the brown stuff off.\n");
    write("Omar says: I am honored to have you in my store and would love to sell your\nitems for you.\n");
    write("Omar says: All I need you to do to put the item in here is to:\n");
    write("Omar says: type \"add /players/"+this_player()->query_real_name()+"/the/directory/file_name\"\n");
    write("Omar says: The \".c\" is not needed but can be put in if you prefer.\n");
    write("Omar says: The only request is that no weapons or armor that can be found in\nthe game should be put in here.\n");
    write("Omar says: Thank you again for honoring me with your presence!\nOmar pukes on his shoes and hops back over the counter.\n");
    return 1;
  }
  if(!(ob = clone_object(it))) {
    write("Omar says: I cannot find that item.\n");
    return 1;
  }
  write("Omar says: Thank you! I'll add the "+ob->short()+" valued at: "+ob->query_value()*2+"\n to my list immediately!\n");
  write_file("/players/grimm/novelty_items",it+"\n");
  write_file("/players/grimm/closed/LOGS/novelty",
  capitalize(this_player()->query_real_name())
  +" just put in:\n"+it+"\nThe time is: "+ctime(time())+"\n-----------------------\n");
  return 1;
}
