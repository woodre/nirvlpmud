# MySQL-Front Dump 2.5
#
# Host: nomiya.beanos.com   Database: nirvana
# --------------------------------------------------------
# Server version 4.0.18-max-debug


#
# Table structure for table masterlog
#


CREATE TABLE masterlog (
  date_recorded datetime default NULL,
  my_ip_number varchar(16) default NULL,
  my_ip_name varchar(128) default NULL,
  my_real_name varchar(16) default NULL,
  my_mailaddr varchar(128) default NULL,
  my_level mediumint(3) default NULL,
  my_guild_name varchar(50) default NULL,
  my_exp int(4) default NULL,
  my_qp int(4) default NULL,
  my_money int(4) default NULL,
  my_wc int(4) default NULL,
  my_ac int(4) default NULL,
  my_hp int(4) default NULL,
  my_sp int(4) default NULL,
  my_pl_k int(4) default NULL,
  my_extra_level int(4) default NULL,
  room_creator varchar(16) default NULL,
  room_file_name varchar(255) default NULL,
  att_creator varchar(16) default NULL,
  att_file_name varchar(255) default NULL,
  att_name varchar(128) default NULL,
  att_wc int(4) default NULL,
  att_ac int(4) default NULL,
  att_mhp int(4) default NULL,
  wep_creator varchar(16) default NULL,
  wep_file_name varchar(255) default NULL,
  wep_wc int(4) default NULL,
  oid bigint(8) NOT NULL auto_increment,

  PRIMARY KEY  (oid)
) TYPE=MyISAM;
