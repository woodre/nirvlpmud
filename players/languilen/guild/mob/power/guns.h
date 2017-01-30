/*
 *  Guns.h
 *  Mob G-Wep Ability
 */

guns_cmd(string str){
     int i;
     string *list;
     mapping guns;

     guns = TPGO->query_all_guns();
     if(!guns){
        write("You have no guns!\n");
        return 1;
     }
     i = sizeof(list = keys(guns));
/*     Have a possible bug here.  guns = ([])      */
     write("  Gun                      Ammo\n");
     while(i--){
          switch(list[i]){
                 case "22":{
                           write(pad(".22 caliber luger", 20));
                           write(guns[list[i]]+"\n");
                           break;
                 }
                 case "38":{
                           write(pad(".38 special", 20));
                           write(guns[list[i]]+"\n");
                           break;
                 }
                 case "45":{
                           write(pad("nickle plated .45", 20));
                           write(guns[list[i]]+"\n");
                           break;
                 }
                 case "44":{
                           write(pad(".44  magnum", 20));
                           write(guns[list[i]]+"\n");
                           break;
                 }
                 case "silencer":{
                           write(pad("silenced .22", 20));
                           write(guns[list[i]]+"\n");
                           break;
                 }
                 case "thomson":{
                           write(pad("Thomson", 20));
                           write(guns[list[i]]+"\n");
                           break;
                 }
                 default:{
                           write(pad("problem", 20));
                           break;
                 }
          }
     write("\n");
     return 1;
     }
     return 1;
}
