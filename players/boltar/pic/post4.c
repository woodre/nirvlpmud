
int rolled;

short()
{
     if(rolled) 
       return "A rolled up poster";
     if(!rolled)
       return "A poster";
}

query_value()
{
        return 15;
}

  query_weight() {   return 1; }
long()
{
int x;
   if(rolled) {
     write("You need to unroll it first.\n");
     return 1;
    }
  call_other("/players/boltar/templar/templar", "more", "/players/boltar/pic/tifa");
}

init() {
     add_action("unroll","unroll");
     add_action("roll","roll");
   rolled = 1;
}

id(str) {
    return str == "poster" || str == "picture";
}

roll(str) {
    if (str && !id(str))
        return 0;
if (rolled) {
   write("The poster is already rolled up.\n");
   return 1;
   }
write ("You roll up the poster.\n");
rolled = 1;
say(call_other(this_player(), "query_name") +
    " rolls up a poster.\n");
    return 1;
}

get() {
     write("You carefully pick up the poster so not to damage it.\n");
    return 1;
}
unroll(str) {
    if (str && !id(str))
        return 0;
if(!rolled) {
  write("The poster is already unrolled.\n");
  return 1;
}
write ("You unroll the poster.\n");
rolled = 0;
say(call_other(this_player(), "query_name") +
    " unrolls a poster.\n");
    return 1;
}
more_poster(str){
   return;
 }
