#include <ansi.h>

inherit "/obj/monster";
int str;

reset(arg) {
    ::reset(arg);
    if (!arg)  {
	    
	    switch (random(5)) { 
           case 0: str=HIB; break;
           case 1: str=HIR; break;
           case 2: str=HIG; break;
           case 3: str=HIC; break;
           case 4: str=HIM; break;
           default: str=HIB; break;
                              }
      }
        
        set_name("bat");
        set_short(HIB+"A Bat"+NORM);
        set_race("bat");
        set_long(
	"   This is a small black bat.  With flapping wings and a high\n"+
"pitched shrill, the bat opens it's eyes as if preparing for an attack!\n");
        set_level(10);
        set_ac(8);
        set_wc(14);
        set_hp(150);
        set_al(-100);
        set_chat_chance(10);
        set_a_chat_chance(10);
        
        load_chat("The bat flaps its wings.\n");
        load_chat("The bat goes 'Shreeeeeeeeeee'.\n");
        load_a_chat("The bat lands on your head and burrows in your hair!\n");
        set_dead_ob(this_object());
}
id(str){return str == "bat"|| str == "black";} 
monster_died(ob)  {
    object wings;

    write(BOLD+"You rip off the bat's silky wings!\n"+NORM);
    tell_room(environment(),
        this_player()->query_name()+" rips the wings off the Bat.\n",
        ({ this_player()}));

  wings = clone_object("/obj/treasure");
  wings->set_id("wings");
  wings->set_short(BOLD+"Bat Wings"+NORM);
  wings->set_long(
"These are the wings from a bat.  They could be valuable.\n"
  );
  wings->set_value(350+random(50));
  wings->set_weight(1);

  move_object(wings,environment(ob));

}
