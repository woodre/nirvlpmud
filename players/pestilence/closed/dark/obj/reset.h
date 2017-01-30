reset(arg) {
  if (arg) return 0;
  stalk = 0;
  cout = 0;

call_out("light_damage",3);
set_heart_beat(1);
}
