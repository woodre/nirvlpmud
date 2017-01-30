id(str) {return "fg";}
init() {
   object ob1;
   int i;
    i=0;
      while (i<25) {
        ob1=clone_object("players/haji/ha.c");
        move_object(ob1,"players/haji/yard.c");
        i+=1;
        }
write("woogie\n");
destruct(this_object());

}
