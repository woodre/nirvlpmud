#include "/players/forbin/define.h"

status main(int mode) {
  object *Users, *Items;
  string *Creators, *Data;
  string Tmp;
  int x, i, y, z;
  Users = users(); Creators = ({ });
  for(x = 0; x < sizeof(Users); x ++) {
    Items = deep_inventory(Users[x]);
    for(y = 0; y < sizeof(Items); y ++) {
      Tmp = creator(Items[y]);
      if(!Tmp) Tmp = "None";
      else Tmp = capitalize(Tmp);
      if((i = member_array(Tmp, Creators)) == -1) Creators += ({ Tmp, 1 });
      else                                        Creators[i + 1] = ((Creators[i + 1]) + 1);
    }
  }
  for(z = 0; z < sizeof(Creators); z += 2) {
    write(pad(Creators[z],15)+" "+Creators[z+1]+"\n");
  }
    return 1;
}
