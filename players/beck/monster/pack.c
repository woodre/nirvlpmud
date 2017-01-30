/* The Pack of the Wild Hunt  */

inherit "/obj/monster.c";
int quantity;
reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("pack of the wild hunt");
   set_level(20);
   set_alt_name("hunt");
   set_alias("pack");
   set_wc(30);
   set_ac(30);
   set_hp(600);
   set_al(0);
   set_race("magic");
   quantity = 20;
   set_dead_ob(this_object());
   call_out("hurt_pack",12);
   call_out("inform",4000);
}
short(){
   return "The Pack of the Wild Hunt\n"+
   "("+query_quantity()+") Dogs";
}
long(){
   write("A pack of ghostly dogs with red eyes and flames for tounges.\n");
write("There are "+query_quantity()+" dogs.\n");
   return 1;
}
set_quantity(arg){
   quantity = arg;
   return 1;
}
query_quantity(){
   return quantity;
}
hurt_pack(){
if(!present("hunter", environment(this_object()))){
tell_room(environment(this_object()),"The dogs suddenly all vanish into thin air.\n");
destruct(this_object());
return 1;
}
   if(query_hp() < (30*query_quantity())-30){
      set_quantity(query_quantity()-1);
      set_wc(10+query_quantity());
      set_ac(10+query_quantity());
      say("One of the dogs suddenly dissapears into thin air.\n"+
         "There are "+query_quantity()+" dogs left.\n");
      call_out("hurt_pack",12);
      return 1;
   }
   call_out("hurt_pack", 12);
   return 1;
}
monster_died(object monster){
   object corpse;
   corpse = present("corpse", environment(this_object()));
   say("As you kill the pack of dogs, and the last one dissapears into the night\n"+
      "You feel uncomfortable as the Master of the Hunt turns his attention to you.\n"+
      "");
   destruct(corpse);
   return 0;
}
inform(){
string message;
message = "You hear a pack of wild dogs howling in the distance.\n";
"obj/user/one_chan.c"->chan_msg(message,"junk");
   call_out("inform",4000+random(1000));
   return 1;
}
