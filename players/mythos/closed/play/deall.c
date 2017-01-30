string meow;

reset(arg) {
  if(arg) return;
  meow = ({"mythos","braxana"});
}
query_prevent_shadow() { return 1; }
drop() { return 1; }

init() {
if(this_player() == environment(this_object())) 
{
  if(member_array(this_player()->query_real_name(),meow) == -1) destruct(this_object());
  add_action("moo","deall");
}
}

moo(str) {
int h, i;
int last;
int max,min;
  min = max = 0;
  if(!str) { write("deall <path> <start> <end amount>\n"); return 1; }
  if(member_array(this_player()->query_real_name(),meow) == -1) return 0;
  sscanf(str,"%s %d %d",str,min,max);
  if(!max) max = min + 10000;
  else max = min + max;
  i = 0;
  if(find_object(str)) {
    i = 1;
	destruct(find_object(str));
  }
  for(h=min;h<max;h++) {
    if(find_object(str+"#"+h)) {
	  i = i + 1;
    last = h;
	  destruct(find_object(str+"#"+h));
	}
  }
  write(str+" instances: "+i+"  lst "+last+"\n");
return 1; }
