inherit "obj/armor";
object polisher;
int polished;

init() {
   ::init();
   
   add_action("polish", "polish");
   add_action("amulokt", "amulokt");
}

polish(arg) {
    if(arg != "amulokt") {
    write("What do you want to polish?\n");
    return 1;
    }
    if(polished == 1) {
    write("You can't polish it anymore! It's as shiny as it can get.\n");
    return 1;
    }
   if(arg == "amulokt") {
      polisher=this_player();
      amulokt();
      polished = 1;
      return 1;
   }
   else {
      return 0;
   }
}
amulokt(arg) {
   object here;
   string herestr;
   here=environment(polisher);
   herestr=here->realm();
   if(herestr=="NT"){
      write("Nothing seems to happen in this area.\n");
      return 1;
   }
   move_object(this_player(), "/players/cyrex/quest/hiventrance");
   write("You are pulled by an unknown force into the Amulokt.\n");
   write("You find yourself inside the Hive!\n\n");
   command("look",this_player());
   command("cringe",this_player());
   return 1;
}

reset(arg) {
  ::reset();
  if(arg) return;
set_name("amulokt");
   set_short("Amulokt of Protoculture (glowing)");
   set_long("Amulokt of Protoculture...\n"+
      "It looks like it has an image of a hive in the center.\n"+
      "However, it may need some polishing to be certain.\n");
   set_weight(0);
   set_value(2000);
   set_ac(2);
   set_type("amulet");
   polished = 0;
}
id(str) {return (str == "amulokt");}

