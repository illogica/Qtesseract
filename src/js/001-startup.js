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


function startup() {
    console.log("JS startup" + Events.N_WELCOME + " hey hey hey!");
}

server.registerHook(Events.N_CONNECT, "onConnect", false);

function onConnect(arg1, arg2){
    server.sendservmsg("OnConnect() inside JS! propTestInt=" + server.qtestInt);
    server.qtestInt++;
    server.qtestInt++;
    server.qtestInt++;
    server.qtestInt++;
    server.sendservmsg("OnConnect() inside JS! propTestInt=" + server.qtestInt);
    server.sendservmsg("Capsule test: " + arg1.name + ", " + arg2);
    var str = JSON.stringify(arg1.state);
    //str = JSON.stringify(arg1, null, 4); // (Optional) beautiful indented output.
    server.sendservmsg("state: " + str);
    server.sendservmsg("state.state: " + arg1.state.state);
    server.sendservmsg("ci.position: " + arg1.position);
    server.sendservmsg("ci.position.length: " + arg1.position.length);
    server.sendservmsg("ci.position.constructor.name: " + arg1.position.constructor.name);
    server.sendservmsg("ci.state: " + arg1.state);
    server.sendservmsg("ci.bots: " + arg1.bots);
    server.sendservmsg("ci.bots.length: " + arg1.bots.length);
    server.sendservmsg("ci.bots.constructor.name: " + arg1.bots.constructor.name);

    //server.sendservmsg(JSON.stringify(arg1.state));
    console.log(str);
}
