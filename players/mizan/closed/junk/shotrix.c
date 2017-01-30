inherit "obj/weapon";
   int power,percent,amount,charge;
   object carica,aim,nomeaim;
init()  
 {
   add_action("shoot","shoot");
   add_action("insert","insert");
   add_action("help","help");
   add_action("info","info");
add_action("wield", "wield");
add_action("stopwield", "unwield");
   return 1;
 }

reset(arg){
   if(arg) return;
   ::reset(arg);
    charge=25;
   set_name("trix-71");
   set_alt_name("shotgun");
   set_alias("gun");
   set_short("A trix-71 automatic shotgun");
   set_class(18);
   set_weight(4);
   set_value(5000);
}

long()
 {  write("This is a trix-71 automatic shotgun, a devastating weapon very useful in massive\n"+
          "monster slaughters, type 'help trix-71' to see more.\n"+
          "The gun is loaded with "+charge+" shots.\n");
    return 1;
 }

shoot()
 {
   if(!call_other(this_player(),"query_attack",)) { write("*** You're not fighting anyone!\n"); return 1; }
   if(!charge) { write("*** Your trix-71 is unloaded.\n"); return 1; }
   aim=call_other(this_player(),"query_attack",);
   nomeaim=call_other(aim,"query_name",);
   power=random(6)+5;
   percent=(power*100)/10;
   charge--;
   call_other(aim,"hit_player",power);
   write("*** You shoulder your trix-71,pull the trigger and a dumdum bullet hits the aim.\n"+
         "*** Released power: "+percent+"%.\n"+
         "*** You have "+charge+" shots left.\n");
   say(call_other(this_player(),"query_name",)+" shots "+nomeaim+" with his trix-71 shotgun.\n",this_player());     
   return 1;
 }
insert(arg)
 {
   if(arg!="clip") { return 0; }
   carica=present("cartridge clip",this_player());
   if (!carica) { write("*** You have no cartridge clip , go buying one at the recharger.\n"); return 1; }
   if (charge>=1) { write("*** Your trix-71 still has "+charge+" shots left.\n"); return 1; }
   charge=25;
   write("*** You insert the clip, your trix-71 shines bright, you now have 25 shots.\n");
    say(call_other(this_player(),"query_name",)+" insert a clip in hi71 that shines with power.\n");
   destruct(carica);
   return 1;
 }
recharge(arg)
 { 
   if(arg<1) { write("*** You can't do that.\n"); return 1; }
   if(arg+charge>25) { write("*** You can't load more than 25 bullets in this gun.\n"); return 1; }
   amount=arg*200;
   if(amount>query_money(this_player())) { write("*** You don't have enough money for "+arg+" bullets.\n"); return 1; }
   charge=charge+arg;
   write("*** You load "+arg+" bullets in your trix-71.\n");
   call_other(this_player(),"add_money",-amount);
   return 1;  
 }
help(arg)
 {
   if(arg=="trix-71")
    { cat("/players/trix/helpdir/helpgun");
      return 1;
    }   
 }

info(arg)
 {
   if(arg=="trix-71")
    { cat("/players/trix/helpdir/guninfo");
      return 1;
    }   
 }
