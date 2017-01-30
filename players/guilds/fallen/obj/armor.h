static string name, typea;
static int size, save_flaga, worn, ac, set_ac_flag;
static object worn_by, next;

link(ob){  next = ob;  }

remove_link(str){
  object ob;
  if(str == name)
  {
    ob = next;
    next = 0;
    return ob;
  }
  if(next)
    next = call_other(next, "remove_link", str);
  return this_object();
}

rec_short(){
  if(next)
    return name + ", " + call_other(next, "rec_short");
  return name;
}

test_type(str){
  if(str == typea)
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

query_type(){  return typea; }
query_worn(){  return worn; }
query_name(){  return name; }
armor_class(){ return ac;   }

remove(str) {
  if(!id(str))
    return 0;
  if(!worn)
    return 0;
  call_other(worn_by, "stop_wearing",name);
  worn_by = 0;
  worn = 0;
  return 1;
}

set_ac(a){
  ac = a;  
  set_ac_flag = 7; 
}
      
set_type(t){
  if(ac > 0 || !set_ac_flag)
  {
    if(t !="armor" && t !="helmet" && t != "boots" && t != "ring" && 
      t !="amulet" && t != "shield" && t != "misc") 
    destruct (this_object());
  }
  typea = t;
}

take_off(){
  worn_by = this_player();
  worn_by = 0;
  worn = 0;
  return 1;
}

shield_msgs(){
  int a;
  string b;
  a = random(9);
  switch(a)
  {
  case 0:
    b = "The shield of shadows partially deflects the blow.\n";
    break;
  case 1:
    b = "Shadows dance over you as the blow is partially deflected.\n";
    break;
  case 2:
    b = "The shield of shadows protects you.\n";
    break;
  case 3:
    b = "Shadows flit around you, lessening the blow.\n";
    break;
  case 4:
    b = "Shadowy tendrils protect you from the attack.\n";
    break;
  case 5:
    b = "The shadows harden to protect you.\n";
    break;
  case 6:
    b = "The shadows form around you to protect you.\n";
    break;
  case 7:
    b = "Shadows rise up to deflect the blow.\n";
    break;
  case 8:
    b = "The shadows protect you from harm.\n";
    break;
  }
  return b;
}

shield_bonus(){
  int bonus;
  bonus = 0;
  if(duration)  /* if focused and low ac, get ac bonus */
  {
    if((int)USER->query_ac() == 0)
      bonus += 3;
    else if(random((int)USER->query_ac()) <= 1)
      bonus += 2;
    else if(random((int)USER->query_ac()) <= 3)
      bonus += 1;
  }
  if(shadow_shield)  /* shield spell */
  {
    if(USER->query_attack() && !random(3))
      tell_object(USER, shield_msgs());

    bonus += (int)USER->query_attrib("int") / 10; /* max 2 */
    bonus += (int)USER->query_attrib("ste") / 5;  /* max 6 */

    if(random((int)USER->query_ac()) > 3)  /* high ac lowers shield bonus */
      bonus -= random((int)USER->query_ac() / 2);
  }
  return bonus;
}
