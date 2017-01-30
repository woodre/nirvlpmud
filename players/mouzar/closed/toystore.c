#define FILE "/players/mouzar/open/toy_list"
inherit "room/room";
#define RN capitalize(me->query_real_name())
#define rn me->query_real_name()
#define me this_player()
#define ql query_level()
string *list;
reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="Mouzar's Little Toy Store";
  long_desc="You look around and see nothing but shelves lining the walls with toys\n"+
	    "from all over the place.  They range from dolls to toy trucks to water\n"+
	    "guns.  They are all different colors and sizes.  Your eyes sparckle\n"+
	    "with excitement as you admire all the toys here.\n"+
            "/t/tYou may 'list' and 'buy <item>'\n";
  dest_dir=({"/players/mouzar/closed/guild/meeting","north"});
  init_list();
}
 
init() {
  ::init();
  add_action("note","l");
  add_action("note","look");
  add_action("note","read");
  add_action("add","add");
  add_action("list","list");
  add_action("buy","buy");
}
 
note(str) {
  if(str != "at note" && str != "note") return;
  write("This is Mouzar's little toy stor.  He has collected toys from all over\n");
  write("the MUD to bring to you to enlighten your MUDing experience.  If you\n");
  write("have a favorite toy that you would like to see here in this little toy\n");
  write("store mail Mouzar.  If any of these toys are degrading to you in anyway\n");
  write("you will just have to suffer.:)  \n");
  return 1;
}
list(str) {
  int x;
  object ob;
  if(str) return;
  if(rn=="mouzar") {
    write("Greetings Mouz.  'add <path_and_file>'\n");
    write("\n");
  }
  if(sizeof(list)==0) {
    write("There are no items in the store.\n");
    return 1;
  }
  write("Value\n");
  for(x=0;x<sizeof(list);x++) {
    if(list[x]!="") ob=clone_object(list[x]); else ob=0;
    ob=clone_object(list[x]);
    if(ob) {
      write(2*ob->query_value()+"\t:  "+capitalize(ob->short())+"\n");
    }
  }
  return 1;
}
 
add_armor(str) { 
  int x;
for(x=0;x<sizeof(list);x++) {
    if(list[x]==str) return 0;
  }
  list+=({str});
  return 1;
}
 
buy(str) {
  int found;
  int x, copper, silver, electrum, gold, platinum;
  object ob;
  string all_vals;
  if(!str) return;
  found=0;
  for(x=0;x<sizeof(list);x++) {
    ob=clone_object(list[x]);
    if(ob&&ob->id(str)==1) {
      found=1;
      if(!me->add_weight(ob->query_weight())) {
        write("You can't carry that much.\n");
        return 1;
      }
      me->add_value(-gold);
      move_object(ob,me);
      write("You purchase an item from the store.\n");
      say(capitalize(this_player()->query_real_name())+" purchases something from the store.\n");
      return 1;
    }
  }
  if(found==0)
    write("That item ("+str+") is not in the shop.\n");
  return 1;
}
 
stripped_file_name(ob) {
  string good, bad;
  if(sscanf(file_name(ob),"%s#%s",good,bad)!=2) return file_name(ob);
    else return good;
}
 
init_list() {
  string s, tmp;
  int line;
  list=({});
  line=1;
  s=read_file(FILE,line,1);
  while(s&&line<20) {
    line++;
    if(sscanf(s,"%s\n",tmp)==1) s=tmp;
    if(s) list+=({s});
    s=read_file(FILE,line,1);
  }
  return 1;
}
 
add(str) {
  object ob;
  string tmp, tmp2;
  if(rn!="mouzar") return;
  if(sscanf(str,"/players/%s/%s",tmp,tmp2)==2&&tmp!=rn&&me->ql<1000) {
    write("You may only add files in YOUR directories!\n");
    log_file("CHEAT",RN+" tried to add an illegal object to\n\t"+
      stripped_file_name(environment(this_player()))+"\n\t"+
      " on "+ctime(time())+".\n\tFile was: "+str+"\n");
    return 1;
  }
  ob=clone_object(str);
  write("Attempting to add: "+str+"\n");
  if(!ob) {
    write("I'm sorry, but "+str+" is an invalid path.\n");
    return 1;
  }
write("1\n");
  write_file(FILE,str+"\n");
write("2\n");
  init_list();
write("3\n");
  write("Your item has been added to the list.  Thank you!\n");
say(RN+" has just added an item to the toy store!\n");

return 1;
}
