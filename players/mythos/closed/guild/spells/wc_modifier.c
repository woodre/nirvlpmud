int wc;

id(str){
  return str=="wc_modifier" || str=="generic_wc_bonus";
}

drop() { return 1; }

start_it(x,y){
  wc = x;
  call_out("end_it", y);
}

gen_wc_bonus(){
  return -wc;
}

end_it(){
  destruct(this_object());
}
