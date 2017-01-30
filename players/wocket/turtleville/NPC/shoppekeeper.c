/*  Added in a destruct object check as compared with the
    village shop.  > 6k worth, and query_dest_flag()
    For some reason it was not desting an item when it had
    this.  The value thing is also an issue: Air could be bought, 
    etc.   - Maledicta    03-17-02   */


#include "/players/wocket/closed/ansi.h"
inherit "obj/monster.c";

reset(arg){
  ::reset(arg);
  if(arg) return 1;

set_name("banus");
set_alias("shoppekeeper");
set_short("An old shoppekeeper");
set_long("This gentle shoppekeeper has been manning his store for many years\n"+
         "now.  Grey has taken some of his hair adding just a bit more\n"+
         "distinction to this already distinguished man.  His clothes lay\n"+
         "slightly tattered but mended well through the passing decades.\n"+
         "Time has been good to him.  You can hear the jingle of coins in\n"+
         "his pocket.\n");
set_race("seussian");
set_al(200);
set_level(14);
set_hp(210);
set_wc(18);
set_ac(11);
add_money(random(1300)+200);
set_chat_chance(5);
load_chat("Banus smiles.\n");
load_chat("Banus says:  What would you like to buy?\n");

set_a_chat_chance(20);
load_a_chat("A soft whistle can be heard before .   .    .\n\n"+BOLD+
            "              T     W      A     C     K       \n\n"+NORM+
            "Banus "+HIR+"smashes"+NORM+" his attacker with his cane.\n");
load_a_chat("Banus' cane whirls coming down hard upon his attacker.\n\n"+HIB+
            "              C R  R  A   A    C       K \n\n"+NORM+
            "Splinters fly everywhere from the "+HIR+"devistating"+NORM+" blow.\n");
}




init(){
    ::init();
    add_action("shoppesell","sell");
    add_action("shoppebuy","buy");
    add_action("list","list");
}

string cut_string(int str,int i){
string newstr;
newstr = str+"                                                    ";
newstr = newstr[0..i];
return newstr;
}


int sell_all(){
object ob;
object next;
  ob = first_inventory(this_player());
while(ob){
  next = next_inventory(ob);
  this_object()->shoppesell(" ",ob);
  ob = next;
}
return 1;
}  

int shoppesell(string str,object ob){
int COST;
int do_destroy;
    if(!str){
      notify_fail("Banus says: What do you want to sell?\n");
      return 0;
    }
if(str == "all"){
    write("You sell all that you have.\n");
    sell_all();
    return 1;
}
if(!ob) ob = present(str,this_player());
    if(!ob){
      notify_fail("Banus says: You don't have that to sell.\n");
      return 0;
    }
  if(ob->query_value() > 6000) do_destroy = 1;
  if(ob->query_dest_flag()) do_destroy = 1;
  if(ob->query_no_sell()){
    notify_fail("Banus says: I couldn't possibly take that from you.\n");
    return 0;
  }
    if((int)ob->drop() == 1){
      notify_fail("Banus says: You can't sell that.\n");
      return 0;
    }
COST = (int) ob->query_value();
  if(COST > 1000){
     COST = 1000;
  }
  if(COST < 1){
/* This causing problems with ob->short() -Snow 5/99
     destruct(ob);
*/
  notify_fail("Banus says: That is worthless to me.\n");
    return 0;
  }
write("You give "+ob->short()+" to Banus.\n");
say(this_player()->query_name()+" gives "+ob->short()+" to Banus.\n",this_player());
write("Banus gives you "+COST+" coins.\n");
say("Banus gives "+this_player()->query_name()+" "+COST+" coins.\n",this_player());
tell_room(environment(this_object()),"Banus takes the object to the back and promptly returns empty handed.\n");
this_player()->add_money(COST);
if(do_destroy){
  destruct(ob);
  write("The valuable item is hidden away.\n");
  }
else{
move_object(ob,"/players/wocket/turtleville/tville_storage.c");
}
this_player()->recalc_carry();
return 1;
}

shoppebuy(string str){
object ob;
object room;
int COST;
  
  if(!str){
    notify_fail("Banus says: What would you like to buy?\n");
    return 0;
  }
room = find_object("/players/wocket/turtleville/tville_storage.c");
ob = present(str,room);
  if(!ob){
    notify_fail("Banus says: I'm sorry, but I don't have that to sell you.\n");
    return 0;
  }
COST = (ob->query_value()+ob->query_value()) - (ob->query_value()/15);
  if(this_player()->query_money() < COST){
    notify_fail("Banus says: I'm sorry, but you don't have enought money.\n");
    return 0;
  }
  if(!this_player()->add_weight(ob->query_weight())){
    notify_fail("Banus says: I'm sorry, but you can not carry that.\n");
    return 0;
  }

write("You give "+COST+" coins to Banus.\n");
say(this_player()->query_name()+" gives "+COST+" coins to Banus.\n",this_player());
tell_room(environment(this_player()),"Banus rushes off to the back room.\n");
tell_room(environment(this_player()),"Banus returns with "+ob->short()+".\n");
write("Banus gives "+ob->short()+" to you.\n");
say("Banus gives "+ob->short()+" to "+this_player()->query_name()+".\n",this_player());
this_player()->add_money(-COST);
move_object(ob,this_player());
this_player()->recalc_carry();
return 1;
}


list(){
object ob;
object next;
int VALUE;
    write("Banus says:  I can sell you:\n\n");
    write("  COST      ITEM\n");
ob = first_inventory("/players/wocket/turtleville/tville_storage.c");
while(ob){
    VALUE = (ob->query_value() + ob->query_value())-(ob->query_value()/15);
    next = next_inventory(ob);
    write("  "+cut_string(VALUE,5)+"    "+ob->short()+"\n");
    ob = next;
}
return 1;
}
