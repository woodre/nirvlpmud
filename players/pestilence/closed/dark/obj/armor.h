#define Uwil USER->query_attrib("wil")
#define Uint USER->query_attrib("int")
static string name, type;
static int size, save_flag, worn, ac, set_ac_flag;
static object worn_by, next;




rec_short(){
    if(next)
        return name + ", " + call_other(next, "rec_short");
    return name;
}

test_type(str){
    if(str == type)
        return this_object();
    if(next)
        return call_other(next, "test_type", str);
    return 0;
}

tot_ac(){
    if(next)
        return ac + call_other(next, "tot_ac");
    return ac;
}

query_type() { return type; }
query_worn() { return worn; }
query_name() { return name; }
armor_class() { return ac; }

remove(str) {
    if (!id(str))
        return 0;
    if (!worn) {
        return 0;
    }
    call_other(worn_by, "stop_wearing",name);
    worn_by = 0;
    worn = 0;
    return 1;
}

set_ac(a) { ac = a; 
      set_ac_flag = 14; }
      
set_type(t) {
   if (ac > 0 || !set_ac_flag) {
    if (t !="armor" && t !="helmet" && t != "boots" && t != "ring" && 
                t !="amulet" && t != "shield" && t != "misc" && t != "mine") 
    destruct (this_object());
     }
 type = t;
}

take_off() {
   worn_by = this_player();
   worn_by = 0;
   worn = 0;
    return 1;
}
