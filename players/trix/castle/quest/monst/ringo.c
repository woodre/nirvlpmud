inherit "obj/armor";
object who;
reset(arg){
   ::reset(arg);
   set_short("Melko's Ring of Power");
   set_long("This is Melko's Ring of Power, it's made with fine gold and a wierd strong\n"+
      "metal that you don't know. There is an inscription in its inner circle.\n");
   set_ac(2);
   set_weight(1);
   set_value(10000);
   set_alias("melkoring");
   set_name("ring");
   set_type("ring");
}
init(){
 ::init();
    add_action("read","read");
   add_action("wear", "jkjkjkjk");
    add_action("wea","wear");
}
read(str)
{ if(str!="inscription") return;
  write("The inscrition says: This is the ring of the powerful Melko, He's the only one\n"+
        "                     that can control its power. The ring will destroy itself \n"+
        "                     if worn by anyone else.\n");
  return 1;
}
wea(str)
{ if(str=="ring") { command("jkjkjkjk ring",this_player());
                    who=this_player(); 
                    if(call_other(this_object(),"query_worn")) call_out("final",1); 
                    return 1; }
}
final()
{ object flowers;
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
