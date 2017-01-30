#include "/players/wocket/closed/ansi.h"
inherit "/obj/armor.c";

reset(arg){
  if(arg) return;
  set_name("cloak");
  set_long("The outline of a cloak seems to glimmer for a second and then fade as\n"+
           "light glances across it.  Waves of woven fibers shimmer then fade.\n"+
           "This is an invisible cloak.\n");
  set_ac(2);
  set_type("misc");
  set_weight(2);
  set_heart_beat(1);
}

short(){
string str;
  if(this_player() == environment(this_object())){
    str = "A "+HIC+"cloak"+OFF+" of "+HIC+"invisibility"+OFF;
    if(worn)
    str += " (worn)";
    return str;
  }
  return 0; 
}

heart_beat(){
  if(environment(this_object())->is_player()){
    if(worn)   
      environment(this_object())->set_invs_sp();
  }
  if(!random(30)){
    tell_object(environment(this_object()),HIC+"The cloak shimmers in the light.\n"+OFF);
    tell_room(environment(this_object()),HIC+"The cloak shimmers in the light.\n"+OFF);
  }
}                                                                                                                                                                                                                                                                                                                                                                                                                                        

link(ob){
  next = ob;
  tell_object(environment(this_object()),HIC+"You become invisible as the cloak shrouds your body.\n"+OFF);
}

remove_link(str)
{
    object ob;

    if (str == name) {
        ob = next;
        next = 0;
        tell_object(environment(this_object()),HIC+"You become visible as you remove the cloak.\n"+OFF);
        environment(this_object())->visible();
        return ob;
    }
    if (next)
        next = call_other(next, "remove_link", str);
    return this_object();
}
