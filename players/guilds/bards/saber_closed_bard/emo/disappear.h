/* Emotions for Bards */

disappear(str)  {
object ob;


 if(!str)  {
  write("Muttering a brief incantation, you momentarily cloak yourself in invisibility.\n");
  say(tp+" disappears in a puff of smoke.\n");
  return 1;
        }

  ob = present(str,ENV);

  if(!ob)  {
    write("Who do you want to make disappear?\n");
    return 1;
        }

  write("You incant sharply and point at "+CAP+", binding "+ob->query_objective()+"\n"+
        "with a momentary cloak of invisibility.\n");
  say(tp+" incants sharply and points at "+CAP+", causing "+ob->query_objective()+" to\n"+
        "disappear in a puff of "+HIB+"blue smoke"+NORM+".\n",ob);
  tell_object(ob, tp+" incants sharply and points at you.\n"+
                     "You disappear in a puff of "+HIB+"blue smoke"+NORM+".\n");
  return 1;
        }
