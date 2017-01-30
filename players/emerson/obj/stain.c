#define room_ob environment(this_player())
#define FILE_NAME     "/players/emerson/obj/stain"
id(str) { return str == "stain"; }
short() { return "A pizza stain  (messy)"; }
long() {
write("This stain looks permanent! But it may be helpful...\n"+
       "Typing 'Show Stain' does wonders to the people around\n"+
       "you, etc.\n");
}
init() { 
  add_action("flauntme","show");
   add_action("emote","emote");
}

get() { return 1; }
drop() { return 1; }
query_auto_load() { return "/players/emerson/stain.c:"; }
emote(str)  {
    if(!str)  {
     write("emote what?\n");
    return 1;
         }
   say((this_player()->query_name())+" "+str+" \n");
   write((this_player()->query_name())+" "+str+"\n");
    return 1;
          }
 

flauntme(str) {
  object ob;
  if(str != "stain" || !str) return 0;

  ob=first_inventory(environment(this_player()));
 write("You flaunt your stain, and watch happily as the people react.\n");
  say((this_player()->query_name())+" flashes a messy stain that looks like pizza.\n");
  while(ob) {
    object oc;
    oc=ob;
    ob=next_inventory(ob);
      if(living(oc) && oc!=this_player()) {
      if(oc->query_level() < 20) {
        command("sing "+(this_player()->query_name()), oc);
      } else {
        write((oc->query_name())+" refuses to sing to you.\n");
      }
     }
    }
  return 1;
}
