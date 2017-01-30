init() {add_action("snoop_off","look");}

snoop_off() { 
  write("%");
  snoop();
  destruct(this_object());
  return 1;
}

