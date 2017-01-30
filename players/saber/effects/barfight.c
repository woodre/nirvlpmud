id(str) { return str == "barfight"; }
int z;
long() {
write("A raging barfight of epic proportion.\n");
}
query_value() {
  return 0;
}
query_weight() {
  return 100;
}

reset(arg) {
   if(arg) return;

call_out("barfight",random(15));
}

barfight() {
 z=random(5);
if(!environment(this_object())) return 1;
if (z == 1)
{
tell_room(environment(this_object()),
 "A chair flies across the room.\n");
call_out("barfight",random(15));
   return 1;
}
else
{ if (z == 2)
{
 tell_room(environment(this_object()),
 "Somebody grunts in pain.\n");
call_out("barfight",random(15));
 return 1;
}
else if (z == 3)
{
tell_room(environment(this_object()),
 "You hear a loud *CRACK* as something breaks.\n");
call_out("barfight",random(15));
 return 1;
}
else if (z == 4)
{
tell_room(environment(this_object()),
 "One of the bodies on the floor twitches slightly.\n");
call_out("barfight",random(15));
 return 1;
}
else
 tell_room(environment(this_object()),
 "The barmaid ducks a punch.\n");
call_out("barfight",random(15));
   return 1;
}
}
