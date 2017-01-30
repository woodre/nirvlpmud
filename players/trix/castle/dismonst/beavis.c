inherit "obj/monster";
reset(arg){
   object gold;
   ::reset(arg);
   if(arg) return;
   set_name("beavis");
   set_race("human");
   set_alias("boy");
   set_short("Beavis");
   set_long("This is Beavis, a 15 years old guy wearing shorts and a Metallica t-shirt.\n");
   set_level(14);
   set_hp(210);
   set_al(100);
   set_wc(15);
   set_ac(11);
   set_aggressive(0);
   set_chat_chance (12);
   load_chat("Beavis yells 'Fire fire fire !!!!'\n");
   load_chat("Beavis burps.\n");
   load_chat("Beavis says: hehe hehe hehe\n");
   load_chat("Beavis pulls down his shorts and moons you.\n");
   load_chat("Beavis screams '..push a little daisy and make it come up'\n");
   load_chat("Beavis says: hehe hehe hehe\n");
   load_chat("Beavis punches Butthead in the groin.\n");
   load_chat("Beavis says: Het Butthead, check this out.\n");
   set_chance(10);
   set_spell_dam(random(2)+1);
   set_spell_mess1("Beaves screams: HELP HELP BUTTHEAD, IT SUCKS!.");
   set_spell_mess1("Beaves screams: HELP HELP BUTTHEAD, IT SUCKS!.");
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
      if(who&&call_other(who,"query_gender")=="female")
       { rand1=random(9)+1;
         if(rand1>=7)
            say("Beavis says: Hey Butthead, look at this chick!\n");
         else if(rand1>=5) say("Beavis says: Oooh, look at those thingies!!!\n");
         else if(rand1>=3) say("Beavis says: This chick kicks ass!\n");
         else say("Beavis says: Woa! This chick rocks!\n");
       }
   }
  else if(sscanf(arg,"%sAC%sDC%s",name,buf,buf2))
        call_out("acdc1",1);     
  else if(sscanf(arg,"Butthead says: Shuddup Beavis!%s",name))
        call_out("acdc2",1);
  else if(sscanf(arg,"Butthead says: Hey Beavis, I gotta spank my monkey%s",name))
        call_out("monkey",1);
  else if(sscanf(arg,"Butthead says: This guy must be always complaining%s",name))
        call_out("compla",1); 
  else if(sscanf(arg,"Butthead says: This guy has no future%s",name))
        call_out("burn",1);
  else if(sscanf(arg,"Butthead says: This guy sucks%s",name))
        call_out("really",1);
  else if(sscanf(arg,"Butthead says: This guy looks like a mass murderer%s",name))
        call_out("murder",1);
  else if(sscanf(arg,"Butthead says: Soundgarden kick ass%s",name))
        call_out("seattle",1);
  else if(sscanf(arg,"%s555-5678",name))
        call_out("number",1);
}
acdc1() { say("Beavis sings: ...highway to hell... highway to hell...\n"); }
acdc2() { say("Beavis says: You shuddup, don't make me smack you.\n");}
monkey(){ say("Beavis says: I think birth control is an important issue in a man's life!\n"); }
compla(){ say("Beavis says: I guess I was complaining too if I sucked.\n"); }
burn() { say("Beavis says: Let's burn him!!! Fire fire fire!!!!!\n"); }
really() { say("Beavis says: Yea, this guy does really suck!\n"); }
murder() { say("Beavis says: Yes, DAMN!!\n"); }
seattle() { say("Beavis says: Yes , Soundgarden is cool!\n"); }
number() { say("Beavis says: No, call Butthead's dad!\n"); }
