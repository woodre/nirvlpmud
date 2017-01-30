#include <ansi.h>

object* grab_inventory(object mob,int type);

int main(string str){
  object mob;
  
  if(!str) {
    if(!(mob = (object)this_player()->query_attack())){
      write("Who would you like to dent ?\n");
      return 1;
    }
  }
  else {
    if(!(mob = present(str, environment(this_player())))){
      write("You don't see \""+str+"\" here.\n");
      return 1;
    }
  }
  
  /*
  if(!this_player()->valid_attack(mob)) {
  }
  */
  
  if(!this_player()){
  }
  
  else {
    int type, qw; /* 0 = wep, 1 = arm */
    object obj, *objs;
    string obj_name;
    
    if(previous_object()->query_done()){
      write("You cannot use \"dent\" this round.\n");
      return 1;
    }
    
    previous_object()->set_done(1);
    
    type = random(2);
    
    objs = grab_inventory(mob,type);
    
    if(!sizeof(objs)){
      objs = grab_inventory(mob,!type);
      if(!sizeof(objs)){
        write((string)mob->query_name()+
          " isn't using any equipment.\n");
        return 1;
      }
    }
    
    obj = objs[random(sizeof(objs))];
    obj_name = (string)obj->query_name();
    
    /* cost and checks */
    
    if(obj->is_weapon()){
      int r;
      obj->add_wear(500 + random(500)); /* replace 500's with 5 * prof */
      qw = (int)obj->query_wear();
      r = 4450000 / ((int)obj->query_wear());
      r = random(r);
      if(r < 10){
        obj->weapon_breaks();
      }
    }
    if(obj->is_armor()){
      qw = 1; /* need a query_wear() return 1 flag  in armor .c to mark*/
              /* most armors as breakable. "temper" can make them unbreakable */
              /* armor_breaks() will have to point to this */
      if(random(1000) < 200 + random(200)) { /* replace 200's with prof * 2 */
        obj->armor_breaks();
      }
    }
    if(qw){
      write("You dent "+(string)mob->query_name()+"'s "+
        obj_name+".\n");
      say((string)this_player()->query_name()+" dents "+
        (string)mob->query_name()+"'s "
        +obj_name+".\n", mob);
      tell_object(mob, (string)this_player()->query_name()
        +" dents your "+obj_name+".\n");
    }
    else { /* if item is unbreakable */
      write("Your swing glances off "+(string)mob->query_name()
        +"'s "+obj_name+".\n");
      say((string)this_player()->query_name()+"'s swing glances off"+
      " "+(string)mob->query_name()+"'s "+obj_name+".\n", mob);
      tell_object(mob, (string)this_player()->query_name()
        +"'s swing glances off your "+obj_name+".\n");
    }
  }
  return 1;
}

object * grab_inventory(object mob, int type){
  object ob, oc, *objs;
  objs = ({});
  ob = first_inventory(mob);
  while(ob){
    oc = next_inventory(ob);
    if(ob->is_weapon() && type == 0 &&
      (ob->query_wielded() || ob->query_offwielded())){
      objs += ({ ob });
    }
    else if(ob->is_armor() && type == 1 && ob->query_worn()){
      objs += ({ ob });
    }
    ob = oc;
  }
  return objs;
}