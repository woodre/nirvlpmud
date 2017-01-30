echo_all(str) {
                if(!str) return 1;
                shout(str+"\n");
                write(str+"\n");
                return 1;
              }

echoto(str) {
              object who;
              string who2, what;
              if(sscanf(str,"%s %s",who2,what) != 2) return write("Usage: echoto <player> <action>");
              who=find_player(who2);
              if (!who) {
                 write(capitalize(who2)+" is not here.\n");
                 return;
                        }
              tell_object(who,what+"\n");
   write("You echoto "+capitalize(who2)+": "+what+"\n");
              return 1;
            }

echo(str) {
            write(str+"\n");
            say(str+"\n");
            return 1;
          }

