copy(str) {
            string who,what,file,junk;
            object who1,what1,mine;
           
            if (!str) return;
            if(sscanf(str,"%s from %s",what,who) != 2) {
              write("Usage: copy <item> from <player>.\n");
              return; }
            who1 = find_player(who);
            if (!who1) return;
            what1 = present(what,who1);
            if (!what1) return;
            sscanf(object_name(what1),"%s#%s",file,junk);
            mine = clone_object(file);
   write(
"You copy: "+mine->short()+"\n"
   );
            move_object(mine,USER);
            return 1;
          }
