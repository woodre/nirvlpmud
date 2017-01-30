object this;
int data;
inherit "obj/monster";
string name;
reset(arg){
   object gold,skirt;
   ::reset(arg);
   if(arg) return;
   set_name("sylvia");
   set_race("human");
   set_alias("sylvia");
   set_short("Sylvia, the sexy bomb");
   set_long("Sylvia is a fair blond babe, she's got a smooth perfect skin that invites you\n" +
            "to caress her. She wears a red tight short dress that shows off her curves,\n"+
            "taking your breath away. She smiles brightly at you and you can't help falling\n"+
            "at her feet.\n");
   set_level(20);
   set_hp(1000);
   set_al(100);
   set_wc(1);
   set_ac(100);
   set_aggressive(0);
   set_chat_chance (10);
   load_chat("Sylvia smiles happily.\n");
   load_chat("Sylvia winks at Karma suggestively.\n");
   load_chat("Sylvia snuggles up at Karma.\n");
}
enable_commands() { return 1; }
catch_tell(str)
{ 
    if(sscanf(str,"%s kisses you.",name)) 
     call_out("kiss",1);
     this=this_player();
}

kiss()
{ object who;
  tell_object(this,"Sylvia kisses you.\n");
  say("Sylvia kisses "+name+".\n",this);
  if(this->query_real_name()=="karma"&&!data) 
   { say("Sylvia says: Wow Karma, your kiss was something special....it deserves a gift.\n");
     say("Sylvia unwraps a pack and give Karma what was inside.\n");
     move_object(clone_object("/players/trix/closed/obj/kblade"),this);
     data=1;
   } 
 return 1;
}
