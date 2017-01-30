visit(str) {
             object dude;
             dude=find_player(str);
             if (!dude) return 0;
             move_object(USER,environment(dude));
             return 1;
           }
