#define tp this_player()->query_name()
id(str) { return str == "candle"; }
short() { return "A candle"; }
long()  {
  write("A candle.\n"+
  "You can 'candle' or 'out candle'.\n");
       }
query_weight() { return 0; }
query_value() { return 1; }

string is_lit;
reset(arg) {
   if(arg) return;
is_lit = 1;
}

init()  {
  add_action("light_candle","candle");
   add_action("out_candle","candle out");
        }

flicker() {
   tell_room(environment(this_object()), "The candle flickers.\n");
 call_out("flicker",5);
   return 1;
}

light_candle()  {
if(!is_lit)  {
call_out("flicker",5);
is_lit = 1 - is_lit;
tell_room(environment(this_player()),
 tp+" lights a candle.\n");
  return 1;  }
        }

out_candle()  {
if(is_lit)  {
is_lit = 1 - is_lit;
tell_room(environment(this_player()),
 tp+" extinguishes the candle.\n");
remove_call_out("flicker()");
 return 1;
        }
        }
