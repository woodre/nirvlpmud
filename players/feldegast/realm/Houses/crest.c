#include "/players/feldegast/defines.h"
#define PATH "/players/feldegast/realm/Houses/"
#define LINE "--------------------------------------------------------\n"

string house_name;


int id(string str) {
  return str=="crest" || str==house_name || str=="house id";
}

void long(string str) {
  write("You bear the crest of House "+house_name+".  For more\n"+
        "information on it, type <"+BOLD+"house_cmds"+NORM+">.\n");
}

string extra_look() {
  return environment(this_object())->query_name()+" bears the crest of House "+house_name;
}

drop() { return 1; }
get() { return 0; }

void init() {
  CHANNEL->register(TP,house_name);
  add_action("do_talk",lower_case(house_name));
  add_action("do_house_cmds","house_cmds");
  add_action("cmd_house_who","house_who");
  add_action("cmd_house_history","house_history");
  add_action("cmd_house_title","house_title");
  add_action("cmd_house_sponsor","house_sponsor");
  add_action("cmd_refresh","1234");
  add_action("cmd_party","form");
}

void set_house_name(string str) {
  house_name=str;
}
string query_house() {
  return house_name;
}

int do_talk(string str) {
  if(!str) {
    object *us;
    int i;
    us=(object *)CHANNEL->users(house_name);
    write("House "+house_name+"\n");
    write("================\n");
    for(i=0; i<sizeof(us); i++)
      write(us[i]->query_name()+"\n");
    return 1;
  }
  if(str[0]==':')
    CHANNEL->broadcast(house_name,"<"+BOLD+house_name+NORM+"> "+
                       TPN+" "+str[1..strlen(str)]+"\n");
  else
    CHANNEL->broadcast(house_name,"<"+BOLD+house_name+NORM+"> "+
                       TPN+" says: "+str+"\n");
  return 1;
}
int do_house_cmds(string str) {
  cat(PATH+"help.txt");
  return 1;
}

remove_object() {
  CHANNEL->deregister(TP,house_name);
}

greater_fun(ob1,ob2) {
  int l1,l2;
  l1=ob1->query_level();
  l2=ob2->query_level();
  if(l1==l2)
    return ob1->query_extra_level() < ob2->query_extra_level();
  else
    return l1 < l2;
}

cmd_house_who(str) {
  object *world;
  object cn;
  string area_name,wiz_name;
  int i,max;
  max=sizeof(users());
  world=users();
  world=sort_array(world,"greater_fun",this_object());
  write("\n");
  write(LINE);
  write(
" Name           Level   Guild  House         Area\n");
  write(LINE);
  for(i=0;i<max;i++) {
    if(world[i]->query_invis() < TP->query_level()) {
      if(world[i]->query_pl_k())
        write(RED+"*"+NORM);
      else
        write(" ");
      write(pad((string)world[i]->query_name(),15));
      write(pad((string)world[i]->query_level()+"+"+world[i]->query_extra_level(),7));
      write(" ");
      write(pad((string)world[i]->query_guild_name(),5));
      write("  ");
      cn=present("house id",world[i]);
      if(cn)
        write(pad(cn->query_house(),10));
      else
        write(pad(" ",10));

      if(environment(world[i])) {
        if((string)environment(world[i])->realm()=="NT")
          write(HIB+"X"+NORM);
        else
          write(" ");
        if(world[i]->query_fight_area())
          write(RED+"*"+NORM);
        else
          write(" ");
        if((string)environment(world[i])->realm() == "NM")
          write(MAG+"#"+NORM);
        else
          write(" ");
        write(" ");

        wiz_name=creator(environment(world[i]));

        if(wiz_name)
          write(pad(capitalize(wiz_name),15));
        else
          write(pad("Nirvana",15));
      }
      cn=0;
      wiz_name=0;
      write(NORM+"\n");

    }
  }
  write(LINE);
  return 1;
}
cmd_house_history() {
  string *chats;
  int i;
  write(house_name+" History\n");
  write("====================\n");
  chats=CHANNEL->query_history(house_name);
  for(i=0;i<sizeof(chats);i++)
    write(chats[i]);
  write("\n");
  return 1;
}

cmd_house_title() {
  TP->set_title("of House "+house_name);
  write("You are now "+TPN+" "+TP->query_title()+".\n");
  return 1;
}

cmd_house_sponsor(str) {
  object target;
  object ob;
  if(!str) {
    write("Usage: house_sponsor <player>\n");
    return 1;
  }
  target=present(str,environment(TP));
  if(ob=present("house id",target)) {
    write("That person is a member of House"+ob->query_house()+"!\n");
    return 1;
  }

  ob=clone_object(PATH+"crest");
  ob->set_house_name(house_name);
  move_object(ob,target);
  write("You bestow the crest of House "+house_name+" upon "+target->query_name()+".\n");
  tell_object(target,"You have been inducted into House "+house_name+"!\n"+
                     "Type <"+BOLD+"house_cmds"+NORM+"> for more information.\n");
  tell_room(environment(TP),TPN+" bestows the crest of House "+house_name+" upon "+target->query_name()+".\n",({ TP, target }));
  CHANNEL->broadcast(house_name,target->query_name()+" has been inducted into House "+house_name+"!\n");
  return 1;
}
cmd_refresh() {
  object ob;
  ob=clone_object(PATH+"crest");
  ob->set_house_name(house_name);
  destruct(this_object());
  move_object(ob,TP);
  return 1;
}
cmd_party(str) {
  object ob;
  if(!str || str!="party") return 0;
  if(present("party_object",TP)) {
    notify_fail("You already have a party object.\n");
    return 0;
  }
  write("You form a new party.\n");
  ob=clone_object("/obj/partyob");
  move_object(ob,TP);
  return 1;
}
