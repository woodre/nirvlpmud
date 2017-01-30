

short(){
  if(!environment()) return 0;
  if((string)environment()->query_real_name() == "zeus"){
    if(this_player() && (string)this_player()->query_real_name() != "zeus")
      call_out("short_test", 1, this_player());
    if(!present(this_player(), environment(environment())) &&
      (string)this_player()->query_real_name() != "zeus"){
      tell_object(environment(), 
        capitalize((string)this_player()->query_real_name())+
        " just peeked at your inventory.\n");
    }
    else if(present(this_player(), environment(environment())) &&
      ((string)this_player()->query_real_name() != "zeus"))
    {
      return "a long, narrow cane";
/*
"\n\n"+
"o                                  o\n"+
"   o              x             o\n"+
"      o          xxx          o\n"+
"         o       xxx       o\n"+
"            o  ooxxxoo  o\n"+
"             oo xxxxx oo\n"+
"           oo xxxxxxxxx oo\n"+
"         oo xx        xxx oo\n"+
"    xxxxxxxxx  Closer  xxxxxxxxx\n"+
"    xxxxxxxxx     to   xxxxxxxxx\n"+
"         oo xxx  God  xxx oo\n"+
"           oo xx     xx oo\n"+
"             oo xxxxx oo\n"+
"               ooxxxoo\n"+
"                 xxx\n"+
"                 xxx\n"+
"                 xxx\n"+
"                 xxx\n"+
"                 xxx\n"+
"                 xxx\n"+
"                 xxx\n"+
"                 xxx\n"+
"                 xxx\n"+
"                 xxx\n"+
"                 xxx\n"+
"                 xxx\n\n\n";
*/
    }
  }
}

void short_test(object me){
  if(!me) return;
  if(!me->is_player()) return;
/*
  if(me->query_level() < 20)
  {
*/
    if(!random(5))
      tell_object(me, "You suddenly feel a chill run through your body.\n");
/*
  }
  else {
    int a;
    for(a = 0; a < 50; a++)
      tell_object(me, "\n");
  }
*/
}

