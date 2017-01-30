#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster.c";
string horse_name;
object mounted;
object mounted2;

reset(){
  ::reset();
  horse_name = "Lightning";
}

short(){
string str;
  if(mounted){
    str = mounted->short()+YEL+" mounted upon "+horse_name+" the horse"+OFF;
    return str;
  }
  else{
    str = YEL+horse_name+" the horse"+OFF;
    return str;
  }
}

long(str,remote){
object room;
object ob;
string item;
  if(this_player() != mounted){
    write("blah blah blah blah .\n");
    return 1;
  }
  room = environment(this_object());
  if(room->test_dark())
    return 1;
  if(!str){
    if(remote && this_player()->query_brief()){
      write(room->short()+"\n");
    }
    else{
      room->long();
    }
    ob = first_inventory(room);
    while(ob){
      if(ob!=this_object()){
        if(ob->short()){
          write(ob->short()+".\n");
        }
      }
      ob = next_inventory(ob);
    }
    return 1;
  }
  
    item = lower_case(item);
    ob = mypresent(item,room);
    if(!ob && room->id(item))
      ob = room;
    if(!ob){
      write("There is no "+item+" here.\n");
      return 1;
    }
    ob->long(item);
    return 1;
}

mypresent(item,room){
object ob;
  ob = first_inventory(room);
  while(ob){
    if(ob == this_object()){
    }
    else{
      if(ob->id(item)){
        ob = 0;
        return 1;
      }
    }
    ob = next_inventory(ob);
  }
  return 0;
}

id(str){
object room;
  room = environment(this_object());
  if(mounted && str == mounted->query_real_name()) return 1;
  if( str == "horse") return 1;  
  if(this_player() == mounted){ 
    if(str){
      if(mypresent(str,room))
        return 1;
      if(room->id(str))
        return 1;
      return 0;
    }
    return 0;
   }
}

catch_tell(str){
 if(this_player() && (environment(this_player())==this_object()))
   say(str,mounted);
   
 else
   tell_room(this_object(),str);
}

init(){
  if(environment(this_player()) == this_object()){
    add_action("dismountme","dismount");
    add_action("gallop","gallop");
  }
  else{
    add_action("mountme","mount");
  }
}

mountme(str){
  if(id(str)){
    if(mounted){
      notify_fail(mounted->query_name()+" is already mounting this horse.\n");
      return 0;
    }
    else{
      write("You mount your horse.\n");
      say(this_player()->query_name()+" mounts "+this_player()->query_possessive()+" horse.\n");
      move_object(this_player(),this_object());
      mounted = this_player();
      return 1;
    }
  }
  notify_fail("What would you like to mount?\n");
  return 0;
}

dismountme(){
  move_object(this_player(),environment(this_object()));
  mounted = 0;
  write("You dismount your horse.\n");
  say(this_player()->query_name()+" dismounts "+this_player()->query_possessive()+" horse.\n");
  return 1;
}

gallop(str){
  write("Not done yet.\n");
  return 1;
}