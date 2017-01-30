/*
 *  The succor ability of the mini guilds. (v2.0)
 *
 */

succor()  {
  object ob, TO;
  string mess1, mess2;
  ob = this_player();

  if(spell(-4000,1,40,ob) ==-1) return 0;

  if(REALM !="NT")  {

  TO = present("base_obj", this_player());

  if(TO->query_object_name() == "succubus_obj")  {
    mess1 = tp+" turns into smoke and drifts away";
    mess2 = "You turn into smoke and drife away";
        }
  if(TO->query_object_name() == "larn_obj")  {
    mess1 = tp+" grasps "+POSS+" holy symbol and whispers a prayer";
    mess2 = "You grasp your holy symbol of Larn and whisper a prayer";
        }
  if(TO->query_object_name() == "kender_obj")  {
    mess1 = tp+" smiles and is gone";
    mess2 = "you smile";
        }
  if(TO->query_object_name() == "meow_obj")  {
    mess1 = tp+" turns three circles and is gone";
    mess2 = "You turn three circles";
        }
  if(TO->query_object_name() == "blade_obj")  {
    mess1 = tp+" disappears into a shadow";
    mess2 = "You duck into a shadow";
        }
  if(TO->query_object_name() == "gothic_obj")  {
    mess1 = tp+" looks so depressed that they just fade away..";
    mess2 = "You feel so depressed that you just fade away";
        }
  if(mess1 == "0")  {
    mess1 = tp+" opens a door and steps into a portal..";
    mess2 = "You open a door and step into it...";
        }

  say(mess1+".\n");
  write(mess2+".\n");
  move_object(ob, "/players/saber/ryllian/portal.c");
  say(tp+" fades into view.\n");
  write("You are now in the chamber of portals.\n");
  call_other(TP, "add_spell_point", -40);
  return 1;
        }

  write("You cannot goportal from here.\n");
  return 1;
        }
