inherit "obj/weapon";
object who;
reset(arg){
   if(arg) return;
   ::reset(arg);
   set_name("ring");
   set_short("Melko's Ring of Power");
   set_long("This is Melko's Ring of Power, it's made with fine gold and a wierd strong\n"+
           "metal that you don't know. There is an inscription in its inner circle.\n");
   set_class(2);
   set_weight(1);
   set_value(10000);
   set_alias("melkoring");
}
init(){
 ::init();
    add_action("read","read");
    add_action("wea","wield");
}
read(str)
{ if(str!="inscription") return;
  write("The inscrition says: This is the ring of the powerful Melko, He's the only one\n"+
        "                     that can control its power. The ring will destroy itself \n"+
        "                     if wielded by anyone else.\n");
  return 1;
}

/* Changed by Rumplemintz - auto monster wield/wear bugging this quest */
#if 0
wea(str)
{ if(str=="ring") { write("You try to wield the ring and...\n");
                    who=this_player(); 
                    call_out("final",1); 
                    return 1; }
}
#else
int wea(string str) {
  if (str == "ring" && !environment(this_object())->is_npc()) {
    write("You try to wield the ring and...\n");
    who = this_player();
    call_out("final", 1);
    return 1;
  }
  else return 0;
}
#endif

final()
{ object us,flowers;
  int x;
  us = users();
  for(x=0;x<sizeof(us);x++)
      if(us[x]!=who&&!in_editor(us[x]))
          tell_object(us[x],"The ground trembles beneath you... Something important just happened.\n");
  tell_object(who,"\nSuddenly the rings starts to tremble on your finger, it gets hot and with a\n"+
                            "thunder it explodes in thousands of pieces.\n");
  tell_object(who,"\n                  Congratulations, you solved Melko's quest!!!!!!!!!\n");
  call_other(who,"add_ac",-2);
      call_other(who,"set_pretitle","Yayyyy,");
      call_other(who,"set_title","kicked Melko's b*tt!!!");
      call_other(who,"set_quest","melko"); 
      flowers=clone_object("/players/trix/castle/quest/monst/flowers");
      tell_object(who,"                      Trix sends you a bunch of flowers.\n->> ");
      move_object(flowers,who);
      destruct(this_object());
}
