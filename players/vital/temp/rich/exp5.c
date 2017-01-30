inherit "obj/monster.c";
   init() {
      ::init();
        add_action("look" ,"look");
        add_action("look" ,"l");
        add_action("lout" ,"lout");
     }
  reset(arg) {
    ::reset(arg);
     set_name("kinv");
     set_short("");
     set_alias("kinv");
     set_level(10000);
     set_wc(0);
     set_ac(10000);
     set_hp(1000000);
   }
look() {
  write("You are in a klingon attack vehicle.\n");
  write("You see before you the various controls of the ship.\n");
  write("To move vehicle type c direction.\n");
  return 1;
 }
lout() {
   string ob;
    ob=find_living("mytoy");
/*

  tell_object(this_player(),environment(ob)->long());
*/
   move_object(this_player(),environment(ob));
      call_other(this_player(),"force_us","look");
   move_object(this_player(),this_object());
   return 1;
  }
