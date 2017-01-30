init() {
	int i;
	object *list;
	list = users();
	for(i=0;i<sizeof(list);i++) {
			destruct(list[i]);
	}
}
