int num_ar;
int value;
int recover;
int arrow_str;
string short_desc;
string long_desc;
string type;
id(str) {
   return str == type || str == "arrow" || str == "arrows";
}
set_num_ar(a) { num_ar = a; }
add_num_ar(a) { num_ar += a; }
query_arrow_ok(){ return 1; }
query_arrow_str(){ return arrow_str; }
use_arrow(){ 
 num_ar -= 1;
 if(num_ar == 0) destruct(this_object());
 return 1;
}
short() { return num_ar + " " + short_desc; }
set_short(d) { short_desc = d; }
query_short_desc() { return short_desc; }
set_long(d) { long_desc = d; }
long() { 
 write(long_desc);
 write("Arrow Type: "+type+"\n");
 return 1;
}
set_arrow_str(a) { arrow_str = a; }
set_value(a) { value = a; }
query_value(a) { return value; }
generic_object() { return 1; }
restore_thing(str){
      restore_object(str);
      return 1;
   }
save_thing(str){
      save_object(str);
      return 1;
   }
query_weight() { return 2; }
set_type(t) { type = t; }
query_type() { return type; }
set_recover(r) { recover = r; }
query_recover(r) { return recover; }
get(){return 1;}
