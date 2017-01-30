force(str) {
                object who;
                string who2, what;
                if(sscanf(str,"%s %s",who2,what) != 2) return write("Usage: force <player> <command>.\n");
                who=find_player(who2);
                if(!who) {
                           write(capitalize(who2)+" is not here.\n");
                         }
                command(what, who);
                return 1;
              }
