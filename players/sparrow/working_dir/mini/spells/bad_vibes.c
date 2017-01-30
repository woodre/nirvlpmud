/*
 *  The goth ability to give a player bad vibes.  (v2.0)
 *
 */

bad_vibes(str)  {
  object ob;
  int scare_chance, will, bad_thing;

  if(!str)  {
  write("You begin to emanate an aura of despair.\n");
  say("You begin to feel uneasy as an almost tangible aura of despair surrounds "+tp+".\n");
  return 1;
       }

  if(spell(-3000,1,30) ==-1) return 0;

  ob = present(str, environment(TP));
  if(!ob)  {
    write("Who would you like to make miserable?\n");
    return 1;
        }
  write("You glare at "+CAP+" and emanate despair.\n");
  say(tp+" glares maliciously at "+CAP+".\n",ob);
  tell_object(ob, tp+" glares maliciously at you.\n"+
      "You begin to feel very uneasy.\n");

  if(ob->is_player())  {
    will = ob->query_attrib("wil");
    will = (will * 2) + ob->query_level();
    scare_chance = random(8);
    if(random(will) < scare_chance)  {
    if(ob->query_level() < 20)  {
     bad_thing = random(5);
     if(bad_thing == 0)  ob->run_away();
     if(bad_thing == 1)  command("unwield weapon",ob);
     if(bad_thing == 2)  tell_room(ENV, OJN+" flinches.\n");
     if(bad_thing == 3)  tell_room(ENV, OJN+" takes a step back.\n");
     if(bad_thing == 4)  tell_room(ENV, OJN+" looks nervious.\n");

  call_other(this_player(), "add_spell_point", -30);
        }
        }
        }
  return 1;
        }
