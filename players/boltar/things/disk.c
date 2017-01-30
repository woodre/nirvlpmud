int i,t;
object list;
short() { return "A small, metal, disk shaped object emitting green light";}
long() {
    if(environment(this_player()) != this_object())
    {
      write("It appears to have an intelligence all its own.\n");
       return 1;
     }
    write("You are inside the disk, the walls are plain and metallic.\n"+
     "You can see out through a small window or leave through the green portal.\n");
      if(this_player()->query_level() > 40)
         write(this_object());
       return 1;
      }
set_list() {
  i=0;
  list=allocate(50);
   list=users();
    t=sizeof(list);
}
reset() {
  set_list();
 call_out("move_me", 30);
  }
move_me(){
   set_list();
   i=random(t);
if(list[i]->query_level() > 20 || environment(list[i]) == this_object()) {
     call_out("move_me",2);
    return 1;
      }
  say("A small metal disk flys out of the room.\n");
  move_object(this_object(),environment(list[i]));
  say("A small metal disk flys in.\n");
  call_out("move_me",45+random(30));
      return 1;
  }
id(str) { return str=="disk"; }
init() { 
  add_action("see","see");
       add_action("leave","leave");
            add_action("touch","touch");
}
see(){
   call_other(environment(this_object()), "long", 0);
   return 1;
}
leave() {
    if(environment(this_player()) !=this_object()) return 0;
     write("You leave through the green light.\n");
     move_object(this_player(), environment(this_object()));
     say(this_player()->query_name() + " enters the room in a green flash.\n");
     return 1;
}
touch(str) {
   if(str != "disk") return 0;
          write("You see nothing but a bright green light.\n");
      write("You are sucked into the disk!\n");
   say(this_player()->query_name() + " touches the disk and is sucked in a bright green flash of light.\n");
       move_object(this_player(),this_object());
       long();
       return 1;
}
