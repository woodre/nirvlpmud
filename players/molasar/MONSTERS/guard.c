inherit "obj/monster";

reset(arg){
  ::reset(arg);
  if(arg) return;

set_name("guard");
set_alias("castle guard");
set_short("A castle guard");
set_long("One of the many castle guards which keep an eye out for thieves and robbers.\n");
set_ac(6);
set_wc(16);
set_level(10);
set_al(120);
set_aggressive(0);
  call_out("move_function",10);
}


move_function(){

object ob;
int n;
  if(!environment(this_object())) return 1;
n = random(8);
   if(n == 0 || n ==7)
     init_command("north");
    if(n == 1 || n == 2)
   init_command("south");
   if(n == 4 || n == 6)
     init_command("west");
   if(n == 5 || n == 3)
   if(n==5)
     init_command("east");
  call_out("move_function",random(300));
return 1;
}
init() {
  if(this_player())
  if(this_player() != this_object())
     if(this_player()->is_player())
     if(call_other(this_player(),"query_alignment") < 0) {
       write("How did you get in here you evil slime!!\n");
       call_other(this_object(), "attack_object", this_player());
       return 1;
     }
}

