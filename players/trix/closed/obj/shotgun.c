inherit "obj/weapon";
   int power,percent,amount,charge;
   object carica,aim,nomeaim;
init()  
 {
   add_action("shoot","sho");
   add_action("shoot","shoot");
   add_action("insert","insert");
   add_action("help","help");
   add_action("info","info");
   add_action("ext_wield", "wield");
   add_action("ext_unwield", "unwield");
   return 1;
 }

reset(arg){
   if(arg) return;
   ::reset(arg);
   set_name("trix-71");
   set_alt_name("shotgun");
   set_alias("gun");
   set_short("A trix-71 automatic shotgun");
   set_class(18);
   set_weight(3);
   set_value(5000);
}

ext_wield(str)
{ call_other(this_object(),"wield",str); return 1; }
ext_unwield(str)
{ call_other(this_object(),"stopwield"); return 1; }
long()
 { int wear;
   write("This is a trix-71 automatic shotgun, a devastating weapon very useful in massive\n"+
         "monster slaughters, type 'help trix-71' to see more.\n"+
         "The gun is loaded with "+charge+" shots.\n");
   write("It is ");
   wear=query_wear();
   if(wear < 40) write("like new.\n");
   if(wear > 39 && wear < 100) write("a little worn.\n");
   if(wear > 99 && wear < 200) write("somewhat worn.\n");
   if(wear > 199 && wear < 400) write("worn.\n");
   if(wear > 399) write("well worn.\n");
   if(this_player()->query_level() > 100) { write("Wear = "+wear+"\n");
   write("Hits = "+hits+"    Misses = "+misses+"\n");
   }
   return 1;
 }


shoot()
 {
   if(!call_other(this_player(),"query_attack",)) { write("*** You're not fighting anyone!\n"); return 1; }
   if(!charge) { write("*** Your trix-71 is unloaded.\n"); return 1; }
   aim=call_other(this_player(),"query_attack",);
   nomeaim=call_other(aim,"query_name",);
   power=random(6)+10;
   percent=(power*100)/15;
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
   charge=5;
   write("*** You insert the clip, your trix-71 shines bright, you now have 5 shots.\n");
    say(call_other(this_player(),"query_name",)+" inserts a clip in hi71 that shines with power.\n");
   destruct(carica);
   return 1;
 }
recharge(arg)
 { 
   if(arg<1) { write("*** You can't do that.\n"); return 1; }
   if(arg+charge>5) { write("*** You can't load more than 5 bullets in this gun.\n"); return 1; }
   amount=arg*150;
 if(amount>call_other(this_player(),"query_money",)) { write("*** You don't have enough money for "+arg+" bullets.\n"); return 1; }
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
