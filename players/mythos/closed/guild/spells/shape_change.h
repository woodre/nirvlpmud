#include "/players/mythos/closed/guild/def.h"
object ob, ob2;
string form,form, mesg, nam,p;
shape_change(str) {
if(!str) { write("You may change into anything.\n"+
                 "However only the follow have special properties:\n"+
                 "    blood_bird  winter_wolf  dragon\n"+
                 "Remember the better the shape, the worse the curse.\n\n"+
"NOTE: Should this spell be found to be misused I will take it out - Mythos\n"); return 1;}
if(qtf < 19) { write("Your control over fae is not enough!\n"); return 1;}
if(present("form_ob",this_player())) { write("You must get out of this form first!\n"+
                                       "Type <form_off>\n"); return 1;}
if(present("shadowcon",tp)) { write("You may not cast shape chage when distraction is on!\n");
return 1;}
if(str != "blood_bird" && str != "bird" && str != "blood" &&
  str != "winter_wolf" && str != "wolf" && str != "winter" && str != "dragon") {
  if(tsp < 75) { write("You do not have enough energy!\n"); return 1;}
  if(scrp < 1000) { write("The darkness calls for a sacrifice.\n"); return 1;}
  if(restore_object("players/"+str)) {
  write("You may not take the form of another player.\n"); return 1;}
  nam = str;
  write("Description?\n");
  input_to("new");
  return 1;}
if(tsp < 100) { write("You do not have enough energy!\n"); return 1;}
if(scrp < 1000) { write("The darkness calls for a sacrifice.\n"); return 1;}
if(str == "blood_bird" || str == "bird" || str == "blood") {
   command("drop all",tp);
   form = "Blood Bird";
   ob=clone_object("/players/mythos/closed/guild/spells/shape_change_form.c");
   ob->set_form1("blood bird");
   ob->set_owner(tpn);
   ob->set_form2("bird");
   ob->set_msg("A huge "+BOLD+"black"+NORM+" eagle with a wing span of over 18 feet.\n"+
               "Sparkling "+HIR+"ruby"+NORM+" eyes seem to peer into your soul.  "+HIR+"Blood\n"+
               "red"+NORM+" talons and a cruel curved beak give an atmosphere of death.\n");
   move_object(tp,environment(tp));
   move_object(ob,environment(tp));
   move_object(clone_object("/players/mythos/closed/guild/spells/birdw.c"),tp);
   move_object(clone_object("/players/mythos/closed/guild/spells/shape_form1.c"),tp);
   move_object(clone_object("/players/mythos/closed/guild/spells/prevent.c"),tp);
}
if(str == "winter_wolf" || str == "wolf" || str == "winter") {
   command("drop all",tp);
   form = "Winter Wolf";
   ob=clone_object("/players/mythos/closed/guild/spells/shape_change_form.c");
   ob->set_form1("winter wolf");
   ob->set_owner(tpn);
   ob->set_form2("wolf");
   ob->set_msg("A great white wolf reaching 8 feet in length.\n"+
               HIR+"Blood red"+NORM+" eyes glare about.  Great speed\n"+
               "and powerful jaws are something to fear.....\n");
   move_object(tp,environment(tp));
   move_object(ob,environment(tp));
   move_object(clone_object("/players/mythos/closed/guild/spells/wolfw.c"),tp);
   move_object(clone_object("/players/mythos/closed/guild/spells/shape_form2.c"),tp);
   move_object(clone_object("/players/mythos/closed/guild/spells/prevent.c"),tp);
}
if(str == "dragon") {
   command("drop all",tp);
   form = "Dragon";
   ob=clone_object("/players/mythos/closed/guild/spells/shape_change_form.c");
   ob->set_form1("dragon");
   ob->set_owner(tpn);
   ob->set_form2("dragon");
   ob->set_msg("Scales of glossy "+BOLD+"BLACK"+NORM+
               " reflect back your face a thousandfold.\n"+
               "Above you, the dragon's eyes burn with "+HIB+"Cold Fire"+NORM+"\n"+
               "A jaw lined with razor sharp teeth opens as "+capitalize(tpn)+"\n"+
               "laughs at you.  You shudder in fear....\n");
   move_object(tp,environment(tp));
   move_object(ob,environment(tp));
   move_object(clone_object("/players/mythos/closed/guild/spells/dragonw.c"),tp);
   move_object(clone_object("/players/mythos/closed/guild/spells/shape_form3.c"),tp);
   move_object(clone_object("/players/mythos/closed/guild/spells/prevent.c"),tp);   
   tp->lower_attrib();
}
tp->add_spell_point(-100);
pp->add_sacrifice(-1000);
tell_room(environment(tp),"The body of "+capitalize(tpn)+" seems to fade.\n"+
          "Suddenly, there is a "+CYN+"BLAZE"+NORM+" of "+CYN+"LIGHT"+NORM+" as "+
          CYN+"COLD FIRE"+NORM+" floods the area!\n");
tell_room(environment(tp),"\nThe light fades and in the place of "+capitalize(tpn)+" is a "+
          form+"!\n\n");
  command("wield aura_of_shape",tp);
write("To become once again yourself, type <form_off>.\n"+
      "For new comands, type <shape_help>.\n");
return 1;}

new(p) {
  mesg = p;
  mesg = format(mesg,60)+"\n";
  command("drop all",tp);
  form = capitalize(nam);
   ob=clone_object("/players/mythos/closed/guild/spells/shape_change_form.c");
   ob->set_form1(nam);
   ob->set_owner(tpn);
   ob->set_form2(nam);
   ob->set_msg(mesg+"\n");
   move_object(tp,environment(tp));
   move_object(ob,environment(tp)); 
   ob2=clone_object("/players/mythos/closed/guild/spells/shape_form.c");
   ob2->set_ti(form);
   move_object(ob2,tp);
   tp->add_spell_point(-75);
   pp->add_sacrifice(-800);
   command("nnot",tp);
tell_room(environment(tp),"The body of "+capitalize(tpn)+" seems to fade.\n"+
          "Suddenly, there is a "+CYN+"BLAZE"+NORM+" of "+CYN+"LIGHT"+NORM+" as "+
          CYN+"COLD FIRE"+NORM+" floods the area!\n");
tell_room(environment(tp),"\nThe light fades and in the place of "+capitalize(tpn)+" is a "+
          form+"!\n\n");
write("To become once again yourself, type <form_off>.\n"+
      "For new comands, type <shape_help>.\n");
write_file("/players/mythos/closed/guild/shapes",ctime(time())+" "+tpn+" shape: "+form+"\n"+
           mesg+"\n");
return 1;}
