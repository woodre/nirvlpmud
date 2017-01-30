inherit "obj/monster";
object who;
reset(arg){
   object gold,sblade;
   ::reset(arg);
   if(arg) return;
   set_name("dealer");
   set_race("human");
   set_alias("dealer");
   set_short("A drug dealer");
   set_long("A bad looking man , he has an unshaved face with a menacing expression , maybe\n" +
      "he thinks you're not here to buy his drug.\n");
   set_level(1);
   set_hp(400);
   set_al(-200);
   set_wc(0);
   set_ac(2013);
   set_aggressive(0);
   set_chat_chance (5);
   load_chat("Drug dealer says: Do u wanna buy some stuff?\n");
   load_chat("Drug dealer says: I got what u need, come on!\n");
   set_chance(10);
   set_spell_dam(1+random(2));
   set_spell_mess1("The dealer kicks your butt");
   set_spell_mess2("The dealer uses his switchblade on your face");
   sblade=clone_object("/players/trix/castle/dismonst/sblade.c");
   move_object(sblade,this_object());
}
catch_tell(arg)
{ string name,first,before;
  if(sscanf(arg,"%s says: %s list%s",name,first,before))
   { name=lower_case(name);
     who=find_player(name);
   if(present(name,environment()) == who)
     call_out("dice",1);
     return 1;
   }
}    
dice()
{
if(who)
    tell_object(who, "\n            .----------------------._____.-----------------------.\n"+
                      "            |----------------------|drugs|-----------------------|\n"+
                      "            |----------------------`-----'-----------------------|\n"+
                      "            | # |       item          | pts healed |    cost     |\n"+
                      "            |----------------------------------------------------|\n"+
                      "            | 1 | joint of marijuana  | (15hp+15sp)| 1800  coins |\n"+
                      "            | 2 | joint of hashish    | (20hp+20sp)| 2400  coins |\n"+
                      "            | 3 | ecstasy             | (40hp+40sp)| 4800  coins |\n"+
                      "            | 4 | dragon acid         | (50hp+50sp)| 6000  coins |\n"+
                      "            | 5 | gram of cocaine     | (full heal)| 10000 coins |\n"+
                      "            `----------------------------------------------------'\n");
     return 1;
}
