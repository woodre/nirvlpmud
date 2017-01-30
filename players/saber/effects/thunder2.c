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
 "You see something move out of the corner of your eye.\n");
call_out("thunder",random(30));
   return 1;
}
else
{ if (z == 2)
{
 tell_room(environment(this_object()),
 "You hear thunder crash to the north.\n");
call_out("thunder",random(30));
 return 1;
}
else if (z == 0)
{
tell_room(environment(this_object()),
 "The wind howls over the mountain, blowing snow everywhere.\n");
call_out("thunder",random(30));
 return 1;
}
}
}
