object george;
inherit "room/room";
 
reset(arg) {
  if(arg) return;
  set_light(1);
  long_desc = 
"  You are walking along the Main Road of Trixtown.  To the north you can see\n"+
"the Trixtown general shop, while to your south there's a nice bakery.  The\n"+
"Main Road continues from east to west.\n";
   short_desc = "Trixtown Main Road";
   dest_dir = ({ "/players/trix/castle/town/shop.c", "north",
                 "/players/trix/castle/town/bakery.c", "south",
                 "/players/trix/castle/town/trixplaza.c", "west",
                 "/players/trix/castle/town/mainroad1.c", "east"});
   starta_george();
}

starta_george() {
    if(!george || !living(george)) {
        george = clone_object("obj/monster");
        call_other(george, "set_name", "george");
        call_other(george, "set_alias", "man");
        call_other(george, "set_short", "George the sandwich-man");
        call_other(george, "set_long", "George is stuck between two big sheets of cardboard.\n");
        call_other(george, "set_ac", 2049);
        call_other(george, "set_level",6);
        call_other(george, "set_al",50);
        call_other(george, "set_ep",2283);
        call_other(george, "set_hp",30);
        call_other(george, "set_wc",0);
        call_other(george, "set_aggressive", 0);
        move_object(george, "/players/trix/castle/town/mainroad2");
        call_other(george, "set_object", this_object());
        call_other(george, "set_chat_chance",20);
        call_other(george, "set_a_chat_chance", 33);
        call_other(george, "load_chat", "George says: Trixtown shop!!! Trixtown shop!!!\n");
        call_other(george, "load_chat", "George says: Good rewards for selling valuable items!!!\n");
        call_other(george, "load_chat", "George says: Go to Trixtown shop!!!\n");
        call_other(george, "load_a_chat", "George says: " +
                   "Don't hit me!\n");
        call_other(george, "load_a_chat", "George says: " +
                   "That hurt!\n");
        call_other(george, "load_a_chat", "George says: " +
                   "Help, someone!\n");
        call_other(george, "load_a_chat", "George says: " +
                   "Why can't you go bullying elsewhere?\n");
        call_other(george, "load_a_chat", "George says: " +
                   "Aooooo!!!\n");
        call_other(george, "load_a_chat", "George says: " +
                   "I hate bashers!\n");
        call_other(george, "load_a_chat", "George says: " +
                   "Bastard!\n");
        call_other(george, "load_a_chat", "George says: " +
                   "You big brute!\n");
/*       call_other(george, "set_random_pick", 20); */
        call_other(george, "set_move_at_reset", 0);
        call_out("muovi",1);
    }
}
muovi()
 {
  if(george) george->random_move();
  call_out("muovi",16);
  return 1;
}
