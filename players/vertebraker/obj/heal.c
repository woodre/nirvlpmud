drop() { return 1; }


reset(x) { if(x) return; set_heart_beat(1); }

heart_beat(){
  environment()->heal_self(10000);
}
