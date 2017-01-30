inherit "obj/clean";

id(str) { return str=="stone"; }
short() { return "A Philosopher's Stone"; }
long() {
   write("The Philosopher's Stone!\n");
}

howto() {
 write("The fabled Philosopher's Stone appears as a large jewel\n"+
  "with hundreds of smooth polished edges.  It radiates with\n"+
  "a rainbow of dazzling colors.  However, the value of this\n"+
  "stone is not in its beauty, but what it can do.  The\n"+
  "Philosopher's Stone, or 'Alchemists Stone', converts\n"+
  "ordinary objects into gold!  Just type 'stone [object]'.\n"+
  "Be careful though, for the stone can turn Anything into gold!\n");
}

stone(str) {
   int num;
   object ob;
   if (!str) {
      write("Stone what?\n"); return 1;}
   if(present(str, this_player())) {
      ob = present(str, this_player());
      if(ob->query_value()) {
         num = ob->query_value();
         if(num >= 1000) num = 1000;
         this_player()->add_money(num);}
      else {
         num = 1;
         this_player()->add_money(num);}
      if(num == 1) {
         write("You turn the "+str+" into 1 gold coin.\n");}
      else write("You turn the "+str+" into "+num+" gold pieces!\n");
      destruct(ob);
      return 1;}
   else write("You have no "+str+".\n");
   return 1;
}
