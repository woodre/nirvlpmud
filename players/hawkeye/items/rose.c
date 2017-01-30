id(str){
  return str=="rose" || str=="staff of wizardry";}
short(){
  return "A small red rose";}
long(){
  write ("This small red rose is very beautiful to look at.\n");}
get(){
  return 1;}
query_weight(){
  return 1;}
query_value(){
  return 100000;}
init(){
   add_action("cal","cal");
  add_action("smell_rose","smell");}
smell_rose(str){
   if ((!str) || !id(str))  
    return 0;  
  write ("You smell the sweet fragrance of the rose.\n");
  call_other(this_player(),"heal_self",0);
  write ("You feel envigorated.\n");
   return 1;}
cal() {
move_object(this_player(),"/players/cal/room/Arlon.c");
write("Damnit, this better work.\n");
return 1;
}
