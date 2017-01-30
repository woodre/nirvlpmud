/* Example of mapping with an array of arrays of values per key */

mapping Map;
string *ArrA1;
int *ArrA2;
int *ArrA3;
mixed *MasterArrA;

id(str){ return str == "map_test"; }
short(){ return "A Mapping Tester"; }
long(){
  write("fill_map to add data to the mapping\n");
  write("view_map to see the data\n");
}

reset(arg){
  if(arg) return;
  /* size 2 mapping */
  Map = allocate_mapping(1);
  ArrA1 = allocate(11);
  ArrA2 = allocate(11);
  ArrA3 = allocate(11);
  MasterArrA = allocate(4);
}

init(){
  add_action("fill_map","fill_map");
  add_action("view_map","view_map");
}

fill_map(){

  ArrA1 = ({"a","b","c","d","e","f","g","h","i","j","k","l"});
  ArrA2 = ({1,2,5,1,3,4,5,3,2,2,1,2});
  ArrA3 = ({0,3,0,0,0,0,0,0,1,7,0,4});
  MasterArrA = ({ ArrA1, ArrA2, ArrA3 });

  Map = ([ "ALPHA":MasterArrA ]);
  write("Mapping filled.\n");
  return 1;
}

view_map(){
  mixed *masterarr;
  string *arra1;
  int *arra2, *arra3;
  int y,z;
  masterarr = Map["ALPHA"];
  arra1 = masterarr[0];
  arra2 = masterarr[1];
  arra3 = masterarr[2];
  write("Key\tName\tRank\tTitle\n");
  write("ALPHA"+"\n");
  for(y=0;y<12;y++){
    write("\t"+arra1[y]);
    write("\t"+arra2[y]);
    write("\t"+arra3[y]);
    write("\n");
  }
  write("Done.\n");
  return 1;
}
