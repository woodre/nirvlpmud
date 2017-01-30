inherit "obj/monster";
reset(arg){
   object gold;
   ::reset(arg);
   if(arg) return;
   set_name("butthead");
   set_race("human");
   set_alias("boy");
   set_short("Butthead");
   set_long("This is Butthead, a 15 years old guy wearing shorts and an ACDC t-shirt.\n");
   set_level(14);
   set_hp(210);
   set_al(100);
   set_wc(15);
   set_ac(11);
   set_aggressive(0);
   set_chat_chance (12);
   load_chat("Butthead says: Hey Beavis check this out! \"For good times call\n"+
             "               Beavis's mum 555-5678\".\n");
   load_chat("Butthead says: AC DC rules!\n");
   load_chat("Butthead says: Hey Beavis, I gotta spank my monkey.\n");
   load_chat("Butthead says: Soundgarden kick ass.\n");
   load_chat("Butthead yells: Taaa daaaaan taaa daaaan taa daaaan.\n");
   load_chat("Butthead says: hehe hehe hehe\n");
   load_chat("Butthead says: Butthole surfers kick ass!\n");
   set_chance(10);
   set_spell_dam(random(2)+1);
   set_spell_mess1("Butthead shouts: I'm gonna kick your ass!");
   set_spell_mess2("Butthead shouts: I'm gonna kick your ass!");
   gold=clone_object("obj/money");
   gold->set_money(800 + random(50));
   move_object(gold,this_object());
}
catch_tell(arg)
{ int rand1;
  string name,buf,buf2;
  object who;
  if(sscanf(arg,"%s enters the game.",name)||sscanf(arg,"%s arrives%s",name,buf))
   {  who=present(lower_case(name),environment(this_object()));
      if(who&&call_other(who,"query_gender")=="male")
       { 
      if(who&&call_other(who,"query_real_name")=="trix")
        { if(random(2))    call_out("trix1",1);
          else             call_out("trix2",1);      
          return 1;
        }
         rand1=random(9)+1;
         if(rand1>=7)
            say("Butthead says: This guy must be always complaining.\n");
         else if(rand1>=5) say("Butthead says: This guy has no future.\n");
         else if(rand1>=3) say("Butthead says: This guy sucks.\n");
         else say("Butthead says: This guy looks like a mass murderer.\n");
       }
   }
  else if(sscanf(arg,"Beavis sings: ...highway to hell%s",name))
        call_out("acdc1",1);     
  else if(sscanf(arg,"Beavis says: You shuddup%s",name))
        call_out("acdc2",1);
  else if(sscanf(arg,"Beavis punches Butthead%s",name))
        call_out("monkey",1);
  else if(sscanf(arg,"Beavis says: Oooh, look at those thingies%s",name))
        call_out("cool",1);
  else if(sscanf(arg,"Beavis says: Yes , Soundgarden is cool%s",name))
        call_out("seattle",1);
  else if(sscanf(arg,"Beavis says: Hey Butthead, look at this chick%s",name))
        call_out("come",1);
  else if(sscanf(arg,"Beavis says: Woa! This chick rocks%s",name))
        call_out("shorts",1);

}
trix1() { say("Butthead says: Hey Beavis, Trix is a good dancer, I wish I was more like him!\n");}
trix2() { say("Butthead screams: Hey this Trix guy kicks ass!\n"); }
acdc1() { say("Butthead says: Shuddup Beavis!!! You're ruinin' it, we're missing this\n"+
              "               video and it doesn't even suck!\n"); }
acdc2() { say("Butthead says: Don't make me kick your butt again!\n"); }
monkey() { say("Butthead says: Hey Beavis, spank your own monkey, keep your hands off\n"+
               "               mine!!!\n"); }
cool() { say("Butthead says: Yeaah, she's coool!\n"); }
seattle() { say("Butthead says: Everybody in Seattle is cool!\n"); }
come() { say("Butthead says: Ooooh baby, come to Butthead!\n"); }
shorts() { say("Butthead says: Yea, I like chicks in tight shorts!\n"); }
