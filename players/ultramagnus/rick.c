   inherit "obj/monster";
   reset(arg) {
  object gold;
   ::reset(arg);
     if(arg) return;
    gold=clone_object("obj/money");
    gold->set_money(750);
    move_object(gold, this_object());
 set_name("rick");
 set_level(17);
 set_al(350);
 set_wc(15);
 set_hp(425);
 set_aggressive(0);
      move_object("players/magnum/items/shade", this_object());
        command ("wear shades");
       move_object("players/magnum/items/jacket", this_object());
        command ("wear jacket");
       move_object("players/magnum/items/shoe", this_object());
         command ("wear boots");
   set_short("Rick The Stud");
   set_long("This is Rick!  He is also known as 'Rick The Stud'\n"+
            "because he dresses nice and always with some 'HOT'\n"+
            "looking woman every other days.\n");
    set_chat_chance(8);
   load_chat("Rick says: Hey man! How's it going?\n");
   load_chat("Rick says: Hey! You like my clothes..\n");
   load_chat("Rick whispers to you: What do you think of the babe?\n");
   load_chat("Rick does the M.C. Hammer.\n");
   load_chat("Rick takes Tracy and do the Lambada.\n");
    set_a_chat_chance(6);
   load_a_chat("Rick says: Hey! How come you are hitting me?\n");
   load_a_chat("Rick says: Don't screw up with my threat dude!\n");
   load_a_chat("Rick says: If you want one of my babes, just say so!\n");
   set_ac(13);
 }
