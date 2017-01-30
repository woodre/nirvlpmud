#define MAX_WEIGHT 40
 int local_weight;
string box_owner;

short() {
  return "A Footlocker";
}

query_value() {  return 3;  }

  query_weight() {   return 666; }

add_weight(w) {
  if(local_weight + w > MAX_WEIGHT)
        return 0;
   local_weight += w;
     return 1;
}

 can_put_and_get() {
   if(call_other(this_player(), "query_real_name",0) != box_owner) {
      return;
 }
   return 1;
}

long() {
if(call_other(this_player(),"query_real_name",0) !=box_owner) {
 write("A Footlocker.  It's not yours, so don't worry about it.\n");
     }
  if(this_player()->query_real_name() == box_owner) {
  write("A Footlocker\n");
   if(first_inventory(this_object()))
     write("There is something in it.\n");
      else
    write("You can put things in it.\n");
   }
}

reset(arg) {
   if(arg)
       return;
  local_weight = 0;
}

prevent_insert() {
  if(local_weight > 0) {
write("You can't when there are things in your locker!\n");
   return 1;
}
    return 0;
}

id(str) {
    return str == "locker" || str == "foot locker";
}


set_owner(str) {
       box_owner = str;
       return 1;
   }
get() {
  return 0;
}

