id(str) { return str == "voice"; }
short() { return 0; }
long() { return 0; }
reset() {
  call_out("fake_beat", 1);
	}
    
fake_beat() {
int a;
a=random(40);
if(a=6) {
say("You hear a creaking noise.\n");
	}
  remove_call_out("fake_beat");
  call_out("fake_beat", 2);
}
