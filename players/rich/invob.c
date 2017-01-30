short() {return "";}
id() {return "kinv";
}
get(){return 0;}
drop() {
  destruct(this_object());
  return 1;
  }
init() {
     add_action("look" ,"look");
     add_action("look", "l");
     add_action("lout" ,"lout");
      }
look() {
  write("You are in a klingon attack vehicle.\n");
  write("You see before you the various controls of the ship.\n");
  return 1;
 }
lout() {
   string ob,dir;
    ob=find_living("mytoy");
     dir=environment(ob);
  call_other(this_player(),"move_player","#"+file_name(dir));
  move_object(this_player(),ob);
   return 1;
  }
