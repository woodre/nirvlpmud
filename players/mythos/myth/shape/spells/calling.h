#define WEPFILE "/players/mythos/myth/shape/wep/"+tpn+".c"

calling(object targ,string choice) {
object shadow;
  shadow = 0;
  shadow = clone_object(WEPFILE);
  if(!shadow) {
    write_file(WEPFILE,"#include ");
    write_file(WEPFILE,"\"");
    write_file(WEPFILE,"/players/mythos/myth/myth/shape/spells/"+choice+".h");
    write_file(WEPFILE,"\"");
    write_file(WEPFILE,";\n");
    write_file(WEPFILE,"inherit ");
    write_file(WEPFILE,"\"");
    write_file(WEPFILE,"players/mythos/myth/shape/spells/wep");
    write_file(WEPFILE,"\"");
    write_file(WEPFILE,";\n");
    shadow = clone_object(WEPFILE);
  }
  move_object(shadow,targ);
  tell_object(targ,"\n");
return 1; }
