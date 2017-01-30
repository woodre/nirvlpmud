inherit "obj/treasure";
int W;

/*A Timing Device*/

reset(arg) {
  W = 10;
  if(arg) return;

  set_id("timer");
  set_value(0);
  set_weight(10000);
  call_out("check_time",20);
}

check_time()  {
  if(W < 1)  {
    destruct(this_object());
  return 1;
  }  else  {
    W = W -1;
  call_out("check_time",20);
  return 1;
        }
return 1;
}
