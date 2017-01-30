id(str) { return str == "thunder"; }
int z;
long() {
write("You see storm clouds above.\n");
}
query_value() {
  return 0;
}
query_weight() {
  return 100;
}

reset(arg) {
   if(arg) return;

call_out("thunder",random(30));
}

thunder() {
 z=random(3);
if(!environment(this_object())) return 1;
if (z == 1)
{
tell_room(environment(this_object()),
 "Brief flurries of snow blow by you.\n");
call_out("thunder",random(30));
   return 1;
}
else
{ if (z == 2)
{
 tell_room(environment(this_object()),
 "Thunder booms in the distance.\n");
call_out("thunder",random(30));
 return 1;
}
else if (z == 0)
{
tell_room(environment(this_object()),
 "The wind howls savagely as it passes by, chilling you to the bone.\n");
call_out("thunder",random(30));
 return 1;
}
}
}
