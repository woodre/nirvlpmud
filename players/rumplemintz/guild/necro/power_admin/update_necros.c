#include "../DEFS"

cmd(){
    int i,a;
    object *ppl;
    object gob;
    ppl = users();
    for(i=0,a=sizeof(ppl);i<a;i++){
	gob = present("necro_ob", ppl[i]);
	if(gob){
	    destruct(gob);
	    move_object(clone_object(PATH+"/guildob.c"),ppl[i]);
	    tell_object(ppl[i],"Your guild object has been updated.\n");
	    write(HIR+capitalize(ppl[i]->query_real_name())+" updated.\n"+OFF);
	}
    }
    write(HIR+"The necromancers guild object has been updated.\n"+OFF);
    return 1;
}
