goin(str) {
             object dude;
             dude=find_player(str);
             if (!dude) return 0;
             move_object(USER,dude);
             return 1;
           }
