#define TP this_player()
#define CAP capitalize(str)
#define AON attacker_ob()->query_name()

sic (str) {
   
   object ob;
   
 ob = present(str, environment(this_player()));

  if(!ob)  {
    write(CAP+" is not here for you to attack.\n");
    return 1;
        }
   if(this_player()->query_sp() < 10)  {
      write("You don't have enough spell points to do this.\n");
      return 1;
   }
   if(!str){
      notify_fail("Usage: sic <monster>\n");
      return 0;
   }
if(TP->query_ghost()) {
      write("You can not fight with a ghost.\n");
      return 1;
   }
   if(!TP->query_attack()) {
write("You are not in battle.\n");
      return 1; }
   
   TP->add_spell_point(-10);
   ob->attack_object(TP);
   TP->attack_object(ob);
   write("You leap to attack "+AON+"!\n");
say(TP+" leaps o attack "+AON+"!\n");
   return 1;
}
