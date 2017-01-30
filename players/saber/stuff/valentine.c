inherit "/players/saber/closed/bards/shapeobj.c";
string valentine_name, sender_name;
reset(arg)  {
valentine_name = "Noone";
sender_name = "Nobody";
   if (arg) return;
   set_name("valentine");
   set_short("A Valentine");
   set_long("A lovely red valentine.\n"+
       "You might want to read it.\n");
   set_weight(0);
   set_value(0);
        }

read(str)  {
  if(str == "valentine")  {
  write(
       "\n"+
       "               * * *          * * *\n"+
       "              *      *       *     *\n"+
       "             *        *     *       *\n"+
       "            *          *   *         *\n"+
       "           *             *            *\n"+
       "           *                          *\n"+
       "           *         To:              *\n"+
       "            *        "+pad(capitalize(this_object()->query_VAL()),12)+"    *\n"+
        "             *                      *\n"+
       "              *      From:         *\n"+
       "               *     "+pad(this_object()->query_NAME(),12)+" *\n"+
       "                *                *\n"+
       "                 *              *\n"+
       "                  *            *\n"+
       "                   *          *\n"+
       "                    *        *\n"+
       "                     *      *\n"+
       "                      *    *\n"+
       "                       *  *\n"+
       "                        **\n"+
        "\nTo use type SEND <player name>. (send in all caps)\n"+
       "                                   - A SABER product.\n");
  return 1;
        }
        }

init()  {
  ::init();
   add_action("send","SEND");
   add_action("read","read");
        }

send(str)  {
object ob, ob2;
  if(!str)  {
    write("To use type: SEND <player name>\n");
    return 1;
        }
  ob = this_object();
  ob2 = find_player(str);
  if(!ob2)  {
    write("You cannot find "+capitalize(str)+" anywhere.\n");
    return 1;
        }
  call_other(ob,"set_valentine",str);
  call_other(ob,"set_NAME", this_player()->query_name());
  write("You send a valentine to "+capitalize(str)+".\n"+
       "\nYou get a warm feeling inside of you.\n");
  tell_room(environment(ob), "A valentine flies into the room and goes to "+capitalize(str)+".\n");
  tell_object(ob2,"You have recieved a valentine.\n");
  move_object(ob,ob2);
  return 1;
        }

set_valentine(str)   { valentine_name = str;  }
set_NAME(str)  { sender_name = str;  }

query_VAL()  { return valentine_name;  }
query_NAME()  { return sender_name;  }
