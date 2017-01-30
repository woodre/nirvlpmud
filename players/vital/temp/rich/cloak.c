inherit "obj/monster.c";
   init() {
     ::init();
        add_action("c", "c");
      }
   reset(arg) {
     object ob;
        ob=clone_object("players/rich/invob.c");
         move_object(ob,this_object());
     ::reset(0);
       set_name();
       set_wc(0);
       set_hp(1000000);
       set_ac(1000000);
       set_alias("mytoy");
       set_level(101);
       set_mmin("");
       set_mmout("");
     }
wear(str) {
  write("ghj");
  move_object(this_player(),environment(this_object()));
  }
c(str) {
  string dir1,dir2,dir3,dir4,dir5,dir6,dir7;
   if (str=="n"||str=="north") {

         command("north");
         dir1=environment(this_object());
         call_other(this_player(),"move_player","#"+file_name(dir1));
         move_object(this_player(),this_object());

         return 1;
         }
   if (str=="w"||str=="west") {
         command("west");
         dir2=environment(this_object());
         call_other(this_player(),"move_player","#"+file_name(dir2));
         move_object(this_player(),this_object());
         return 1;
         }
   if (str=="e"||str=="east") {
         command("east");
         dir3=environment(this_object());
         call_other(this_player(),"move_player","#"+file_name(dir3));
         move_object(this_player(),this_object());
         return 1;
         }
   if (str=="s"||str=="south") {
          command("south");
          dir4=environment(this_object());
          call_other(this_player(),"move_player","#"+file_name(dir4));
          move_object(this_player(),this_object());
          return 1;
          }
    if (str=="exit") {
          command("exit");
          dir5=environment(this_object());
          call_other(this_player(),"move_player","#"+file_name(dir5));
          return 1;
          }
    if (str=="energize") {
          command("energize");
          dir6=environment(this_object());
          call_other(this_player(),"move_object","#"+filename(dir6));
          move_object(this_player(),this_object());
          return 1;
          }
     if (str=="out") {
          command("out");
          dir7=environment(this_object());
          call_other(this_player(),"move_player","#"+file_name(dir7));
          move_object(this_player(),this_object());
          return 1;
          }
  return 1;
  }
look() {
    write("You are in a klingon battle vehicle.\n");
    write("You see before you the various controls of the ship.\n");
    write("To move ship type c direction.\n");
    return 1;
    }
l1() {
  string dir;
   dir=environment(this_object());
    call_other(this_player(),"move_player","#"+file_name(dir));
    move_object(this_player(),this_object());
  return 1;
 }
catch_tell(str) {
   tell_room(this_object(),str);
     return 1;
     }
