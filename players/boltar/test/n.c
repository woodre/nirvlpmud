init() {
add_action("ffg","ffg");
}
ffg(str) {
write_file("/log/WR/boltar_workreport", str);
return 1;
}
