pget(str) {
                 object ob;
                 if (!str) return 0;
                 ob = present(str,HERE);
                 if (!ob) {
                            write ("There is no "+str+" here.\n");
                            return 1;
                          }
                 write ("You take: "+ob->short()+".\n");
                 say(NAME+" takes: "+ob->short()+".\n");
                 move_object(ob,USER);
                 return 1;
               }

pdrop(str) {
                  object ob;
                  if (!str) return 0;
                  ob = present(str,USER);
                  if (!ob) {
                             write ("You don't have a "+str+".\n");
                             return 1;
                           }
                  write ("You drop: "+ob->short()+".\n");
                  say(NAME+" drops: "+ob->short()+".\n");
                  move_object(ob,HERE);
                  return 1;
                }
