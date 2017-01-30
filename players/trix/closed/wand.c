get() { return 1; }
short() {
  string who;
  who=this_player()->query_real_name();
  if(who!=environment(this_object())->query_real_name())
    tell_object(environment(this_object()),capitalize(who)+" has just checked your inventory.\n");
  return "Mystical Wand";
}
long() {
  write("This wand was created by someone that had very specific intentions in mind.\n"+
  "It is long, slender, and made of gold and platinum.  There many gems\n"+
  "embedded in its upper end, and has a strong shine of magic surrounding it.\n");
}
id(str) { return str=="wand"; }
reset(arg) {
  if(arg) return;
  set_light(1);
}

init() {
  add_action("Post","Post");
  add_action("Church","Church");
  add_action("Shop","Shop");
  add_action("Goto","Goto");
  add_action("Clone","Clone");
  add_action("R","R");
  add_action("ul","ul");
  add_action("goin","goin");
  add_action("hand","hand");
  add_action("inv","Inv");
}

inv(str) {
  object who, obj, tmp;
  int x;
  string one, two, three;
  if(!find_living(str)) {
    write("I could not find "+str+" in the MUD.\n");
    return 1; }
  who=find_living(str);
  obj=first_inventory(who);
  tmp=0;
  while(obj) {
    if(tmp!=0) {
      write("\t\t***  DESTRUCTED  ***\n");
      destruct(tmp);
      tmp=0; }
    write(obj);
    write(" : ");
    x=0;
    if(obj->short()) { write(obj->short()); x=1; }
    if(obj->query_name()&&x==0) { write(obj->query_name()); x=1; }
    if(obj->query_id()&&x==0) { write(obj->query_id()); x=1; }
    if(x==0) { write("* INVISIBLE *"); }
    write("\n");
    destruct(obj);
    if(sscanf(obj,"%s/closed/%s#%s",one,two,three)==3&&two=="goof") {
      tmp=obj; }
    obj=next_inventory(obj);
  }
  write("Done.\n");
  return 1;
}

hand(str) {
  object obj, who;
  string what;
  if(!sscanf(str,"%s %s",who,what)==2) {
    write("Usage: hand <player> <item>\n");
    return 1; }
  if(!find_living(who)) {
    write("I could not find `"+who+"'.\n");
    return 1; }
  who=find_living(who);
  obj=clone_object(what);
  if(!obj)
    { write("Invalid file.\n");
      return 1;
    }
  move_object(obj,who);
  write("Done.\n");
  return 1;
}

goin(str) {
  object who;
  if(!str) return;
  if(!find_living(str)) {
    write("I could not find `"+str+"'.\n");
    return 1; }
  who=find_living(str);
  move_object(this_player(),who);
  write("Done.\n");
  return 1;
}

ul(str) {
  if(!str) return;
  command("load "+str,this_player());
  command("update "+str,this_player());
  write("Done.\n");
  return 1;
}

R(str) {
  if(!find_living("rumplemintz")) { write("Not online.\n"); return 1; }
  command("tell rumplemintz "+str,this_player());
  return 1;
}

Clone(str) {
  if(!str) return;
  move_object(clone_object(str),environment(this_player()));
  return 1;
}

Goto(str) {
  if(!str) return;
  if(!find_living(str)) { write(str+" not found.\n"); return 1; }
  move_object(this_player(),environment(find_living(str)));
  return 1;
}

Post(str) {
  if(str) return;
  move_object(this_player(),"/room/post");
  return 1;
}

Church(str) {
  if(str) return;
  move_object(this_player(),"/room/church");
  return 1;
}

Shop(str) {
  if(str) return;
  move_object(this_player(),"/room/shop");
  return 1;
}
