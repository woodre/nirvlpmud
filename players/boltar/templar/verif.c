verifpl(str) {
if(restore_object("pfiles/" + extract(str,0,0) + "/" + str)) return 1;
return 0;
}
