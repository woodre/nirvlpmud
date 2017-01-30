#define LIMIT 20
#define RAISE 5
int befwc, clock, aftwc;

id(str) { return str == "str_ob"; }

reset(arg) {
  if(arg) return;
  clock = 0;
  befwc = 0;
  aftwc = -69;
  set_heart_beat(1);
}

drop() { return 1; }

heart_beat() {
  if(!environment(this_object())) { set_heart_beat(0); return; }
  if(!living(environment(this_object()))) { set_heart_beat(0); return; }
  if(clock > LIMIT) { crap_out(); return; }
  check();
  clock++;
}

check() {
	if(environment(this_object())) {
	  if(living(environment(this_object()))) {
		befwc = environment(this_object())->query_wc();
		if(befwc != aftwc || aftwc == -69) {
		  aftwc = befwc + RAISE;
		  environment(this_object())->set_wc(aftwc);
	    }
  	   }
	}
return 1; }

crap_out() {
  set_heart_beat(0);
  if(environment(this_object())) {
	  if(living(environment(this_object()))) {
          environment(this_object())->set_wc(environment(this_object())->query_wc() - RAISE);
          tell_object(environment(this_object()),"Your strength returns to normal.\n");
      }
  }
  destruct(this_object());
return 1; }
