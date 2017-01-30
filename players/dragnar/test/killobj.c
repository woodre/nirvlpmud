id(string str) {

   return str == "test" || str == "2d" || str == "kill_check_object";
}


init() {
      
}
reset(arg){
    if(arg) return;
}

kill_check(object victim) {
  if( !this_player() || !environment( this_player() ) )
    return;
  write("You murdered "+ victim->query_real_name() +"!\n");
  tell_room( environment( this_player() ), "F\nA\nT\nA\nL\nI\nT\nY!\n");
}

get() { return 1; }
drop() { return 1; }
query_weight() { return 0; }
query_value() { return 0; }

