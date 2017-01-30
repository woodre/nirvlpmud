inherit "room/room";
object play;
reset(arg) {
   if(arg) return;
   set_light(0);
   long_desc =
              "A small room with smooth walls, except for a circular stone that sticks out\n"+
              "of the eastern wall.\n";
    short_desc = "A lateral room";
    dest_dir = ({
                  "/players/trix/castle/quest/doc4","north",
                                                        });
    items=({ "stone","A smooth circular stone sticking out of the eastern wall, it looks like it\n"+
              "can be moved"});
}
init(){
 ::init();
     add_action("push","push");
     }
push(str)
{ if(str=="stone") {
   write("You pushes the stone and the walls starts trembling, then suddenly it turns\n"+
         "around itself dragging you in another room.\n\n");
   move_object(this_player(),"/players/trix/castle/quest/dod5");
   command("look",this_player());
    play=this_player();
   call_out("stampa",2);
   return 1;
   }
  return;
}
realm(){return "NT";}
stampa()
{ tell_object(play,"\nA flash lights the room, you are smashed to the ground by a tremendous power\n"+
        "and as you look above your head you see Melko.\n\n");
  call_out("stampa2",1);
}
stampa2()
{ tell_object(play,"Melko says: Oh mortal one, repent for thy faults, leave here all thy goods.\n");
  call_out("force",1);
}
force()
{ command("drop all",play);
   move_object(play,"/players/trix/castle/quest/dod5_2");
  call_out("stampa3",3);
}
stampa3()
{ object us;
  int x;
  call_other(play,"set_pretitle","Ouch,");
  call_other(play,"set_title","got their butt kicked by Melko!!!");
  emit_channel("junk", "*Ouch!*  *Oof!*  Someone got their butt kicked!\n");
  tell_object(play,"Melko says: Now run away from this place, before I think twice about thy fate!\n");
  call_out("scappa",1);
}
scappa()
{ 
  tell_object(play,"You see another flash, than you lose consciousness and wake in another room...\n");
  command("trixrules",play);
  tell_object(play,"->> ");
}
