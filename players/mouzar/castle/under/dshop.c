#define FILE "/players/mouzar/open/dshop_list"
inherit "room/room";
#define RN capitalize(me->query_real_name())
#define rn me->query_real_name()
#define me this_player()
#define ql query_level()
string *list;
reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="Drow Shop";
  long_desc="This is a well kept little shop.  There are all kinds of stuff that line\n"+
            "the shelves.  Some of the things that are on the shelves you can only\n"+
            "imagine and hope that they are not used for what your are thinking.\n"+
            "Better not steal anything or you might find out.\n"+
            "\t\tThe commands are: 'list' and 'buy <item>'\n";
  dest_dir=({"/players/mouzar/castle/under/under24","west"});
  init_list();
if(!present("keeper"))
move_object(clone_object("/players/mouzar/castle/under/mon/dkeeper"),this_object());
}
 
init() {
  ::init();
  add_action("add","add");
  add_action("list","list");
  add_action("buy","buy");
  add_action("sell","sell");
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
  write("Platinum\tElectrum\tCopper\n\tGold\t\tSilver\n");
  for(x=0;x<sizeof(list)-1;x++) {
    if(list[x]!="") ob=clone_object(list[x]); else ob=0;
    ob=clone_object(list[x]);
    if(ob) {
      write(2*ob->query_platinum()+"\t");
      if(ob->query_value()) write(2*ob->query_value()+"\t");
        else write(2*ob->query_gold()+"\t");
      write(2*ob->query_electrum()+"\t"+ob->query_silver()*2+"\t");
      write(2*ob->query_copper()+"\t:  "+capitalize(ob->short())+"\n");
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
  for(x=0;x<sizeof(list)-1;x++) {
    ob=clone_object(list[x]);
    if(ob&&ob->id(str)==1) {
      found=1;
      all_vals=ob->query_all_values();
      if(all_vals!=0)
        sscanf(all_vals,"%d#%d#%d#%d#%d",copper,silver,electrum,gold,platinum);
        else {
        copper=ob->query_copper(); silver=ob->query_silver(); gold=ob->query_gold();
        electrum=ob->query_electrum(); platinum=ob->query_platinum();
        }
      if(ob->query_value()>0) gold=ob->query_value();
       copper*=2; silver*=2; electrum*=2; gold*=2; platinum*=2;
      if(copper>me->query_copper()||silver>me->query_silver()||
         electrum>me->query_electrum()||gold>me->query_gold()||
         platinum>me->query_platinum()) {
        write("You do not have enough money.\n");
        return 1;
      }
      me->add_copper(-copper);
      me->add_silver(-silver);
      me->add_electrum(-electrum);
      me->add_gold(-gold);
      me->add_platinum(-platinum);
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
 
sell(str) {
  object ob;
  int x, found, copper, silver, electrum, gold, platinum;
  string all_vals;
  if(!str) return;
  if(!present(str,me)) {
    write("You do not have that item ("+str+").\n");
    return 1;
  }
  found=0;
  for(x=0;x<sizeof(list);x++) {
    ob=present(str,me);
    if(list[x]==stripped_file_name(ob)||list[x]=="/"+stripped_file_name(ob))
      found=1;
  }
  if(found==0) {
    write("You may not sell that item here.\n");
    return 1;
  }
  all_vals=ob->query_all_values();
  if(all_vals)
    sscanf(all_vals,"%d#%d#%d#%d#%d",copper,silver,electrum,gold,platinum);
    else { copper=0; silver=0; electrum=0; gold=ob->query_value(); platinum=0; }
  me->add_copper(copper);
  me->add_silver(silver);
  me->add_electrum(electrum);
  me->add_gold(gold);
  me->add_platinum(platinum);
  write("You sell the item to the store.\n");
  say(capitalize(this_player()->query_real_name())+" sells something to the store.\n");
  destruct(ob);
  return 1;
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
  say(RN+" has just added an item to the store.\n");
  return 1;
}
