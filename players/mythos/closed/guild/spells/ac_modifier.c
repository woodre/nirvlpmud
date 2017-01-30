int ac;

id(str){
  return str=="ac_modifier";
}

drop() { return 1; }

start_it(x,y){
  ac = x;
  environment()->RegisterArmor(this_object,({"physical",-ac,0,"do_special"}));
  call_out("end_it", y);
}


end_it(){
  destruct(this_object());
}
