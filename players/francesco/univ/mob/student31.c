inherit "obj/monster";
   object gold;
reset(arg){
   ::reset(arg);
  set_name("student");
   set_race("human");
   set_long("As you look at this student, you ask yourself:\n"+
            "How come could we two look like exactly the same?\n"+
            "Did the geneticists succeed in cloning me?\n");

   set_level(13);
   set_hp(200);
   set_al(-10);
   set_wc(17);
   set_ac(10);
 gold = clone_object("obj/money");
 gold->set_money(random(150)+550);
 move_object(gold,this_object());

 set_chat_chance(20);
     
/*
 load_chat(short()+" says: hello, "+this_player()->query_name()+", how are you doing?\n");
*/

}

short() { return this_player() -> query_name();}

id(str) { return ::id(str) ||
          (this_player()?this_player()->query_real_name()==str:0); }

query_name() {
        return (this_player() ? capitalize(this_player() -> query_real_name()): "Clone");}
/*
query_name() {return capitalize(this_player() -> query_real_name());}
*/
init(){
  ::init();
if (this_player()->is_player()) call_out("greeting",3,this_player());
}

greeting(object ob) {
if(!environment()) return ;
tell_room(environment(this_object()),"Hello, "+ob->query_name()+"!"+
         " How are you doing?\n");
return 1;
}
long() { set_name(this_player()->query_real_name());::long(); return 1; } 
