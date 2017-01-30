#define tp this_player()

string type;
int heal;

id(str) { return str == "ration" || str == type || str == alias; }

query_save_flag() { return 1; } /* no save */

short() { return alias; }

long() { write(short());
         write("You may ");
         if(type == "stuff") write("eat");
         else write("drink");
         write(" it.\n");
       }

get() { return 1; }
drop() { return 0; }
query_weight() { return heal/5; }
query_value() { return heal * 20; }

set_type(str) { type = str; }
set_heal(n) { heal = n; 
                 if(type == "intox") alias = "";
                 if(type == "stuff") alias = "";
                 if(type == "soak") alias = "";
              } 

init() {
  add_action("eat","eat");
  add_action("drink","drink");
}

eat(str) {
  if(type == "stuff" && id(str)) {
  
  healing(tp);
  return 1; }
}

drink(str) {
  if(type == "intox" && id(str)) {
  
  healing(tp);
  return 1; }
  if(type == "soak" && id(str)) {
  
  healing(tp);
  return 1;}
}

healing(ob) {
  object targ;
  targ = ob;
  if((type == "intox" && targ->drink_alcohol(6))
     || (type == "stuff" && targ->eat_food(6))
     || (type == "soak"&& targ->drink_soft(6))) {
       targ->heal_self(heal);
       targ->add_weight(-query_weight());
       destruct(this_object());
       return 1; }
}
  