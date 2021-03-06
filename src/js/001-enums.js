/**

  Enums to be used in all other .js files.
  There's no need to "import" or "include", they are all loaded into the
  global object and can be addressed simply by e.g. Events.N_CONNECT

  */

var Events = {
    N_CONNECT       : 0,
    N_SERVINFO      : 1,
    N_WELCOME       : 2,
    N_INITCLIENT    : 3,
    N_POS           : 4,
    N_TEXT          : 5,
    N_SOUND         : 6,
    N_CDIS          : 7,
    N_SHOOT         : 8,
    N_EXPLODE       : 9,
    N_SUICIDE       :10,
    N_DIED          :11,
    N_DAMAGE        :12,
    N_HITPUSH       :13,
    N_SHOTFX        :14,
    N_EXPLODEFX     :15,
    N_TRYSPAWN      :16,
    N_SPAWNSTATE    :17,
    N_SPAWN         :18,
    N_FORCEDEATH    :19,
    N_GUNSELECT     :20,
    N_TAUNT         :21,
    N_MAPCHANGE     :22,
    N_MAPVOTE       :23,
    N_TEAMINFO      :24,
    N_ITEMSPAWN     :25,
    N_ITEMPICKUP    :26,
    N_ITEMACC       :27,
    N_TELEPORT      :28,
    N_JUMPPAD       :29,
    N_PING          :30,
    N_PONG          :31,
    N_CLIENTPING    :32,
    N_TIMEUP        :33,
    N_FORCEINTERMISSION:34,
    N_SERVMSG       :35,
    N_ITEMLIST      :36,
    N_RESUME        :37,
    N_EDITMODE      :38,
    N_EDITENT       :39,
    N_EDITF         :40,
    N_EDITT         :41,
    N_EDITM         :42,
    N_FLIP          :43,
    N_COPY          :44,
    N_PASTE         :45,
    N_ROTATE        :46,
    N_REPLACE       :47,
    N_DELCUBE       :48,
    N_CALCLIGHT     :49,
    N_REMIP         :50,
    N_EDITVSLOT     :51,
    N_UNDO          :52,
    N_REDO          :53,
    N_NEWMAP        :54,
    N_GETMAP        :55,
    N_SENDMAP       :56,
    N_CLIPBOARD     :57,
    N_EDITVAR       :58,
    N_MASTERMODE    :59,
    N_KICK          :60,
    N_CLEARBANS     :61,
    N_CURRENTMASTER :62,
    N_SPECTATOR     :63,
    N_SETMASTER     :64,
    N_SETTEAM       :65,
    N_LISTDEMOS     :66,
    N_SENDDEMOLIST  :67,
    N_GETDEMO       :68,
    N_SENDDEMO      :69,
    N_DEMOPLAYBACK  :70,
    N_RECORDDEMO    :71,
    N_STOPDEMO      :72,
    N_CLEARDEMOS    :73,
    N_TAKEFLAG      :74,
    N_RETURNFLAG    :75,
    N_RESETFLAG     :76,
    N_TRYDROPFLAG   :77,
    N_DROPFLAG      :78,
    N_SCOREFLAG     :79,
    N_INITFLAGS     :80,
    N_SAYTEAM       :81,
    N_CLIENT        :82,
    N_AUTHTRY       :83,
    N_AUTHKICK      :84,
    N_AUTHCHAL      :85,
    N_AUTHANS       :86,
    N_REQAUTH       :87,
    N_PAUSEGAME     :88,
    N_GAMESPEED     :89,
    N_ADDBOT        :90,
    N_DELBOT        :91,
    N_INITAI        :92,
    N_FROMAI        :93,
    N_BOTLIMIT      :94,
    N_BOTBALANCE    :95,
    N_MAPCRC        :96,
    N_CHECKMAPS     :97,
    N_SWITCHNAME    :98,
    N_SWITCHMODEL   :99,
    N_SWITCHCOLOR   :100,
    N_SWITCHTEAM    :101,
    N_SERVCMD       :102,
    N_DEMOPACKET    :103,
    NUMMSG          :104
};

var FunctionEvent = {
    F_CONNECTEDPRE : 200,
    F_CONNECTEDPOST : 201,
    F_DODAMAGE : 202,
    F_RUGBY : 203
}

var Disconnect = {
    DISC_NONE: 0,
    DISC_EOP:1,
    DISC_LOCAL:2,
    DISC_KICK:3,
    DISC_MSGERR:4,
    DISC_IPBAN:5,
    DISC_PRIVATE:6,
    DISC_MAXCLIENTS:7,
    DISC_TIMEOUT:8,
    DISC_OVERFLOW:9,
    DISC_PASSWORD:10,
    DISC_NUM:11
};

var MasterMode = {
    MM_AUTH : -1,
    MM_OPEN : 0,
    MM_VETO: 1,
    MM_LOCKED:2,
    MM_PRIVATE:3
}

var Conout = {
    CON_INFO  : 1<<0,
    CON_WARN  : 1<<1,
    CON_ERROR : 1<<2,
    CON_DEBUG : 1<<3,
    CON_INIT  : 1<<4,
    CON_ECHO  : 1<<5
};

var Sound = {
    S_JUMP : 0,
    S_LAND : 1,
    S_SPLASHIN : 2,
    S_SPLASHOUT : 3,
    S_BURN : 4,
    S_ITEMSPAWN : 5,
    S_TELEPORT : 6,
    S_JUMPPAD : 7,
    S_MELEE : 8,
    S_PULSE1 : 9,
    S_PULSE2 : 10,
    S_PULSEEXPLODE : 11,
    S_RAIL1 : 12,
    S_RAIL2 : 13,
    S_WEAPLOAD : 14,
    S_NOAMMO : 15,
    S_HIT : 16,
    S_PAIN1 : 17,
    S_PAIN2 : 18,
    S_DIE1 : 19,
    S_DIE2 : 20,

    S_FLAGPICKUP : 21,
    S_FLAGDROP : 22,
    S_FLAGRETURN : 23,
    S_FLAGSCORE : 24,
    S_FLAGRESET : 25,
    S_FLAGFAIL : 26
};

var Privilege = {
    PRIV_NONE : 0,
    PRIV_MASTER : 1,
    PRIV_AUTH : 2,
    PRIV_ADMIN : 3
};

var GameMode = {
    M_TEAM       : 1<<0,
    M_CTF        : 1<<1,
    M_OVERTIME   : 1<<2,
    M_EDIT       : 1<<3,
    M_DEMO       : 1<<4,
    M_LOCAL      : 1<<5,
    M_LOBBY      : 1<<6,
    M_RAIL       : 1<<7,
    M_PULSE      : 1<<8
};

