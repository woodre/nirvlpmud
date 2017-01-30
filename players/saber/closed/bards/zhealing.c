bury_corpse(str)  {
object corpse;
int heal;
string gender;
heal = 0;
corpse = present("corpse",environment(this_player()));
if(!corpse)  {
corpse = present("corpse",this_player());   }
if(!corpse)  {
  write("There is no corpse here to bury.\n");
  return 1;    }
gender = this_player()->query_pronoun();
heal = corpse->heal_value();
call_other(this_player(),"heal_self",heal);
write("You murmur a brief prayer and then bury the corpse.\n"+
     "You feel good.\n");
say(tp+" murmurs a brief prayer as "+gender+" buries a corpse.\n");
destruct(corpse);
move_object(clone_object("/players/saber/closed/bards/marker.c"),this_player());
command("drop marker",this_player());
  return 1;
      }

pyre_corpse(str)  {
object corpse;
int heal;
heal = 0;
corpse = present("corpse",environment(this_player()));
if(!corpse)  {
corpse = present("corpse",this_player());
  }
if(!corpse)  {
  write("There is no corpse here to burn.\n");
  return 1;
   }
heal = corpse->heal_value();
call_other(this_player(),"heal_self",heal);
write("You make a funeral pyre and burn the corpse.\n"+
    "You feel good.\n");
say(tp+" builds a funeral pyre and burns a corpse.\n");
destruct(corpse);
  return 1;
        }

chant_heal(str)  {
object ob;
if(!str)  {
  write("Cure who?\n");
  return 1;        }
  ob = present(str,environment(TP));
  if(!ob)  {
  write("You do not see a "+CAP+" here.\n");
  return 1;        }
  if(spell(0,2,15,TO) == -1)  return 0;
  ob->add_hit_point(12);
  write("You chant the song of healing.\n"+
   "You dance around in a circle.\n"+
  CAP+" is healed.\n");
  say(tp+" chants a strangly soothing chant.\n"+
  tp+" dances around in a circle.\n"+
  CAP+" is covered in an aura of healing.\n");
tell_object(ob, "You feel very good.\n");
  call_other(TP, "add_spell_point", -15);
  return 1;
        }

chord_of_agony(str)  {
string gender;
object ob;
  if(!str)  {
    write("You must strike the Chord of Agony towards a creature.\n");
    return 1;
        }
  ob = present(str,environment(TP));
  gender = ob->query_objective();
  if(!ob)  {
  write(CAP+" is not here.\n");
  return 1;
        }
  if(attack_spell(-100,4,20,ob) == -1) return 0;
  call_other(ob, "set_heal", 0,100);
  say(tp+" plays a dissonant chord upon "+TP->query_possessive()+" "+TO->query_instrument()+".\n"+
  "A black aura settles over "+capitalize(str)+".\n");
  write("You play a dissonant chord upon your "+TO->query_instrument()+".\n"+
    "A bl sh shadowdowck aura settles over "+capitalize(str)+".\n");
  call_other(TP, "add_spell_point", -20);
  return 1;
        }

hymn_of_healing()  {
if(spell(-100,8,50,TO) == -1) return 0;
TP->add_hit_point(45);
write("You are surrounded by a halo of light as you play the Hymn of Healing.\n"+
   "You faintly hear a choir of angels singing in accompaniment to your "+TO->query_instrument()+".\n"+
   "Your wounds are bathed in a healing aura.\n");
say(tp+" is surrounded by a halo of light as "+TP->query_possessive()+" plays a Hymn.\n"+
   "You faintly hear a choir of angels singing in accompniment to the "+TO->query_instrument()+" music.\n"+
   tp+" is bathed in a healing aura.\n");
  call_other(TP, "add_spell_point", -50);
  return 1;
        }

regeneration()  {
object ob;
int regen_count;
 if(spell(-194,9,100) == -1) return 0;
  if(present("regen",this_player()))  {
  ob = first_inventory(this_player());
  while(ob)  {
    if(call_other(ob, "id", "regen"))  {
    regen_count = regen_count + 1;
        }
  ob = next_inventory(ob);
        }
        }
   if(regen_count > 1)  {
    write("You are regenerating as much as bardic magic can do...\n");
    return 1;
        }
tell_room(environment(TP), "\n\n");
write("You play the Rhapsody of Regeneration upon your "+TO->query_instrument()+".\n"+
  "You speak one of the Words of Power.\nYou begin to regenerate.\n");
say(tp+" plays a Rhapsody upon "+TP->query_possessive()+" "+TO->query_instrument()+".\n"+
  tp+" speaks one of the Words of Power.\n\nYou shiver.\n"+
  tp+" begins to regenerate at a rapid rate.\n");
move_object(clone_object("/players/saber/closed/bards/regen.c"),this_player());
  call_other(TP,"add_spell_point",-100);
  return 1;
        }
