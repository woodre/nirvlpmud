id(str) { return str == "candle"; }
short() { return "A candle"; }
long() { write("A candle.\n");
   }
query_weight() { return 0; }
query_value() { return 1; }

reset(arg) {
   if(arg) return;

   call_out("flicker", random(5));

}

flicker() {
   tell_room(environment(this_object()), "The candle flickers.\n");
   call_out("flicker",random(5));
   return 1;
}
