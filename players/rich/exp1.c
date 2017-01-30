inherit "obj/monster.c";
   init() {
     ::init();
        add_action("wear" ,"wear");
      }
   reset(arg) {
     ::reset(0);
       set_name("a");
     }
wear(str) {
  write("ghj");
  move_object(this_player(),environment(this_object()));
  }
