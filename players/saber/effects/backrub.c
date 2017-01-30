id(str) { return str == "backrub"; }
int z;
long() {
 write("Sassak is recieving a backrub from some generic bandit.\n");
}
query_value() {
  return 0;
}
query_weight() {
  return 100;
}

reset(arg) {
   if(arg) return;

call_out("backrub",random(10));
}

backrub() {
 z=random(5);
if(!environment(this_object())) return 1;
if (z == 1)
{
tell_room(environment(this_object()),
 "Sassak says: Harder slave!\n");
call_out("backrub",random(10));
   return 1;
}
else
{ if (z == 2)
{
 tell_room(environment(this_object()),
 "Sassak moans happily.\n");
call_out("backrub",random(10));
 return 1;
}
else if (z == 3)
{
tell_room(environment(this_object()),
 "Sassak says: Put more oil on my back.\n");
call_out("backrub",random(10));
 return 1;
}
else if (z == 4)
{
tell_room(environment(this_object()),
 "Man rubs Sassak's back.\n");
call_out("backrub",random(10));
 return 1;
}
else
 tell_room(environment(this_object()),
 "Man rubs oil into Sassak's back.\n");
call_out("backrub",random(10));
   return 1;
}
}
