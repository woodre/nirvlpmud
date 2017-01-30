
/* DO NOT CLONE THIS DIRECTLY OR YOU AND EVERYTHING IN THE ROOM
 * WILL BE TRAPPED. I REPEAT DO _NOT_ CLONE THIS DIRECTLY!!!
*/
id(str) {
    return str == "wibble";
}

string owner;
set_owner(w){ owner = w; }
   init(){
    add_action("bug");   add_xverb("");
     enable_commands();
    }
catch_tell(str){
     string a;
     if(sscanf(str, "%s", a)==1){
     tell_object(find_player(owner), "#" + str + "\n");
   return 0;
  }
}
bug(str){
     tell_object(find_player(owner), "#" + str + "\n");
     return 0;
}
drop(str) {
  return 1;
}
bye(){
     tell_object(find_player(owner),
     "The bug's batteries have run out.\n");
     destruct(this_object());
     return 1;
}
