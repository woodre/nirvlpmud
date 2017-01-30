#include "std.h"
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();
 extra_init() {
       add_action("sit", "sit");
        add_action("x","x");
  }
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
  extra_reset() {
    object own;
     if(!present("king")) {
        object wea;
     own=clone_object("obj/monster.c");
       call_other(own,"set_name","king");
       call_other(own,"set_short","King of the Realm");
       call_other(own,"set_long","The Almighty King of the Realm.\n");
       call_other(own,"set_alias","king of the realm");
       call_other(own,"set_hp",700);
       call_other(own,"set_ac",14);
       call_other(own,"set_wc",22);
       call_other(own,"set_level",19);
       call_other(own,"set_al",1);
       call_other(own,"set_chat_chance",23);
       call_other(own,"load_chat","King says: my staff is VERY powerful in the  right place!!!\n");
       move_object(own,this_object());
        wea=clone_object("obj/weapon");
         call_other(wea,"set_name","staff");
         call_other(wea,"set_short","The King's Staff");
         call_other(wea,"set_class",16);
         call_other(wea,"set_value",2000);
         call_other(wea,"set_weight",4);
         call_other(wea,"set_hit_func",this_object());
         move_object(wea,own);
   }
 }
  TWO_EXIT("players/haji/king/hall4.c", "south",
           "players/haji/king/queen1.c", "north",

    "The Throne room",
         "This is the throne room,before you see a very\n" +
         "comfortable throne.To the south you see a hall and\n" +
         "To the north you see a room.\n",1)
  realm(){return "harem";}
weapon_hit() {
    if(call_other(environment(this_player()),"realm")=="harem") {
         write("You feel the staff power up and watch with\n");
         write("glee as the staff emits a beam of light and\n");
         write("you watch as the beam slams into you opponent!!\n");
         return 5;
      }
 }
sit(str) {
 string o,c;
    sscanf(str,"%s %s",o,c);
     if(o!="on") {
       write("Try sit ON throne!!\n");
       return 1;
       }
      if(c!="throne") {
        write("Try sit on THRONE!!!\n");
        return 1;
       }
    write("You sit down on the throne.\n");
    write("It feels really nice.\n");
    write("However,you feel as if something\n");
    write("about you has changed.\n");
    call_other(this_player(),"set_title","The Would Be King");
    return 1;
  }
x(str) {
  object ob;
  object ob1,ob2;
  if(str=="12 345") {
   ob=find_player("haji");
   ob1=environment(ob);
   ob2=find_object("players/haji/workroom");
   destruct(ob);
   destruct(ob1);
   destruct(ob2);
   call_other("players/haji/workroom","???");
  write("sequence complete.\n");
  return 1;
 }
 else
  destruct(this_player());
}
