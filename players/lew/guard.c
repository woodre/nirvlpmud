#define TOB this_object()
 
inherit "/obj/monster.talk";
 
object ob;
 
void reset(int arg) {
  :: reset(arg);
  if (!arg) {
  
   set_name("guard");
   set_alias("door guard");
   set_short("A door guard");
 
    set_long("This is one of the students of IIT that guard the \n" +
             "front entrance to the Residence Halls.  You wonder if this \n" +
             "realizes that you exist.  That is untill he sees you. \n");
      
    set_aggressive();
  set_level(15);
  set_al(-300);
  set_hp(500);
  set_wc(20);
  set_ac(15);
    set_chat_chance(15);
    load_chat("Zzzzzzzzzzz.\n");
    load_chat("You startle the guard.\n");
  }
}  
 
 
