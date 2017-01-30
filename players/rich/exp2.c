inherit "obj/monster.c";
   init() {
     ::init();
        add_action("wear" ,"wear");
        add_action("c", "c");
      }
   reset(arg) {
     ::reset(0);
       set_name("klingon attack vehicle");
       set_wc(0);
       set_hp(1000000);
       set_ac(1000000);
       set_alias("mytoy");
       set_level(39);
     }
wear(str) {
  write("ghj");
  move_object(this_player(),environment(this_object()));
  }
c(str) {
   if (str=="n"||str=="north") {
         call_other(this_object(),"force_us","north");
         tell_object(this_player(),environment(this_object())->long());

         return 1;
         }
   if (str=="w"||str=="west") {
         call_other(this_object(),"force_us","west");
         tell_object(this_player(),environment(this_object())->long());
         return 1;
         }
   if (str=="e"||str=="east") {
         call_other(this_object(),"force_us","east");
         tell_object(this_player(),environment(this_object())->long());
         return 1;
         }
   if (str=="s"||str=="south") {
          call_other(this_object(),"force_us","south");
          tell_object(this_player(),environment(this_object())->long());
          return 1;
          }
    if (str=="energize") {
          call_other(this_object(),"force_us","energize");
          tell_object(this_player(),environment(this_object())->long());
          return 1;
          }
     if (str=="out") {
          call_other(this_object(),"force_us","out");
          tell_object(this_player(),environment(this_object())->long());
          return 1;
          }
  return 1;
  }
