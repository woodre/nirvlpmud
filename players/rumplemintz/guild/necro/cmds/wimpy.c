#include "../DEFS"

int cmd(string str){
    if(!str){
	write("<"+HIR+"RoD"+OFF+
	  "> The Realm of Death disdains cowardice in their servants.\n");
	return 0;
    }
    if(str != "off"){
	write("<"+HIR+"RoD"+OFF+"> The Realm of Death disdains your cowardice.\n");
	return 0;
    }
    write("<"+HIR+"RoD"+OFF+
      "> The Realm of Death is pleased with your bravery.\n");
    return 0 ; 
}
