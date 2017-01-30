/*
 * xenhance id object
 */

int num_wc;
int num_ac;
object target;
object owner;

id(str) { return str == "xcripple"; }

reset(arg) {
  if(arg) return;
  call_out("recover", 100);
}

drop() {
  destruct(this_object());
  return 1;
}

set_num_wc(x) { num_wc = x; }
set_num_ac(x) { num_ac = x; }
set_target(ob) { target = ob; }
set_owner(ob) { owner = ob; }

recover() {
  if(environment() != target) {
	if(target) {
		target->set_ac(target->query_ac() + num_ac);
		target->set_wc(target->query_wc() + num_wc);
	}
	destruct(this_object());
	return 1;
  }
  if(num_ac >= 1) {
	target->set_ac(target->query_ac() + 1);
	num_ac--;
  }
  if(num_wc >= 1) {
	target->set_wc(target->query_wc() + 1);
 	num_wc--;
  }
  if(!num_wc && !num_ac) {
	destruct(this_object());
	return 1;
  }
  if(!present(owner, environment(target))) call_out("recover", 10 + random(50));
  else call_out("recover", 100 + random(200));
  return 1;
}

