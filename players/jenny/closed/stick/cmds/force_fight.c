#include "/players/jenny/define.h"
main(str){
           string a,b;
           string att1, att2;
           sscanf(str, "%s %s", att1, att2);
           a = present(att1, environment(this_player()));
           b = present(att2, environment(this_player()));
           b->attack_object(a); 
           a->attack_object(b);
return 1;
}
