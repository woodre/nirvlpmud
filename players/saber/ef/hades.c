id(str) { return str == "hades"; }
int z;
long() {
write("You think you see Hades staring back at you.\n");
}
query_value() {
  return 0;
}
query_weight() {
  return 100;
}

reset(arg) {
   if(arg) return;

call_out("hades",random(10));
}

hades() {
 z=random(5);
if (z == 1)
{
tell_room(environment(this_object()),
 "You are almost singed by a burst of flame.\n");
call_out("hades",random(10));
   return 1;
}
else
{ if (z == 2)
{
 tell_room(environment(this_object()),
 "Your eyes water from the smoke.\n");
call_out("hades",random(10));
 return 1;
}
else if (z == 3)
{
tell_room(environment(this_object()),
 "The stench of sulpher invades your senses.\n");
call_out("hades",random(10));
 return 1;
}
else if (z == 4)
{
tell_room(environment(this_object()),
 "Black smoke drifts across the fiery chamber.\n");
call_out("hades",random(10));
 return 1;
}
else
 tell_room(environment(this_object()),
 "The chamber blazes.\n");
call_out("hades",random(10));
   return 1;
}
}
