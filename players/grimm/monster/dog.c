#include "/players/grimm/header"
inherit "obj/monster";
int boneflag;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("dog");
set_short("A tracking dog");
set_al(-500);
set_long("This is a famous breed of a vampire tracking dog.\n");
set_level(15);
set_hp(225);
set_aggressive(0);
set_ac(12);
set_wc(20);
}
init() {
   add_action("give","give");
   ::init();
}
give(str) {
   object what,to,who,temp;
   if(!str) return;
   sscanf(str,"%s %s %s",what,to,who);
   if(!what) return 0;
   if(!present(what,this_player())) {
      write("You don't have that!\n");
      return 1;
   }
   if(who!="dog") return;
   if(!boneflag && who =="dog" && what!= "bone") {
      write("The dog doesn't like you!  Try to befriend him first.\n");
      return 1;
   }
   if(what=="bone" && who=="dog" && present("vamp bone",this_player())) {
      boneflag = 1;
      write("gruff gruff  you're my friend.\n");
      temp = present(what,this_player());
      destruct(temp);
      return 1;
   }
   if(boneflag && what=="cloth" && who == "dog") {
      write("The dog takes a sniff of the cloth and starts to trackdown\n"+
            "the vampire!!!\n");
      write("\nThe dog has led you to the Castle of Malachi!\n");
      this_player()->move_player("with the dog#"+DIR5(castle1));
      write("\n\nThe dog, sensing his job done, leaves for home.\n");
      temp = present(what,this_player());
      destruct(temp);
      destruct(this_object());
      return 1;
   }
   if(what) {
      temp = present(what,this_player());
      destruct(temp);
   }
return 1;
}
