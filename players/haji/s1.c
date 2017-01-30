/* wizard level catagories */
#define SENIOR 10
#define ELDER 11
#define GOD 12
#define APPRENTICE 2
#define WIZARD 3

/* standard security */
#define EXPLORE 2
#define CREATE 4
#define TITLE 4
#define INVIS 5
#define STAT 6
#define OUT_OF_BODY 7
#define CONTROL 7
#define SNOOP 8
#define DAMAGE 9
#define ITEM_OVER 9
#define ECHO 11
#define SHUTDOWN 12
#define EDIT_STANDARD 13
#define ALL_POWER GOD

/* invisability */
#define NO_SHORT 10
#define CAN_NO_SHORT 12
#define NO_WHO 10
#define CAN_NO_WHO 12
#define SOMEONE 13
#define CAN_SOMEONE 15
#define INVIS_TELEPORT 15
#define CAN_INVIS_TELEPORT 15
#define INVIS_ACTION 16
#define CAN_INVIS_ACTION 100
#define NO_ID 60
#define CAN_NO_ID 300
#define NO_PEOPLE 100
#define CAN_NO_PEOPLE 600
/* to make life easier */
#define INV1 NO_SHORT
#define CINV1 CAN_NO_SHORT
#define INV2 NO_WHO
#define CINV2 CAN_NO_WHO
#define INV3 SOMEONE
#define CINV3 CAN_SOMEONE
#define INV4 INVIS_TELEPORT
#define CINV4 CAN_INVIS_TELEPORT
#define INV5 INVIS_ACTION
#define CINV5 CAN_INVIS_ACTION
#define INV6 NO_ID
#define CINV6 CAN_NO_ID
#define INV7 NO_PEOPLE
#define CINV7 CAN_NO_PEOPLE


/* file access */
#define ED_OTHERS   SENIOR
#define ED_LOG	    ELDER
#define READ_OTHERS STAT


/* object access */
#define private if (this_player() != this_object()) return 0
